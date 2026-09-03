'''
Author: LetMeFly
Date: 2026-09-02 13:54:11
LastEditors: LetMeFly.xyz
LastEditTime: 2026-09-02 13:54:11
'''
from flask import Flask, request, jsonify, send_from_directory
from pywebpush import webpush, WebPushException
import json
import os

app = Flask(__name__, static_folder="static")

SUBSCRIPTIONS_FILE = "subscriptions.json"
VAPID_PRIVATE_KEY = "private_key.pem"

with open("public_key.txt", "r") as f:
    VAPID_PUBLIC_KEY = f.read().strip()

VAPID_CLAIMS = {
    "sub": "mailto:admin@letmefly.xyz"
}


def load_subscriptions():
    if not os.path.exists(SUBSCRIPTIONS_FILE):
        return []

    with open(SUBSCRIPTIONS_FILE, "r") as f:
        return json.load(f)


def save_subscriptions(subscriptions):
    with open(SUBSCRIPTIONS_FILE, "w") as f:
        json.dump(subscriptions, f, indent=2)


@app.route("/")
def index():
    return send_from_directory("static", "index.html")


@app.route("/sw.js")
def service_worker():
    return send_from_directory("static", "sw.js")


@app.route("/api/vapid-public-key")
def vapid_public_key():
    return jsonify({
        "publicKey": VAPID_PUBLIC_KEY
    })


@app.route("/api/subscribe", methods=["POST"])
def subscribe():
    subscription = request.get_json()

    if not subscription or "endpoint" not in subscription:
        return jsonify({
            "error": "invalid subscription"
        }), 400

    subscriptions = load_subscriptions()

    # 避免重复保存
    if not any(
        x.get("endpoint") == subscription["endpoint"]
        for x in subscriptions
    ):
        subscriptions.append(subscription)
        save_subscriptions(subscriptions)

    return jsonify({
        "success": True,
        "count": len(subscriptions)
    })


@app.route("/api/send", methods=["POST"])
def send_notification():
    data = request.get_json() or {}

    title = data.get("title", "通知")
    message = data.get("message", "你收到了一条新消息")

    subscriptions = load_subscriptions()

    payload = json.dumps({
        "title": title,
        "message": message
    })

    alive = []

    success = 0
    failed = 0

    for subscription in subscriptions:
        try:
            webpush(
                subscription_info=subscription,
                data=payload,
                vapid_private_key=VAPID_PRIVATE_KEY,
                vapid_claims=VAPID_CLAIMS
            )

            alive.append(subscription)
            success += 1

        except WebPushException as e:
            print("Push failed:", e)

            # 订阅失效，删除
            if e.response is not None and e.response.status_code in (
                404,
                410
            ):
                failed += 1
                continue

            alive.append(subscription)
            failed += 1

    save_subscriptions(alive)

    return jsonify({
        "success": True,
        "sent": success,
        "failed": failed,
        "total": len(alive)
    })


if __name__ == "__main__":
    app.run(
        host="127.0.0.1",
        port=8000
    )
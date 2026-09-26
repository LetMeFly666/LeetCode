/*
 * @Author: LetMeFly
 * @Date: 2026-09-02 13:54:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-02 13:54:58
 */
self.addEventListener("push", event => {

    let data = {
        title: "通知",
        message: "你收到了一条新消息"
    };

    if (event.data) {
        data = event.data.json();
    }

    event.waitUntil(

        self.registration.showNotification(
            data.title,
            {
                body: data.message,
                icon: "/icon.png",
                badge: "/icon.png"
            }
        )

    );

});
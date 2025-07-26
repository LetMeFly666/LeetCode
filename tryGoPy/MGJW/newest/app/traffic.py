
from flask import Blueprint, request, jsonify
from script.traffic_remote_genenrate import traffic_data, stop_events, traffic_remote_generate
import threading

traffic_blueprint = Blueprint('traffic', __name__)


threads = {}        # 存储各 IP 的停止事件

# 处理limit_start请求
@traffic_blueprint.route('/limit_start', methods=['POST'])
def limit_start():
    ipdata = request.get_json()
    ip = ipdata.get('ip') 
    username = ipdata.get('username') 
    password = ipdata.get('password')
    print(f"Received request to start traffic capture for IP: {ip}, Username: {username}")
    if not ip:
        return jsonify({'status': 'error', 'message': '缺少 ip 参数'}), 400

    if ip in threads:
        return jsonify({'status': 'already_started', 'ip': ip})
    # 初始化数据与线程控制
    stop_events[ip] = threading.Event()
    traffic_data[ip] = {'ip': ip, 'upload': 0, 'download': 0}
    t = threading.Thread(target=traffic_remote_generate, args=(ip, username, password), daemon=True)
    threads[ip] = t
    t.start()
    return jsonify({'status': 'started', 'ip': ip})

# 处理limit_end请求
@traffic_blueprint.route('/limit_end', methods=['POST'])
def limit_end():
    ipdata = request.get_json()
    ip = ipdata.get('ip')  # 

    if not ip or ip not in threads:
        return jsonify({'status': 'error', 'message': '没有正在运行的捕捉线程'}), 400

    # 触发停止事件并清理线程
    stop_events[ip].set()
    threads[ip].join(timeout=1)
    del threads[ip]
    del stop_events[ip]
    # 保留最后的 traffic_data 供查询

    return jsonify({'status': 'stopped', 'ip': ip})

@traffic_blueprint.route('/get_traffic', methods=['GET'])
def get_traffic():
    ip = request.args.get('ip')  # 获取 IP 地址

    if not ip or ip not in traffic_data:
        return jsonify({'status': 'error', 'message': '无效或不存在的 ip'}), 404

    return jsonify(traffic_data[ip])
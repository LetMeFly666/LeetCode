from flask import request, jsonify, Blueprint
import paramiko


ssh_blueprint = Blueprint('ssh', __name__)

@ssh_blueprint.route('/check', methods=['POST'])
def ssh_check():
    data = request.get_json()
    ip = data.get('ip')
    port = 22
    username = data.get('username')
    password = data.get('password')
    try:
        ssh = paramiko.SSHClient()
        ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        ssh.connect(ip, username=username, port=port, password=password, timeout=3)
        ssh.close()
        return jsonify({"success": True})
    except Exception as e:
        return jsonify({"success": False, "error": str(e)})
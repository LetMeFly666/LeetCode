from flask import Blueprint, request, jsonify
from werkzeug.utils import secure_filename
from script.pcap_process import allowed_file, extract_zip
from script.pcap_remote_analysis import analyze_pcap_on_linux
from script.task_manager import create_task, update_task_status, get_task_info, mark_task_complete
import os

pcap_blueprint = Blueprint('pcap', __name__)

# 配置上传文件夹
UPLOAD_FOLDER = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 
                             'data/uploads_files')
os.makedirs(UPLOAD_FOLDER, exist_ok=True)


@pcap_blueprint.route('/upload', methods=['POST'])
def upload_file():
    files = request.files.getlist('files')
    linux_ip = request.form.get('linux_ip')
    linux_username = request.form.get('linux_username')
    linux_password = request.form.get('linux_password')
    # 在主线程保存文件
    saved_files = []
    for file in files:
        if file and allowed_file(file.filename):
            filename = secure_filename(file.filename)
            file_path = os.path.join(UPLOAD_FOLDER, filename)
            file.save(file_path)
            saved_files.append(file_path)
        else:
            saved_files.append(None) 

    task_id = create_task(files)
    
    def process_files():
        """处理文件的后台任务"""
        for i, file in enumerate(files):
            try:
                file_result = None
                    # 处理文件
                if filename.endswith('.zip'):
                    extracted_files = extract_zip(file_path)
                    for extracted_file in extracted_files:
                        remote_name = os.path.basename(extracted_file)
                        result = analyze_pcap_on_linux(extracted_file,
                                                       remote_name, 
                                                       linux_ip, 
                                                       linux_username, 
                                                       linux_password)
                        print(f"分析结果: {result}")
                        update_task_status(task_id, "processing", 
                                               {"file": extracted_file, "result": result})
                else:
                    remote_name = filename
                    result = analyze_pcap_on_linux(file_path,
                                                remote_name,
                                                linux_ip, 
                                                linux_username, 
                                                linux_password)
                    print(f"分析结果: {result}")
                    update_task_status(task_id, "processing", 
                                          {"file": filename, "result": result})
                file_result = f"{filename} 分析完成"
                update_task_status(task_id, "processing", file_result)
            except Exception as e:
                error_msg = f"处理文件 {file.filename} 时出错: {str(e)}"
                update_task_status(task_id, "processing", error_msg)
                    
        # 所有文件处理完成
        mark_task_complete(task_id)
    
    # 启动后台处理线程
    import threading
    processing_thread = threading.Thread(target=process_files)
    processing_thread.daemon = True
    processing_thread.start()
    
    # 返回任务ID
    return jsonify({"success": True, "task_id": task_id})

@pcap_blueprint.route('/task_status/<task_id>', methods=['GET'])
def task_status(task_id):
    """获取任务状态"""
    return jsonify(get_task_info(task_id))
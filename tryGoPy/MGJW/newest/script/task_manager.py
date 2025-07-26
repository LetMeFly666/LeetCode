# script/task_manager.py

import uuid
from threading import Lock

# 用于存储任务状态的任务字典
tasks = {}
tasks_lock = Lock()

def get_task_info(task_id):
    """获取任务信息"""
    with tasks_lock:
        return tasks.get(task_id, {"status": "not_found"})

def update_task_status(task_id, status, result=None):
    """更新任务状态"""
    with tasks_lock:
        if task_id in tasks:
            tasks[task_id]["status"] = status
            if result is not None:
                # 确保 filesResults 存在
                if "filesResults" not in tasks[task_id]:
                    tasks[task_id]["filesResults"] = []
                tasks[task_id]["filesResults"].append(result)

def create_task(files):
    """创建新任务"""
    task_id = str(uuid.uuid4())
    with tasks_lock:
        tasks[task_id] = {
            "status": "processing",
            "file_count": len(files),
            "completed_files": 0,
            "filesResults": []
        }
    return task_id

def mark_task_complete(task_id):
    """标记任务完成"""
    with tasks_lock:
        if task_id in tasks:
            tasks[task_id]["status"] = "completed"

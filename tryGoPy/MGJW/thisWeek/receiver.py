'''
Author: LetMeFly
Date: 2025-03-08 11:06:53
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-08 11:15:29
'''
import time
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
import os

FILE_PATH = 'letreceiver'

if not os.path.exists(FILE_PATH):
    os.system(f'echo > {FILE_PATH}')

class FileChangeHandler(FileSystemEventHandler):
    def on_modified(self, event):
        if event.src_path.endswith(FILE_PATH):
            print(f"File {FILE_PATH} has been modified. Reading new content...")
            self.read_file_content()

    def read_file_content(self):
        try:
            with open(FILE_PATH, 'r', encoding='utf-8') as file:
                content = file.read()
                print("New content:")
                print(content)
        except Exception as e:
            print(f"Error reading file: {e}")

if __name__ == "__main__":
    # 创建事件处理器和观察者
    event_handler = FileChangeHandler()
    observer = Observer()
    observer.schedule(event_handler, path='.', recursive=False)

    # 启动观察者
    observer.start()
    print(f"Started watching {FILE_PATH} for changes...")

    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        observer.stop()

    observer.join()
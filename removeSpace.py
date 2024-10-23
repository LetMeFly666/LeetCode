import tkinter as tk
from tkinterdnd2 import TkinterDnD, DND_TEXT
import pyperclip
import re

# 处理输入文本，去除特定字符之间的空格
def process_text(text):
    # 去除英文字母或数字与汉字之间的空格
    processed_text = re.sub(r'(\w)\s+([\u4e00-\u9fff])', r'\1\2', text)
    processed_text = re.sub(r'([\u4e00-\u9fff])\s+(\w)', r'\1\2', processed_text)

    # 去除英文字母或数字与全角字符之间的空格，包括中文句号
    processed_text = re.sub(r'(\w)\s+([\uFF00-\uFFEF]|。)', r'\1\2', processed_text)
    processed_text = re.sub(r'([\uFF00-\uFFEF]|。)\s+(\w)', r'\1\2', processed_text)

    return processed_text

# 将处理后的文本复制到剪贴板
def copy_to_clipboard(text):
    pyperclip.copy(text)
    show_status("文本已处理并复制到剪贴板！")

# 从文本框获取内容并处理
def handle_paste(event=None):
    # 获取文本框内容
    input_text = text_box.get(1.0, tk.END).strip()
    if input_text:
        # 处理文本
        processed_text = process_text(input_text)
        # 将处理后的文本复制回剪贴板
        copy_to_clipboard(processed_text)
        # 更新文本框内容
        text_box.delete(1.0, tk.END)
        text_box.insert(tk.END, processed_text)
    else:
        show_status("剪贴板为空或无效，请粘贴文本。")

# 处理拖入的文本
def handle_drop(event):
    dragged_text = event.data
    text_box.delete(1.0, tk.END)
    text_box.insert(tk.END, dragged_text)
    handle_paste()

# 显示渐变状态提示
def show_status(message):
    status_label.config(text=message, fg='#000000')
    status_label.after(100, lambda: status_label.config(fg='#202020'))
    status_label.after(200, lambda: status_label.config(fg='#404040'))
    status_label.after(300, lambda: status_label.config(fg='#606060'))
    status_label.after(400, lambda: status_label.config(fg='#808080'))
    status_label.after(500, lambda: status_label.config(fg='#A0A0A0'))
    status_label.after(600, lambda: status_label.config(fg='#C0C0C0'))
    status_label.after(700, lambda: status_label.config(fg='#E0E0E0'))
    status_label.after(800, lambda: status_label.config(fg='#F0F0F0'))
    status_label.after(900, lambda: status_label.config(fg='#FFFFFF'))
    status_label.after(1000, lambda: status_label.config(fg=root.cget("bg")))

# 自动转换（粘贴事件时触发）
def on_paste(event=None):
    handle_paste()

# 初始化TkinterDnD窗口
root = TkinterDnD.Tk()
root.title("文本处理器")
root.geometry("500x400")

# 功能说明标签
desc_label = tk.Label(root, text="功能说明：删除汉字、全角字符与英文或数字之间的空格，英文或数字之间的空格保留", font=("Arial", 10), wraplength=450)
desc_label.pack(pady=10)

# 文本框
text_box = tk.Text(root, height=10, width=60)
text_box.pack(pady=10)

# 支持文本拖入功能
text_box.drop_target_register(DND_TEXT)
text_box.dnd_bind('<<Drop>>', handle_drop)

# 开始转换按钮
convert_button = tk.Button(root, text="开始转换", command=handle_paste)
convert_button.pack(pady=10)

# 状态提示标签
status_label = tk.Label(root, text="", font=("Arial", 10))
status_label.pack(pady=10)

# 绑定Ctrl+V粘贴事件，自动转换
root.bind('<Control-v>', on_paste)

# 运行GUI主循环
root.mainloop()

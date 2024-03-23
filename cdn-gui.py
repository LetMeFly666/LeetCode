'''
Author: LetMeFly
Date: 2024-03-22 23:44:27
LastEditors: LetMeFly
LastEditTime: 2024-03-22 23:59:06
'''
import tkinter as tk
from tkinter import ttk
import os
import subprocess
import shutil
from tkinter.simpledialog import askstring
from tkinter import messagebox
from tkinterdnd2 import DND_FILES, TkinterDnD

def fill_tree(path, parent=''):
    for entry in os.listdir(path):
        entry_path = os.path.join(path, entry)
        is_dir = os.path.isdir(entry_path)
        id = tree.insert(parent, 'end', text=entry, open=False)
        if is_dir:
            fill_tree(entry_path, id)

def on_double_click(event):
    selected_items = tree.selection()
    if selected_items:  # Check if the selection is not empty
        item_id = selected_items[0]
        item_path = os.path.join(os.getcwd(), tree.item(item_id, 'text'))
        if os.path.isdir(item_path):
            os.startfile(item_path)
        else:
            subprocess.Popen(['notepad.exe', item_path])
    else:
        print("No item selected")

def create_folder():
    selected_items = tree.selection()
    if selected_items:
        item_id = selected_items[0]
        parent_path = os.path.join(os.getcwd(), tree.item(item_id, 'text'))
        if not os.path.isdir(parent_path):
            parent_path = os.path.dirname(parent_path)
    else:
        # 没有选中任何项目时的处理逻辑
        # 这里，我们可以选择在根目录下创建新文件夹
        parent_path = os.getcwd()  # 或者选择一个默认路径

    new_folder_name = askstring("New Folder", "Enter folder name:")
    if new_folder_name:
        try:
            new_folder_path = os.path.join(parent_path, new_folder_name)
            os.mkdir(new_folder_path)
            # 如果是在根目录下创建，我们需要刷新或更新树视图
            # 注意：这里的实现取决于你如何组织树视图的节点和路径
            if not selected_items:
                # 假设你有一个函数来填充或更新树视图
                # fill_tree(new_folder_path, parent='')
                # 或者只简单地添加到树视图中，如果适用的话
                tree.insert('', 'end', text=new_folder_name, open=False)
        except Exception as e:
            messagebox.showerror("Error", str(e))

def on_right_click(event):
    try:
        item_id = tree.identify_row(event.y)
        tree.selection_set(item_id)
        item_path = os.path.join(os.getcwd(), tree.item(item_id, 'text'))
        if os.path.isdir(item_path):
            right_click_menu.tk_popup(event.x_root, event.y_root)
        else:
            # Optionally, you can show a different menu for files or do nothing
            pass
    finally:
        right_click_menu.grab_release()

def on_drop(event):
    # 转换全局鼠标位置到树视图坐标
    x, y = tree.winfo_pointerxy()
    tree_x = tree.winfo_rootx()
    tree_y = tree.winfo_rooty()
    local_x, local_y = x - tree_x, y - tree_y
    
    # 确定鼠标下方的节点
    item_id = tree.identify_row(local_y)
    if item_id:
        item_path = os.path.join(os.getcwd(), tree.item(item_id, 'text'))
        if os.path.isdir(item_path):
            files = root.tk.splitlist(event.data)
            for f in files:
                try:
                    # 复制文件到目标目录
                    shutil.copy(f, item_path)
                    # 这里可以添加更多的逻辑，如更新树视图等
                except Exception as e:
                    messagebox.showerror("Error", f"Failed to copy file: {e}")
        else:
            messagebox.showinfo("Info", "Please drop the file on a folder.")
    else:
        messagebox.showinfo("Info", "Please drop the file on a valid target.")

root = TkinterDnD.Tk()
root.title("Directory Browser")
root.geometry("600x400")

tree = ttk.Treeview(root)
tree.pack(expand=True, fill='both')
fill_tree(os.getcwd())  # Start with the current working directory

tree.bind("<Double-1>", on_double_click)

right_click_menu = tk.Menu(root, tearoff=0)
right_click_menu.add_command(label="New Folder", command=create_folder)

tree.bind("<Button-3>", on_right_click)

root.drop_target_register(DND_FILES)
root.dnd_bind('<<Drop>>', on_drop)

root.mainloop()

'''
Author: LetMeFly
Date: 2023-10-20 10:00:08
LastEditors: LetMeFly
LastEditTime: 2023-10-20 10:20:27
'''
from flask import send_file, send_from_directory
import flask

app = flask.Flask('1')

@app.route("/a/")
def download_file():
    return send_file(r"C:\Users\LetMeFly\Desktop\image.png", 'a.png', as_attachment=True)

print(app.url_map)
app.run(host='0.0.0.0', port='80', debug=True)
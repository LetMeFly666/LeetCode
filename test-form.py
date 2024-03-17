'''
Author: LetMeFly
Date: 2024-03-16 22:20:36
LastEditors: LetMeFly
LastEditTime: 2024-03-16 22:29:48
'''
from flask import Flask, request

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST'])
def main():
    print(request.method)
    if request.method == 'GET':
        return open('test-form.html').read()
    else:
        print(f'register: {request.get_data()}')
        return 'Success'

app.run(debug=True, port=8888)
from flask import Blueprint, render_template
# 创建蓝图


home_blueprint = Blueprint('home', __name__)



@home_blueprint.route('/')
def index():
    return render_template('traffic_index.html')

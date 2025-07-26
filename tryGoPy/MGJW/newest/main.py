from flask import Flask
import os
from app.home import home_blueprint
from app.traffic import traffic_blueprint
from app.pcap import pcap_blueprint
from app.webex import webex_blueprint
from app.ssh import ssh_blueprint
from app.owa import owa_blueprint
from app.backend import backend_blueprint
from app.redirect import redirect_blueprint

cur_dir = os.path.dirname(os.path.abspath(__file__))
analysis_template_dir = os.path.join(cur_dir, 'templates')
analysis_static_dir = os.path.join(cur_dir, 'static')

app = Flask(__name__,
            static_folder=analysis_static_dir,  
            template_folder=analysis_template_dir)

app.register_blueprint(home_blueprint,url_prefix='/home') 
app.register_blueprint(traffic_blueprint,url_prefix='/traffic') 
app.register_blueprint(pcap_blueprint,url_prefix='/pcap')
app.register_blueprint(webex_blueprint,url_prefix='/webex')
app.register_blueprint(ssh_blueprint,url_prefix='/ssh')
app.register_blueprint(owa_blueprint,url_prefix='/owa')
app.register_blueprint(backend_blueprint,url_prefix='/backend')
app.register_blueprint(redirect_blueprint, url_prefix='/redirect')


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=86, ssl_context=('cert.pem', 'key.pem'))

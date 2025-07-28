import os
import zipfile
UPLOAD_FOLDER = 'data/uploads_files'


# 判断文件类型
ALLOWED_EXTENSIONS = {'pcap', 'zip'}
def allowed_file(filename):
    return '.' in filename and filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS


def extract_zip(zip_file_path):
    extracted_files = []
    with zipfile.ZipFile(zip_file_path, 'r') as zip_ref:
        extract_folder = os.path.join(UPLOAD_FOLDER, '../extracted')
        os.makedirs(extract_folder, exist_ok=True)
        zip_ref.extractall(extract_folder)
        extracted_files = [os.path.join(extract_folder, file) for file in zip_ref.namelist()  if file.endswith('.pcap')]
    return extracted_files
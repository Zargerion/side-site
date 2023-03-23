from PIL import Image
import os

def jpgToPngAllDir(src_dir, dst_dir):
    """ задаем путь к исходной директории и директории, в которую будут сохраняться преобразованные файлы
        src_dir = "/path/to/source/directory"
        dst_dir = "/path/to/destination/directory """

    # перебираем все файлы в директории
    for filename in os.listdir(src_dir):
        # проверяем, что файл является изображением в формате JPEG
        if filename.endswith(".jpg"):
            # открываем файл с помощью модуля Pillow
            with Image.open(os.path.join(src_dir, filename)) as img:
                # изменяем формат изображения на WEBP
                img = img.convert("RGB").save(os.path.join(dst_dir, os.path.splitext(filename)[0] + ".webp"))

def jpgToPngOneFile(src_dir, dst_dir):
    """ задаем путь к исходной директории и директории, в которую будут сохраняться преобразованные файлы
        src_dir = "/path/to/source/directory"
        dst_dir = "/path/to/destination/directory """

    # перебираем все файлы в директории
    for i, filename in enumerate(os.listdir(src_dir)):
        # проверяем, что файл является изображением в формате JPEG и обрабатываем только первый файл
        if i == 0 and filename.endswith(".jpg"):
            # открываем файл с помощью модуля Pillow
            with Image.open(os.path.join(src_dir, filename)) as img:
                # изменяем формат изображения на WEBP
                img = img.convert("RGB").save(os.path.join(dst_dir, os.path.splitext(filename)[0] + ".webp"))
            # прерываем цикл, чтобы обработать только первый файл
            break

jpgToPngAllDir("C:/Users/щдуп/Pictures/aCamera", "C:/Users/щдуп/Pictures/aCameraNew")
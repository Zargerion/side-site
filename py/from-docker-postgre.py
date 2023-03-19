import docker

client = docker.from_env()

# Get the "app" container from the network
network_name = "sabter-site-2_custom"
container_name = "app"
network = client.networks.get(network_name)
container = network.containers.get(container_name)

# Get the IP address of the container
ip_address = container.attrs['NetworkSettings']['Networks'][network_name]['IPAddress']

print("IP address of the app container:", ip_address)

import psutil

# Find the Docker daemon process
for proc in psutil.process_iter(['pid', 'name', 'cmdline']):
    if proc.info['name'] == 'dockerd':
        cmdline = proc.info['cmdline']
        break

# Extract the port number from the command line arguments
port = None
for arg in cmdline:
    if arg.startswith('-H'):
        parts = arg.split(':')
        if len(parts) == 2 and parts[1].isdigit():
            port = int(parts[1])
            break

# Use the port number to construct the Docker host URL
if port is not None:
    docker_host = f'tcp://localhost:{port}'
    print(f"Doker host is {docker_host}")
else:
    raise ValueError('Could not determine Docker daemon port numbe')

#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
from setuptools import setup 

setup(
    name='ss2',
    version='0.0.1',
    author='Oleg OSS Sabter Zarg',
    description='FastApiApp',
    install_requires=[
    'fastapi==0.70.0',
    'uvicorn==0.15.0',
    'SQLAlchemy==1.4.26',
    'pytest==6.2.5',
    'requests==2.26.0',
    'psycopg2-binary==2.9.5',
    'alembic==1.10.1',
    'python-dotenv==1.0.0',
    ],
    scripts=['app/main.py']
)

#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

def some_function():
    for i in range(4):
        yield i
for i in some_function():
    print(i)

####################################################################

import psycopg2

# Подключение к базе данных
conn = psycopg2.connect(
    host="hostname",
    database="database_name",
    user="username",
    password="password"
)

# Создание курсора
cur = conn.cursor()

# Выполнение запроса
cur.execute("SELECT * FROM table_name")

# Получение результатов
rows = cur.fetchall()

# Вывод результатов
for row in rows:
    print(row)

# Закрытие соединения с базой данных
cur.close()
conn.close()

################################################################

import psycopg2

# Подключение к базе данных
conn = psycopg2.connect(
    host="hostname",
    database="database_name",
    user="username",
    password="password"
)

# Создание курсора
cur = conn.cursor()

# Открытие файла изображения в двоичном режиме
with open("image.jpg", "rb") as f:
    # Чтение содержимого файла
    image_data = f.read()
    
    # Подготовка запроса на добавление данных
    insert_query = "INSERT INTO images (data) VALUES (%s)"
    
    # Выполнение запроса на добавление данных
    cur.execute(insert_query, (psycopg2.Binary(image_data),))
    
    # Фиксация изменений в базе данных
    conn.commit()

# Закрытие соединения с базой данных
cur.close()
conn.close()
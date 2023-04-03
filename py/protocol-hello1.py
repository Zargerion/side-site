import socket
import ssl

HOST = 'localhost'
PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen(1)

conn, addr = s.accept()
conn_ssl = ssl.wrap_socket(conn, server_side=True, certfile='server.crt', keyfile='server.key')  # создаем SSL-сокет

data = conn_ssl.recv(1024)
if data.decode().startswith('привет'):
    name = data.decode()[6:]
    response = f'привет, {name}'.encode()
    conn_ssl.sendall(response)

    while True:
        data = conn_ssl.recv(1024)
        if not data:
            break
        response = f'ответ на "{data.decode()}"'.encode()
        conn_ssl.sendall(response)

conn_ssl.close()
s.close()

# openssl genrsa -out server.key 2048
# openssl req -new -x509 -sha256 -key server.key -out server.crt -days 3650
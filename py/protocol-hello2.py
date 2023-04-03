import socket
import ssl

HOST = 'localhost'
PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s_ssl = ssl.wrap_socket(s, cert_reqs=ssl.CERT_REQUIRED, ca_certs='server.crt')  # создаем SSL-сокет

s_ssl.connect((HOST, PORT))

name = input('Введите ваше имя: ')
s_ssl.sendall(f'привет{name}'.encode())

data = s_ssl.recv(1024)
print(data.decode())

while True:
    message = input('Введите сообщение для сервера: ')
    s_ssl.sendall(message.encode())
    data = s_ssl.recv(1024)
    print(data.decode())

s_ssl.close()
s.close()
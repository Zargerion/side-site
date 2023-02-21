import ipaddress

# Создаем объекты сетевых адресов
ips = []
for i in range(30):
    ips.append(ipaddress.IPv4Address('192.0.2.{}'.format(i)))
network = ipaddress.IPv4Network('192.0.2.0/24')

#for i in range(30):
#    print(ip[i])

# Проверяем, принадлежит ли IP-адрес сети
for ip in ips:
    if ip in network:
        print(f'{ip} принадлежит сети {network}')
    else:
        print(f'{ip} не принадлежит сети {network}')
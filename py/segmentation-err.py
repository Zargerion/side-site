import faulthandler

# Включение faulthandler для вывода стека вызовов при критических сбоях
faulthandler.enable()

# Симуляция ошибки сегментации
a = [1, 2, 3]
b = a[10]

import numpy as np

# Пример обучения нейронной сети на данных XOR

# Входные данные
x_train = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
# Выходные данные
y_train = np.array([0, 1, 1, 0])

# Инициализация весов
w = np.random.rand(2)
b = np.random.rand(1)
#input_weights = np.random.rand(2, 3)
#hidden_weights = np.random.rand(3, 1)

# Цикл обучения
for i in range(3):
   for j in range(4):
       x = x_train[j]
       y = y_train[j]
       print("x, y = ", x, y)
       # Вычисление выходного значения нейрона
       output = np.dot(x, w) + b
       print("output = ", output)
       # Вычисление ошибки
       error = y - output
       print("error = ", error)
       # Обновление весов
       w = w + error * x
       b = b + error
       print("w, b = ", w, b)

# Тестирование нейронной сети
x_test = np.array([1, 1])
output = np.dot(x_test, w) + b

print("output test = ", output) # Должно выдать значение близкое к 0

input_weights = np.random.rand(2, 3)
hidden_weights = np.random.rand(3, 1)
print(input_weights, '\n alo', hidden_weights)
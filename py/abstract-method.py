from abc import ABC, abstractmethod

class Math1(ABC):
    @abstractmethod
    def square(x):
        return x**2
    
print(Math1.square(5)) # 25

class MyMath(Math1):
    def square(self, x):
        return x**2

my_math = MyMath()
result = my_math.square(5)
print(result) # 25
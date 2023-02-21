import math

a = 0
for i in range(180):
    a+=1
    print("sin ", str(math.sin(math.radians(a))), "cos ", str(math.cos(math.radians(a))), " ", str(a))
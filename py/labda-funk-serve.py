import asyncio
import websockets

async def handler(websocket, path):
    async for message in websocket:
        # обрабатываем сообщение лямбда-функцией
        response = (lambda x: x.upper())(message)
        await websocket.send(response)

async def main():
    async with websockets.serve(handler, "localhost", 8765):
        await asyncio.Future()  # бесконечный цикл

asyncio.run(main())

# numbers = [1, 2, 3, 4, 5]
# squares = map(lambda x: x**2, numbers)
# print(list(squares)) # Выводит [1, 4, 9, 16, 25]

# include <iostream>
# 
# int main() {
#     int x = 10;
#     auto func = [x](int y) -> int { return x + y; };
#     std::cout << func(5) << std::endl; // Выводит 15
#     return 0;
# }
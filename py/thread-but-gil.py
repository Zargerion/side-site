import time
from datetime import datetime
from threading import Thread

def longRunningTask():
    time.sleep(3)
    return int(time.time()) % 100

def thread():
    r = longRunningTask()
    print(f"{r} {datetime.now()}")

def main():
    t = Thread(target=thread)
    t.start()
    a = 0
    while True:
        print(f"{a} | {datetime.now()}")
        a += 1
        time.sleep(1)

main()
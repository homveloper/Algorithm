from collections import deque
import sys

N = int(sys.stdin.readline())
arr = deque()


for i in sys.stdin.readlines():

    command = i.split()

    if command[0] == "push_front":
        arr.appendleft(command[1])
    elif command[0] == "push_back":
        arr.append(command[1])
    elif command[0] == "pop_front":
        try:
            print(arr.popleft())
        except:
            print(-1)
    elif command[0] == "pop_back":
        try:
            print(arr.pop())
        except:
            print(-1)
    elif command[0] == "size":
        print(len(arr))
    elif command[0] == "empty":
        print(int(len(arr) == 0))
    elif command[0] == "front":
        try:
            print(arr[0])
        except:
            print(-1)
    elif command[0] == "back":
        try:
            print(arr[-1])
        except:
            print(-1)








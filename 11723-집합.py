from sys import stdin

input = stdin.readline

M = int(input())
S = set()

for _ in range(M):
    cmd = input().strip()

    if cmd == "all":
        S = set(i for i in range(1,21))
    elif cmd == "empty":
        S = set()   
    else:
        cmd,i = cmd.split(); i = int(i)

        if cmd == "add":
            S.add(i)
        elif cmd == "check":
            print(int(i in S))
        elif cmd == "remove":
            try:
                S.remove(i)
            except:
                pass
        elif cmd == "toggle":
            if i in S:
                S.remove(i)
            else:
                S.add(i)
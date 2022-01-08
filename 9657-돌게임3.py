# turn 0 = 상근, 1 = 창영
def choose(n : int,turn : int, previous):
    if n == 0:
        if turn:
            print("CY")
            return
        else:
            print("SK")
            return

    if n>=4:
        choose(n-4, not turn, previous)
    
    if n>=3:
        choose(n-3, not turn, previous)
    
    if n>=1:
        choose(n-1, not turn, previous)

choose(int(input()),1)
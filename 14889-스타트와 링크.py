# 20C10 => 20! / 10! 10! => 4.4142574036356955e+24
N = int(input())
abilities = [list(map(int, input().split())) for i in range(N)]
members = set([i for i in range(N)])

# 10C2 => 10! / 8! 2! => 10 * 9 /2 = 4500
min_ability = 5000
case = []

def get_ability(team : set):
    team_ability = 0
  
    for i in team:
        for j in team:
            if i != j:
                team_ability += abilities[i][j]
    
    return team_ability

def combination(n : int,r : int, depth : int):
    global min_ability

    if r == 0:
        # start team
        start_team = get_ability(set(case))

        # link team
        link_team = get_ability(members - set(case))
        
        diff = abs(start_team - link_team)
        min_ability = min(diff, min_ability)
        return

    if depth == n:
        return

    case.append(depth)
    combination(n,r-1,depth+1)

    case.pop()
    combination(n,r,depth+1)

combination(N,N//2, 0)
print(min_ability)
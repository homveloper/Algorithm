S1 = input()
S2 = input()

T = [[0 for _ in range(len(S1) + 1)] for _ in range(len(S2)+1)]
lcs_length = 0

for i,s1 in enumerate(S1,1):
    length = 0
    for j,s2 in enumerate(S2,1):
        if s1 == s2:
            T[j][i] = T[j-1][i-1] + 1
            length = T[j-1][i-1] + 1
        else:
            T[j][i] = max(T[j-1][i], T[j][i-1])
    
    lcs_length = max(lcs_length, length)

temp1 = lcs_length
temp2 = temp1-1
for_j = len(S1)
lcs = ''

for i in range(len(S2),0,-1):
    for j in range(for_j,0,-1):
        if T[i][j] == temp1 and T[i][j-1] == temp2 and T[i-1][j-1] == temp2 and T[i-1][j] == temp2:
            temp1 -= 1
            temp2 -= 1
            lcs += S2[i-1]
            for_j = j
            break
    
print(lcs[::-1])
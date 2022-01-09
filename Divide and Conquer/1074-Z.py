# '''
# function F(x):
#   if F(x)의 문제가 간단 then:
#     return F(x)을 직접 계산한 값
#   else:
#     x를 y1, y2로 분할
#     F(y1)과 F(y2)를 호출
#     return F(y1), F(y2)로부터 F(x)를 구한 값
# '''

from queue import Queue
from sys import base_exec_prefix

N, R, C = map(int, input().split())
num = -1

def solution(n,r,c):
	global num

	if n == 0:
		num += 1
		if c == C and r == R:
			print(num)
			exit(0)
		return

	next = 2**(n-1)

	solution(n-1, r, c)
	solution(n-1, r, c + next)
	solution(n-1, r + next,c)
	solution(n-1, r + next, c + next)

def solution2(n,r,c):
	global num

	if n == 0:
		num += 1
		if c == C and r == R:
			print(num)
		return

	next = 2**(n-1)

	if r <= R < r + next and c<= C < c + next:
		# num += next * 0
		solution2(n-1, r, c)
	elif r<= R < r+ next and c + next <= C:
		num += next**2 * 1
		solution2(n-1, r, c + next)
	elif r+next <= R and c<= C < c + next: 
		num += next**2 * 2
		solution2(n-1, r + next,c)
	elif r+next <= R and c + next <= C:
		num += next**2 * 3
		solution2(n-1, r + next, c + next)

solution2(N,0,0)
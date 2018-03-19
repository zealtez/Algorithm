#-*-coding:utf-8-*-
import sys

#입력
N = input()
M = input()
f = []
ans = 0
for i in range(N):
    f.append([0]*N)

for i in range(M):
    a ,b = map(int, raw_input().split())
    if(a == 1) :
        ans+=1
    f[a - 1][b - 1] = 1
    f[b - 1][a - 1] = 1

#굳이 다 돌필요 없는 와샬-플로이드
#1번의 친구와 친구의 친구만 찾으면 되기 때문

for k in range(N):
        for j in range(N):
            if (j == 0 or j == k or f[0][j] >=1) : continue
            if(f[0][k] * f[k][j] == 1):
                f[0][j] = 2
                ans +=1

print ans

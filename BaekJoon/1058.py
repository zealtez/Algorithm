#-*-coding:utf-8-*-
import sys

#입력
N = input()
f = []
s = []
ans = [0]*N
for i in range(N):
    f.append(raw_input())
    s.append([0]*N)

for i in range(N):
    for j in range(N):
        if(f[i][j] == 'Y'):
            s[i][j] = 1
            ans[i] +=1
        else:
            s[i][j] = 0

#그래프 - 플로이드 와샬
for k in range(N):
    for i in range(N):
        for j in range(N):
            if (i == j or i == k or j == k or s[i][j] >=1) : continue
            if(s[i][k] * s[k][j] == 1):
                s[i][j] = 2
                ans[i] +=1
print max(ans)



S,C = map(int, raw_input().split())
N = []
for i in range(S):
    N.append(input())

left,right = 1,1000000000

while(left <= right):
    mid = (right + left) / 2
    remain,cnt = 0,0

    for val in N:
        if(val >= mid and  C > cnt ):
            cnt += val/mid
        remain += val%mid

    if(cnt >= C):
        left = mid + 1
    else:
        right = mid - 1

print remain

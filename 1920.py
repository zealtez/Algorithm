N = input()
lines = raw_input().split()
ans = []
nums = set()

#Input into set avoiding same val
for i in range(N):
    nums.add(int(lines[i]))

#Check Value
N = input()
lines = raw_input().split()
for i in range(N):
    if int(lines[i]) in nums:
        ans.append(1)
    else:
        ans.append(0)

for i in ans:
    print i


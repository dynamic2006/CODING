import os

print(os.getcwd())

def solve(left, right):
    left.sort()
    right.sort()
    totDist = sum(abs(l-r) for l, r in zip(left, right))
    return totDist

left = []
right = []

with open("input.in", "r") as file:
    for line in file:
        l,r = map(int, line.strip().split())
        left.append(l)
        right.append(r)

res = solve(left, right)
print(res)
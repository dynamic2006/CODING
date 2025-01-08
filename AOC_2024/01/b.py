def solve(left, right):
    score = 0
    for l in left:
        score += l*right.count(l)
    
    return score



left = []
right = []

with open("input.in" , "r") as file:
    for line in file:
        l,r = map(int, line.strip().split())
        left.append(l)
        right.append(r)

print(solve(left, right))

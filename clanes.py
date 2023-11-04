N, P, G = map(int, input().split())
m = []
num_todos = []

for i in range(N):
    num = 0
    total_P = 0
    total_G = 0
    K = int(input())
    for j in range(K):
        m.append(list(map(int, input().split())))
    while total_P < P and total_G < G:
        min_m = min(m)
        total_P += min_m[0]
        total_G += min_m[1]
        m.remove(min(m))
        num += 1
    if total_P > P or total_G > G:
        num -= 1
    num_todos.append(num)

print(num_todos)




n, k = list(map(int, input().split(' ')))
a = [[0]*k]*n
for i in range(n):
    a[i] = list(map(int, input().split(' ')))
    #a[i] = list(map(int, infile.readline().split(' ')))
k, m = list(map(int, input().split(' ')))
b = [[0]*m]*k
for i in range(k):
    b[i] = list(map(int, input().split(' ')))
c = [[0]*m for _ in range(n)]

for i in range(n):
    for j in range(m):
        for t in range(k):
            c[i][j] += a[i][t]*b[t][j]
        print(c[i][j], end=" ")
    print()
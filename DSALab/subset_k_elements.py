def back_tracking(n, k, i):
    for j in range(a[i-1]+1, n):
        a[i] = j
        if i == k:
            for t in range(1, k+1):
                print(a[t], end=" ")
            print("\n")
        else: back_tracking(n, k, i + 1)

n = 7
a = [i for i in range(8)]
back_tracking(n, 3, 1)

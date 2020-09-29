N, M = map(int, input().split())

A = [list(map(int, list(input()))) for _ in range(N)]
B = [list(map(int, list(input()))) for _ in range(N)]


def flip(x, y):
    for i in range(x, x + 3):
        for j in range(y, y + 3):
            A[i][j] = 1 - A[i][j]


def is_equal():
    for i in range(N):
        for j in range(M):
            if A[i][j] != B[i][j]:
                return False
    return True


count = 0

for n in range(N - 2):
    for m in range(M - 2):
        if A[n][m] != B[n][m]:
            flip(n, m)
            count += 1

if is_equal():
    print(count)
else:
    print(-1)

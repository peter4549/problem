import sys
sys.setrecursionlimit(10000)

T = int(input())
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def dfs(y, x):
    if field[y][x] == 1:
        field[y][x] = 0
        for i in range(4):
            p = dy[i] + y
            q = dx[i] + x
            if 0 <= p < N and 0 <= q < M:
                dfs(p, q)


for t in range(T):
    M, N, K = map(int, input().split())
    field = [[0] * M for _ in range(N)]
    count = 0

    for k in range(K):
        m, n = map(int, input().split())
        field[n][m] = 1

    for n in range(N):
        for m in range(M):
            if field[n][m] == 1:
                dfs(n, m)
                count += 1

    print(count)

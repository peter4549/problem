import sys
sys.setrecursionlimit(10000)

N = int(input())

area = [[int(_) for _ in input().split()] for _ in range(N)]
visited = [[False] * N for _ in range(N)]

dy = [1, -1, 0, 0]
dx = [0, 0, 1, - 1]


def dfs(n, m):
    if visited[n][m]:
        return

    visited[n][m] = True

    for i in range(4):
        y = n + dy[i]
        x = m + dx[i]

        if 0 <= y < N and 0 <= x < N:
            dfs(y, x)


def flood(height):
    for n in range(N):
        for m in range(N):
            if area[n][m] <= height:
                visited[n][m] = True
            else:
                visited[n][m] = False


max_count = 1
for height in range(1, 101):
    count = 0
    flood(height)

    for n in range(N):
        for m in range(N):
            if not visited[n][m]:
                dfs(n, m)
                count += 1

    if max_count < count:
        max_count = count

print(max_count)

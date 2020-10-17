# Depth-First Search

import sys
sys.setrecursionlimit(10000)

R, C = map(int, input().split())

grid = [[_ for _ in input()] for _ in range(R)]

dy = [-1, 0, 1]


def dfs(y, x):
    global pipeline_count
    global found_path

    if grid[y][x] == 'x' or found_path:
        return

    grid[y][x] = 'x'

    if x >= C - 1:
        pipeline_count += 1
        found_path = True
        return

    for i in range(3):
        q = y + dy[i]
        p = x + 1

        if 0 <= q < R and 0 <= p < C:
            dfs(q, p)


pipeline_count = 0
found_path = False

for r in range(R):
    found_path = False
    dfs(r, 0)

print(pipeline_count)

import bisect

N = int(input())
M = int(input())

count = -1
graph = dict()
visited = [False] * (N + 1)

for n in range(N):
    graph[n + 1] = []

for m in range(M):
    node_01, node_02 = map(int, input().split())
    bisect.insort(graph[node_01], node_02)
    bisect.insort(graph[node_02], node_01)


def dfs(x):
    global count

    if visited[x]:
        return

    visited[x] = True
    count += 1

    for i in graph[x]:
        dfs(i)


dfs(1)
print(count)

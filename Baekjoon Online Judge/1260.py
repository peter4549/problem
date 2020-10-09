import queue

N, M, V = map(int, input().split())

graph = dict()

for n in range(N):
    graph[n + 1] = []

for m in range(M):
    node_01, node_02 = map(int, input().split())
    graph[node_01].append(node_02)
    graph[node_02].append(node_01)

    graph[node_01].sort()
    graph[node_02].sort()

visited = [False] * (N + 1)


def dfs(x):
    if visited[x]:
        return

    visited[x] = True
    print(x, end=' ')

    for i in graph[x]:
        dfs(i)


def bfs(x):
    q = queue.Queue()
    visited[x] = True
    q.put(x)

    while not q.empty():
        y = q.get()
        print(y, end=' ')

        for i in graph[y]:
            if not visited[i]:
                visited[i] = True
                q.put(i)


dfs(V)
print()

for n in range(len(visited)):
    visited[n] = False

bfs(V)

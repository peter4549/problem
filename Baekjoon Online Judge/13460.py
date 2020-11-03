import queue

N, M = map(int, input().split())
board = [input() for _ in range(N)]

dy = [-1, 0, 1, 0]
dx = [0, -1, 0, 1]

visited = [[[[False] * 10 for _ in range(10)] * 10 for _ in range(10)] * 10 for _ in range(10)]


class Positions:
    def __init__(self):
        self.ry = 0
        self.rx = 0
        self.by = 0
        self.bx = 0
        self.count = 0


start = Positions()

for i in range(N):
    for j in range(M):
        if board[i][j] == 'R':
            start.ry = i
            start.rx = j
        elif board[i][j] == 'B':
            start.by = i
            start.bx = j


def bfs():
    count = -1
    q = queue.Queue()
    q.put(start)
    visited[start.ry][start.rx][start.by][start.bx] = True

    while not q.empty():
        p = q.get()

        if p.count > 10:
            break

        if board[p.ry][p.rx] == 'O' and board[p.by][p.bx] != 'O':
            count = p.count
            break

        for i in range(4):
            ry = p.ry
            rx = p.rx
            by = p.by
            bx = p.bx

            while True:
                if board[ry][rx] != '#' and board[ry][rx] != 'O':
                    ry += dy[i]
                    rx += dx[i]
                else:
                    if board[ry][rx] == '#':
                        ry -= dy[i]
                        rx -= dx[i]
                    break

            while True:
                if board[by][bx] != '#' and board[by][bx] != 'O':
                    by += dy[i]
                    bx += dx[i]

                else:
                    if board[by][bx] == '#':
                        by -= dy[i]
                        bx -= dx[i]
                    break

            if ry == by and rx == bx:
                if board[ry][rx] != 'O':
                    if abs(ry - p.ry) + abs(rx - p.rx) > abs(by - p.by) + abs(bx - p.bx):
                        ry -= dy[i]
                        rx -= dx[i]
                    else:
                        by -= dy[i]
                        bx -= dx[i]

            if not visited[ry][rx][by][bx]:
                visited[ry][rx][by][bx] = True
                next_p = Positions()
                next_p.ry = ry
                next_p.rx = rx
                next_p.by = by
                next_p.bx = bx
                next_p.count = p.count + 1
                q.put(next_p)

    return count


print(bfs())

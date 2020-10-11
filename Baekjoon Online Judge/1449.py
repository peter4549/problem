N, L = map(int, input().split())
points = list(map(int, input().split()))
points.sort()

count = 1
current_position = N - 1

for i in range(N - 2, -1, -1):
    for j in range(current_position - 1, -1, -1):
        if points[current_position] - points[j] + 1 > L:
            count += 1
            current_position = j

        if j == 0:
            break
    else:
        continue
    break

print(count)

N, L = map(int, input().split())
points = list(map(int, input().split()))
points.sort()

count = 1
current_point_index = N - 1

for i in range(N - 2, -1, -1):
    for j in range(current_point_index - 1, -1, -1):
        if points[current_point_index] - points[j] + 1 > L:
            count += 1
            current_point_index = j

        if j == 0:
            break
    else:
        continue
    break

print(count)


N, L = map(int, input().split())
points = list(map(int,input().split()))
points.sort()

count = 0
current_point = 0

for point in points:
    if current_point < point:
        current_point = point + L - 1
        count += 1

print(count)

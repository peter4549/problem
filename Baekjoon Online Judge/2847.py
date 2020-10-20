N = int(input())
scores = [int(input()) for _ in range(N)]

count = 0

for i in range(N - 1, 0, -1):
    if scores[i] <= scores[i - 1]:
        count += scores[i - 1] - scores[i] + 1
        scores[i - 1] = scores[i] - 1

print(count)

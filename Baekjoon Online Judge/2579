N = int(input())

scores = [0] * 300
stairs = [0] * 300

for i in range(N):
    stairs[i] = int(input())

scores[0] = stairs[0]
scores[1] = max(stairs[0] + stairs[1], stairs[1])
scores[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2])

for i in range(3, N):
    scores[i] = max(scores[i - 2] + stairs[i], scores[i - 3] + stairs[i - 1] + stairs[i])

print(scores[N - 1])

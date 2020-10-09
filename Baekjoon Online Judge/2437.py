N = int(input())
weights = [int(weight) for weight in input().strip().split()]
weights.sort()

weight_sum = 0

for i in range(0, len(weights)):
    if weights[i] > weight_sum + 1:
        break
    weight_sum += weights[i]

print(weight_sum + 1)

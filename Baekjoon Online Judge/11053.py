N = int(input())
numbers = [int(number) for number in input().strip().split()]

length = 0
lengths = [0] * N

for i in range(0, N):
    length = 0

    for j in range(0, i):
        if numbers[i] > numbers[j]:
            if length < lengths[j]:
                length = lengths[j]

    lengths[i] = length + 1

print(max(lengths))

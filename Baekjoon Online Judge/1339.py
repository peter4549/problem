N = int(input())
words = [input() for _ in range(N)]
frequency = dict()

for i in range(26):
    frequency[chr(i + 65)] = 0

for word in words:
    for i in range(len(word) - 1, -1, -1):
        frequency[word[len(word) - i - 1]] += pow(10, i)

sorted_frequency = sorted(frequency.items(), reverse=True, key=lambda item: item[1])

n = 10
for key, value in sorted_frequency:
    n -= 1

    for i in range(N):
        words[i] = words[i].replace(key, str(n))

    if n <= 0:
        break

print(sum(map(int, words)))

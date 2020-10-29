S = input()
count = 0

for i in range(1, len(S)):
    if S[i - 1] == S[0] and S[i - 1] != S[i]:
        count += 1

print(count)

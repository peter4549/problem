N, M = map(int, input().split())

if N == 1:
    print(1)
elif N == 2:
    print(min(4, int((M + 1) / 2)))
elif N >= 3:
    if M < 7:
        print(min(4, M))
    else:
        print(M - 2)

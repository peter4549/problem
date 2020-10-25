N = int(input())
count = N


def make_it_one(n, i, j, k):
    global count

    if count < i + j + k:
        return

    if n == 1:
        if count > i + j + k:
            count = i + j + k
        return
    if n % 3 == 0:
        make_it_one(n // 3, i + 1, j, k)
    if n % 2 == 0:
        make_it_one(n // 2, i, j + 1, k)
    make_it_one(n - 1, i, j, k + 1)


make_it_one(N, 0, 0, 0)

print(count)

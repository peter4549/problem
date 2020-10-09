i = 1

while True:
    L, P, V = map(int, input().split())
    if L == 0 and P == 0 and V == 0:
        break

    print(f'Case {i:d}: {(int(V / P) * L + min((V % P), L)):d}')
    i += 1
   

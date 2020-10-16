N, K = map(int, input().split())
appliances = [int(_) for _ in input().strip().split()]

in_use = []
count = 0

for i, appliance in enumerate(appliances):
    if appliance in in_use:
        pass
    elif len(in_use) < N:
        in_use.append(appliance)
    else:
        port = 0
        maximumDistance = 0

        for use in in_use:
            distance = 9999
            for k in range(i + 1, K):
                if use == appliances[k]:
                    distance = k
                    break

            if distance > maximumDistance:
                port = use
                maximumDistance = distance

        in_use.remove(port)
        count += 1
        in_use.append(appliance)

print(count)










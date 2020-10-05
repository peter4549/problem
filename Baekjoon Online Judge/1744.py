N = int(input())
numbers = [int(input()) for _ in range(N)]

numbers.sort(reverse=True)

positive_numbers = list(filter(lambda x: x > 0, numbers))
negative_numbers_including_zero = list(filter(lambda x: x <= 0, numbers))

sum_of_numbers = 0

if len(positive_numbers) == 1:
    sum_of_numbers += positive_numbers[0]
else:
    for i in range(1, len(positive_numbers), 2):
        if positive_numbers[i - 1] == 1 or positive_numbers[i] == 1:
            sum_of_numbers += positive_numbers[i - 1] + positive_numbers[i]
        else:
            sum_of_numbers += positive_numbers[i - 1] * positive_numbers[i]

        if i + 2 == len(positive_numbers):
            sum_of_numbers += positive_numbers[len(positive_numbers) - 1]

negative_numbers_including_zero.sort()

if len(negative_numbers_including_zero) == 1:
    sum_of_numbers += negative_numbers_including_zero[0]
else:
    for i in range(1, len(negative_numbers_including_zero), 2):
        sum_of_numbers += negative_numbers_including_zero[i - 1] * negative_numbers_including_zero[i]
        
        if i + 2 == len(negative_numbers_including_zero):
            sum_of_numbers += negative_numbers_including_zero[len(negative_numbers_including_zero) - 1]

print(sum_of_numbers)

start = int(input("Enter start: "))
end = int(input("Enter end: "))


def is_prime(num):
    if num > 1:
        for i in range(2, num):
            if num % i == 0:
                return False
        return True
    return False


list_prime_numbers = []
for i in range(start, end):
    if is_prime(i):
        list_prime_numbers.append(i)

print(list_prime_numbers)
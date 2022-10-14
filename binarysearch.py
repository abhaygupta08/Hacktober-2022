def binary(list, target):
    first = 0
    last = len(list) - 1

    while first <= last:
        mid = (first + last)//2

        if list[mid] == target:
            return mid
        elif list[mid] < target:
            first = mid + 1
        else:
            last = mid - 1
    return None

def verify(index):
    if index is not None:
        print(f"target Found at {index}")
    else:
        print("target not found")

numbers = [1,2,3,4,5,6,7,8,9,10]

result = binary(numbers, 6)
verify(result)

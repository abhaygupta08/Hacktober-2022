# fn to check whether string is palindrome
# Time Complexity = O(n) and Space Complexity = O(1)


def is_palindrome(string1):
    low = 0
    high = len(string1) - 1
    while low < high:
        if string1[low].lower() != string1[high].lower():
            return False
        else:
            low += 1
            high -= 1
    return True


# Driver's Code
string1 = "Abcba"

if is_palindrome(string1):
    print("String is palindrome")
else:
    print("String is not palindrome")

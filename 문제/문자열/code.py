str = input()

def isPelindrome(word):
    return word == word[::-1]

print(isPelindrome(str))
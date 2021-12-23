def solution(word) -> bool:
    previous = word[0]
    sequence = set(word[0])

    for i in word:
        if previous != i:
            previous = i
            if i not in sequence:
                sequence.add(i)
            else:
                return False

    return True

def main():
    N = int(input())
    count = 0

    for i in range(N):
        count += solution(input())

    print(count)

if __name__=="__main__":
    main()
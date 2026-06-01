def reverseMatrix(s: list) -> list:
    return [n[::-1] for n in s[::-1]]

def main() -> None:
    print(reverseMatrix([[1, 2], [3, 4]]))
    print(reverseMatrix([[1, 2, 3], [4, 5, 6]]))
    print(reverseMatrix([[1, 2, 3, 4]]))
    print(reverseMatrix([[1], [2], [3]]))
    print(reverseMatrix([[1]]))
    print(reverseMatrix([]))
    print(reverseMatrix([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))

if __name__ == "__main__":
    main()


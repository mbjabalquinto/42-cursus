def isPalindrome(s: str) -> bool:
    result: str = ""
    for p in s:
        if p.isalnum():
            result += p.lower()
    return result == result[::-1]    

def main() -> None:
    print(isPalindrome("madam"))
    print(isPalindrome("racecar"))
    print(isPalindrome("A man, a plan, a canal: Panama"))
    print(isPalindrome("hello"))


if __name__ == "__main__":
    main()


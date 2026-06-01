def Anagram(s1: str, s2: str) -> bool:
    return sorted(s1) == sorted(s2)

def main() -> None:
    print(Anagram("racecar", "carrace"))
    print(Anagram("racecar", "carace"))

if __name__ == "__main__":
    main()


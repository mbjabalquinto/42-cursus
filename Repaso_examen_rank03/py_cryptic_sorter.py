def count_vocals(target: str) -> int:
    vocals: str = "aeiouAEIOU"
    count: int = 0
    for t in target:
        if t in vocals:
            count += 1
    return count

def cryptic_sorter(tlist: list) -> list:
    return sorted(tlist, key=lambda x: (count_vocals(x), len(x), x.lower()))

def main() -> None:
    print(cryptic_sorter(["apple", "bat", "car", "ae", "b"]))
    print(cryptic_sorter(["dog", "cat", "hi", "a"]))
    print(cryptic_sorter(["bat", "cat", "ant"]))
    print(cryptic_sorter(["bbb", "ccc", "ddd"]))
    print([])

if __name__ == "__main__":
    main()


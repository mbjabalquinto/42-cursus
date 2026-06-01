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

if __name__ == "__main__":
    main()


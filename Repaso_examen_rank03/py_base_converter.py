def convert_base(num: str, from_base: int, to_base: int) -> str:
    if num == "0":
        return num
    try:
        result = int(num, from_base)
    except ValueError:
        return "ERROR"
    if to_base == 10:
        return str(result)
    alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    number: str = ""
    while result > 0:
        rest = result % to_base
        number += alphabet[rest]
        result //= to_base
    return number[::-1]

def main() -> None:
    print(convert_base("1010", 2, 10))
    print(convert_base("10", 10, 2))
    print(convert_base("1A", 16, 10))
    print(convert_base("26", 10, 16))
    print(convert_base("ZZZ", 36, 10))
    print(convert_base("0", 10, 2))
    print(convert_base("000", 2, 10))
    print(convert_base("2", 2, 10))


if __name__ == "__main__":
    main()


import sys


def main() -> None:
    argc: int = len(sys.argv)
    i: int = 1
    print("=== Command Quest ===")
    print(f"Program name: {sys.argv[0]}")
    if argc > 1:
        print(f"Arguments received: {argc - 1}")
        for arg in sys.argv[1:]:
            print(f"Argument {i}: {arg}")
            i += 1
    else:
        print("No arguments provided!")
    print(f"Total arguments : {argc}")


if __name__ == "__main__":
    main()

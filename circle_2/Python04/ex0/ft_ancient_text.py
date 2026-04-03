import sys
from typing import IO


def main() -> None:
    file_name: str = ""
    if len(sys.argv) > 1:
        file_name = sys.argv[1]
    else:
        print("Usage: ft_ancient_text.py <file>")
        return
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{file_name}'")
    file: IO[str] | None = None
    try:
        file = open(file_name, "r")
        text: str = file.read()
        print("==============================================================")
        print()
        print(text)
        print()
        print("==============================================================")
    except FileNotFoundError as e:
        print(f"Error opening file '{file_name}' {e}")
    except PermissionError as e:
        print(f"Error opening file '{file_name}' {e}")
    finally:
        if file is not None:
            file.close()
            print(f"File '{file_name}' closed.")


if __name__ == "__main__":
    main()

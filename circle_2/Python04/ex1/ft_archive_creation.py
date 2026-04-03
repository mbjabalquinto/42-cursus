import sys
from typing import IO


def read_file(file_name: str) -> str | None:
    text: str | None = None
    file: IO[str] | None = None
    try:
        file = open(file_name, "r")
        text = file.read()
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
    return text


def transform_text(text: str) -> str:
    if not text:
        return ""
    new_text: str = text.replace("\n", "#\n")
    if not text.endswith("\n"):
        new_text += "#"
    return new_text


def save_file(new_file: str, new_text: str) -> bool:
    file: IO[str] | None = None
    result: bool = False
    try:
        file = open(new_file, "w")
        file.write(new_text)
        result = True
    except PermissionError as e:
        print(f"Error saving file: {e}")
    finally:
        if file is not None:
            file.close()
    return result


def main() -> None:
    file_name: str = ""
    text: str | None = None
    if len(sys.argv) > 1:
        file_name = sys.argv[1]
    else:
        print("Usage: ft_ancient_text.py <file>")
        return
    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{file_name}'")
    text = read_file(file_name)
    print()
    print("Transform data:")
    print("===============")
    print()
    new_text: str = ""
    if not text:
        return
    new_text = transform_text(text)
    print(f"{new_text}")
    print("===============")
    new_file: str = input("Enter new file name (or empty):")
    if new_file == "":
        print("Not saving data.")
        return
    else:
        print(f"Saving data to '{new_file}'")
        if save_file(new_file, new_text):
            print(f"Data saved in file '{new_file}'.")


if __name__ == "__main__":
    main()

def secure_archive(
    file_name: str, operation: str = "r",
    data: str | None = None
) -> tuple[bool, str]:
    op: bool = True
    text: str = ""
    try:
        with open(file_name, operation) as file:
            if operation == "r":
                text = file.read()
            else:
                if data is not None:
                    file.write(data)
                    text = "Content successfully written to file"
    except FileNotFoundError as e:
        op = False
        text = str(e)
    except PermissionError as e:
        op = False
        text = str(e)
    result: tuple[bool, str] = (op, text)
    return result


def main() -> None:
    print("=== Cyber Archives Security ===")
    print()
    print("Using 'secure_archive' to read from a nonexistent file:")
    test1: tuple[bool, str] = secure_archive("/etc/file", "r")
    print(test1)
    print()
    print("Using 'secure_archive' to read from an inaccessible file:")
    test2: tuple[bool, str] = secure_archive("/etc/master.passwd", "r")
    print(test2)
    print()
    print("Using 'secure_archive' to read from a regular file:")
    test3: tuple[bool, str] = secure_archive("read.txt", "r")
    print(test3)
    print()
    print("Using 'secure_archive' to write "
          "previus content to a new file:")
    test4: tuple[bool, str] = secure_archive("write.txt", "w", "Hola amigo\n")
    print(test4)
    print()


if __name__ == "__main__":
    main()

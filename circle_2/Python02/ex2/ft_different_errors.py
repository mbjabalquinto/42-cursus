def garden_operations(operation_number: int) -> int:
    if operation_number == 0:
        return int("abc")
    elif operation_number == 1:
        return int(operation_number / 0)
    elif operation_number == 2:
        open("non/existent/file", "r")
        return 1
    elif operation_number == 3:
        return "text" + operation_number
    elif operation_number == 4:
        return int(operation_number)
    return 1


def test_error_types() -> None:
    i: int = 0
    print("=== Garden Error Types Demo ===")
    while i < 5:
        print(f"Testing operation {i}...")
        try:
            garden_operations(i)
        except ValueError as e:
            print(f"Caught ValueError: {e}")
        except ZeroDivisionError as e:
            print(f"Caught ZeroDivisionError: {e}")
        except FileNotFoundError as e:
            print(f"Caught FileNotFoundError: {e}")
        except TypeError as e:
            print(f"Caught TypeError: {e}")
        else:
            print("Operation completed successfully")
        i += 1
    print()
    print("All error types tested successfully!")


if __name__ == "__main__":
    test_error_types()

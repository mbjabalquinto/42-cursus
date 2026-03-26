def input_temperature(temp: str) -> int:
    num = int(temp)
    if num > 40:
        raise ValueError(f"{num}°C is too hot for plants (max 40°C)")
    elif num < 0:
        raise ValueError(f"{num}°C is too cold for plants (min 40°C)")
    else:
        return num


def test_temperature():
    print("=== Garden Temperature Checker ===")
    print()
    print("Input data is '25'")
    try:
        temp = input_temperature("25")
        print(f"Temperature is now {temp}°C")
    except ValueError as e:
        print(f"Caught intpu_temperature error: {e}")
    print()
    print("Input data is 'abc'")
    try:
        temp = input_temperature("abc")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    print()
    print("Input data is '100'")
    try:
        temp = input_temperature("100")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    print()
    print("Input data is '-50'")
    try:
        temp = input_temperature("-50")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    print()
    print("All tests completed - program didn't chash!")


if __name__ == "__main__":
    test_temperature()

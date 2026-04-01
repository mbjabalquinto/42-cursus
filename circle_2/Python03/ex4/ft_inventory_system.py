import sys


def main() -> None:
    items: dict[str, int] = {}
    temp: list[str] = []
    print("=== Inventory System Analysis ===")
    for arg in sys.argv[1:]:
        temp = arg.split(":")
        if len(temp) == 2:
            if temp[0] not in items:
                key_temp: str = temp[0]
                try:
                    value_temp: int = int(temp[1])
                    items.update({key_temp: value_temp})
                except ValueError as e:
                    print(f"Quantity error for '{key_temp}': {e}")
            else:
                print(f"Redundant item '{temp[0]}' - discarding")
        else:
            print(f"Error - invalid parameter '{arg}'")
    print(f"Got inventory: {items}")
    print(f"Item list: {list(items.keys())}")
    if len(items) > 0:
        total_values: int = sum(items.values())
        print(f"Total quantity of the {len(items)} items: {total_values}")
        for item in items:
            percent: float = float(items[item] * 100 / total_values)
            print(f"Item {item} represents {round(percent, 1)}%")
        temp_list = list(items.keys())
        max_value: int = items[temp_list[0]]
        min_value: int = items[temp_list[0]]
        max_key: str = temp_list[0]
        min_key: str = temp_list[0]
        for item in items:
            if items[item] > max_value:
                max_value = items[item]
                max_key = item
            if items[item] < min_value:
                min_value = items[item]
                min_key = item
        print(f"Item most abundant: {max_key} with quantity {max_value}")
        print(f"Item least abundant: {min_key} with quantity {min_value}")
    items.update({"new_magic_item": 3})
    print(f"Updated inventory: {items}")


if __name__ == "__main__":
    main()

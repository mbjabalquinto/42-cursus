from collections.abc import Callable
from typing import Any


def mage_counter() -> Callable:
    current_count: int = 0

    def count() -> int:
        nonlocal current_count
        current_count += 1
        return current_count
    return count


def spell_accumulator(initial_power: int) -> Callable:
    power: int = initial_power

    def accum_power(additional_power: int) -> int:
        nonlocal power
        power += additional_power
        return power
    return accum_power


def enchantment_factory(enchantment_type: str) -> Callable:
    def enchantment_item(item_name: str) -> str:
        return f"{enchantment_type} {item_name}"
    return enchantment_item


def memory_vault() -> dict[str, Callable]:
    mem: dict[str, Any] = {}

    def store(key: str, value: int) -> str:
        mem[key] = value
        return f"{value}"

    def recall(key: str) -> str:
        return f"{mem.get(key, 'Memory not found')}"
    return {"store": store, "recall": recall}


def main() -> None:
    count_a = mage_counter()
    count_b = mage_counter()
    print("Testing mage counter...")
    print(f"Counter_a call 1: {count_a()}")
    print(f"Counter_b call 1: {count_b()}")
    print(f"Counter_a call 2: {count_a()}")
    print()
    add_power = spell_accumulator(100)
    print("Testing spell accumulator...")
    print(f"Base 100, add 20: {add_power(20)}")
    print(f"Base 100, add 20: {add_power(30)}")
    print()
    frozen_enchantment = enchantment_factory("Frozen")
    flaming_enchantment = enchantment_factory("Flaming")
    print("Testing enchantment factory...")
    print(f"{frozen_enchantment('Shield')}")
    print(f"{flaming_enchantment('Sword')}")
    print()
    print("Testing memory vault...")
    memory = memory_vault()
    print(f"Store 'secret' = {memory['store']('secret', 42)}")
    print(f"Recall 'secret': {memory['recall']('secret')}")
    print(f"Recall 'unknown': {memory['recall']('unknown')}")


if __name__ == "__main__":
    main()

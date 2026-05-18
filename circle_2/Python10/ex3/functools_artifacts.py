from functools import reduce, partial, lru_cache, singledispatch
from operator import add, mul
from collections.abc import Callable
from typing import Any


def spell_reducer(spells: list[int], operation: str) -> int:
    if not spells:
        return 0
    if operation == "add":
        return reduce(add, spells)
    elif operation == "multiply":
        return reduce(mul, spells)
    elif operation == "max":
        return reduce(max, spells)
    elif operation == "min":
        return reduce(min, spells)
    else:
        raise ValueError(f"Unknown operation: {operation}")


def enchanter(power: int, type: str, target: str) -> str:
    return f"{type} enchantment to {target} hit for {power}"


def partial_enchanter(
    base_enchantment: Callable[[int, str, str], str]
) -> dict[str, Callable[[str], str]]:
    air_enchantment = partial(base_enchantment, 50, "air")
    fire_enchantment = partial(base_enchantment, 50, "fire")
    water_enchantment = partial(base_enchantment, 50, "water")
    partial_enchanters: dict[str, Callable[[str], str]] = {}
    partial_enchanters["air_enchantment"] = air_enchantment
    partial_enchanters["fire_enchantment"] = fire_enchantment
    partial_enchanters["water_enchantment"] = water_enchantment
    return partial_enchanters


@lru_cache
def memoized_fibonacci(n: int) -> int:
    if n <= 0:
        return 0
    if n == 1:
        return 1
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:
    @singledispatch
    def dispatcher(arg: Any) -> str:
        return "Unknown spell type"

    @dispatcher.register(int)
    def _(arg: int) -> str:
        return f"Damage spell: {arg} damage"

    @dispatcher.register(str)
    def _(arg: str) -> str:
        return f"Enchantment: {arg}"

    @dispatcher.register(list)
    def _(arg: list[Any]) -> str:
        return f"Multi-cast: {len(arg)} spells"
    return dispatcher


def main() -> None:
    spell_powers = [47, 20, 13, 37, 14, 36]
    print("Testing spell reducer...")
    try:
        print(f"Sum: {spell_reducer(spell_powers, 'add')}")
        print(f"Product: {spell_reducer(spell_powers, 'multiply')}")
        print(f"Max: {spell_reducer(spell_powers, 'max')}")
    except ValueError as e:
        print(e)
    print()
    print("Testing partial enchanter...")
    enchanters = partial_enchanter(enchanter)
    for _, value in enchanters.items():
        print(value("troll"))
    print()
    print("Testing memorized fibonacci...")
    print(f"Fib(0): {memoized_fibonacci(0)}")
    print(f"Fib(1): {memoized_fibonacci(1)}")
    print(f"Fib(10): {memoized_fibonacci(10)}")
    print(f"Fib(15): {memoized_fibonacci(15)}")
    print(f"Cache info: {memoized_fibonacci.cache_info()}")
    print()
    print("Testing spell dispatcher...")
    dispatch = spell_dispatcher()
    print(dispatch(42))
    print(dispatch("fireball"))
    print(dispatch([1, 2, 3]))
    print(dispatch(3.14))


if __name__ == "__main__":
    main()

from functools import reduce, partial, lru_cache
from operator import add, mul
from collections.abc import Callable


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


def partial_enchanter(base_enchantment: Callable[[int, str, str], str]) -> dict[str, Callable[[str], str]]:
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


def main() -> None:
    pass


if __name__ == "__main__":
    main()

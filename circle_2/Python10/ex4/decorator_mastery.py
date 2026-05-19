import time
from functools import wraps
from typing import Any
from collections.abc import Callable


def spell_timer(func: Callable) -> Callable:
    @wraps(func)
    def wrapper(*args: Any, **kwargs: Any) -> str:
        print(f"Casting {func.__name__}...")
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        print(f"Spell completed in {end - start:.3f} seconds")
        return result
    return wrapper


def power_validator(min_power: int) -> Callable:
    def decorator_factory(func: Callable) -> Callable:
        @wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> str:
            if not args and not kwargs:
                raise ValueError("No argument found")
            power = kwargs.get("power")
            if power is None:
                if len(args) > 0 and isinstance(args[0], int):
                    power = args[0]
                elif len(args) >= 3:
                    power = args[2]
            if power is not None and power < min_power:
                return "Insufficient power for this spell"
            return func(*args, **kwargs)
        return wrapper
    return decorator_factory


def retry_spell(max_attempts: int) -> Callable:
    def decorator_factory(func: Callable) -> Callable:
        @wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> str:
            current: int = 0
            result: str = ""
            for _ in range(max_attempts):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    current += 1
                    if current < max_attempts:
                        print(f"Spell failed, retrying... "
                              f"(attempt {current}/{max_attempts})")
                    else:
                        result = (f"Spell casting failed after "
                                  f"{max_attempts} attempts")
            return result
        return wrapper
    return decorator_factory


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        return len(name) >= 3 and all(c.isalpha() or c.isspace() for c in name)

    @power_validator(10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return f"Successfully cast {spell_name} with {power} power"


@spell_timer
def fireball() -> str:
    time.sleep(0.5)
    return "Result: Fireball cast!"


@power_validator(10)
def icepunch(power: int) -> str:
    return f"Icepunch hits with {power} power"


@retry_spell(3)
def bad_spell() -> str:
    raise Exception("Spell failed..")


@retry_spell(3)
def good_spell() -> str:
    return "Waaaaaaaagh spelled !"


def main() -> None:
    print("Testing spell timer...")
    print(fireball())
    print(icepunch(22))
    print(bad_spell())
    print(good_spell())
    print()
    print("Testing MageGuild...")
    mage = MageGuild()
    print(mage.validate_mage_name("Harry Potter"))
    print(mage.validate_mage_name("Snape8"))
    print(mage.validate_mage_name("HP"))
    print(mage.cast_spell("Lightning", 20))
    print(mage.cast_spell("Lightning", 14))


if __name__ == "__main__":
    main()

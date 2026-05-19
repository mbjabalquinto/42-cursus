import time
from functools import wraps
from typing import Callable


def spell_timer(func: Callable[[], str]) -> Callable[[], str]:
    @wraps(func)
    def wrapper(*args, **kwargs) -> str:
        print(f"Casting {func.__name__}...")
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        print(f"Spell completed in {end - start:.3f} seconds")
        return result
    return wrapper


def power_validator(min_power: int) -> Callable:
    pass


# def retry_spell(max_attempts: int) -> Callable:
#    pass


@spell_timer
def fireball() -> str:
    time.sleep(0.5)
    return "Result: Fireball cast!"


# class MageGuild:
#    @staticmethod
#    def validate_mage_name(name: str) -> bool:
#        pass
#
#    def cast_spell(self, spell_name: str, power: int) -> str:
#        pass


def main() -> None:
    print("Testing spell timer...")
    print(fireball())


if __name__ == "__main__":
    main()

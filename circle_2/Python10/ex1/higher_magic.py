from typing import Callable


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    def combined(power: int, target: str) -> tuple:
        return (spell1(target, power), spell2(target, power))
    return combined


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    def amplifier(target: str, power: int) -> str:
        return base_spell(target, power * multiplier)
    return amplifier


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    def conditional(target: str, power: int) -> str:
        if condition(target, power):
            result: str = spell(target, power)
        else:
            result = "Spell fizzled"
        return result
    return conditional


def spell_sequence(spells: list[Callable]) -> Callable:
    def sequence(target: str, power: int) -> list[str]:
        return [spell(target, power) for spell in spells]
    return sequence


def fireball(target: str, power: int) -> str:
    return f"Fireball hits {target} for {power} HP"


def meteor(target: str, power: int) -> str:
    return f"Meteor hits {target} for {power} HP"


def heal(target: str, power: int) -> str:
    return f"Heal restores {target} for {power} HP"


def condition_cast(target: str, power: int) -> bool:
    return power > 15


def main() -> None:
    power: int = 16
    targets: list[str] = ['Dragon', 'Goblin', 'Wizard', 'Knight']
    combined = spell_combiner(fireball, heal)
    print("Testing spell combiner...")
    print(f"Combined spell result: "
          f"{combined(power, targets[0])[0]}, "
          f"{combined(power, targets[0])[1]}")
    print()
    mega_meteor = power_amplifier(meteor, 3)
    print("Testing power amplifier...")
    print(f"Original: {meteor(targets[0], power)}, "
          f"Amplified: {mega_meteor(targets[0], power)}")
    condition = conditional_caster(condition_cast, fireball)
    print()
    print("Testing conditional caster...")
    print(f"{condition(targets[1], power)}")
    print()
    spell_sec = spell_sequence([fireball, meteor, heal])
    print("Testing spell sequence...")
    print(", ".join(spell_sec(targets[2], power)))


if __name__ == "__main__":
    main()

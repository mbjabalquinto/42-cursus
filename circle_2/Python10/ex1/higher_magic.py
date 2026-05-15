from collections.abc import Callable


def spell_combiner(
    spell1: Callable[[str, int], str], spell2: Callable[[str, int], str]
) -> Callable[[str, int], tuple[str, str]]:
    def combined(target: str, power: int) -> tuple[str, str]:
        return (spell1(target, power), spell2(target, power))
    return combined


def power_amplifier(
    base_spell: Callable[[str, int], str], multiplier: int
) -> Callable[[str, int], str]:
    def amplifier(target: str, power: int) -> str:
        return base_spell(target, power * multiplier)
    return amplifier


def conditional_caster(
    condition: Callable[[str, int], bool], spell: Callable[[str, int], str]
) -> Callable[[str, int], str]:
    def conditional(target: str, power: int) -> str:
        if condition(target, power):
            result: str = spell(target, power)
        else:
            result = "Spell fizzled"
        return result
    return conditional


def spell_sequence(
    spells: list[Callable[[str, int], str]]
) -> Callable[[str, int], list[str]]:
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
    res = combined(targets[0], power)
    print(f"Combined spell result: {res[0]}, {res[1]}")
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

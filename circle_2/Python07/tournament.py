from ex0 import FlameFactory, AquaFactory, CreatureFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import (
    NormalStrategy, DefensiveStrategy, AggressiveStrategy, BattleStrategy,
    InvalidStrategyError
)
Participant = tuple[CreatureFactory, BattleStrategy]
Round = list[Participant]


def battle(round: list[Participant]) -> None:
    for i in range(0, len(round)):
        for j in range(i + 1, len(round)):
            factory1, strategy1 = round[i]
            factory2, strategy2 = round[j]
            creature1 = factory1.create_base()
            creature2 = factory2.create_base()
            print(f"{creature1.describe()}")
            print("vs.")
            print(f"{creature2.describe()}")
            print("now fight!")
            try:
                strategy1.act(creature1)
                strategy2.act(creature2)
                print()
            except InvalidStrategyError as e:
                print(e)
                print()
                return


def main() -> None:
    phases: list[tuple[str, str]] = [
        ("Tournament 0", "(basic)"), ("Tournament 1", "(error)"),
        ("Tournament 2", "(multiple)")
    ]
    factory_flame = FlameFactory()
    factory_aqua = AquaFactory()
    factory_healing = HealingCreatureFactory()
    factory_transform = TransformCreatureFactory()
    combats: list[Round] = [
        [
            (factory_flame, NormalStrategy()),
            (factory_healing, DefensiveStrategy())
        ],
        [
            (factory_flame, AggressiveStrategy()),
            (factory_healing, DefensiveStrategy())
        ],
        [
            (factory_aqua, NormalStrategy()),
            (factory_healing, DefensiveStrategy()),
            (factory_transform, AggressiveStrategy())
        ],
    ]
    i: int = 0
    for combat in combats:
        num, typ = phases[i]
        print(f"{num} {typ}")
        fighters_list: list[str] = []
        for factory, strategy in combat:
            f_class = factory.__class__.__name__
            if "CreatureFactory" in f_class:
                f_name = factory.__class__.__name__.replace(
                    "CreatureFactory", "")
            else:
                f_name = factory.create_base().name
            s_name = strategy.__class__.__name__.replace("Strategy", "")
            fighters_list.append(f"({f_name}+{s_name})")
        print(f"[ {(', ').join(fighters_list)} ]")
        print("*** Tournament ***")
        print(f"{len(combat)} opponents involved")
        print()
        print("* Battle *")
        battle(combat)
        i += 1


if __name__ == "__main__":
    main()

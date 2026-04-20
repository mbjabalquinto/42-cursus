from ex0 import FlameFactory, AquaFactory, CreatureFactory


def test_battle(factory_flame: CreatureFactory, factory_aqua: CreatureFactory) -> None:
    creature1_base = factory_flame.create_base()
    creature2_base = factory_aqua.create_base()
    print("Testing battle")
    print(f"{creature1_base.describe()}")
    print("vs.")
    print(f"{creature2_base.describe()}")
    print("fight!")
    print(f"{creature1_base.attack()}")
    print(f"{creature2_base.attack()}")


def test_factory(factory: CreatureFactory) -> None:
    creature_base = factory.create_base()
    creature_evolved = factory.create_evolved()
    print("Testing factory")
    print(f"{creature_base.describe()}")
    print(f"{creature_base.attack()}")
    print(f"{creature_evolved.describe()}")
    print(f"{creature_evolved.attack()}")
    print()


def main() -> None:
    factory_flame = FlameFactory()
    test_factory(factory_flame)
    factory_aqua = AquaFactory()
    test_factory(factory_aqua)
    test_battle(factory_flame, factory_aqua)


if __name__ == "__main__":
    main()

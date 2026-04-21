from ex1 import (
    HealingCreatureFactory, TransformCreatureFactory, HealCapability,
    TransformCapability
)


def healing_creature_factory(factory: HealingCreatureFactory) -> None:
    print("base:")
    creature_base = factory.create_base()
    creature_evolved = factory.create_evolved()
    print(f"{creature_base.describe()}")
    print(f"{creature_base.attack()}")
    if isinstance(creature_base, HealCapability):
        print(f"{creature_base.heal()}")
    print("evolved:")
    print(f"{creature_evolved.describe()}")
    print(f"{creature_evolved.attack()}")
    if isinstance(creature_evolved, HealCapability):
        print(f"{creature_evolved.heal()}")


def transforming_creature_factory(factory: TransformCreatureFactory) -> None:
    print("base:")
    creature_base = factory.create_base()
    creature_evolved = factory.create_evolved()
    print(f"{creature_base.describe()}")
    print(f"{creature_base.attack()}")
    if isinstance(creature_base, TransformCapability):
        print(f"{creature_base.transform()}")
    print(f"{creature_base.attack()}")
    if isinstance(creature_base, TransformCapability):
        print(f"{creature_base.revert()}")
    print("evolved:")
    print(f"{creature_evolved.describe()}")
    print(f"{creature_evolved.attack()}")
    if isinstance(creature_evolved, TransformCapability):
        print(f"{creature_evolved.transform()}")
    print(f"{creature_evolved.attack()}")
    if isinstance(creature_evolved, TransformCapability):
        print(f"{creature_evolved.revert()}")


def main() -> None:
    print("Testing Creature with healing capability")
    healing_factory = HealingCreatureFactory()
    healing_creature_factory(healing_factory)
    print()
    print("Testing Creature with transform capability")
    transform_factory = TransformCreatureFactory()
    transforming_creature_factory(transform_factory)


if __name__ == "__main__":
    main()

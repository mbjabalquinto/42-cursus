from abc import ABC, abstractmethod
from ex0 import Creature
from ex1.creature import TransformCapability, HealCapability


class InvalidStrategyError(Exception):
    def __init__(self, message: str) -> None:
        super().__init__(message)


class BattleStrategy(ABC):
    @abstractmethod
    def act(self, creature: Creature) -> None:
        pass

    @abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        pass


class NormalStrategy(BattleStrategy):
    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise InvalidStrategyError(
                f"Battle error, aborting tournament: "
                f"Invalid Creature '{creature.name}' "
                f"for this normal strategy"
            )
        print(f"{creature.attack()}")

    def is_valid(self, creature: Creature) -> bool:
        return True


class AggressiveStrategy(BattleStrategy):
    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise InvalidStrategyError(
                f"Battle error, aborting tournament: "
                f"Invalid Creature '{creature.name}' "
                f"for this aggressive strategy"
            )
        print(f"{creature.attack()}")
        if isinstance(creature, TransformCapability):
            print(f"{creature.transform()}")
            print(f"{creature.attack()}")
            print(f"{creature.revert()}")

    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, TransformCapability)


class DefensiveStrategy(BattleStrategy):
    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise InvalidStrategyError(
                f"Battle error, aborting tournament: "
                f"Invalid Creature '{creature.name}' "
                f"for this defensive strategy"
            )
        print(f"{creature.attack()}")
        if isinstance(creature, HealCapability):
            print(f"{creature.heal()}")

    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, HealCapability)

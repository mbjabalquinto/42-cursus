class SecurePlant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self._height = height
        self._p_age = age

    def get_height(self) -> int:
        return (self._height)

    def get_age(self) -> int:
        return (self._p_age)

    def set_height(self, height: int) -> str:
        if height < 0:
            return (
                    f"\nInvalid operation attempted: "
                    f"height {height}cm [REJECTED]"
                    f"\nSecurity: Negative height rejected"
            )
        else:
            self._height = height
            return f"Height updated: {height}cm [OK]"

    def set_age(self, age: int) -> str:
        if age < 0:
            return (
                    f"\nInvalid operation attempted: "
                    f"age {age} days [REJECTED]"
                    f"\nSecurity: Negative age rejected"
            )
        else:
            self._p_age = age
            return f"Age updated: {age} days [OK]"


def ft_garden_security() -> None:
    print("=== Garden Security System  ===")
    plant = SecurePlant("rose", 25, 30)
    print(f"Plant created: {plant.name.capitalize()}")
    print(f"{plant.set_height(25)}")
    print(f"{plant.set_age(30)}")
    print(f"{plant.set_height(-5)}")
    print(f"{plant.set_age(-1)}")
    print(
            f"\nCurrent plant: "
            f"{plant.name.capitalize()} ("
            f"{plant.get_height()}cm, "
            f"{plant.get_age()} days)"
    )


if __name__ == "__main__":
    ft_garden_security()

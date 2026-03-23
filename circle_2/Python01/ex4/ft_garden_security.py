class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self._height = height
        self._age = age

    def show(self) -> None:
        print(
            f"{self.name.capitalize()}: "
            f"{self._height}cm, {self._age} days old\n"
            )

    def get_height(self) -> float:
        return (self._height)

    def get_age(self) -> int:
        return (self._age)

    def set_height(self, height: float) -> None:
        if height < 0:
            print(
                f"{self.name.capitalize()}: "
                f"Error, height can't be negative\n"
                f"Height update rejected"
            )
        else:
            self._height = height
            print(f"Height updated: {round(height, 1)}cm")

    def set_age(self, age: int) -> None:
        if age < 0:
            print(
                f"{self.name.capitalize()}: "
                f"Error, age can't be negative"
                f"\nAge update rejected"
            )
        else:
            self._age = age
            print(f"Age updated: {self._age} days")
            print()


def ft_garden_security() -> None:
    print("=== Garden Security System  ===")
    plant = Plant("rose", 15.0, 10)
    print("Plant created: ", end="")
    plant.show()
    plant.set_height(25.0)
    plant.set_age(30)
    plant.set_height(-5.0)
    plant.set_age(-1)
    print(
            f"\nCurrent state: "
            f"{plant.name.capitalize()}: "
            f"{round(plant.get_height(), 1)}cm, "
            f"{plant.get_age()} days old"
    )


if __name__ == "__main__":
    ft_garden_security()

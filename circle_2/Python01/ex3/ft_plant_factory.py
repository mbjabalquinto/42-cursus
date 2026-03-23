class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.p_age = age

    def show(self) -> None:
        print(f"Created: {self.name.capitalize()}: "
              f"{self.height}cm, "
              f"{self.p_age} days old")


def ft_plant_factory() -> None:
    plants: list[Plant] = [
            Plant("rose", 25.0, 30),
            Plant("oak", 200.0, 365),
            Plant("cactus", 5.0, 90),
            Plant("sunflower", 80.0, 45),
            Plant("fern", 15.0, 120)
            ]
    print("=== Plant Factory Output  ===")
    for x in plants:
        x.show()


if __name__ == "__main__":
    ft_plant_factory()

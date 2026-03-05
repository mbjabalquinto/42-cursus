class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.p_age = age

    def grow(self, days: int) -> None:
        self.height += days

    def age(self, days: int) -> None:
        self.p_age += days

    def get_info(self) -> str:
        return (f"{self.name.capitalize()}: "
                f"{self.height}cm, "
                f"{self.p_age} days old")


def ft_plant_growth() -> None:
    rose = Plant("rose", 25, 30)
    sunflower = Plant("sunflower", 80, 45)
    cactus = Plant("cactus", 15, 120)
    flowers = [rose, sunflower, cactus]
    days = 6

    print("=== Day 1  ===")
    for x in flowers:
        print(f"{x.get_info()}")
    print("=== Day 7 ===")
    for x in flowers:
        x.grow(days)
        x.age(days)
        print(f"{x.get_info()}")
        print(f"Growth this week: +{days}cm")


if __name__ == "__main__":
    ft_plant_growth()

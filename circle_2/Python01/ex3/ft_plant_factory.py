class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.p_age = age

    def get_info(self) -> str:
        return (f"{self.name.capitalize()} "
                f"({self.height}cm, "
                f"{self.p_age} days)")


def ft_plant_factory() -> None:
    seeds = [
            ("rose", 25, 30),
            ("oak", 200, 365),
            ("cactus", 5, 90),
            ("sunflower", 80, 45),
            ("fern", 15, 120)
            ]
    print("=== Plant Factory Output  ===")
    plants: list[Plant] = []
    for name, height, age in seeds:
        plant = Plant(name, height, age)
        plants.append(plant)
    for x in plants:
        print(f"Created: {x.get_info()}")
    print(f"\nTotal plants created: {len(plants)}")


if __name__ == "__main__":
    ft_plant_factory()

class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age


class Flower(Plant):
    def __init__(self, name: str, height: int, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color

    def bloom(self) -> str:
        return "is blooming beautifully!"


class Tree(Plant):
    def __init__(
                self,
                name: str,
                height: int,
                age: int,
                trunk_diameter: int
    ) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self) -> str:
        return "provides 78 square meters of shade"


class Vegetable(Plant):
    def __init__(
                self,
                name: str,
                height: int,
                age: int,
                harvest_season: str,
                nutritional_value: str
    ) -> None:
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value


def ft_plant_types() -> None:
    print("=== Garden Plant Types ===\n")
    flower = Flower("rose", 25, 30, "red color")
    flower2 = Flower("sunflower", 80, 45, "yellow")
    tree = Tree("oak", 500, 1825, 50)
    tree2 = Tree("pine", 400, 1000, 30)
    vegetable = Vegetable("tomato", 80, 90, "summer harvest", "vitamin C")
    vegetable2 = Vegetable("carrot", 15, 60, "spring harvest", "vitamin A")
    print(
            f"{flower.name.capitalize()} (Flower): "
            f"{flower.height}cm, "
            f"{flower.age} days, "
            f"{flower.color}"
    )
    print(f"{flower.name.capitalize()} {flower.bloom()}\n")
    print(
            f"{tree.name.capitalize()} (Tree): "
            f"{tree.height}cm, "
            f"{tree.age} days, "
            f"{tree.trunk_diameter}cm diameter"
    )
    print(f"{tree.name.capitalize()} {tree.produce_shade()}\n")
    print(
            f"{vegetable.name.capitalize()} (Vegetable): "
            f"{vegetable.height}cm, "
            f"{vegetable.age} days, "
            f"{vegetable.harvest_season}"
    )
    print(
            f"{vegetable.name.capitalize()} "
            f"is rich in {vegetable.nutritional_value}"
    )
    print(
            f"\n{flower2.name.capitalize()} (Flower): "
            f"{flower2.height}cm, "
            f"{flower2.age} days, "
            f"{flower2.color}"
    )
    print(f"{flower2.name.capitalize()} {flower2.bloom()}\n")
    print(
            f"{tree2.name.capitalize()} (Tree): "
            f"{tree2.height}cm, "
            f"{tree2.age} days, "
            f"{tree2.trunk_diameter}cm diameter"
    )
    print(f"{tree2.name.capitalize()} {tree2.produce_shade()}\n")
    print(
            f"{vegetable2.name.capitalize()} (Vegetable): "
            f"{vegetable2.height}cm, "
            f"{vegetable2.age} days, "
            f"{vegetable2.harvest_season}"
    )
    print(
            f"{vegetable2.name.capitalize()} "
            f"is rich in {vegetable2.nutritional_value}"
    )


if __name__ == "__main__":
    ft_plant_types()

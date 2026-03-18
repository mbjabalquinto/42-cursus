class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def special_info(self) -> str:
        return ""

class FloweringPlant(Plant):
    def __init__(self, name: str, height: int, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color

    def bloom(self) -> str:
        return "is blooming beautifully!"

    def __str__(self) -> str:
        return (
                f"{self.name.capitalize()} (Flower): "
                f"{self.height}cm, "
                f"{self.age} days, "
                f"{self.color}"
        )

    def special_info(self) -> str:
        return f"{self.name.capitalize()} {self.bloom()}"


class PrizeFlower(FloweringPlant):
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

    def __str__(self) -> str:
        return (
                f"{self.name.capitalize()} (Tree): "
                f"{self.height}cm, "
                f"{self.age} days, "
                f"{self.trunk_diameter}cm diameter"
        )

    def special_info(self) -> str:
        return f"{self.name.capitalize()} {self.produce_shade()}"

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

    def __str__(self) -> str:
        return (
                f"{self.name.capitalize()} (Vegetable): "
                f"{self.height}cm, "
                f"{self.age} days, "
                f"{self.harvest_season}"
        )

    def special_info(self) -> str:
        return f"{self.name.capitalize()} is rich in {self.nutritional_value}"

def ft_plant_types() -> None:
    print("=== Garden Plant Types ===\n")
    plants: list[Plant]
    plants = [
                Flower("rose", 25, 30, "red color"),
                Flower("sunflower", 80, 45, "yellow"),
                Tree("oak", 500, 1825, 50),
                Tree("pine", 400, 1000, 30),
                Vegetable("tomato", 80, 90, "summer harvest", "vitamin C"),
                Vegetable("carrot", 15, 60, "spring harvest", "vitamin A")
              ]
    for x in plants:
        print(f"{x}")
        info = x.special_info()
        if info:
            print(f"{info}\n")


if __name__ == "__main__":
    ft_plant_types()

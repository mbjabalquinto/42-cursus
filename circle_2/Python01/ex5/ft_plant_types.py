class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self._height = height
        self._age = age

    def grow(self, amount: float) -> None:
        self._height += amount

    def age(self, days: int) -> None:
        self._age += days

    def show(self):
        print(
            f"{self.name.capitalize()}: "
            f"{round(self._height, 1)}cm, "
            f"{self._age} days old"
        )

class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color

    def bloom(self) -> None:
        print(f"[asking the {self.name} to bloom]")
        super().show()
        print(
            f"Color: {self.color}\n"
            f"{self.name.capitalize()} is blooming beautifully!"
        )
        print()

    def show(self) -> None:
        super().show()
        print(
                f"Color: {self.color}\n"
                f"{self.name.capitalize()} "
                f"has not bloomed yet"
        )


class Tree(Plant):
    def __init__(
                self,
                name: str,
                height: float,
                age: int,
                trunk_diameter: float
    ) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self) -> None:
        print(
            f"[asking the {self.name} to produce shade]\n"
            f"Tree {self.name.capitalize()} "
            f"now produces a shade of "
            f"{round(self._height, 1)}cm long "
            f"and {round(self.trunk_diameter, 1)}cm wide."
        )
        print()

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter: {round(self.trunk_diameter,1)}cm")


class Vegetable(Plant):
    def __init__(
                self,
                name: str,
                height: float,
                age: int,
                harvest_season: str,
                nutritional_value: int
    ) -> None:
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def _update_nutritional_value(self) -> None:
        self.nutritional_value += 1
    
    def age(self, days: int) -> None:
        super().age(days)
        self._update_nutritional_value()

    def grow(self, amount: float) -> None:
        super().grow(amount)
        self._update_nutritional_value()
        
    
    def show(self) -> None:
        print(
                f"{self.name.capitalize()}: "
                f"{round(self._height, 1)}cm, "
                f"{self._age} days old\n"
                f"Harvest season: {self.harvest_season}\n"
                f"Nutritional value: {self.nutritional_value}"
        )


def ft_plant_types() -> None:
    print("=== Garden Plant Types ===")
    flowers: list[Flower]
    trees: list[Tree]
    vegetables: list[Vegetable]
    flowers = [
        Flower("rose", 15.0, 10, "red"),
        Flower("sunflower", 80, 45, "yellow")
    ]
    trees = [
        Tree("oak", 200.0, 365, 5.0),
        Tree("pine", 400.0, 1000, 3.0)
    ]
    vegetables = [
        Vegetable("tomato", 5.0, 10, "April", 0),
        Vegetable("carrot", 15.2, 60, "spring harvest", 0)
    ]
    for flower in flowers:
        print("=== Flower")
        flower.show()
        flower.bloom()
    for tree in trees:
        print("=== Tree")
        tree.show()
        tree.produce_shade()
    for vegetable in vegetables:
        print("=== Vegetable")
        vegetable.show()
        print(f"[make {vegetable.name} grow and age for 20 days]")
        vegetable.age(20)
        vegetable.grow(42.0)
        vegetable.show()
        print()



if __name__ == "__main__":
    ft_plant_types()

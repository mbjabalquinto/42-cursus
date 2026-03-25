class Plant:
    class Stats:
        def __init__(self, plant_name: str) -> None:
            self.plant_name = plant_name
            self._cont_show = 0
            self._cont_grow = 0
            self._cont_age = 0

        def increment_show(self) -> None:
            self._cont_show += 1

        def increment_age(self) -> None:
            self._cont_age += 1

        def increment_grow(self) -> None:
            self._cont_grow += 1

        def display(self) -> None:
            print(
                f"[statistics for {self.plant_name.capitalize()}]\n"
                f"Stats: {self._cont_grow} grow, "
                f"{self._cont_age} age, {self._cont_show} show"
            )

    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self._height = height
        self._age = age
        self.stats = self.Stats(self.name)

    def show(self) -> None:
        print(
            f"{self.name.capitalize()}: "
            f"{round(self._height, 1)}cm, "
            f"{self._age} days old"
        )
        self.stats.increment_show()

    def age(self) -> None:
        self.stats.increment_age()

    def grow(self) -> None:
        self.stats.increment_grow()

    @staticmethod
    def check_age(age: int) -> bool:
        return age > 365

    @classmethod
    def anonymous_plant(cls) -> 'Plant':
        return cls("unknown plant", 0.0, 0)


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color

    def grow(self) -> None:
        super().grow()
        self._height += 8

    def bloom(self) -> None:
        super().show()
        print(
            f"Color: {self.color}\n"
            f"{self.name.capitalize()} is blooming beautifully!"
        )

    def show(self) -> None:
        super().show()
        print(
                f"Color: {self.color}\n"
                f"{self.name.capitalize()} "
                f"has not bloomed yet"
        )


class Seed(Flower):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age, color)
        self._seeds = 0

    def grow(self) -> None:
        super().grow()
        self._height += 12.0

    def age(self) -> None:
        super().age()
        self._age += 20

    def seed(self) -> None:
        self._seeds = 42

    def bloom(self) -> None:
        super().bloom()
        print(f"Seeds: {self._seeds}")

    def show(self) -> None:
        super().show()
        print(f"Seeds: {self._seeds}")


class Tree(Plant):
    class Stats(Plant.Stats):
        def __init__(self, plant_name: str) -> None:
            super().__init__(plant_name)
            self._cont_shade = 0

        def increment_shade(self) -> None:
            self._cont_shade += 1

        def display(self) -> None:
            print(
                f"[statistics for {self.plant_name.capitalize()}]\n"
                f"Stats: {self._cont_grow} grow, "
                f"{self._cont_age} age, {self._cont_show} show, "
                f"{self._cont_shade} shade"
            )

    def __init__(
                self,
                name: str,
                height: float,
                age: int,
                trunk_diameter: float
    ) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter
        self.stats: Tree.Stats = self.Stats(self.name)

    def produce_shade(self) -> None:
        self.stats.increment_shade()
        print(
            f"Tree {self.name.capitalize()} "
            f"now produces a shade of "
            f"{round(self._height, 1)}cm long "
            f"and {round(self.trunk_diameter, 1)}cm wide."
        )

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter: {round(self.trunk_diameter, 1)}cm")


def ft_garden_analytics() -> None:
    flowers: list[Flower] = [
        Flower("rose", 15.0, 10, "red"),
        Flower("tulip", 10.0, 5, "yellow")
    ]
    trees: list[Tree] = [
        Tree("oak", 200.0, 365, 5.0),
        Tree("pine", 250.0, 400, 4.5)
    ]
    seeds: list[Seed] = [
        Seed("sunflower", 80.0, 45, "yellow"),
        Seed("lily", 50.0, 80, "purple")
    ]
    unknown: list[Plant] = [
        Plant.anonymous_plant(),
        Plant.anonymous_plant()
    ]
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.check_age(30)}")
    print(f"Is 400 days more than a year? -> {Plant.check_age(400)}")
    print()
    for flower in flowers:
        print("=== Flower")
        flower.show()
        flower.stats.display()
        print(f"[asking the {flower.name} to grow and bloom]")
        flower.grow()
        flower.bloom()
        flower.stats.display()
        print()
    for tree in trees:
        print("=== Tree")
        tree.show()
        tree.stats.display()
        print(f"[asking the {tree.name} to produce shade]")
        tree.produce_shade()
        tree.stats.display()
        print()
    for seed in seeds:
        print("=== Seed")
        seed.show()
        print(f"[make {seed.name} grow, age and bloom]")
        seed.bloom()
        seed.grow()
        seed.age()
        seed.seed()
        seed.stats.display()
        print()
    for u in unknown:
        print("=== Anonymous")
        u.show()
        u.stats.display()
        print()


if __name__ == "__main__":
    ft_garden_analytics()

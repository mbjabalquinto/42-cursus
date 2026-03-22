class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.p_age = age
        self.initial_height = height

    def grow(self, height: float) -> None:
        self.height += height

    def age(self, day: int) -> None:
        self.p_age += day

    def show(self) -> None:
        print(f"{self.name.capitalize()}: "
              f"{round(self.height, 1)}cm, "
              f"{self.p_age} days old")


def ft_plant_growth() -> None:
    plant = Plant("rose", 25.0, 30)
    height = 0.8
    grow_time = 1
    print("=== Garden Plant Growth ===")
    for day in range(1, 8):
        print(f"=== Day {day}  ===")
        plant.show()
        if day < 7:
            plant.grow(height)
            plant.age(grow_time)
    print(f"Growth this week: "
          f"{round(plant.height - plant.initial_height, 1)}cm")


if __name__ == "__main__":
    ft_plant_growth()

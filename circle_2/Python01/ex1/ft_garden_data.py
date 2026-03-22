class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self) -> None:
        print(f"{self.name.capitalize()}: {self.height}cm, {self.age} days old")

def ft_garden_data() -> None:
    flowers = [
    Plant("rose", 25, 30),
    Plant("sunflower", 80, 45),
    Plant("cactus", 15, 120)
    ]
    print("=== Garden Plant Registry ===")
    for x in flowers:
        x.show()


if __name__ == "__main__":
    ft_garden_data()

class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age


def ft_garden_data() -> None:
    rose = Plant("rose", 25, 30)
    sunflower = Plant("sunflower", 80, 45)
    cactus = Plant("cactus", 15, 120)
    flowers = [rose, sunflower, cactus]
    print("=== Garden Plant Registry ===")
    for x in flowers:
        print(f"{x.name.capitalize()}: {x.height}cm, {x.age} days old")


if __name__ == "__main__":
    ft_garden_data()

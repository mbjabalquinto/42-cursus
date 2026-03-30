class PlantError(Exception):
    def __init__(self, message: str = "Unknown Plant error") -> None:
        super().__init__(message)


def water_plant(plant_name: str) -> None:
    if plant_name == plant_name.capitalize():
        print(f"Watering {plant_name}: [OK]")
    else:
        raise PlantError(f"Invalid plant name to water: '{plant_name}'")


def test_watering_system() -> None:
    print("=== Garden Watering System ===")
    print()
    print("Testing valid plants...")
    print("Opening watering system")
    try:
        water_plant("tomato".capitalize())
        water_plant("letucce".capitalize())
        water_plant("carrots".capitalize())
    except PlantError as e:
        print(f"Caught PlantError: {e}")
    finally:
        print("Closing watering system")
    print()
    print("Testing invalid plants...")
    print("Opening watering system")
    try:
        water_plant("tomato".capitalize())
        water_plant("letucce")
        water_plant("carrots".capitalize())
    except PlantError as e:
        print(f"Caught PlantError: {e}")
        print(".. ending tests and returning to main")
        return
    finally:
        print("Closing watering system")
        print()


def main() -> None:
    test_watering_system()
    print("Cleanup always happens, even with errors!")


if __name__ == "__main__":
    main()

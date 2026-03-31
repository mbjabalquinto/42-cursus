import math


def get_player_pos() -> tuple:
    coords: tuple = ()
    try:
        x_str, y_str, z_str = input(
            "Enter new coordinates as floats in format 'x, y ,z': "
            ).split(',')
    except ValueError:
        print("Invalid syntax")
        get_player_pos()
    x, y, z = float(x_str), float(y_str), float(z_str)
    coords = (x, y, z)
    return coords


def main() -> None:
    coords1: tuple = ()
    coords2: tuple = ()
    print("=== Game Coordinate System ===")
    print()
    print("Get a first set of coordinates")
    coords1 = get_player_pos()
    print(f"Got a first tuple: {coords1}")
    print(f"It includes: X={coords1[0]}, Y={coords1[1]}, Z={coords1[2]}")
    x1, y1, z1 = coords1
    x2, y2, z2 = 0, 0, 0
    print(
        "Distance to center: "
        f"{round(math.sqrt((x2 - x1)**2 + (y2 - y1)**2 + (z2 - z1)**2), 4)}"
    )
    print()
    print("Get a second set of coordinates")
    coords2 = get_player_pos()
    print(f"Got a second tuple: {coords2}")
    x2, y2, z2 = coords2
    print(
        "Distance between the 2 sets of coordinates: "
        f"{round(math.sqrt((x2 - x1)**2 + (y2 - y1)**2 + (z2 - z1)**2), 4)}"
    )


if __name__ == "__main__":
    main()

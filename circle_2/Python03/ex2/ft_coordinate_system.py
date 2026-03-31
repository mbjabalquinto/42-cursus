import math


def get_player_pos() -> tuple:
    coords: tuple = ()
    coords_str: list[str] = []
    coords_float: list[float] = []
    while True:
        coords_str = input(
            "Enter new coordinates as floats in format 'x, y ,z': "
        ).split(',')
        if len(coords_str) != 3:
            print("Invalid syntax")
            continue
        for coord in coords_str:
            try:
                coords_float += [float(coord)]
            except ValueError as e:
                print(f"Error on parameter '{coord}': {e}")
                coords_float = []
                break
        if len(coords_float) == 3:
            break
    x, y, z = coords_float
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

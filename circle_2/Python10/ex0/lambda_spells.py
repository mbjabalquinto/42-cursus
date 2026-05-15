from typing import Any


def artifact_sorter(artifacts: list[dict[str, Any]]) -> list[dict[str, Any]]:
    try:
        artifacts = sorted(
            artifacts, key=lambda artifact: artifact["power"], reverse=True
        )
    except Exception as e:
        print(f"Error sortering data: {e}")
    return artifacts


def power_filter(
    mages: list[dict[str, Any]], min_power: int
) -> list[dict[str, Any]]:
    try:
        mages = list(filter(lambda mage: mage["power"] >= min_power, mages))
    except Exception as e:
        print(f"Error filtering data: {e}")
    return mages


def spell_transformer(spells: list[str]) -> list[str]:
    try:
        spells = list(map(lambda name: f"* {name} *", spells))
    except Exception as e:
        print(f"Error transforming data: {e}")
    return spells


def mage_stats(mages: list[dict[str, Any]]) -> dict[str, int | float]:
    stats: dict[str, int | float] = {}
    try:
        stats["max_power"] = max(
            mages, key=lambda mage: mage["power"])["power"]
        stats["min_power"] = min(
            mages, key=lambda mage: mage["power"])["power"]
        stats["avg_power"] = round(
            sum(mage["power"] for mage in mages) / len(mages), 2
            )
    except Exception as e:
        print(f"Error calculating stats: {e}")
    return stats


def main() -> None:
    artifacts: list[dict[str, Any]] = [
        {'name': 'Storm Crown', 'power': 72, 'type': 'relic'},
        {'name': 'Light Prism', 'power': 109, 'type': 'accessory'},
        {'name': 'Light Prism', 'power': 60, 'type': 'focus'},
        {'name': 'Storm Crown', 'power': 99, 'type': 'relic'}
    ]
    mages: list[dict[str, Any]] = [
        {'name': 'Luna', 'power': 71, 'element': 'ice'},
        {'name': 'Liam', 'power': 84, 'element': 'wind'},
        {'name': 'Sage', 'power': 68, 'element': 'water'},
        {'name': 'Casey', 'power': 83, 'element': 'light'},
        {'name': 'Rowan', 'power': 84, 'element': 'fire'}
    ]
    spells = ['flash', 'earthquake', 'meteor', 'heal']
    min_power: int = 80
    print("Testing artifact sorter...")
    sorted_arts = artifact_sorter(artifacts)
    if not sorted_arts:
        print("Error: artifacts list is empty..")
    else:
        print(
            f"{sorted_arts[0]['name']} ({sorted_arts[0]['power']} power) "
            "comes before "
            f"{sorted_arts[1]['name']} ({sorted_arts[1]['power']} power)"
        )
    print()
    print("Testing power filter...")
    power_filt = power_filter(mages, min_power)
    for item in power_filt:
        print(*(f"{key}: {value} " for key, value in item.items()))
    print()
    print("Testing spell transformer...")
    print(*spell_transformer(spells))
    print()
    print("Testing mage stats")
    stats = mage_stats(mages)
    print(*(f"{key}: {value} " for key, value in stats.items()))


if __name__ == "__main__":
    main()

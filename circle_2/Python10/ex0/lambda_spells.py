def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    artifacts = sorted(
        artifacts, key=lambda artifact: artifact["power"], reverse=True
    )
    return artifacts


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    mages = list(filter(lambda mage: mage["power"] >= min_power, mages))
    return mages


def spell_transformer(spells: list[str]) -> list[str]:
    spells = list(map(lambda name: "*" + name + "*", spells))
    return spells


def mage_stats(mages: list[dict]) -> dict:
    stats: dict = {}
    stats["max_power"] = max(mages, key=lambda mage: mage["power"])
    stats["min_power"] = min(mages, key=lambda mage: mage["power"])
    stats["avg_power"] = round(
        sum(mage["power"] for mage in mages) / len(mages), 2
        )
    return stats


def main() -> None:
    artifacts = [
        {'name': 'Storm Crown', 'power': 72, 'type': 'relic'},
        {'name': 'Light Prism', 'power': 109, 'type': 'accessory'},
        {'name': 'Light Prism', 'power': 60, 'type': 'focus'},
        {'name': 'Storm Crown', 'power': 99, 'type': 'relic'}
    ]
    mages = [
        {'name': 'Luna', 'power': 71, 'element': 'ice'},
        {'name': 'Casey', 'power': 84, 'element': 'wind'},
        {'name': 'Sage', 'power': 68, 'element': 'water'},
        {'name': 'Casey', 'power': 83, 'element': 'light'},
        {'name': 'Rowan', 'power': 84, 'element': 'fire'}
    ]
    spells = ['flash', 'earthquake', 'meteor', 'heal']
    # min_power: dict = min(mages, key=lambda mage: mage["power"])
    min_power: int = 80
    print("Testing artifact sorter...")
    sorted_arts = artifact_sorter(artifacts)
    print(
        f"{sorted_arts[0]['name']} ({sorted_arts[0]['power']} power) "
        "comes before "
        f"{sorted_arts[1]['name']} ({sorted_arts[1]['power']} power)"
    )
    print()
    print("Testing power filter...")
    # print(power_filter(mages, min_power["power"]))
    power_filt = power_filter(mages, min_power)
    for item in power_filt:
        print(*(f"{key}: {value}, " for key, value in item.items()))
    print()
    print("Testing spell transformer...")
    print(*spell_transformer(spells))
    print()
    print("Testing mage stats")
    print(mage_stats(mages))


if __name__ == "__main__":
    main()

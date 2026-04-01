import random


def gen_player_achievements(players: list[str],
                            achievements: list[str]) -> list[set[str]]:
    players_achievements: list[set[str]] = []
    for _ in players:
        number: int = random.randint(1, len(achievements))
        players_achievements += [set(random.sample(achievements, number))]
    return players_achievements


def main() -> None:
    players_achievements: list[set[str]] = []
    unlocked_achievements: set[str] = set()
    players: list[str] = ["Alice", "Bob", "Charlie", "Dylan"]
    achievements: list[str] = [
        "Crafting Genius", "Strategist", "World Savior",
        "Speed Runner", "Survivor", "Master Explorer",
        "Treasure Hunter", "Unstoppable", "First Steps",
        "Collector Supreme", "Untouchable", "Sharp Mind", "Boss Slayer"
    ]
    print("=== Achievement Tracker System ===")
    print()
    players_achievements = gen_player_achievements(players, achievements)
    i: int = 0
    for player in players_achievements:
        print(f"{players[i]}: {player}")
        i += 1
    print()
    for player in players_achievements:
        unlocked_achievements = unlocked_achievements.union(player)
    print(f"All distinct achievements: {unlocked_achievements}")
    temp: set[str] = players_achievements[0]
    for player in players_achievements[1:]:
        temp = temp.intersection(player)
    print(f"Common achievements: {temp}")
    for i in range(len(players)):
        temp = set(players_achievements[i])
        for j in range(len(players_achievements)):
            if i != j:
                temp = temp.difference(players_achievements[j])
        print(f"Only {players[i]} has: {temp}")
    i = 0
    for player in players_achievements:
        temp = set(achievements) - player
        print(f"{players[i]} is missing: {temp}")
        i += 1


if __name__ == "__main__":
    main()

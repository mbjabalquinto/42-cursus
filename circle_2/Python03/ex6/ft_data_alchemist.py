import random


def main() -> None:
    players: list[str] = [
        "Alice", "bob", "Charlie", "dylan",
        "Emma", "Gregory", "john", "kevin", "Lian"
    ]
    capitalized_players: list[str] = [
        player for player in players if player == player.capitalize()
    ]
    all_capitalized: list[str] = [
        player.capitalize() for player in players
    ]
    print(f"Initial list of players: {players}")
    print(f"New list with all names capitalized: {all_capitalized}")
    print(f"New list of capitalized names only: {capitalized_players}")
    scores: dict[str, int] = {
        player: random.randint(1, 999) for player in all_capitalized
    }
    print(f"Score dict: {scores}")
    average: float = sum(scores.values()) / len(scores)
    print(f"Score average is: {round(average, 2)}")
    higher_scores: dict[str, int] = {
        player: score for player, score in scores.items() if score > average
    }
    print(f"High scores: {higher_scores}")


if __name__ == "__main__":
    main()

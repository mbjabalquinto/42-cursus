import sys


def get_score() -> list[int]:
    argc: int = len(sys.argv)
    scores: list[int] = []
    if argc > 1:
        for arg in sys.argv[1:]:
            try:
                scores += [int(arg)]
            except ValueError:
                print(f"Invalid parameter: '{arg}'")
    return scores


def calculate_stats(scores: list[int]) -> None:
    players: int = len(scores)
    total_score: int = sum(scores)
    average_score: float = total_score / players
    high_score: int = max(scores)
    low_score: int = min(scores)
    score_range: int = high_score - low_score
    print(f"Total players: {players}")
    print(f"Total score: {total_score}")
    print(f"Average score: {average_score}")
    print(f"High score: {high_score}")
    print(f"Low score: {low_score}")
    print(f"Score range: {score_range}")


def main() -> None:
    print("=== Player Score Analytics ===")
    scores: list[int] = get_score()
    if len(scores) == 0:
        print(
            "No scores provided. Usage: python3 "
            "ft_score_analytics.py <score1> <score2> ..."
        )
        return
    print(f"Scores processed: {scores}")
    calculate_stats(scores)


if __name__ == "__main__":
    main()

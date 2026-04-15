import alchemy.transmutation as transmutation


def main() -> None:
    print("=== Transmutation 0 ===")
    print("Using file alchemy/transmutation/recipes.py directly")
    print(f"Testing lead to gold: "
          f"{transmutation.lead_to_gold()}")


if __name__ == "__main__":
    main()

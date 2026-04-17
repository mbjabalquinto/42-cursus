import alchemy.grimoire as alch


def main() -> None:
    print("=== Kaboom 0 ===")
    print("Using grimoire module directly")
    print(f"Testing record light spell: Spell recorded: "
          f"Fantasy (Earth, wind and fire - "
          f"{alch.light_spell_record('Fantasy', 'Earth, wind, fire')})")


if __name__ == "__main__":
    main()

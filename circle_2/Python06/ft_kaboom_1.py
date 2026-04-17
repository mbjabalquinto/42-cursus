def main() -> None:
    print("=== Kaboom 1 ===")
    print("Access to alchemy/grimoire/dark_spellbook.py directly")
    print("Test import now - THIS WILL RAISE AN UNCAUGHT EXCEPTION ",
          end="", flush=True)
    import alchemy.grimoire.dark_spellbook as dark
    print(f"{dark.dark_spell_record('Fantasy', 'Bat')}")


if __name__ == "__main__":
    main()

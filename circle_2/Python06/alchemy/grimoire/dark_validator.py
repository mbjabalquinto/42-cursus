from .dark_spellbook import dark_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    allowed: list[str] = dark_spell_allowed_ingredients()
    allowed = [ing.lower() for ing in allowed]
    for ingredient in ingredients:
        if ingredient.lower() in allowed:
            return "VALID"
    return "INVALID"

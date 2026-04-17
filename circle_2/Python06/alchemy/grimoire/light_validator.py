from .light_spellbook import light_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    allowed: list[str] = light_spell_allowed_ingredients()
    allowed = [ing.lower() for ing in allowed]
    ing_to_check: list[str] = ingredients.split()
    for ingredient in ing_to_check:
        if ingredient.lower() in allowed:
            return "VALID"
    return "INVALID"

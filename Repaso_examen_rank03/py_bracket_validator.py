def bracket_validator(s: str) -> bool:
    stack: list[str] = []
    map: dict[str, str] = {
        ")": "(",
        "}": "{",
        "]": "["
    }
    for c in s:
        if c in map.values():
            stack.append(c)
        elif c in map.keys():
            if stack and map[c] == stack[-1]:
                stack.pop()
            else:
                return False
    if stack:
        return False
    return True

def main() -> None:
    print(bracket_validator("()"))
    print(bracket_validator("()[]{}"))
    print(bracket_validator("{[()]}"))
    print(bracket_validator(""))
    print(bracket_validator("hello(hhhh)world{ho}w are"))
    print(bracket_validator("(]"))
    print(bracket_validator("([)]"))
    print(bracket_validator("((("))
    print(bracket_validator("())"))

if __name__ == "__main__":
    main()


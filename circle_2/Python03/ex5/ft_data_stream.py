import typing
import random


def gen_event(
    players: list[str],
    actions: list[str]
) -> typing.Generator[tuple[str, str], None, None]:
    while True:
        event: tuple[str, str] = (
            random.choice(players),
            random.choice(actions)
        )
        yield event


def consume_event(
    event_list: list[tuple[str, str]]
) -> typing.Generator[tuple[str, str], None, None]:
    event: tuple[str, str]
    while len(event_list) > 0:
        event = event_list.pop(random.randrange(len(event_list)))
        yield event


def main() -> None:
    print("=== Game Data Stream Processor ===")
    event: tuple[str, str]
    event_list: list[tuple[str, str]] = []
    players: list[str] = ["Alice", "Bob", "Charlie", "Dylan"]
    actions: list[str] = ["run", "eat", "sleep", "grab",
                          "move", "climb", "swim", "use", "release"]
    stream = gen_event(players, actions)
    for i in range(1000):
        event = next(stream)
        print(f"Event {i}: Player {event[0]} did action {event[1]}")
    for i in range(10):
        event_list += [next(stream)]
    print(f"Built list of 10 events: {event_list}")
    stream = consume_event(event_list)
    for event in stream:
        print(f"Got event from list: {event}")
        print(f"Remains in list: {event_list}")


if __name__ == "__main__":
    main()

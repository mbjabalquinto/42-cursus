from typing import Any
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    def __init__(self) -> None:
        self._storage: list[tuple[int, Any]] = []
        self._process_rank: int = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if not self._storage:
            raise IndexError("Error: store is empty.")
        else:
            return self._storage.pop(0)


class NumericProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()

    def validate(self, data: Any) -> bool:
        if isinstance(data, (int, float)):
            return True
        elif isinstance(data, list):
            for item in data:
                if not isinstance(item, (int, float)):
                    return False
            return True
        return False

    def ingest(self, data: int | float | list[Any]) -> None:
        if not self.validate(data):
            raise TypeError("Improper numeric data")
        if isinstance(data, (int, float)):
            self._storage.append((self._process_rank, str(data)))
            self._process_rank += 1
        else:
            for item in data:
                self._storage.append((self._process_rank, str(item)))
                self._process_rank += 1


class TextProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()

    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True
        elif isinstance(data, list):
            for item in data:
                if not isinstance(item, str):
                    return False
            return True
        return False

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise TypeError("Test invalid ingestion")
        if isinstance(data, str):
            self._storage.append((self._process_rank, data))
            self._process_rank += 1
        else:
            for item in data:
                self._storage.append((self._process_rank, item))
                self._process_rank += 1


class LogProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()

    def validate(self, data: Any) -> bool:
        if isinstance(data, dict):
            for key, value in data.items():
                if not isinstance(key, str) or not isinstance(value, str):
                    return False
            return True
        elif isinstance(data, list):
            for item in data:
                if not isinstance(item, dict):
                    return False
                for key, value in item.items():
                    if not isinstance(key, str) or not isinstance(value, str):
                        return False
            return True
        return False

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise TypeError("Improper log data")
        if isinstance(data, dict):
            formated_text = ": ".join(data.values())
            self._storage.append((self._process_rank, formated_text))
            self._process_rank += 1
        else:
            for item in data:
                formated_text = ": ".join(item.values())
                self._storage.append((self._process_rank, formated_text))
                self._process_rank += 1


def main() -> None:
    print("=== Code Nexus - Data Processor ===")
    print()
    print("Testing Numeric Processor...")
    num_test = NumericProcessor()
    print(f"Trying to validate intput '42': {num_test.validate(42)}")
    print(f"Trying to validate input 'Hello': {num_test.validate('Hello')}")
    print("Test invalid ingestion of string 'foo' without prior validation")
    try:
        num_test.ingest("foo")  # type: ignore
    except TypeError as e:
        print(f"Got exception: {e}")
    print("Processing data: [1, 2, 3, 4 ,5]")
    print("Extracting 3 values...")
    num_test.ingest([1, 2, 3, 4, 5])
    for _ in range(0, 3):
        index, value = num_test.output()
        print(f"Numeric value {index}: {value}")
    print("Testing Text Processor...")
    text_test = TextProcessor()
    print(f"Trying to validate input '42': {text_test.validate(42)}")
    print("Processing data: ['Hello', 'Nexus', 'World']")
    text_test.ingest(["Hello", "Nexus", "World"])
    print("Extracting 1 value...")
    index, value = text_test.output()
    print(f"Text value {index}: {value}")
    print("Testing Log Processor...")
    log_test = LogProcessor()
    print(f"Trying to validate input 'Hello': {log_test.validate('Hello')}")
    print(
        "Processing data: "
        "[{'log_level': 'NOTICE', 'log_message': 'Connection to server'}, "
        "{'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}]"
    )
    log_test.ingest([
        {'log_level': 'NOTICE', 'log_message': 'Connection to server'},
        {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}
    ])
    print("Extracting 2 values...")
    for _ in range(0, 2):
        index, value = log_test.output()
        print(f"Log entry {index}: {value}")


if __name__ == "__main__":
    main()

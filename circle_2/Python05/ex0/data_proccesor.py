from typing import Any, cast
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
            safe_list = cast(list[Any], data)
            for item in safe_list:
                if not isinstance(item, (int, float)):
                    return False
            return True
        return False

    def ingest(self, data: int | float | list[Any]) -> None:
        if not self.validate(data):
            raise TypeError("Test invalid ingestion")
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
            safe_list = cast(list[Any], data)
            for item in safe_list:
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
            safe_dict = cast(dict[Any, Any], data)
            for key, value in safe_dict.items():
                if not isinstance(key, str) or not isinstance(value, str):
                    return False
            return True
        elif isinstance(data, list):
            safe_list = cast(list[Any], data)
            for item in safe_list:
                if not isinstance(item, dict):
                    return False
                safe_dict = cast(dict[Any, Any], data)
                for key, value in safe_dict.items():
                    if not isinstance(key, str) or not isinstance(value, str):
                        return False
            return True
        return False

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise TypeError("Error a completar al final")
        if isinstance(data, dict):
            self._storage.append((self._process_rank, str(data)))
            self._process_rank += 1
        else:
            for item in data:
                self._storage.append((self._process_rank, str(item)))
                self._process_rank += 1


def main() -> None:
    print("=== Code Nexus - Data Processor ===")
    print()
    print("Testing Numeric Processor...")


if __name__ == "__main__":
    main()

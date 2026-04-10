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

    def get_total_processed(self) -> int:
        return self._process_rank

    def get_remaining(self) -> int:
        return len(self._storage)


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


class DataStream():
    def __init__(self) -> None:
        self.processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self.processors.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
        if not stream:
            print("No data")
        else:
            for item in stream:
                for proc in self.processors:
                    if proc.validate(item):
                        proc.ingest(item)
                        break
                else:
                    print(f"DataStream error - "
                          f"Can't process element in stream: {item}")

    def print_processors_stats(self) -> None:
        if not self.processors:
            print("No processor found, no data")
        else:
            print("== DataStream statistics ==")
            for proc in self.processors:
                if isinstance(proc, NumericProcessor):
                    print(f"Numeric Processor: total "
                          f"{proc.get_total_processed()} "
                          f"items processed, remaining "
                          f"{proc.get_remaining()} on processor")
                elif isinstance(proc, TextProcessor):
                    print(f"Text Processor: total "
                          f"{proc.get_total_processed()} "
                          f"items processed, remaining "
                          f"{proc.get_remaining()} on processor")
                elif isinstance(proc, LogProcessor):
                    print(f"Log Processor: total {proc.get_total_processed()} "
                          f"items processed, remaining "
                          f"{proc.get_remaining()} on processor")


def main() -> None:
    print("=== Code Nexus - Data Stream ===")
    print()
    print("Initialize Data Stream...")
    print("== DataStream statistics ==")
    stream = DataStream()
    stream.print_processors_stats()
    print()
    print("Registering Numeric Processor")
    print()
    num_proc = NumericProcessor()
    stream.register_processor(num_proc)
    data_list: list[Any] = [
        'Hello world', [3.14, -1, 2.71], [
            {'log_level': 'WARNING',
             'log_message': 'Telnet access! Use ssh instead'},
            {'log_level': 'INFO', 'log_message': 'User wil is connected'}
        ], 42, ['Hi', 'five']
    ]
    print(f"send first batch of data on stream: {data_list}")
    stream.process_stream(data_list)
    stream.print_processors_stats()
    print()
    print("Registering other data processors")
    print("Send the same batch again")
    text_proc = TextProcessor()
    log_proc = LogProcessor()
    stream.register_processor(text_proc)
    stream.register_processor(log_proc)
    stream.process_stream(data_list)
    stream.print_processors_stats()
    print()
    print("Consume some elements from the data "
          "processors: Numeric 3, Text 2, Log 1")
    for _ in range(0, 3):
        num_proc.output()
    for _ in range(0, 2):
        text_proc.output()
    log_proc.output()
    stream.print_processors_stats()


if __name__ == "__main__":
    main()

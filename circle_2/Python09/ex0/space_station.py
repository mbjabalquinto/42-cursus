from pydantic import BaseModel, Field, ValidationError
from typing import Optional, Any
from datetime import datetime


class SpaceStation(BaseModel):
    station_id: str = Field(..., min_length=3, max_length=10)
    name: str = Field(..., min_length=1, max_length=50)
    crew_size: int = Field(..., ge=1, le=20)
    power_level: float = Field(..., ge=0.0, le=100.0)
    oxygen_level: float = Field(..., ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = True
    notes: Optional[str] = Field(None, max_length=200)


def main() -> None:
    data: dict[str, Any] = {
        "station_id": "ISS001",
        "name": "International Space Station",
        "crew_size": "6",
        "power_level": "85.5",
        "oxygen_level": "92.3",
        "last_maintenance": "2026-01-01",
        "is_operational": "True"
    }
    data2: dict[str, Any] = data.copy()
    data2["crew_size"] = "21"
    datasets: list[dict[str, Any]] = [data, data2]
    for data in datasets:
        try:
            station = SpaceStation(**data)
            print("Space Station Data Validation")
            print("=" * 40)
            print("Valid station created:")
            print(f"ID: {station.station_id}")
            print(f"Name: {station.name}")
            print(f"Crew: {station.crew_size} people")
            print(f"Power: {station.power_level}%")
            print(f"Oxygen: {station.oxygen_level}%")
            status = "Operational" if station.is_operational else "Not"
            print(f"Status: {status}")
            print("=" * 40)
            print()
        except ValidationError as e:
            print("Expected validation error:")
            for error in e.errors():
                print(error["msg"])


if __name__ == "__main__":
    main()

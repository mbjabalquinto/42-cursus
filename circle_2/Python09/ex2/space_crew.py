from pydantic import BaseModel, Field, ValidationError, model_validator
from typing import Any
from datetime import datetime
from enum import Enum
import json


class Rank(Enum):
    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class CrewMember(BaseModel):
    member_id: str = Field(..., min_length=3, max_length=10)
    name: str = Field(..., min_length=2, max_length=50)
    rank: Rank
    age: int = Field(..., ge=18, le=80)
    specialization: str = Field(..., min_length=3, max_length=30)
    years_experience: int = Field(..., ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):
    mission_id: str = Field(..., min_length=5, max_length=15)
    mission_name: str = Field(..., min_length=3, max_length=300)
    destination: str = Field(..., min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(..., ge=1, le=3650)
    crew: list[CrewMember]
    mission_status: str = "planned"
    budget_millions: float = Field(..., ge=1.0, le=10000.0)

    @model_validator(mode='after')
    def custom_validations(self) -> SpaceMission:
        if not self.mission_id.startswith("M"):
            raise ValueError("Mission ID must start with 'M'")
        high_rank_present: bool = False
        for member in self.crew:
            if member.rank in [Rank.COMMANDER, Rank.CAPTAIN]:
                high_rank_present = True
                break
        if not high_rank_present:
            raise ValueError("Must have at least one Commander or Captain")
        if self.duration_days > 365:
            exp_count: int = 0
            for member in self.crew:
                if member.years_experience >= 5:
                    exp_count += 1
            if exp_count < len(self.crew) / 2:
                msg = ("Long missions (>365 days) need 50% experienced "
                       "crew (+5years)")
                raise ValueError(msg)
        for member in self.crew:
            if not member.is_active:
                raise ValueError("All crew members must be active")
        return self


def main() -> None:
    try:
        with open("../generated_data/space_missions.json", "r",
                  encoding="utf-8") as file:
            missions_dataset: list[dict[str, Any]] = json.load(file)
    except FileNotFoundError:
        print("Error: space_missions.json not found.")
        return

    for dataset in missions_dataset:
        try:
            mission = SpaceMission(**dataset)
            print("Space Mission Crew Validation")
            print("=" * 41)
            print("Valid mission created:")
            print(f"Mission: {mission.mission_name}")
            print(f"ID: {mission.mission_id}")
            print(f"Destination: {mission.destination}")
            print(f"Duration: {mission.duration_days} days")
            print(f"Budget: ${mission.budget_millions}M")
            print(f"Crew size: {len(mission.crew)}")
            print("Crew members:")
            for crew in mission.crew:
                print(f"- {crew.name} ({crew.rank.value}) - "
                      f"{crew.specialization}")
            print("=" * 41)
        except ValidationError as e:
            print("Expected validation error:")
            for error in e.errors():
                print(error["msg"].removeprefix("Value error, "))


if __name__ == "__main__":
    main()

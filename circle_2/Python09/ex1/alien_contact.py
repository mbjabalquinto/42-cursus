from pydantic import BaseModel, Field, ValidationError, model_validator
from typing import Optional, Any
from datetime import datetime
from enum import Enum


class ContactType(Enum):
    RADIO = "radio"
    VISUAL = "visual"
    PHYSICAL = "physical"
    TELEPATHIC = "telepathic"


class AlienContact(BaseModel):
    contact_id: str = Field(..., min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(..., min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(..., ge=0.0, le=10.0)
    duration_minutes: int = Field(..., ge=1, le=1440)
    witness_count: int = Field(..., ge=1, le=100)
    message_received: Optional[str] = Field(None, max_length=500)
    is_verified: bool = False

    @model_validator(mode='after')
    def custom_validation(self) -> AlienContact:
        if not self.contact_id.startswith("AC"):
            raise ValueError("Contact ID must start with 'AC'")
        if (self.contact_type == ContactType.PHYSICAL and
                not self.is_verified):
            raise ValueError("Physical contact reports must be verified")
        if (self.contact_type == ContactType.TELEPATHIC and
                self.witness_count < 3):
            msg = "Telepathic contact requires at least 3 witnesses"
            raise ValueError(msg)
        if self.signal_strength > 7.0 and not self.message_received:
            msg = "Strong signals (>7.0) should include received messages"
            raise ValueError(msg)
        return self


def main() -> None:
    data1: dict[str, Any] = {
        "contact_id": "AC_2024_001",
        "timestamp": "2024-01-01",
        "location": "Area 51, Nevada",
        "contact_type": "radio",
        "signal_strength": "8.5",
        "duration_minutes": "45",
        "witness_count": "5",
        "message_received": "Greetings from Zeta Reticuli"
    }
    data2: dict[str, Any] = data1.copy()
    data2["contact_type"] = "telepathic"
    data2["witness_count"] = "2"
    data3: dict[str, Any] = data1.copy()
    data3["contact_id"] = "2025_001"
    data4: dict[str, Any] = data1.copy()
    data4["contact_type"] = "physical"
    data5: dict[str, Any] = data1.copy()
    data5["message_received"] = ""
    datasets: list[dict[str, Any]] = [data1, data2, data3, data4, data5]
    for data in datasets:
        try:
            new_contact = AlienContact(**data)
            print("Alien Contact Log Validation")
            print("=" * 38)
            print("Valid contact report:")
            print(f"ID: {new_contact.contact_id}")
            print(f"Type: {new_contact.contact_type.value}")
            print(f"Location: {new_contact.location}")
            print(f"Signal: {new_contact.signal_strength}/10")
            print(f"Duration: {new_contact.duration_minutes} minutes")
            print(f"Witnesses: {new_contact.witness_count}")
            print(f"Message: '{new_contact.message_received}'")
            print("=" * 38)
        except ValidationError as e:
            print("Expected validation error:")
            for error in e.errors():
                print(error["msg"].removeprefix("Value error, "))


if __name__ == "__main__":
    main()

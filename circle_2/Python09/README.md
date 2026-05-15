# Python 09 - Cosmic Data

## Discover Pydantic Models & Validation

This project is part of the 42 Cursus and focuses on mastering **Pydantic v2** for data validation. Through a series of space-themed exercises, I learned how to create robust data models, implement custom validation logic using `@model_validator`, and handle complex nested data structures.

---

## 🌌 Project Overview

The "Cosmic Data Observatory" requires a robust system to validate incoming data streams from space stations, alien contact reports, and mission crew assignments.

### Exercises

#### [ex0] Space Station Data
- **Objective:** Learn basic Pydantic model creation using `BaseModel` and `Field`.
- **Key Concepts:** Type hinting, field constraints (`min_length`, `ge`, `le`), and automatic type conversion.

#### [ex1] Alien Contact Logs
- **Objective:** Master custom validation for complex business rules.
- **Key Concepts:** `Enum` for contact types and `@model_validator(mode='after')` to enforce rules based on multiple fields (e.g., verifying physical contacts, witness requirements for telepathic signals).

#### [ex2] Space Crew Management
- **Objective:** Handle nested Pydantic models and complex data relationships.
- **Key Concepts:** Nested models (`CrewMember` inside `SpaceMission`), processing external JSON data, and sophisticated validation logic (e.g., ensuring 50% experienced crew for long-duration missions).

---

## 🛠️ Requirements & Tools

- **Python:** 3.10 or later.
- **Library:** [Pydantic v2](https://docs.pydantic.dev/latest/).
- **Linting:** `flake8` (coding standards).
- **Type Checking:** `mypy` (static analysis).

---

## 🚀 Getting Started

### Installation

1. Create and activate a virtual environment:
   ```bash
   python3 -m venv .venv
   source .venv/bin/activate
   ```

2. Install Pydantic:
   ```bash
   pip install pydantic
   ```

### Running the Exercises

Each exercise can be executed directly from its directory:

```bash
# Exercise 0
python3 ex0/space_station.py

# Exercise 1
python3 ex1/alien_contact.py

# Exercise 2
cd ex2 && python3 space_crew.py
```

---

## 🧪 Validation

To ensure the project meets the required standards, run the following commands:

**Check Coding Style (Flake8):**
```bash
flake8 ex0/ ex1/ ex2/
```

**Check Type Annotations (Mypy):**
```bash
mypy ex0/ ex1/ ex2/
```

---

## 🛰️ Cosmic Theme Summary

> "Data integrity is the oxygen of the known universe."

- **Space Stations:** Fundamentals of validation.
- **Alien Contacts:** Custom rules and logic.
- **Crew Management:** Nested structures and mission safety.

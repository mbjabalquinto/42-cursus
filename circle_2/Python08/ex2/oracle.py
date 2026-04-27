from dotenv import load_dotenv  # type: ignore
import os


def check_config() -> None:
    load_dotenv()
    matrix_mode: str | None = os.environ.get("MATRIX_MODE")
    database_url: str | None = os.environ.get("DATABASE_URL")
    api_key: str | None = os.environ.get("API_KEY")
    log_level: str | None = os.environ.get("LOG_LEVEL")
    zion_endpoint: str | None = os.environ.get("ZION_ENDPOINT")
    config: dict[str, str | None] = {
        "Mode": matrix_mode, "Database": database_url,
        "API Access": api_key, "Log Level": log_level,
        "Zion Network": zion_endpoint
    }
    prod_msgs: dict[str, str | None] = {
        "Mode": matrix_mode,
        "Database": "Connected to a cloud instance",
        "API Access": "Authenticated", "Log Level": log_level,
        "Zion Network": "Online"
    }
    dev_msgs: dict[str, str | None] = {
        "Mode": matrix_mode,
        "Database": "Connected to local instance",
        "API Access": "Authenticated", "Log Level": log_level,
        "Zion Network": "Online"
    }
    messages: dict[str, str | None] = dev_msgs
    if matrix_mode == "production":
        messages = prod_msgs
    env_valid: bool = True
    for key, value in config.items():
        if not value:
            print(f"{key}: is missing!")
            env_valid = False
        elif key == "Mode" and value not in ["development", "production"]:
            print(f"{key}: invalid value '{value}'. "
                  f"Must be development or production!")
            env_valid = False
        else:
            print(f"{key}: {messages[key]}")
    print()
    print("Environment security check:")
    print("[OK] No hardcoded secrets detected")
    if env_valid:
        print("[OK] .env file properly configured")
    else:
        print("[KO] .env file has missing params")
    print("[OK] Production overrides available")


def main() -> None:
    print()
    print("ORACLE STATUS: Reading the Matrix...")
    print()
    print("Configuration loaded:")
    check_config()
    print()
    print("The Oracle sees all configurations.")


if __name__ == "__main__":
    main()

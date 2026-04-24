import sys
import os
import site


def outside() -> None:
    print("MATRIX STATUS: You're still plugged in")
    print()
    print(f"Current Python: {sys.executable}")
    print(f"Virtual Environment: {os.environ.get('VIRTUAL_ENV')} detected")
    print()
    print("WARNING: You're in the global environment!")
    print("The machines can see everything you install.")
    print()
    print("To enter the construct, run:")
    print("python -m venv matrix_env")
    print("source matrix_env/bin/activate # On Unix")
    print("matrix_env\\Scripts\\activate # On Windows")
    print()
    print("Then run this program again.")


def inside() -> None:
    print("MATRIX STATUS: Welcome to the construct")
    print()
    print(f"Current Python: {sys.executable}")
    env_path = os.environ.get('VIRTUAL_ENV')
    if env_path:
        print(f"Virtual Environment: {os.path.basename(env_path)}")
    print(f"Environment Path: {os.environ.get('VIRTUAL_ENV')}")
    print()
    print("SUCCESS: You're in an isolated environment!")
    print("Safe to install packages without affecting the global system.")
    print()
    print("Package installation path:")
    print(f"{site.getsitepackages()[0]}")


def main() -> None:
    if sys.prefix == sys.base_prefix:
        outside()
    else:
        inside()


if __name__ == "__main__":
    main()

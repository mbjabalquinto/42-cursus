import sys
import importlib.metadata
from importlib.metadata import PackageNotFoundError


def check_dependencies() -> None:
    print("LOADING STATUS: Loading programs...")
    print()
    print("Checking dependencies:")
    import_libs: list[str] = [
        "pandas", "numpy", "matplotlib"
    ]
    missing_libs: list[str] = []
    for lib in import_libs:
        try:
            version = importlib.metadata.version(lib)
            print(f"[OK] {lib} ({version})")
        except PackageNotFoundError:
            missing_libs.append(lib)
    if missing_libs:
        print()
        print("Error: following dependencies are missing:")
        print(f"{', '.join(missing_libs)}")
        print()
        print("Installing with pip: $>pip install -r requirements.txt")
        print("Installing with Poetry: $>poetry install")
        print("Running with Poetry: $>poetry run python loading.py")
        sys.exit(1)


check_dependencies()
import pandas as pd  # type: ignore # noqa: E402
import numpy as np  # type: ignore # noqa: E402
import matplotlib.pyplot as plt  # type: ignore # noqa: E402


def processing_data(x: np.ndarray, y: np.ndarray) -> pd.DataFrame:
    z: np.ndarray = x + y
    data: dict[str, np.ndarray] = {
        "Time": x, "Activity": y, "Sum": z
    }
    return pd.DataFrame(data)


def create_graphic(df: pd.DataFrame) -> None:
    plt.plot(
        df["Time"], df["Activity"], color="green", label="Matrix Activity"
    )
    plt.title("The Matrix simulation analysis")
    plt.xlabel("Time")
    plt.ylabel("Activity level")
    plt.legend()
    plt.savefig("matrix_analysis.png")


def main() -> None:
    print()
    print("Analyzing Matrix data...")
    print("Processing 1000 data points...")
    x: np.ndarray = np.linspace(1, 2000, 1000)
    y: np.ndarray = x ** 2
    dataframe: pd.DataFrame = processing_data(x, y)
    print("Generating visualization...")
    create_graphic(dataframe)
    print()
    print("Analysis complete!")
    print("Results saved to: matrix_analysis.png")


if __name__ == "__main__":
    main()

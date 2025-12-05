"""
Main module for PackageDevTesting package.
"""


def hello_world():
    """
    Print a hello world message.

    Returns:
        str: Hello world message
    """
    message = "Hello, World! from PackageDevTesting package"
    print(message)
    return message


def add_numbers(a: float, b: float) -> float:
    """
    Add two numbers together.

    Args:
        a: First number
        b: Second number

    Returns:
        float: Sum of a and b

    Example:
        >>> add_numbers(2, 3)
        5.0
    """
    return float(a + b)


def multiply_numbers(a: float, b: float) -> float:
    """
    Multiply two numbers.

    Args:
        a: First number
        b: Second number

    Returns:
        float: Product of a and b

    Example:
        >>> multiply_numbers(2, 3)
        6.0
    """
    return float(a * b)


def main():
    """Demo function that shows all package features."""
    print("=== PackageDevTesting Package Demo ===")
    hello_world()
    print(f"2 + 3 = {add_numbers(2, 3)}")
    print(f"2 * 3 = {multiply_numbers(2, 3)}")
    print("==================================")


if __name__ == "__main__":
    main()
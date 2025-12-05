"""
The Hello World Package

A simple package that says hello and does basic math.
"""

__version__ = "0.1.0"


__all__ = [
    "hello_world",
    "add_numbers",
    "multiply_numbers",
    "__version__"
]

from .src.main import hello_world, add_numbers, multiply_numbers
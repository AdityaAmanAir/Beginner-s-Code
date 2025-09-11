def is_multiple(a : int, b : int) -> bool:
    if b == 0:
        return False
    return a % b == 0
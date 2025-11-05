def discriminant(a, b, c):
    D = b**2 - 4*a*c
    if D > 0:
        return "The Equation has two Real Roots"
    elif D == 0:
        return "The Equation has one Real Root"
    else:
        return "The Equation has two Complex Roots"

a, b, c = 1, -3, 2
print(discriminant(a, b, c))
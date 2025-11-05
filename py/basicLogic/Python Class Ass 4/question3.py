import math

def calc_Distance(x1, y1, x2, y2):
    return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)

x1, y1 = 1, 2
x2, y2 = 4, 6
print(f"Distance between points: {calc_Distance(x1, y1, x2, y2)}")
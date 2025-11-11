from area_module import calculate_area

base = float(input("Enter base: "))
height = float(input("Enter height: "))

area = calculate_area(base, height)
print(f"Area of triangle: {area}")
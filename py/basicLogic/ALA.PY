# Gaussian elimination with partial pivoting + inconsistency check
def solve_linear_system(A, B, eps=1e-12):
    n = len(B)
    mat = [list(map(float, row)) for row in A]   # copy as floats
    rhs = list(map(float, B))

    row = 0
    lead_col = [-1]*n
    # Forward elimination with partial pivoting
    for col in range(n):
        # pick best pivot row
        sel = max(range(row, n), key=lambda r: abs(mat[r][col]))
        if abs(mat[sel][col]) < eps:
            continue
        # swap into current row
        mat[row], mat[sel] = mat[sel], mat[row]
        rhs[row], rhs[sel] = rhs[sel], rhs[row]

        # eliminate below
        for r in range(row+1, n):
            factor = mat[r][col] / mat[row][col]
            for c in range(col, n):
                mat[r][c] -= factor * mat[row][c]
            rhs[r] -= factor * rhs[row]

        lead_col[row] = col
        row += 1
        if row == n:
            break

    # Check for inconsistency: 0 = nonzero
    for r in range(row, n):
        if all(abs(mat[r][c]) < eps for c in range(n)) and abs(rhs[r]) > eps:
            print("No solution: system is inconsistent.")
            return None

    # Back substitution (free variables set to 0 if underdetermined)
    x = [0.0]*n
    for r in range(row-1, -1, -1):
        c = lead_col[r]
        s = rhs[r]
        for j in range(c+1, n):
            s -= mat[r][j] * x[j]
        x[c] = s / mat[r][c]

    return x

# Coefficient matrix and RHS from the slide
A = [
    [-1, 0, 0, 1],   # -x1 + x4 = 130
    [0, 0, 1, -1],   #  x3 - x4 = 60
    [0, 1, -1, 0],   #  x2 - x3 = -240
    [1, -1, 0, 0]    #  x1 - x2 = -50
]
B = [130, 60, -240, -50]

sol = solve_linear_system(A, B)
if sol is None:
    # no solution message already printed
    pass
else:
    for i, val in enumerate(sol, 1):
        print(f"x{i} = {val:.6f}")
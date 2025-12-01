n1 = int(input("Okay Engineer! You want to do Matrix 1 x Matrix 2 haaan?! \n Enter the Number of rows in your 1st matrix :"))
m1 = int(input(" Enter the Number of columns in your 1st matrix :"))
n2 = int(input(" Enter the Number of rows in your 2nd matrix :"))
m2 = int(input(" Enter the Number of columns in your 2nd matrix :"))

if m1 != n2:
    print("Wow! matrices cannot be multiplied together, You VITen?")
else:
    print("Enter the Matrix 1 :")
    mx1 = []
    for i in range(n1):
        row = list(map(int, input().split()))
        mx1.append(row)
    print("Enter the Matrix 2 :")
    mx2 = []
    for i in range(n2):
        row = list(map(int, input().split()))
        mx2.append(row)
    result = []
    for i in range(n1):
        row = []
        for j in range(m2):
            sum_val = 0
            for k in range(m1):
                sum_val += mx1[i][k] * mx2[k][j]
            row.append(sum_val)
        result.append(row)
    print("Result:")
    for row in result:
        print(' '.join(map(str, row)))
def count_valid_sequences(A, k):
    n = len(A)
    count = 0
    for i in range(n):
        current_sum = 0
        for j in range(i, n):
            current_sum += A[j] 
            if current_sum >= k:
                count += 1
                break

    return (count)

t = int(input())
for _ in range(t):
    n, k, x = map(int, input().split())
    a = list(map(int, input().split()))
    b=a*k
    print(count_valid_sequences(a,x)*6  )      

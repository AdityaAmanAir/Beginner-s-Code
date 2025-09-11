try:
    from mpmath import mp
    import time

    # Set decimal places (10,000 for integer part + 2 for decimal places)
    mp.dps = 10002

    # Create a 10,000-digit number (e.g., 10^9999)
    number = mp.mpf('1' + '0' * 9999)

    # Measure time
    start = time.time()
    sqrt_result = mp.sqrt(number)
    end = time.time()

    # Print result (first 20 digits and last few for brevity)
    print(f"Square root (first 20 digits): {str(sqrt_result)[:20]}...")
    print(f"Time taken: {(end - start) * 1000:.2f} milliseconds")

except ImportError:
    print("Error: mpmath library is not installed. Install it using 'pip install mpmath'.")
except Exception as e:
    print(f"An error occurred: {e}")
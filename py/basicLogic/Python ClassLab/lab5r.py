import sys

if len(sys.argv) > 1:
    print(f"Number of command line arguments: {len(sys.argv) - 1}")
    print("Arguments:", ' '.join(sys.argv[1:]))
else:
    print("No command line arguments provided.")
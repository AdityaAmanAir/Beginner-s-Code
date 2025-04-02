# You are organizing a coding competition, and two events are being conducted: Python Basics and Advanced Java. The participants are as follows:
# Participants in Python Basics: John, Edwin, Sophia, Olivia, Lee
# Participants in Advanced Java: Sophia, Olivia, William, James, Edwin
# Using Python sets, answer the following questions:
# Write Python code to solve these problems.
# Identify participants who registered for both events.
# List the participants who registered for only one event (not both).
# Determine if all participants of Advanced Java also registered for Python Basics.
# Find the total number of unique participants across both events.

Python_Basics={ "ohn", "Edwin", "Sophia", "Olivia", "Lee"}
Advanced_Java={ "Sophia", "Olivia", "William", "James", "Edwin"}

print(Python_Basics.intersection(Advanced_Java))

print(Python_Basics.symmetric_difference(Advanced_Java))

print(Advanced_Java.issubset(Python_Basics))

print(len(Python_Basics.intersection(Advanced_Java))+len(Python_Basics.symmetric_difference(Advanced_Java)))
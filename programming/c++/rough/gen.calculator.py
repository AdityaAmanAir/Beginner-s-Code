from tkinter import *

# Create the main window
root = Tk()
root.title("Calculator")

# Global variables
current_number = ""
previous_number = ""
operation = ""

# Function to update the display
def update_display(number):
    global current_number
    current_number += str(number)
    display_label.config(text=current_number)

# Function to handle operations
def handle_operation(op):
    global current_number
    global previous_number
    global operation
    previous_number = current_number
    current_number = ""
    operation = op

# Function to calculate the result
def calculate_result():
    global current_number
    global previous_number
    global operation
    if previous_number and operation:
        try:
            result = eval(previous_number + operation + current_number)
            display_label.config(text=str(result))
            previous_number = ""
            current_number = str(result)
        except Exception as e:
            display_label.config(text="Error")
            previous_number = ""
            current_number = ""

# Create the display label
display_label = Label(root, text="0", width=25, borderwidth=5, relief=RIDGE, font=("Arial", 24))
display_label.grid(row=0, column=0, columnspan=4)

# Create the number buttons
button_7 = Button(root, text="7", padx=40, pady=20, command=lambda: update_display(7))
button_8 = Button(root, text="8", padx=40, pady=20, command=lambda: update_display(8))
button_9 = Button(root, text="9", padx=40, pady=20, command=lambda: update_display(9))
button_4 = Button(root, text="4", padx=40, pady=20, command=lambda: update_display(4))
button_5 = Button(root, text="5", padx=40, pady=20, command=lambda: update_display(5))
button_6 = Button(root, text="6", padx=40, pady=20, command=lambda: update_display(6))
button_1 = Button(root, text="1", padx=40, pady=20, command=lambda: update_display(1))
button_2 = Button(root, text="2", padx=40, pady=20, command=lambda: update_display(2))
button_3 = Button(root, text="3", padx=40, pady=20, command=lambda: update_display(3))
button_0 = Button(root, text="0", padx=40, pady=20, command=lambda: update_display(0))

button_7.grid(row=1, column=0)
button_8.grid(row=1, column=1)
button_9.grid(row=1, column=2)
button_4.grid(row=2, column=0)
button_5.grid(row=2, column=1)
button_6.grid(row=2, column=2)
button_1.grid(row=3, column=0)
button_2.grid(row=3, column=1)
button_3.grid(row=3, column=2)
button_0.grid(row=4, column=0)

# Create the operation buttons
button_add = Button(root, text="+", padx=39, pady=20, command=lambda: handle_operation("+"))
button_subtract = Button(root, text="-", padx=40, pady=20, command=lambda: handle_operation("-"))
button_multiply = Button(root, text="*", padx=40, pady=20, command=lambda: handle_operation("*"))
button_divide = Button(root, text="/", padx=40, pady=20, command=lambda: handle_operation("/"))
button_equals = Button(root, text="=", padx=39, pady=20, command=calculate_result)
button_clear = Button(root, text="C", padx=39, pady=20, command=lambda: [display_label.config(text="0"), current_number.clear(), previous_number.clear(), operation.clear()])

button_add.grid(row=1, column=3)
button_subtract.grid(row=2, column=3)
button_multiply.grid(row=3, column=3)
button_divide.grid(row=4, column=3)
button_equals.grid(row=4, column=2)
button_clear.grid(row=4, column=1)

root.mainloop()
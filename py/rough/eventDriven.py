import tkinter as tk
from tkinter import messagebox

class EventDrivenApp:
    def __init__(self):
        self.root = tk.Tk()
        self.root.title("Event-Driven Programming Example")
        
        # Create widgets
        self.label = tk.Label(self.root, text="Click the button or type in entry")
        self.label.pack(pady=10)
        
        self.entry = tk.Entry(self.root, width=30)
        self.entry.pack(pady=5)
        self.entry.bind('<KeyRelease>', self.on_key_release)  # Event binding
        
        self.button = tk.Button(self.root, text="Click Me", 
                               command=self.on_button_click)  # Event binding
        self.button.pack(pady=10)
        
        self.quit_button = tk.Button(self.root, text="Quit", 
                                    command=self.root.quit)
        self.quit_button.pack(pady=5)
        
    def on_button_click(self):
        """Event handler for button click"""
        messagebox.showinfo("Event", "Button was clicked!")
        
    def on_key_release(self, event):
        """Event handler for key release"""
        text = self.entry.get()
        self.label.config(text=f"Typing: {text}")
        
    def run(self):
        """Start the event loop"""
        self.root.mainloop()

# Sequential programming equivalent (simplified)
def sequential_program():
    print("Step 1: Show window")
    print("Step 2: Wait for input...")
    # Can't handle multiple simultaneous events naturally
    user_input = input("Enter something: ")
    print(f"You entered: {user_input}")
    print("Step 3: End program")

# Run event-driven example
if __name__ == "__main__":
    app = EventDrivenApp()
    app.run()
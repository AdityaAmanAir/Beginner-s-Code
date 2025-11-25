# Module-level variable
counter = 0
settings = {"debug": True}

def increment_counter():
    global counter  # Refers to the module-level variable
    counter += 1

def update_settings():
    global settings
    settings["debug"] = False

# Usage
print(counter)  # 0
increment_counter()
print(counter)  # 1 - module variable was modified
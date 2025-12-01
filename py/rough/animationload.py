import time
import sys
import os

def loading_animation():
    """Fancy loading animation with text changes."""
    texts = [
        "▁▂▃▄▅▆▇█ LOADING █▇▆▅▄▃▂▁",
        "█▇▆▅▄▃▂▁ PLEASE WAIT ▁▂▃▄▅▆▇█",
        "COMPLETING TASKS...",
        "ALMOST DONE...",
        "✓ SUCCESSFULLY COMPLETED!"
    ]
    
    for text in texts:
        # Clear line
        sys.stdout.write('\r' + ' ' * 50 + '\r')
        
        # Type text with animation
        for i, char in enumerate(text):
            sys.stdout.write(char)
            sys.stdout.flush()
            time.sleep(0.03)
        
        # Hold for a moment
        time.sleep(1)
        
        # Delete text backwards
        for i in range(len(text)):
            time.sleep(0.02)
            sys.stdout.write('\b \b')
            sys.stdout.flush()
    
    print("\n✅ Process completed!")

loading_animation()
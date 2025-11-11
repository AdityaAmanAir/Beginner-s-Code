def convert_days_to_months(days):
    if not isinstance(days, int) or days < 0:
        raise ValueError("Days must be a non-negative integer")
    
    months = days // 30
    remaining_days = days % 30
    
    return months, remaining_days

def display_conversion(days):
    try:
        months, remaining_days = convert_days_to_months(days)
        
        print(f"\nConversion Result:")
        print(f"Total Days: {days}")
        print(f"Months: {months}")
        print(f"Remaining Days: {remaining_days}")
        
        if months == 0:
            print(f"\n{days} days = {remaining_days} days")
        elif remaining_days == 0:
            print(f"\n{days} days = {months} months")
        else:
            print(f"\n{days} days = {months} months and {remaining_days} days")
            
    except ValueError as e:
        print(f"Error: {e}")

def get_days_input():
    while True:
        try:
            days = int(input("Enter total number of days: "))
            if days < 0:
                print("Please enter a non-negative number.")
                continue
            return days
        except ValueError:
            print("Please enter a valid integer.")

if __name__ == "__main__":
    print("Days to Months Converter (Module Test)")
    print("=" * 40)
    
    days = get_days_input()
    display_conversion(days)
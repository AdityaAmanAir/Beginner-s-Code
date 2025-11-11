from days_converter import convert_days_to_months, display_conversion, get_days_input

def main():
    print("Days to Months Converter")
    print("=" * 30)
    print("This program converts total days into months and remaining days.")
    print("Note: 1 month = 30 days\n")
    total_days = get_days_input()
    display_conversion(total_days)
    print("\n" + "=" * 40)
    print("Alternative Display:")
    months, remaining_days = convert_days_to_months(total_days)
    
    if months == 1:
        month_text = "month"
    else:
        month_text = "months"
        
    if remaining_days == 1:
        day_text = "day"
    else:
        day_text = "days"
    
    print(f"{total_days} days is equivalent to {months} {month_text} and {remaining_days} {day_text}.")

def batch_conversion():
    print("\n" + "=" * 50)
    print("Batch Conversion Example")
    print("=" * 50)
    test_days = [45, 100, 365, 720, 15, 0, 30]
    print(f"{'Days':<10} {'Months':<10} {'Remaining Days':<15}")
    print("-" * 35)
    
    for days in test_days:
        months, remaining_days = convert_days_to_months(days)
        print(f"{days:<10} {months:<10} {remaining_days:<15}")

if __name__ == "__main__":
    main()
    batch_conversion()
    print("\n" + "=" * 50)
    print("Multiple Conversions")
    print("=" * 50)
    while True:
        try:
            more = input("\nDo you want to convert another value? (yes/no): ").lower().strip()
            if more in ['no', 'n']:
                print("Thank you for using the Days Converter!")
                break
            elif more in ['yes', 'y']:
                days = get_days_input()
                display_conversion(days)
            else:
                print("Please enter 'yes' or 'no'")
        except KeyboardInterrupt:
            print("\n\nProgram interrupted. Goodbye!")
            break
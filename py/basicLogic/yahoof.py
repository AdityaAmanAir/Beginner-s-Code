import yfinance as yf
import time
import os

tickers = ["AAPL", "MSFT", "GOOGL", "AMZN", "TSLA"]

while True:
    os.system('clear')  # Linux/Mac (use 'cls' for Windows)
    
    for ticker in tickers:
        stock = yf.Ticker(ticker)
        info = stock.info
        
        price = info.get('regularMarketPrice', 'N/A')
        change = info.get('regularMarketChange', 'N/A')
        change_percent = info.get('regularMarketChangePercent', 'N/A')
        
        print(f"{ticker:6} ${price:8.2f} {change:7.2f} ({change_percent:.2f}%)")
    
    print(f"\nUpdated: {time.strftime('%H:%M:%S')}")
    print("Ctrl+C to stop")
    time.sleep(5)
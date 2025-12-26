import asyncio
import websockets
import json
import ssl

async def get_stock_price():
    """Simple function to get stock prices"""
    
    symbol = input("Enter stock symbol (e.g., NSE:SBIN, NASDAQ:AAPL): ").strip()
    if not symbol:
        symbol = "NSE:SBIN"  # Default to State Bank of India
    
    print(f"\n🔍 Trying to connect to TradingView for {symbol}...")
    print("If you see nothing, press Ctrl+C to stop\n")
    
    try:
        # Connect to TradingView
        ssl_context = ssl.create_default_context()
        ssl_context.check_hostname = False
        ssl_context.verify_mode = ssl.CERT_NONE
        
        async with websockets.connect(
            "wss://data.tradingview.com/socket.io/websocket",
            ssl=ssl_context,
            extra_headers={
                'Origin': 'https://www.tradingview.com',
                'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36'
            }
        ) as websocket:
            print("✅ Connected to TradingView!")
            
            # Send setup messages
            setup_messages = [
                '~m~50~m~{"m":"set_auth_token","p":["unauthorized_user_token"]}',
                '~m~46~m~{"m":"set_locale","p":["en"]}',
                '~m~58~m~{"m":"chart_create_session","p":["cs_1",""]}',
                '~m~53~m~{"m":"quote_create_session","p":["qs_1"]}',
                '~m~67~m~{"m":"quote_set_fields","p":["qs_1","lp","ch","chp","volume","bid","ask"]}',
                f'~m~{60 + len(symbol)}~m~{{"m":"quote_add_symbols","p":["qs_1","{symbol}",{{"flags":["force_permission"]}}]}}'
            ]
            
            for msg in setup_messages:
                await websocket.send(msg)
                await asyncio.sleep(0.1)
            
            print(f"✅ Subscribed to {symbol}")
            print("📊 Waiting for live data...\n")
            
            # Listen for messages for 30 seconds
            for i in range(30):  # Listen for 30 seconds max
                try:
                    response = await asyncio.wait_for(websocket.recv(), timeout=1.0)
                    
                    # Look for price data
                    if '"qsd"' in response or '"lp"' in response:
                        print(f"Raw response: {response[:200]}...")  # Show first 200 chars
                        
                        # Try to parse JSON
                        if '~m~' in response:
                            parts = response.split('~m~')
                            for part in parts:
                                if part and part.startswith('{'):
                                    try:
                                        data = json.loads(part)
                                        if 'm' in data and data['m'] == 'qsd':
                                            symbol_name = data['p'][1]['n']
                                            price = data['p'][1]['v'].get('lp', 'N/A')
                                            print(f"\n🎯 LIVE PRICE: {symbol_name} = ₹{price}")
                                    except:
                                        pass
                    
                except asyncio.TimeoutError:
                    # Send ping to keep connection alive
                    await websocket.send('~m~6~m~{"m":"ping"}')
                    print(f"⏳ Waiting... ({i+1}/30)")
                    
    except Exception as e:
        print(f"\n❌ Error: {e}")
        print("\nTroubleshooting:")
        print("1. Check your internet connection")
        print("2. Try a different symbol like 'NSE:SBIN' or 'NASDAQ:AAPL'")
        print("3. Make sure you have websockets installed: pip install websockets")
        print("4. Try running as administrator/root if on Linux/Mac")

# Even simpler test function
async def quick_test():
    """Quick test without WebSocket complexity"""
    print("=" * 50)
    print("TradingView WebSocket Test")
    print("=" * 50)
    
    symbols_to_try = ["NSE:SBIN", "NSE:RELIANCE", "NASDAQ:AAPL", "BSE:ONGC"]
    
    for symbol in symbols_to_try:
        print(f"\nTrying {symbol}...")
        await get_stock_price_simple(symbol)
        await asyncio.sleep(2)

async def get_stock_price_simple(symbol):
    """Super simple version"""
    try:
        ssl_context = ssl.create_default_context()
        ssl_context.check_hostname = False
        ssl_context.verify_mode = ssl.CERT_NONE
        
        async with websockets.connect(
            "wss://data.tradingview.com/socket.io/websocket",
            ssl=ssl_context,
            ping_interval=20
        ) as ws:
            
            # Quick subscribe
            await ws.send(json.dumps({"m": "quote_add_symbols", "p": ["qs_1", symbol]}))
            
            # Get one response
            response = await asyncio.wait_for(ws.recv(), timeout=5)
            print(f"Got response: {response[:100]}")
            
    except Exception as e:
        print(f"Failed for {symbol}: {str(e)[:50]}")

# Run it
if __name__ == "__main__":
    print("Starting TradingView Stock Price Fetcher...")
    print("\nNote: If Meesho isn't available, try these symbols instead:")
    print("1. NSE:SBIN (State Bank of India)")
    print("2. NSE:RELIANCE (Reliance Industries)")
    print("3. NASDAQ:AAPL (Apple)")
    print("4. BSE:ONGC\n")
    
    try:
        asyncio.run(get_stock_price())
    except KeyboardInterrupt:
        print("\n👋 Stopped by user")
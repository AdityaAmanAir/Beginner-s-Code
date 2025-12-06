class NetworkError(Exception):
    def __init__ (self, arg):
        self.name = arg
# try:
raise NetworkError('Network Connection Failed')
# except NetworkError as e:
#     print("The network error is:", e.name)   

print("LOL , Ended!")         
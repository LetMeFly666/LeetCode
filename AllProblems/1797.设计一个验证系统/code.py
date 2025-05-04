class AuthenticationManager:

    def __init__(self, timeToLive: int):
        

    def generate(self, tokenId: str, currentTime: int) -> None:
        

    def renew(self, tokenId: str, currentTime: int) -> None:
        

    def countUnexpiredTokens(self, currentTime: int) -> int:
        


# Your AuthenticationManager object will be instantiated and called as such:
# obj = AuthenticationManager(timeToLive)
# obj.generate(tokenId,currentTime)
# obj.renew(tokenId,currentTime)
# param_3 = obj.countUnexpiredTokens(currentTime)
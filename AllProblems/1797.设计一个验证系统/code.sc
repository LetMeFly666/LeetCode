class AuthenticationManager(_timeToLive: Int) {

    def generate(tokenId: String, currentTime: Int): Unit = {
        
    }

    def renew(tokenId: String, currentTime: Int): Unit = {
        
    }

    def countUnexpiredTokens(currentTime: Int): Int = {
        
    }

}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * val obj = new AuthenticationManager(timeToLive)
 * obj.generate(tokenId,currentTime)
 * obj.renew(tokenId,currentTime)
 * val param_3 = obj.countUnexpiredTokens(currentTime)
 */
class AuthenticationManager {
    /**
     * @param Integer $timeToLive
     */
    function __construct($timeToLive) {
        
    }
  
    /**
     * @param String $tokenId
     * @param Integer $currentTime
     * @return NULL
     */
    function generate($tokenId, $currentTime) {
        
    }
  
    /**
     * @param String $tokenId
     * @param Integer $currentTime
     * @return NULL
     */
    function renew($tokenId, $currentTime) {
        
    }
  
    /**
     * @param Integer $currentTime
     * @return Integer
     */
    function countUnexpiredTokens($currentTime) {
        
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * $obj = AuthenticationManager($timeToLive);
 * $obj->generate($tokenId, $currentTime);
 * $obj->renew($tokenId, $currentTime);
 * $ret_3 = $obj->countUnexpiredTokens($currentTime);
 */
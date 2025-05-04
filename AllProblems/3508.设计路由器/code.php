class Router {
    /**
     * @param Integer $memoryLimit
     */
    function __construct($memoryLimit) {
        
    }
  
    /**
     * @param Integer $source
     * @param Integer $destination
     * @param Integer $timestamp
     * @return Boolean
     */
    function addPacket($source, $destination, $timestamp) {
        
    }
  
    /**
     * @return Integer[]
     */
    function forwardPacket() {
        
    }
  
    /**
     * @param Integer $destination
     * @param Integer $startTime
     * @param Integer $endTime
     * @return Integer
     */
    function getCount($destination, $startTime, $endTime) {
        
    }
}

/**
 * Your Router object will be instantiated and called as such:
 * $obj = Router($memoryLimit);
 * $ret_1 = $obj->addPacket($source, $destination, $timestamp);
 * $ret_2 = $obj->forwardPacket();
 * $ret_3 = $obj->getCount($destination, $startTime, $endTime);
 */
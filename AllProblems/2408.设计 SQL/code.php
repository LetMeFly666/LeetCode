class SQL {
    /**
     * @param String[] $names
     * @param Integer[] $columns
     */
    function __construct($names, $columns) {
        
    }
  
    /**
     * @param String $name
     * @param String[] $row
     * @return Boolean
     */
    function ins($name, $row) {
        
    }
  
    /**
     * @param String $name
     * @param Integer $rowId
     * @return NULL
     */
    function rmv($name, $rowId) {
        
    }
  
    /**
     * @param String $name
     * @param Integer $rowId
     * @param Integer $columnId
     * @return String
     */
    function sel($name, $rowId, $columnId) {
        
    }
  
    /**
     * @param String $name
     * @return String[]
     */
    function exp($name) {
        
    }
}

/**
 * Your SQL object will be instantiated and called as such:
 * $obj = SQL($names, $columns);
 * $ret_1 = $obj->ins($name, $row);
 * $obj->rmv($name, $rowId);
 * $ret_3 = $obj->sel($name, $rowId, $columnId);
 * $ret_4 = $obj->exp($name);
 */
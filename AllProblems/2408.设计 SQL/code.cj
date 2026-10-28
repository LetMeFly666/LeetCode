class SQL {
    init(names: ArrayList<String>, columns: ArrayList<Int64>) {

    }
    
    func ins(name: String, row: ArrayList<String>): Bool {

    }
    
    func rmv(name: String, rowId: Int64): Unit {

    }
    
    func sel(name: String, rowId: Int64, columnId: Int64): String {

    }
    
    func exp(name: String): ArrayList<String> {

    }
}

/**
 * Your SQL object will be instantiated and called as such:
 * let obj: SQL = SQL(names, columns)
 * let param_1 = obj.ins(name,row)
 * obj.rmv(name,rowId)
 * let param_3 = obj.sel(name,rowId,columnId)
 * let param_4 = obj.exp(name)
 */
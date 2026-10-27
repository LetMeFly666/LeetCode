type SQL struct {
    
}


func Constructor(names []string, columns []int) SQL {
    
}


func (this *SQL) Ins(name string, row []string) bool {
    
}


func (this *SQL) Rmv(name string, rowId int)  {
    
}


func (this *SQL) Sel(name string, rowId int, columnId int) string {
    
}


func (this *SQL) Exp(name string) []string {
    
}


/**
 * Your SQL object will be instantiated and called as such:
 * obj := Constructor(names, columns);
 * param_1 := obj.Ins(name,row);
 * obj.Rmv(name,rowId);
 * param_3 := obj.Sel(name,rowId,columnId);
 * param_4 := obj.Exp(name);
 */
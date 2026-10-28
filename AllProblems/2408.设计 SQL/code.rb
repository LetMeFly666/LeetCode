class SQL

=begin
    :type names: String[]
    :type columns: Integer[]
=end
    def initialize(names, columns)
        
    end


=begin
    :type name: String
    :type row: String[]
    :rtype: Boolean
=end
    def ins(name, row)
        
    end


=begin
    :type name: String
    :type row_id: Integer
    :rtype: Void
=end
    def rmv(name, row_id)
        
    end


=begin
    :type name: String
    :type row_id: Integer
    :type column_id: Integer
    :rtype: String
=end
    def sel(name, row_id, column_id)
        
    end


=begin
    :type name: String
    :rtype: String[]
=end
    def exp(name)
        
    end


end

# Your SQL object will be instantiated and called as such:
# obj = SQL.new(names, columns)
# param_1 = obj.ins(name, row)
# obj.rmv(name, row_id)
# param_3 = obj.sel(name, row_id, column_id)
# param_4 = obj.exp(name)
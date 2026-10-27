class SQL(object):

    def __init__(self, names, columns):
        """
        :type names: List[str]
        :type columns: List[int]
        """
        

    def ins(self, name, row):
        """
        :type name: str
        :type row: List[str]
        :rtype: bool
        """
        

    def rmv(self, name, rowId):
        """
        :type name: str
        :type rowId: int
        :rtype: None
        """
        

    def sel(self, name, rowId, columnId):
        """
        :type name: str
        :type rowId: int
        :type columnId: int
        :rtype: str
        """
        

    def exp(self, name):
        """
        :type name: str
        :rtype: List[str]
        """
        


# Your SQL object will be instantiated and called as such:
# obj = SQL(names, columns)
# param_1 = obj.ins(name,row)
# obj.rmv(name,rowId)
# param_3 = obj.sel(name,rowId,columnId)
# param_4 = obj.exp(name)
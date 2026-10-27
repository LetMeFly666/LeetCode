defmodule SQL do
  @spec init_(names :: [String.t], columns :: [integer]) :: any
  def init_(names, columns) do
    
  end

  @spec ins(name :: String.t, row :: [String.t]) :: boolean
  def ins(name, row) do
    
  end

  @spec rmv(name :: String.t, row_id :: integer) :: any
  def rmv(name, row_id) do
    
  end

  @spec sel(name :: String.t, row_id :: integer, column_id :: integer) :: String.t
  def sel(name, row_id, column_id) do
    
  end

  @spec exp(name :: String.t) :: [String.t]
  def exp(name) do
    
  end
end

# Your functions will be called as such:
# SQL.init_(names, columns)
# param_1 = SQL.ins(name, row)
# SQL.rmv(name, row_id)
# param_3 = SQL.sel(name, row_id, column_id)
# param_4 = SQL.exp(name)

# SQL.init_ will be called before every test case, in which you can do some necessary initializations.
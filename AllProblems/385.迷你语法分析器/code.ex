# # This is the interface that allows for creating nested lists.
# # You should not implement it, or speculate about its implementation
#
# # Create an empty nested list.
# :nested_integer.new() :: :nested_integer.nested_integer
#
# # Create a single integer.
# :nested_integer.new(val :: integer) :: :nested_integer.nested_integer
#
# # Return true if argument nested_integer holds a single integer, rather than a nested list.
# :nested_integer.is_integer(nested_integer :: :nested_integer.nested_integer) :: boolean
#
# # Return the single integer that nested_integer holds, if it holds a single integer
# # The result is undefined if it holds a nested list.
# :nested_integer.get_integer(nested_integer :: :nested_integer.nested_integer) :: integer
#
# # Return a copy of argument nested_integer with it set to hold a single integer val.
# :nested_integer.set_integer(nested_integer :: :nested_integer.nested_integer, val :: integer) :: :nested_integer.nested_integer
#
# # Return a copy of argument nested_integer with it set to hold a nested list and adds a nested_integer elem to it.
# :nested_integer.add(nested_integer :: :nested_integer.nested_integer, elem :: :nested_integer.nested_integer) :: :nested_integer.nested_integer
#
# # Return the nested list that nested_integer holds, if it holds a nested list.
# # The result is undefined if it holds a single integer.
# :nested_integer.get_list(nested_integer :: :nested_integer.nested_integer) :: :array.array(:nested_integer.nested_integer)

defmodule Solution do
  @spec deserialize(s :: String.t) :: :nested_integer.nested_integer
  def deserialize(s) do
    
  end
end
defmodule Router do
  @spec init_(memory_limit :: integer) :: any
  def init_(memory_limit) do
    
  end

  @spec add_packet(source :: integer, destination :: integer, timestamp :: integer) :: boolean
  def add_packet(source, destination, timestamp) do
    
  end

  @spec forward_packet() :: [integer]
  def forward_packet() do
    
  end

  @spec get_count(destination :: integer, start_time :: integer, end_time :: integer) :: integer
  def get_count(destination, start_time, end_time) do
    
  end
end

# Your functions will be called as such:
# Router.init_(memory_limit)
# param_1 = Router.add_packet(source, destination, timestamp)
# param_2 = Router.forward_packet()
# param_3 = Router.get_count(destination, start_time, end_time)

# Router.init_ will be called before every test case, in which you can do some necessary initializations.
defmodule TaskManager do
  @spec init_(tasks :: [[integer]]) :: any
  def init_(tasks) do
    
  end

  @spec add(user_id :: integer, task_id :: integer, priority :: integer) :: any
  def add(user_id, task_id, priority) do
    
  end

  @spec edit(task_id :: integer, new_priority :: integer) :: any
  def edit(task_id, new_priority) do
    
  end

  @spec rmv(task_id :: integer) :: any
  def rmv(task_id) do
    
  end

  @spec exec_top() :: integer
  def exec_top() do
    
  end
end

# Your functions will be called as such:
# TaskManager.init_(tasks)
# TaskManager.add(user_id, task_id, priority)
# TaskManager.edit(task_id, new_priority)
# TaskManager.rmv(task_id)
# param_4 = TaskManager.exec_top()

# TaskManager.init_ will be called before every test case, in which you can do some necessary initializations.
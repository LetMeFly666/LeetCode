defmodule Bank do
  @spec init_(balance :: [integer]) :: any
  def init_(balance) do
    
  end

  @spec transfer(account1 :: integer, account2 :: integer, money :: integer) :: boolean
  def transfer(account1, account2, money) do
    
  end

  @spec deposit(account :: integer, money :: integer) :: boolean
  def deposit(account, money) do
    
  end

  @spec withdraw(account :: integer, money :: integer) :: boolean
  def withdraw(account, money) do
    
  end
end

# Your functions will be called as such:
# Bank.init_(balance)
# param_1 = Bank.transfer(account1, account2, money)
# param_2 = Bank.deposit(account, money)
# param_3 = Bank.withdraw(account, money)

# Bank.init_ will be called before every test case, in which you can do some necessary initializations.
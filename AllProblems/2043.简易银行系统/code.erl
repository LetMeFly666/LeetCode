-spec bank_init_(Balance :: [integer()]) -> any().
bank_init_(Balance) ->
  .

-spec bank_transfer(Account1 :: integer(), Account2 :: integer(), Money :: integer()) -> boolean().
bank_transfer(Account1, Account2, Money) ->
  .

-spec bank_deposit(Account :: integer(), Money :: integer()) -> boolean().
bank_deposit(Account, Money) ->
  .

-spec bank_withdraw(Account :: integer(), Money :: integer()) -> boolean().
bank_withdraw(Account, Money) ->
  .


%% Your functions will be called as such:
%% bank_init_(Balance),
%% Param_1 = bank_transfer(Account1, Account2, Money),
%% Param_2 = bank_deposit(Account, Money),
%% Param_3 = bank_withdraw(Account, Money),

%% bank_init_ will be called before every test case, in which you can do some necessary initializations.
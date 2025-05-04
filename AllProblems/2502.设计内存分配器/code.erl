-spec allocator_init_(N :: integer()) -> any().
allocator_init_(N) ->
  .

-spec allocator_allocate(Size :: integer(), MID :: integer()) -> integer().
allocator_allocate(Size, MID) ->
  .

-spec allocator_free_memory(MID :: integer()) -> integer().
allocator_free_memory(MID) ->
  .


%% Your functions will be called as such:
%% allocator_init_(N),
%% Param_1 = allocator_allocate(Size, MID),
%% Param_2 = allocator_free_memory(MID),

%% allocator_init_ will be called before every test case, in which you can do some necessary initializations.
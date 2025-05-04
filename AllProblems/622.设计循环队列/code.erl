-spec my_circular_queue_init_(K :: integer()) -> any().
my_circular_queue_init_(K) ->
  .

-spec my_circular_queue_en_queue(Value :: integer()) -> boolean().
my_circular_queue_en_queue(Value) ->
  .

-spec my_circular_queue_de_queue() -> boolean().
my_circular_queue_de_queue() ->
  .

-spec my_circular_queue_front() -> integer().
my_circular_queue_front() ->
  .

-spec my_circular_queue_rear() -> integer().
my_circular_queue_rear() ->
  .

-spec my_circular_queue_is_empty() -> boolean().
my_circular_queue_is_empty() ->
  .

-spec my_circular_queue_is_full() -> boolean().
my_circular_queue_is_full() ->
  .


%% Your functions will be called as such:
%% my_circular_queue_init_(K),
%% Param_1 = my_circular_queue_en_queue(Value),
%% Param_2 = my_circular_queue_de_queue(),
%% Param_3 = my_circular_queue_front(),
%% Param_4 = my_circular_queue_rear(),
%% Param_5 = my_circular_queue_is_empty(),
%% Param_6 = my_circular_queue_is_full(),

%% my_circular_queue_init_ will be called before every test case, in which you can do some necessary initializations.
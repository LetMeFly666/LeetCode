-spec task_manager_init_(Tasks :: [[integer()]]) -> any().
task_manager_init_(Tasks) ->
  .

-spec task_manager_add(UserId :: integer(), TaskId :: integer(), Priority :: integer()) -> any().
task_manager_add(UserId, TaskId, Priority) ->
  .

-spec task_manager_edit(TaskId :: integer(), NewPriority :: integer()) -> any().
task_manager_edit(TaskId, NewPriority) ->
  .

-spec task_manager_rmv(TaskId :: integer()) -> any().
task_manager_rmv(TaskId) ->
  .

-spec task_manager_exec_top() -> integer().
task_manager_exec_top() ->
  .


%% Your functions will be called as such:
%% task_manager_init_(Tasks),
%% task_manager_add(UserId, TaskId, Priority),
%% task_manager_edit(TaskId, NewPriority),
%% task_manager_rmv(TaskId),
%% Param_4 = task_manager_exec_top(),

%% task_manager_init_ will be called before every test case, in which you can do some necessary initializations.
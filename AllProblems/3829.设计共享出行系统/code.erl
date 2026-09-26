-spec ride_sharing_system_init_() -> any().
ride_sharing_system_init_() ->
  .

-spec ride_sharing_system_add_rider(RiderId :: integer()) -> any().
ride_sharing_system_add_rider(RiderId) ->
  .

-spec ride_sharing_system_add_driver(DriverId :: integer()) -> any().
ride_sharing_system_add_driver(DriverId) ->
  .

-spec ride_sharing_system_match_driver_with_rider() -> [integer()].
ride_sharing_system_match_driver_with_rider() ->
  .

-spec ride_sharing_system_cancel_rider(RiderId :: integer()) -> any().
ride_sharing_system_cancel_rider(RiderId) ->
  .


%% Your functions will be called as such:
%% ride_sharing_system_init_(),
%% ride_sharing_system_add_rider(RiderId),
%% ride_sharing_system_add_driver(DriverId),
%% Param_3 = ride_sharing_system_match_driver_with_rider(),
%% ride_sharing_system_cancel_rider(RiderId),

%% ride_sharing_system_init_ will be called before every test case, in which you can do some necessary initializations.
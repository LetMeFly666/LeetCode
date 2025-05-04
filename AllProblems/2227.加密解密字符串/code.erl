-spec encrypter_init_(Keys :: [char()], Values :: [unicode:unicode_binary()], Dictionary :: [unicode:unicode_binary()]) -> any().
encrypter_init_(Keys, Values, Dictionary) ->
  .

-spec encrypter_encrypt(Word1 :: unicode:unicode_binary()) -> unicode:unicode_binary().
encrypter_encrypt(Word1) ->
  .

-spec encrypter_decrypt(Word2 :: unicode:unicode_binary()) -> integer().
encrypter_decrypt(Word2) ->
  .


%% Your functions will be called as such:
%% encrypter_init_(Keys, Values, Dictionary),
%% Param_1 = encrypter_encrypt(Word1),
%% Param_2 = encrypter_decrypt(Word2),

%% encrypter_init_ will be called before every test case, in which you can do some necessary initializations.
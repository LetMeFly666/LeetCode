-spec report_spam(Message :: [unicode:unicode_binary()], BannedWords :: [unicode:unicode_binary()]) -> boolean().
report_spam(Message, BannedWords) ->
  .
<!--
 * @Author: LetMeFly
 * @Date: 2025-12-20 10:40:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-20 10:40:08
-->
PS C:\Users\LetMe\Desktop\LeetCode-test> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query($id:ID!) {
>> >>     node(id:$id) { __typename }
>> >>   }
>> >> ' -f id=PVT_kwHOA2Wuss4BKNdu
>> {
>>   "data": {
>>     "node": {
>>       "__typename": "ProjectV2"
>>     }
>>   }
>> }
>> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query($id:ID!) {
>> >>     node(id:$id) { __typename }
>> >>   }
>> >> ' -f id=PVT_kwHOA2Wuss4BKNduzg
>> {
>>   "data": {
>>     "node": null
>>   },
>>   "errors": [
>>     {
>>       "path": [
>>         "node"
>>       ],
>>       "locations": [
>>         {
>>           "line": 3,
>>           "column": 5
>>         }
>>       ],
>>       "message": "Could not resolve to a node with the global id of 'PVT_kwHOA2Wuss4BKNduzg'"
>>     }
>>   ]
>> }
>> gh: Could not resolve to a node with the global id of 'PVT_kwHOA2Wuss4BKNduzg'
>> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query {
>> >>     user(login: "LetMeFly666") {
>> >>       projectV2(number: 5) {
>> >>         id
>> >>         title
>> >>       }
>> >>     }
>> >>   }
>> >> '
>> >>
>> {
>>   "errors": [
>>     {
>>       "path": [
>>         "query",
>>         "user",
>>         "login"
>>       ],
>>       "extensions": {
>>         "code": "argumentLiteralsIncompatible",
>>         "typeName": "Field",
>>         "argumentName": "login"
>>       },
>>       "locations": [
>>         {
>>           "line": 3,
>>           "column": 5
>>         }
>>       ],
>>       "message": "Argument 'login' on Field 'user' has an invalid value (LetMeFly666). Expected type 'String!'."
>>     }
>>   ]
>> }
>> gh: Argument 'login' on Field 'user' has an invalid value (LetMeFly666). Expected type 'String!'.
哎呀，出现问题。请在报告此 Bug 时添加以下详细信息。
在 GitHub 上报告: https://github.com/lzybkr/PSReadLine/issues/new
-----------------------------------------------------------------------
上 39 个密钥:
 g i t Space p u s h Enter
 g i t Space p u s h Enter
 Enter
 g i t Space p u s h Enter
 g i t Space p u s h Enter
 Ctrl+v Ctrl+c

异常:
System.ArgumentOutOfRangeException: 该值必须大于或等于零，且必须小于控制台缓冲区在该维度的大小。
参数名: top
实际值是 -45。
   在 System.Console.SetCursorPosition(Int32 left, Int32 top)
   在 Microsoft.PowerShell.PSConsoleReadLine.ReallyRender(RenderData renderData, String defaultColor)
   在 Microsoft.PowerShell.PSConsoleReadLine.ForceRender()
   在 Microsoft.PowerShell.PSConsoleReadLine.CancelLine(Nullable`1 key, Object arg)
   在 Microsoft.PowerShell.PSConsoleReadLine.CopyOrCancelLine(Nullable`1 key, Object arg)
   在 Microsoft.PowerShell.PSConsoleReadLine.ProcessOneKey(ConsoleKeyInfo key, Dictionary`2 dispatchTable, Boolean ignoreIfNoAction, Object arg)
   在 Microsoft.PowerShell.PSConsoleReadLine.InputLoop()
   在 Microsoft.PowerShell.PSConsoleReadLine.ReadLine(Runspace runspace, EngineIntrinsics engineIntrinsics)
-----------------------------------------------------------------------
PS C:\Users\LetMe\Desktop\LeetCode-test> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query($id:ID!) {
>> >>     node(id:$id) { __typename }
>> >>   }
>> >> ' -f id=PVT_kwHOA2Wuss4BKNdu
>> {
>>   "data": {
>>     "node": {
>>       "__typename": "ProjectV2"
>>     }
>>   }
>> }
>> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query($id:ID!) {
>> >>     node(id:$id) { __typename }
>> >>   }
>> >> ' -f id=PVT_kwHOA2Wuss4BKNduzg
>> {
>>   "data": {
>>     "node": null
>>   },
>>   "errors": [
>>     {
>>       "path": [
>>         "node"
>>       ],
>>       "locations": [
>>         {
>>           "line": 3,
>>           "column": 5
>>         }
>>       ],
>>       "message": "Could not resolve to a node with the global id of 'PVT_kwHOA2Wuss4BKNduzg'"
>>     }
>>   ]
>> }
>> gh: Could not resolve to a node with the global id of 'PVT_kwHOA2Wuss4BKNduzg'
>> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query {
>> >>     user(login: "LetMeFly666") {
>> >>       projectV2(number: 5) {
>> >>         id
>> >>         title
>> >>       }
>> >>     }
>> >>   }
>> >> '
>> >>
>> {
>>   "errors": [
>>     {
>>       "path": [
>>         "query",
>>         "user",
>>         "login"
>>       ],
>>       "extensions": {
>>         "code": "argumentLiteralsIncompatible",
>>         "typeName": "Field",
>>         "argumentName": "login"
>>       },
>>       "locations": [
>>         {
>>           "line": 3,
>>           "column": 5
>>         }
>>       ],
>>       "message": "Argument 'login' on Field 'user' has an invalid value (LetMeFly666). Expected type 'String!'."
>>     }
>>   ]
>> }
>> gh: Argument 'login' on Field 'user' has an invalid value (LetMeFly666). Expected type 'String!'.
哎呀，出现问题。请在报告此 Bug 时添加以下详细信息。
在 GitHub 上报告: https://github.com/lzybkr/PSReadLine/issues/new
-----------------------------------------------------------------------
上 40 个密钥:
 g i t Space p u s h Enter
 g i t Space p u s h Enter
 Enter
 g i t Space p u s h Enter
 g i t Space p u s h Enter
 Ctrl+v Ctrl+c Ctrl+a

异常:
System.ArgumentOutOfRangeException: 该值必须大于或等于零，且必须小于控制台缓冲区在该维度的大小。
参数名: top
实际值是 -45。
   在 System.Console.SetCursorPosition(Int32 left, Int32 top)
   在 Microsoft.PowerShell.PSConsoleReadLine.ReallyRender(RenderData renderData, String defaultColor)
   在 Microsoft.PowerShell.PSConsoleReadLine.ForceRender()
   在 Microsoft.PowerShell.PSConsoleReadLine.ProcessOneKey(ConsoleKeyInfo key, Dictionary`2 dispatchTable, Boolean ignoreIfNoAction, Object arg)
   在 Microsoft.PowerShell.PSConsoleReadLine.InputLoop()
   在 Microsoft.PowerShell.PSConsoleReadLine.ReadLine(Runspace runspace, EngineIntrinsics engineIntrinsics)
-----------------------------------------------------------------------
PS C:\Users\LetMe\Desktop\LeetCode-test> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query($id:ID!) {
>> >>     node(id:$id) { __typename }
>> >>   }
>> >> ' -f id=PVT_kwHOA2Wuss4BKNdu
>> {
>>   "data": {
>>     "node": {
>>       "__typename": "ProjectV2"
>>     }
>>   }
>> }
>> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query($id:ID!) {
>> >>     node(id:$id) { __typename }
>> >>   }
>> >> ' -f id=PVT_kwHOA2Wuss4BKNduzg
>> {
>>   "data": {
>>     "node": null
>>   },
>>   "errors": [
>>     {
>>       "path": [
>>         "node"
>>       ],
>>       "locations": [
>>         {
>>           "line": 3,
>>           "column": 5
>>         }
>>       ],
>>       "message": "Could not resolve to a node with the global id of 'PVT_kwHOA2Wuss4BKNduzg'"
>>     }
>>   ]
>> }
>> gh: Could not resolve to a node with the global id of 'PVT_kwHOA2Wuss4BKNduzg'
>> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query {
>> >>     user(login: "LetMeFly666") {
>> >>       projectV2(number: 5) {
>> >>         id
>> >>         title
>> >>       }
>> >>     }
>> >>   }
>> >> '
>> >>
>> {
>>   "errors": [
>>     {
>>       "path": [
>>         "query",
>>         "user",
>>         "login"
>>       ],
>>       "extensions": {
>>         "code": "argumentLiteralsIncompatible",
>>         "typeName": "Field",
>>         "argumentName": "login"
>>       },
>>       "locations": [
>>         {
>>           "line": 3,
>>           "column": 5
>>         }
>>       ],
>>       "message": "Argument 'login' on Field 'user' has an invalid value (LetMeFly666). Expected type 'String!'."
>>     }
>>   ]
>> }
>> gh: Argument 'login' on Field 'user' has an invalid value (LetMeFly666). Expected type 'String!'.
哎呀，出现问题。请在报告此 Bug 时添加以下详细信息。
在 GitHub 上报告: https://github.com/lzybkr/PSReadLine/issues/new
-----------------------------------------------------------------------
上 41 个密钥:
 g i t Space p u s h Enter
 g i t Space p u s h Enter
 Enter
 g i t Space p u s h Enter
 g i t Space p u s h Enter
 Ctrl+v Ctrl+c Ctrl+a Ctrl+a

异常:
System.ArgumentOutOfRangeException: 该值必须大于或等于零，且必须小于控制台缓冲区在该维度的大小。
参数名: top
实际值是 -45。
   在 System.Console.SetCursorPosition(Int32 left, Int32 top)
   在 Microsoft.PowerShell.PSConsoleReadLine.ReallyRender(RenderData renderData, String defaultColor)
   在 Microsoft.PowerShell.PSConsoleReadLine.ForceRender()
   在 Microsoft.PowerShell.PSConsoleReadLine.ProcessOneKey(ConsoleKeyInfo key, Dictionary`2 dispatchTable, Boolean ignoreIfNoAction, Object arg)
   在 Microsoft.PowerShell.PSConsoleReadLine.InputLoop()
   在 Microsoft.PowerShell.PSConsoleReadLine.ReadLine(Runspace runspace, EngineIntrinsics engineIntrinsics)
-----------------------------------------------------------------------
PS C:\Users\LetMe\Desktop\LeetCode-test> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query($id:ID!) {
>> >>     node(id:$id) { __typename }
>> >>   }
>> >> ' -f id=PVT_kwHOA2Wuss4BKNdu
>> {
>>   "data": {
>>     "node": {
>>       "__typename": "ProjectV2"
>>     }
>>   }
>> }
>> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query($id:ID!) {
>> >>     node(id:$id) { __typename }
>> >>   }
>> >> ' -f id=PVT_kwHOA2Wuss4BKNduzg
>> {
>>   "data": {
>>     "node": null
>>   },
>>   "errors": [
>>     {
>>       "path": [
>>         "node"
>>       ],
>>       "locations": [
>>         {
>>           "line": 3,
>>           "column": 5
>>         }
>>       ],
>>       "message": "Could not resolve to a node with the global id of 'PVT_kwHOA2Wuss4BKNduzg'"
>>     }
>>   ]
>> }
>> gh: Could not resolve to a node with the global id of 'PVT_kwHOA2Wuss4BKNduzg'
>> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query {
>> >>     user(login: "LetMeFly666") {
>> >>       projectV2(number: 5) {
>> >>         id
>> >>         title
>> >>       }
>> >>     }
>> >>   }
>> >> '
>> >>
>> {
>>   "errors": [
>>     {
>>       "path": [
>>         "query",
>>         "user",
>>         "login"
>>       ],
>>       "extensions": {
>>         "code": "argumentLiteralsIncompatible",
>>         "typeName": "Field",
>>         "argumentName": "login"
>>       },
>>       "locations": [
>>         {
>>           "line": 3,
>>           "column": 5
>>         }
>>       ],
>>       "message": "Argument 'login' on Field 'user' has an invalid value (LetMeFly666). Expected type 'String!'."
>>     }
>>   ]
>> }
>> gh: Argument 'login' on Field 'user' has an invalid value (LetMeFly666). Expected type 'String!'.
哎呀，出现问题。请在报告此 Bug 时添加以下详细信息。
在 GitHub 上报告: https://github.com/lzybkr/PSReadLine/issues/new
-----------------------------------------------------------------------
上 42 个密钥:
 g i t Space p u s h Enter
 g i t Space p u s h Enter
 Enter
 g i t Space p u s h Enter
 g i t Space p u s h Enter
 Ctrl+v Ctrl+c Ctrl+a Ctrl+a Ctrl+a

异常:
System.ArgumentOutOfRangeException: 该值必须大于或等于零，且必须小于控制台缓冲区在该维度的大小。
参数名: top
实际值是 -45。
   在 System.Console.SetCursorPosition(Int32 left, Int32 top)
   在 Microsoft.PowerShell.PSConsoleReadLine.ReallyRender(RenderData renderData, String defaultColor)
   在 Microsoft.PowerShell.PSConsoleReadLine.ForceRender()
   在 Microsoft.PowerShell.PSConsoleReadLine.ProcessOneKey(ConsoleKeyInfo key, Dictionary`2 dispatchTable, Boolean ignoreIfNoAction, Object arg)
   在 Microsoft.PowerShell.PSConsoleReadLine.InputLoop()
   在 Microsoft.PowerShell.PSConsoleReadLine.ReadLine(Runspace runspace, EngineIntrinsics engineIntrinsics)
-----------------------------------------------------------------------
PS C:\Users\LetMe\Desktop\LeetCode-test> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query($id:ID!) {
>> >>     node(id:$id) { __typename }
>> >>   }
>> >> ' -f id=PVT_kwHOA2Wuss4BKNdu
>> {
>>   "data": {
>>     "node": {
>>       "__typename": "ProjectV2"
>>     }
>>   }
>> }
>> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query($id:ID!) {
>> >>     node(id:$id) { __typename }
>> >>   }
>> >> ' -f id=PVT_kwHOA2Wuss4BKNduzg
>> {
>>   "data": {
>>     "node": null
>>   },
>>   "errors": [
>>     {
>>       "path": [
>>         "node"
>>       ],
>>       "locations": [
>>         {
>>           "line": 3,
>>           "column": 5
>>         }
>>       ],
>>       "message": "Could not resolve to a node with the global id of 'PVT_kwHOA2Wuss4BKNduzg'"
>>     }
>>   ]
>> }
>> gh: Could not resolve to a node with the global id of 'PVT_kwHOA2Wuss4BKNduzg'
>> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query {
>> >>     user(login: "LetMeFly666") {
>> >>       projectV2(number: 5) {
>> >>         id
>> >>         title
>> >>       }
>> >>     }
>> >>   }
>> >> '
>> >>
>> {
>>   "errors": [
>>     {
>>       "path": [
>>         "query",
>>         "user",
>>         "login"
>>       ],
>>       "extensions": {
>>         "code": "argumentLiteralsIncompatible",
>>         "typeName": "Field",
>>         "argumentName": "login"
>>       },
>>       "locations": [
>>         {
>>           "line": 3,
>>           "column": 5
>>         }
>>       ],
>>       "message": "Argument 'login' on Field 'user' has an invalid value (LetMeFly666). Expected type 'String!'."
>>     }
>>   ]
>> }
>> gh: Argument 'login' on Field 'user' has an invalid value (LetMeFly666). Expected type 'String!'.
哎呀，出现问题。请在报告此 Bug 时添加以下详细信息。
在 GitHub 上报告: https://github.com/lzybkr/PSReadLine/issues/new
-----------------------------------------------------------------------
上 43 个密钥:
 g i t Space p u s h Enter
 g i t Space p u s h Enter
 Enter
 g i t Space p u s h Enter
 g i t Space p u s h Enter
 Ctrl+v Ctrl+c Ctrl+a Ctrl+a Ctrl+a Ctrl+a

异常:
System.ArgumentOutOfRangeException: 该值必须大于或等于零，且必须小于控制台缓冲区在该维度的大小。
参数名: top
实际值是 -45。
   在 System.Console.SetCursorPosition(Int32 left, Int32 top)
   在 Microsoft.PowerShell.PSConsoleReadLine.ReallyRender(RenderData renderData, String defaultColor)
   在 Microsoft.PowerShell.PSConsoleReadLine.ForceRender()
   在 Microsoft.PowerShell.PSConsoleReadLine.ProcessOneKey(ConsoleKeyInfo key, Dictionary`2 dispatchTable, Boolean ignoreIfNoAction, Object arg)
   在 Microsoft.PowerShell.PSConsoleReadLine.InputLoop()
   在 Microsoft.PowerShell.PSConsoleReadLine.ReadLine(Runspace runspace, EngineIntrinsics engineIntrinsics)
-----------------------------------------------------------------------
PS C:\Users\LetMe\Desktop\LeetCode-test> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query($id:ID!) {
>> >>     node(id:$id) { __typename }
>> >>   }
>> >> ' -f id=PVT_kwHOA2Wuss4BKNdu
>> {
>>   "data": {
>>     "node": {
>>       "__typename": "ProjectV2"
>>     }
>>   }
>> }
>> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query($id:ID!) {
>> >>     node(id:$id) { __typename }
>> >>   }
>> >> ' -f id=PVT_kwHOA2Wuss4BKNduzg
>> {
>>   "data": {
>>     "node": null
>>   },
>>   "errors": [
>>     {
>>       "path": [
>>         "node"
>>       ],
>>       "locations": [
>>         {
>>           "line": 3,
>>           "column": 5
>>         }
>>       ],
>>       "message": "Could not resolve to a node with the global id of 'PVT_kwHOA2Wuss4BKNduzg'"
>>     }
>>   ]
>> }
>> gh: Could not resolve to a node with the global id of 'PVT_kwHOA2Wuss4BKNduzg'
>> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query {
>> >>     user(login: "LetMeFly666") {
>> >>       projectV2(number: 5) {
>> >>         id
>> >>         title
>> >>       }
>> >>     }
>> >>   }
>> >> '
>> >>
>> {
>>   "errors": [
>>     {
>>       "path": [
>>         "query",
>>         "user",
>>         "login"
>>       ],
>>       "extensions": {
>>         "code": "argumentLiteralsIncompatible",
>>         "typeName": "Field",
>>         "argumentName": "login"
>>       },
>>       "locations": [
>>         {
>>           "line": 3,
>>           "column": 5
>>         }
>>       ],
>>       "message": "Argument 'login' on Field 'user' has an invalid value (LetMeFly666). Expected type 'String!'."
>>     }
>>   ]
>> }
>> gh: Argument 'login' on Field 'user' has an invalid value (LetMeFly666). Expected type 'String!'.
哎呀，出现问题。请在报告此 Bug 时添加以下详细信息。
在 GitHub 上报告: https://github.com/lzybkr/PSReadLine/issues/new
-----------------------------------------------------------------------
上 44 个密钥:
 g i t Space p u s h Enter
 g i t Space p u s h Enter
 Enter
 g i t Space p u s h Enter
 g i t Space p u s h Enter
 Ctrl+v Ctrl+c Ctrl+a Ctrl+a Ctrl+a Ctrl+a Ctrl+a

异常:
System.ArgumentOutOfRangeException: 该值必须大于或等于零，且必须小于控制台缓冲区在该维度的大小。
参数名: top
实际值是 -45。
   在 System.Console.SetCursorPosition(Int32 left, Int32 top)
   在 Microsoft.PowerShell.PSConsoleReadLine.ReallyRender(RenderData renderData, String defaultColor)
   在 Microsoft.PowerShell.PSConsoleReadLine.ForceRender()
   在 Microsoft.PowerShell.PSConsoleReadLine.ProcessOneKey(ConsoleKeyInfo key, Dictionary`2 dispatchTable, Boolean ignoreIfNoAction, Object arg)
   在 Microsoft.PowerShell.PSConsoleReadLine.InputLoop()
   在 Microsoft.PowerShell.PSConsoleReadLine.ReadLine(Runspace runspace, EngineIntrinsics engineIntrinsics)
-----------------------------------------------------------------------
PS C:\Users\LetMe\Desktop\LeetCode-test> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query($id:ID!) {
>> >>     node(id:$id) { __typename }
>> >>   }
>> >> ' -f id=PVT_kwHOA2Wuss4BKNdu
>> {
>>   "data": {
>>     "node": {
>>       "__typename": "ProjectV2"
>>     }
>>   }
>> }
>> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query($id:ID!) {
>> >>     node(id:$id) { __typename }
>> >>   }
>> >> ' -f id=PVT_kwHOA2Wuss4BKNduzg
>> {
>>   "data": {
>>     "node": null
>>   },
>>   "errors": [
>>     {
>>       "path": [
>>         "node"
>>       ],
>>       "locations": [
>>         {
>>           "line": 3,
>>           "column": 5
>>         }
>>       ],
>>       "message": "Could not resolve to a node with the global id of 'PVT_kwHOA2Wuss4BKNduzg'"
>>     }
>>   ]
>> }
>> gh: Could not resolve to a node with the global id of 'PVT_kwHOA2Wuss4BKNduzg'
>> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query {
>> >>     user(login: "LetMeFly666") {
>> >>       projectV2(number: 5) {
>> >>         id
>> >>         title
>> >>       }
>> >>     }
>> >>   }
>> >> '
>> >>
>> {
>>   "errors": [
>>     {
>>       "path": [
>>         "query",
>>         "user",
>>         "login"
>>       ],
>>       "extensions": {
>>         "code": "argumentLiteralsIncompatible",
>>         "typeName": "Field",
>>         "argumentName": "login"
>>       },
>>       "locations": [
>>         {
>>           "line": 3,
>>           "column": 5
>>         }
>>       ],
>>       "message": "Argument 'login' on Field 'user' has an invalid value (LetMeFly666). Expected type 'String!'."
>>     }
>>   ]
>> }
>> gh: Argument 'login' on Field 'user' has an invalid value (LetMeFly666). Expected type 'String!'.
哎呀，出现问题。请在报告此 Bug 时添加以下详细信息。
在 GitHub 上报告: https://github.com/lzybkr/PSReadLine/issues/new
-----------------------------------------------------------------------
上 45 个密钥:
 g i t Space p u s h Enter
 g i t Space p u s h Enter
 Enter
 g i t Space p u s h Enter
 g i t Space p u s h Enter
 Ctrl+v Ctrl+c Ctrl+a Ctrl+a Ctrl+a Ctrl+a Ctrl+a Ctrl+a

异常:
System.ArgumentOutOfRangeException: 该值必须大于或等于零，且必须小于控制台缓冲区在该维度的大小。
参数名: top
实际值是 -45。
   在 System.Console.SetCursorPosition(Int32 left, Int32 top)
   在 Microsoft.PowerShell.PSConsoleReadLine.ReallyRender(RenderData renderData, String defaultColor)
   在 Microsoft.PowerShell.PSConsoleReadLine.ForceRender()
   在 Microsoft.PowerShell.PSConsoleReadLine.ProcessOneKey(ConsoleKeyInfo key, Dictionary`2 dispatchTable, Boolean ignoreIfNoAction, Object arg)
   在 Microsoft.PowerShell.PSConsoleReadLine.InputLoop()
   在 Microsoft.PowerShell.PSConsoleReadLine.ReadLine(Runspace runspace, EngineIntrinsics engineIntrinsics)
-----------------------------------------------------------------------
PS C:\Users\LetMe\Desktop\LeetCode-test> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query($id:ID!) {
>> >>     node(id:$id) { __typename }
>> >>   }
>> >> ' -f id=PVT_kwHOA2Wuss4BKNdu
>> {
>>   "data": {
>>     "node": {
>>       "__typename": "ProjectV2"
>>     }
>>   }
>> }
>> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query($id:ID!) {
>> >>     node(id:$id) { __typename }
>> >>   }
>> >> ' -f id=PVT_kwHOA2Wuss4BKNduzg
>> {
>>   "data": {
>>     "node": null
>>   },
>>   "errors": [
>>     {
>>       "path": [
>>         "node"
>>       ],
>>       "locations": [
>>         {
>>           "line": 3,
>>           "column": 5
>>         }
>>       ],
>>       "message": "Could not resolve to a node with the global id of 'PVT_kwHOA2Wuss4BKNduzg'"
>>     }
>>   ]
>> }
>> gh: Could not resolve to a node with the global id of 'PVT_kwHOA2Wuss4BKNduzg'
>> PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> gh api graphql -f query='
>> >>   query {
>> >>     user(login: "LetMeFly666") {
>> >>       projectV2(number: 5) {
>> >>         id
>> >>         title
>> >>       }
>> >>     }
>> >>   }
>> >> '
>> >>
>> {
>>   "errors": [
>>     {
>>       "path": [
>>         "query",
>>         "user",
>>         "login"
>>       ],
>>       "extensions": {
>>         "code": "argumentLiteralsIncompatible",
>>         "typeName": "Field",
>>         "argumentName": "login"
>>       },
>>       "locations": [
>>         {
>>           "line": 3,
>>           "column": 5
>>         }
>>       ],
>>       "message": "Argument 'login' on Field 'user' has an invalid value (LetMeFly666). Expected type 'String!'."
>>     }
>>   ]
>> }
>> gh: Argument 'login' on Field 'user' has an invalid value (LetMeFly666). Expected type 'String!'.
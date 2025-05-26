PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> git cm "1857: AC.cpp+py + CE.java (#956)
>> 
>> cpp - AC,71.94%,89.21%
>> py - AC,55.40%,77.03%
>> 
>> Java的API好复杂啊
>> 
>> coding while chating
哎呀，出现问题。请在报告此 Bug 时添加以下详细信息。
在 GitHub 上报告: https://github.com/lzybkr/PSReadLine/issues/new
-----------------------------------------------------------------------
上 200 个密钥:
 t Space c m Space " Ctrl+v " Enter
 g i t Space p u s h Enter
 g i t Space s w i t c h Space m a s t e r Enter
 g i t Space b r a n c h Enter
 g i t Space p u l l Space o r i g i n Space m a s t e r Enter
 g i t Space f e t c h Space o r i g i n Space 1 8 5 7 Enter
 g i t Space b r a n c h Space - d Space Ctrl+v Enter
 g i t Space s w i t c h Space - c Space 1 8 5 7 Space o r i g i n / 1 8 5 7 Enter
 g i t Space s t a t u s Enter
 g i t Space c m Space " Ctrl+v " Enter
 g i t Space p u s h Enter
 g i t Space c m Space " Ctrl+v " Enter
 g i t Space p u s h Enter
 g i t Space c m Space " Ctrl+v "

异常:
System.ArgumentOutOfRangeException: 该值必须大于或等于零，且必须小于控制台缓冲区在该维度的大小。
参数名: top
实际值是 -1。
   在 System.Console.SetCursorPosition(Int32 left, Int32 top)
   在 Microsoft.PowerShell.PSConsoleReadLine.ReallyRender(RenderData renderData, String defaultColor)
   在 Microsoft.PowerShell.PSConsoleReadLine.ForceRender()
   在 Microsoft.PowerShell.PSConsoleReadLine.Insert(Char c)
   在 Microsoft.PowerShell.PSConsoleReadLine.SelfInsert(Nullable`1 key, Object arg)
   在 Microsoft.PowerShell.PSConsoleReadLine.ProcessOneKey(ConsoleKeyInfo key, Dictionary`2 dispatchTable, Boolean ignoreIfNoAction, Object arg)
   在 Microsoft.PowerShell.PSConsoleReadLine.InputLoop()
   在 Microsoft.PowerShell.PSConsoleReadLine.ReadLine(Runspace runspace, EngineIntrinsics engineIntrinsics)
-----------------------------------------------------------------------
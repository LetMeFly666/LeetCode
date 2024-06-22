; 定义一个热键来启动脚本，例如Ctrl+Alt+R
; ^!r::
; SetTimer, SendEnter, 10000 ; 每10秒执行一次
; MsgBox, Script started and timer set.
Sleep, 2000



IfWinExist, 微信
{
    WinActivate
    Sleep, 500
    Send, {Enter}
    MsgBox, Sent Enter key to window.
}
else
{
    MsgBox, Window not found.
}
return

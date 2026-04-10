'
' @Author: LetMeFly
' @Date: 2026-04-07 10:04:17
' @LastEditors: LetMeFly.xyz
' @LastEditTime: 2026-04-09 21:49:22
'
Sub ScaleShapesOnSlide()
    Dim s As Shape
    Dim ratio As Double
    Dim slideIndex As Long
    
    ratio = 1.5       '放大倍数，按需改
    slideIndex = 1     '要操作的幻灯片页码
    
    For Each s In ActivePresentation.Slides(slideIndex).Shapes
        '等比缩放位置和尺寸
        s.Left = s.Left * ratio
        s.Top = s.Top * ratio
        s.Width = s.Width * ratio
        s.Height = s.Height * ratio
    Next
End Sub

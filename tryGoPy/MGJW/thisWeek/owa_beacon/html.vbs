Sub htmlTest()
Dim insp As Inspector
Set insp = ActiveInspector
If insp.IsWordMail Then
Dim wordDoc As Word.document
Set wordDoc = insp.WordEditor
wordDoc.Application.Selection.InsertFile "C:\Users\LetMeFly\Desktop\installer\script\owa_beacon\email.html", , False, False, False
End If
End Sub

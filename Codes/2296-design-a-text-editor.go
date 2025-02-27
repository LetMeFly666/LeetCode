/*
 * @Author: LetMeFly
 * @Date: 2025-02-27 10:34:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-27 10:55:47
 */
package main

type TextEditor struct {
    left, right []byte
}


func Constructor() TextEditor {
    return TextEditor{};
}

func (this *TextEditor) text() string {
    return string(this.left[max(0, len(this.left) - 10):])
}


func (this *TextEditor) AddText(text string)  {
    this.left = append(this.left, text...)
}


func (this *TextEditor) DeleteText(k int) int {
    k = min(k, len(this.left))
    this.left = this.left[:len(this.left) - k]
    return k
}


func (this *TextEditor) CursorLeft(k int) string {
    for ; k > 0 && len(this.left) > 0; k-- {
        this.right = append(this.right, this.left[len(this.left) - 1])
        this.left = this.left[:len(this.left) - 1]
    }
    return this.text()
}


func (this *TextEditor) CursorRight(k int) string {
    for ; k > 0 && len(this.right) > 0; k-- {
        this.left = append(this.left, this.right[len(this.right) - 1])
        this.right = this.right[:len(this.right) - 1]
    }
    return this.text()
}


/**
 * Your TextEditor object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddText(text);
 * param_2 := obj.DeleteText(k);
 * param_3 := obj.CursorLeft(k);
 * param_4 := obj.CursorRight(k);
 */
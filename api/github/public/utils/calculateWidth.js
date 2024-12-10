/*
 * @Author: LetMeFly
 * @Date: 2024-12-10 23:50:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-11 00:06:21
 */
export function calculateTextWidth(text, fontSize=16) {
    const averageCharacterWidth = 0.5;  // 假设每个字符宽度为字体大小的0.5倍
    const textLength = text.length;
    // 估算文本的宽度
    const estimatedWidth = textLength * fontSize * averageCharacterWidth;
    console.log(textLength);
    console.log(fontSize);
    console.log(averageCharacterWidth);
    console.log(estimatedWidth);
    return estimatedWidth;
}
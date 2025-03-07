/*
 * @Author: LetMeFly
 * @Date: 2025-03-07 18:10:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-07 23:31:45
 */
github merge使用rebase方式的时候，会默认生成一些message消息体。消息体中一般包含了多次commit的具体内容。
默认的消息体不包含签名“Signed-off-by: LetMeFly666 <814114971@qq.com>”，但是我可以在进行merge的时候手动加上这一行。
但是我使用github gh进行rebase方式的merge的时候，似乎要么采用默认内容，要么手动定义内容。如何做到在默认内容的同时最后一行加上签名？

---

git pr以squash的方式合并时，
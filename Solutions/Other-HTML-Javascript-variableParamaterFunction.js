/*
 * @Author: LetMeFly
 * @Date: 2023-04-05 21:06:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-05 21:08:11
 */
function MySum() {
    var ans = 0;
    for (var i = 0; i < arguments.length; i++) {
        ans += arguments[i];
    }
    return ans;
}

const SUM = MySum(1, 2, 3, 4);
console.log(SUM);
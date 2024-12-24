/*
 * @Author: LetMeFly
 * @Date: 2024-12-20 22:14:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-21 21:36:00
 */
export function getCookie(request, name) {
    const cookieHeader = request.headers.get("Cookie")
    // console.log(cookieHeader);
    const cookies = cookieHeader ? cookieHeader.split(';') : []
    // console.log(cookies);
    for (let cookie of cookies) {
        const [key, value] = cookie.trim().split('=')
        // console.log(key, value);
        // console.log(`key = ${key}, name = ${name}, key === name: ${key === name}`)
        if (key.toLowerCase() === name.toLowerCase()) {  // fix: cookie中获取到的key是全小写
            return value
        }
    }
    return null
}
/*
 * @Author: LetMeFly
 * @Date: 2024-12-20 22:14:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-20 22:14:33
 */
export function getCookie(request, name) {
    const cookieHeader = request.headers.get("Cookie")
    const cookies = cookieHeader ? cookieHeader.split(';') : []
    for (let cookie of cookies) {
        const [key, value] = cookie.trim().split('=')
        if (key === name) {
            return value
        }
    }
    return null
}
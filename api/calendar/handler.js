/*
 * @Author: LetMeFly
 * @Date: 2024-12-15 16:34:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-15 17:31:31
 */
import { indexHTML } from "./front/html"

// 返回主页HTML
export async function index(request) {
    return await indexHTML();
}

// 事件处理函数
export async function events(request) {
    if (request.method == 'POST') {
        return await createEvent(request);
    } else if (request.method == 'GET') {
        return await getEvents(request);
    } else if (request.method == 'DELETE') {
        return await deleteEvent(request);
    }
}
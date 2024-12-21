/*
 * @Author: LetMeFly
 * @Date: 2024-12-15 16:34:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-21 21:18:36
 */
import { indexHTML } from "./front/html"
import { createEvent, getEvents, deleteEvent } from "./back/event";

// 返回主页HTML
export async function index() {
    return await indexHTML();
}

// 事件处理函数
export async function events(request, env) {
    if (request.method == 'POST') {
        return await createEvent(request, env);
    } else if (request.method == 'GET') {
        return await getEvents(request, env);
    } else if (request.method == 'DELETE') {
        return await deleteEvent(request, env);
    }
}
/*
 * @Author: LetMeFly
 * @Date: 2024-12-15 16:34:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-26 08:32:48
 */
import { indexHTMLFunc, files } from "./front/fileRouter"
import { createEvent, getEvents, deleteEvent } from "./back/event";
import { createTag, getTags, deleteTag, alterTag } from "./back/tags";

// 返回主页HTML
export async function index(request) {
    return await indexHTMLFunc(request);
}

// 返回前端所需文件 cs js html等
export async function front(request) {
    return await files(request);
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

// 标签处理函数
export async function tags(request, env) {
    if (request.method == 'POST') {
        return await createTag(request, env);
    } else if (request.method == 'GET') {
        return await getTags(request, env);
    } else if (request.method == 'DELETE') {
        return await deleteTag(request, env);
    } else if (request.method == 'PUT') {
        return await alterTag(request, env);
    }
}
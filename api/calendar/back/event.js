/*
 * @Author: LetMeFly
 * @Date: 2024-12-17 23:11:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-20 22:16:14
 */
import { getUserIdFromPassKey } from "./user";
import { getCookie } from "./cookie";

// 创建事件
export async function createEvent(request) {
    // 获取参数、信息
    const { title, description, startTime, during, tags } = await request.json();
    const passKey = getCookie(request, 'passKey');
    const userid = await getUserIdFromPassKey(passKey);
    if (!userid) {
        return new Response('Invalid passKey', { status: 401 });
    }
    // 添加任务
    const insertTaskQuery = `
        INSERT INTO Calendar_Tasks (title, description, startTime, during, userid)
        VALUES (?, ?, ?, ?, ?);
    `;
    const taskValues = [title, description, startTime, during, userid];
    try {
        const taskResult = await CALENDAR_DB.prepare(insertTaskQuery).bind(...taskValues).run();
        const taskId = taskResult.lastInsertRowid;
        if (tags && tags.length > 0) {
            const insertTagQuery = `
                INSERT INTO Calendar_TaskTag (taskID, tagId)
                VALUES ${tags.map(() => '(?, ?)').join(', ')};
            `;
            const tagValues = tags.flatMap(tagId => [taskId, tagId]);
            await CALENDAR_DB.prepare(insertTagQuery).bind(...tagValues).run();
            return new Response(JSON.stringify({ success: "ok", taskId }), { status: 200 });
        }
    } catch (error) {
        return new Response('Failed to create task', { status: 500 });
    }
}

// 获取事件 - TODO: 依据日期筛选，要不然会越来越多。
export async function getEvents(request) {
    const passKey = getCookie(request, 'passkey');
    const userid = await getUserIdFromPassKey(passKey);
    if (!userid) {
        return new Response('Invalid passKey', { status: 401 })
    }
    const tasks = await CALENDAR_DB.prepare(`
        SELECT * FROM Calendar_Tasks WHERE userid = ?
    `).bind(passKey).all();
    return new Response(JSON.stringify(tasks), { headers: {'Content-Type': 'application/json'} });
}

// 删除事件 - 将数据保留在了请求体当中而不是url中，不是很规范，但是先实现再说吧。
export async function deleteEvent(request) {
    const { taskId } = await request.json();
    const passKey = getCookie(request, 'passKey');
    const userid = await getUserIdFromPassKey(passKey);
    if (!userid) {
        return new Response('Invalid passKey', { status: 401 });
    }
    const deleteResult = await CALENDAR_DB.prepare(`
        SELECT userid FROM Calendar_Tasks
        WHERE taskId = ? AND userid = ?
    `).bind(taskId, userid).first();
    if (deleteResult.changes === 0) {
        return new Response('Access Denied!', { status: 404 });
    } else {
        return new Response(`Task ${taskId} deleted successfully.`, { status: 200 });
    }
}
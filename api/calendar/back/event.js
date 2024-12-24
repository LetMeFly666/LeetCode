/*
 * @Author: LetMeFly
 * @Date: 2024-12-17 23:11:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-24 09:49:52
 */
import { getUserIdFromPassKey } from "./utils/user";
import { getCookie } from "./utils/cookie";

// 创建事件
export async function createEvent(request, env) {
    const CALENDAR_DB = env.CALENDAR_DB;
    // 获取参数、信息
    const { title, description, startTime, during, tags } = await request.json();
    const passKey = getCookie(request, 'passKey');
    const userid = await getUserIdFromPassKey(passKey, CALENDAR_DB);
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
        const taskId = taskResult.meta.last_row_id;  // 这里GPT说的不对，最后从devtools里找到了
        if (tags && tags.length > 0) {
            const insertTaskTagQuery = `
                INSERT INTO Calendar_TaskTag (taskID, tagId)
                VALUES ${tags.map(() => '(?, ?)').join(', ')};
            `;
            const tagValues = tags.flatMap(tagId => [taskId, tagId]);
            await CALENDAR_DB.prepare(insertTaskTagQuery).bind(...tagValues).run();
        }
        return new Response(JSON.stringify({ success: "ok", taskId }), { status: 200 });
    } catch (error) {
        return new Response('Failed to create task', { status: 500 });
    }
}

// 获取事件 - TODO: 依据日期筛选，要不然会越来越多。
export async function getEvents(request, env) {
    const CALENDAR_DB = env.CALENDAR_DB;
    const passKey = getCookie(request, 'passkey');
    const userid = await getUserIdFromPassKey(passKey, CALENDAR_DB);  // fix: WHAT? 之前咋拼成那玩意儿了
    if (!userid) {
        return new Response('Invalid passKey', { status: 401 })
    }
    const tasks = await CALENDAR_DB.prepare(`
        SELECT * FROM Calendar_Tasks WHERE userid = ?
    `).bind(userid).all();
    return new Response(JSON.stringify(tasks.results), { headers: {'Content-Type': 'application/json'} });
}

// 删除事件 - 将数据保留在了请求体当中而不是url中，不是很规范，但是先实现再说吧。
export async function deleteEvent(request, env) {
    const CALENDAR_DB = env.CALENDAR_DB;
    const { taskId } = await request.json();
    const passKey = getCookie(request, 'passKey');
    const userid = await getUserIdFromPassKey(passKey, CALENDAR_DB);
    if (!userid) {
        return new Response('Invalid passKey', { status: 401 });
    }
    const deleteResult = await CALENDAR_DB.prepare(`
        DELETE FROM Calendar_Tasks
        WHERE taskId = ? AND userid = ?
    `).bind(taskId, userid).run();
    if (deleteResult.meta.changes === 0) {
        return new Response('Access Denied!', { status: 404 });
    } else {
        return new Response(`Task ${taskId} deleted successfully.`, { status: 200 });
    }
}
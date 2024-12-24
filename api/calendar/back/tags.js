/*
 * @Author: LetMeFly
 * @Date: 2024-12-23 18:19:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-24 10:27:27
 */
import { getCookie } from "./utils/cookie";
import { getUserIdFromPassKey } from "./utils/user";

// 创建标签
export async function createTag(request, env) {
    const CALENDAR_DB = env.CALENDAR_DB;
    const { tagName, tagColor } = await request.json();
    const passKey = getCookie(request, 'passKey');
    const userid = await getUserIdFromPassKey(passKey, CALENDAR_DB);
    if (!userid) {
        return new Response(JSON.stringify({status: 1, message: "Invalid passKey."}), {status: 401});
    }
    const insertTagQuery = `
        INSERT INTO Calendar_Tags (tagName, tagColor, creator)
        VALUES (?, ?, ?)
    `;
    try {
        const insertResult = await CALENDAR_DB.prepare(insertTagQuery).bind(tagName, tagColor, userid).run();
        const tagId = insertResult.meta.last_row_id;
        return new Response(JSON.stringify({status: 0, tagId}), {status: 200});
    } catch (error) {
        console.log(error);
        return new Response(JSON.stringify({status: 2, message: "Tag create faild."}), {status: 500});
    }
}

// 获取标签
export async function getTags(request, env) {
    const CALENDAR_DB = env.CALENDAR_DB;
    const passKey = getCookie(request, 'passKey');
    const userid = await getUserIdFromPassKey(passKey, CALENDAR_DB)
    if (!userid) {
        return new Response(JSON.stringify({status: 1, message: "Invalid passKey."}), {status: 401});
    }
    const tags = await CALENDAR_DB.prepare(`
        SELECT * FROM Calendar_Tags WHERE creator = ?
    `).bind(userid).all();
    return new Response(JSON.stringify(tags.results), {headers: {'Content-Type': 'application/json'}});
}

// 删除标签
export async function deleteTag(request, env) {
    const CALENDAR_DB = env.CALENDAR_DB;
    const passKey = getCookie(request, 'passKey');
    const userid = await getUserIdFromPassKey(passKey, CALENDAR_DB);
    if (!userid) {
        return new Response(JSON.stringify({status: 1, message: "Invalid passKey."}), {status: 401});
    }
    const { tagId } = await request.json();
    const deleteResult = await CALENDAR_DB.prepare(`
        DELETE FROM Calendar_Tags
        WHERE tagId = ? AND creator = ?
    `).bind(tagId, userid).run();
    if (deleteResult.meta.changes === 0) {
        return new Response(JSON.stringify({status: 2, message: "Access Denied!"}), {status: 404});
    } else {
        return new Response(JSON.stringify({status: 0, message: `Tag ${tagId} deleted successfully.`}), {status: 200})
    }
}

// 修改标签
export async function alterTag(request, env) {
    const CALENDAR_DB = env.CALENDAR_DB;
    const passKey = getCookie(request, 'passKey');
    const userid = await getUserIdFromPassKey(passKey, CALENDAR_DB);
    if (!userid) {
        return new Response(JSON.stringify({status: 1, message: "Invalid passKey."}), {status: 401});
    }
    const { tagId, tagName, tagColor } = await request.json();
    const alterResult = await CALENDAR_DB.prepare(`
        UPDATE Calendar_Tags
        SET tagName = ?, tagColor = ?
        WHERE tagId = ? AND creator = ?
    `).bind(tagName, tagColor, tagId, userid).run();
    if (alterResult.meta.changes === 0) {
        return new Response(JSON.stringify({status: 2, message: "Access Denied!"}), {status: 500});
    } else {
        return new Response(JSON.stringify({status: 0, message: `Tag ${tagId} altered successfully.`}), {status: 200})
    }    
}
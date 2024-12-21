/*
 * @Author: LetMeFly
 * @Date: 2024-12-18 09:58:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-20 22:35:16
 */
// console.log(CALENDAR_DB);
// 依据passKey获取userid
export async function getUserIdFromPassKey(passKey) {
    const query = `
        SELECT u.userid
        FROM USER_LoginInfo li
        JOIN Users u ON li.userid = u.userid
        WHERE li.passKey = ?
        ORDER BY li.loginTime DESC
        LIMIT 1;
    `;

    try {
        const result = await CALENDAR_DB.prepare(query).bind(passKey).first();
        return result ? result.userid : null;
    } catch (error) {
        console.error('Error fetching user ID:', error);
        return null;
    }
}
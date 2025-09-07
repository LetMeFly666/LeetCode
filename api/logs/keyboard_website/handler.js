/*
 * @Author: LetMeFly
 * @Date: 2025-01-07 00:00:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-07 00:00:00
 */

// 记录网站按键数据
export async function recordKeyboard(request, env) {
    // 设置CORS头，支持跨域调用
    const corsHeaders = {
        'Access-Control-Allow-Origin': '*',
        'Access-Control-Allow-Methods': 'POST, OPTIONS',
        'Access-Control-Allow-Headers': 'Content-Type',
        'Content-Type': 'application/json'
    };

    // 处理预检请求
    if (request.method === 'OPTIONS') {
        return new Response(null, { 
            status: 200,
            headers: corsHeaders
        });
    }

    // 只允许POST请求
    if (request.method !== 'POST') {
        return new Response(JSON.stringify({ 
            success: false, 
            error: 'Only POST method is allowed' 
        }), {
            status: 405,
            headers: corsHeaders
        });
    }

    try {
        const CALENDAR_DB = env.CALENDAR_DB;
        
        // 获取请求参数
        const { url, keyboardData } = await request.json();
        
        // 验证必需参数
        if (!url || !keyboardData) {
            return new Response(JSON.stringify({
                success: false,
                error: 'Missing required parameters: url and keyboardData'
            }), {
                status: 400,
                headers: corsHeaders
            });
        }

        // 自动记录时间和IP
        const recordTime = new Date().toISOString();
        const clientIP = request.headers.get('CF-Connecting-IP') || 
                        request.headers.get('X-Forwarded-For') || 
                        request.headers.get('X-Real-IP') || 
                        'unknown';

        // 插入数据到数据库
        const insertQuery = `
            INSERT INTO Logs_Keyboard_Website (url, record_time, client_ip, keyboard_data)
            VALUES (?, ?, ?, ?);
        `;
        
        const values = [url, recordTime, clientIP, keyboardData];
        const result = await CALENDAR_DB.prepare(insertQuery).bind(...values).run();
        
        return new Response(JSON.stringify({
            success: true,
            message: 'Keyboard data recorded successfully',
            recordId: result.meta.last_row_id,
            recordTime: recordTime
        }), {
            status: 200,
            headers: corsHeaders
        });

    } catch (error) {
        console.error('Error recording keyboard data:', error);
        return new Response(JSON.stringify({
            success: false,
            error: 'Internal server error'
        }), {
            status: 500,
            headers: corsHeaders
        });
    }
}
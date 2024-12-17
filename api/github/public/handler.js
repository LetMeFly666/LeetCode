/*
 * @Author: LetMeFly
 * @Date: 2024-12-10 19:09:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-15 16:40:35
 */
import { calculateTextWidth } from './utils/calculateWidth'

// 判断一个Github仓库是否公开
export async function ifPublic(request) {
    /* 写一个workers函数，判断一个github仓库是否公开（若不公开则Github会返回404） */
    const {user, repo} = Object.fromEntries(new URL(request.url).searchParams.entries());
    const repoUrl = `https://github.com/${user}/${repo}`
    const response = await fetch(repoUrl);
    const statusCode = response.status;
    const text = statusCode == 200 ? 'Public' : 'Private'

    const svgContent = `
        <svg xmlns="http://www.w3.org/2000/svg" height="16" width="${calculateTextWidth(text)}">
            <text x="0" y="16" font-size="16">${text}</text>
        </svg>
    `;
    return new Response(svgContent, {
        headers: { 'Content-Type': 'image/svg+xml' }
    });
}
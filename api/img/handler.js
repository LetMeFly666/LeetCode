/*
 * @Author: LetMeFly
 * @Date: 2024-12-09 15:18:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-10 23:07:17
 */
// img/handler.js

export function showSvgHelloWorld() {
    const svgContent = `
      <svg xmlns="http://www.w3.org/2000/svg" width="200" height="200">
        <text x="50%" y="50%" font-size="20" text-anchor="middle" fill="black">Hello World</text>
      </svg>
    `;
    return new Response(svgContent, {
        headers: { 'Content-Type': 'image/svg+xml' }
    });
}

export function showSvgNiHao() {
    const svgContent = `
      <svg xmlns="http://www.w3.org/2000/svg" width="200" height="200">
        <text x="50%" y="50%" font-size="20" text-anchor="middle" fill="black">Ni Hao</text>
      </svg>
    `;
    return new Response(svgContent, {
        headers: { 'Content-Type': 'image/svg+xml' }
    });
}

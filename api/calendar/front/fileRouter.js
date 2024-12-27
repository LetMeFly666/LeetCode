/*
 * @Author: LetMeFly
 * @Date: 2024-12-15 16:56:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-26 22:49:37
 */
import { indexHTML, stylesCSS, scriptsJS } from './files'

export async function indexHTMLFunc(request) {
    const url = new URL(request.url);
    if (!url.pathname.endsWith('/')) {
        url.pathname += '/';
        return Response.redirect(url, 302);
    }
    return new Response(indexHTML, {
        headers: { "Content-Type": "text/html" },
    });
}

const fileRoutePath = {
    'styles.css': stylesCSS,
    'scripts.js': scriptsJS,
}

const fileTypeDict = {  // html -> { "Content-Type": "text/html" }
    'html': { "Content-Type": "text/html" },
    'css': { "Content-Type": "text/css" },
    'js': { "Content-Type": "application/javascrip" }
}

export async function files(request) {
    const url = new URL(request.url);
    const filePath = url.pathname.replace(request.modulePath, '').replace(request.modulePath_sub, '').substring(1);
    // console.log(filePath);  // 例如style.css
    if (!(filePath in fileRoutePath)) {
        return new Response('', {status: 404});
    }
    const fileType = filePath.split('.').pop();
    console.log(fileType);
    return new Response(fileRoutePath[filePath], { headers: fileTypeDict[fileType] || {} });
}
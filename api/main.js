/*
 * @Author: LetMeFly
 * @Date: 2024-12-09 14:18:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-10 23:15:48
 */
// main.js

import { imgRoutes } from './img/url.js';  // 导入 img 模块的路由
import {github_public} from './github/public/url.js'

// 路由表
const routes = {
    '/img': imgRoutes,  // 将 /img 路由映射到 img 模块
    '/github/public': github_public,
};

// 请求事件监听
addEventListener('fetch', event => {
    const url = new URL(event.request.url);
    const path = url.pathname;  // 获取请求路径


    // 查找是否有匹配的模块
    const modulePath = Object.keys(routes).find(route => path.startsWith(route));

    if (modulePath) {
        // 获取模块的路由表
        const moduleRoutes = routes[modulePath];
        const nowPath = '/' + (path.replace(modulePath, '').split('/')[1] || '');
        const routeHandler = moduleRoutes[nowPath];  // 查找对应的处理函数
        if (routeHandler) {
            event.respondWith(routeHandler(event.request));  // 如果找到了匹配的处理函数，执行它
        } else {
            event.respondWith(new Response('Not Found', { status: 404 }));  // 找不到对应路由
        }
    } else {
        event.respondWith(new Response('Not Found', { status: 404 }));  // 找不到模块
    }
});

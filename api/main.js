/*
 * @Author: LetMeFly
 * @Date: 2024-12-09 14:18:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-17 23:15:19
 */
// main.js

import { imgRoutes } from './img/url.js';  // 导入 img 模块的路由
import { github_public } from './github/public/url.js'
import { calendarRoutes } from './calendar/url.js'

// 路由表
const routes = {
    '/img': imgRoutes,  // 将 /img 路由映射到 img 模块
    '/github/public': github_public,  // Github一个仓库是否为public
    '/calendar': calendarRoutes,  // 日历
    
};

// 请求事件监听
export default {
    async fetch(request) {
    const url = new URL(request.url);
    const path = url.pathname;  // 获取请求路径


    // 查找是否有匹配的模块
    const modulePath = Object.keys(routes).find(route => path.startsWith(route));

    if (modulePath) {
        // 获取模块的路由表
        const moduleRoutes = routes[modulePath];
        const nowPath = '/' + (path.replace(modulePath, '').split('/')[1] || '');
        console.log(nowPath); 
        const routeHandler = moduleRoutes[nowPath];  // 查找对应的处理函数
        if (routeHandler) {
            return routeHandler(request);  // 如果找到了匹配的处理函数，执行它
        } else {
            return new Response('Route Not Found', { status: 404 });  // 找不到对应路由
        }
    } else {
        return new Response('Module Not Found', { status: 404 });  // 找不到模块
    }
}}

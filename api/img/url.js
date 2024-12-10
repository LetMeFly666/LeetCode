/*
 * @Author: LetMeFly
 * @Date: 2024-12-09 15:12:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-10 19:12:24
 */
// img/url.js

import { showSvgHelloWorld, showSvgNiHao } from './handler.js';

// 定义 img 模块的路由映射
export const imgRoutes = {
    '/a.png': showSvgHelloWorld,
    '/svg': showSvgNiHao,
};

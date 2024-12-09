// img/url.js

import { showSvgHelloWorld, showSvgNiHao } from './handler.js';

// 定义 img 模块的路由映射
export const imgRoutes = {
    '/a.png': showSvgHelloWorld,
    '/svg': showSvgNiHao,
};

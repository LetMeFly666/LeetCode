/*
 * @Author: LetMeFly
 * @Date: 2024-12-15 16:34:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-25 23:10:53
 */
import { index, events, tags, front } from './handler.js';

export const calendarRoutes = {
    '/': index,
    '/front': front,
    '/events': events,
    '/tags': tags,
};
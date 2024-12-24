/*
 * @Author: LetMeFly
 * @Date: 2024-12-15 16:34:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-23 23:09:00
 */
import { index, events, tags } from './handler.js';

export const calendarRoutes = {
    '/': index,
    '/events': events,
    '/tags': tags,
};
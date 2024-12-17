/*
 * @Author: LetMeFly
 * @Date: 2024-12-15 16:34:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-15 17:28:44
 */
import { index, events } from './handler.js';

export const calendarRoutes = {
    '/': index,
    'events': events,
};
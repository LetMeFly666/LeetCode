/*
 * @Author: LetMeFly
 * @Date: 2025-01-03 21:58:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-03 22:36:03
 */
// script.js
document.addEventListener('DOMContentLoaded', function () {
    /* 初始化日期 */
    const tableBody = document.querySelector('#calendarTable tbody');
    const dateRow = document.querySelector('#dateRow');
    const weekRange = document.querySelector('#weekRange');
    const prevWeekButton = document.querySelector('#prevWeek');
    const nextWeekButton = document.querySelector('#nextWeek');

    let currentDate = new Date(); // 当前日期

    // 生成时间行
    const hours = 24; // 24小时制
    for (let i = 0; i < hours; i++) {
        const row = document.createElement('tr');
        row.innerHTML = '<td>' + i + ':00</td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>';
        tableBody.appendChild(row);
    }

    // 更新日期行和周范围显示
    function updateDates() {
        const startOfWeek = getStartOfWeek(currentDate);
        const oneDay_ths = dateRow.querySelectorAll('th');

        for (let i = 0; i < 7; i++) {
            const date = new Date(startOfWeek);
            date.setDate(startOfWeek.getDate() + i);
            oneDay_ths[i + 1].querySelector('span').innerHTML = date.toLocaleDateString('zh-CN', { month: 'numeric', day: 'numeric' });
        }

        // 更新周范围显示
        const endOfWeek = new Date(startOfWeek);
        endOfWeek.setDate(startOfWeek.getDate() + 6);
        weekRange.textContent = startOfWeek.toLocaleDateString('zh-CN') + '-' + endOfWeek.toLocaleDateString('zh-CN');

        // 如果显示周是当前周，则高亮今天
        if (currentDate.toDateString() == getStartOfWeek(new Date()).toDateString()) {
            console.log('this week');
            const day = (new Date()).getDay();
            const index = day ? day : 7;  // 周日的下标是7
            oneDay_ths[index].classList.add('today');
        } else {
            oneDay_ths.forEach(th => th.classList.remove('today'));
        }
    }

    /**
     * 获取当前周的周一
     * @param {Date} date
     * @returns {Date}
     */
    function getStartOfWeek(date) {
        const day = date.getDay();
        const diff = date.getDate() - day + (day === 0 ? -6 : 1);  // 如果当前是周日，则减去6天
        return new Date(date.setDate(diff));
    }

    // 切换到上一周
    prevWeekButton.addEventListener('click', () => {
        currentDate.setDate(currentDate.getDate() - 7);
        updateDates();
    });

    // 切换到下一周
    nextWeekButton.addEventListener('click', () => {
        currentDate.setDate(currentDate.getDate() + 7);
        updateDates();
    });

    // 初始化日期
    updateDates();

    /* 定义拖拽高亮 */
    // 高亮单元格逻辑（保持不变）
    let isDragging = false;
    let startCell = null;
    let endCell = null;

    tableBody.addEventListener('mousedown', function (e) {
        if (e.target.tagName === 'TD' && e.target.cellIndex !== 0) {
            isDragging = true;
            startCell = e.target;
            highlightCells(startCell, startCell);
        }
    });

    tableBody.addEventListener('mouseover', function (e) {
        if (isDragging && e.target.tagName === 'TD' && e.target.cellIndex !== 0) {
            endCell = e.target;
            highlightCells(startCell, endCell);
        }
    });

    tableBody.addEventListener('mouseup', function () {
        isDragging = false;
        startCell = null;
        endCell = null;
    });

    function highlightCells(start, end) {
        const startRow = start.parentElement.rowIndex;
        const startCol = start.cellIndex;
        const endRow = end.parentElement.rowIndex;

        const minRow = Math.min(startRow, endRow);
        const maxRow = Math.max(startRow, endRow);
        const Col = startCol;

        // 清除之前的高亮
        const allCells = tableBody.querySelectorAll('td');
        allCells.forEach(cell => cell.classList.remove('time-slot'));

        // 高亮选中的区域
        for (let i = minRow - 1; i <= maxRow - 1; i++) {  // 表头还有一行
            const cell = tableBody.rows[i].cells[Col];
            cell.classList.add('time-slot');
        }
    }
});
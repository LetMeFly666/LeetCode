/*
 * @Author: LetMeFly
 * @Date: 2025-01-02 21:59:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-02 22:51:31
 */
// script.js
document.addEventListener('DOMContentLoaded', function() {
    const tableBody = document.querySelector('#calendarTable tbody');
    const hours = 24; // 24小时制

    // 生成时间行
    for (let i = 0; i < hours; i++) {
        const row = document.createElement('tr');
        row.innerHTML = `<td>${i}:00</td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>`;
        tableBody.appendChild(row);
    }

    let isDragging = false;
    let startCell = null;
    let endCell = null;

    // 添加事件监听器
    tableBody.addEventListener('mousedown', function(e) {
        if (e.target.tagName === 'TD' && e.target.cellIndex !== 0) {
            isDragging = true;
            startCell = e.target;
            startCell.classList.add('time-slot');
        }
    });

    tableBody.addEventListener('mouseover', function(e) {
        if (isDragging && e.target.tagName === 'TD' && e.target.cellIndex !== 0) {
            endCell = e.target;
            highlightCells(startCell, endCell);
        }
    });

    tableBody.addEventListener('mouseup', function() {
        isDragging = false;
        startCell = null;
        endCell = null;
    });

    // 高亮单元格
    function highlightCells(start, end) {
        const startRow = start.parentElement.rowIndex;
        const startCol = start.cellIndex;
        const endRow = end.parentElement.rowIndex;
        const endCol = end.cellIndex;
        console.log(start);
        console.log(end);
        console.log(`(${startRow}, ${startCol}) -> (${endRow}, ${endCol})`);

        const minRow = Math.min(startRow, endRow);
        const maxRow = Math.max(startRow, endRow);
        const minCol = Math.min(startCol, endCol);
        const maxCol = Math.max(startCol, endCol);

        // 清除之前的高亮
        const allCells = tableBody.querySelectorAll('td');
        allCells.forEach(cell => cell.classList.remove('time-slot'));

        // 高亮选中的区域
        for (let i = minRow - 1; i <= maxRow - 1; i++) {  // 表头还有一行
            for (let j = minCol; j <= maxCol; j++) {
                const cell = tableBody.rows[i].cells[j];
                cell.classList.add('time-slot');
            }
        }
    }
});
/*
 * @Author: LetMeFly
 * @Date: 2024-12-25 23:31:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-02 23:02:32
 */
/* 以下为前端各个页面的源码 */
// index.html
export const indexHTML = `
<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Let Calendar</title>
    <link rel="stylesheet" href="./front/style.css">
    <script src="https://letmefly.xyz/Links/Common.js" async></script>
</head>
<body>
    <div class="calendar">
        <table id="calendarTable">
            <thead>
                <tr>
                    <th>Time</th>
                    <th>Mon</th>
                    <th>Tue</th>
                    <th>Wed</th>
                    <th>Thu</th>
                    <th>Fri</th>
                    <th>Sat</th>
                    <th>Sun</th>
                </tr>
            </thead>
            <tbody>
                <!-- Rows will be generated by JavaScript -->
            </tbody>
        </table>
    </div>
    <script src="./front/script.js"></script>
</body>
</html>
`;

export const stylesCSS = `
/* styles.css */
body {
    font-family: Arial, sans-serif;
}

.calendar {
    width: 100%;
    max-width: 1200px;
    margin: 0 auto;
}

table {
    width: 100%;
    border-collapse: collapse;
    user-select: none;
    table-layout: fixed;
}

th, td {
    border: 1px solid #ddd;
    padding: 8px;
    text-align: center;
}

th {
    background-color: #f4f4f4;
}

td {
    height: 50px;
    position: relative;
}

.time-slot {
    /*position: absolute;
    width: 100%;*/
    background-color: rgba(0, 123, 255, 0.3);
    cursor: pointer;
    z-index: 1;
}
`;

export const scriptsJS = `
// script.js
document.addEventListener('DOMContentLoaded', function() {
    const tableBody = document.querySelector('#calendarTable tbody');
    const hours = 24; // 24小时制

    // 生成时间行
    for (let i = 0; i < hours; i++) {
        const row = document.createElement('tr');
        row.innerHTML = \`<td>\${i}:00</td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>\`;
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
            highlightCells(startCell, startCell);
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
`;
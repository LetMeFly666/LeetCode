/*
 * @Author: LetMeFly
 * @Date: 2024-12-25 23:31:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-25 23:43:30
 */
/* 以下为前端各个页面的源码 */
// index.html
export const indexHTML = `
<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>日历</title>
    <link rel="stylesheet" href="front/styles.css"> <!-- 外部样式 -->
    <script src="https://letmefly.xyz/Links/Common.js"></script>
</head>
<body>
    <!-- 日历容器 -->
    <div class="calendar-container">
        
        <!-- 日历头部，包含上一周和下一周按钮，以及当前显示的日期范围 -->
        <div class="calendar-header">
            <button id="prevWeekBtn">上一周</button>
            <h2 id="weekLabel">2024年12月15日 - 2024年12月21日</h2> <!-- 当前日期范围会动态更新 -->
            <button id="nextWeekBtn">下一周</button>
        </div>

        <!-- 日历主体区域：显示每一天和每小时 -->
        <div class="calendar-grid" id="calendarGrid">
            <!-- 日历天数列（动态生成） -->
        </div>
    </div>

    <!-- 事件模态框（创建或修改事件） -->
    <div class="event-modal" id="eventModal" style="display:none;">
        <div class="modal-content">
            <h3 id="eventModalTitle">创建事件</h3>
            <form id="eventForm">
                <label for="eventTitle">事件标题:</label>
                <input type="text" id="eventTitle" name="title" placeholder="请输入事件标题" required>

                <label for="eventDescription">事件描述:</label>
                <textarea id="eventDescription" name="description" placeholder="请输入事件描述"></textarea>

                <label for="eventStartTime">开始时间:</label>
                <input type="datetime-local" id="eventStartTime" name="startTime" required>

                <label for="eventDuration">持续时长 (分钟):</label>
                <input type="number" id="eventDuration" name="duration" placeholder="持续时长" required>

                <label for="eventTags">标签:</label>
                <select id="eventTags" name="tags" multiple>
                    <!-- 动态加载标签选项 -->
                </select>

                <button type="submit" id="saveEventBtn">保存</button>
                <button type="button" id="closeModalBtn">关闭</button>
            </form>
        </div>
    </div>

    <script src="front/scripts.js"></script> <!-- 外部JS -->
</body>
</html>
`;

export const stylesCSS = `
/* 日历容器样式 */
.calendar-container {
    max-width: 1200px;
    margin: 20px auto;
    background-color: #fff;
    padding: 20px;
    border-radius: 10px;
    box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
}

/* 日历头部 */
.calendar-header {
    display: flex;
    justify-content: space-between;
    align-items: center;
    margin-bottom: 20px;
}

.calendar-header h2 {
    margin: 0;
    font-size: 1.5rem;
    color: #333;
}

.calendar-header button {
    padding: 10px;
    font-size: 1rem;
    cursor: pointer;
    background-color: #4CAF50;
    color: #fff;
    border: none;
    border-radius: 5px;
    transition: background-color 0.3s ease;
}

.calendar-header button:hover {
    background-color: #45a049;
}

/* 日历主体区域 */
.calendar-grid {
    display: flex;
    justify-content: space-between;
    overflow-x: auto;
}

/* 每一天的列 */
.day-column {
    width: calc(100% / 7);
    border-left: 1px solid #ddd;
    overflow-y: auto;
}

/* 日期标签 */
.date-label {
    text-align: center;
    font-weight: bold;
    margin: 10px 0;
}

/* 每个小时的时间条目 */
.hour-row {
    text-align: center;
    padding: 10px;
    border-bottom: 1px solid #ddd;
    cursor: pointer;
}

.hour-row:hover {
    background-color: #f1f1f1;
}
`;
export const scriptsJS = `
// 当前日期（返回YYYY-MM-DD格式）
function getCurrentDate() {
    const now = new Date();
    const year = now.getFullYear();
    const month = (now.getMonth() + 1).toString().padStart(2, '0');
    const day = now.getDate().toString().padStart(2, '0');
    return \`\${year}-\${month}-\${day}\`;
}

// 获取当前周的开始日期和结束日期
function getWeekRange(date) {
    const currentDate = new Date(date);
    const currentDay = currentDate.getDay() || 7;  // 星期天返回7，其他返回1-6
    currentDate.setDate(currentDate.getDate() - currentDay + 1); // 设置为本周的星期一
    const weekStart = currentDate.toISOString().split('T')[0];

    currentDate.setDate(currentDate.getDate() + 6);  // 设置为本周的星期日
    const weekEnd = currentDate.toISOString().split('T')[0];

    return { weekStart, weekEnd };
}

// 显示当前日期范围（默认显示当前一周）
function displayCalendar(date = getCurrentDate()) {
    const { weekStart, weekEnd } = getWeekRange(date);
    
    // 更新头部显示当前周
    document.getElementById('weekLabel').textContent = \`\${weekStart} - \${weekEnd}\`;

    // 更新日历内容
    const calendarGrid = document.getElementById('calendarGrid');
    calendarGrid.innerHTML = ''; // 清空日历内容

    const daysOfWeek = ['周一', '周二', '周三', '周四', '周五', '周六', '周日'];
    const currentDate = new Date(weekStart);
    
    // 创建日期列
    for (let i = 0; i < 7; i++) {
        const dayColumn = document.createElement('div');
        dayColumn.classList.add('day-column');
        const dateLabel = document.createElement('div');
        dateLabel.classList.add('date-label');
        dateLabel.textContent = \`\${daysOfWeek[i]} (\${currentDate.getDate()})\`;
        dayColumn.appendChild(dateLabel);
        
        // 添加小时条目
        for (let j = 7; j <= 24; j++) {  // 默认从7点开始到24点
            const hourRow = document.createElement('div');
            hourRow.classList.add('hour-row');
            hourRow.textContent = \`\${j}:00\`;
            dayColumn.appendChild(hourRow);
        }
        calendarGrid.appendChild(dayColumn);

        // 更新时间为下一个日期
        currentDate.setDate(currentDate.getDate() + 1);
    }
}

// 切换上一周
function showPrevWeek() {
    const currentDate = getCurrentDate();
    const { weekStart } = getWeekRange(currentDate);
    const previousWeekStart = new Date(weekStart);
    previousWeekStart.setDate(previousWeekStart.getDate() - 7);
    displayCalendar(previousWeekStart.toISOString().split('T')[0]);
}

// 切换下一周
function showNextWeek() {
    const currentDate = getCurrentDate();
    const { weekStart } = getWeekRange(currentDate);
    const nextWeekStart = new Date(weekStart);
    nextWeekStart.setDate(nextWeekStart.getDate() + 7);
    displayCalendar(nextWeekStart.toISOString().split('T')[0]);
}

// 初始加载日历
document.addEventListener('DOMContentLoaded', () => {
    displayCalendar();
    
    // 设置按钮点击事件
    document.getElementById('prevWeekBtn').addEventListener('click', showPrevWeek);
    document.getElementById('nextWeekBtn').addEventListener('click', showNextWeek);
});
`;
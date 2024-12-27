/*
 * @Author: LetMeFly
 * @Date: 2024-12-25 23:31:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-26 23:10:25
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
    <link rel="stylesheet" href="./front/styles.css"> <!-- 外部样式 -->
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
            <div class="calendar-time">
                <!-- 这里显示时间段 -->
                <div class="time-slot">00:00</div>
                <div class="time-slot">01:00</div>
                <div class="time-slot">02:00</div>
                <div class="time-slot">03:00</div>
                <div class="time-slot">04:00</div>
                <div class="time-slot">05:00</div>
                <div class="time-slot">06:00</div>
                <div class="time-slot">07:00</div>
                <div class="time-slot">08:00</div>
                <div class="time-slot">09:00</div>
                <div class="time-slot">10:00</div>
                <div class="time-slot">11:00</div>
                <div class="time-slot">12:00</div>
                <div class="time-slot">13:00</div>
                <div class="time-slot">14:00</div>
                <div class="time-slot">15:00</div>
                <div class="time-slot">16:00</div>
                <div class="time-slot">17:00</div>
                <div class="time-slot">18:00</div>
                <div class="time-slot">19:00</div>
                <div class="time-slot">20:00</div>
                <div class="time-slot">21:00</div>
                <div class="time-slot">22:00</div>
                <div class="time-slot">23:00</div>
            </div>

            <div class="calendar-days">
                <!-- 这里会动态填充每天的日期和拖拽区域 -->
                <div class="day-column" data-day="2024-12-15">
                    <div class="day-header">周一</div>
                    <!-- 每天的小时块 -->
                    <div class="time-block"></div>
                </div>
                <div class="day-column" data-day="2024-12-16">
                    <div class="day-header">周二</div>
                    <div class="time-block"></div>
                </div>
                <div class="day-column" data-day="2024-12-17">
                    <div class="day-header">周三</div>
                    <div class="time-block"></div>
                </div>
                <div class="day-column" data-day="2024-12-18">
                    <div class="day-header">周四</div>
                    <div class="time-block"></div>
                </div>
                <div class="day-column" data-day="2024-12-19">
                    <div class="day-header">周五</div>
                    <div class="time-block"></div>
                </div>
                <div class="day-column" data-day="2024-12-20">
                    <div class="day-header">周六</div>
                    <div class="time-block"></div>
                </div>
                <div class="day-column" data-day="2024-12-21">
                    <div class="day-header">周日</div>
                    <div class="time-block"></div>
                </div>
            </div>
        </div>
    </div>

    <!-- 事件模态框（创建或修改事件） -->
    <div class="event-modal" id="eventModal" style="display:none;">
        <div class="modal-content">
            <h3 id="eventModalTitle">创建事件</h3>
            <form id="eventForm">
                <label for="eventTitle">事件标题:</label>
                <input type="text" id="eventTitle" name="eventTitle">
                <label for="eventStart">开始时间:</label>
                <input type="datetime-local" id="eventStart" name="eventStart">
                <label for="eventEnd">结束时间:</label>
                <input type="datetime-local" id="eventEnd" name="eventEnd">
                <button type="submit">保存</button>
            </form>
        </div>
    </div>
</body>
</html>

`;

export const stylesCSS = `
/* 重置默认样式 */
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}

/* 全局字体样式 */
body {
    font-family: 'Arial', sans-serif;
    background-color: #f0f2f5;
    color: #333;
    height: 100%;  /* 确保页面填满整个屏幕 */
    display: flex;
    justify-content: center;
    align-items: flex-start;
    flex-direction: column;
}

/* 日历容器 */
.calendar-container {
    width: 100%;
    height: 100vh;  /* 填满整个屏幕 */
    display: flex;
    flex-direction: column;
    background-color: #fff;
    border-radius: 10px;
    box-shadow: 0 4px 12px rgba(0, 0, 0, 0.1);
    overflow: hidden;  /* 防止滚动条外泄 */
}

/* 日历头部 */
.calendar-header {
    display: flex;
    justify-content: space-between;
    align-items: center;
    padding: 15px 20px;
    background-color: #007BFF;
    color: #fff;
    font-size: 18px;
}

.calendar-header button {
    background-color: #0056b3;
    border: none;
    color: white;
    padding: 10px 15px;
    font-size: 16px;
    cursor: pointer;
    border-radius: 5px;
    transition: background-color 0.3s;
}

.calendar-header button:hover {
    background-color: #004085;
}

#weekLabel {
    font-weight: bold;
    text-align: center;
}

/* 日历主体区域 */
.calendar-grid {
    display: grid;
    grid-template-columns: 50px repeat(7, 1fr); /* 7天，每天占一个1fr单位，左侧时间栏占50px */
    grid-template-rows: repeat(24, 1fr); /* 24小时 */
    height: calc(100vh - 70px);  /* 减去头部高度 */
    overflow: auto;
}

/* 时间列 */
.calendar-time {
    display: flex;
    flex-direction: column;
    align-items: center;
    background-color: #f0f0f0;
    border-right: 1px solid #ddd;
}

.time-slot {
    padding: 10px 0;
    text-align: center;
    background-color: #f9f9f9;
    border-bottom: 1px solid #ddd;
    font-size: 14px;
    color: #555;
}

/* 每日的单元格 */
.calendar-grid > div {
    border-bottom: 1px solid #ddd;
    border-left: 1px solid #ddd;
    position: relative;
}

/* 每个日格 */
.calendar-grid .day-cell {
    position: relative;
    cursor: pointer;
    display: flex;
    flex-direction: column;
    justify-content: flex-start;
    padding: 5px;
}

/* 事件的样式 */
.event {
    background-color: #ff9800;
    border-radius: 5px;
    margin-top: 5px;
    padding: 5px;
    cursor: pointer;
    color: #fff;
    font-size: 12px;
}

/* 当拖拽创建事件时的样式 */
.event-dragging {
    opacity: 0.7;
    background-color: #ff5722;
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
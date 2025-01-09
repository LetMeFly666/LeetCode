/*
 * @Author: LetMeFly
 * @Date: 2024-12-25 23:41:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-25 23:41:29
 */
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

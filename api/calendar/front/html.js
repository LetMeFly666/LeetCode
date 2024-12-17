/*
 * @Author: LetMeFly
 * @Date: 2024-12-15 16:56:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-15 17:01:31
 */
export async function indexHTML() {
    const htmlContent = `
    <!DOCTYPE html>
    <html lang="zh">
      <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>日历应用</title>
        <script src="https://letmefly.xyz/Links/Common.js"></script>
        <style>
            body {
                font-family: Arial, sans-serif;
                padding: 20px;
                background-color: #f4f4f9;
            }
            h1 {
                color: #333;
            }
            .calendar {
                display: grid;
                grid-template-columns: repeat(7, 1fr);
                gap: 10px;
            }
            .day {
                padding: 20px;
                background-color: #fff;
                border: 1px solid #ddd;
                text-align: center;
                border-radius: 5px;
            }
            .day:hover {
                background-color: #f0f0f0;
                cursor: pointer;
            }
        </style>
      </head>
      <body>
        <h1>欢迎来到您的日历</h1>
        <div class="calendar">
          <div class="day">周一</div>
          <div class="day">周二</div>
          <div class="day">周三</div>
          <div class="day">周四</div>
          <div class="day">周五</div>
          <div class="day">周六</div>
          <div class="day">周日</div>
        </div>
        <script>
            // 这里你可以添加一些JavaScript代码来处理日历交互
            console.log("日历页面已加载");
        </script>
      </body>
    </html>
    `;

    return new Response(htmlContent, {
        headers: { "Content-Type": "text/html" },
    });
}
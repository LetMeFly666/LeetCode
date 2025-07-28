//下拉菜单
document.getElementById('dropdownMenuBtn').onclick = function() {
    var content = document.getElementById('dropdownContent');
    content.style.display = (content.style.display === 'none' || content.style.display === '') ? 'block' : 'none';
};
// 点击页面其它地方关闭下拉
document.addEventListener('click', function(e) {
    if (!e.target.closest('.dropdown')) {
        document.getElementById('dropdownContent').style.display = 'none';
    }
});

let linux_ip = null;
let linux_username = null;
let linux_password = null;

document.getElementById('add-linux-ip-btn').onclick = () => {

    const ip = document.getElementById('linux-ip-input').value.trim();
    const username = document.getElementById('linux-username-input').value.trim();
    const password = document.getElementById('linux-password-input').value.trim();
    if (!ip || !username || !password) {
        alert("请保证Linu-ip-username-password输入完整");
        return;
    }
    fetch('/ssh/check', {
        method: 'POST',
        headers: {'Content-Type': 'application/json'},
        body: JSON.stringify({ip, username, password})
    })
    .then(res => res.json())
    .then(data => {
        if (data.success) {
            linux_ip = ip;
            linux_username = username;
            linux_password = password;
        } else {
            alert("ssh连接失败！请检查ip-username-password是否有误");
        }
    })
    .catch(() => {
        alert("ssh连接失败！请检查ip-username-password是否有误");
    });
};


let currentAbortController = null; // 用于存储当前请求的 AbortController
let currentTaskId = null; // 当前任务的ID
let progressInterval = null; // 进度检查的intervalID

// 显示上传的文件列表
document.getElementById("file-upload").addEventListener("change", function(e) {
    const files = e.target.files;
    const fileListElement = document.getElementById("file-list");
    fileListElement.innerHTML = "";
    
    for (let file of files) {
        const li = document.createElement("li");
        li.className = "file-item";
        li.innerHTML = `
            <div class="file-name">${file.name}</div>
            <div class="file-status" id="status-${file.name}">待上传</div>
            <div class="progress-bar">
                <div class="progress" id="progress-${file.name}" style="width: 0%"></div>
            </div>
        `;
        fileListElement.appendChild(li);
    }
});

// 开始推理按钮
document.getElementById("start-inference").addEventListener("click", function() {
    const files = document.getElementById("file-upload").files;
    if (files.length === 0) {
        alert('请先选择文件');
        return;
    }
        if (!linux_ip || !linux_username || !linux_password) {
        alert("请先输入Linux:ip-username-password");
        return;
    }
    
    // 清空结果列表
    document.getElementById("results-list").innerHTML = "";
    
    // 创建FormData对象
    const formData = new FormData();
    for (let i = 0; i < files.length; i++) {
        formData.append("files", files[i]);
        
        // 设置文件状态为上传中
        const statusElement = document.getElementById(`status-${files[i].name}`);
        if (statusElement) {
            statusElement.textContent = "上传中";
        }
    }
    formData.append("linux_ip", linux_ip);
    formData.append("linux_username", linux_username);
    formData.append("linux_password", linux_password);
    
    // 创建取消控制器
    const abortController = new AbortController();
    currentAbortController = abortController;
    
    // 发送上传请求
    fetch("/pcap/upload", {
        method: "POST",
        body: formData,
        signal: abortController.signal,
    })
    .then(response => response.json())
    .then(data => {
        if (data.success) {
            console.log("文件上传成功，任务ID:", data.task_id);
            currentTaskId = data.task_id;
            
            // 设置文件状态为分析中
            for (let i = 0; i < files.length; i++) {
                const statusElement = document.getElementById(`status-${files[i].name}`);
                if (statusElement) {
                    statusElement.textContent = "分析中";
                }
            }
            
            // 开始检查任务进度
            startMonitoringTaskProgress();
        } else {
            console.error("上传失败:", data.message);
        }
    })
    .catch(error => {
        if (error.name === "AbortError") {
            console.log("上传已被取消");
        } else {
            console.error("上传发生错误:", error);
            
            // 更新状态显示
            for (let i = 0; i < files.length; i++) {
                const statusElement = document.getElementById(`status-${files[i].name}`);
                if (statusElement) {
                    statusElement.textContent = "上传失败";
                    statusElement.style.color = "red";
                }
            }
        }
    });
});

// 开始监控任务进度
function startMonitoringTaskProgress() {
    if (!currentTaskId) return;
    // 停止之前的监控
    if (progressInterval) {
        clearInterval(progressInterval);
    }
    // 检查任务状态
    progressInterval = setInterval(() => {
        fetch(`/pcap/task_status/${currentTaskId}`)
            .then(response => response.json())
            .then(taskStatus => {
                // 更新进度显示
                if (taskStatus.status !== "not_found") {
                    const totalFiles = taskStatus.file_count || 1;
                    const completed = taskStatus.completed_files || 0;
                    const progress = totalFiles > 0 ? Math.round((completed / totalFiles) * 100) : 0;
                    
                    // 更新所有文件的进度条
                    document.querySelectorAll(".file-name").forEach(element => {
                        const fileName = element.textContent;
                        const progressBar = document.getElementById(`progress-${fileName}`);
                        if (progressBar) {
                            progressBar.style.width = `${progress}%`;
                        }
                    });
                    
                    // 处理已完成的结果
                    if (taskStatus.filesResults && taskStatus.filesResults.length > 0) {
                        const resultsList = document.getElementById("results-list");
                        
                        taskStatus.filesResults.forEach(result => {
                            // // result 是一个对象：{file: ..., result: ...}
                            // const fileName = result.file ? result.file.replace(/\\/g, "/") : "";
                            const displayText = result.file
                                // ? `${result.file}: \n ${result.result}`
                                ? `${result.result}`
                                : (typeof result === "string" ? result : JSON.stringify(result));

                            // 检查是否已经添加（避免重复）
                            if (!Array.from(resultsList.children).some(li => li.innerText === displayText)) {
                                const resultItem = document.createElement("li");
                                resultItem.innerHTML = displayText.replace(/\n/g, "<br>");
                                resultItem.className = "result-item";
                                resultsList.appendChild(resultItem);
                            }
                        });

                    }
                    
                    // 如果任务完成，停止监控
                    if (taskStatus.status === "completed") {
                        clearInterval(progressInterval);
                        currentTaskId = null;
                        
                        // 更新状态为完成
                        document.querySelectorAll(".file-status").forEach(element => {
                            element.textContent = "完成";
                            element.style.color = "green";
                        });
                    }
                }
            })
            .catch(error => {
                console.error("获取任务状态失败:", error);
            });
    }, 500); // 每0.5秒检查一次
}

// 取消上传函数
function cancelUpload() {
    // 取消上传请求
    if (currentAbortController) {
        currentAbortController.abort();
    }
    
    if (progressInterval) {
        clearInterval(progressInterval);
    }
    
    currentTaskId = null;

    document.querySelectorAll(".file-status").forEach(element => {
        element.textContent = "已取消";
        element.style.color = "orange";
    });

}

// 绑定取消上传按钮
document.getElementById("cancel-upload").addEventListener("click", function() {
    cancelUpload();
});

//左侧区域
//左侧区域
//左侧区域

// 主机IP管理
// const ipInput = document.getElementById('ip-input');
// const usernameInput = document.getElementById('username-input');
// const passwordInput = document.getElementById('password-input');
// const addIpBtn = document.getElementById('add-ip-btn');

const savedIpListUl = document.getElementById('saved-ip-list');
let savedIpMap = {};
let savedIpList = [];

//受控主机ip列表

function renderSavedIpList() {
    savedIpListUl.innerHTML = '';
    Object.keys(savedIpMap).forEach(ip => {
        const li = document.createElement('li');
        li.textContent = `${ip} - ${savedIpMap[ip]['username']}`;
        // 删除按钮
        const del = document.createElement('button');
        del.textContent = '删除';
        del.className = 'ip-delete-btn';
        del.onclick = () => {
            savedIpList = savedIpList.filter(item => item !== ip);
            delete savedIpMap[ip];
            renderSavedIpList();
        };
        li.appendChild(del);
        savedIpListUl.appendChild(li);
    });
}

document.getElementById('add-ip-btn').onclick = () => {
    const ip = document.getElementById('ip-input').value.trim();
    const username = document.getElementById('username-input').value.trim();
    const password = document.getElementById('password-input').value.trim();
    if (!ip || !username || !password) {
        alert("请保证ip-username-password输入完整");
        return;
    }
    fetch('/ssh/check', {
        method: 'POST',
        headers: {'Content-Type': 'application/json'},
        body: JSON.stringify({ip, username, password})
    })
    .then(res => res.json())
    .then(data => {
        if (data.success) {
            if (!savedIpMap[ip]) {
                savedIpMap[ip] = {
                    "ip": ip,
                    "username": username, 
                    "password": password 
                };
                if (!savedIpList.includes(ip)) savedIpList.push(ip);
                renderSavedIpList();
                document.getElementById('ip-input').value = '';
                document.getElementById('username-input').value = '';
                document.getElementById('password-input').value = '';
            }
        } else {
            alert("ssh无法连接！请检查ip-username-password是否有误");
        }
    })
    .catch(() => {
        alert("ssh无法连接！请检查ip-username-password是否有误");
    });
    // if (!savedIpMap[ip]) {
    //     savedIpMap[ip] = {
    //         "ip": ip,
    //         "username": username, 
    //         "password": password 
    //     };
    //     if (!savedIpList.includes(ip)) savedIpList.push(ip);
    //     renderSavedIpList();
    //     // 清空输入框
    //     document.getElementById('ip-input').value = '';
    //     document.getElementById('username-input').value = '';
    //     document.getElementById('password-input').value = '';
    // }
};

renderSavedIpList();



// 流量监控图表
let trafficCharts = [];  // 存储所有图表对象
let upHistories = [];    // 存储所有上行流量历史数据
let downHistories = [];  // 存储所有下行流量历史数据

let trafficInterval = null;

function initTrafficChart(chartId, upHistory, downHistory) {
    const ctx = document.getElementById(chartId).getContext('2d');
    const chart = new Chart(ctx, {
        type: 'line',
        data: {
            labels: Array(30).fill('').map((_, i) => (i).toString()), 
            datasets: [
                {
                    label: '上行流量 (MB/s)',
                    data: upHistory,
                    borderColor: '#2ecc71',
                    backgroundColor: 'rgba(46,204,113,0.15)',
                    fill: true,
                    tension: 0.33
                },
                {
                    label: '下行流量 (MB/s)',
                    data: downHistory,
                    borderColor: '#e67e22',
                    backgroundColor: 'rgba(230,126,34,0.13)',
                    fill: true,
                    tension: 0.33
                }
            ]
        },
        options: {
            responsive: true,
            scales: {
                x: {
                    display: true,
                    ticks: {
                        display: false
                    },
                    title: {
                        display: true,
                        text: '时间 (ms)',
                        color: "#fff"
                    }
                },
                y: { 
                    beginAtZero: true,
                    min: 0,
                    max: 100,
                    title: {
                        display: true,
                        text: '流量 (MB/s)',
                        color: "#fff"
                    }
                }
            },
            plugins: {
                legend: {
                    display: true,
                }
            }
        }
    });
    return chart;
}

// 初始化数据和图表
function initializeCharts() {
    for (let i = 0; i < 4; i++) {
        upHistories[i] = Array(30).fill(0);    // 每个图表的上行流量历史
        downHistories[i] = Array(30).fill(0);  // 每个图表的下行流量历史
        trafficCharts[i] = initTrafficChart(`traffic-chart${i + 1}`, upHistories[i], downHistories[i]);
    }
}
initializeCharts();

function stopTrafficUpdate() {
    if (trafficInterval) clearInterval(trafficInterval);
}

// 更新图表数据
function updateChartData(index, up, down) {
    if (upHistories[index].length >=30) {
        upHistories[index].shift();  // 删除数组的第一个元素
        downHistories[index].shift();  // 删除数组的第一个元素
    }
    upHistories[index].push(up);  // 添加新数据到数组末尾
    downHistories[index].push(down);  // 添加新数据到数组末尾
    trafficCharts[index].update();  // 更新图表
}

let isInducing = false;  // 状态标志

const pollIntervals = [];
// 开始诱导的按钮功能
document.getElementById('start-capture').addEventListener('click', function() {
    if (isInducing) {
        console.log("当前已经在诱导中，无法重复开始");
        return;
    }
    isInducing = true;
    const requests = savedIpList.map((ip, index) => {
        return fetch('/traffic/limit_start', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ 
                ip: ip, 
                username: savedIpMap[ip]['username'], 
                password: savedIpMap[ip]['password']
            })
        })
        .then(response => response.json())
        .then(data => {
            console.log(`${ip} 诱导开始：`, data);
            // 启动流式数据接收
            startTrafficStream(ip, index);  // 传递 index 来标识对应的图表
        })
        .catch(error => {
            console.error("请求失败:", error);
        });
    });

    // 等待所有请求完成
    Promise.all(requests)
        .then(() => {
            console.log("所有请求已发送完毕！");
        })
        .catch(error => {
            console.error("某些请求失败:", error);
        });  
});

// 停止诱导按钮
document.getElementById('cancel-capture').addEventListener('click', function() {
    const requests = savedIpList.map((ip, index) => {
        return fetch('/traffic/limit_end', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ 
                ip: ip, 
                username: savedIpMap[ip]['username'], 
                password: savedIpMap[ip]['password']
            })
        })
        .then(response => response.json())
        .then(data => {
            console.log(`${ip} 诱导停止：`, data);
            // 停止流量监听
            if (pollIntervals[index]) {
                clearInterval(pollIntervals[index]);
                pollIntervals[index] = null;
                isInducing = false;  // 结束诱导状态
            }
        })
        .catch(error => {
            console.error("停止请求失败:", error);
        });
    });

    // 等待所有请求完成
    Promise.all(requests)
        .then(() => {
            console.log("所有停止请求已发送完毕！");
        })
        .catch(error => {
            console.error("某些停止请求失败:", error);
        }); 

});

// 启动流式接收流量数据
function startTrafficStream(ip, index) {
    const intervalMs = 300;  // 轮询间隔
  // 如果之前已有定时器，先清掉
  if (pollIntervals[index]) clearInterval(pollIntervals[index]);

  pollIntervals[index] = setInterval(() => {
    fetch(`/traffic/get_traffic?ip=${encodeURIComponent(ip)}`)
      .then(res => res.json())
      .then(data => {
        updateChartData(savedIpList.indexOf(data.ip), data.upload, data.download);
      })
      .catch(err => console.error(`${ip} 轮询失败:`, err));
  }, intervalMs);
}
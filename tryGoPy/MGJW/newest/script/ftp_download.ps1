<#
.SYNOPSIS
    FTP 下载脚本，支持 Ctrl+C 和外部 Kill 终止时的清理逻辑。
#>

# FTP 配置
$FtpServer = "10.112.105.109"
$FtpUser = "ftpuser"
$FtpPass = "ftpuser"
$FileName = "10GB_random.bin"
$TempFile = "./$FileName"

# 全局变量
$curlProcess = $null

# 清理函数
function Cleanup {
    Write-Output "[INFO] Cleaning up..."
    if ($curlProcess -and -not $curlProcess.HasExited) {
        Stop-Process -Id $curlProcess.Id -Force -ErrorAction SilentlyContinue
        Write-Output "[INFO] Terminated curl process (PID: $($curlProcess.Id))"
    }
    if (Test-Path $TempFile) {
        Remove-Item $TempFile -Force -ErrorAction SilentlyContinue
        Write-Output "[INFO] Deleted: $TempFile"
    }
}

# 注册退出事件（被 kill 或 ctrl+c）
Register-EngineEvent PowerShell.Exiting -Action {
    Cleanup
}

try {
    Write-Output "[INFO] Starting FTP download from: ftp://$FtpServer/$FileName"

    $curlArgs = @(
        "-u", "$FtpUser`:$FtpPass",
        "ftp://$FtpServer/$FileName",
        "-o", $TempFile,
        "--fail",
        "--no-buffer"
    )

    # 使用 Start-Process 启动 curl，并获取其进程对象
    $curlProcess = Start-Process -FilePath "curl.exe" -ArgumentList $curlArgs -NoNewWindow -PassThru

    Write-Output "curl process : $curlProcess"
    
    # 记录初始流量
    $adapter = Get-NetAdapter | Where-Object { $_.Status -eq "Up" } | Select-Object -First 1
    $startStats = Get-NetAdapterStatistics -Name $adapter.Name
    
    while (-not $curlProcess.HasExited) {
        Start-Sleep -Milliseconds 500
    
        $stats = Get-NetAdapterStatistics -Name $adapter.Name
        $upload = $stats.SentBytes - $startStats.SentBytes
        $download = $stats.ReceivedBytes - $startStats.ReceivedBytes
    
        Write-Output ("upload {0} download {1}" -f $upload, $download)
    }

    if ($curlProcess.ExitCode -eq 0) {
        Write-Output "[INFO] Download completed."
    } else {
        Write-Output "[ERROR] curl exited with code $($curlProcess.ExitCode)"
    }
}
catch {
    Write-Output "[ERROR] $_"
}
finally {
    Cleanup
}

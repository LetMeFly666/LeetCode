---
title: 记录一下今日见到的.appinstaller格式的小巧文件
date: 2022-11-05 16:10:00
tags: [其他, .appinstaller, 简单, Windows]
categories: [技术思考]
---

今日下载了一个名为“Files.stable.appinstaller”的文件，只有几k，可以直接双击运行，但在Win沙盒中无法识别

内容为：

```xml
<?xml version="1.0" encoding="utf-8"?>
<AppInstaller
	Uri="https://cdn.files.community/files/stable/Files.Package.appinstaller"
	Version="2.3.0.0" xmlns="http://schemas.microsoft.com/appx/appinstaller/2018">
	<MainBundle
		Name="Files"
		Version="2.3.0.0"
		Publisher="CN=Yair Aichenbaum, O=Yair Aichenbaum, S=Washington, C=US"
		Uri="https://cdn.files.community/files/stable/Files.Package_2.3.0.0_Sideload_Test/Files.Package_2.3.0.0_x86_x64_arm64_Sideload.msixbundle" />
	<Dependencies>
		<Package
			Name="Microsoft.NET.Native.Framework.2.2"
			Publisher="CN=Microsoft Corporation, O=Microsoft Corporation, L=Redmond, S=Washington, C=US"
			ProcessorArchitecture="x86"
			Uri="https://cdn.files.community/files/stable/Files.Package_2.3.0.0_Sideload_Test/Dependencies/x86/Microsoft.NET.Native.Framework.2.2.appx"
			Version="2.2.29512.0" />
		<Package
			Name="Microsoft.NET.Native.Framework.2.2"
			Publisher="CN=Microsoft Corporation, O=Microsoft Corporation, L=Redmond, S=Washington, C=US"
			ProcessorArchitecture="x64"
			Uri="https://cdn.files.community/files/stable/Files.Package_2.3.0.0_Sideload_Test/Dependencies/x64/Microsoft.NET.Native.Framework.2.2.appx"
			Version="2.2.29512.0" />
		<Package
			Name="Microsoft.NET.Native.Framework.2.2"
			Publisher="CN=Microsoft Corporation, O=Microsoft Corporation, L=Redmond, S=Washington, C=US"
			ProcessorArchitecture="arm64"
			Uri="https://cdn.files.community/files/stable/Files.Package_2.3.0.0_Sideload_Test/Dependencies/arm64/Microsoft.NET.Native.Framework.2.2.appx"
			Version="2.2.29512.0" />
		<Package
			Name="Microsoft.NET.Native.Runtime.2.2"
			Publisher="CN=Microsoft Corporation, O=Microsoft Corporation, L=Redmond, S=Washington, C=US"
			ProcessorArchitecture="x86"
			Uri="https://cdn.files.community/files/stable/Files.Package_2.3.0.0_Sideload_Test/Dependencies/x86/Microsoft.NET.Native.Runtime.2.2.appx"
			Version="2.2.28604.0" />
		<Package
			Name="Microsoft.NET.Native.Runtime.2.2"
			Publisher="CN=Microsoft Corporation, O=Microsoft Corporation, L=Redmond, S=Washington, C=US"
			ProcessorArchitecture="x64"
			Uri="https://cdn.files.community/files/stable/Files.Package_2.3.0.0_Sideload_Test/Dependencies/x64/Microsoft.NET.Native.Runtime.2.2.appx"
			Version="2.2.28604.0" />
		<Package
			Name="Microsoft.NET.Native.Runtime.2.2"
			Publisher="CN=Microsoft Corporation, O=Microsoft Corporation, L=Redmond, S=Washington, C=US"
			ProcessorArchitecture="arm64"
			Uri="https://cdn.files.community/files/stable/Files.Package_2.3.0.0_Sideload_Test/Dependencies/arm64/Microsoft.NET.Native.Runtime.2.2.appx"
			Version="2.2.28604.0" />
		<Package
			Name="Microsoft.VCLibs.140.00.UWPDesktop"
			Publisher="CN=Microsoft Corporation, O=Microsoft Corporation, L=Redmond, S=Washington, C=US"
			ProcessorArchitecture="arm64"
			Uri="https://cdn.files.community/files/stable/Files.Package_2.3.0.0_Sideload_Test/Dependencies/arm64/Microsoft.VCLibs.ARM64.14.00.Desktop.appx"
			Version="14.0.30704.0" />
		<Package
			Name="Microsoft.VCLibs.140.00.UWPDesktop"
			Publisher="CN=Microsoft Corporation, O=Microsoft Corporation, L=Redmond, S=Washington, C=US"
			ProcessorArchitecture="x64"
			Uri="https://cdn.files.community/files/stable/Files.Package_2.3.0.0_Sideload_Test/Dependencies/x64/Microsoft.VCLibs.x64.14.00.Desktop.appx"
			Version="14.0.30704.0" />
		<Package
			Name="Microsoft.VCLibs.140.00.UWPDesktop"
			Publisher="CN=Microsoft Corporation, O=Microsoft Corporation, L=Redmond, S=Washington, C=US"
			ProcessorArchitecture="x86"
			Uri="https://cdn.files.community/files/stable/Files.Package_2.3.0.0_Sideload_Test/Dependencies/x86/Microsoft.VCLibs.x86.14.00.Desktop.appx"
			Version="14.0.30704.0" />
		<Package
			Name="Microsoft.VCLibs.140.00"
			Publisher="CN=Microsoft Corporation, O=Microsoft Corporation, L=Redmond, S=Washington, C=US"
			ProcessorArchitecture="arm64"
			Uri="https://cdn.files.community/files/stable/Files.Package_2.3.0.0_Sideload_Test/Dependencies/arm64/Microsoft.VCLibs.ARM64.14.00.appx"
			Version="14.0.30704.0" />
		<Package
			Name="Microsoft.VCLibs.140.00"
			Publisher="CN=Microsoft Corporation, O=Microsoft Corporation, L=Redmond, S=Washington, C=US"
			ProcessorArchitecture="x64"
			Uri="https://cdn.files.community/files/stable/Files.Package_2.3.0.0_Sideload_Test/Dependencies/x64/Microsoft.VCLibs.x64.14.00.appx"
			Version="14.0.30704.0" />
		<Package
			Name="Microsoft.VCLibs.140.00"
			Publisher="CN=Microsoft Corporation, O=Microsoft Corporation, L=Redmond, S=Washington, C=US"
			ProcessorArchitecture="x86"
			Uri="https://cdn.files.community/files/stable/Files.Package_2.3.0.0_Sideload_Test/Dependencies/x86/Microsoft.VCLibs.x86.14.00.appx"
			Version="14.0.30704.0" />
	</Dependencies>
	<UpdateSettings>
		<AutomaticBackgroundTask />
	</UpdateSettings>
</AppInstaller>
```
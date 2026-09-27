# PRESS START · Windows 构建

[回到草坪](../README.md) · [操作手册](PLAYBOOK.md) · [构建记录](VERIFICATION.md)

## 环境

需要 Windows、MSVC C++ 工具链和 CMake 3.20 或更新版本。Visual Studio / Build Tools 的“使用 C++ 的桌面开发”工作负载提供编译器与 Windows SDK。仓库的 CMake 目标仅接受 Windows + MSVC。

源代码中的中文字符串按原有 GBK 保留。目标显式设置 `/source-charset:.936` 和 `/execution-charset:.936`，不依赖 CI 机器的默认系统语言。参数语法见 [Microsoft 文档](https://learn.microsoft.com/en-us/cpp/build/reference/source-charset-set-source-character-set?view=msvc-170)。

## 编译

在仓库根目录的命令提示符中运行：

```bat
cmake -S . -B build -A x64
cmake --build build --config Release
```

输出为 `build\Release\pvz.exe`。CMake 同时复制已有的 `.wav` 音效和程序读取的文字资源到该目录；源仓库资源不被修改。

## 启动

```bat
cd build\Release
chcp 936
pvz.exe
```

从可执行文件所在目录启动，以便相对路径能找到 `menu.txt`、`fengmian.txt`、`Conversation content.txt` 和音效文件。代码页命令只作用于当前终端；使用能显示中文的控制台字体。若缩放或中文占宽导致错位，先检查字体与窗口尺寸。

`chcp 936` 是当前 GBK 程序的运行设置，不代表完成 UTF-8 改造或跨平台适配。

## CI 构建产物

[Windows build](https://github.com/yuanjuju/pvz-self-created/actions/workflows/build.yml) 在 Windows runner 上执行配置、Release 编译及关键资源存在性检查，并保存 `pvz-windows-x64` artifact，保留 7 天。登录 GitHub 后可从成功的运行中下载；解压后仍需从该目录运行。

CI 不进行交互试玩，也不验证扬声器播放效果。具体通过的运行与尚未覆盖的内容见[验证记录](VERIFICATION.md)。

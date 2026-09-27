# 构建与展示验证

[回到草坪](../README.md)

## Windows 构建

2026-09-27，源码提交 `1ba6f6138b19da48289cf30c74592292588f7169` 在 GitHub Windows runner 上完成：

- CMake 配置 MSVC x64；
- Release 编译与链接，生成 `pvz.exe`；
- 复制运行所需文字与音效；
- 检查可执行文件、BGM、菜单、封面、说明与对话文件；
- 上传 `pvz-windows-x64` artifact。

[通过的构建记录](https://github.com/yuanjuju/pvz-self-created/actions/runs/36294605573) · [最新构建](https://github.com/yuanjuju/pvz-self-created/actions/workflows/build.yml)

首次接入时出现 Windows SDK `byte` 与 C++17 `std::byte` 的歧义；调整 `Plant.h`、`Zombie.h` 的头文件顺序后通过。原 GBK 编码及玩法实现保留。

## 编译警告与运行范围

日志仍包含原有的整数窄化、未使用局部变量，以及 `Pole_Zombie::move` 并非所有路径返回值的警告。后者需要后续修正并结合试玩确认分支行为；编译通过不代表玩法或内存安全已全部验证。

本轮未在交互式 Windows 桌面实际试玩，也没有验证音效输出。操作说明来源于源码检查，当前已知限制见[操作手册](PLAYBOOK.md)和[技术说明](ARCHITECTURE.md)。

## 展示与资源

- 新增中英文 README、操作手册、图鉴、技术说明与构建指南。
- 原有 `.txt` 字符画 / 对话和 `.wav` 音效保持在 Git 中，不被封面替换。
- README 中的像素图是 AI 生成的封面插画，不是运行截图。
- 静态检查覆盖 Markdown 本地链接、素材存在性，以及原资源 Git blob 与改版前一致。

本地是稀疏检出，较大的旧 IDE 缓存和音效未为文档工作重复下载；Windows CI 会取回构建与运行所需文件。未删除或重写历史资源。

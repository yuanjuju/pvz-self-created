<div align="right">

**中文** · [English](README_EN.md)

</div>

<div align="center">

# PVZ 自创版

**一块字符草坪，十二张植物卡。**

`C++` · `Windows Console` · `Keyboard Only`

[开始游戏](docs/BUILD.md) · [操作手册](docs/PLAYBOOK.md) · [草坪图鉴](docs/ALMANAC.md) · [翻开代码](docs/ARCHITECTURE.md)

</div>

![植物与僵尸的复古像素封面插画](assets/pvz-field-guide.png)

<p align="center"><sub>README 封面插画 · 游戏本体为 Windows 字符控制台</sub></p>

<div align="center">

**7 × 5 草坪**　 /　 **12 种植物**　 /　 **11 种僵尸**　 /　 **无尽模式**

[![Windows build](https://github.com/yuanjuju/pvz-self-created/actions/workflows/build.yml/badge.svg)](https://github.com/yuanjuju/pvz-self-created/actions/workflows/build.yml)

</div>

## 01 / PRESS START

用键盘选卡、移动焦点、种下植物。商店管理阳光和冷却，豌豆在字符网格里移动，僵尸从右侧入场。这个 C++ 学习项目用 Win32 控制台输出、对象继承与单线程游戏循环，复现植物大战僵尸的部分塔防玩法。

当前入口包含封面、背景对话、无尽模式和角色说明。角色、音效与原有文字素材继续保留；本轮新增的像素插画只用于 README 展示。

## 02 / PLAYER ONE

| 选卡 | 落子 | 管理草坪 |
| :---: | :---: | :---: |
| <kbd>1</kbd>–<kbd>9</kbd> / <kbd>A</kbd><kbd>B</kbd><kbd>C</kbd> | <kbd>↑</kbd><kbd>↓</kbd><kbd>←</kbd><kbd>→</kbd> 移动 | <kbd>X</kbd> 进入铲除 |
| 选择植物卡 | <kbd>Enter</kbd> 确认 | <kbd>Esc</kbd> 取消 · <kbd>Space</kbd> 暂停 |

种植成功才会扣除阳光并启动冷却。完整键位、调试快捷键和当前玩法限制见[操作手册](docs/PLAYBOOK.md)。

## 03 / 草坪图鉴

<table>
<tr>
<td width="33%" valign="top">
<h3>🌻 向日葵</h3>
<p><b>50 阳光 · 键位 1</b></p>
<p>负责生产。先有收入，才有下一张卡。</p>
</td>
<td width="33%" valign="top">
<h3>🟢 豌豆射手</h3>
<p><b>100 阳光 · 键位 2</b></p>
<p>负责输出。普通豌豆沿所在行前进。</p>
</td>
<td width="33%" valign="top">
<h3>🥜 坚果墙</h3>
<p><b>50 阳光 · 键位 5</b></p>
<p>负责挡路。给后排多争取一点时间。</p>
</td>
</tr>
<tr>
<td valign="top">
<h3>❄️ 寒冰射手</h3>
<p><b>175 阳光 · 键位 6</b></p>
<p>伤害之外，再给目标一点减速。</p>
</td>
<td valign="top">
<h3>🍒 樱桃炸弹</h3>
<p><b>150 阳光 · 键位 4</b></p>
<p>处理挤在一起的麻烦。</p>
</td>
<td valign="top">
<h3>🌶️ 火爆辣椒</h3>
<p><b>125 阳光 · 键位 9</b></p>
<p>对所在整行发动攻击。</p>
</td>
</tr>
</table>

[查看全部 12 张植物卡与 11 种僵尸 →](docs/ALMANAC.md)

## 04 / 装好再开局

Windows + MSVC + CMake，在仓库根目录执行：

```bat
cmake -S . -B build -A x64
cmake --build build --config Release
cd build\Release
chcp 936
pvz.exe
```

构建时自动复制文字和音效资源。程序保留 GBK 中文字符串，`chcp 936` 仅调整当前终端。请从 `pvz.exe` 所在目录启动。[详细构建说明 →](docs/BUILD.md)

GitHub Actions 检查 Windows 编译及资源到位，提供临时构建 artifact。交互试玩和音效播放仍需在实际 Windows 控制台确认。[验证范围 →](docs/VERIFICATION.md)

## 05 / UNDER THE HOOD

```text
Game：输入状态与每轮更新
 ├─ Map / Grid：位置、放置与局部重绘
 ├─ Plant：生产、射击、爆破、阻挡
 ├─ Zombie：移动、啃咬、特殊行为
 ├─ Bullet：移动与碰撞
 └─ Store：阳光、价格与冷却
```

植物和僵尸以派生类表达行为差异，格子与队列关联实体，Win32 接口负责字符定位和颜色，WinMM 播放已有音效。[对象关系、循环顺序与状态切换 →](docs/ARCHITECTURE.md)

<details>
<summary>资源与历史说明</summary>

- `*.cpp / *.h`：游戏逻辑与控制台工具。
- `*.txt`：原有封面字符画、对话和角色说明。
- `*.wav`：原有音效。
- `assets/`：本轮 README 展示素材。
- [原始 README](docs/archive/README.original.md)：保留历史说明；旧文档中的存档、多关卡、破瓦罐和传送带不作为当前已验证玩法。
- [素材说明](docs/ARTWORK.md)：封面插画来源、生成提示词及展示边界。

</details>

本项目为学习与同人实践。植物大战僵尸相关角色和原作素材归相应权利方所有；新增插画不代表官方关联。

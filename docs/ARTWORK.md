# 封面插画与文档风格

[回到草坪](../README.md)

`assets/pvz-field-guide.png` 是本次通过内置 imagegen 工具生成的 README 封面，尺寸 2172×724。采用奶油色、草绿色和淡紫色的复古像素插画。封面不进入游戏资源加载流程；原有字符画与音效继续保留。

它是展示插画，不是游戏截图。README 中的植物卡片为文档排版，emoji 也不代表新增游戏精灵。

## 生成方式

- 模式：内置 imagegen 工具，未使用 API CLI。
- 最终文件：`assets/pvz-field-guide.png`。
- 原始生成结果非覆盖保存，项目使用副本。

## 最终提示词

```text
Use case: illustration-story. Asset type: wide cover illustration for the GitHub README of a small C++ Windows console Plants vs. Zombies fan project. Primary request: playful retro pixel-art game instruction-manual cover, visually distinctive, charming and humorous, not an actual gameplay screenshot. Compose a wide landscape 3:1 image. A smiling sunflower, a determined pea-shooter plant and a nervous walnut defend a small checkerboard lawn against two goofy green zombies, one with an orange traffic cone; a few pea projectiles and a small golden sun. Crisp carefully placed 16-bit pixels, limited warm cream / leafy green / golden yellow / muted lavender palette, soft sky and tiny clouds, thick readable silhouettes, elegant balanced magazine-cover composition, plenty of cream negative space around the scene. A thin pixel-art frame at the edges. No words, no letters, no logos, no UI panels, no watermark, no realistic violence. Original cover illustration only; do not mimic a captured game UI. Keep all characters comfortably within the frame.
```

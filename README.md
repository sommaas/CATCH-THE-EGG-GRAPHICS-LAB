# 🥚 Egg Catcher

<div align="center">

![Version](https://img.shields.io/badge/version-2.0-blue.svg)
![Language](https://img.shields.io/badge/language-C-orange.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Platform](https://img.shields.io/badge/platform-OpenGL-red.svg)

**A fast-paced catch the egg game built with OpenGL and GLUT**

---

</div>

## 🎮 About

Egg Catcher is a retro-style arcade game where you control a basket to catch falling eggs while avoiding poop! The chicken moves automatically on a bamboo perch, dropping various items that you must catch or dodge. As time progresses, the game gets faster and more challenging!

## ✨ Features

- 🌈 **Beautiful gradient backgrounds** and smooth animations
- 🐔 **Animated chicken** moving back and forth on a bamboo perch
- 🥚 **Multiple egg types** with different point values
- ⚡ **Progressive difficulty** - speed increases every 15 seconds
- 🎯 **Three control methods** - mouse, arrow keys, or A/D keys
- ⏱️ **60-second time challenge** - beat your high score!
- 🎨 **Polished UI** with glow effects and modern design

## 🎯 How to Play

1. **Start the game** by pressing `S` from the main menu
2. **Move your basket** to catch falling eggs
3. **Avoid catching poop** - it reduces your score!
4. **Survive for 60 seconds** and maximize your score
5. **Watch out!** The game speeds up every 15 seconds

<div align="center">

### 🏆 Goal: Catch as many eggs as possible!

</div>

## 🕹️ Controls

| Action | Keys |
|--------|------|
| **Move Basket** | `Mouse` / `Arrow Keys` / `A` & `D` |
| **Start Game** | `S` |
| **Pause/Resume** | `P` |
| **Main Menu** | `M` (from pause/game over) |
| **Quit Game** | `Q` / `ESC` |

## 🎯 Scoring

| Item | Points | Speed | Rarity |
|------|--------|-------|--------|
| 🥚 **Normal Egg** | +1 | Slow | Common (70%) |
| 🔵 **Blue Egg** | +5 | Medium | Uncommon (14%) |
| 🌟 **Gold Egg** | +10 | Fast | Rare (5%) |
| 💩 **Poop** | -10 | Very Fast | Uncommon (10%) |

## 🚀 Game Progression

The game features **4 speed stages** to keep you on your toes:

- **Stage 1 (0-15s)**: Base speed - warm up!
- **Stage 2 (15-30s)**: 25% faster - things heat up!
- **Stage 3 (30-45s)**: 56% faster - intense action!
- **Stage 4 (45-60s)**: 95% faster - survive if you can!

## 📊 Spawn Rate Changes

As your score increases, objects fall more frequently:

- **Score 0-14**: One object every 900ms
- **Score 15-29**: One object every 730ms  
- **Score 30+**: One object every 550ms

## 🎨 Technical Details

- **Language**: C
- **Graphics**: OpenGL with GLUT
- **Frame Rate**: 60 FPS
- **Resolution**: 600x700 pixels (resizable)
- **Rendering**: Double-buffered with alpha blending

## 🤝 Contributor

- Soma Das - 21201111
- Sheikh Muhammad Ashik - 21201118

## 👨‍💻  Notes

The game uses a simple game loop with state management:
- **STATE_MENU**: Main menu screen
- **STATE_PLAYING**: Active gameplay
- **STATE_PAUSED**: Game paused
- **STATE_GAMEOVER**: End screen with final score

High scores are tracked per session (resets when you close the game).

---

<div align="center">

**Made with Glut and OpenGL**

*Have fun catching eggs!* 🥚🎮

</div>

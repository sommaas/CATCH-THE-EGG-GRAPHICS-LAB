#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

// Window dimensions
const int WINDOW_WIDTH = 900;
const int WINDOW_HEIGHT = 700;

// Game states
enum GameState { MENU, HELP, PLAYING, PAUSED, GAME_OVER };
GameState currentState = MENU;

// Game variables
int score = 0;
int highScore = 0;
float gameTime = 60.0f;
float timeRemaining = gameTime;
float lastTime = 0;
int comboCount = 0;
int maxCombo = 0;

// Basket properties
float basketX = 450;
float basketY = 50;
float basketWidth = 80;
float basketHeight = 60;
float basketSpeed = 15.0f;

// Multiple chicken properties
struct Chicken {
    float x, y;
    float speed;
    int direction;
    float stickY;
    float stickLeft, stickRight;
    bool active;
};

vector<Chicken> chickens;

// Egg/Item types
enum ItemType { 
    NORMAL_EGG, BLUE_EGG, GOLDEN_EGG, POOP, 
    PERK_LARGER_BASKET, PERK_SLOW_TIME, PERK_EXTRA_TIME,
    PERK_SHIELD, PERK_MAGNET, PERK_SPEED_BOOST,
    BOMB // New damage item
};

struct FallingItem {
    float x, y;
    float vx, vy; // Velocity for airflow
    ItemType type;
    float speed;
    bool active;
    float rotation;
    int sourceChicken; // Which chicken dropped it
};

vector<FallingItem> items;
float spawnTimer = 0;
float spawnInterval = 1.2f;

// Airflow system
struct Airflow {
    float startTime;
    float duration;
    float strength;
    int direction; // -1 left, 1 right
    bool active;
};

Airflow currentAirflow;
float airflowTimer = 0;
float airflowInterval = 8.0f;

// Particle system for effects
struct Particle {
    float x, y;
    float vx, vy;
    float life;
    float r, g, b;
};

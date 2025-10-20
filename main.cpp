#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Screen */
int WIN_W = 600;
int WIN_H = 700;

/* Game states */
typedef enum { STATE_MENU, STATE_PLAYING, STATE_PAUSED, STATE_GAMEOVER } GameState;
GameState state = STATE_MENU;

/* Timing */
const int FPS = 60;
const int TIMER_MS = 1000 / FPS;
const int TIME_LIMIT_SECONDS = 60;
int time_remaining = TIME_LIMIT_SECONDS;

/* Basket */
float basket_x = 300.0f;
const float BASKET_Y = 50.0f;
const float BASKET_WIDTH = 90.0f;
const float BASKET_HEIGHT = 25.0f;

/* Score */
int score = 0;
int highscore = 0;

/* Chicken */
float chicken_x = 300.0f;
float chicken_y = 620.0f;
float chicken_speed = 80.0f;

/* Speed progression */
int game_elapsed_ms = 0;
int speed_stage = 0;
const float SPEED_INCREASE = 1.25f;

/* Falling objects */
typedef enum { EGG_NORMAL, EGG_BLUE, EGG_GOLD, POOP } ObjType;

typedef struct {
    int active;
    float x, y, vy;
    ObjType type;
} FallingObj;

#define MAX_OBJS 30
FallingObj objs[MAX_OBJS];

int spawn_timer = 0;
int spawn_interval = 900;
float speed_multiplier = 1.0f;

/* Utility functions */
int rnd(int a, int b) { return a + rand() % (b - a + 1); }

void drawText(float x, float y, const char *s) {
    glRasterPos2f(x, y);
    while (*s) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *s++);
}

void drawTextCentered(float y, const char *s) {
    int len = 0;
    const char *p = s;
    while (*p++) len++;
    float x = (WIN_W - len * 10) / 2.0f;
    drawText(x, y, s);
}

/* Draw gradient background */
void draw_gradient_bg(float r1, float g1, float b1, float r2, float g2, float b2) {
    glBegin(GL_QUADS);
    glColor3f(r1, g1, b1);
    glVertex2f(0, 0);
    glVertex2f(WIN_W, 0);
    glColor3f(r2, g2, b2);
    glVertex2f(WIN_W, WIN_H);
    glVertex2f(0, WIN_H);
    glEnd();
}

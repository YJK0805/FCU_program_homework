#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

#define LEFT_KEY 0x25     // The key to move left, default = 0x25 (left arrow)
#define RIGHT_KEY 0x27    // The key to move right, default = 0x27 (right arrow)
#define ROTATE_KEY 0x26   // The key to rotate, default = 0x26 (up arrow)
#define DOWN_KEY 0x28     // The key to move down, default = 0x28 (down arrow)
#define FALL_KEY 0x20     // The key to fall, default = 0x20 (spacebar)
#define HOLD_KEY 0x43     // The key to hold, default = 0x43 (C)
#define UP_KEY 0x26	      // The key to up option, default = 0x26 (up arrow)
#define ENTER_KEY 0x0D	  // The key to enter, default = 0x0D (enter)
#define ESC_KEY 0x1B	  // The key to esc, default = 0x1B (esc)

#define FALL_DELAY 200    // The delay between each fall, default = 500
#define RENDER_DELAY 20  // The delay between each frame, default = 100

#define LEFT_FUNC() GetAsyncKeyState(LEFT_KEY) & 0x8000 //
#define RIGHT_FUNC() GetAsyncKeyState(RIGHT_KEY) & 0x8000
#define ROTATE_FUNC() GetAsyncKeyState(ROTATE_KEY) & 0x8000
#define UP_FUNC() GetAsyncKeyState(UP_KEY) & 0x8000
#define DOWN_FUNC() GetAsyncKeyState(DOWN_KEY) & 0x8000
#define FALL_FUNC() GetAsyncKeyState(FALL_KEY) & 0x8000
#define HOLD_FUNC() GetAsyncKeyState(HOLD_KEY) & 0x8000
#define ENTER_FUNC() GetAsyncKeyState(ENTER_KEY) & 0x8000
#define ESC_FUNC() GetAsyncKeyState(ESC_KEY) & 0x8000

#define CANVAS_WIDTH 10
#define CANVAS_HEIGHT 20

int CountScore[5] = {0, 10, 30, 60, 100}; // The score for each line, default = {0, 10, 30, 60, 100}
char start_menu[3][100] = { "Classic","40 lines","Quit" }, end_menu[2][100] = {"Continue","Quit"}; // The menu for start and end
// The Color of each block
typedef enum {
    RED = 41,
    GREEN,
    YELLOW,
    BLUE,
    PURPLE,
    CYAN,
    WHITE,
    BLACK = 0,
}Color;
// The shape of each block
typedef enum {
    EMPTY = -1,
    I,
    J,
    L,
    O,
    S,
    T,
    Z
}ShapeId;
// The state of each block
typedef struct {
    ShapeId shape;
    Color color;
    int size;
    char rotates[4][4][4];
}Shape;
// The state of the game
typedef struct{
    int x;
    int y;
    int line;
    int score;
    int rotate;
    int fallTime;
    int mode;
    int end;
    double start_time;
    double end_time;
    bool holdable;
    bool esc;
    ShapeId queue[4];
    ShapeId hold;
}State;
// The state of each block
typedef struct {
    Color color;
    ShapeId shape;
    bool current;
}Block;
// The state of the Block
Shape shapes[7] = {
    {
        .shape = I,
        .color = CYAN,
        .size = 4,
        .rotates =
        {
            {
                {0, 0, 0, 0},
                {1, 1, 1, 1},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 0, 1, 0},
                {0, 0, 1, 0},
                {0, 0, 1, 0},
                {0, 0, 1, 0}
            },
            {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 1, 1},
                {0, 0, 0, 0}
            },
            {
                {0, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 1, 0, 0}
            }
        }
    },
    {
        .shape = J,
        .color = BLUE,
        .size = 3,
        .rotates =
        {
            {
                {1, 0, 0},
                {1, 1, 1},
                {0, 0, 0}
            },
            {
                {0, 1, 1},
                {0, 1, 0},
                {0, 1, 0}
            },
            {
                {0, 0, 0},
                {1, 1, 1},
                {0, 0, 1}
            },
            {
                {0, 1, 0},
                {0, 1, 0},
                {1, 1, 0}
            }
        }
    },
    {
        .shape = L,
        .color = YELLOW,
        .size = 3,
        .rotates =
        {
            {
                {0, 0, 1},
                {1, 1, 1},
                {0, 0, 0}
            },
            {
                {0, 1, 0},
                {0, 1, 0},
                {0, 1, 1}
            },
            {
                {0, 0, 0},
                {1, 1, 1},
                {1, 0, 0}
            },
            {
                {1, 1, 0},
                {0, 1, 0},
                {0, 1, 0}
            }
        }
    },
    {
        .shape = O,
        .color = WHITE,
        .size = 2,
        .rotates =
        {
            {
                {1, 1},
                {1, 1}
            },
            {
                {1, 1},
                {1, 1}
            },
            {
                {1, 1},
                {1, 1}
            },
            {
                {1, 1},
                {1, 1}
            }
        }
    },
    {
        .shape = S,
        .color = GREEN,
        .size = 3,
        .rotates =
        {
            {
                {0, 1, 1},
                {1, 1, 0},
                {0, 0, 0}
            },
            {
                {0, 1, 0},
                {0, 1, 1},
                {0, 0, 1}
            },
            {
                {0, 0, 0},
                {0, 1, 1},
                {1, 1, 0}
            },
            {
                {1, 0, 0},
                {1, 1, 0},
                {0, 1, 0}
            }
        }
    },
    {
        .shape = T,
        .color = PURPLE,
        .size = 3,
        .rotates =
        {
            {
                {0, 1, 0},
                {1, 1, 1},
                {0, 0, 0}
            },

                {{0, 1, 0},
                {0, 1, 1},
                {0, 1, 0}
            },
            {
                {0, 0, 0},
                {1, 1, 1},
                {0, 1, 0}
            },
            {
                {0, 1, 0},
                {1, 1, 0},
                {0, 1, 0}
            }
        }
    },
    {
        .shape = Z,
        .color = RED,
        .size = 3,
        .rotates =
        {
            {
                {1, 1, 0},
                {0, 1, 1},
                {0, 0, 0}
            },
            {
                {0, 0, 1},
                {0, 1, 1},
                {0, 1, 0}
            },
            {
                {0, 0, 0},
                {1, 1, 0},
                {0, 1, 1}
            },
            {
                {0, 1, 0},
                {1, 1, 0},
                {1, 0, 0}
            }
        }
    },
};
// set the block with the given color and shape
void setBlock(Block* block, Color color, ShapeId shape, bool current){
    block->color = color;
    block->shape = shape;
    block->current = current;
}
// reset the block to empty
void resetBlock(Block* block){
    block->color = BLACK;
    block->shape = EMPTY;
    block->current = false;
}
// move the block to the new position
bool move(Block canvas[CANVAS_HEIGHT][CANVAS_WIDTH], int originalX, int originalY, int originalRotate, int newX, int newY, int newRotate, ShapeId shapeId) {
    Shape shapeData = shapes[shapeId];
    int size = shapeData.size;

    // check if the new position is valid to place the block
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (shapeData.rotates[newRotate][i][j]) {
                if (newX + j < 0 || newX + j >= CANVAS_WIDTH || newY + i < 0 || newY + i >= CANVAS_HEIGHT) {
                    return false;
                }
                if (!canvas[newY + i][newX + j].current && canvas[newY + i][newX + j].shape != EMPTY) {
                    return false;
                }
            }
        }
    }

    // remove the old position
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (shapeData.rotates[originalRotate][i][j]) {
                resetBlock(&canvas[originalY + i][originalX + j]);
            }
        }
    }

    // move the block
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (shapeData.rotates[newRotate][i][j]) {
                setBlock(&canvas[newY + i][newX + j], shapeData.color, shapeId, true);
            }
        }
    }

    return true;
}
// print the canvas
void printCanvas(Block canvas[CANVAS_HEIGHT][CANVAS_WIDTH], State* state){
    //printf("\033[0;0H\");
    for (int i = 0; i < CANVAS_HEIGHT; i++) {
        printf("\033[%d;10H",i + 2);
        printf("|");
        for (int j = 0; j < CANVAS_WIDTH; j++) {
            printf("\033[%dm\u3000", canvas[i][j].color);
        }
        printf("\033[0m|\n");
    }

    Shape shapeData = shapes[state->queue[1]];
    printf("\033[%d;%dHNext:", 3, CANVAS_WIDTH * 2 + 15);
    for (int i = 1; i <= 3; i++){
        shapeData = shapes[state->queue[i]];
        for (int j = 0; j < 4; j++) {
            printf("\033[%d;%dH", i * 4 + j + 1, CANVAS_WIDTH * 2 + 23);
            for (int k = 0; k < 4; k++) {
                if (j < shapeData.size && k < shapeData.size && shapeData.rotates[0][j][k]) {
                    printf("\x1b[%dm  ", shapeData.color);
                }
                else {
                    printf("\x1b[0m  ");
                }
            }
        }
    }
    if (state->mode == 0) {
        printf("\033[%d;%dHScore: %d\n", 17, CANVAS_WIDTH * 2 + 15, state->score);
    }
    printf("\033[%d;%dHHold: \n", 3, 0);
    shapeData = shapes[state->hold];
    if (state->mode == 1) {
        double time = (clock() - state->start_time) / CLOCKS_PER_SEC;
        int minutes = time / 60, seconds = (int)time % 60, microseconds = (time - (int)time) * 1000 / 10;
        printf("\033[%d;%dHtime: \n  %d:%d:%d\n", 8, 0, minutes, seconds, microseconds);
        printf("\033[%d;%dHLines:\n  %d", 12,0,state->line);
    }
    for (int j = 0; j < 4; j++) {
        printf("\033[%d;%dH",j + 4,2);
        for (int k = 0; k < 4; k++) {
            if (j < shapeData.size && k < shapeData.size && shapeData.rotates[0][j][k]) {
                printf("\x1b[%dm  ", shapeData.color);
            }
            else {
                printf("\x1b[0m  ");
            }
        }
    }
    return;
}
// clear the line and return the number of lines cleared
int clearLine(Block canvas[CANVAS_HEIGHT][CANVAS_WIDTH]) {
    for (int i = 0; i < CANVAS_HEIGHT; i++) {
        for (int j = 0; j < CANVAS_WIDTH; j++) {
            if (canvas[i][j].current) {
                canvas[i][j].current = false;
            }
        }
    }
    int linesCleared = 0;
    for (int i = CANVAS_HEIGHT - 1; i >= 0; i--){
        bool isFull = true;
        for (int j = 0; j < CANVAS_WIDTH; j++){
            if (canvas[i][j].shape == EMPTY) {
                isFull = false;
                break;
            }
        }
        if (isFull){
            linesCleared += 1;
            for (int j = i; j > 0; j--){
                for (int k = 0; k < CANVAS_WIDTH; k++){
                    setBlock(&canvas[j][k], canvas[j - 1][k].color, canvas[j - 1][k].shape, false);
                    resetBlock(&canvas[j - 1][k]);
                }
            }
            i++;
        }
    }
    return linesCleared;
}
// check the game's status
int logic(Block canvas[CANVAS_HEIGHT][CANVAS_WIDTH], State* state){
    if (HOLD_FUNC() && !state->holdable) {
        state->holdable = true;
        for(int i = 0; i < CANVAS_HEIGHT; i++){
			for(int j = 0; j < CANVAS_WIDTH; j++){
				if(canvas[i][j].current){
					resetBlock(&canvas[i][j]);
				}
			}
		}
        state->x = CANVAS_WIDTH / 2;
        state->y = 0;
        state->rotate = 0;
        state->fallTime = 0;
        if (state->hold != EMPTY) {
            ShapeId t = state->hold;
            state->hold = state->queue[0];
            state->queue[0] = t;
        }else {
            state->hold = state->queue[0];
            state->queue[0] = state->queue[1];
            state->queue[1] = state->queue[2];
            state->queue[2] = state->queue[3];
            state->queue[3] = rand() % 7;
        }
        move(canvas, state->x, state->y, state->rotate, state->x, state->y, state->rotate, state->queue[0]);
    }else if (ROTATE_FUNC()) {
        int newRotate = (state->rotate + 1) % 4;
        if (move(canvas, state->x, state->y, state->rotate, state->x, state->y, newRotate, state->queue[0])){
            state->rotate = newRotate;
        }
    }else if (LEFT_FUNC()){
        if (move(canvas, state->x, state->y, state->rotate, state->x - 1, state->y, state->rotate, state->queue[0])){
            state->x -= 1;
        }
    }else if (RIGHT_FUNC()){
        if (move(canvas, state->x, state->y, state->rotate, state->x + 1, state->y, state->rotate, state->queue[0])){
            state->x += 1;
        }
    }else if (DOWN_FUNC()) {
        state->fallTime = FALL_DELAY;
    }else if (FALL_FUNC()) {
        state->fallTime += FALL_DELAY * CANVAS_HEIGHT;
    }
    state->fallTime += RENDER_DELAY;
    while (state->fallTime >= FALL_DELAY) {
        state->fallTime -= FALL_DELAY;
        if(move(canvas, state->x, state->y, state->rotate, state->x, state->y + 1, state->rotate, state->queue[0])) {
            state->y++;
        }else{
            int linesCleared = clearLine(canvas);
            state->line += linesCleared;
            state->score += CountScore[linesCleared];
            state->x = CANVAS_WIDTH / 2;
            state->y = 0;
            state->rotate = 0;
            state->fallTime = 0;
            state->queue[0] = state->queue[1];
            state->queue[1] = state->queue[2];
            state->queue[2] = state->queue[3];
            state->queue[3] = rand() % 7;
            state->holdable = false;
            if (!move(canvas, state->x, state->y, state->rotate, state->x, state->y, state->rotate, state->queue[0])){
                return -1;
            }
        }
    }
    return 1;
}
// print the game's rules
void printRules(int mode) {
    printf("\033[%d;%dH---------- Tetris Game Rules ----------\n",3,3);
    printf("\033[%d;%dHGame Mode: %s\n",4,3,mode == 0 ? "Classic" : "40 Lines");
    printf("\n");
    if (mode == 0) {
        printf("\033[%d;%dHPlay the game until you can't place any more blocks.",5,3);
        printf("\033[%d;%dHOr you can press ESC to quit the game.", 6, 3);
    }else {
        printf("\033[%d;%dHPlay the game until you clear 40 or more lines or blocks reach the top of the screen.", 5, 3);
        printf("\033[%d;%dHOr you can press ESC to quit the game.", 6, 3);
    }
    printf("\033[%d;%dHControls:\n",8,3);
    printf("\033[%d;%dH   - Move Left: Arrow Left\n",9,3);
    printf("\033[%d;%dH   - Move Right: Arrow Right\n",10,3);
    printf("\033[%d;%dH   - Rotate: Arrow Up\n",11,3);
    printf("\033[%d;%dH   - Move Down: Arrow Down\n",12,3);
    printf("\033[%d;%dH   - Fall Instantly: Spacebar\n",13,3);
    printf("\033[%d;%dH   - Hold: C\n",14,3);
    printf("\n");
    printf("\033[%d;%dHObjective:\n",16,3);
    printf("\033[%d;%dH   - Fill horizontal lines with blocks to clear them\n",17,3);
    printf("\033[%d;%dH   - The game ends when blocks reach the top of the screen\n",18,3);
    printf("\n");
    if (mode == 0) {
        printf("\033[%d;%dHScoring:\n", 20, 3);
        printf("\033[%d;%dH   - Clearing 1 line: +10 points\n", 21, 3);
        printf("\033[%d;%dH   - Clearing 2 lines: +30 points\n", 22, 3);
        printf("\033[%d;%dH   - Clearing 3 lines: +60 points\n", 23, 3);
        printf("\033[%d;%dH   - Clearing 4 lines (Tetris): +100 points\n", 24, 3);
        printf("\033[%d;%dHpress Enter to play the game\n", 26, 3);
    }else {
        printf("\033[%d;%dH   - Or ends when clear 40 or more lines or blocks reach the top of the screen\n", 19, 3);
        printf("\033[%d;%dHpress Enter to play the game\n", 21, 3);
    }
}
// print the start screen
void start_display() {
    printf("\033[%d;%dH _______ ______ _______ _____  _____  _____ \n",3,3);
    printf("\033[%d;%dH|__   __|  ____|__   __|  __ \\|_   _|/ ____|\n",4,3);
    printf("\033[%d;%dH   | |  | |__     | |  | |__) | | | | (___  \n",5,3);
    printf("\033[%d;%dH   | |  |  __|    | |  |  _  /  | |  \\___ \\ \n",6,3);
    printf("\033[%d;%dH   | |  | |____   | |  | | \\ \\ _| |_ ____) |\n",7,3);
    printf("\033[%d;%dH   |_|  |______|  |_|  |_|  \\_\\_____|_____/ \n",8,3);
    printf("\033[%d;%dHpress any key to start(except Enter)\n",10,7);
}
// print the menu screen
void menu_display(int mode) {
    printf("\033[%d;%dH       SELECT MODE\n\n",3,5);
    for (int i = 0; i < 3; i++) {
        printf("\033[%d;%dH", 5 + i, 13);
        if (mode == i) {
            printf(">");
        }
        else {
            printf(" ");
        }
        printf("%s\n", start_menu[i]);
    }
    printf("\033[%d;%dH\npress up,down,Enter to select mode.\n",8,5);
}
// print the end screen
void end_display(State* state) {
    printf("\033[%d;%dH _______ ______ _______ _____  _____  _____ \n",3,3);
    printf("\033[%d;%dH|__   __|  ____|__   __|  __ \\|_   _|/ ____|\n",4,3);
    printf("\033[%d;%dH   | |  | |__     | |  | |__) | | | | (___  \n",5,3);
    printf("\033[%d;%dH   | |  |  __|    | |  |  _  /  | |  \\___ \\ \n",6,3);
    printf("\033[%d;%dH   | |  | |____   | |  | | \\ \\ _| |_ ____) |\n",7,3);
    printf("\033[%d;%dH   |_|  |______|  |_|  |_|  \\_\\_____|_____/ \n",8,3);
    printf("\033[%d;%dH\n\n",10,7);
    if (state->mode == 0) {
        printf("\033[%d;%dHYour score is %d\n", 12, 7, state->score);
    }else {
        if (state->line >= 40) {
            double time = (state->end_time - state->start_time) / CLOCKS_PER_SEC;
            int minutes = time / 60, seconds = (int)time % 60, microseconds = (time - (int)time) * 1000 / 10;
            printf("\033[%d;%dHYou win!\n", 12, 10);
            printf("\033[%d;%dHYou use %d:%d:%d!\n", 13, 7,minutes,seconds,microseconds);
        }else if(!state->esc){
		    printf("\033[%d;%dHYou lose!\n", 12, 9);
        }
    }
    for (int i = 0; i < 2; i++) {
        printf("\033[%d;%dH", 14 + i, 9);
        if (state->end == i) {
            printf(">");
        }else {
            printf(" ");
        }
        printf("%s\n", end_menu[i]);
    }
    printf("\033[%d;%dHpress up,down,Enter to select continue or quit\n",17,0);
}
int main(){
    srand(time(NULL));
    while (!_kbhit()) {
        start_display();
        Sleep(100);
    }
    system("cls");
    while (1) {
        State state = {
            .x = CANVAS_WIDTH / 2,
            .y = 0,
            .line = 0,
            .score = 0,
            .rotate = 0,
            .fallTime = 0,
            .mode = 0,
            .end = 0,
            .esc = false,
            .hold = EMPTY,
            .holdable = false
        };
        for (int i = 0; i < 4; i++) {
            state.queue[i] = rand() % 7;
        }
        Block canvas[CANVAS_HEIGHT][CANVAS_WIDTH];
        for (int i = 0; i < CANVAS_HEIGHT; i++) {
            for (int j = 0; j < CANVAS_WIDTH; j++) {
                resetBlock(&canvas[i][j]);
            }
        }
        while(1) {
			menu_display(state.mode);
			if (UP_FUNC()) {
				state.mode = (state.mode + 2) % 3;
			}else if (DOWN_FUNC()) {
				state.mode = (state.mode + 1) % 3;
			}else if (ENTER_FUNC()) {
				break;
			}
			Sleep(100);
		}
        if (state.mode != 2) {
            system("cls");
            printRules(state.mode);
            Sleep(500);
            while (1){
                printRules(state.mode);
                if(ENTER_FUNC()) {
					break;
				}
            }
            system("cls");
            move(canvas, state.x, state.y, state.rotate, state.x, state.y, state.rotate, state.queue[0]);
            state.start_time = clock();
            while (1) {
                if (logic(canvas, &state) == -1) {
                    break;
                }else if(state.mode == 1 && state.line >= 40) {
                    state.end_time = clock();
					break;
                }else if (ESC_FUNC()) {
                    state.esc = true;
                    break;
                }
                printCanvas(canvas, &state);
                Sleep(100);
            }
            system("cls");
            while (1) {
                end_display(&state);
                if (UP_FUNC() || DOWN_FUNC()) {
                    state.end = (state.end + 1) % 2;
                }else if (ENTER_FUNC()) {
                    break;
                }
                Sleep(100);
            }
            if (state.end == 1) {
				break;
            }else {
                Sleep(100);
                system("cls");
            }
        }else {
            break;
        }
    }
    system("cls");
    printf("\n\n\tThanks for playing.\n\t      bye bye！\n\n");
    return 0;
}
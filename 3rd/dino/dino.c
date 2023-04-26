#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define ROAD_LENGTH 50 //路面長度
#define DINO_PLACE 6   //小恐龍在路面上的第幾格

char menu[3][100] = { "Classic","bonus","Quit" }, item[5] = { 'F','*','/','+','-' };

typedef struct dino {
    char road[ROAD_LENGTH + 1];//字串結尾需要'\0'
    char sky[ROAD_LENGTH + 1];//字串結尾需要'\0'
    int jump_time_left;      //還剩多久掉回地面
    int score;               //分數
    int wait_time;           //每次迴圈之間等待的時間
    int barrier_chance;      //放置障礙物的機率
    int item_chance;      //放置天空物品的機率
    int item;             //取得的物品
    int jump_times;          //跳躍次數
    int fever;                //無敵時間
    int mode;                //遊戲模式
    //可以放之後可能會增加或是其他你需要的資料
}Dino;

void rule_display(Dino* MyDino) {
    system("cls");
    printf("\n\t\t\trule\n\n");
    if (MyDino->mode == 0) {
        printf("\t1. Run and avoid obstacles on an endless map.\n\n");
        printf("\t2. Jump with spacebar or up, return to ground with down.\n\n");
        printf("\t3. Keep playing to increase your score.\n\n");
    }else if (MyDino->mode == 1) {
        printf("\t1. Run and avoid obstacles on an endless map.\n\n");
        printf("\t2. Jump with spacebar or up, return to ground with down.\n\n");
        printf("\t3. Keep playing to increase your score.\n\n");
        printf("\t4. In this mode, some items will appear in the air that you can collect.\n\n");
        printf("\t\tHere are the item descriptions :\n\n");
        printf("\tF：Enters fever mode, makes you invincible for 5 seconds, and touching obstacles will not end the game.\n\n");
        printf("\t*：Doubles your score.\n\n");
        printf("\t/：Divides your score by 2.\n\n");
        printf("\t+：Adds 5 to your score.\n\n");
        printf("\t-：Subtracts 5 from your score.\n\n");
    }
    printf("press any key to play the game\n");
    return;
}

Dino* init(void) {
    Dino* MyDino = malloc(sizeof(Dino));
    if (MyDino != NULL) {
        MyDino->score = 0;
        MyDino->jump_time_left = 0;
        MyDino->wait_time = 150;
        MyDino->barrier_chance = 5;
        MyDino->item_chance = 5;
        MyDino->jump_times = 0;
        MyDino->mode = 0;
        MyDino->fever = 0;
        MyDino->item = 0;
        for (int i = 0; i < ROAD_LENGTH; i++) {
            MyDino->sky[i] = ' ';
            MyDino->road[i] = '_';
        }
        MyDino->sky[ROAD_LENGTH] = '\0';
        MyDino->road[ROAD_LENGTH] = '\0';
    }
    return MyDino;
}

void menu_display(int mode) {
    system("cls");
    printf("\n\t       SELECT MODE\n\n");
    for (int i = 0; i < 3; i++) {
        printf("\t\t");
        if (mode == i) {
            printf(">");
        }else{
            printf(" ");
        }
        printf("%s\n", menu[i]);
    }
    printf("\npress up,down,Enter to select mode.\n");
}

void game_display(Dino* MyDino) {
    system("cls");
    printf("\n\t");
    if (MyDino->mode == 1) {
        if (MyDino->item != 0) {
            if (MyDino->item == 1) {
                printf("collect fever,you're in fever mode.            ");
            }else if (MyDino->item == 2) {
                printf("collect multiple,your score will multipled by 2");
            }else if (MyDino->item == 3) {
                printf("collect divide,your score will divided by 2    ");
            }else if (MyDino->item == 4) {
                printf("collect plus,your score will increased by 5    ");
            }else if (MyDino->item == 5) {
                printf("collect minus,your score will decreased by 5   ");
            }
            MyDino->item = 0;
        }else {
            printf("                                               ");
        }
        if (MyDino->fever != 0) {
			printf("\tfever time：%d", MyDino->fever);
		}
    }
    printf("\n\t");
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (i == DINO_PLACE && MyDino->jump_time_left > 0) {
            if (MyDino->fever != 0) {
                printf("\033[0;32mF\033[m");
            }else {
                printf("O");
            }
        }else {
            printf("%c",MyDino->sky[i]);
        }
    }
    printf("\n\t");
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (i == DINO_PLACE && MyDino->jump_time_left == 0) {
            if (MyDino->fever != 0) {
                printf("\033[0;32mF\033[m");
            }else {
                printf("O");
            }
        }else {
            if (MyDino->road[i] == 'X') {
                printf("\033[0;31mX\033[m");
            }else {
                printf("%c", MyDino->road[i]);
            }
        }
    }
    printf("\n\n\n\t");
    printf("\tjump times：%d\tscore：%d\n", MyDino->jump_times,MyDino->score);
    return;
}

void over_display(Dino* MyDino) {
    system("cls");
    printf("\n\n\t\tGame Over\n\t\tjump times：%d\n\t\tscore：%d\n", MyDino->jump_times, MyDino->score);
    printf("\npress any key to continue(except Enter)\n");
    return;
}

void start_display(void) {
    system("cls");
    printf("\t _____    _____   _   _    ____ \n");
    printf("\t|  __ \\  |_   _| | \\ | |  / __ \\\n");
    printf("\t| |  | |   | |   |  \\| | | |  | |\n");
    printf("\t| |  | |   | |   | . ` | | |  | |\n");
    printf("\t| |__| |  _| |_  | |\\  | | |__| |\n");
    printf("\t|_____/  |_____| |_| \\_|  \\____/ \n");
    printf("\npress any key to start(except Enter)\n");
    return;
}

void move(Dino* MyDino) {
    for (int i = 0; i < ROAD_LENGTH - 1; i++) {
        MyDino->road[i] = MyDino->road[i + 1];
        MyDino->sky[i] = MyDino->sky[i + 1];
    }
    MyDino->road[ROAD_LENGTH - 1] = '_';
    MyDino->sky[ROAD_LENGTH - 1] = ' ';
}

int game_operate(void) {
    if (_kbhit() != 0) {
		int ch = _getch();
        if (ch == 32 || ch == 72) {
			return 1;
        }else if (ch == 80) {
			return 2;
		}
	}
	return 0;
}

int option_choose(void) {
    if (_kbhit() != 0) {
        int ch = _getch();
        if (ch == 13) {
            return 1;
        }else if (ch == 80) {
            return 2;
        }else if (ch == 72) {
            return 3;
        }
    }
    return 0;
}

bool spawn_barrier(Dino* MyDino) {
    int rand_num = rand() % 100;
    return rand_num < MyDino->barrier_chance;
}

bool spawn_item(Dino* MyDino) {
    int rand_num = rand() % 100;
    return rand_num < MyDino->item_chance;
}

bool is_bumped(Dino* MyDino) {
    return (MyDino->jump_time_left == 0 && MyDino->road[DINO_PLACE] == 'X' && MyDino->fever == 0);
}

bool collect_item(Dino* MyDino) {
    if (MyDino->jump_time_left != 0) {
        if (MyDino->sky[DINO_PLACE] != ' ') {
            return true;
        }
    }
    return false;
}

void update_chance(Dino* MyDino) {
    if (MyDino->score % 100 == 0) {
        MyDino->barrier_chance += 5;
    }
    if (MyDino->score % 100 == 0) {
        MyDino->item_chance++;
    }
}

int main(){
    start_display();
    Sleep(1000);
    while (!_kbhit()){
        start_display();
        Sleep(100);
    }
    while (true) {
        /* 初始化 */
        srand(time(NULL));
        Dino* MyDino = init();
        /* 選單 */
        menu_display(MyDino->mode);
        Sleep(500);
        while (true) {
            menu_display(MyDino->mode);
            int option = option_choose();
            if (option == 1) {
                break;
            }else if (option == 2 && MyDino->mode < 2) {
                MyDino->mode++;
            }else if (option == 3 && MyDino->mode > 0) {
                MyDino->mode--;
            }
            Sleep(100);
        }
        if (MyDino->mode == 2) {
            break;
        }else {
            rule_display(MyDino);
            Sleep(500);
            while (!_kbhit()){
                rule_display(MyDino);
                Sleep(100);
            }
        }
        /* 遊戲本體 */
        game_display(MyDino);
        while (true) {
            /* 邏輯運算 */
            int operate = game_operate();
            if (operate == 1 && MyDino->jump_time_left == 0) {
                MyDino->jump_times++;
                MyDino->jump_time_left = 7;
            }else if (operate == 2) {
                MyDino->jump_time_left = 0;
            }
            move(MyDino);
            if (spawn_barrier(MyDino)) {
                MyDino->road[ROAD_LENGTH - 1] = 'X';
            }
            if (MyDino->mode == 1) {
                if (MyDino->fever > 0) {
					MyDino->fever--;
				}
                if (spawn_item(MyDino)) {
                    MyDino->sky[ROAD_LENGTH - 1] = item[rand() % 5];
                }
                if (collect_item(MyDino)) {
                    if (MyDino->sky[DINO_PLACE] == 'F') {
                        MyDino->fever = 5;
                        MyDino->item = 1;
                    }else if (MyDino->sky[DINO_PLACE] == '*') {
                        MyDino->score *= 2;
                        MyDino->item = 2;
                    }else if (MyDino->sky[DINO_PLACE] == '/') {
                        MyDino->score /= 2;
                        MyDino->item = 3;
                    }else if (MyDino->sky[DINO_PLACE] == '+') {
                        MyDino->score += 5;
                        MyDino->item = 4;
                    }else if (MyDino->sky[DINO_PLACE] == '-') {
                        MyDino->score -= 5;
                        MyDino->item = 5;
                    }
                    MyDino->sky[DINO_PLACE] = ' ';
                }
            }
            if (MyDino->jump_time_left > 0) {
                MyDino->jump_time_left--;
            }
            if (is_bumped(MyDino)) {
                break;
            }
            update_chance(MyDino);
            /* 渲染呈現 */
            game_display(MyDino);
            MyDino->score++;
            Sleep(MyDino->wait_time);
        }
        over_display(MyDino);
        Sleep(500);
        while (!_kbhit()) {
            over_display(MyDino);
            Sleep(100);
        }
    }
    system("cls");
    printf("\n\n\tThanks for playing.\n\t      bye bye！\n\n");
    return 0;
}
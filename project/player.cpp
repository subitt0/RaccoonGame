#include "player.h"
#include "basic.h"
#include "title.h"
#include <time.h>
#define JUMPDELAY 3
#define ENEMYTIME 3
long startTime = 0;
long totalElapsedTime = 0;
int iStage;
int score;
int life;
int isJumping;
int jumpDelay = 0;
int jumpPower;
int dir;
Pos PlyPos;
int isPlaying;
int enemyTime;
Enemy e1;
Enemy e2;
Enemy e3;
Enemy e4;
Enemy e5;
Enemy e6;

int map1_b[22][26] = {
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,4,0,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,2,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,0,0,0,3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,3,0,0,5,0,0,0,0,0,0,3,0,0,2,0,0,0,0,0,4,0,1},
   {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,3,0,0,0,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,7,0,0,4,0,0,3,0,0,0,0,0,0,8,0,0,0,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int map[22][26] = {

   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,9,0,0,0,4,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,4,0,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,2,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,0,0,0,3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,3,0,0,5,0,0,0,0,0,0,3,0,0,2,0,0,0,0,0,4,0,1},
   {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,3,0,0,0,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,7,0,0,4,0,0,3,0,0,0,0,0,0,8,0,0,0,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int map2[22][26] = {

   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,7,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,4,0,0,1},
   {1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,4,0,0,0,0,0,3,0,0,0,0,0,0,0,0,88,0,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,1},
   {1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,5,0,5,0,4,0,0,3,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1},
   {1,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,3,0,0,0,0,2,0,5,5,5,5,5,5,5,5,5,5,5,5,5,9,4,1},
   {1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1},
   {1,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,4,0,3,0,0,2,4,2,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int map3[22][26] = {

   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,4,0,0,9,5,5,5,5,5,5,5,5,5,5,5,5,5,0,2,0,9,5,5,5,1},
   {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,5,5,5,5,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,5,0,0,0,0,0,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,1},
   {1,0,0,0,0,0,0,5,888,0,0,0,0,0,0,8888,0,0,0,0,0,5,3,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,7,3,5,5,0,5,5,0,5,5,0,5,5,0,5,5,0,5,5,0,5,5,0,4,1},
   {1,1,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,1},
   {1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,3,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void putPlayer(int x, int y, char* ch)
{
    gotoxy(x * 2 + MAPX, y + MAPY);
    printf("%s", ch);
    ch = 0;
}

void erasePlayer(int x, int y)
{
    gotoxy(x * 2 + MAPX, y + MAPY);
    printf("%s", BLANK);
}

void eraseEnemy(Enemy* e) {
    gotoxy(e->x * 2 + MAPX, e->y + MAPY);
    printf("%s", BLANK);
}

int game() {
    gameInit();
    while (isPlaying) {
        gameUpdate();
        gameRender();
    }
   
    return 0;
}


void gameInit() {
    int keep_moving;
    iStage = 1;
    score = 0;
    life = 3;
    PlyPos.x = 22;
    PlyPos.y = 19;
    dir = 0;
    isPlaying = 1;
    removeCursor();

    keep_moving = 0; 
    enemyTime = 0;
    if(iStage==1){
    e1.x = 8;
    e1.y = 3;
    e2.x = 10;
    e2.y = 7;
    map[e1.y][e1.x] = 6;
    map[e2.y][e2.x] = 6;
    }
     e3.x = 9;
     e3.y = 7;
     e4.x = 3;
     e4.y = 11;
     e5.x = 14;
     e5.y = 19;
     e6.x = 9;
     e6.y = 7;

   
}


void gameUpdate() {
    putPlayer(PlyPos.x, PlyPos.y, (char*)PLAYER);
    unsigned char ch = 0; // 초기값 정지상태
    erasePlayer(PlyPos.x, PlyPos.y);
    //map[PlyPos.y][PlyPos.x] = 0;

    if (_kbhit() == 1)  // 키보드가 눌려져 있으면
        ch = _getch(); // key 값을 읽는다

    switch (ch) {
    case ESC: isPlaying = 0; break;
    case UP:
        if (map[PlyPos.y][PlyPos.x] == 3 || map[PlyPos.y + 1][PlyPos.x] == 3) {
            PlyPos.y--;
            break;
        }
        else if (map[PlyPos.y][PlyPos.x] == 0)
            break;
    case DOWN:
        if (map[PlyPos.y + 1][PlyPos.x] == 3 || map[PlyPos.y + 2][PlyPos.x] == 3) {
            PlyPos.y++;
            break;
        }
        else
            break;
    case LEFT:
        if (map[PlyPos.y][PlyPos.x - 1] != 1) {
            PlyPos.x--;
            dir = -1;
        }
        break;
    case RIGHT:
        if (map[PlyPos.y][PlyPos.x + 1] != 1) {
            PlyPos.x++;
            dir = 1;
        }
        break;
    case SPACE:
        if (!isJumping) {
            isJumping = 1;
            jumpPower = 1;
        }
        break;

        case ENTER:
            if (score == 250)
                iStage++;
            else if (score == 550)
                iStage++;
           if (iStage == 2) {
              cls(15, 0);
              stage();
              remove_stage();
              map[e3.y][e3.x] = 6;
              map[e4.y][e4.x] = 6;
              enemyStart();
           }
           else if (iStage == 3) {
               cls(15, 0);
               stage();
               remove_stage2();
               map[e5.y][e5.x] = 6;
               map[e6.y][e6.x] = 6;
               enemyStart();
           }
           break;
    }
    if (isJumping)
        jump();

    if (map[PlyPos.y][PlyPos.x] == 4) {
        eat_item();
    }
    if (map[PlyPos.y][PlyPos.x] == 7)
        eat_life();
    if (map[PlyPos.y][PlyPos.x] == 2)
        spike();
    if (map[PlyPos.y][PlyPos.x] == 6)
        EnemyAttack();
    if (map[PlyPos.y][PlyPos.x] == 5) {
        drop();
    }
    if (map[PlyPos.y][PlyPos.x] == 8) {
        teleport(1, 3);
    }
    if (map[PlyPos.y][PlyPos.x] == 88) {
        teleport(23, 15);
    }
    if (map[PlyPos.y][PlyPos.x] == 888) {
        teleport(21, 4);
    }
    if (map[PlyPos.y][PlyPos.x] == 8888) {
        teleport(4, 3);
    }
    

    putPlayer(PlyPos.x, PlyPos.y, (char*)PLAYER);
}

void gameRender() {
    int x, y;
    for (y = 0; y < 22; y++) {
        for (x = 0; x < 26; x++) {
            gotoxy((x * 2) + MAPX, y + MAPY);
            switch (map[y][x])
            {
            case 1: printf("■"); break;
            case 2: printf("▲"); break;
            case 22: printf("▲"); break;
            case 3: printf("Ⅱ"); break;
            case 4:
                int c;
                c = rand() % 5;
                switch (c) {
                case 0: textcolor(GREEN1, BLACK);  break;
                case 1: textcolor(MAGENTA1, BLACK); break;
                case 2: textcolor(YELLOW1, BLACK); break;
                case 3: textcolor(CYAN2, BLACK);  break;
                case 4: textcolor(BLUE2, BLACK);  break;
                }
                printf("@");
                textcolor(WHITE, BLACK);
                break;
            case 5: printf(" "); break;
            case 6:
                textcolor(BLACK, RED1);
                printf("▣");
                textcolor(WHITE, BLACK); break;
            case 7:
                textcolor(RED1, BLACK);
                printf("♥");
                textcolor(WHITE, BLACK); break;
            case 8:
                textcolor(BLUE1, BLACK);
                printf("◎");
                textcolor(WHITE, BLACK); break;
            case 88:
                textcolor(BLUE1, BLACK);
                printf("◎");
                textcolor(WHITE, BLACK); break;
            case 888:
                textcolor(BLUE1, BLACK);
                printf("◎");
                textcolor(WHITE, BLACK); break;
            case 8888:
                textcolor(BLUE1, BLACK);
                printf("◎");
                textcolor(WHITE, BLACK); break;
            case 9:
                textcolor(RED1, BLACK);
                printf("◎");
                textcolor(WHITE, BLACK); break;
            case 10: printf("  "); break;
            }
        }
    }
    putPlayer(PlyPos.x, PlyPos.y, (char*)PLAYER);
    stage();
    show_life();
    score_UI();
    enemyStart();
}

void enemyStart() {
    if (enemyTime > ENEMYTIME * 10) {
        if (iStage == 1) {
            EnemyMove(&e1);
            EnemyMove(&e2);
        }
        if (iStage == 2) {
            EnemyMove(&e3);
            EnemyMove(&e4);
        }
        if (iStage == 3) {
            EnemyMove(&e5);
            EnemyMove(&e6);
        }

        enemyTime = 0;
    }
    enemyTime++;
}


void EnemyAttack()
{
    map[PlyPos.y][PlyPos.x] = 0;
    if (life == 1)
        game_over();
    else {
        life--;
        show_life();
    }
}

void EnemyMove(Enemy* e)
{
    int dir;
    int isSomthing;

    map[e->y][e->x] = 0;
    eraseEnemy(e);

    do {
        dir = rand() % 2;
        isSomthing = 0;

        switch (dir)
        {
        case 0: if (map[e->y][e->x - 1] != 0) isSomthing = 1;
            if (map[e->y][e->x] == 4) e->x--;
            break;
        case 1: if (map[e->y][e->x + 1] != 0) isSomthing = 1;
            if (map[e->y][e->x] == 4) e->x++;
            break;
        }
    } while (isSomthing);

    switch (dir)
    {
    case 0: e->x--; break;
    case 1: e->x++; break;
    }

    map[e->y][e->x] = 6;
}

void drop() {
    putPlayer(PlyPos.x, PlyPos.y + 1, (char*)PLAYER);
    Sleep(100);
    erasePlayer(PlyPos.x, PlyPos.y + 1);
    putPlayer(PlyPos.x, PlyPos.y + 2, (char*)PLAYER);
    Sleep(100);
    erasePlayer(PlyPos.x, PlyPos.y + 2);
    putPlayer(PlyPos.x, PlyPos.y + 3, (char*)PLAYER);
    Sleep(100);
    erasePlayer(PlyPos.x, PlyPos.y + 3);
    putPlayer(PlyPos.x, PlyPos.y + 4, (char*)"ㅇㅣㅅ");
    Sleep(1000);
    game_over();
}

void teleport(int x, int y) {
        gotoxy(x, y);
        PlyPos.x = x;
        PlyPos.y = y;
        putPlayer(PlyPos.x, PlyPos.y, (char*)PLAYER);
}


void remove_stage() {
    system("cls");
    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 24; j++) {
            map[i][j] = map2[i][j];
        }
    }
    PlyPos.x = 22;
    PlyPos.y = 19;
    putPlayer(PlyPos.x, PlyPos.y, (char*)PLAYER);


}

void remove_stage2() {
   
    system("cls");
    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 24; j++) {
            map[i][j] = map3[i][j];
        }
    }
    PlyPos.x = 22;
    PlyPos.y = 19;
    putPlayer(PlyPos.x, PlyPos.y, (char*)PLAYER);


}

void eat_item() {
    score += 50;
    score_UI();
    if (score == 250) {
        //iStage++;
        gotoxy(59, 10);
        textcolor(YELLOW1, BLACK);
        printf("STAGE 1 CLEAR\n");
        gotoxy(57, 15);
        printf(" ENTER 키를 눌러");
        gotoxy(58, 16);
        printf("다음 스테이지로 ");
    }
    else if (score == 550) {
        //iStage++;
        gotoxy(59, 10);
        textcolor(YELLOW1, BLACK);
        printf("STAGE 1 CLEAR\n");
        gotoxy(57, 15);
        printf(" ENTER 키를 눌러");
        gotoxy(58, 16);
        printf("다음 스테이지로 ");
        textcolor(15, 0);
    }
    else if (score == 700) {
        finish();
    }
    map[PlyPos.y][PlyPos.x] = 0;
}

void eat_life() {
    map[PlyPos.y][PlyPos.x] = 0;
    if (life < 3)
        life++;
}

void spike() {
    if (life == 1) {
        map[PlyPos.y][PlyPos.x] = 22;
        game_over();
    }
    else {
        map[PlyPos.y][PlyPos.x] = 22;
        life--;
        show_life();
    }


}

void show_life() {

    if (life == 1) {
        gotoxy(10, 26);
        printf("♥");
        gotoxy(12, 26);
        printf("  ");
        gotoxy(14, 26);
        printf("  ");
    }
    else if (life == 2) {
        gotoxy(10, 26);
        printf("♥");
        gotoxy(12, 26);
        printf("♥");
        gotoxy(14, 26);
        printf("  ");
    }
    else if (life == 3) {
        gotoxy(10, 26);
        printf("♥");
        gotoxy(12, 26);
        printf("♥");
        gotoxy(14, 26);
        printf("♥");
    }
}

void game_over() {
    //게임오버출력하고 메인으로 나감
    isPlaying = 0;
    cls(BLACK, RED1);
    gotoxy(35, 15);
    printf(" GAME OVER");
    gotoxy(35, 17);
    printf(" 점수 : %d", score);
    gotoxy(20, 25);
    printf(" ENTER 키를 눌러 메인 화면으로 나가세요.");

    while (1) {
        //if (iStage == 1) {
            for (int i = 1; i <= 19; i++) {
                for (int j = 1; j <= 24; j++) {
                    map[i][j] = map1_b[i][j];
                }
           // }
        }
        char ch = 0;
        if (_kbhit())
            ch = _getch();
        switch (ch) {
        case ENTER:
            cls(15, 0);
            title();
            break;
        }
    }


}

void jump() {
    if (isJumping)
    {
        if (jumpDelay >= JUMPDELAY)
        {
            PlyPos.y -= jumpPower;
            if (map[PlyPos.y][PlyPos.x + dir] != 1)
                PlyPos.x += 1 * dir;
            jumpPower--;
            jumpDelay = 0;
            if (jumpPower == -2)
                isJumping = false;
        }
        jumpDelay++;
    }
}

void score_UI() { // 점수 :
    gotoxy(35, 26);
    printf(" 점수 : %d", score);
}

void stage() {
    gotoxy(61, 3);
    printf("STAGE");
    gotoxy(67, 3);
    printf("%d", iStage);

}

void manual() {
    //cls(15, 0);
    while (1) {
        gotoxy(35, 3);
        textcolor(WHITE, BLACK);
        printf("게임 방법");
        gotoxy(33, 10);
        printf("플레이어 : 읏");
        gotoxy(18, 13);
        printf("하트");
        textcolor(RED1, BLACK);
        printf("♥   ");
        textcolor(WHITE, BLACK);
        printf(": 생명력 1을 회복합니다(최대 3)");
        gotoxy(18, 14);
        printf("가시 ▲  : 닿으면 생명력이 1 감소합니다");
        gotoxy(18, 15);
        printf("몬스터 ");
        textcolor(RED1, BLACK);
        printf("▣");
        textcolor(WHITE, BLACK);
        printf(": 맞으면 생명력이 1 감소합니다");
        gotoxy(18, 16);
        printf("과일 ");
        int c;
        c = rand() % 5;
        switch (c) {
        case 0: textcolor(GREEN1, BLACK);  break;
        case 1: textcolor(MAGENTA1, BLACK); break;
        case 2: textcolor(YELLOW1, BLACK); break;
        case 3: textcolor(CYAN2, BLACK);  break;
        case 4: textcolor(BLUE2, BLACK);  break;
        }
        printf("@");
        textcolor(WHITE, BLACK);
        printf("   : 전부 먹으면 다음 스테이지로 넘어갑니다");
        gotoxy(18, 17);
        printf("포탈");
        textcolor(BLUE1,BLACK);
        printf("◎");
        textcolor(WHITE, BLACK);
        printf("으로 들어가면 ");
        textcolor(RED1, BLACK);
        printf("◎");
        textcolor(WHITE, BLACK);
        printf("위치로 순간이동됩니다");
        gotoxy(18, 19);
        printf("← → 버튼으로 캐릭터를 움직일 수 있습니다.");
        gotoxy(18, 20);
        printf("↑ ↓ 버튼으로 사다리를 탈 수 있습니다.");
        gotoxy(18, 21);
        printf("space 버튼을 누르면 캐릭터가 점프합니다.");
        gotoxy(18, 22);
        printf("몬스터는 랜덤하게 움직입니다.");
        gotoxy(5, 24);
        printf("-----------------------------------TIP---------------------------------");
        gotoxy(11, 26);
        printf("space 버튼을 누른 채로 방향키을 연타하면 긴 점프가 가능합니다.");
        gotoxy(11, 27);
        printf("아이템의 유혹에 빠지지 마세요! 중간중간 함정이 숨어있습니다!");


        char ch = 0;
        if (_kbhit())
            ch = _getch();
        if (ch == ENTER) {
            cls(15, 0);
            title();
        }
    }
}

void finish() {
    isPlaying = 0;
    cls(15, 0);
    //while (1) {
    gotoxy(28, 10);
    textcolor(YELLOW1, BLACK);
    printf("★★★★★CLEAR★★★★★");
    textcolor(15, 0);
    gotoxy(32, 15);
    printf(" 수고하셨습니다 ");
    gotoxy(24, 20);
    printf("ENTER 키를 눌러 메인화면으로 나가기");
    while (1) {
        for (int i = 1; i <= 19; i++) {
            for (int j = 1; j <= 24; j++) {
                map[i][j] = map1_b[i][j];
            }
        }
        char ch = 0;
        if (_kbhit())
            ch = _getch();
        if (ch == ENTER) {
            cls(15, 0);
            title();
            break;
        }
        // }
    }

}
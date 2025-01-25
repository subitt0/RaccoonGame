#include "title.h"

int cursor;

int map_title[11][32] = {

	{0,0,0,1,0,0,0,1,0,0,1,1,1,0,0,1,1,1,0,1,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,0,1,0,0,0,1,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0},
	{1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0},
	{1,0,0,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,0,0,0},
	{1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0},
	{1,1,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,0,0,0}
};

void Draw_title() {
	textcolor(WHITE, BLACK);
	int i, x, y;
	//gotoxy(5,5);
	for (y = 0; y < 11; y++) {
		for (x = 0; x < 32; x++) {
			gotoxy((x * 2) + 16, y + 3);
			if (map_title[y][x] == 0)
				printf(" ");
			if (map_title[y][x] == 1)
				printf("▨");
		}
	}
}
	
void title()
{
	titleInit();
	while (1) {
		titleUpdate();
		titleRender();
	}
}

void titleInit()
{	
	
	void removeCursor(void);
	cursor = 0;
	Draw_title();
	

}

void titleUpdate()
{
	char ch = 0;
	if (_kbhit())
		ch = _getch();

	switch (ch) {
	case DOWN: if (cursor != 2) cursor++; break;
	case UP:  if (cursor != 0) cursor--; break;
	case ENTER: 
		gotoxy(20, 10);
		switch (cursor)
		{
		case 0: 
			cls(WHITE, BLACK);
			game();
			cls(BLACK, RED1);
			game_over();
			break;
		case 1:
			cls(WHITE, BLACK);
			manual();
			break;
		case 2: 
			gotoxy(26, 29);
			exit(1);
		}
		textcolor(WHITE, BLACK);
	}
}

void titleRender()
{
	switch (cursor) {
	case 0:
		gotoxy(34, 17);
		textcolor(WHITE, BLACK);
		printf("            ");
		gotoxy(34, 18);
		printf(" ▶게임시작 ");
		gotoxy(34, 19);
		printf("            ");

		gotoxy(34, 21);
		textcolor(GRAY2, BLACK);
		printf("            ");
		gotoxy(34, 22);
		printf("  게임방법 ");
		gotoxy(34, 23);
		printf("            ");

		gotoxy(34, 25);
		textcolor(GRAY2, BLACK);
		printf("            ");
		gotoxy(34, 26);
		printf("  게임종료 ");
		gotoxy(34, 27);
		printf("            ");
		break;
	case 1:
		gotoxy(34, 17);
		textcolor(GRAY2, BLACK);
		printf("            ");
		gotoxy(34, 18);
		printf("  게임시작 ");
		gotoxy(34, 19);
		printf("            ");

		gotoxy(34, 21);
		textcolor(WHITE, BLACK);
		printf("            ");
		gotoxy(34, 22);
		printf(" ▶게임방법 ");
		gotoxy(34, 23);
		printf("            ");

		gotoxy(34, 25);
		textcolor(GRAY2, BLACK);
		printf("            ");
		gotoxy(34, 26);
		printf("  게임종료 ");
		gotoxy(34, 27);
		printf("            ");
		break;
	case 2:
		gotoxy(34, 17);
		textcolor(GRAY2, BLACK);
		printf("            ");
		gotoxy(34, 18);
		printf("  게임시작 ");
		gotoxy(34, 19);
		printf("            ");

		gotoxy(34, 21);
		textcolor(GRAY2, BLACK);
		printf("            ");
		gotoxy(34, 22);
		printf("  게임방법 ");
		gotoxy(34, 23);
		printf("            ");

		gotoxy(34, 25);
		textcolor(WHITE, BLACK);
		printf("            ");
		gotoxy(34, 26);
		printf(" ▶게임종료 ");
		gotoxy(34, 27);
		printf("            ");
		break;
	}
}

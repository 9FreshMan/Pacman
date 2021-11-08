#include <iostream>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include "time.h"
#include <fstream>
using namespace std;

/*
		Black         = 0,
		Blue          = 1,
		Green         = 2,
		Cyan          = 3,
		Red           = 4,
		Magenta       = 5,
		Brown         = 6,
		LightGray     = 7,
	   &nbsp;DarkGray      = 8,
		LightBlue     = 9,
		LightGreen    = 10,
		LightCyan     = 11,
		LightRed      = 12,
		LightMagenta  = 13,
		Yellow        = 14,
		White         = 15

*/

const int m = 31, n = 28;
char area[m][n];
int choose = 0;
char temp;
bool best = false;
bool leftp = false, rightp = false, up = false, downp = false, lh1=false, rh1=false, uh1=false, dh1=false, start=false, rage=false, lh2 = false, rh2 = false, uh2 = false, dh2 = false;
bool lh3 = false, rh3 = false, uh3 = false, dh3 = false, lh4 = false, rh4 = false, uh4 = false, dh4 = false;
int xp = 12, yp = 23, colour = 14, score = 0, lives = 3, active=0, gameover=0, xh1=14, yh1=15, way, timerage=0, xh2 = 14, yh2 = 14, way2, best_score=0, xh3 = 14, yh3 = 13, way3;
int xh4 = 14, yh4 = 14, way4;
void setcur(int x, int y)//установка курсора на позицию  x y 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
void ghost1() {
	if (xh1 == 14 && yh1 >= 10 && start==false) {
		
		uh1 = true;
		if (yh1 == 10) {
			start = true;
		}
	}
	
		/////////UP/////////
	if (uh1 == true && (area[yh1 - 1][xh1] == ' ' || area[yh1 - 1][xh1] == (char)250) && (area[yh1][xh1+1] == ' ' || area[yh1][xh1+1] == (char)250) && (area[yh1][xh1 - 1] == ' ' || area[yh1][xh1 - 1] == (char)250)) {
		uh1 = false;
		srand(time(NULL));
		way = rand()%3;
		if (way == 0) {
			uh1 = true;
		}
		 if (way == 1) {
			rh1 = true; 
		}
		if (way == 2)  {
			lh1 = true; 
		}
	}
	else if (uh1 == true && area[yh1-1][xh1] != (char)250 && area[yh1-1][xh1] != ' ' && (area[yh1][xh1-1] == ' ' || area[yh1][xh1-1] == (char)250) && (area[yh1][xh1+1] == ' ' || area[yh1][xh1+1] == (char)250)) {
		uh1 = false;
		srand(time(NULL));
		way = rand() % 2;
		if (way == 1) {
			rh1 = true;
		}
		else { lh1 = true; }
	}
	else if (uh1 == true && area[yh1][xh1+1] != (char)250 && area[yh1][xh1+1] != ' ' && (area[yh1 - 1][xh1] == ' ' || area[yh1 - 1][xh1] == (char)250) && (area[yh1][xh1 - 1] == ' ' || area[yh1][xh1 - 1] == (char)250)) {
		uh1 = false;
		srand(time(NULL));
		way = rand() % 2;
		if (way == 1) {
			uh1 = true;
		}
		else { lh1 = true; }
	}
	else if (uh1 == true && area[yh1][xh1-1] != (char)250 && area[yh1][xh1-1] != ' ' && (area[yh1 - 1][xh1] == ' ' || area[yh1 - 1][xh1] == (char)250) && (area[yh1][xh1 + 1] == ' ' || area[yh1][xh1 + 1] == (char)250)) {
		uh1 = false;
		srand(time(NULL));
		way = rand() % 2;
		if (way == 1) {
			uh1 = true;
		}
		else { rh1 = true; }
	}
	else if (uh1 == true && area[yh1][xh1 - 1] != ' ' && area[yh1][xh1 - 1] != (char)250 && (area[yh1][xh1+1] == ' ' || area[yh1][xh1+1] == (char)250)) {
		uh1 = false;
		rh1 = true;
	}
	else if (uh1 == true && area[yh1][xh1 + 1] != ' ' && area[yh1][xh1 + 1] != (char)250 && (area[yh1][xh1-1] == ' ' || area[yh1][xh1-1] == (char)250)) {
		uh1 = false;
		lh1 = true;
	}
		/////////UP/////////



		/////////RIGHT/////////
		if (rh1 == true && (area[yh1 + 1][xh1] == ' ' || area[yh1 + 1][xh1] == (char)250) && (area[yh1 - 1][xh1] == ' ' || area[yh1 - 1][xh1] == (char)250) && (area[yh1][xh1 + 1] == ' ' || area[yh1][xh1 + 1] == (char)250)) {
			rh1 = false;
			srand(time(NULL));
			way = rand() % 3;
			if (way == 1) {
				uh1 = true;
			}
			else if (way == 0) { dh1 = true; }
			else { rh1 = true; }
		}
		else 		if (rh1 == true && area[yh1][xh1 + 1] != (char)250 && area[yh1][xh1 + 1] != ' ' && (area[yh1 + 1][xh1] == ' ' || area[yh1 + 1][xh1] == (char)250) && (area[yh1 - 1][xh1] == ' ' || area[yh1 - 1][xh1] == (char)250)) {
			rh1 = false;
			srand(time(NULL));
			way = rand() % 2;
			if (way == 1) {
				uh1 = true;
			}
			else { dh1 = true; }
		}
		else if (rh1 == true && area[yh1 + 1][xh1] != (char)250 && area[yh1 + 1][xh1] != ' ' && (area[yh1 - 1][xh1] == ' ' || area[yh1 - 1][xh1] == (char)250) && (area[yh1][xh1 + 1] == ' ' || area[yh1][xh1 + 1] == (char)250)) {
			rh1 = false;
			srand(time(NULL));
			way = rand() % 2;
			if (way == 1) {
				uh1 = true;
			}
			else { rh1 = true; }
		}
		else 	if (rh1 == true && area[yh1 + 1][xh1] != (char)250 && area[yh1 + 1][xh1] != ' ' && (area[yh1 + 1][xh1] == ' ' || area[yh1 + 1][xh1] == (char)250) && (area[yh1][xh1 + 1] == ' ' || area[yh1][xh1 + 1] == (char)250)) {
			rh1 = false;
			srand(time(NULL));
			way = rand() % 2;
			if (way == 1) {
				dh1 = true;
			}
			else { rh1 = true; }
		}
		else if (rh1 == true && area[yh1][xh1+1] != ' ' && area[yh1][xh1+1] != (char)250  && (area[yh1 + 1][xh1] == ' ' || area[yh1 + 1][xh1] == (char)250)) {
			rh1 = false;
			dh1 = true;
		}
		else	if (rh1 == true && area[yh1][xh1 + 1] != ' ' && area[yh1][xh1 + 1] != (char)250 && (area[yh1 - 1][xh1] == ' ' || area[yh1 - 1][xh1] == (char)250)) {
			rh1 = false;
			uh1 = true;
		}
		/////////RIGHT/////////



		/////////LEFT/////////
		if (lh1 == true && (area[yh1 + 1][xh1] == ' ' || area[yh1 + 1][xh1] == (char)250) && (area[yh1 - 1][xh1] == ' ' || area[yh1 - 1][xh1] == (char)250) && (area[yh1][xh1 - 1] == ' ' || area[yh1][xh1 - 1] == (char)250)) {
			lh1 = false;
			srand(time(NULL));
			way = rand() % 3;
			if (way == 1) {
				uh1 = true;
			}
			else if (way == 0) { dh1 = true; }
			else { lh1 = true; }
		}
		else 	if (lh1 == true && area[yh1][xh1 - 1] != (char)250 && area[yh1][xh1 - 1] != ' ' && (area[yh1 + 1][xh1] == ' ' || area[yh1 + 1][xh1] == (char)250) && (area[yh1 - 1][xh1] == ' ' || area[yh1 - 1][xh1] == (char)250)) {
			lh1 = false;
			srand(time(NULL));
			way = rand() % 2;
			if (way == 1) {
				uh1 = true;
			}
			else { dh1 = true; }
		}
		else 	if (lh1 == true && area[yh1 + 1][xh1] != (char)250 && area[yh1 + 1][xh1] != ' ' && (area[yh1 - 1][xh1] == ' ' || area[yh1 - 1][xh1] == (char)250) && (area[yh1][xh1 - 1] == ' ' || area[yh1][xh1 - 1] == (char)250)) {
			lh1 = false;
			srand(time(NULL));
			way = rand() % 2;
			if (way == 1) {
				uh1 = true;
			}
			else { lh1 = true; }
		}
		else if (lh1 == true && area[yh1 - 1][xh1] != (char)250 && area[yh1 - 1][xh1] != ' ' && (area[yh1 + 1][xh1] == ' ' || area[yh1 + 1][xh1] == (char)250) && (area[yh1][xh1 - 1] == ' ' || area[yh1][xh1 - 1] == (char)250)) {
			lh1 = false;
			srand(time(NULL));
			way = rand() % 2;
			if (way == 1) {
				dh1 = true;
			}
			else { lh1 = true; }
		}
		else 	if (lh1 == true && area[yh1][xh1 - 1] != ' ' && area[yh1][xh1 - 1] != (char)250 && (area[yh1 + 1][xh1] == ' ' || area[yh1 + 1][xh1] == (char)250)) {
			lh1 = false;
			dh1 = true;
		}
		else 	if (lh1 == true && area[yh1][xh1 - 1] != ' ' && area[yh1][xh1 - 1] != (char)250 && (area[yh1 - 1][xh1] == ' ' || area[yh1 - 1][xh1] == (char)250)) {
			lh1 = false;
			uh1 = true;
		}
	/////////DOWN/////////
		if (dh1 == true && (area[yh1 + 1][xh1] == ' ' || area[yh1 + 1][xh1] == (char)250) && (area[yh1][xh1 + 1] == ' ' || area[yh1][xh1 + 1] == (char)250) && (area[yh1][xh1 - 1] == ' ' || area[yh1][xh1 - 1] == (char)250)) {
			dh1 = false;
			srand(time(NULL));
			way = rand() % 3;
			if (way == 0) {
				dh1 = true;
			}
			if (way == 1) {
				rh1 = true;
			}
			if (way == 2) {
				lh1 = true;
			}
		}
		else 	if (dh1 == true && area[yh1 + 1][xh1] != (char)250 && area[yh1 + 1][xh1] != ' ' && (area[yh1][xh1 - 1] == ' ' || area[yh1][xh1 - 1] == (char)250) && (area[yh1][xh1 + 1] == ' ' || area[yh1][xh1 + 1] == (char)250)) {
			dh1 = false;
			srand(time(NULL));
			way = rand() % 2;
			if (way == 1) {
				rh1 = true;
			}
			else { lh1 = true; }
		}
		else 	if (dh1 == true && area[yh1][xh1 + 1] != (char)250 && area[yh1][xh1 + 1] != ' ' && (area[yh1 + 1][xh1] == ' ' || area[yh1 + 1][xh1] == (char)250) && (area[yh1][xh1 - 1] == ' ' || area[yh1][xh1 - 1] == (char)250)) {
			dh1 = false;
			srand(time(NULL));
			way = rand() % 2;
			if (way == 1) {
				dh1 = true;
			}
			else { lh1 = true; }
		}
		else 	if (dh1 == true && area[yh1][xh1 - 1] != (char)250 && area[yh1][xh1 - 1] != ' ' && (area[yh1 + 1][xh1] == ' ' || area[yh1 + 1][xh1] == (char)250) && (area[yh1][xh1 + 1] == ' ' || area[yh1][xh1 + 1] == (char)250)) {
			dh1 = false;
			srand(time(NULL));
			way = rand() % 2;
			if (way == 1) {
				dh1 = true;
			}
			else { rh1 = true; }
		}
		else 	if (dh1 == true && area[yh1][xh1 - 1] != ' ' && area[yh1][xh1 - 1] != (char)250 && (area[yh1][xh1 + 1] == ' ' || area[yh1][xh1 + 1] == (char)250)) {
			dh1 = false;
			rh1 = true;
		}
		else if (dh1 == true && area[yh1][xh1 + 1] != ' ' && area[yh1][xh1 + 1] != (char)250 && (area[yh1][xh1 - 1] == ' ' || area[yh1][xh1 - 1] == (char)250)) {
			dh1 = false;
			lh1 = true;
		}
	/////////DOWN/////////

	if (uh1 == true) {
		yh1--;
	
	}
	else if (dh1 == true) {
		yh1++;
	}
	else if (xh1 == 14 && yh1 == 23) {
		xh1++;
	}
	else if (rh1 == true) {
		xh1++;
	}
	else if (lh1 == true) {
		xh1--;
	}
}
void ghost2(){
	if (xh2 == 14 && yh2 >= 10 && start == false) {

		uh2 = true;
		if (yh2 == 10) {
			start = true;
		}
	}

	/////////UP/////////
	if (uh2 == true && (area[yh2 - 1][xh2] == ' ' || area[yh2 - 1][xh2] == (char)250) && (area[yh2][xh2 + 1] == ' ' || area[yh2][xh2 + 1] == (char)250) && (area[yh2][xh2 - 1] == ' ' || area[yh2][xh2 - 1] == (char)250)) {
		uh2 = false;
		srand(time(NULL));
		way2 = rand() % 3;
		if (way2 == 0) {
			uh2 = true;
		}
		if (way2 == 1) {
			rh2 = true;
		}
		if (way2 == 2) {
			lh2 = true;
		}
	}
	else if (uh2 == true && area[yh2 - 1][xh2] != (char)250 && area[yh2 - 1][xh2] != ' ' && (area[yh2][xh2 - 1] == ' ' || area[yh2][xh2 - 1] == (char)250) && (area[yh2][xh2 + 1] == ' ' || area[yh2][xh2 + 1] == (char)250)) {
		uh2 = false;
		srand(time(NULL));
		way2 = rand() % 2;
		if (way2 == 1) {
			rh2 = true;
		}
		else { lh2 = true; }
	}
	else if (uh2 == true && area[yh2][xh2 + 1] != (char)250 && area[yh2][xh2 + 1] != ' ' && (area[yh2 - 1][xh2] == ' ' || area[yh2 - 1][xh2] == (char)250) && (area[yh2][xh2 - 1] == ' ' || area[yh2][xh2 - 1] == (char)250)) {
		uh2 = false;
		srand(time(NULL));
		way2 = rand() % 2;
		if (way2 == 1) {
			uh2 = true;
		}
		else { lh2 = true; }
	}
	else if (uh2 == true && area[yh2][xh2 - 1] != (char)250 && area[yh2][xh2 - 1] != ' ' && (area[yh2 - 1][xh2] == ' ' || area[yh2 - 1][xh2] == (char)250) && (area[yh2][xh2 + 1] == ' ' || area[yh2][xh2 + 1] == (char)250)) {
		uh2 = false;
		srand(time(NULL));
		way2 = rand() % 2;
		if (way2 == 1) {
			uh2 = true;
		}
		else { rh2 = true; }
	}
	else if (uh2 == true && area[yh2][xh2 - 1] != ' ' && area[yh2][xh2 - 1] != (char)250 && (area[yh2][xh2 + 1] == ' ' || area[yh2][xh2 + 1] == (char)250)) {
		uh2 = false;
		rh2 = true;
	}
	else if (uh2 == true && area[yh2][xh2 + 1] != ' ' && area[yh2][xh2 + 1] != (char)250 && (area[yh2][xh2 - 1] == ' ' || area[yh2][xh2 - 1] == (char)250)) {
		uh2 = false;
		lh2 = true;
	}
	/////////UP/////////



	/////////RIGHT/////////
	if (rh2 == true && (area[yh2 + 1][xh2] == ' ' || area[yh2 + 1][xh2] == (char)250) && (area[yh2 - 1][xh2] == ' ' || area[yh2 - 1][xh2] == (char)250) && (area[yh2][xh2 + 1] == ' ' || area[yh2][xh2 + 1] == (char)250)) {
		rh2 = false;
		srand(time(NULL));
		way2 = rand() % 3;
		if (way2 == 1) {
			uh2 = true;
		}
		else if (way2 == 0) { dh2 = true; }
		else { rh2 = true; }
	}
	else 		if (rh2 == true && area[yh2][xh2 + 1] != (char)250 && area[yh2][xh2 + 1] != ' ' && (area[yh2 + 1][xh2] == ' ' || area[yh2 + 1][xh2] == (char)250) && (area[yh2 - 1][xh2] == ' ' || area[yh2 - 1][xh2] == (char)250)) {
		rh2 = false;
		srand(time(NULL));
		way2 = rand() % 2;
		if (way2 == 1) {
			uh2 = true;
		}
		else { dh2 = true; }
	}
	else if (rh2 == true && area[yh2 + 1][xh2] != (char)250 && area[yh2 + 1][xh2] != ' ' && (area[yh2 - 1][xh2] == ' ' || area[yh2 - 1][xh2] == (char)250) && (area[yh2][xh2 + 1] == ' ' || area[yh2][xh2 + 1] == (char)250)) {
		rh2 = false;
		srand(time(NULL));
		way2 = rand() % 2;
		if (way2 == 1) {
			uh2 = true;
		}
		else { rh2 = true; }
	}
	else 	if (rh2 == true && area[yh2 + 1][xh2] != (char)250 && area[yh2 + 1][xh2] != ' ' && (area[yh2 + 1][xh2] == ' ' || area[yh2 + 1][xh2] == (char)250) && (area[yh2][xh2 + 1] == ' ' || area[yh2][xh2 + 1] == (char)250)) {
		rh2 = false;
		srand(time(NULL));
		way2 = rand() % 2;
		if (way2 == 1) {
			dh2 = true;
		}
		else { rh2 = true; }
	}
	else if (rh2 == true && area[yh2][xh2 + 1] != ' ' && area[yh2][xh2 + 1] != (char)250 && (area[yh2 + 1][xh2] == ' ' || area[yh2 + 1][xh2] == (char)250)) {
		rh2 = false;
		dh2 = true;
	}
	else	if (rh2 == true && area[yh2][xh2 + 1] != ' ' && area[yh2][xh2 + 1] != (char)250 && (area[yh2 - 1][xh2] == ' ' || area[yh2 - 1][xh2] == (char)250)) {
		rh2 = false;
		uh2 = true;
	}
	/////////RIGHT/////////



	/////////LEFT/////////
	if (lh2 == true && (area[yh2 + 1][xh2] == ' ' || area[yh2 + 1][xh2] == (char)250) && (area[yh2 - 1][xh2] == ' ' || area[yh2 - 1][xh2] == (char)250) && (area[yh2][xh2 - 1] == ' ' || area[yh2][xh2 - 1] == (char)250)) {
		lh2 = false;
		srand(time(NULL));
		way2 = rand() % 3;
		if (way2 == 1) {
			uh2 = true;
		}
		else if (way2 == 0) { dh2 = true; }
		else { lh2 = true; }
	}
	else 	if (lh2 == true && area[yh2][xh2 - 1] != (char)250 && area[yh2][xh2 - 1] != ' ' && (area[yh2 + 1][xh2] == ' ' || area[yh2 + 1][xh2] == (char)250) && (area[yh2 - 1][xh2] == ' ' || area[yh2 - 1][xh2] == (char)250)) {
		lh2 = false;
		srand(time(NULL));
		way2 = rand() % 2;
		if (way2 == 1) {
			uh2 = true;
		}
		else { dh2 = true; }
	}
	else 	if (lh2 == true && area[yh2 + 1][xh2] != (char)250 && area[yh2 + 1][xh2] != ' ' && (area[yh2 - 1][xh2] == ' ' || area[yh2 - 1][xh2] == (char)250) && (area[yh2][xh2 - 1] == ' ' || area[yh2][xh2 - 1] == (char)250)) {
		lh2 = false;
		srand(time(NULL));
		way2 = rand() % 2;
		if (way2 == 1) {
			uh2 = true;
		}
		else { lh2 = true; }
	}
	else if (lh2 == true && area[yh2 - 1][xh2] != (char)250 && area[yh2 - 1][xh2] != ' ' && (area[yh2 + 1][xh2] == ' ' || area[yh2 + 1][xh2] == (char)250) && (area[yh2][xh2 - 1] == ' ' || area[yh2][xh2 - 1] == (char)250)) {
		lh2 = false;
		srand(time(NULL));
		way2 = rand() % 2;
		if (way2 == 1) {
			dh2 = true;
		}
		else { lh2 = true; }
	}
	else 	if (lh2 == true && area[yh2][xh2 - 1] != ' ' && area[yh2][xh2 - 1] != (char)250 && (area[yh2 + 1][xh2] == ' ' || area[yh2 + 1][xh2] == (char)250)) {
		lh2 = false;
		dh2 = true;
	}
	else 	if (lh2 == true && area[yh2][xh2 - 1] != ' ' && area[yh2][xh2 - 1] != (char)250 && (area[yh2 - 1][xh2] == ' ' || area[yh2 - 1][xh2] == (char)250)) {
		lh2 = false;
		uh2 = true;
	}
	/////////DOWN/////////
	if (dh2 == true && (area[yh2 + 1][xh2] == ' ' || area[yh2 + 1][xh2] == (char)250) && (area[yh2][xh2 + 1] == ' ' || area[yh2][xh2 + 1] == (char)250) && (area[yh2][xh2 - 1] == ' ' || area[yh2][xh2 - 1] == (char)250)) {
		dh2 = false;
		srand(time(NULL));
		way2 = rand() % 3;
		if (way2 == 0) {
			dh2 = true;
		}
		if (way2 == 1) {
			rh2 = true;
		}
		if (way2 == 2) {
			lh2 = true;
		}
	}
	else 	if (dh2 == true && area[yh2 + 1][xh2] != (char)250 && area[yh2 + 1][xh2] != ' ' && (area[yh2][xh2 - 1] == ' ' || area[yh2][xh2 - 1] == (char)250) && (area[yh2][xh2 + 1] == ' ' || area[yh2][xh2 + 1] == (char)250)) {
		dh2 = false;
		srand(time(NULL));
		way2 = rand() % 2;
		if (way2 == 1) {
			rh2 = true;
		}
		else { lh2 = true; }
	}
	else 	if (dh2 == true && area[yh2][xh2 + 1] != (char)250 && area[yh2][xh2 + 1] != ' ' && (area[yh2 + 1][xh2] == ' ' || area[yh2 + 1][xh2] == (char)250) && (area[yh2][xh2 - 1] == ' ' || area[yh2][xh2 - 1] == (char)250)) {
		dh2 = false;
		srand(time(NULL));
		way2 = rand() % 2;
		if (way2 == 1) {
			dh2 = true;
		}
		else { lh2 = true; }
	}
	else 	if (dh2 == true && area[yh2][xh2 - 1] != (char)250 && area[yh2][xh2 - 1] != ' ' && (area[yh2 + 1][xh2] == ' ' || area[yh2 + 1][xh2] == (char)250) && (area[yh2][xh2 + 1] == ' ' || area[yh2][xh2 + 1] == (char)250)) {
		dh2 = false;
		srand(time(NULL));
		way2 = rand() % 2;
		if (way2 == 1) {
			dh2 = true;
		}
		else { rh2 = true; }
	}
	else 	if (dh2 == true && area[yh2][xh2 - 1] != ' ' && area[yh2][xh2 - 1] != (char)250 && (area[yh2][xh2 + 1] == ' ' || area[yh2][xh2 + 1] == (char)250)) {
		dh2 = false;
		rh2 = true;
	}
	else if (dh2 == true && area[yh2][xh2 + 1] != ' ' && area[yh2][xh2 + 1] != (char)250 && (area[yh2][xh2 - 1] == ' ' || area[yh2][xh2 - 1] == (char)250)) {
		dh2 = false;
		lh2 = true;
	}
	/////////DOWN/////////

	if (uh2 == true) {
		yh2--;

	}
	else if (dh2 == true) {
		yh2++;
	}
	else if (xh2 == 14 && yh2 == 23) {
		xh2++;
	}
	else if (rh2 == true) {
		xh2++;
	}
	else if (lh2 == true) {
		xh2--;
	}

}
void ghost3() {
	if (xh3 == 14 && yh3 >= 10 && start == false) {

		uh3 = true;
		if (yh3 == 10) {
			start = true;
		}
	}

	/////////UP/////////
	if (uh3 == true && (area[yh3 - 1][xh3] == ' ' || area[yh3 - 1][xh3] == (char)250) && (area[yh3][xh3 + 1] == ' ' || area[yh3][xh3 + 1] == (char)250) && (area[yh3][xh3 - 1] == ' ' || area[yh3][xh3 - 1] == (char)250)) {
		uh3 = false;
		srand(time(NULL));
		way3 = rand() % 3;
		if (way3 == 0) {
			uh3 = true;
		}
		if (way3 == 1) {
			rh3 = true;
		}
		if (way3 == 2) {
			lh3 = true;
		}
	}
	else if (uh3 == true && area[yh3 - 1][xh3] != (char)250 && area[yh3 - 1][xh3] != ' ' && (area[yh3][xh3 - 1] == ' ' || area[yh3][xh3 - 1] == (char)250) && (area[yh3][xh3 + 1] == ' ' || area[yh3][xh3 + 1] == (char)250)) {
		uh3 = false;
		srand(time(NULL));
		way3 = rand() % 2;
		if (way3 == 1) {
			rh3 = true;
		}
		else { lh3 = true; }
	}
	else if (uh3 == true && area[yh3][xh3 + 1] != (char)250 && area[yh3][xh3 + 1] != ' ' && (area[yh3 - 1][xh3] == ' ' || area[yh3 - 1][xh3] == (char)250) && (area[yh3][xh3 - 1] == ' ' || area[yh3][xh3 - 1] == (char)250)) {
		uh3 = false;
		srand(time(NULL));
		way3 = rand() % 2;
		if (way3 == 1) {
			uh3 = true;
		}
		else { lh3 = true; }
	}
	else if (uh3 == true && area[yh3][xh3 - 1] != (char)250 && area[yh3][xh3 - 1] != ' ' && (area[yh3 - 1][xh3] == ' ' || area[yh3 - 1][xh3] == (char)250) && (area[yh3][xh3 + 1] == ' ' || area[yh3][xh3 + 1] == (char)250)) {
		uh3 = false;
		srand(time(NULL));
		way3 = rand() % 2;
		if (way3 == 1) {
			uh3 = true;
		}
		else { rh3 = true; }
	}
	else if (uh3 == true && area[yh3][xh3 - 1] != ' ' && area[yh3][xh3 - 1] != (char)250 && (area[yh3][xh3 + 1] == ' ' || area[yh3][xh3 + 1] == (char)250)) {
		uh3 = false;
		rh3 = true;
	}
	else if (uh3 == true && area[yh3][xh3 + 1] != ' ' && area[yh3][xh3 + 1] != (char)250 && (area[yh3][xh3 - 1] == ' ' || area[yh3][xh3 - 1] == (char)250)) {
		uh3 = false;
		lh3 = true;
	}
	/////////UP/////////



	/////////RIGHT/////////
	if (rh3 == true && (area[yh3 + 1][xh3] == ' ' || area[yh3 + 1][xh3] == (char)250) && (area[yh3 - 1][xh3] == ' ' || area[yh3 - 1][xh3] == (char)250) && (area[yh3][xh3 + 1] == ' ' || area[yh3][xh3 + 1] == (char)250)) {
		rh3 = false;
		srand(time(NULL));
		way3 = rand() % 3;
		if (way3 == 1) {
			uh3 = true;
		}
		else if (way3 == 0) { dh3 = true; }
		else { rh3 = true; }
	}
	else 		if (rh3 == true && area[yh3][xh3 + 1] != (char)250 && area[yh3][xh3 + 1] != ' ' && (area[yh3 + 1][xh3] == ' ' || area[yh3 + 1][xh3] == (char)250) && (area[yh3 - 1][xh3] == ' ' || area[yh3 - 1][xh3] == (char)250)) {
		rh3 = false;
		srand(time(NULL));
		way3 = rand() % 2;
		if (way3 == 1) {
			uh3 = true;
		}
		else { dh3 = true; }
	}
	else if (rh3 == true && area[yh3 + 1][xh3] != (char)250 && area[yh3 + 1][xh3] != ' ' && (area[yh3 - 1][xh3] == ' ' || area[yh3 - 1][xh3] == (char)250) && (area[yh3][xh3 + 1] == ' ' || area[yh3][xh3 + 1] == (char)250)) {
		rh3 = false;
		srand(time(NULL));
		way3 = rand() % 2;
		if (way3 == 1) {
			uh3 = true;
		}
		else { rh3 = true; }
	}
	else 	if (rh3 == true && area[yh3 + 1][xh3] != (char)250 && area[yh3 + 1][xh3] != ' ' && (area[yh3 + 1][xh3] == ' ' || area[yh3 + 1][xh3] == (char)250) && (area[yh3][xh3 + 1] == ' ' || area[yh3][xh3 + 1] == (char)250)) {
		rh3 = false;
		srand(time(NULL));
		way3 = rand() % 2;
		if (way3 == 1) {
			dh3 = true;
		}
		else { rh3 = true; }
	}
	else if (rh3 == true && area[yh3][xh3 + 1] != ' ' && area[yh3][xh3 + 1] != (char)250 && (area[yh3 + 1][xh3] == ' ' || area[yh3 + 1][xh3] == (char)250)) {
		rh3 = false;
		dh3 = true;
	}
	else	if (rh3 == true && area[yh3][xh3 + 1] != ' ' && area[yh3][xh3 + 1] != (char)250 && (area[yh3 - 1][xh3] == ' ' || area[yh3 - 1][xh3] == (char)250)) {
		rh3 = false;
		uh3 = true;
	}
	/////////RIGHT/////////



	/////////LEFT/////////
	if (lh3 == true && (area[yh3 + 1][xh3] == ' ' || area[yh3 + 1][xh3] == (char)250) && (area[yh3 - 1][xh3] == ' ' || area[yh3 - 1][xh3] == (char)250) && (area[yh3][xh3 - 1] == ' ' || area[yh3][xh3 - 1] == (char)250)) {
		lh3 = false;
		srand(time(NULL));
		way3 = rand() % 3;
		if (way3 == 1) {
			uh3 = true;
		}
		else if (way3 == 0) { dh3 = true; }
		else { lh3 = true; }
	}
	else 	if (lh3 == true && area[yh3][xh3 - 1] != (char)250 && area[yh3][xh3 - 1] != ' ' && (area[yh3 + 1][xh3] == ' ' || area[yh3 + 1][xh3] == (char)250) && (area[yh3 - 1][xh3] == ' ' || area[yh3 - 1][xh3] == (char)250)) {
		lh3 = false;
		srand(time(NULL));
		way3 = rand() % 2;
		if (way3 == 1) {
			uh3 = true;
		}
		else { dh3 = true; }
	}
	else 	if (lh3 == true && area[yh3 + 1][xh3] != (char)250 && area[yh3 + 1][xh3] != ' ' && (area[yh3 - 1][xh3] == ' ' || area[yh3 - 1][xh3] == (char)250) && (area[yh3][xh3 - 1] == ' ' || area[yh3][xh3 - 1] == (char)250)) {
		lh3 = false;
		srand(time(NULL));
		way3 = rand() % 2;
		if (way3 == 1) {
			uh3 = true;
		}
		else { lh3 = true; }
	}
	else if (lh3 == true && area[yh3 - 1][xh3] != (char)250 && area[yh3 - 1][xh3] != ' ' && (area[yh3 + 1][xh3] == ' ' || area[yh3 + 1][xh3] == (char)250) && (area[yh3][xh3 - 1] == ' ' || area[yh3][xh3 - 1] == (char)250)) {
		lh3 = false;
		srand(time(NULL));
		way3 = rand() % 2;
		if (way3 == 1) {
			dh3 = true;
		}
		else { lh3 = true; }
	}
	else 	if (lh3 == true && area[yh3][xh3 - 1] != ' ' && area[yh3][xh3 - 1] != (char)250 && (area[yh3 + 1][xh3] == ' ' || area[yh3 + 1][xh3] == (char)250)) {
		lh3 = false;
		dh3 = true;
	}
	else 	if (lh3 == true && area[yh3][xh3 - 1] != ' ' && area[yh3][xh3 - 1] != (char)250 && (area[yh3 - 1][xh3] == ' ' || area[yh3 - 1][xh3] == (char)250)) {
		lh3 = false;
		uh3 = true;
	}
	/////////DOWN/////////
	if (dh3 == true && (area[yh3 + 1][xh3] == ' ' || area[yh3 + 1][xh3] == (char)250) && (area[yh3][xh3 + 1] == ' ' || area[yh3][xh3 + 1] == (char)250) && (area[yh3][xh3 - 1] == ' ' || area[yh3][xh3 - 1] == (char)250)) {
		dh3 = false;
		srand(time(NULL));
		way3 = rand() % 3;
		if (way3 == 0) {
			dh3 = true;
		}
		if (way3 == 1) {
			rh3 = true;
		}
		if (way3 == 2) {
			lh3 = true;
		}
	}
	else 	if (dh3 == true && area[yh3 + 1][xh3] != (char)250 && area[yh3 + 1][xh3] != ' ' && (area[yh3][xh3 - 1] == ' ' || area[yh3][xh3 - 1] == (char)250) && (area[yh3][xh3 + 1] == ' ' || area[yh3][xh3 + 1] == (char)250)) {
		dh3 = false;
		srand(time(NULL));
		way3 = rand() % 2;
		if (way3 == 1) {
			rh3 = true;
		}
		else { lh3 = true; }
	}
	else 	if (dh3 == true && area[yh3][xh3 + 1] != (char)250 && area[yh3][xh3 + 1] != ' ' && (area[yh3 + 1][xh3] == ' ' || area[yh3 + 1][xh3] == (char)250) && (area[yh3][xh3 - 1] == ' ' || area[yh3][xh3 - 1] == (char)250)) {
		dh3 = false;
		srand(time(NULL));
		way3 = rand() % 2;
		if (way3 == 1) {
			dh3 = true;
		}
		else { lh3 = true; }
	}
	else 	if (dh3 == true && area[yh3][xh3 - 1] != (char)250 && area[yh3][xh3 - 1] != ' ' && (area[yh3 + 1][xh3] == ' ' || area[yh3 + 1][xh3] == (char)250) && (area[yh3][xh3 + 1] == ' ' || area[yh3][xh3 + 1] == (char)250)) {
		dh3 = false;
		srand(time(NULL));
		way3 = rand() % 2;
		if (way3 == 1) {
			dh3 = true;
		}
		else { rh3 = true; }
	}
	else 	if (dh3 == true && area[yh3][xh3 - 1] != ' ' && area[yh3][xh3 - 1] != (char)250 && (area[yh3][xh3 + 1] == ' ' || area[yh3][xh3 + 1] == (char)250)) {
		dh3 = false;
		rh3 = true;
	}
	else if (dh3 == true && area[yh3][xh3 + 1] != ' ' && area[yh3][xh3 + 1] != (char)250 && (area[yh3][xh3 - 1] == ' ' || area[yh3][xh3 - 1] == (char)250)) {
		dh3 = false;
		lh3 = true;
	}
	/////////DOWN/////////

	if (uh3 == true) {
		yh3--;

	}
	else if (dh3 == true) {
		yh3++;
	}
	else if (xh3 == 14 && yh3 == 23) {
		xh3++;
	}
	else if (rh3 == true) {
		xh3++;
	}
	else if (lh3 == true) {
		xh3--;
	}
}
void move() {
	while (_kbhit()) {
		switch (_getch())
		{
		case 'a': {
		
			leftp = true;
			rightp = false;
			up = false;
			downp = false;
			active = 1;
			if (area[yp][xp - 1] != ' ' && area[yp][xp - 1] != (char)253 && area[yp][xp - 1] != (char)250 && leftp == true) {
				leftp = false;
				active = 0;
			}
			break;
		}



		case 'w': {
	
			up = true;
			rightp = false;
			downp = false;
			leftp = false;
			active = 1;
			if (area[yp - 1][xp] != ' ' && area[yp - 1][xp] != (char)253 && area[yp - 1][xp] != (char)250 && up == true) {
				up = false;
				active = 0;
			}
			break;
		}	
		case 'd': {
	
			rightp = true;
			leftp = false;
			up = false;
			downp = false;
			active = 1;
			if (area[yp][xp + 1] != ' ' && area[yp][xp + 1] != (char)253 && area[yp][xp + 1] != (char)250 && rightp == true) {
				rightp = false;
				active = 0;
			}
			break;
		}



		case 's': {
			
			downp = true;
			rightp = false;
			leftp = false;
			up = false;
			active = 1;
			if (area[yp + 1][xp] != ' ' && area[yp + 1][xp] != (char)253 && area[yp + 1][xp] != (char)250 && downp == true) {
				downp = false;
				active = 0;
			}
			break;
		}
		default:
			break;
		}
	}
}
void draw() {
	
	
	
	if (up == true) {
		yp--;
	}
	else if (downp == true) {
		yp++;
	}
	else if (rightp == true) {
		xp++;
	}
	else if (leftp == true) {
		xp--;
	}
	if (area[yp][xp] == (char)250) {
		score += 10;
		area[yp][xp] = ' ';
	}
	if (area[yp][xp] == (char)253) {
		score += 50;
		area[yp][xp] = ' ';
		rage = true;
	
	}
	if (active == 1) {
		if (area[yp][xp + 1] != ' ' && area[yp][xp + 1] != (char)253 && area[yp][xp + 1] != (char)250 && rightp == true) {
			rightp = false;
			active = 0;
		}
		if (area[yp][xp-1] != ' '  && area[yp][xp-1] != (char)253 && area[yp][xp-1] != (char)250 && leftp == true) {
			leftp = false;
			active = 0;
		}
		if (area[yp+1][xp] != ' ' && area[yp+1][xp] != (char)253  && area[yp+1][xp] != (char)250 && downp == true) {
			downp = false;
			active = 0;
		}
		if (area[yp-1][xp] != ' '  && area[yp-1][xp] != (char)253  && area[yp-1][xp] != (char)250 && up == true) {
			up = false;
			active = 0;
		}
	}
	if (xp == 27 && yp == 14) {
		xp = 1;
		yp = 14;
	}
	else if (xp == 0 && yp == 14) {
		xp = 26;
		yp = 14;
	}
	/////////1////////////
	if (xh1 == 27 && yh1 == 14) {
		xh1 = 1;
		yh1 = 14;
	}
	else if (xh1 == 0 && yh1 == 14) {
		xh1 = 26;
		yh1 = 14;
	}
	if (rage == true) {
		timerage += 125;

	}
	if (timerage == 5000) {
		timerage = 0;
		rage = false;
	}
	if (rage == true && xp == xh1 && yp == yh1) {
		score += 100;
		xh1 = 14;
		yh1 = 15;
		
	}
	/////////1////////////
	///////2/////////
	if (xh2 == 27 && yh2 == 14) {
		xh2 = 1;
		yh2 = 14;
	}
	else if (xh2 == 0 && yh2 == 14) {
		xh2 = 26;
		yh2 = 14;
	}
	if (rage == true) {
		timerage += 125;

	}
	if (timerage == 5000) {
		timerage = 0;
		rage = false;
	}
	if (rage == true && xp == xh2 && yp == yh2) {
		score += 100;
		xh2 = 14;
		yh2 = 15;

	}
	////////2//////
	///////3////////////
	if (xh3 == 27 && yh3 == 14) {
		xh3 = 1;
		yh3 = 14;
	}
	else if (xh3 == 0 && yh3 == 14) {
		xh3 = 26;
		yh3 = 14;
	}
	if (rage == true) {
		timerage += 125;

	}
	if (timerage == 5000) {
		timerage = 0;
		rage = false;
	}
	if (rage == true && xp == xh3 && yp == yh3) {
		score += 100;
		xh3 = 14;
		yh3 = 15;

	}
	/////////3////////////
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j == xh1 && i == yh1) {
				if (rage == true) {
					HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); /////////////////////////////////////////////////////////////
					SetConsoleTextAttribute(h, 9);

					cout << (char)254;
				}
				else {
					HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); /////////////////////////////////////////////////////////////
					SetConsoleTextAttribute(h, 2);

					cout << (char)254;
				}
			}
			else	if (j == xh2 && i == yh2) {
				if (rage == true) {
					HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); /////////////////////////////////////////////////////////////
					SetConsoleTextAttribute(h, 9);

					cout << (char)254;
				}
				else {
					HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); /////////////////////////////////////////////////////////////
					SetConsoleTextAttribute(h, 4);

					cout << (char)254;
				}
			}
			else	if (j == xh3 && i == yh3) {
				if (rage == true) {
					HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); /////////////////////////////////////////////////////////////
					SetConsoleTextAttribute(h, 9);

					cout << (char)254;
				}
				else {
					HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); /////////////////////////////////////////////////////////////
					SetConsoleTextAttribute(h, 11);

					cout << (char)254;
				}
			}
			else if (i == yp && j == xp) {
					HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(h, colour);

					cout << (char)254;
				}
			else if (area[i][j] == (char)253) {
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(h, 15);
				cout << (char)253;
			}
			else if (area[i][j] == (char)250) {
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(h, 15);
				cout << (char)249;
			}
			else {
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(h, 3);
				if (area[i][j] == (char)249 || area[i][j] == (char)253) {
					continue;
				}
				else {
					cout << area[i][j];
				}
			}
		}
		cout<<endl;
	}
	cout << "SCORE: " << score<<"  Left:"<<304-score/10<<"  LIVES:"<<lives;
}



int main()
{
	ifstream fout("score.txt");
		while (!fout.eof()) {
			fout >> temp;
		}
		if (temp != ' ') {
			best = true;
		}
		fout.close();
	do {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 
		SetConsoleTextAttribute(h, 9);
		cout << "\t1)Play" << endl;
		SetConsoleTextAttribute(h, 2);
		cout << "\t2)Best score" << endl;
		SetConsoleTextAttribute(h, 3);
		cout << "\t3)Delete best score" << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "\t4)Exit" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1: {
			
			SetConsoleTitleA("PACKMAN");
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_CURSOR_INFO info;
			info.bVisible = false;
			info.dwSize = 100;
			SetConsoleCursorInfo(h, &info);
			system("mode con cols=40 lines=40");
			//РИСОВКА ПОЛЯ ИГРЫ 
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					///////////////////////////////////////////
					if (i == 9 && j == 0) {
						area[i][j] = (char)200;
					}
					else if (i == 9 && j > 0 && j < 5) {
						area[i][j] = (char)205;

					}
					else if (i == 9 && j == 5) {
						area[i][j] = (char)187;
					}
					else if (i > 9 && i < 13 && j == 5) {
						area[i][j] = (char)186;
					}
					else if (i == 13 && j == 5) {
						area[i][j] = (char)188;
					}
					else if (i == 13 && j >= 0 && j < 5) {
						area[i][j] = (char)205;
					}
					else if (i > 9 && i < 13 && j >= 0 && j < 5) {
						area[i][j] = ' ';
					}
					else if (i > 13 && i < 15 && j >= 0 && j < 6) {
						area[i][j] = ' ';
					}
					else if (i == 15 && j >= 0 && j < 5) {
						area[i][j] = (char)205;
					}
					else if (i == 15 && j == 5) {
						area[i][j] = (char)187;
					}
					///////////////////////////////////////////
					else if (i == 0 && j == 0) {
						area[i][j] = (char)201;

					}
					else if (i == 0 && j > 0 && j < 13) {
						area[i][j] = (char)205;

					}
					else if (i == 0 && j == 13) {
						area[i][j] = (char)187;

					}
					else if (i > 0 && i < 4 && j == 13) {
						area[i][j] = (char)186;

					}
					else if (i == 4 && j == 13) {
						area[i][j] = (char)200;

					}
					else if (i > 0 && i < 4 && j == 14) {
						area[i][j] = (char)186;

					}
					else if (i == 0 && j == 14) {
						area[i][j] = (char)201;

					}
					else if (i == 0 && j == 27) {
						area[i][j] = (char)187;

					}
					else if (i == 0 && j > 14 && j < 27) {
						area[i][j] = (char)205;

					}
					else if (i == 30 && j == 0) {
						area[i][j] = (char)200;

					}
					else if (i == 30 && j > 0 && j < 27) {
						area[i][j] = (char)205;

					}
					else if (i == 30 && j == 27) {
						area[i][j] = (char)188;

					}
					else if (i == 4 && j == 14) {
						area[i][j] = (char)188;

					}
					else if (i == 2 && j == 5) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 2 && j == 2) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 2 && j == 3 || i == 2 && j == 4) {
						area[i][j] = (char)205;
						//═
					}
					else if (i == 3 && j == 3 || i == 3 && j == 4) {
						area[i][j] = (char)219;
						//inner
					}
					else if (i == 3 && j == 2 || i == 3 && j == 5) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 4 && j == 2) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 4 && j == 5) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 4 && j == 3 || i == 4 && j == 4) {
						area[i][j] = (char)205;
						//═
					}
					//------------------------------------------------------------------------------
					else if (i == 6 && j == 5) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 6 && j == 2) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 6 && j == 3 || i == 6 && j == 4) {
						area[i][j] = (char)205;
						//═
					}


					else if (i == 7 && j == 2) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 7 && j == 5) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 7 && j == 3 || i == 7 && j == 4) {
						area[i][j] = (char)205;
						//═
					}
					//////////////////////////////////////////////////////////////////////
					else if (i == 6 && j == 25) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 6 && j == 22) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 6 && j == 23 || i == 6 && j == 24) {
						area[i][j] = (char)205;
						//═
					}


					else if (i == 7 && j == 22) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 7 && j == 25) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 7 && j == 23 || i == 7 && j == 24) {
						area[i][j] = (char)205;
						//═
					}

					//////////////////////////////////////////////////////////////////////////
					else if (i == 6 && j == 8) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 9 && j == 8) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 9 && j == 11) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 6 && j == 7) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 10 && j == 8) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 9 && j == 9 || i == 9 && j == 10) {
						area[i][j] = (char)205;
						//═
					}
					else if (i == 10 && j == 11) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 13 && j == 8) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i > 6 && i < 13 && j == 7 || i>6 && i < 9 && j == 8 || i>10 && i < 13 && j == 8) {
						area[i][j] = (char)186;
						//║
					}

					else if (i == 13 && j == 7) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 7 && j == 24) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 7 && j == 22 || i == 7 && j == 23) {
						area[i][j] = (char)205;
						//═
					}
					else if (i == 10 && j == 9 || i == 10 && j == 10) {
						area[i][j] = (char)205;
						//═
					}
					//////////////////////////////////////////////////////////////////////////////
					else if (i == 6 && j == 17) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 10 && j == 13) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 7 && j == 13) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 7 && j == 14) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 6 && j == 10) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 6 && j < 17 && j>10 || i == 7 && j < 16 && j>14 || i == 7 && j < 13 && j>10 || i == 7 && j == 16) {
						area[i][j] = (char)205;
						//═
					}
					else if (i == 7 && j == 17) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 10 && j == 14) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i > 7 && i < 10 && j == 13 || i>7 && i < 10 && j == 14) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 7 && j == 10) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 13 && j == 7) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 7 && j == 24) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 7 && j == 22 || i == 7 && j == 23) {
						area[i][j] = (char)205;
						//═
					}
					else if (i == 10 && j == 9 || i == 10 && j == 10) {
						area[i][j] = (char)205;
						//═
					}
					///////////////////////////////////////////////////////////////////////////////
					else if (i == 9 && j == 27) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 9 && j < 27 && j>22 || i == 13 && j < 27 && j>22 || i == 15 && j < 27 && j>22) {
						area[i][j] = (char)205;
						//═
					}
					else if (i == 9 && j == 22 || i == 15 && j == 22) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i > 9 && i <= 12 && j == 22) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 13 && j == 22) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 13 && j == 27 || i == 15 && j == 27) {
						area[i][j] = (char)205;
						//═
					}
					else if (i > 9 && i < 13 && j>22 && j <= 27 || i > 13 && i < 15 && j >= 22 && j <= 27) {
						area[i][j] = ' ';

					}

					//////////////////////////////////////////////////////////////////////////////
					else if (i == 16 && j == 10) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 12 && j == 17) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 12 && j == 10) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 16 && j == 17) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i > 12 && i < 16 && j == 10 || i > 12 && i < 16 && j == 17) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 12 && j > 10 && j < 13 || i == 16 && j >= 11 && j <= 16 || i == 12 && j >= 15 && j < 17) {
						area[i][j] = (char)205;
						//═
					}
					else if (i > 12 && i < 16 && j>10 && j <= 17 || i == 12 && j == 14 || i == 12 && j == 13) {
						area[i][j] = ' ';

					}
					///////////////////////////////////////////////////////////////////////////////
					else if (i == 6 && j == 20) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 13 && j == 19) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 10 && j == 19) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 9 && j == 16) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 6 && j == 19) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 9 && j == 18 || i == 10 && j == 18 || i == 10 && j == 17 || i == 9 && j == 17) {
						area[i][j] = (char)205;
						//═
					}
					else if (i == 9 && j == 19) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 13 && j == 20) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i > 6 && i < 13 && j == 20 || i>6 && i < 9 && j == 19 || i>10 && i < 13 && j == 19) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 10 && j == 16) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 13 && j == 8) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 7 && j == 25) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 7 && j == 23 || i == 7 && j == 24) {
						area[i][j] = (char)205;
						//═
					}
					else if (i == 10 && j == 10 || i == 10 && j == 11) {
						area[i][j] = (char)205;
						//═
					}
					/////////////////////////////////////////////////////////////////////////////////
					else if (i == 2 && j == 25) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 2 && j == 21) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 2 && j == 22 || i == 2 && j == 21 || i == 2 && j == 23 || i == 2 && j == 24) {
						area[i][j] = (char)205;
						//═
					}
					else if (i == 3 && j == 22 || i == 3 && j == 23 || i == 3 && j == 24) {
						area[i][j] = (char)219;
						//inner
					}
					else if (i == 3 && j == 21 || i == 3 && j == 25) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 4 && j == 21) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 4 && j == 25) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 4 && j == 22 || i == 4 && j == 23 || i == 4 && j == 24) {
						area[i][j] = (char)205;
						//═
					}
					else if (j == 0 || j == n - 1) {
						area[i][j] = (char)186;
					}
					/////////////////////////////////////////////////////////////////////////////////
					else if (i == 2 && j == 11) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 2 && j == 7) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 2 && j == 8 || i == 2 && j == 9 || i == 2 && j == 10) {
						area[i][j] = (char)205;
						//═
					}
					else if (i == 3 && j == 8 || i == 3 && j == 9 || i == 3 && j == 10) {
						area[i][j] = (char)219;
						//inner
					}
					else if (i == 3 && j == 7 || i == 3 && j == 11) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 4 && j == 7) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 4 && j == 11) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 4 && j == 8 || i == 4 && j == 9 || i == 4 && j == 10) {
						area[i][j] = (char)205;
						//═
					}
					else if (j == 0 || j == n - 1) {
						area[i][j] = (char)186;
					}

					else area[i][j] = (char)250;
					/////////////////////////////////////////////////////////////////////////////////
					if (i == 15 && j == 20) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 15 && j == 19) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i > 15 && i < 19 && j == 19 || i >15 && i < 19 && j == 20) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 19 && j == 19) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 19 && j == 20) {
						area[i][j] = (char)188;
						//╝
					}
					////////////////////////////////////////////////////////////////////////////////
					if (i == 15 && j == 8) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 15 && j == 7) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i > 15 && i < 19 && j == 8 || i >15 && i < 19 && j == 7) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 19 && j == 7) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 19 && j == 8) {
						area[i][j] = (char)188;
						//╝
					}
					//////////////////////////////////////////////////////////////////////////////////
					else if (i == 18 && j == 17) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 22 && j == 13) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 19 && j == 13) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 19 && j == 14) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 18 && j == 10) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 18 && j < 17 && j>10 || i == 19 && j < 16 && j>14 || i == 19 && j < 13 && j>10 || i == 19 && j == 16) {
						area[i][j] = (char)205;
						//═
					}
					else if (i == 19 && j == 17) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 22 && j == 14) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i > 18 && i < 22 && j == 13 || i>18 && i < 22 && j == 14) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 19 && j == 10) {
						area[i][j] = (char)200;
						//╚
					}
					///////////////////////////////////////////////////////////////////////////////
					else if (i == 24 && j == 17) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 28 && j == 13) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 25 && j == 13) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 25 && j == 14) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 24 && j == 10) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 24 && j < 17 && j>10 || i == 25 && j < 16 && j>14 || i == 25 && j < 13 && j>10 || i == 25 && j == 16) {
						area[i][j] = (char)205;
						//═
					}
					else if (i == 25 && j == 17) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 28 && j == 14) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i > 24 && i < 28 && j == 13 || i>24 && i < 28 && j == 14) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 25 && j == 10) {
						area[i][j] = (char)200;
						//╚
					}
					////////////////////////////////////////////////////////////////////////////////
					else if (i == 21 && j == 11) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 21 && j == 7) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 21 && j > 7 && j < 11) {
						area[i][j] = (char)205;
						//═
					}


					else if (i == 22 && j == 7) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 22 && j == 11) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 22 && j > 7 && j < 11) {
						area[i][j] = (char)205;
						//═
					}
					/////////////////////////////////////////////////////////////////////////////////
					else if (i == 21 && j == 20) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 21 && j == 16) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 21 && j > 16 && j < 20) {
						area[i][j] = (char)205;
						//═
					}


					else if (i == 22 && j == 16) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 22 && j == 20) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 22 && j > 16 && j < 20) {
						area[i][j] = (char)205;
						//═
					}
					////////////////////////////////////////////////////////////////////////////////
					else if (i > 15 && j == 5 && i < 19) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 19 && j == 5) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 19 && j > 0 && j < 5) {
						area[i][j] = (char)205;
						//═
					}
					else if (i == 19 && j == 0) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i > 15 && i < 19 && j >= 0 && j < 5) {
						area[i][j] = ' ';
					}
					////////////////////////////////////////////////////////////////////////////////
					else if (i > 15 && j == 22 && i < 19) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 19 && j == 22) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 19 && j > 22 && j < 27) {
						area[i][j] = (char)205;
						//═
					}
					if (i == 19 && j == 27) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i > 15 && i < 19 && j > 22 && j <= 27) {
						area[i][j] = ' ';
					}
					///////////////////////////////////////////////////////////////////////////////
					if (i == 21 && j == 25) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 21 && j > 22 && j < 25 || i == 22 && j == 24) {
						area[i][j] = (char)205;
						//═
					}
					else if (i == 21 && j == 22) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i > 21 && j == 22 && i < 25 || i > 22 && j == 23 && i < 25) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 22 && j == 23) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 22 && j == 25) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 25 && j == 22) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 25 && j == 23) {
						area[i][j] = (char)188;
						//╝
					}
					////////////////////////////////////////////////////////////////////////////////
					if (i == 21 && j == 5) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 21 && j > 2 && j < 5 || i == 22 && j == 3) {
						area[i][j] = (char)205;
						//═
					}
					else if (i == 21 && j == 22) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i > 21 && j == 5 && i < 25 || i > 22 && j == 4 && i < 25) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 21 && j == 2) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 25 && j == 5) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 25 && j == 4) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 22 && j == 4) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 22 && j == 2) {
						area[i][j] = (char)200;
						//╚
					}
					////////////////////////////////////////////////////////////////////////////////
					else if (i == 24 && j == 27) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 24 && j == 25) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 25 && j == 25) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 25 && j == 27) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 24 && j == 26 || i == 25 && j == 26) {
						area[i][j] = (char)205;
						//═
					}
					////////////////////////////////////////////////////////////////////////////////
					else if (i == 24 && j == 2) {
						area[i][j] = (char)187;
						//╗
					}

					else if (i == 24 && j == 1 || i == 25 && j == 1) {
						area[i][j] = (char)205;
						//═
					}

					else if (i == 25 && j == 2) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 24 && j == 0) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 25 && j == 0) {
						area[i][j] = (char)201;
						//╔
					}
					////////////////////////////////////////////////////////////////////////////////
					else if (i == 24 && j == 19) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 24 && j == 20) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 27 && j == 16) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 27 && j == 25) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 28 && j > 16 && j < 25 || i == 27 && j > 16 && j < 19 || i == 27 && j > 20 && j < 25) {
						area[i][j] = (char)205;
						//═
					}
					else if (i > 24 && i < 27 && j == 19 || i>24 && i < 27 && j == 20) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 27 && j == 20) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 27 && j == 19) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 28 && j == 16) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 28 && j == 25) {
						area[i][j] = (char)188;
						//╝
					}
					////////////////////////////////////////////////////////////////////////////////
					else if (i == 24 && j == 7) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 24 && j == 8) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 27 && j == 2) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 27 && j == 11) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 28 && j > 2 && j < 11 || i == 27 && j > 2 && j < 7 || i == 27 && j > 8 && j < 11) {
						area[i][j] = (char)205;
						//═
					}
					else if (i > 24 && i < 27 && j == 7 || i>24 && i < 27 && j == 8) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 27 && j == 8) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 27 && j == 7) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 28 && j == 2) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 28 && j == 11) {
						area[i][j] = (char)188;
						//╝
					}
					/////////////////////////////////////////////////////////////////////////////////
					if (i == 2 && j == 19) {
						area[i][j] = (char)187;
						//╗
					}
					else if (i == 2 && j == 16) {
						area[i][j] = (char)201;
						//╔
					}
					else if (i == 2 && j == 19 || i == 2 && j == 18 || i == 2 && j == 17) {
						area[i][j] = (char)205;
						//═
					}
					else if (i == 3 && j == 17 || i == 3 && j == 18) {
						area[i][j] = (char)219;
						//inner
					}
					else if (i == 3 && j == 16 || i == 3 && j == 19) {
						area[i][j] = (char)186;
						//║
					}
					else if (i == 4 && j == 16) {
						area[i][j] = (char)200;
						//╚
					}
					else if (i == 4 && j == 19) {
						area[i][j] = (char)188;
						//╝
					}
					else if (i == 4 && j == 17 || i == 4 && j == 18) {
						area[i][j] = (char)205;
						//═
					}
					///////////////////////////////////////////////////////////
					//////////////////////////////////////////////////////////////////////////
					area[3][26] = (char)253;
					area[3][1] = (char)253;
					area[23][26] = (char)253;
					area[23][1] = (char)253;
				}
			}
			//РИСОВКА ПОЛЯ ИГРЫ 

			uh1 = true;
			uh2 = true;
			uh3 = true;
			while (true)
			{
				setcur(0, 0);
				Sleep(100);
				draw();
				ghost1();
				ghost2();
				ghost3();
				move();

				if (xp == xh1 && yp == yh1) {
					lives--;
				}
				
				if (xp == xh2 && yp == yh2) {
					lives--;
				}
				if (xp == xh3 && yp == yh3) {
					lives--;
				}
				if (304-score/10==0) { gameover = 1; break; }
				if (lives == 0) { gameover == 0; break; }
			}
			if (gameover == 1) {
				system("cls");
				/*█───█─███─█──█
				  █───█──█──██─█
				  █─█─█──█──█─██
				  █████──█──█──█
				─  █─█──███─█──█*/
				cout << (char)219 << "   " << (char)219 << " " << (char)219 << (char)219 << (char)219 << " " << (char)219 << "  " << (char)219 << endl;
				cout << (char)219 << "   " << (char)219 << "  " << (char)219 << "  " << (char)219 << (char)219 << " " << (char)219 << endl;
				cout << (char)219 << " " << (char)219 << " " << (char)219 << "  " << (char)219 << "  " << (char)219 << " " << (char)219 << (char)219 << endl;
				cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << "  " << (char)219 << "  " << (char)219 << endl;
				cout << " " << (char)219 << " " << (char)219 << "  " << (char)219 << (char)219 << (char)219 << " " << (char)219 << "  " << (char)219 << endl;
			}
			else {
				system("cls");
				cout << (char)219 << (char)219 << (char)219 << (char)219 << " " << (char)219 << (char)219 << (char)219 << (char)219 << " " << (char)219 << "   " << (char)219 << " " << (char)219 << (char)219 << (char)219;
				cout << endl;
				cout << (char)219 << "    " << (char)219 << "  " << (char)219 << " " << (char)219 << (char)219 << " " << (char)219 << (char)219 << " " << (char)219 << endl;
				cout << (char)219 << " " << (char)219 << (char)219 << " " << (char)219 << (char)219 << (char)219 << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << (char)219 << (char)219 << endl;
				cout << (char)219 << "  " << (char)219 << " " << (char)219 << "  " << (char)219 << " " << (char)219 << "   " << (char)219 << " " << (char)219 << endl;
				cout << (char)219 << (char)219 << (char)219 << (char)219 << " " << (char)219 << "  " << (char)219 << " " << (char)219 << "   " << (char)219 << " " << (char)219 << (char)219 << (char)219 << endl;
				cout << endl;
				/* ████─████─█───█─███
				   █────█──█─██─██─█
				   █─██─████─█─█─█─███
				   █──█─█──█─█───█─█
				   ████─█──█─█───█─███


			████─█─█─███─████
			█──█─█─█─█───█──█
			█──█─█─█─███─████
			█──█─███─█───█─█
			████──█──███─█─█*/

				cout << (char)219 << (char)219 << (char)219 << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << (char)219 << (char)219 << " " << (char)219 << (char)219 << (char)219 << (char)219 << endl;
				cout << (char)219 << "  " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << "   " << (char)219 << "  " << (char)219 << endl;
				cout << (char)219 << "  " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << (char)219 << (char)219 << " " << (char)219 << (char)219 << (char)219 << (char)219 << endl;
				cout << (char)219 << "  " << (char)219 << " " << (char)219 << (char)219 << (char)219 << " " << (char)219 << "   " << (char)219 << " " << (char)219 << endl;
				cout << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << "  " << (char)219 << (char)219 << (char)219 << " " << (char)219 << " " << (char)219 << endl;
				cout << "SCORE: " << score;
				Sleep(2000);
			}
			system("cls");

			ifstream fout("score.txt");
			while (!fout.eof()) {
				fout >> best_score;
			}
			fout.close();
			
			if (score > best_score) {
			
				ofstream fout("score.txt");
				fout << score;
				fout.close();
			}
		
				break;
			
		}
		case 2: {
			if (best == false) {
				cout << "Error!!!";
				Sleep(500);
				system("cls");
				break;
			}
			else {
				system("cls");
				ifstream fout("score.txt");
				fout >> best_score;
				cout << best_score;
				fout.close();
			}
			Sleep(6000);
			system("cls");
			break;
		}
		case 3: {
			ofstream fout("score.txt");
			fout << ' ';
			fout.close();
			system("cls");
		}
		default:
			break;
		}
	} while (choose != 4);
	return 0;
}
/*

176░
177▒
178▓
179│
180┤
181╡
182╢
183╖
184╕
185╣
186║++++++++++++
187╗+++++++++++++++++++++
188╝+++++++++++++++++++
189╜
190╛
191┐
192└
193┴
194┬
195├
196─
197┼
198╞
199╟
200╚++++++++++++++++++++++++
201╔+++++++++++++++++++++
202╩++++++++++++++++++
203╦++++++++++++++
204╠
205═+++++++++++++++++++
206╬
207╧
208╨
209╤
210╥
211╙
212╘
213╒
214╓
215╫
216╪
217┘
218┌
219█
220▄
221▌
222▐
223▀
248°
249∙
250·
251√
252№
253¤
254■
*/
/*for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

		}
	}
	*/
/*

box 4x3


else if (i == 2 && j == 5) {
				area[i][j] = (char)187;
				//╗
			}
			else if (i == 2 && j == 2) {
				area[i][j] = (char)201;
				//╔
			}
			else if (i == 2 && j == 3|| i == 2 && j==4) {
				area[i][j] = (char)205;
				//═
			}
			else if (i == 3 && j == 3 || i == 3 && j == 4) {
				area[i][j] = (char)219;
				//inner
			}
			else if (i == 3 && j == 2 || i == 3 && j == 5) {
				area[i][j] = (char)186;
				//║
			}
			else if (i == 4 && j == 2 ) {
				area[i][j] = (char)200;
				//╚
			}
			else if (i == 4 && j == 5) {
				area[i][j] = (char)188;
				//╝
			}
			else if (i == 4 && j == 3 || i == 4 && j == 4) {
				area[i][j] = (char)205;
				//═
			}*/
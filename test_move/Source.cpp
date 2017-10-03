#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>
#include <time.h>
#include <algorithm>
#include <glut.h>

using namespace std;

#pragma region Definitions

class monsters
{
public:
	float speed;
	float ypos, xpos;

};
int rightmmm = 0;
int p = 3;
int lives = 3;
int score = 0;
int startcircle = 10, endcircle = 110;
float posX = 3.75f, posY = 3.75f, radius = 3.0f;
int flagright = 0, flagleft = 0;
float move_unit = 0.5f;

int r1, r2;
int thingNum = 0;
int thingTotal = 4;
int width = 1;
int rwall = 0;
int flag = 0;
int w = 6;

monsters monster1;
monsters monster2;
monsters monster3;
monsters monster4;
int countm4 = 0;
int rm1, rm2, rm3, rm4;
int flag_moving1 = 0;
int flag_moving2 = 0;
int flag_moving3 = 0;
int flag_moving4 = 0;

int arr[45][42] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1 },
	{ 1,3,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,2,0,3,1 },
	{ 1,3,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,3,3,3,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,1 },
	{ 1,3,0,3,1,1,1,1,1,1,1,1,1,1,1,1,1,3,0,3,1,1,3,0,3,1,1,1,1,1,1,1,1,1,1,1,1,1,3,0,3,1 },
	{ 1,3,2,3,3,3,3,3,3,3,3,3,1,3,3,3,3,3,2,3,1,1,3,2,3,3,3,3,3,1,3,3,3,3,3,3,3,3,3,2,3,1 },
	{ 1,3,0,2,0,2,0,2,0,2,0,3,1,3,0,2,0,2,0,3,1,1,3,0,2,0,2,0,3,1,3,0,2,0,2,4,2,0,2,0,3,1 },
	{ 1,3,3,3,3,3,2,3,3,3,2,3,1,3,2,3,3,3,3,3,1,1,3,3,3,3,3,2,3,1,3,2,3,3,3,2,3,3,3,3,3,1 },
	{ 1,1,1,1,1,3,2,3,1,3,2,3,1,3,2,3,1,1,1,1,1,1,1,1,1,1,3,0,3,1,3,2,3,1,3,2,3,1,1,1,1,1 },
	{ 1,1,1,1,1,3,0,3,1,3,0,3,1,3,0,3,1,1,1,1,1,1,1,1,1,1,3,2,3,1,3,0,3,1,3,0,3,1,1,1,1,1 },
	{ 1,3,3,3,3,3,2,3,1,3,2,3,3,3,2,3,3,3,3,3,3,3,3,3,3,3,3,2,3,3,3,2,3,1,3,2,3,3,3,3,3,1 },
	{ 1,3,0,2,0,2,4,3,1,3,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,2,0,3,1,3,0,2,0,2,0,3,1 },
	{ 1,3,2,3,3,3,3,3,1,3,2,3,3,3,3,3,3,3,2,3,3,3,3,2,3,3,3,3,3,3,3,2,3,1,3,3,3,3,3,2,3,1 },
	{ 1,3,0,3,1,1,1,1,1,3,0,3,1,1,1,1,1,3,0,3,1,1,3,4,3,1,1,1,1,1,3,0,3,1,1,1,1,1,3,0,3,1 },
	{ 1,3,2,3,3,3,3,3,3,3,2,3,3,3,3,3,3,3,2,3,1,1,3,2,3,3,3,3,3,3,3,2,3,3,3,3,3,3,3,2,3,1 },
	{ 1,3,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,3,1,1,3,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,3,1 },
	{ 1,3,3,3,3,3,3,3,3,3,2,3,3,3,2,3,3,3,3,3,1,1,3,3,3,3,3,2,3,3,3,2,3,3,3,3,3,3,3,3,3,1 },
	{ 1,1,1,1,1,1,1,1,1,3,0,3,1,3,0,3,1,1,1,1,1,1,1,1,1,1,3,0,3,1,3,0,3,1,1,1,1,1,1,1,1,1 },
	{ 2,2,2,2,2,2,2,2,1,3,2,3,1,3,2,3,3,3,3,3,3,3,3,3,3,3,3,2,3,1,3,2,3,1,2,2,2,2,2,2,2,2 },
	{ 2,2,2,2,2,2,2,2,1,3,0,3,1,3,2,0,2,0,2,0,2,0,2,0,2,0,2,0,3,1,3,0,3,1,2,2,2,2,2,2,2,2 },
	{ 2,2,2,2,2,2,2,2,1,3,2,3,1,3,2,3,3,3,3,3,3,3,3,3,3,3,3,2,3,1,3,2,3,1,2,2,2,2,2,2,2,2 },
	{ 1,1,1,1,1,1,1,1,1,3,0,3,1,3,0,3,1,1,1,1,1,1,1,1,1,1,3,0,3,1,3,0,3,1,1,1,1,1,1,1,1,1 },
	{ 3,3,3,3,3,3,3,3,3,3,2,3,3,3,2,3,1,3,3,3,3,3,3,3,3,1,3,2,3,3,3,2,3,3,3,3,3,3,3,3,3,3 },
	{ 2,0,2,0,2,0,2,4,2,0,2,0,2,2,0,3,1,3,2,2,2,2,2,2,3,1,3,0,2,2,0,2,0,2,0,2,0,2,0,2,0,2 },
	{ 3,3,3,3,3,3,3,3,3,3,0,3,3,3,2,3,1,3,0,2,0,2,0,2,3,1,3,2,3,3,3,0,3,3,3,3,3,3,3,3,3,3 },
	{ 1,1,1,1,1,1,1,1,1,3,2,3,1,3,0,3,1,3,3,3,2,3,3,3,3,1,3,0,3,1,3,2,3,1,1,1,1,1,1,1,1,1 },
	{ 2,2,2,2,2,2,2,2,1,3,0,3,1,3,2,3,1,1,1,3,0,3,1,1,1,1,3,2,3,1,3,0,3,1,2,2,2,2,2,2,2,2 },
	{ 2,2,2,2,2,2,2,2,1,3,2,3,1,3,2,3,3,3,3,3,2,3,3,3,3,3,3,0,3,1,3,2,3,1,2,2,2,2,2,2,2,2 },
	{ 2,2,2,2,2,2,2,2,1,3,0,3,1,3,0,2,0,2,0,2,0,2,0,2,0,2,0,2,3,1,3,0,3,1,2,2,2,2,2,2,2,2 },
	{ 2,2,2,2,2,2,2,2,1,3,2,3,1,3,3,3,3,3,2,3,3,3,3,2,3,3,3,3,3,1,3,2,3,1,2,2,2,2,2,2,2,2 },
	{ 1,1,1,1,1,1,1,1,1,3,0,3,1,1,1,1,1,3,0,3,1,1,3,0,3,1,1,1,1,1,3,0,3,1,1,1,1,1,1,1,1,1 },
	{ 1,3,3,3,3,3,3,3,3,3,2,3,1,3,3,3,3,3,2,3,1,1,3,2,3,3,3,3,3,1,3,2,3,3,3,3,3,3,3,3,3,1 },
	{ 1,3,0,2,0,2,0,2,0,2,0,3,1,3,0,2,0,2,0,3,1,1,3,0,2,0,2,0,3,1,3,0,2,0,2,0,2,4,2,0,3,1 },
	{ 1,3,2,3,3,3,3,3,3,3,2,3,1,3,2,3,3,3,3,3,1,1,3,3,3,3,3,2,3,1,3,2,3,3,3,3,3,3,3,2,3,1 },
	{ 1,3,0,3,1,1,1,1,1,3,0,3,1,3,0,3,1,1,1,1,1,1,1,1,1,1,3,0,3,1,3,0,3,1,1,1,1,1,3,0,3,1 },
	{ 1,3,2,3,3,3,3,3,3,3,2,3,3,3,2,3,3,3,3,3,3,3,3,3,3,3,3,2,3,3,3,2,3,3,3,3,3,3,3,2,3,1 },
	{ 1,3,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,2,0,3,1 },
	{ 1,3,2,3,3,3,3,3,3,3,2,3,3,3,3,3,3,3,2,3,3,3,3,2,3,3,3,3,3,3,3,2,3,3,3,3,3,3,3,2,3,1 },
	{ 1,3,4,3,1,1,1,1,1,3,0,3,1,1,1,1,1,3,0,3,1,1,3,0,3,1,1,1,1,1,3,0,3,1,1,1,1,1,3,0,3,1 },
	{ 1,3,2,3,1,1,1,1,1,3,2,3,1,1,1,1,1,3,2,3,1,1,3,2,3,1,1,1,1,1,3,2,3,1,1,1,1,1,3,2,3,1 },
	{ 1,3,0,3,1,1,1,1,1,3,0,3,1,1,1,1,1,3,0,3,1,1,3,0,3,1,1,1,1,1,3,0,3,1,1,1,1,1,3,0,3,1 },
	{ 1,3,2,3,3,3,3,3,3,3,2,3,3,3,3,3,3,3,2,3,1,1,3,2,3,3,3,3,3,3,3,2,3,3,3,3,3,3,3,2,3,1 },
	{ 1,3,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,3,1,1,3,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,3,1 },
	{ 1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};

#pragma endregion

void draw_score() {
	int x = 1;
	int y = 2;
	int starty = 48;
	int startx;

	glLineWidth(2);
	glColor3f(0.08, 0.61, 0.8);
	startx = 1;
	glBegin(GL_LINES);
	glVertex2i((startx)* p, (starty)* p);
	glVertex2i((startx + x) * p, (starty)* p);

	glVertex2i((startx + x) * p, (starty)* p);
	glVertex2i((startx + x) * p, (starty + y / 2)* p);

	glVertex2i((startx + x) * p, (starty + y / 2)* p);
	glVertex2i((startx)* p, (starty + y / 2)* p);

	glVertex2i((startx)* p, (starty + y / 2)* p);
	glVertex2i((startx)* p, (starty + y)* p);

	glVertex2i((startx)* p, (starty + y)* p);
	glVertex2i((startx + x)* p, (starty + y)* p);
	glEnd();


	//first letter after s
	startx = 2 * 1 + x;
	glBegin(GL_LINES);

	glVertex2i((startx + x) * p, (starty)* p);
	glVertex2i((startx)* p, (starty)* p);

	glVertex2i((startx)* p, (starty)* p);
	glVertex2i((startx)* p, (starty + y)* p);

	glVertex2i((startx)* p, (starty + y)* p);
	glVertex2i((startx + x) * p, (starty + y)* p);

	glEnd();


	//second letter after s
	startx = 2 * 2 + x;
	glBegin(GL_LINES);

	glVertex2i((startx)* p, (starty)* p);
	glVertex2i((startx + x)* p, (starty)* p);

	glVertex2i((startx + x)* p, (starty)* p);
	glVertex2i((startx + x)* p, (starty + y)* p);

	glVertex2i((startx + x)* p, (starty + y)* p);
	glVertex2i((startx)* p, (starty + y)* p);

	glVertex2i((startx)* p, (starty + y)* p);
	glVertex2i((startx)* p, (starty)* p);

	glEnd();

	//third letter after s
	startx = 2 * 3 + x;
	glBegin(GL_LINES);

	glVertex2i((startx)* p, (starty)* p);
	glVertex2i((startx)* p, (starty + y)* p);

	glVertex2i((startx)* p, (starty + y)* p);
	glVertex2i((startx + x)* p, (starty + y)* p);

	glVertex2i((startx + x)* p, (starty + y)* p);
	glVertex2i((startx + x)* p, (starty + y / 2)* p);

	glVertex2i((startx + x)* p, (starty + y / 2)* p);
	glVertex2i((startx)* p, (starty + y / 2)* p);

	glVertex2i((startx)* p, (starty + y / 2)* p);
	glVertex2i((startx + x)* p, (starty)* p);

	glEnd();

	//fourth letter after s
	startx = 2 * 4 + x;
	glBegin(GL_LINES);

	glVertex2i((startx + x)* p, (starty)* p);
	glVertex2i((startx)* p, (starty)* p);

	glVertex2i((startx)* p, (starty)* p);
	glVertex2i((startx)* p, (starty + y / 2)* p);

	glVertex2i((startx)* p, (starty + y / 2)* p);
	glVertex2i((startx + x)* p, (starty + y / 2)* p);

	glVertex2i((startx)* p, (starty + y / 2)* p);
	glVertex2i((startx)* p, (starty + y)* p);

	glVertex2i((startx)* p, (starty + y)* p);
	glVertex2i((startx + x)* p, (starty + y)* p);

	glEnd();

	//two dots
	startx = 2 * 5.0 + x;
	glBegin(GL_POINTS);

	glVertex2i((startx)* p, (starty + 0.5)* p);
	glVertex2i((startx)* p, ((starty + y / 2) + 0.5)* p);

	glEnd();


	//Lives
	//L
	startx = 25;
	//startx =startx +( 2 * 4 + x);
	glBegin(GL_LINES);

	glVertex2i((startx)* p, (starty + y)* p);
	glVertex2i((startx)* p, (starty)* p);

	glVertex2i((startx)* p, (starty)* p);
	glVertex2i((startx + x)* p, (starty)* p);

	glEnd();

	//first letter after L
	startx = 25 + (2 * 1);
	glBegin(GL_LINES);

	glVertex2i((startx)* p, (starty + y)* p);
	glVertex2i((startx)* p, (starty)* p);

	glEnd();

	//second letter after L
	startx = 24 + (2 * 2);
	glBegin(GL_LINES);

	glVertex2i((startx)* p, (starty + y)* p);
	glVertex2i((startx + 0.5)* p, (starty)* p);

	glVertex2i((startx + 0.5)* p, (starty)* p);
	glVertex2i((startx + x)* p, (starty + y)* p);

	glEnd();


	//third letter after L
	startx = 24 + (2 * 3);
	glBegin(GL_LINES);

	glVertex2i((startx + x)* p, (starty)* p);
	glVertex2i((startx)* p, (starty)* p);

	glVertex2i((startx)* p, (starty)* p);
	glVertex2i((startx)* p, (starty + y / 2)* p);

	glVertex2i((startx)* p, (starty + y / 2)* p);
	glVertex2i((startx + x)* p, (starty + y / 2)* p);

	glVertex2i((startx)* p, (starty + y / 2)* p);
	glVertex2i((startx)* p, (starty + y)* p);

	glVertex2i((startx)* p, (starty + y)* p);
	glVertex2i((startx + x)* p, (starty + y)* p);

	glEnd();


	//fourth letter after L
	startx = 24 + (2 * 4);
	glBegin(GL_LINES);
	glVertex2i((startx)* p, (starty)* p);
	glVertex2i((startx + x) * p, (starty)* p);

	glVertex2i((startx + x) * p, (starty)* p);
	glVertex2i((startx + x) * p, (starty + y / 2)* p);

	glVertex2i((startx + x) * p, (starty + y / 2)* p);
	glVertex2i((startx)* p, (starty + y / 2)* p);

	glVertex2i((startx)* p, (starty + y / 2)* p);
	glVertex2i((startx)* p, (starty + y)* p);

	glVertex2i((startx)* p, (starty + y)* p);
	glVertex2i((startx + x)* p, (starty + y)* p);
	glEnd();

	startx = 24 + (2 * 5);
	glBegin(GL_POINTS);

	glVertex2i((startx)* p, (starty + 0.5)* p);
	glVertex2i((startx)* p, ((starty + y / 2) + 0.5)* p);

	glEnd();

}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius, int start, int end) {
	int triangleAmount = 120;
	GLfloat twicePi = 6.28318f;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (; start <= end;start++) {
		glVertex2f(
			x + (radius * cos(start *  twicePi / triangleAmount)),
			y + (radius * sin(start * twicePi / triangleAmount))
			);
	}
	glEnd();
}

void Initialization(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboardown(int key, int x, int y)
{
	int xt, yt;
	switch (key) {
	case GLUT_KEY_RIGHT:
		startcircle = 10;
		endcircle = 110;
		if (flagright == 1) {
			if ((posX - 2.25f) > 63.0f) {
				posX = -2.0f;
				flagright = 0;
			}
			posX += move_unit;
		}
		else if (flagright == 0) {
			xt = (int)((posX + 2.25f) * 2) / 3;
			yt = (int)(posY * 2) / 3;
			if (arr[yt][xt] != 1) {
				xt = (int)((posX + 0.75f) * 2) / 3;
				yt = (int)(posY * 2) / 3;
				if (arr[yt][xt] != 3)
					posX += move_unit;
			}
			xt = (int)(posX * 2) / 3;
			if (xt == 41) {
				flagright = 1;
			}
		}
		if (arr[(int)(posY * 2 / 3)][(int)(posX * 2 / 3)] == 0) {
			score += 10;
			arr[(int)(posY * 2 / 3)][(int)(posX * 2 / 3)] = 2;
		} else if (arr[(int)(posY * 2 / 3)][(int)(posX * 2 / 3)] == 4) {
			score += 50;
			arr[(int)(posY * 2 / 3)][(int)(posX * 2 / 3)] = 2;
		}
		break;

	case GLUT_KEY_LEFT:
		startcircle = 70;
		endcircle = 170;
		if (flagleft == 1) {
			if ((posX + 2.25f) < 0.0f) {
				posX = 65.0f;
				flagleft = 0;
			}
			posX -= move_unit;
		}
		else if (flagleft == 0) {
			xt = (int)((posX - 2.25f) * 2) / 3;
			yt = (int)(posY * 2) / 3;
			if (arr[yt][xt] != 1) {
				xt = (int)((posX - 0.75f) * 2) / 3;
				if (xt == 42)
					xt = 41;
				yt = (int)(posY * 2) / 3;
				if (arr[yt][xt] != 3)
					posX -= move_unit;
			}
			xt = (int)(posX * 2) / 3;
			if (xt == 0)
				flagleft = 1;
		}
		if (arr[(int)(posY * 2 / 3)][(int)(posX * 2 / 3)] == 0) {
			score += 10;
			arr[(int)(posY * 2 / 3)][(int)(posX * 2 / 3)] = 2;
		}
		else if (arr[(int)(posY * 2 / 3)][(int)(posX * 2 / 3)] == 4) {
			score += 50;
			arr[(int)(posY * 2 / 3)][(int)(posX * 2 / 3)] = 2;
		}
		break;

	case GLUT_KEY_UP:
		startcircle = 40;
		endcircle = 140;
		xt = (int)(posX * 2) / 3;
		yt = (int)((posY + 2.25f) * 2) / 3;
		if (arr[yt][xt] != 1) {
			xt = (int)(posX * 2) / 3;
			yt = (int)((posY + 0.75f) * 2) / 3;
			if (arr[yt][xt] != 3)
				posY += move_unit;
		}
		if (arr[(int)(posY * 2 / 3)][(int)(posX * 2 / 3)] == 0) {
			score += 10;
			arr[(int)(posY * 2 / 3)][(int)(posX * 2 / 3)] = 2;
		}
		else if (arr[(int)(posY * 2 / 3)][(int)(posX * 2 / 3)] == 4) {
			score += 50;
			arr[(int)(posY * 2 / 3)][(int)(posX * 2 / 3)] = 2;
		}
		break;

	case GLUT_KEY_DOWN:
		startcircle = 100;
		endcircle = 200;
		xt = (int)(posX * 2) / 3;
		yt = (int)((posY - 2.25f) * 2) / 3;
		if (arr[yt][xt] != 1) {
			xt = (int)(posX * 2) / 3;
			yt = (int)((posY - 0.75f) * 2) / 3;
			if (arr[yt][xt] != 3)
				posY -= move_unit;
		}
		if (arr[(int)(posY * 2 / 3)][(int)(posX * 2 / 3)] == 0) {
			score += 10;
			arr[(int)(posY * 2 / 3)][(int)(posX * 2 / 3)] = 2;
		}
		else if (arr[(int)(posY * 2 / 3)][(int)(posX * 2 / 3)] == 4) {
			score += 50;
			arr[(int)(posY * 2 / 3)][(int)(posX * 2 / 3)] = 2;
		}
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

void drawmonster()
{
	if (flag == 0)
	{

		monster1.xpos = 118.5f;
		monster1.ypos = 7.5f;
		monster1.speed = 0.5;

		monster2.xpos = 7.5f;
		monster2.ypos = 127.5f;
		monster2.speed = 1.0;

		monster3.xpos = 118.5f;
		monster3.ypos = 127.5f;
		monster3.speed = 1.5;

		monster4.xpos = 62.5f;
		monster4.ypos = 85.0f;
		monster4.speed = 2.0;

		flag = 1;
	}
}

void scoredisplay(int posx, int posy, int posz, int space_char, int scorevar)
{
	int j = 0, p, k;
	GLvoid *font_style1 = GLUT_BITMAP_TIMES_ROMAN_24;
	p = scorevar;
	j = 0;
	k = 0;
	while (p > 9)
	{
		k = p % 10;
		glRasterPos3f((posx - (j*space_char)), posy, posz);
		glutBitmapCharacter(font_style1, 48 + k);
		j++;
		p /= 10;
	}
	glRasterPos3f((posx - (j*space_char)), posy, posz);
	glutBitmapCharacter(font_style1, 48 + p);

}

void playerlives(float num1, float num2) {
	if (num1 == num2)
	{
		lives--;
		posX = 3.75f;
		posY = 3.75f;
	}
}

void draw_maze(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(posX, posY, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	drawFilledCircle(posX, posY, radius, startcircle, endcircle);
	drawmonster();
	glPopMatrix();
	glPushMatrix();

	
	glPopMatrix();

	glPushMatrix();
	draw_score();
	glColor3f(1.0, 1.0, 0.0);
	scoredisplay(15.0 * p, 48.5 * p, 1.0, 3, score);
	
	if ((posY * 2) < (monster1.ypos + 1.5) && (posY * 2) > (monster1.ypos - 1.5)) {
		playerlives((posX + 1.5) * 2, monster1.xpos - 1.5);
		playerlives((posX - 1.5) * 2, monster1.xpos + 1.5);
	}
	else if ((posX * 2) < (monster1.xpos + 1.5) && (posX * 2) > (monster1.xpos - 1.5)) {
		playerlives((posY - 1.5) * 2, monster1.ypos + 1.5);
		playerlives((posY + 1.5) * 2, monster1.ypos - 1.5);
	}

	if ((posY * 2) < (monster2.ypos + 1.5) && (posY * 2) > (monster2.ypos - 1.5)) {
		playerlives((posX + 1.5) * 2, monster2.xpos - 1.5);
		playerlives((posX - 1.5) * 2, monster2.xpos + 1.5);
	}
	else if ((posX * 2) < (monster2.xpos + 1.5) && (posX * 2) > (monster2.xpos - 1.5)) {
		playerlives((posY - 1.5) * 2, monster2.ypos + 1.5);
		playerlives((posY + 1.5) * 2, monster2.ypos - 1.5);
	}

	if ((posY * 2) < (monster3.ypos + 1.5) && (posY * 2) > (monster3.ypos - 1.5)) {
		playerlives((posX + 1.5) * 2, monster3.xpos - 1.5);
		playerlives((posX - 1.5) * 2, monster3.xpos + 1.5);
	}
	else if ((posX * 2) < (monster3.xpos + 1.5) && (posX * 2) > (monster3.xpos - 1.5)) {
		playerlives((posY - 1.5) * 2, monster3.ypos + 1.5);
		playerlives((posY + 1.5) * 2, monster3.ypos - 1.5);
	}

	if ((posY * 2) < (monster4.ypos + 1.5) && (posY * 2) > (monster4.ypos - 1.5)) {
		playerlives((posX + 1.5) * 2, monster4.xpos - 1.5);
		playerlives((posX - 1.5) * 2, monster4.xpos + 1.5);
	}
	else if ((posX * 2) < (monster4.xpos + 1.5) && (posX * 2) > (monster4.xpos - 1.5)) {
		playerlives((posY - 1.5) * 2, monster4.ypos + 1.5);
		playerlives((posY + 1.5) * 2, monster4.ypos - 1.5);
	}

	if (lives == 3) {
		drawFilledCircle(35.5 * p, 49.0 * p, 2.75, 10, 110);
		drawFilledCircle(37.75 * p, 49.0 * p, 2.75, 10, 110);
		drawFilledCircle(40.0 * p, 49.0 * p, 2.75, 10, 110);
	}
	else if (lives == 2) {
		drawFilledCircle(35.5 * p, 49.0 * p, 2.75, 10, 110);
		drawFilledCircle(37.75 * p, 49.0 * p, 2.75, 10, 110);
	}
	else if (lives == 1) {
		drawFilledCircle(35.5 * p, 49.0 * p, 2.75, 10, 110);
	}
	else if (lives == 0) {
		MessageBox(NULL, L"GAMEOVER", L"GAMEOVER", MB_OK);
		exit(0);
	}
	if (score == 2360) {
		MessageBox(NULL, L"You Win !!", L"You Win !!", MB_OK);
		exit(0);
	}
	glPopMatrix();

#pragma region Maze

	glLineWidth(2);
	glColor3f(0.08, 0.61, 0.8);


	glBegin(GL_LINE_LOOP);
	glVertex2i(4 * p, 14 * p);
	glVertex2i(9 * p, 14 * p);
	glVertex2i(9 * p, 8 * p);
	glVertex2i(8 * p, 8 * p);
	glVertex2i(8 * p, 13 * p);
	glVertex2i(4 * p, 13 * p);
	glVertex2i(4 * p, 14 * p);
	glVertex2i(9 * p, 14 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(33 * p, 8 * p);
	glVertex2i(34 * p, 8 * p);
	glVertex2i(34 * p, 13 * p);
	glVertex2i(38 * p, 13 * p);
	glVertex2i(38 * p, 14 * p);
	glVertex2i(33 * p, 14 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(0 * p, 25 * p);
	glVertex2i(9 * p, 25 * p);
	glVertex2i(9 * p, 31 * p);
	glVertex2i(1 * p, 31 * p);
	glVertex2i(1 * p, 44 * p);
	glVertex2i(20 * p, 44 * p);
	glVertex2i(20 * p, 38 * p);
	glVertex2i(22 * p, 38 * p);
	glVertex2i(22 * p, 44 * p);
	glVertex2i(41 * p, 44 * p);
	glVertex2i(41 * p, 31 * p);
	glVertex2i(33 * p, 31 * p);
	glVertex2i(33 * p, 25 * p);
	glVertex2i(42 * p, 25 * p);
	glVertex2i(42 * p, 26 * p);
	glVertex2i(34 * p, 26 * p);
	glVertex2i(34 * p, 30 * p);
	glVertex2i(42 * p, 30 * p);
	glVertex2i(42 * p, 45 * p);
	glVertex2i(0 * p, 45 * p);
	glVertex2i(0 * p, 30 * p);
	glVertex2i(8 * p, 30 * p);
	glVertex2i(8 * p, 26 * p);
	glVertex2i(0 * p, 26 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(0 * p, 21 * p);
	glVertex2i(8 * p, 21 * p);
	glVertex2i(8 * p, 18 * p);
	glVertex2i(0 * p, 18 * p);
	glVertex2i(0 * p, 0 * p);
	glVertex2i(42 * p, 0 * p);
	glVertex2i(42 * p, 18 * p);
	glVertex2i(34 * p, 18 * p);
	glVertex2i(34 * p, 21 * p);
	glVertex2i(42 * p, 21 * p);
	glVertex2i(42 * p, 22 * p);
	glVertex2i(33 * p, 22 * p);
	glVertex2i(33 * p, 17 * p);
	glVertex2i(41 * p, 17 * p);
	glVertex2i(41 * p, 10 * p);
	glVertex2i(37 * p, 10 * p);
	glVertex2i(37 * p, 8 * p);
	glVertex2i(41 * p, 8 * p);
	glVertex2i(41 * p, 1 * p);
	glVertex2i(1 * p, 1 * p);
	glVertex2i(1 * p, 8 * p);
	glVertex2i(5 * p, 8 * p);
	glVertex2i(5 * p, 10 * p);
	glVertex2i(1 * p, 10 * p);
	glVertex2i(1 * p, 17 * p);
	glVertex2i(9 * p, 17 * p);
	glVertex2i(9 * p, 22 * p);
	glVertex2i(0 * p, 22 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(4 * p, 41 * p);
	glVertex2i(4 * p, 38 * p);
	glVertex2i(9 * p, 38 * p);
	glVertex2i(9 * p, 41 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(4 * p, 35 * p);
	glVertex2i(9 * p, 35 * p);
	glVertex2i(9 * p, 34 * p);
	glVertex2i(4 * p, 34 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(12 * p, 41 * p);
	glVertex2i(12 * p, 38 * p);
	glVertex2i(17 * p, 38 * p);
	glVertex2i(17 * p, 41 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(25 * p, 41 * p);
	glVertex2i(25 * p, 38 * p);
	glVertex2i(30 * p, 38 * p);
	glVertex2i(30 * p, 41 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(33 * p, 41 * p);
	glVertex2i(33 * p, 38 * p);
	glVertex2i(38 * p, 38 * p);
	glVertex2i(38 * p, 41 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(25 * p, 4 * p);
	glVertex2i(25 * p, 5 * p);
	glVertex2i(29 * p, 5 * p);
	glVertex2i(29 * p, 10 * p);
	glVertex2i(30 * p, 10 * p);
	glVertex2i(30 * p, 5 * p);
	glVertex2i(38 * p, 5 * p);
	glVertex2i(38 * p, 4 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(17 * p, 4 * p);
	glVertex2i(17 * p, 5 * p);
	glVertex2i(13 * p, 5 * p);
	glVertex2i(13 * p, 10 * p);
	glVertex2i(12 * p, 10 * p);
	glVertex2i(12 * p, 5 * p);
	glVertex2i(4 * p, 5 * p);
	glVertex2i(4 * p, 4 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(12 * p, 13 * p);
	glVertex2i(12 * p, 14 * p);
	glVertex2i(17 * p, 14 * p);
	glVertex2i(17 * p, 13 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(12 * p, 17 * p);
	glVertex2i(12 * p, 22 * p);
	glVertex2i(13 * p, 22 * p);
	glVertex2i(13 * p, 17 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(25 * p, 13 * p);
	glVertex2i(30 * p, 13 * p);
	glVertex2i(30 * p, 14 * p);
	glVertex2i(25 * p, 14 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(12 * p, 25 * p);
	glVertex2i(13 * p, 25 * p);
	glVertex2i(13 * p, 30 * p);
	glVertex2i(17 * p, 30 * p);
	glVertex2i(17 * p, 31 * p);
	glVertex2i(13 * p, 31 * p);
	glVertex2i(13 * p, 35 * p);
	glVertex2i(12 * p, 35 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(16 * p, 21 * p);
	glVertex2i(16 * p, 27 * p);
	glVertex2i(19 * p, 27 * p);
	glVertex2i(19 * p, 26 * p);
	glVertex2i(17 * p, 26 * p);
	glVertex2i(17 * p, 22 * p);
	glVertex2i(25 * p, 22 * p);
	glVertex2i(25 * p, 26 * p);
	glVertex2i(22 * p, 26 * p);
	glVertex2i(22 * p, 27 * p);
	glVertex2i(26 * p, 27 * p);
	glVertex2i(26 * p, 21 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(20 * p, 30 * p);
	glVertex2i(22 * p, 30 * p);
	glVertex2i(22 * p, 34 * p);
	glVertex2i(26 * p, 34 * p);
	glVertex2i(26 * p, 35 * p);
	glVertex2i(16 * p, 35 * p);
	glVertex2i(16 * p, 34 * p);
	glVertex2i(20 * p, 34 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(20 * p, 13 * p);
	glVertex2i(22 * p, 13 * p);
	glVertex2i(22 * p, 17 * p);
	glVertex2i(26 * p, 17 * p);
	glVertex2i(26 * p, 18 * p);
	glVertex2i(16 * p, 18 * p);
	glVertex2i(16 * p, 17 * p);
	glVertex2i(20 * p, 17 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(20 * p, 4 * p);
	glVertex2i(22 * p, 4 * p);
	glVertex2i(22 * p, 8 * p);
	glVertex2i(26 * p, 8 * p);
	glVertex2i(26 * p, 10 * p);
	glVertex2i(16 * p, 10 * p);
	glVertex2i(16 * p, 8 * p);
	glVertex2i(20 * p, 8 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(29 * p, 25 * p);
	glVertex2i(30 * p, 25 * p);
	glVertex2i(30 * p, 35 * p);
	glVertex2i(29 * p, 35 * p);
	glVertex2i(29 * p, 31 * p);
	glVertex2i(25 * p, 31 * p);
	glVertex2i(25 * p, 30 * p);
	glVertex2i(29 * p, 30 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(33 * p, 34 * p);
	glVertex2i(33 * p, 35 * p);
	glVertex2i(38 * p, 35 * p);
	glVertex2i(38 * p, 34 * p);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(29 * p, 17 * p);
	glVertex2i(30 * p, 17 * p);
	glVertex2i(30 * p, 22 * p);
	glVertex2i(29 * p, 22 * p);
	glEnd();

#pragma endregion

	for (int i = 0; i < 45; i++)
	{
		for (int j = 0; j < 42; j++)
		{
			if (arr[i][j] == 0) {
				glColor3f(1.0, 1.0, 0.0);
				glPointSize(4.0);
				glBegin(GL_POINTS);
				glVertex2i(j * p + (p / 2), i * p + (p / 2));
				glEnd();
			}
			else if (arr[i][j] == 4) {
				glColor3f(1.0, 0.5, 0.0);
				glPointSize(9.0);
				glBegin(GL_POINTS);
				glVertex2i(j * p + (p / 2), i * p + (p / 2));
				glEnd();
			}
			
		}
	}

	glPushMatrix();
	glColor3f(0.0, 0.797, 0.0);
	drawFilledCircle(monster1.xpos, monster1.ypos, radius, 0, 120);
	glTranslated(monster1.xpos, monster1.ypos, 0.0);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.797, 0.0, 0.0);
	drawFilledCircle(monster2.xpos, monster2.ypos, radius, 0, 120);
	glTranslated(monster2.xpos, monster2.ypos, 0.0);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.797);
	drawFilledCircle(monster3.xpos, monster3.ypos, radius, 0, 120);
	glTranslated(monster3.xpos, monster3.ypos, 0.0);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.6, 0.0, 0.6);
	drawFilledCircle(monster4.xpos, monster4.ypos, radius, 0, 120);
	glTranslated(monster4.xpos, monster4.ypos, 0.0);
	glPopMatrix();

	glPopMatrix();
	glFlush();
}

#pragma region Monsters

void monsters1() {
	int x, y, xright, yup, xleft, ydown;
	int xright3, yup3, xleft3, ydown3;


	x = (int)(monster1.xpos) / 3;
	y = (int)(monster1.ypos) / 3;

	xright = (int)(monster1.xpos + 2.25f) / 3;
	xleft = (int)(monster1.xpos - 2.25f) / 3;
	ydown = (int)(monster1.ypos - 2.25f) / 3;
	yup = (int)(monster1.ypos + 2.25f) / 3;

	xright3 = (int)(monster1.xpos + 0.75f) / 3;
	xleft3 = (int)(monster1.xpos - 0.75f) / 3;
	ydown3 = (int)(monster1.ypos - 0.75f) / 3;
	yup3 = (int)(monster1.ypos + 0.75f) / 3;


	if (flag_moving1 == 0)
	{
		rm1 = rand() % 4;
		flag_moving1 = 1;
	}

	if (rm1 == 0)
	{
		if ((arr[yup][x] == 2 || arr[yup][x] == 0 || arr[yup][x] == 4) && arr[yup3][x] != 3) {
			monster1.ypos += monster1.speed;
		}
		else {
			flag_moving1 = 0;
		}
	}
	else if (rm1 == 2)
	{
		if ((arr[ydown][x] == 2 || arr[ydown][x] == 0 || arr[ydown][x] == 4) && arr[ydown3][x] != 3) {
			monster1.ypos -= monster1.speed;
		}
		else {
			flag_moving1 = 0;
		}
	}
	else if (rm1 == 1)
	{
		if ((arr[y][xright] == 2 || arr[y][xright] == 0 || arr[y][xright] == 4) && arr[y][xright3] != 3) {
			monster1.xpos += monster1.speed;
		}
		else {
			flag_moving1 = 0;
		}
	}
	else if (rm1 == 3)
	{
		if ((arr[y][xleft] == 2 || arr[y][xleft] == 0 || arr[y][xleft] == 4) && arr[y][xleft3] != 3) {
			monster1.xpos -= monster1.speed;
		}
		else {
			flag_moving1 = 0;
		}
	}

}

void monsters2() {
	int x, y, xright, yup, xleft, ydown;
	int xright3, yup3, xleft3, ydown3;

	x = (int)(monster2.xpos) / 3;
	y = (int)(monster2.ypos) / 3;

	xright = (int)(monster2.xpos + 2.25f) / 3;
	xleft = (int)(monster2.xpos - 2.25f) / 3;
	ydown = (int)(monster2.ypos - 2.25f) / 3;
	yup = (int)(monster2.ypos + 2.25f) / 3;

	xright3 = (int)(monster2.xpos + 0.75f) / 3;
	xleft3 = (int)(monster2.xpos - 0.75f) / 3;
	ydown3 = (int)(monster2.ypos - 0.75f) / 3;
	yup3 = (int)(monster2.ypos + 0.75f) / 3;


	if (flag_moving2 == 0)
	{
		rm2 = rand() % 4;
		flag_moving2 = 1;
	}

	if (rm2 == 0)
	{
		if ((arr[yup][x] == 2 || arr[yup][x] == 0 || arr[yup][x] == 4) && arr[yup3][x] != 3) {
			monster2.ypos += monster2.speed;
		}
		else {
			flag_moving2 = 0;
		}
	}
	else if (rm2 == 2)
	{
		if ((arr[ydown][x] == 2 || arr[ydown][x] == 0 || arr[ydown][x] == 4) && arr[ydown3][x] != 3) {
			monster2.ypos -= monster2.speed;
		}
		else {
			flag_moving2 = 0;
		}
	}
	else if (rm2 == 1)
	{
		if ((arr[y][xright] == 2 || arr[y][xright] == 0 || arr[y][xright] == 4) && arr[y][xright3] != 3) {
			monster2.xpos += monster2.speed;
		}
		else {
			flag_moving2 = 0;
		}
	}
	else if (rm2 == 3)
	{
		if ((arr[y][xleft] == 2 || arr[y][xleft] == 0 || arr[y][xleft] == 4) && arr[y][xleft3] != 3) {
			monster2.xpos -= monster2.speed;
		}
		else {
			flag_moving2 = 0;
		}
	}

}

void monsters3() {
	int x, y, xright, yup, xleft, ydown;
	int xright3, yup3, xleft3, ydown3;


	x = (int)(monster3.xpos) / 3;
	y = (int)(monster3.ypos) / 3;

	xright = (int)(monster3.xpos + 2.25f) / 3;
	xleft = (int)(monster3.xpos - 2.25f) / 3;
	ydown = (int)(monster3.ypos - 2.25f) / 3;
	yup = (int)(monster3.ypos + 2.25f) / 3;

	xright3 = (int)(monster3.xpos + 0.75f) / 3;
	xleft3 = (int)(monster3.xpos - 0.75f) / 3;
	ydown3 = (int)(monster3.ypos - 0.75f) / 3;
	yup3 = (int)(monster3.ypos + 0.75f) / 3;


	if (flag_moving3 == 0)
	{
		rm3 = rand() % 4;
		flag_moving3 = 1;
	}

	if (rm3 == 0)
	{
		if ((arr[yup][x] == 2 || arr[yup][x] == 0 || arr[yup][x] == 4) && arr[yup3][x] != 3) {
			monster3.ypos += monster3.speed;
		}
		else {
			flag_moving3 = 0;
		}
	}
	else if (rm3 == 2)
	{
		if ((arr[ydown][x] == 2 || arr[ydown][x] == 0 || arr[ydown][x] == 4) && arr[ydown3][x] != 3) {
			monster3.ypos -= monster3.speed;
		}
		else {
			flag_moving3 = 0;
		}
	}
	else if (rm3 == 1)
	{
		if ((arr[y][xright] == 2 || arr[y][xright] == 0 || arr[y][xright] == 4) && arr[y][xright3] != 3) {
			monster3.xpos += monster3.speed;
		}
		else {
			flag_moving3 = 0;
		}
	}
	else if (rm3 == 3)
	{
		if ((arr[y][xleft] == 2 || arr[y][xleft] == 0 || arr[y][xleft] == 4) && arr[y][xleft3] != 3) {
			monster3.xpos -= monster3.speed;
		}
		else {
			flag_moving3 = 0;
		}
	}

}

void monsters4() {
	int x, y, xright, yup, xleft, ydown;
	int xright3, yup3, xleft3, ydown3;

	x = (int)(monster4.xpos) / 3;
	y = (int)(monster4.ypos) / 3;

	xright = (int)(monster4.xpos + 2.25f) / 3;
	xleft = (int)(monster4.xpos - 2.25f) / 3;
	ydown = (int)(monster4.ypos - 2.25f) / 3;
	yup = (int)(monster4.ypos + 2.25f) / 3;

	xright3 = (int)(monster4.xpos + 0.75f) / 3;
	xleft3 = (int)(monster4.xpos - 0.75f) / 3;
	ydown3 = (int)(monster4.ypos - 0.75f) / 3;
	yup3 = (int)(monster4.ypos + 0.75f) / 3;


	if (flag_moving4 == 0)
	{
		if (countm4 == 0) {
			rm4 = 1;
			countm4++;
		}
		else {
			rm4 = rand() % 4;
		}
		flag_moving4 = 1;
	}

	if (rm4 == 0)
	{
		if ((arr[yup][x] == 2 || arr[yup][x] == 0 || arr[yup][x] == 4) && arr[yup3][x] != 3) {
			monster4.ypos += monster4.speed;
		}
		else {
			flag_moving4 = 0;
		}
	}
	else if (rm4 == 2)
	{
		if ((arr[ydown][x] == 2 || arr[ydown][x] == 0 || arr[ydown][x] == 4) && arr[ydown3][x] != 3) {
			monster4.ypos -= monster4.speed;
		}
		else {
			flag_moving4 = 0;
		}
	}
	else if (rm4 == 1)
	{
		if ((arr[y][xright] == 2 || arr[y][xright] == 0 || arr[y][xright] == 4) && arr[y][xright3] != 3) {
			monster4.xpos += monster4.speed;
		}
		else {
			flag_moving4 = 0;
		}
	}
	else if (rm4 == 3)
	{
		if ((arr[y][xleft] == 2 || arr[y][xleft] == 0 || arr[y][xleft] == 4) && arr[y][xleft3] != 3) {
			monster4.xpos -= monster4.speed;
		}
		else {
			flag_moving4 = 0;
		}
	}

}

#pragma endregion

void idleFunc(void)
{
	// idle event call back in animation , here we increase the values and redisply .
	//for (thingNum = 0; thingNum <4; thingNum++)
	//  {
	//right
	monsters1();
	monsters2();
	monsters3();
	monsters4();

	Sleep(100);
	glutPostRedisplay();
}

int main() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(42 * 5 * p, 45 * 5 * p);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 640) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 700) / 2);
	glutCreateWindow("PacMan");
	glClearColor(0.1, 0.1, 0.1, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 42 * p, 0.0, 45 * p + 25);
	glutDisplayFunc(draw_maze);
	glutIdleFunc(idleFunc);
	glutSpecialFunc(keyboardown);

	glutMainLoop();
	return 0;
}
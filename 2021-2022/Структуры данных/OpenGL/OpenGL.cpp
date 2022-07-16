#include <GL/glut.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <iostream>

/* начальная ширина и высота окна */
GLint Width = 1024, Height = 1024;
/* размер ребра треугольника */
double R = 8;
/* эта функция управляет всем выводом на экран */

void Display(void)
{
	int st = 0, fin = 0;

	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3ub(100, 0, 0);
	glBegin(GL_TRIANGLES);

	while (fin < Height)
	{
		while (st < Width)
		{
			if (R / 2 != 0)
			{
				glVertex2f(st, fin);
				if (R != 1)
					glVertex2f(st + Width / R, fin + Height / R);
				else
					glVertex2f(st + Width / 2, fin + Height);
				if (R != 1)
					glVertex2f(st + Width / (R / 2), fin);
				else 
					glVertex2f(st + Width, fin);
				st += Width / (R / 2);
			}
			else
				st = Width;
		}
		fin += Height / R;
		st = 0;
	}
	glEnd();
	glFinish();
}


/* Функция вызывается при изменении размеров окна */
void Reshape(GLint w, GLint h)
{
	Width = w;
	Height = h;
	/* устанавливаем размеры области отображения */
	glViewport(0, 0, w, h);

	/* ортографическая проекция */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void SpecKeyboard(int key, int x, int y) {
	if (key == GLUT_KEY_UP) R *= 2;
    if (R/2 != 0)
	if (key == GLUT_KEY_DOWN) R /= 2;
}

void TimerMove(int value) {
	glColor3ub(255, 0, 0);
	glutPostRedisplay();
	glutTimerFunc(33, TimerMove, 1);
}

/* Главный цикл приложения */
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Floor");

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutSpecialFunc(SpecKeyboard);
	glutTimerFunc(33, TimerMove, 1);
	glutMainLoop();
}




/*int st = 0, fin = 0;
	while (fin < Height)
	{
		while (st < Width)
		{
			if (R / 2 != 0)
			{
				glVertex2f(st, fin);
				glVertex2f(st + Width / R, fin + Height / R);
				glVertex2f(st + Width / (R / 2), fin);
				st += Width / (R / 2);
			}
			else
				st = Width;
		}
		fin += Height / R;
		st = 0;
	}
	*/
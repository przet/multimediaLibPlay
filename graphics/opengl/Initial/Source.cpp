#include <stdlib.h>
#include<glut.h>
#include <vector>
#include <string>
#include <stdexcept>
#include <array>

void clearAllPixels()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void colorise(const std::vector<float>& color)
{
	if (std::size(color) < 3)
		throw std::logic_error("input color vector to " + std::string(__func__) + " must be at least size 3");

	glColor3f(color[0], color[1], color[2]);
}

void clearingColor(const std::vector<float>& color = {0.0f, 0.0f, 0.0f, 0.0f})
{
	if (std::size(color) < 4)
		throw std::logic_error("input color vector to " + std::string(__func__) + " must be at least size 4");

	glClearColor(color[0], color[1], color[2], color[3]);
}

void initViewing(const std::vector<float>& orthoValue)
{
	if (std::size(orthoValue) != 6)
		throw std::logic_error("input ortho vector to " + std::string(__func__) + " must be of size 6");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(orthoValue[0], orthoValue[1], orthoValue[2], orthoValue[3], orthoValue[4], orthoValue[5]);
}


void display()
{
	clearAllPixels();
	colorise({ 0.0f, 1.0f, 0.0f });
	std::array<float, 2> corner1{ 0.25f, 0.25f };
	std::array<float, 2> corner2{ 0.75f, 0.75f };
	glRectfv(&corner1[0], &corner2[0]);
	
	colorise({ 1.0f, 0.0f, 0.0f });
	glPointSize(8.0f);
	glBegin(GL_POINTS);
		glVertex2f(0.5f, 0.5f);
	glEnd();

	glFlush();
}


void init()
{
	clearingColor();
	initViewing({ 0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 1.0f });
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Initial");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
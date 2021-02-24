#include <stdlib.h>
#include<glut.h>
#include <vector>
#include <string>
#include <stdexcept>

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

void drawRectangle_2D(const std::vector<float>& bottomLCorner,
	const std::vector<float>& topRCorner, const std::vector<float>& color, bool wait = false)
{
	if (std::size(bottomLCorner) < 2 || std::size(topRCorner) < 2) 
		throw std::logic_error("input corner vectors to " + std::string(__func__) + " must be at least size 2");


	std::vector<float> bottomRCorner{ topRCorner[0], bottomLCorner[1], 0 };
	std::vector<float> topLCorner{ bottomLCorner[0], topRCorner[1], 0 };

	colorise(color);
	glBegin(GL_POLYGON);
		glVertex3f(bottomLCorner[0], bottomLCorner[1], 0 );
		glVertex3f(bottomRCorner[0], bottomRCorner[1], 0 );
		glVertex3f(topRCorner[0], topRCorner[1], 0 );
		glVertex3f(topLCorner[0], topLCorner[1], 0 );
	glEnd();

	if (!wait)
		glFlush();
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
	drawRectangle_2D({ 0.25f, 0.25f }, { 0.75f, 0.75f }, { 1.0f, 1.0f, 1.0f });
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
#include"stdafx.h"
#include"RigidBody.h"
#include <glut.h>
#include<math.h>
void RigidBody::render()
{	

	//������� ��������� ������
	glClear(GL_COLOR_BUFFER_BIT);

	//��������� ����� �����������
	glColor3d(1.0, 1.0, 0.0);

	//��������� ����
	glBegin(GL_LINES);
	//��������� ������
	glVertex2d(-40., .0);
	glVertex2d(40., .0);
	glVertex2d(.0, -40.);
	glVertex2d(.0, 40.);
	//��������� ��������� ����
	glEnd();
	glColor3d(255, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < n; i++)
	{
		glVertex2d(nodes[i].x, nodes[i].y);
	}
	glEnd();	
	glFlush();	
}
void RigidBody::update()
{

}
#include"stdafx.h"
#include"RigidBody.h"
#include <glut.h>
#include<math.h>
void RigidBody::render()
{	
	float x, y;
	//������� ��������� ������
	glClear(GL_COLOR_BUFFER_BIT);

	//��������� ����� �����������
	glColor3d(0.0, 0.0, 0.0);

	//��������� ����
	glBegin(GL_LINES);
	//��������� ������
	glVertex2d(-40., .0);
	glVertex2d(40., .0);
	glVertex2d(.0, -40.);
	glVertex2d(.0, 40.);
	//��������� ��������� ����
	glEnd();
	glColor3d(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < n; i++)
	{
		x = nodes[i].x;
		y = nodes[i].y;
		for (int j = 0; j < n; j++)
		{
			if (edge[i][j]!=0)
			{
				glVertex2d(x, y);
				glVertex2d(nodes[j].x, nodes[j].y);
				glTranslated(x, y, 0);				
			}
		}
	}	
	glEnd();	
	glFlush();	
}
void RigidBody::update()
{

}
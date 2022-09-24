#include <iostream>
#include <GL/freeglut.h>


// ����������ڵĴ�С
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

// �����������ľ���
GLfloat G_fDistance = 3.6f;

// �������ת�Ƕ�
GLfloat G_fAngle_horizon = 0.0f;
GLfloat G_fAngle_vertical = 0.0f;

// �û���ʼ������
void myInit(void)
{
	glEnable(GL_DEPTH_TEST);

	//	glEnable(GL_ALPHA_TEST);
	//	glAlphaFunc( GL_GREATER, 0.5f );
	//	GLfloat a = 0.0f;
}

// ���ڴ�С�仯ʱ�Ļص�����
void myReshape(GLsizei w, GLsizei h)
{
	printf("myReshape w: %d, h: %d\n", w, h);

	// �趨����
	glViewport(0, 0, w, h);

	// �趨͸�ӷ�ʽ
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1.0 * (GLfloat)w / (GLfloat)h, 1.0, 30.0);

	//	gluPerspective(60.0, 1.0, 1.0, 30.0);	//�������ڱ���ʱ��������
	//  glFrustum (-1.0, 1.0, -1.0, 1.0, 1.0, 30.0);
}

// ÿ��OpenGL�����������������û�Ӧ�ð���ʾ����������������
void display()
{
	// ���������Ļ����ɫ���������Ļ����Ȼ���
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//	glEnable(GL_ALPHA_TEST);
	//	glAlphaFunc(GL_LESS, 0.5f);

	// ���ó�ģ�;���ģʽ
	glMatrixMode(GL_MODELVIEW);

	// ���뵥λ������
	glLoadIdentity();

	// ����������Z��ƽ�� -G_fDistance (ʹ��������λ�������ǰ��)
	glTranslatef(0.0, 0.0, -G_fDistance);
	glRotatef(G_fAngle_horizon, 0.0f, 1.0f, 0.0f);
	glRotatef(G_fAngle_vertical, 1.0f, 0.0f, 0.0f);


	//////////////////////////////////////
	// ��������
	// ��һ����������
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glVertex3f( 1.0f, -1.0f, 0.0f);
		glVertex3f( 1.0f,  1.0f, 0.0f);
		glVertex3f(-1.0f,  1.0f, 0.0f);
	glEnd();


	// ��һ�����
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	glutWireTeapot(1.0);
	//glutSolidTeapot(1.0);

	// ����ǰ�󻺳���
	glutSwapBuffers();
	glFinish();
}

void processSpecialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		G_fAngle_horizon -= 5.0f;
		break;

	case GLUT_KEY_RIGHT:
		G_fAngle_horizon += 5.0f;
		break;

	case GLUT_KEY_UP:
		G_fAngle_vertical -= 5.0f;
		break;

	case GLUT_KEY_DOWN:
		G_fAngle_vertical += 5.0f;
		break;

	default:
		break;
	}

	// glutPostRedisplay();
}

void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 97:  // 'a'
		G_fDistance -= 0.3f;
		break;

	case 65:  // 'A'
		G_fDistance += 0.3f;
		break;

	case 27:
		exit(0);

	}

	//	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	// ��ʼ��OPENGL��ʾ��ʽ
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	// �趨OPENGL����λ�úʹ�С
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);

	// �򿪴���
	glutCreateWindow("OpenGL");


	// ���ó�ʼ������
	myInit();

	// �趨���ڴ�С�仯�Ļص�����
	glutReshapeFunc(myReshape);

	// �趨���̿��ƵĻص�����
	glutSpecialFunc(processSpecialKeys);
	glutKeyboardFunc(processNormalKeys);



	// ��ʼOPENGL��ѭ��
	glutDisplayFunc(display);

	glutIdleFunc(display);

	glutMainLoop();

	return 0;
}
#include <iostream>
#include <GL/freeglut.h>

int main(int argc, char* argv[])
{
	std::cout << "Hello OpenGL." << std::endl;

	glutInit(&argc, argv);

	// ��ʾģʽ��ʼ��
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	// ���崰�ڴ�С
	glutInitWindowSize(300, 300);

	// ���崰��λ��
	glutInitWindowPosition(100, 100);

	// ��������
	glutCreateWindow("OpenGL Version");

	const unsigned char* version = glGetString(GL_VERSION);

	printf("OpenGL Version: %s\n", version);

	// ����GLUT�¼�����ѭ��������ѭ��
	glutMainLoop();

	return 0;
}


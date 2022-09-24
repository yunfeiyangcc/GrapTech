#include <iostream>
#include <GL/freeglut.h>

int main(int argc, char* argv[])
{
	std::cout << "Hello OpenGL." << std::endl;

	glutInit(&argc, argv);

	// 显示模式初始化
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	// 定义窗口大小
	glutInitWindowSize(300, 300);

	// 定义窗口位置
	glutInitWindowPosition(100, 100);

	// 创建窗口
	glutCreateWindow("OpenGL Version");

	const unsigned char* version = glGetString(GL_VERSION);

	printf("OpenGL Version: %s\n", version);

	// 进入GLUT事件处理循环，无限循环
	glutMainLoop();

	return 0;
}


#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include "Cubic.h"
#include "Solver.h"

Cubic cubic_test;
double rotate_y = -25;
double rotate_x = -25;
std::vector<std::string> function_buffer;

void dysplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

	cubic_test.drow();

	glFlush();
	glutSwapBuffers();

}

void timer(int = 0) {
	
	if (!function_buffer.empty()) {
		if (function_buffer[0] == "U")
			cubic_test.U();
		else if (function_buffer[0] == "U'")
			cubic_test.U_();
		else if (function_buffer[0] == "D")
			cubic_test.D();
		else if (function_buffer[0] == "D'")
			cubic_test.D_();
		else if (function_buffer[0] == "L")
			cubic_test.L();
		else if (function_buffer[0] == "L'")
			cubic_test.L_();
		else if (function_buffer[0] == "F")
			cubic_test.F();
		else if (function_buffer[0] == "F'")
			cubic_test.F_();
		else if (function_buffer[0] == "R")
			cubic_test.R();
		else if (function_buffer[0] == "R'")
			cubic_test.R_();
		else if (function_buffer[0] == "B")
			cubic_test.B();
		else if (function_buffer[0] == "B'")
			cubic_test.B_();
		else if (function_buffer[0] == "y")
			cubic_test.y();
		else if (function_buffer[0] == "Dw")
			cubic_test.Dw();
		else if (function_buffer[0] == "U2") {
			cubic_test.U();
			cubic_test.U();
		}	
		else if (function_buffer[0] == "R2") {
			cubic_test.R();
			cubic_test.R();
		}	
		else if (function_buffer[0] == "L2") {
			cubic_test.L();
			cubic_test.L();
		}
		else if (function_buffer[0] == "D2") {
			cubic_test.D();
			cubic_test.D();
		}	
		else if (function_buffer[0] == "F2") {
			cubic_test.F();
			cubic_test.F();
		}
		else if (function_buffer[0] == "B2") {
			cubic_test.B();
			cubic_test.B();
		}
			
		function_buffer.erase(function_buffer.begin());
		glutTimerFunc(100, timer, 0);
	}
	
}

void specialKeys(int key, int x, int y) {

	if (key == GLUT_KEY_RIGHT)
		rotate_y += 20;

	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 20;

	else if (key == GLUT_KEY_UP)
		rotate_x += 20;

	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 20;

	glutPostRedisplay();
}

int main(int argc, char* argv[]) {

	int width = 640;
	int heigth = 640;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(width, heigth);

	glutCreateWindow("Rubic Cube");
	glEnable(GL_DEPTH_TEST);

	std::string function;

	while (function != "0") {
		std::cin >> function;
		if (function == "U")
			cubic_test.U();
		else if (function == "U'")
			cubic_test.U_();
		else if (function == "D")
			cubic_test.D();
		else if (function == "D'")
			cubic_test.D_();
		else if (function == "L")
			cubic_test.L();
		else if (function == "L'")
			cubic_test.L_();
		else if (function == "F")
			cubic_test.F();
		else if (function == "F'")
			cubic_test.F_();
		else if (function == "R")
			cubic_test.R();
		else if (function == "R'")
			cubic_test.R_();
		else if (function == "B")
			cubic_test.B();
		else if (function == "B'")
			cubic_test.B_();
		else if (function == "y")
			cubic_test.y();
		else if (function == "Dw")
			cubic_test.Dw();
		else if (function == "U2") {
			cubic_test.U();
			cubic_test.U();
		}	
		else if (function == "R2") {
			cubic_test.R();
			cubic_test.R();
		}
		else if (function == "L2") {
			cubic_test.L();
			cubic_test.L();
		}
		else if (function == "D2") {
			cubic_test.D();
			cubic_test.D();
		}
		else if (function == "B2") {
			cubic_test.B();
			cubic_test.B();
		}
		else if (function == "F2") {
			cubic_test.F();
			cubic_test.F();
		}
			
	}

	Solver n(cubic_test);

	std::chrono::steady_clock::time_point start_time;
	std::chrono::steady_clock::time_point end_time;
	std::chrono::microseconds duration;

	start_time = std::chrono::steady_clock::now();
	n.Cross();
	n.Right_Cross();
	n.FirstLayer(0);
	n.SecondLayer(0); //~90 поворотов
	n.YellowCross();
	n.OLL();
	n.RightUpperCross();
	n.Centers();
	end_time = std::chrono::steady_clock::now();

	function_buffer = n.GetSolve();

	duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time); //4 * 10^(-3) секунд
	std::cout << "Build time" << duration.count();

	glutDisplayFunc(dysplay);
	glutSpecialFunc(specialKeys);
	timer();
	
	glutMainLoop();

	return 0;
}
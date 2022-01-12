#pragma once
#define GL_GLEXT_PROTOTYPES
#include <glut.h>

class Cubic {
public:
	std::vector<char> upper_face; //yellow
	std::vector<char> down_face; //white
	std::vector<char> front_face; //green
	std::vector<char> back_face; //blue
	std::vector<char> right_face; //orange
	std::vector<char> left_face;//red

	Cubic() {
		upper_face = { 'y','y','y','y','y','y','y','y','y' };//	8 7 6
															 // 5 4 3
															 // 2 1 0
		down_face  = { 'w','w','w','w','w','w','w','w','w' };
		front_face = { 'g','g','g','g','g','g','g','g','g' };
		back_face  = { 'b','b','b','b','b','b','b','b','b' };
		right_face = { 'o','o','o','o','o','o','o','o','o' };
		left_face =  { 'r','r','r','r','r','r','r','r','r' };
	}

	void U() {//по часовой стрелке
		std::vector<char> tmp;

		tmp = upper_face;
		upper_face[0] = tmp[6];
		upper_face[1] = tmp[3];
		upper_face[2] = tmp[0];
		upper_face[3] = tmp[7];
		upper_face[5] = tmp[1];
		upper_face[6] = tmp[8];
		upper_face[7] = tmp[5];
		upper_face[8] = tmp[2];

		tmp.clear();

		tmp.push_back(front_face[6]);
		tmp.push_back(front_face[7]);
		tmp.push_back(front_face[8]);

		//right -> front
		front_face[6] = right_face[6];
		front_face[7] = right_face[7];
		front_face[8] = right_face[8];

		std::vector<char> tmp2;
		tmp2.push_back(left_face[6]);
		tmp2.push_back(left_face[7]);
		tmp2.push_back(left_face[8]);

		//front -> left
		left_face[6] = tmp[0];
		left_face[7] = tmp[1];
		left_face[8] = tmp[2];

		tmp[0] = back_face[6];
		tmp[1] = back_face[7];
		tmp[2] = back_face[8];

		//left  -> back
		back_face[6] = tmp2[0];
		back_face[7] = tmp2[1];
		back_face[8] = tmp2[2];

		//back  -> right
		right_face[6] = tmp[0];
		right_face[7] = tmp[1];
		right_face[8] = tmp[2];

		//вращение внутри грани
		
		//tmp.clear();
		//tmp2.clear();
		glutPostRedisplay();
	}

	void U_() {//против часовой стрелки
		//front -> right
		std::vector<char> tmp;

		//вращение внутри грани
		//8 7 6      / 6 3 0
		//5 4 3  --> / 7 4 1	
		//2 1 0		 / 8 5 2

		tmp = upper_face;
		upper_face[0] = tmp[2];
		upper_face[1] = tmp[5];
		upper_face[2] = tmp[8];
		upper_face[3] = tmp[1];
		upper_face[5] = tmp[7];
		upper_face[6] = tmp[0];
		upper_face[7] = tmp[3];
		upper_face[8] = tmp[6];

		tmp.clear();

		tmp.push_back(right_face[6]);
		tmp.push_back(right_face[7]);
		tmp.push_back(right_face[8]);

		
		right_face[6] = front_face[6];
		right_face[7] = front_face[7];
		right_face[8] = front_face[8];

		//right -> back
		std::vector<char> tmp2;
		tmp2.push_back(back_face[6]);
		tmp2.push_back(back_face[7]);
		tmp2.push_back(back_face[8]);

		back_face[6] = tmp[0];
		back_face[7] = tmp[1];
		back_face[8] = tmp[2];

		//back  -> left
		tmp[0] = left_face[6];
		tmp[1] = left_face[7];
		tmp[2] = left_face[8];

		left_face[6] = tmp2[0];
		left_face[7] = tmp2[1];
		left_face[8] = tmp2[2];
		//left  -> front
		front_face[6] = tmp[0];
		front_face[7] = tmp[1];
		front_face[8] = tmp[2];

		//tmp.clear();
		//tmp2.clear();
		glutPostRedisplay();
	}

	void D() {
		//front -> right
		std::vector<char> tmp;

		tmp = down_face;
		down_face[0] = tmp[6];
		down_face[1] = tmp[3];
		down_face[2] = tmp[0];
		down_face[3] = tmp[7];
		down_face[5] = tmp[1];
		down_face[6] = tmp[8];
		down_face[7] = tmp[5];
		down_face[8] = tmp[2];

		tmp.clear();

		tmp.push_back(right_face[0]);
		tmp.push_back(right_face[1]);
		tmp.push_back(right_face[2]);


		right_face[0] = front_face[0];
		right_face[1] = front_face[1];
		right_face[2] = front_face[2];

		//right -> back
		std::vector<char> tmp2;
		tmp2.push_back(back_face[0]);
		tmp2.push_back(back_face[1]);
		tmp2.push_back(back_face[2]);

		back_face[0] = tmp[0];
		back_face[1] = tmp[1];
		back_face[2] = tmp[2];

		//back  -> left
		tmp[0] = left_face[0];
		tmp[1] = left_face[1];
		tmp[2] = left_face[2];

		left_face[0] = tmp2[0];
		left_face[1] = tmp2[1];
		left_face[2] = tmp2[2];

		//left  -> front
		front_face[0] = tmp[0];
		front_face[1] = tmp[1];
		front_face[2] = tmp[2];

		//tmp.clear();
		//tmp2.clear();
		glutPostRedisplay();
	}

	void D_() {
		std::vector<char> tmp;

		tmp = down_face;
		down_face[0] = tmp[2];
		down_face[1] = tmp[5];
		down_face[2] = tmp[8];
		down_face[3] = tmp[1];
		down_face[5] = tmp[7];
		down_face[6] = tmp[0];
		down_face[7] = tmp[3];
		down_face[8] = tmp[6];

		tmp.clear();

		tmp.push_back(front_face[0]);
		tmp.push_back(front_face[1]);
		tmp.push_back(front_face[2]);

		//right -> front
		front_face[0] = right_face[0];
		front_face[1] = right_face[1];
		front_face[2] = right_face[2];

		std::vector<char> tmp2;
		tmp2.push_back(left_face[0]);
		tmp2.push_back(left_face[1]);
		tmp2.push_back(left_face[2]);

		//front -> left
		left_face[0] = tmp[0];
		left_face[1] = tmp[1];
		left_face[2] = tmp[2];

		tmp[0] = back_face[0];
		tmp[1] = back_face[1];
		tmp[2] = back_face[2];

		//left  -> back
		back_face[0] = tmp2[0];
		back_face[1] = tmp2[1];
		back_face[2] = tmp2[2];

		//back  -> right
		right_face[0] = tmp[0];
		right_face[1] = tmp[1];
		right_face[2] = tmp[2];

		//tmp.clear();
		//tmp2.clear();
		glutPostRedisplay();
	}

	void F() {		
		std::vector<char> tmp;

		tmp = front_face;
		front_face[0] = tmp[6];
		front_face[1] = tmp[3];
		front_face[2] = tmp[0];
		front_face[3] = tmp[7];
		front_face[5] = tmp[1];
		front_face[6] = tmp[8];
		front_face[7] = tmp[5];
		front_face[8] = tmp[2];

		tmp.clear();

		tmp.push_back(upper_face[0]);
		tmp.push_back(upper_face[1]);
		tmp.push_back(upper_face[2]);

		//left -> up
		upper_face[0] = left_face[6];
		upper_face[1] = left_face[3];
		upper_face[2] = left_face[0];

		std::vector<char> tmp2;
		tmp2.push_back(right_face[2]);
		tmp2.push_back(right_face[5]);
		tmp2.push_back(right_face[8]);

		//up -> right
		right_face[2] = tmp[0];
		right_face[5] = tmp[1];
		right_face[8] = tmp[2];

		tmp[0] = down_face[6];
		tmp[1] = down_face[7];
		tmp[2] = down_face[8];

		//right -> down
		down_face[6] = tmp2[2];
		down_face[7] = tmp2[1];
		down_face[8] = tmp2[0];

		//down -> left
		left_face[0] = tmp[0];
		left_face[3] = tmp[1];
		left_face[6] = tmp[2];
		
		//tmp.clear();
		//tmp2.clear();
		glutPostRedisplay();
	}

	void F_() {
		
		std::vector<char> tmp;

		tmp = front_face;
		front_face[0] = tmp[2];
		front_face[1] = tmp[5];
		front_face[2] = tmp[8];
		front_face[3] = tmp[1];
		front_face[5] = tmp[7];
		front_face[6] = tmp[0];
		front_face[7] = tmp[3];
		front_face[8] = tmp[6];

		tmp.clear();

		tmp.push_back(upper_face[0]);
		tmp.push_back(upper_face[1]);
		tmp.push_back(upper_face[2]);

		//right -> up
		upper_face[0] = right_face[2];
		upper_face[1] = right_face[5];
		upper_face[2] = right_face[8];

		std::vector<char> tmp2;
		tmp2.push_back(left_face[6]);
		tmp2.push_back(left_face[3]);
		tmp2.push_back(left_face[0]);

		//up -> left
		left_face[6] = tmp[0];
		left_face[3] = tmp[1];
		left_face[0] = tmp[2];

		tmp[0] = down_face[8];
		tmp[1] = down_face[7];
		tmp[2] = down_face[6];

		//left -> down
		down_face[8] = tmp2[0];
		down_face[7] = tmp2[1];
		down_face[6] = tmp2[2];

		//down -> right
		right_face[2] = tmp[0];
		right_face[5] = tmp[1];
		right_face[8] = tmp[2];

		//tmp.clear();
		//tmp2.clear();
		glutPostRedisplay();
	}

	void B() {
		std::vector<char> tmp;

		tmp = back_face;
		back_face[0] = tmp[6];
		back_face[1] = tmp[3];
		back_face[2] = tmp[0];
		back_face[3] = tmp[7];
		back_face[5] = tmp[1];
		back_face[6] = tmp[8];
		back_face[7] = tmp[5];
		back_face[8] = tmp[2];

		tmp.clear();

		tmp.push_back(left_face[2]);
		tmp.push_back(left_face[5]);
		tmp.push_back(left_face[8]);

		//up -> left
		left_face[2] = upper_face[8];
		left_face[5] = upper_face[7];
		left_face[8] = upper_face[6];

		std::vector<char> tmp2;
		tmp2.push_back(down_face[0]);
		tmp2.push_back(down_face[1]);
		tmp2.push_back(down_face[2]);

		//left -> down
		down_face[0] = tmp[0];
		down_face[1] = tmp[1];
		down_face[2] = tmp[2];

		tmp[0] = right_face[0];
		tmp[1] = right_face[3];
		tmp[2] = right_face[6];
		
		//down -> right
		right_face[0] = tmp2[2];
		right_face[3] = tmp2[1];
		right_face[6] = tmp2[0];

		//right -> up
		upper_face[6] = tmp[0];
		upper_face[7] = tmp[1];
		upper_face[8] = tmp[2];

		//tmp.clear();
		//tmp2.clear();
		glutPostRedisplay();
	}

	void B_() { //ПРОВЕРИТЬ
		std::vector<char> tmp;

		tmp = back_face;
		back_face[0] = tmp[2];
		back_face[1] = tmp[5];
		back_face[2] = tmp[8];
		back_face[3] = tmp[1];
		back_face[5] = tmp[7];
		back_face[6] = tmp[0];
		back_face[7] = tmp[3];
		back_face[8] = tmp[6];

		tmp.clear();

		tmp.push_back(upper_face[6]);
		tmp.push_back(upper_face[7]);
		tmp.push_back(upper_face[8]);

		//left -> up
		upper_face[6] = left_face[8];
		upper_face[7] = left_face[5];
		upper_face[8] = left_face[2];

		std::vector<char> tmp2;
		tmp2.push_back(right_face[6]);
		tmp2.push_back(right_face[3]);
		tmp2.push_back(right_face[0]);

		//up -> right
		right_face[6] = tmp[2];
		right_face[3] = tmp[1];
		right_face[0] = tmp[0];

		tmp[2] = down_face[2];
		tmp[1] = down_face[1];
		tmp[0] = down_face[0];

		//right -> down
		down_face[2] = tmp2[2];
		down_face[1] = tmp2[1];
		down_face[0] = tmp2[0];
		//down -> left
		left_face[8] = tmp[2];
		left_face[5] = tmp[1];
		left_face[2] = tmp[0];

		//tmp.clear();
		//tmp2.clear();
		glutPostRedisplay();
	}

	void R() {
		std::vector<char> tmp;

		tmp = right_face;
		right_face[0] = tmp[6];
		right_face[1] = tmp[3];
		right_face[2] = tmp[0];
		right_face[3] = tmp[7];
		right_face[5] = tmp[1];
		right_face[6] = tmp[8];
		right_face[7] = tmp[5];
		right_face[8] = tmp[2];

		tmp.clear();

		tmp.push_back(upper_face[0]);
		tmp.push_back(upper_face[3]);
		tmp.push_back(upper_face[6]);

		//front -> up
		upper_face[0] = front_face[0];
		upper_face[3] = front_face[3];
		upper_face[6] = front_face[6];

		std::vector<char> tmp2;
		tmp2.push_back(back_face[8]);
		tmp2.push_back(back_face[5]);
		tmp2.push_back(back_face[2]);

		//up -> back
		back_face[8] = tmp[0];
		back_face[5] = tmp[1];
		back_face[2] = tmp[2];

		tmp[0] = down_face[0];
		tmp[1] = down_face[3];
		tmp[2] = down_face[6];

		//back -> down
		down_face[0] = tmp2[0];
		down_face[3] = tmp2[1];
		down_face[6] = tmp2[2];

		//down -> front
		front_face[0] = tmp[0];
		front_face[3] = tmp[1];
		front_face[6] = tmp[2];

		//tmp.clear();
		//tmp2.clear();
		glutPostRedisplay();
	}

	void R_() {
		std::vector<char> tmp;

		tmp = right_face;
		right_face[0] = tmp[2];
		right_face[1] = tmp[5];
		right_face[2] = tmp[8];
		right_face[3] = tmp[1];
		right_face[5] = tmp[7];
		right_face[6] = tmp[0];
		right_face[7] = tmp[3];
		right_face[8] = tmp[6];

		tmp.clear();

		tmp.push_back(front_face[6]);
		tmp.push_back(front_face[3]);
		tmp.push_back(front_face[0]);

		//up -> front
		front_face[6] = upper_face[6];
		front_face[3] = upper_face[3];
		front_face[0] = upper_face[0];

		std::vector<char> tmp2;
		tmp2.push_back(down_face[6]);
		tmp2.push_back(down_face[3]);
		tmp2.push_back(down_face[0]);

		//front -> down
		down_face[6] = tmp[0];
		down_face[3] = tmp[1];
		down_face[0] = tmp[2];

		tmp[0] = back_face[2];
		tmp[1] = back_face[5];
		tmp[2] = back_face[8];

		//down -> back
		back_face[2] = tmp2[0];
		back_face[5] = tmp2[1];
		back_face[8] = tmp2[2];

		//back -> up
		upper_face[6] = tmp[0];
		upper_face[3] = tmp[1];
		upper_face[0] = tmp[2];

		//tmp.clear();
		//tmp2.clear();
		glutPostRedisplay();
	}

	void L() {
		std::vector<char> tmp;

		tmp = left_face;
		left_face[0] = tmp[6];
		left_face[1] = tmp[3];
		left_face[2] = tmp[0];
		left_face[3] = tmp[7];
		left_face[5] = tmp[1];
		left_face[6] = tmp[8];
		left_face[7] = tmp[5];
		left_face[8] = tmp[2];

		tmp.clear();

		tmp.push_back(front_face[8]);
		tmp.push_back(front_face[5]);
		tmp.push_back(front_face[2]);

		//up -> front
		front_face[8] = upper_face[8];
		front_face[5] = upper_face[5];
		front_face[2] = upper_face[2];

		std::vector<char> tmp2;
		tmp2.push_back(down_face[8]);
		tmp2.push_back(down_face[5]);
		tmp2.push_back(down_face[2]);

		//front -> down
		down_face[8] = tmp[0];
		down_face[5] = tmp[1];
		down_face[2] = tmp[2];

		tmp[0] = back_face[6];
		tmp[1] = back_face[3];
		tmp[2] = back_face[0];

		//down -> back
		back_face[6] = tmp2[2];
		back_face[3] = tmp2[1];
		back_face[0] = tmp2[0];

		//back -> up
		upper_face[8] = tmp[2];
		upper_face[5] = tmp[1];
		upper_face[2] = tmp[0];

		//tmp.clear();
		//tmp2.clear();
		glutPostRedisplay();
	}

	void L_() {
		std::vector<char> tmp;

		tmp = left_face;
		left_face[0] = tmp[2];
		left_face[1] = tmp[5];
		left_face[2] = tmp[8];
		left_face[3] = tmp[1];
		left_face[5] = tmp[7];
		left_face[6] = tmp[0];
		left_face[7] = tmp[3];
		left_face[8] = tmp[6];

		tmp.clear();

		tmp.push_back(upper_face[8]);
		tmp.push_back(upper_face[5]);
		tmp.push_back(upper_face[2]);

		//front -> up
		upper_face[8] = front_face[8];
		upper_face[5] = front_face[5];
		upper_face[2] = front_face[2];

		std::vector<char> tmp2;
		tmp2.push_back(back_face[6]);
		tmp2.push_back(back_face[3]);
		tmp2.push_back(back_face[0]);

		//up -> back
		back_face[6] = tmp[2];
		back_face[3] = tmp[1];
		back_face[0] = tmp[0];

		tmp[0] = down_face[2];
		tmp[1] = down_face[5];
		tmp[2] = down_face[8];

		//back -> down
		down_face[2] = tmp2[0];
		down_face[5] = tmp2[1];
		down_face[8] = tmp2[2];

		//down -> front
		front_face[2] = tmp[0];
		front_face[5] = tmp[1];
		front_face[8] = tmp[2];

		
		//tmp.clear();
		//tmp2.clear();
		glutPostRedisplay();
	}

	void y() {
		std::vector<char> tmp = upper_face;
		upper_face = front_face;

		std::vector<char> tmp2 = back_face;

		for(int i = 0; i < 9; i++)
			back_face[i] = tmp[8-i];

		tmp = down_face;

		for(int i = 0; i < 9; i++)
			down_face[i] = tmp2[8-i];

		front_face = tmp;

		tmp = left_face;
		left_face[0] = tmp[2];
		left_face[1] = tmp[5];
		left_face[2] = tmp[8];
		left_face[3] = tmp[1];
		left_face[5] = tmp[7];
		left_face[6] = tmp[0];
		left_face[7] = tmp[3];
		left_face[8] = tmp[6];

		tmp = right_face;
		right_face[0] = tmp[6];
		right_face[1] = tmp[3];
		right_face[2] = tmp[0];
		right_face[3] = tmp[7];
		right_face[5] = tmp[1];
		right_face[6] = tmp[8];
		right_face[7] = tmp[5];
		right_face[8] = tmp[2];

		//tmp.clear();
		//tmp2.clear();
		glutPostRedisplay();
	}

	void Dw() {
		std::vector<char> tmp;

		tmp = down_face;
		down_face[0] = tmp[6];
		down_face[1] = tmp[3];
		down_face[2] = tmp[0];
		down_face[3] = tmp[7];
		down_face[5] = tmp[1];
		down_face[6] = tmp[8];
		down_face[7] = tmp[5];
		down_face[8] = tmp[2];

		tmp.clear();

		tmp.push_back(right_face[0]);
		tmp.push_back(right_face[1]);
		tmp.push_back(right_face[2]);
		tmp.push_back(right_face[3]);
		tmp.push_back(right_face[4]);
		tmp.push_back(right_face[5]);


		right_face[0] = front_face[0];
		right_face[1] = front_face[1];
		right_face[2] = front_face[2];
		right_face[3] = front_face[3];
		right_face[4] = front_face[4];
		right_face[5] = front_face[5];

		//right -> back
		std::vector<char> tmp2;
		tmp2.push_back(back_face[0]);
		tmp2.push_back(back_face[1]);
		tmp2.push_back(back_face[2]);
		tmp2.push_back(back_face[3]);
		tmp2.push_back(back_face[4]);
		tmp2.push_back(back_face[5]);

		back_face[0] = tmp[0];
		back_face[1] = tmp[1];
		back_face[2] = tmp[2];
		back_face[3] = tmp[3];
		back_face[4] = tmp[4];
		back_face[5] = tmp[5];

		//back  -> left
		tmp[0] = left_face[0];
		tmp[1] = left_face[1];
		tmp[2] = left_face[2];
		tmp[3] = left_face[3];
		tmp[4] = left_face[4];
		tmp[5] = left_face[5];

		left_face[0] = tmp2[0];
		left_face[1] = tmp2[1];
		left_face[2] = tmp2[2];
		left_face[3] = tmp2[3];
		left_face[4] = tmp2[4];
		left_face[5] = tmp2[5];

		//left  -> front
		front_face[0] = tmp[0];
		front_face[1] = tmp[1];
		front_face[2] = tmp[2];
		front_face[3] = tmp[3];
		front_face[4] = tmp[4];
		front_face[5] = tmp[5];

		//tmp.clear();
		//tmp2.clear();
		glutPostRedisplay();

	}

	void drow() {
		double size = 0.3, koef_distance = 0.02;
		double big_cube_size = 3 * size + 2 * koef_distance;
		double norm = big_cube_size/2;

		//Green Side - front - 0.0 1.0 0.0
		double x = norm, y = -norm, z = -norm;

		int index = 0;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {

				std::vector<float> color = GetFrontFaceColor(index);

				glBegin(GL_POLYGON);
				glColor3f(color[0], color[1], color[2]);

				glVertex3f(x, y, z); // x y z
				glVertex3f(x, y + size, z);
				glVertex3f(x - size, y + size, z);
				glVertex3f(x - size, y, z);

				glEnd();

				x = x -(size + koef_distance);
				index++;
			}
			x = norm;
			y += size + koef_distance;
		}

		//Blue Side - Back - 0.0 0.0 1.0
		index = 0;
		x = norm - big_cube_size;
		y = -norm;
		z = -norm+big_cube_size;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {

				std::vector<float> color = GetBackFaceColor(index);

				glBegin(GL_POLYGON);
				glColor3f(color[0], color[1], color[2]);

				glVertex3f(x, y, z);
				glVertex3f(x, y + size, z);
				glVertex3f(x + size, y + size, z);
				glVertex3f(x + size, y, z);

				glEnd();
				index++;

				x = x + size + koef_distance;
			}
			x = norm - big_cube_size;
			y += size + koef_distance;
		}

		// Orange side - RIGHT - 1.0 0.647 0.0
		index = 0;
		x = norm;
		y = -norm;
		z = -norm+big_cube_size;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::vector<float> color = GetRightFaceColor(index);

				glBegin(GL_POLYGON);
				glColor3f(color[0], color[1], color[2]);

				glVertex3f(x, y, z);
				glVertex3f(x, y + size, z);
				glVertex3f(x, y + size, z - size);
				glVertex3f(x, y, z - size);

				glEnd();
				index++;

				z = z - (size + koef_distance);
			}
			z = -norm+big_cube_size;
			y += size + koef_distance;
		}

		// Red side - LEFT - 1.0 0.0 0.0
		index = 0;
		x = norm-big_cube_size;
		y = -norm;
		z = -norm;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::vector<float> color = GetLeftFaceColor(index);
				glBegin(GL_POLYGON);
				glColor3f(color[0], color[1], color[2]);

				glVertex3f(x, y, z);
				glVertex3f(x, y + size, z);
				glVertex3f(x, y + size, z + size);
				glVertex3f(x, y, z + size);

				glEnd();
				index++;

				z += size + koef_distance;
			}

			z = -norm;
			y += size + koef_distance;
		}

		// Yellow side - Up - 1.0 1.0 0.0
		index = 0;
		x = norm;
		z = -norm;
		y = -norm+big_cube_size;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::vector<float> color = GetUpperFaceColor(index);
				glBegin(GL_POLYGON);
				glColor3f(color[0], color[1], color[2]);

				glVertex3f(x, y, z);
				glVertex3f(x, y, z + size);
				glVertex3f(x - size, y, z + size);
				glVertex3f(x - size, y, z);

				glEnd();
				index++;

				x = x - (size + koef_distance);
			}
			x = norm;
			z += size + koef_distance;
		}

		// White side - Down - 1.0 1.0 1.0
		index = 0;
		x = norm;
		y = -norm;
		z = -norm+big_cube_size;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::vector<float> color = GetDownFaceColor(index);
				glBegin(GL_POLYGON);
				glColor3f(color[0], color[1], color[2]);

				glVertex3f(x, y, z);
				glVertex3f(x, y, z - size);
				glVertex3f(x - size, y, z - size);
				glVertex3f(x - size, y, z);

				glEnd();
				index++;

				x = x - (size + koef_distance);
			}
			x = norm;
			z = z - (size + koef_distance);
		}
	}

	std::vector <float> GetUpperFaceColor(int index) {
		std::vector <float> colors(3);
		if (upper_face[index] == 'y') {
			colors[0] = 0.90625;
			colors[1] = 0.43921;
			colors[2] = 0.0;
		}

		else if (upper_face[index] == 'w') {
			colors[0] = 0.95294;
			colors[1] = 0.95294;
			colors[2] = 0.95294;
		}

		else if (upper_face[index] == 'g') {
			colors[0] = 0.0;
			colors[1] = 0.61568;
			colors[2] = 0.32941;
		}

		else if (upper_face[index] == 'b') {
			colors[0] = 0.23921;
			colors[1] = 0.50588;
			colors[2] = 0.96470;
		}
		//0.647
		else if (upper_face[index] == 'o') {
			colors[0] = 0.96078;
			colors[1] = 0.70588;
			colors[2] = 0.0;
		}

		else if (upper_face[index] == 'r') {
			colors[0] = 0.86274;
			colors[1] = 0.25882;
			colors[2] = 0.18431;
		}

		return colors;
	}

	std::vector <float> GetBackFaceColor(int index) {
		std::vector <float> colors(3);
		if (back_face[index] == 'y') {
			colors[0] = 0.90625;
			colors[1] = 0.43921;
			colors[2] = 0.0;
		}

		else if (back_face[index] == 'w') {
			colors[0] = 0.95294;
			colors[1] = 0.95294;
			colors[2] = 0.95294;
		}

		else if (back_face[index] == 'g') {
			colors[0] = 0.0;
			colors[1] = 0.61568;
			colors[2] = 0.32941;
		}

		else if (back_face[index] == 'b') {
			colors[0] = 0.23921;
			colors[1] = 0.50588;
			colors[2] = 0.96470;
		}

		else if (back_face[index] == 'o') {
			colors[0] = 0.96078;
			colors[1] = 0.70588;
			colors[2] = 0.0;
		}

		else if (back_face[index] == 'r') {
			colors[0] = 0.86274;
			colors[1] = 0.25882;
			colors[2] = 0.18431;
		}

		return colors;
	}

	std::vector <float> GetDownFaceColor(int index) {
		std::vector <float> colors(3);
		if (down_face[index] == 'y') {
			colors[0] = 0.90625;
			colors[1] = 0.43921;
			colors[2] = 0.0;
		}

		else if (down_face[index] == 'w') {
			colors[0] = 0.95294;
			colors[1] = 0.95294;
			colors[2] = 0.95294;
		}

		else if (down_face[index] == 'g') {
			colors[0] = 0.0;
			colors[1] = 0.61568;
			colors[2] = 0.32941;
		}

		else if (down_face[index] == 'b') {
			colors[0] = 0.23921;
			colors[1] = 0.50588;
			colors[2] = 0.96470;
		}

		else if (down_face[index] == 'o') {
			colors[0] = 0.96078;
			colors[1] = 0.70588;
			colors[2] = 0.0;
		}

		else if (down_face[index] == 'r') {
			colors[0] = 0.86274;
			colors[1] = 0.25882;
			colors[2] = 0.18431;
		}

		return colors;
	}

	std::vector <float> GetLeftFaceColor(int index) {
		std::vector <float> colors(3);
		if (left_face[index] == 'y') {
			colors[0] = 0.90625;
			colors[1] = 0.43921;
			colors[2] = 0.0;
		}

		else if (left_face[index] == 'w') {
			colors[0] = 0.95294;
			colors[1] = 0.95294;
			colors[2] = 0.95294;
		}

		else if (left_face[index] == 'g') {
			colors[0] = 0.0;
			colors[1] = 0.61568;
			colors[2] = 0.32941;
		}

		else if (left_face[index] == 'b') {
			colors[0] = 0.23921;
			colors[1] = 0.50588;
			colors[2] = 0.96470;
		}

		else if (left_face[index] == 'o') {
			colors[0] = 0.96078;
			colors[1] = 0.70588;
			colors[2] = 0.0;
		}

		else if (left_face[index] == 'r') {
			colors[0] = 0.86274;
			colors[1] = 0.25882;
			colors[2] = 0.18431;
		}

		return colors;
	}

	std::vector <float> GetRightFaceColor(int index) {
		std::vector <float> colors(3);
		if (right_face[index] == 'y') {
			colors[0] = 0.90625;
			colors[1] = 0.43921;
			colors[2] = 0.0;
		}

		else if (right_face[index] == 'w') {
			colors[0] = 0.95294;
			colors[1] = 0.95294;
			colors[2] = 0.95294;
		}

		else if (right_face[index] == 'g') {
			colors[0] = 0.0;
			colors[1] = 0.61568;
			colors[2] = 0.32941;
		}

		else if (right_face[index] == 'b') {
			colors[0] = 0.23921;
			colors[1] = 0.50588;
			colors[2] = 0.96470;
		}

		else if (right_face[index] == 'o') {
			colors[0] = 0.96078;
			colors[1] = 0.70588;
			colors[2] = 0.0;
		}

		else if (right_face[index] == 'r') {
			colors[0] = 0.86274;
			colors[1] = 0.25882;
			colors[2] = 0.18431;
		}

		return colors;
	}

	std::vector <float> GetFrontFaceColor(int index) {
		std::vector <float> colors(3);
		if (front_face[index] == 'y') {
			colors[0] = 0.90625;
			colors[1] = 0.43921;
			colors[2] = 0.0;
		}

		else if (front_face[index] == 'w') {
			colors[0] = 0.95294;
			colors[1] = 0.95294;
			colors[2] = 0.95294;
		}

		else if (front_face[index] == 'g') {
			colors[0] = 0.0;
			colors[1] = 0.61568;
			colors[2] = 0.32941;
		}

		else if (front_face[index] == 'b') {
			colors[0] = 0.23921;
			colors[1] = 0.50588;
			colors[2] = 0.96470;
		}

		else if (front_face[index] == 'o') {
			colors[0] = 0.96078;
			colors[1] = 0.70588;
			colors[2] = 0.0;
		}

		else if (front_face[index] == 'r') {
			colors[0] = 0.86274;
			colors[1] = 0.25882;
			colors[2] = 0.18431;
		}

		return colors;
	}

	friend class Solver;
};
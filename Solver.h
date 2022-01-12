#pragma once

class Solver {

public:
	Cubic cub;
	std::vector <std::string> function_buffer_tmp;

	Solver(Cubic cubic) {
		cub = cubic;
	}

	void PiffPaff() {
		function_buffer_tmp.push_back("R");
		function_buffer_tmp.push_back("U");
		function_buffer_tmp.push_back("R'");
		function_buffer_tmp.push_back("U'");
		cub.R();
		cub.U();
		cub.R_();
		cub.U_();
	}

	bool CheckWhiteCross() {
		if (cub.down_face[1] == 'w' && cub.down_face[3] == 'w' && cub.down_face[5] == 'w' && cub.down_face[7] == 'w') return true;
		else return false;
	}

	bool IsAllowed(int index) {
		if (cub.down_face[index] != 'w') return true;
		else return false;
	}

	void Cross() {
		if (CheckWhiteCross()) return;

		if (cub.front_face[1] == 'w') {
			if (IsAllowed(3)) {

				function_buffer_tmp.push_back("F'");
				function_buffer_tmp.push_back("R'");
				cub.F_();
				cub.R_();
			}
			else {

				function_buffer_tmp.push_back("F'");
				cub.F_();

				while (!IsAllowed(3)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}

				function_buffer_tmp.push_back("R'");
				cub.R_();
			}
		}

		else if (cub.front_face[3] == 'w') {
			if (IsAllowed(3)) {
				function_buffer_tmp.push_back("R'");
				cub.R_();
			}
			else {

				while (!IsAllowed(3)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}
				function_buffer_tmp.push_back("R'");
				cub.R_();
			}

		}

		else if (cub.front_face[5] == 'w') {
			if (IsAllowed(5)) {
				function_buffer_tmp.push_back("L");
				cub.L();
			}
			else {
				while (!IsAllowed(5)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}

				function_buffer_tmp.push_back("L");
				cub.L();
			}
		}

		else if (cub.front_face[7] == 'w') {
			if (IsAllowed(3)) {
				function_buffer_tmp.push_back("F");
				cub.F();
				function_buffer_tmp.push_back("R'");
				cub.R_();
			}
			else {
				while (!IsAllowed(3)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}
				function_buffer_tmp.push_back("F");
				cub.F();
				function_buffer_tmp.push_back("R'");
				cub.R_();
			}
		}

		else if (cub.right_face[5] == 'w') {
			if (IsAllowed(7)) {
				function_buffer_tmp.push_back("F");
				cub.F();
			}
			else {
				while (!IsAllowed(7)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}
				function_buffer_tmp.push_back("F");
				cub.F();
			}
		}

		else if (cub.left_face[3] == 'w') {
			if (IsAllowed(7)) {
				function_buffer_tmp.push_back("F'");
				cub.F_();
			}

			else {
				while (!IsAllowed(7)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}
				function_buffer_tmp.push_back("F'");
				cub.F_();
			}
		}
		
		else if (cub.upper_face[1] == 'w') {
			if (IsAllowed(7)) {
				function_buffer_tmp.push_back("F");
				function_buffer_tmp.push_back("F");
				cub.F();
				cub.F();
			}
			else {
				while (!IsAllowed(7)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}
				function_buffer_tmp.push_back("F");
				function_buffer_tmp.push_back("F");
				cub.F();
				cub.F();
			}
		}

		else if (cub.right_face[1] == 'w') {
			if (IsAllowed(7)) {
				function_buffer_tmp.push_back("R");
				function_buffer_tmp.push_back("F");
				cub.R();
				cub.F();
			}
			else {
				function_buffer_tmp.push_back("R");
				cub.R();

				while (!IsAllowed(7)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}
				
				function_buffer_tmp.push_back("F");
				cub.F();
			}
		}

		else if(cub.right_face[3] == 'w') {
			if (IsAllowed(1)) {
				function_buffer_tmp.push_back("B'");
				cub.B_();
			}
			else {
				while (!IsAllowed(1)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}
				function_buffer_tmp.push_back("B'");
				cub.B_();
			}
		}

		else if (cub.right_face[7] == 'w') {
			if (IsAllowed(7)) {
				function_buffer_tmp.push_back("R'");
				function_buffer_tmp.push_back("F");
				cub.R_();
				cub.F();
			}
			else {
				while (!IsAllowed(7)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}
				function_buffer_tmp.push_back("R'");
				function_buffer_tmp.push_back("F");
				cub.R_();
				cub.F();
			}
		}

		else if (cub.upper_face[3] == 'w') {
			if (IsAllowed(3)) {
				function_buffer_tmp.push_back("R'");
				function_buffer_tmp.push_back("R'");
				cub.R_();
				cub.R_();
			}
			else {
				while (!IsAllowed(3)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}
				function_buffer_tmp.push_back("R'");
				function_buffer_tmp.push_back("R'");
				cub.R_();
				cub.R_();
			}
		}

		else if (cub.back_face[5] == 'w') {
			if (IsAllowed(3)) {
				function_buffer_tmp.push_back("R");
				cub.R();
			}
			else {
				while (!IsAllowed(3)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}
				function_buffer_tmp.push_back("R");
				cub.R();
			}
		}

		else if (cub.left_face[1] == 'w') {
			if (IsAllowed(7)) {
				function_buffer_tmp.push_back("L'");
				function_buffer_tmp.push_back("F'");
				cub.L_();
				cub.F_();
			}
			else {
				function_buffer_tmp.push_back("L'");
				cub.L_();

				while (!IsAllowed(7)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}

				function_buffer_tmp.push_back("F'");
				cub.F_();
			}
		}

		else if (cub.left_face[5] == 'w') {
			if (IsAllowed(1)) {
				function_buffer_tmp.push_back("B");
				cub.B();
			}
			else {
				while (!IsAllowed(1)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}
				function_buffer_tmp.push_back("B");
				cub.B();
			}
		}

		else if (cub.left_face[7] == 'w') {
			if (IsAllowed(7)) {
				function_buffer_tmp.push_back("L");
				function_buffer_tmp.push_back("F'");
				cub.L();
				cub.F_();
			}
			else {
				function_buffer_tmp.push_back("L");
				cub.L();

				while (!IsAllowed(7)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}
				
				function_buffer_tmp.push_back("F'");
				cub.F_();
			}
		}

		else if (cub.upper_face[5] == 'w') {
			if (IsAllowed(5)) {
				function_buffer_tmp.push_back("L");
				function_buffer_tmp.push_back("L");
				cub.L();
				cub.L();
			}
			else {
				while (!IsAllowed(5)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}
				function_buffer_tmp.push_back("L");
				function_buffer_tmp.push_back("L");
				cub.L();
				cub.L();
			}
		}

		else if (cub.back_face[3] == 'w') {
			if (IsAllowed(5)) {
				function_buffer_tmp.push_back("L'");
				cub.L_();
			}
			else {
				while (!IsAllowed(5)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}
				function_buffer_tmp.push_back("L'");
				cub.L_();
			}
		}

		else if (cub.back_face[1] == 'w') {
			if (IsAllowed(5)) {
				function_buffer_tmp.push_back("B'");
				function_buffer_tmp.push_back("L'");
				cub.B_();
				cub.L_();
			}
			else {
				function_buffer_tmp.push_back("B'");
				cub.B_();

				while (!IsAllowed(5)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}
				
				function_buffer_tmp.push_back("L'");
				cub.L_();
			}
		}

		else if (cub.back_face[7] == 'w') {
			if (IsAllowed(5)) {
				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("L'");
				cub.B();
				cub.L_();
			}
			else {
				while (!IsAllowed(5)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}
				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("L'");
				cub.B();
				cub.L_();
			}
		}

		else if (cub.upper_face[7] == 'w') {
			if (IsAllowed(1)) {
				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("B");
				cub.B();
				cub.B();
			}
			else {
				while (!IsAllowed(1)) {
					function_buffer_tmp.push_back("D");
					cub.D();
				}
				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("B");
				cub.B();
				cub.B();
			}
		}

		if (CheckWhiteCross()) return;
		else Cross();
	}

	int NumberOfMatchingEdges(bool &down_1, bool& down_3, bool& down_5, bool& down_7) {
		int number_of_matching_edges = 0;

		if (cub.front_face[4] == cub.front_face[1]) {
			number_of_matching_edges++;
			down_7 = true;
		}
			
		if (cub.left_face[4] == cub.left_face[1]) {
			number_of_matching_edges++;
			down_5 = true;
		}
			
		if (cub.right_face[4] == cub.right_face[1]) {
			number_of_matching_edges++;
			down_3 = true;
		}
			
		if (cub.back_face[4] == cub.back_face[1]) {
			number_of_matching_edges++;
			down_1 = true;
		}

		return number_of_matching_edges;
	}

	void Right_Cross() {

		bool down_1 = false, down_3 = false, down_5 = false, down_7 = false;

		if (NumberOfMatchingEdges(down_1, down_3, down_5, down_7) == 4) 
			return;

		else if (NumberOfMatchingEdges(down_1, down_3, down_5, down_7) == 3) {
			std::cout << "Imposiible situation\n";
			std::exit(1);
		}

		else if (NumberOfMatchingEdges(down_1, down_3, down_5, down_7) == 2) {
			if (!down_1 && !down_7) {

				function_buffer_tmp.push_back("F'");
				function_buffer_tmp.push_back("F'");
				cub.F_();
				cub.F_();

				function_buffer_tmp.push_back("U'");
				function_buffer_tmp.push_back("U'");
				cub.U_();
				cub.U_();

				function_buffer_tmp.push_back("B'");
				function_buffer_tmp.push_back("B'");
				cub.B_();
				cub.B_();

				function_buffer_tmp.push_back("U");
				function_buffer_tmp.push_back("U");
				cub.U();
				cub.U();

				function_buffer_tmp.push_back("F");
				function_buffer_tmp.push_back("F");
				cub.F();
				cub.F();
			}

			else if (!down_3 && !down_5) {
				function_buffer_tmp.push_back("R");
				function_buffer_tmp.push_back("R");
				cub.R();
				cub.R();

				function_buffer_tmp.push_back("U");
				function_buffer_tmp.push_back("U");
				cub.U();
				cub.U();

				function_buffer_tmp.push_back("L");
				function_buffer_tmp.push_back("L");
				cub.L();
				cub.L();

				function_buffer_tmp.push_back("U");
				function_buffer_tmp.push_back("U");
				cub.U();
				cub.U();

				function_buffer_tmp.push_back("R");
				function_buffer_tmp.push_back("R");
				cub.R();
				cub.R();
			}

			else if (!down_7 && !down_3) {
				function_buffer_tmp.push_back("R");
				function_buffer_tmp.push_back("R");
				cub.R();
				cub.R();

				function_buffer_tmp.push_back("U");
				cub.U();

				function_buffer_tmp.push_back("F");
				function_buffer_tmp.push_back("F");
				cub.F();
				cub.F();

				function_buffer_tmp.push_back("U'");
				cub.U_();

				function_buffer_tmp.push_back("R");
				function_buffer_tmp.push_back("R");
				cub.R();
				cub.R();
			}

			else if (!down_1 && !down_3) {
				function_buffer_tmp.push_back("R");
				function_buffer_tmp.push_back("R");
				cub.R();
				cub.R();

				function_buffer_tmp.push_back("U'");
				cub.U_();

				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("B");
				cub.B();
				cub.B();

				function_buffer_tmp.push_back("U");
				cub.U();

				function_buffer_tmp.push_back("R");
				function_buffer_tmp.push_back("R");
				cub.R();
				cub.R();
			}

			else if (!down_1 && !down_5) {
				function_buffer_tmp.push_back("L");
				function_buffer_tmp.push_back("L");
				cub.L();
				cub.L();

				function_buffer_tmp.push_back("U");
				cub.U();

				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("B");
				cub.B();
				cub.B();

				function_buffer_tmp.push_back("U'");
				cub.U_();

				function_buffer_tmp.push_back("L");
				function_buffer_tmp.push_back("L");
				cub.L();
				cub.L();
			}

			else if (!down_5 && !down_7) {
				function_buffer_tmp.push_back("L");
				function_buffer_tmp.push_back("L");
				cub.L();
				cub.L();

				function_buffer_tmp.push_back("U'");
				cub.U_();

				function_buffer_tmp.push_back("F");
				function_buffer_tmp.push_back("F");
				cub.F();
				cub.F();

				function_buffer_tmp.push_back("U");
				cub.U();

				function_buffer_tmp.push_back("L");
				function_buffer_tmp.push_back("L");
				cub.L();
				cub.L();
			}
		}

		else {
			function_buffer_tmp.push_back("D");
			cub.D();
			Right_Cross();
		}

	}

	int findCornerElement(int index) {

		char first_color, second_color;

		switch (index) {

		case 0:
			first_color = 'g';
			second_color = 'o';
			break;
		case 1:
			first_color = 'g';
			second_color = 'r';
			break;
		case 2:
			first_color = 'r';
			second_color = 'b';
			break;
		case 3:
			first_color = 'o';
			second_color = 'b';
			break;
		}

		//Перестать вращать когда совпадут 2 цвета
		while ( !( (cub.front_face[1] == first_color || cub.front_face[1] == second_color) && (cub.right_face[1] == first_color || cub.right_face[1] == second_color) ) ) { //вторую сторону проверять нужно
			function_buffer_tmp.push_back("D");
			cub.D();
		}

		int number_of_matching_colors = 0;
		int corner_index = 0;

		switch (corner_index) {

		case 0:
			number_of_matching_colors = 0;
			if (cub.down_face[6] == first_color || cub.down_face[6] == second_color || cub.down_face[6] == 'w')
				number_of_matching_colors++;
			if (cub.front_face[0] == first_color || cub.front_face[0] == second_color || cub.front_face[0] == 'w')
				number_of_matching_colors++;
			if (cub.right_face[2] == first_color || cub.right_face[2] == second_color || cub.right_face[2] == 'w')
				number_of_matching_colors++;
			if (number_of_matching_colors == 3) return 0;

		case 1:
			number_of_matching_colors = 0;
			if (cub.down_face[8] == first_color || cub.down_face[8] == second_color || cub.down_face[8] == 'w')
				number_of_matching_colors++;
			if (cub.front_face[2] == first_color || cub.front_face[2] == second_color || cub.front_face[2] == 'w')
				number_of_matching_colors++;
			if (cub.left_face[0] == first_color || cub.left_face[0] == second_color || cub.left_face[0] == 'w')
				number_of_matching_colors++;
			if (number_of_matching_colors == 3) return 1;

		case 2:
			number_of_matching_colors = 0;
			if (cub.down_face[0] == first_color || cub.down_face[0] == second_color || cub.down_face[0] == 'w')
				number_of_matching_colors++;
			if (cub.right_face[0] == first_color || cub.right_face[0] == second_color || cub.right_face[0] == 'w')
				number_of_matching_colors++;
			if (cub.back_face[2] == first_color || cub.back_face[2] == second_color || cub.back_face[2] == 'w')
				number_of_matching_colors++;
			if (number_of_matching_colors == 3) return 2;

		case 3:
			number_of_matching_colors = 0;
			if (cub.down_face[2] == first_color || cub.down_face[2] == second_color || cub.down_face[2] == 'w')
				number_of_matching_colors++;
			if (cub.left_face[2] == first_color || cub.left_face[2] == second_color || cub.left_face[2] == 'w')
				number_of_matching_colors++;
			if (cub.back_face[0] == first_color || cub.back_face[0] == second_color || cub.back_face[0] == 'w')
				number_of_matching_colors++;
			if (number_of_matching_colors == 3) return 3;

		case 4:
			number_of_matching_colors = 0;
			if (cub.upper_face[0] == first_color || cub.upper_face[0] == second_color || cub.upper_face[0] == 'w')
				number_of_matching_colors++;
			if (cub.front_face[6] == first_color || cub.front_face[6] == second_color || cub.front_face[6] == 'w')
				number_of_matching_colors++;
			if (cub.right_face[8] == first_color || cub.right_face[8] == second_color || cub.right_face[8] == 'w')
				number_of_matching_colors++;
			if (number_of_matching_colors == 3) return 4;

		case 5:
			number_of_matching_colors = 0;
			if (cub.upper_face[2] == first_color || cub.upper_face[2] == second_color || cub.upper_face[2] == 'w')
				number_of_matching_colors++;
			if (cub.front_face[8] == first_color || cub.front_face[8] == second_color || cub.front_face[8] == 'w')
				number_of_matching_colors++;
			if (cub.left_face[6] == first_color || cub.left_face[6] == second_color || cub.left_face[6] == 'w')
				number_of_matching_colors++;
			if (number_of_matching_colors == 3) return 5;

		case 6:
			number_of_matching_colors = 0;
			if (cub.upper_face[6] == first_color || cub.upper_face[6] == second_color || cub.upper_face[6] == 'w')
				number_of_matching_colors++;
			if (cub.right_face[6] == first_color || cub.right_face[6] == second_color || cub.right_face[6] == 'w')
				number_of_matching_colors++;
			if (cub.back_face[8] == first_color || cub.back_face[8] == second_color || cub.back_face[8] == 'w')
				number_of_matching_colors++;
			if (number_of_matching_colors == 3) return 6;

		case 7:
			number_of_matching_colors = 0;
			if (cub.upper_face[8] == first_color || cub.upper_face[8] == second_color || cub.upper_face[8] == 'w')
				number_of_matching_colors++;
			if (cub.left_face[8] == first_color || cub.left_face[8] == second_color || cub.left_face[8] == 'w')
				number_of_matching_colors++;
			if (cub.back_face[6] == first_color || cub.back_face[6] == second_color || cub.back_face[6] == 'w')
				number_of_matching_colors++;
			if (number_of_matching_colors == 3) return 7;
		}
	
	}

	void FirstLayer(int corner_index) {

		int corner;
		corner = findCornerElement(corner_index);
		corner_index++;

		if (corner == 0) {
			while (!(cub.down_face[6] == 'w' && cub.front_face[1] == cub.front_face[0] && cub.right_face[2] == cub.right_face[1])) {
				PiffPaff();
			}
		}

		else if (corner == 1) {
			function_buffer_tmp.push_back("F");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("F'");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("U'");
			cub.F();
			cub.U();
			cub.F_();
			cub.U_();
			cub.U_();

			while (!(cub.down_face[6] == 'w' && cub.front_face[1] == cub.front_face[0] && cub.right_face[2] == cub.right_face[1])) {
				PiffPaff();
			}
		}

		else if (corner == 2) {
			function_buffer_tmp.push_back("B");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("B'");
			cub.B();
			cub.U();
			cub.B_();

			while (!(cub.down_face[6] == 'w' && cub.front_face[1] == cub.front_face[0] && cub.right_face[2] == cub.right_face[1])) {
				PiffPaff();
			}
		}

		else if (corner == 3) {
			function_buffer_tmp.push_back("L");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("L'");
			function_buffer_tmp.push_back("U");
			cub.L();
			cub.U();
			cub.L_();
			cub.U();

			while (!(cub.down_face[6] == 'w' && cub.front_face[1] == cub.front_face[0] && cub.right_face[2] == cub.right_face[1])) {
				PiffPaff();
			}
		}

		else if (corner == 4) {
			while (!(cub.down_face[6] == 'w' && cub.front_face[1] == cub.front_face[0] && cub.right_face[2] == cub.right_face[1])) {
				PiffPaff();
			}
		}

		else if (corner == 5) {
			function_buffer_tmp.push_back("U'");
			cub.U_();

			while ( !(cub.down_face[6] == 'w' && cub.front_face[1] == cub.front_face[0] && cub.right_face[2] == cub.right_face[1])) {
				PiffPaff();
			}
		}

		else if (corner == 6) {
			function_buffer_tmp.push_back("U");
			cub.U();

			while (!(cub.down_face[6] == 'w' && cub.front_face[1] == cub.front_face[0] && cub.right_face[2] == cub.right_face[1])) {
				PiffPaff();
			}
		}

		else if (corner == 7) {
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("U");
			cub.U();
			cub.U();

			while (!(cub.down_face[6] == 'w' && cub.front_face[1] == cub.front_face[0] && cub.right_face[2] == cub.right_face[1])) {
				PiffPaff();
			}
		}

		if (corner_index > 3) {
			while (cub.front_face[4] != cub.front_face[1]) {
				function_buffer_tmp.push_back("D");
				cub.D();
			}
			return;
		}
		else FirstLayer(corner_index);
	}

	int findCenterElement(int index) {
		char first_color, second_color;

		switch (index) {

		case 0:
			first_color = 'g';
			second_color = 'o';
			break;
		case 1:
			first_color = 'g';
			second_color = 'r';
			break;
		case 2:
			first_color = 'r';
			second_color = 'b';
			break;
		case 3:
			first_color = 'o';
			second_color = 'b';
			break;
		}

		while (!((cub.front_face[4] == first_color || cub.front_face[4] == second_color) && (cub.right_face[4] == first_color || cub.right_face[4] == second_color))) { //вторую сторону проверять нужно
			function_buffer_tmp.push_back("Dw");
			cub.Dw();
		}

		int center_index = 0;
		int number_of_matching_colors = 0;

		switch (center_index) { //ищем центральный элемент

		case 0:
			if (cub.front_face[3] == first_color || cub.front_face[3] == second_color)
				number_of_matching_colors++;
			if (cub.right_face[5] == first_color || cub.right_face[5] == second_color)
				number_of_matching_colors++;
			if (number_of_matching_colors == 2) return 0;

		case 1:
			number_of_matching_colors = 0;
			if (cub.front_face[5] == first_color || cub.front_face[5] == second_color)
				number_of_matching_colors++;
			if (cub.left_face[3] == first_color || cub.left_face[3] == second_color)
				number_of_matching_colors++;
			if (number_of_matching_colors == 2) return 1;

		case 2:
			number_of_matching_colors = 0;
			if (cub.front_face[7] == first_color || cub.front_face[7] == second_color)
				number_of_matching_colors++;
			if (cub.upper_face[1] == first_color || cub.upper_face[1] == second_color)
				number_of_matching_colors++;
			if (number_of_matching_colors == 2) return 2;

		case 3:
			number_of_matching_colors = 0;
			if (cub.right_face[7] == first_color || cub.right_face[7] == second_color)
				number_of_matching_colors++;
			if (cub.upper_face[3] == first_color || cub.upper_face[3] == second_color)
				number_of_matching_colors++;
			if (number_of_matching_colors == 2) return 3;

		case 4:
			number_of_matching_colors = 0;
			if (cub.left_face[7] == first_color || cub.left_face[7] == second_color)
				number_of_matching_colors++;
			if (cub.upper_face[5] == first_color || cub.upper_face[5] == second_color)
				number_of_matching_colors++;
			if (number_of_matching_colors == 2) return 4;

		case 5:
			number_of_matching_colors = 0;
			if (cub.back_face[7] == first_color || cub.back_face[7] == second_color)
				number_of_matching_colors++;
			if (cub.upper_face[7] == first_color || cub.upper_face[7] == second_color)
				number_of_matching_colors++;
			if (number_of_matching_colors == 2) return 5;

		case 6:
			number_of_matching_colors = 0;
			if (cub.left_face[5] == first_color || cub.left_face[5] == second_color)
				number_of_matching_colors++;
			if (cub.back_face[3] == first_color || cub.back_face[3] == second_color)
				number_of_matching_colors++;
			if (number_of_matching_colors == 2) return 6;

		case 7:
			number_of_matching_colors = 0;
			if (cub.right_face[3] == first_color || cub.right_face[3] == second_color)
				number_of_matching_colors++;
			if (cub.back_face[5] == first_color || cub.back_face[5] == second_color)
				number_of_matching_colors++;
			if (number_of_matching_colors == 2) return 7;

		}
	}

	void ToRight() {
		function_buffer_tmp.push_back("U");
		function_buffer_tmp.push_back("R");
		function_buffer_tmp.push_back("U'");
		function_buffer_tmp.push_back("R'");
		function_buffer_tmp.push_back("U'");
		function_buffer_tmp.push_back("F'");
		function_buffer_tmp.push_back("U");
		function_buffer_tmp.push_back("F");
		cub.U();
		cub.R();
		cub.U_();
		cub.R_();
		cub.U_();
		cub.F_();
		cub.U();
		cub.F();
	}

	void ToLeft() {
		function_buffer_tmp.push_back("U'");
		function_buffer_tmp.push_back("F'");
		function_buffer_tmp.push_back("U");
		function_buffer_tmp.push_back("F");
		function_buffer_tmp.push_back("U");
		function_buffer_tmp.push_back("R");
		function_buffer_tmp.push_back("U'");
		function_buffer_tmp.push_back("R'");
		cub.U_();
		cub.F_();
		cub.U();
		cub.F();
		cub.U();
		cub.R();
		cub.U_();
		cub.R_();
	}

	void SecondLayer(int center_index) {

		int center;
		center = findCenterElement(center_index);
		center_index++;

		if (center == 0) { //
			if ((cub.front_face[3] == cub.front_face[4]) && (cub.right_face[5] == cub.right_face[4])) {
				if (center_index > 3) {
					return;
				}
				else {
					SecondLayer(center_index);
				}
			}
			else {
				ToRight();
				function_buffer_tmp.push_back("U");
				cub.U();

				if (cub.right_face[7] == cub.right_face[4]) {
					ToLeft();
				}
				else {
					function_buffer_tmp.push_back("U");
					cub.U();
					ToRight();
				}
			}
		}

		else if (center == 1) {

			function_buffer_tmp.push_back("F");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("F'");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("L'");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("L");

			cub.F();
			cub.U_();
			cub.F_();
			cub.U_();
			cub.L_();
			cub.U();
			cub.L();

			if (cub.right_face[7] == cub.right_face[4]) {
				ToLeft();
			}
			else {
				function_buffer_tmp.push_back("U");
				cub.U();
				ToRight();
			}
		} //

		else if (center == 2) {
			if (cub.front_face[7] == cub.front_face[4]) {
				ToRight();
			}
			else {
				function_buffer_tmp.push_back("U'");
				cub.U_();
				ToLeft();
			}
		}

		else if (center == 3) {
			if (cub.right_face[7] == cub.right_face[4]) {
				ToLeft();
			}
			else {
				function_buffer_tmp.push_back("U");
				cub.U();
				ToRight();
			}
		}

		else if (center == 4) {
			function_buffer_tmp.push_back("U'");
			cub.U_();
			if (cub.front_face[7] == cub.front_face[4]) {
				ToRight();
			}
			else {
				function_buffer_tmp.push_back("U'");
				cub.U_();
				ToLeft();
			}
		}

		else if (center == 5) {
			function_buffer_tmp.push_back("U");
			cub.U();
			if (cub.right_face[7] == cub.right_face[4]) {
				ToLeft();
			}
			else {
				function_buffer_tmp.push_back("U");
				cub.U();
				ToRight();
			}
		}

		else if (center == 6) {
			function_buffer_tmp.push_back("L");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("L'");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("B'");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("B");

			cub.L();
			cub.U_();
			cub.L_();
			cub.U_();
			cub.B_();
			cub.U();
			cub.B();

			if (cub.front_face[7] == cub.front_face[4]) {
				ToRight();
			}
			else {
				function_buffer_tmp.push_back("U'");
				cub.U_();
				ToLeft();
			}
		}

		else if (center == 7) {
			function_buffer_tmp.push_back("R'");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("B");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("B'");

			cub.R_();
			cub.U();
			cub.R();
			cub.U();
			cub.B();
			cub.U_();
			cub.B_();

			if (cub.front_face[7] == cub.front_face[4]) {
				ToRight();
			}
			else {
				function_buffer_tmp.push_back("U'");
				cub.U_();
				ToLeft();
			}
		}

		if (center_index > 3) {
			return;
		}
		else {
			SecondLayer(center_index);
		}
	}

	bool CheckYellowCross() {
		if (cub.upper_face[1] == 'y' && cub.upper_face[3] == 'y' && cub.upper_face[5] == 'y' && cub.upper_face[7] == 'y') return true;
		else return false;
	}

	void YellowCross() {
		if (CheckYellowCross()) return;

		if (cub.upper_face[1] != 'y' && cub.upper_face[3] != 'y' && cub.upper_face[5] != 'y' && cub.upper_face[7] != 'y') {
			function_buffer_tmp.push_back("F");
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("F'");

			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("U");

			function_buffer_tmp.push_back("F");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("R'");
			function_buffer_tmp.push_back("F'");

			cub.F();
			cub.R();
			cub.U();
			cub.R_();
			cub.U_();
			cub.F_();

			cub.U();
			cub.U();

			cub.F();
			cub.U();
			cub.R();
			cub.U_();
			cub.R_();
			cub.F_();
		}

		else if (cub.upper_face[5] == 'y' && cub.upper_face[7] == 'y') {
			function_buffer_tmp.push_back("F");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("R'");
			function_buffer_tmp.push_back("F'");

			cub.F();
			cub.U();
			cub.R();
			cub.U_();
			cub.R_();
			cub.F_();
		}

		else if (cub.upper_face[5] == 'y' && cub.upper_face[3] == 'y') {
			function_buffer_tmp.push_back("F");
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("F'");

			cub.F();
			cub.R();
			cub.U();
			cub.R_();
			cub.U_();
			cub.F_();
		}

		else {
			function_buffer_tmp.push_back("U");
			cub.U();
			YellowCross();
		}

	}

	void OLL() {
		if (cub.upper_face[1] == 'y' && cub.upper_face[2] == 'y' && cub.upper_face[3] == 'y' && cub.upper_face[5] == 'y' && cub.upper_face[7] == 'y' && cub.front_face[6] == 'y' && cub.right_face[6] == 'y') {
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");

			cub.R();
			cub.U();
			cub.R_();
			cub.U();
			cub.R();
			cub.U();
			cub.U();
			cub.R_();
		}

		else if (cub.upper_face[1] == 'y' && cub.upper_face[3] == 'y' && cub.upper_face[5] == 'y' && cub.upper_face[6] == 'y' && cub.upper_face[7] == 'y' && cub.front_face[8] == 'y' && cub.right_face[8] == 'y') {
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("R'");

			cub.R();
			cub.U();
			cub.U();
			cub.R_();
			cub.U_();
			cub.R();
			cub.U_();
			cub.R_();
		}

		else if (cub.upper_face[1] == 'y' && cub.upper_face[2] == 'y' && cub.upper_face[3] == 'y' && cub.upper_face[4] == 'y' && cub.upper_face[5] == 'y' && cub.upper_face[7] == 'y' && cub.upper_face[8] == 'y' && cub.right_face[6] == 'y' && cub.right_face[8] == 'y') {
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("R'");

			cub.R();
			cub.U();
			cub.U();
			cub.R_();
			cub.U_();
			cub.R();
			cub.U_();
			cub.R_();

			function_buffer_tmp.push_back("U'");
			cub.U_();

			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");

			cub.R();
			cub.U();
			cub.R_();
			cub.U();
			cub.R();
			cub.U();
			cub.U();
			cub.R_();
		}

		else if (cub.upper_face[0] == 'y' && cub.upper_face[1] == 'y' && cub.upper_face[2] == 'y'&& cub.upper_face[3] == 'y'&& cub.upper_face[4] == 'y'&& cub.upper_face[5] == 'y' && cub.upper_face[7] == 'y'&& cub.right_face[6] == 'y') {
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("R'");

			cub.R();
			cub.U();
			cub.U();
			cub.R_();
			cub.U_();
			cub.R();
			cub.U_();
			cub.R_();

			function_buffer_tmp.push_back("U");
			cub.U();

			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");

			cub.R();
			cub.U();
			cub.R_();
			cub.U();
			cub.R();
			cub.U();
			cub.U();
			cub.R_();
		}

		else if (cub.upper_face[0] == 'y' && cub.upper_face[1] == 'y'&& cub.upper_face[3] == 'y'&& cub.upper_face[4] == 'y'&& cub.upper_face[5] == 'y'&& cub.upper_face[7] == 'y'&& cub.upper_face[8] == 'y'&& cub.front_face[8] == 'y'&& cub.right_face[6] == 'y') {
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U'");
			function_buffer_tmp.push_back("R'");

			cub.R();
			cub.U();
			cub.U();
			cub.R_();
			cub.U_();
			cub.R();
			cub.U_();
			cub.R_();

			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("U");
			cub.U();
			cub.U();

			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");

			cub.R();
			cub.U();
			cub.R_();
			cub.U();
			cub.R();
			cub.U();
			cub.U();
			cub.R_();
		}

		else if (cub.upper_face[1] == 'y' && cub.upper_face[3] == 'y' && cub.upper_face[5] == 'y' && cub.upper_face[7] == 'y' && cub.right_face[6] == 'y' && cub.right_face[8] == 'y' && cub.upper_face[0] != 'y' && cub.upper_face[2] != 'y' && cub.upper_face[6] != 'y' && cub.upper_face[8] != 'y') {
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");

			cub.R();
			cub.U();
			cub.R_();
			cub.U();
			cub.R();
			cub.U();
			cub.U();
			cub.R_();

			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");

			cub.R();
			cub.U();
			cub.R_();
			cub.U();
			cub.R();
			cub.U();
			cub.U();
			cub.R_();
		}

		else if (cub.upper_face[1] == 'y' && cub.upper_face[3] == 'y' && cub.upper_face[5] == 'y' && cub.upper_face[7] == 'y' && cub.front_face[6] == 'y' && cub.front_face[8] != 'y' && cub.upper_face[0] != 'y' && cub.upper_face[2] != 'y' && cub.upper_face[6] != 'y' && cub.upper_face[8] != 'y') {
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");

			cub.R();
			cub.U();
			cub.R_();
			cub.U();
			cub.R();
			cub.U();
			cub.U();
			cub.R_();

			function_buffer_tmp.push_back("U'");
			cub.U_();

			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("U");
			function_buffer_tmp.push_back("R'");

			cub.R();
			cub.U();
			cub.R_();
			cub.U();
			cub.R();
			cub.U();
			cub.U();
			cub.R_();
		}

		else {
			function_buffer_tmp.push_back("U'");
			cub.U_();
			OLL();
		}

	}

	int NumberOfRightCorners(bool &corner_1, bool& corner_2, bool& corner_3, bool& corner_4) {
		int number_of_right_corners = 0;
		if (cub.front_face[8] == cub.front_face[4] && cub.left_face[6] == cub.left_face[4]) {
			number_of_right_corners++;
			corner_1 = true;
		}
			
		if (cub.left_face[8] == cub.left_face[4] && cub.back_face[6] == cub.back_face[4]) {
			number_of_right_corners++;
			corner_2 = true;
		}
			
		if (cub.back_face[8] == cub.back_face[4] && cub.right_face[6] == cub.right_face[4]) {
			number_of_right_corners++;
			corner_3 = true;
		}
			
		if (cub.right_face[8] == cub.right_face[4] && cub.front_face[6] == cub.front_face[4]) {
			number_of_right_corners++;
			corner_4 = true;
		}
			
		return number_of_right_corners;
	}

	void RightUpperCross() {
		int corners;
		bool corner_1 = false, corner_2 = false, corner_3 = false, corner_4 = false;

		while (NumberOfRightCorners(corner_1, corner_2, corner_3, corner_4) < 1) {
			function_buffer_tmp.push_back("U");
			cub.U();
			corner_1 = false;
			corner_2 = false;
			corner_3 = false;
			corner_4 = false;
		}

		corners = NumberOfRightCorners(corner_1, corner_2, corner_3, corner_4);

		if (corners == 4) return;

		else if (corners == 1) {

			if (corner_1) {
				
			}
			else if(corner_2) {
				function_buffer_tmp.push_back("U'");
				cub.U_();
			}
			else if (corner_3) {
				function_buffer_tmp.push_back("U");
				cub.U();
				function_buffer_tmp.push_back("U");
				cub.U();
			}
			else {
				function_buffer_tmp.push_back("U");
				cub.U();
			}

			if (cub.right_face[8] == cub.right_face[6]) {
				function_buffer_tmp.push_back("R");
				function_buffer_tmp.push_back("R");
				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("R");
				function_buffer_tmp.push_back("F");
				function_buffer_tmp.push_back("R'");
				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("R");
				function_buffer_tmp.push_back("F'");
				function_buffer_tmp.push_back("R");

				cub.R();
				cub.R();
				cub.B();
				cub.B();
				cub.R();
				cub.F();
				cub.R_();
				cub.B();
				cub.B();
				cub.R();
				cub.F_();
				cub.R();
			}
			else {
				function_buffer_tmp.push_back("R'");
				function_buffer_tmp.push_back("F");
				function_buffer_tmp.push_back("R'");
				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("R");
				function_buffer_tmp.push_back("F'");
				function_buffer_tmp.push_back("R'");
				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("R");
				function_buffer_tmp.push_back("R");

				cub.R_();
				cub.F();
				cub.R_();
				cub.B();
				cub.B();
				cub.R();
				cub.F_();
				cub.R_();
				cub.B();
				cub.B();
				cub.R();
				cub.R();
			}
		}

		else if (corners == 2) {
			if (corner_1 && corner_4 || corner_1 && corner_2 || corner_2 && corner_3 || corner_3 && corner_4) {
				
				corner_1 = false;
				corner_2 = false;
				corner_3 = false;
				corner_4 = false;

				while (NumberOfRightCorners(corner_1, corner_2, corner_3, corner_4) != 1) {
					function_buffer_tmp.push_back("U");
					cub.U();
					corner_1 = false;
					corner_2 = false;
					corner_3 = false;
					corner_4 = false;
				}

				RightUpperCross();
			}

			else {
				function_buffer_tmp.push_back("R");
				function_buffer_tmp.push_back("R");
				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("R");
				function_buffer_tmp.push_back("F");
				function_buffer_tmp.push_back("R'");
				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("B");
				function_buffer_tmp.push_back("R");
				function_buffer_tmp.push_back("F'");
				function_buffer_tmp.push_back("R");

				cub.R();
				cub.R();
				cub.B();
				cub.B();
				cub.R();
				cub.F();
				cub.R_();
				cub.B();
				cub.B();
				cub.R();
				cub.F_();
				cub.R();

				RightUpperCross();
			}

		}

		while (cub.front_face[8] != cub.front_face[4]) {
			function_buffer_tmp.push_back("U");
			cub.U();
		}
	}

	void Triangle() {
		function_buffer_tmp.push_back("R");
		function_buffer_tmp.push_back("U'");
		function_buffer_tmp.push_back("R");
		function_buffer_tmp.push_back("U");
		function_buffer_tmp.push_back("R");
		function_buffer_tmp.push_back("U");
		function_buffer_tmp.push_back("R");
		function_buffer_tmp.push_back("U'");
		function_buffer_tmp.push_back("R'");
		function_buffer_tmp.push_back("U'");
		function_buffer_tmp.push_back("R");
		function_buffer_tmp.push_back("R");

		cub.R();
		cub.U_();
		cub.R();
		cub.U();
		cub.R();
		cub.U();
		cub.R();
		cub.U_();
		cub.R_();
		cub.U_();
		cub.R();
		cub.R();
	}

	void Centers() {

		if (cub.front_face[7] == cub.right_face[8] && cub.right_face[7] == cub.left_face[8] && cub.left_face[7] == cub.front_face[8]) {
			Triangle();
		}

		else if (cub.front_face[7] == cub.left_face[8] && cub.right_face[7] == cub.front_face[8] && cub.left_face[7] == cub.right_face[8]) {
			Triangle();
			Triangle();
		}

		else if (cub.front_face[7] == cub.right_face[8] && cub.right_face[7] == cub.front_face[8] && cub.left_face[7] == cub.back_face[8] && cub.back_face[7] == cub.left_face[8]) {
			Triangle();

			function_buffer_tmp.push_back("U'");
			cub.U_();

			Triangle();
		}

		else if (cub.front_face[7] == cub.back_face[8] && cub.back_face[7] == cub.front_face[8] && cub.left_face[7] == cub.right_face[8] && cub.right_face[7] == cub.left_face[8]){
			Triangle();

			function_buffer_tmp.push_back("U");
			cub.U();

			Triangle();
		}

		else {
			function_buffer_tmp.push_back("U");
			cub.U();
			Centers();
		}

		while (cub.front_face[7] != cub.front_face[4]) {
			function_buffer_tmp.push_back("U");
			cub.U();
		}

	}

	std::vector <std::string> GetSolve() {
		return function_buffer_tmp;
	}
};
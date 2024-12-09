void glider(char** world){
	world[1][0] = '@';
	world[2][1] = '@';
	world[0][2] = '@';
	world[1][2] = '@';
	world[2][2] = '@';
}

void glider_2(char** world){
	world[1][8] = '@';
	world[2][9] = '@';
	world[0][10] = '@';
	world[1][10] = '@';
	world[2][10] = '@';
}

void pilar(char** world){
	world[10][10] = '@';
	world[10][11] = '@';
	world[10][12] = '@';
	world[10][13] = '@';
	world[10][14] = '@';
	world[10][15] = '@';
	world[10][16] = '@';
	world[10][17] = '@';
	world[11][10] = '@';
	world[11][11] = '@';
	world[11][12] = '@';
	world[11][13] = '@';
	world[11][14] = '@';
	world[11][15] = '@';
	world[11][16] = '@';
	world[11][17] = '@';

	world[8][10] = '@';
	world[8][11] = '@';
	world[8][12] = '@';
	world[8][13] = '@';
	world[8][14] = '@';
	world[8][15] = '@';
	world[8][16] = '@';
	world[8][17] = '@';
	world[9][10] = '@';
	world[9][11] = '@';
	world[9][12] = '@';
	world[9][13] = '@';
	world[9][14] = '@';
	world[9][15] = '@';
	world[9][16] = '@';
	world[9][17] = '@';
}

void thing_1(char** world){
	world[5][5] = '@';
	world[5][6] = '@';
	world[5][7] = '@';
	world[6][6] = '@';
	world[7][6] = '@';
	world[8][6] = '@';
}

void thing_2(char** world){
	world[18][20] = '@';
	world[19][21] = '@';
	world[20][22] = '@';
	world[21][23] = '@';
	world[22][24] = '@';
	world[18][21] = '@';
	world[18][22] = '@';
	world[18][23] = '@';
	world[18][24] = '@';
}

void thing_3(char** world){
	world[21][17] = '@';
	world[22][17] = '@';
	world[23][17] = '@';
	world[21][18] = '@';
	world[21][19] = '@';
	world[21][19] = '@';
}



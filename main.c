#include <stdio.h>
#include <stdlib.h>
#include "automatas.h"

#define WD 30 //world width
	

char** create_empty_buffer(){
	const char DEAD_C = ' ';

	char **buffer = malloc(WD * sizeof(char*));
	for(int x = 0; x < WD; x++){
		buffer[x] = malloc(WD * sizeof(char));
		for(int y = 0; y < WD; y++){
			buffer[x][y] = DEAD_C;
		}
	}
	return buffer;
}


char** copy_buffer(char** world){ 
	char **buffer = malloc(WD * sizeof(char*));
	for(int x = 0; x < WD; x++){
		buffer[x] = malloc(WD * sizeof(char));
		for(int y = 0; y < WD; y++){
			buffer[x][y] = world[x][y];
		}
	}
	return buffer;
}

int count_nb(char **buffer, int x, int y){ //count the live neighborhood
	int count = 0;
	for(int i = -1; i < 2; i++){
		for(int j = -1; j < 2; j++){
			if((i == 0) && (j == 0)) { continue; }
			if(buffer[(((x+i)%WD)+WD)%WD][(((y+j)%WD)+WD)%WD] == '@'){ count++; }
		}
	}
	return count;
}

void update(char **world){
	char **buffer = copy_buffer(world);
	for(int x = 0; x < WD; x++) {
		for(int y = 0; y < WD; y++){
			int count = count_nb(world, x, y);
			if(world[x][y] == '@' && count < 2){ buffer[x][y] = ' '; }
			if(world[x][y] == '@' && ((count == 2)||(count == 3))){ buffer[x][y] = '@'; }
			if(world[x][y] == '@' && count > 3){ buffer[x][y] = ' '; }
			if(world[x][y] == ' ' && count == 3){ buffer[x][y] = '@'; }
	}
}

	for(int x = 0; x < WD; x++){
		for(int y = 0; y < WD; y++){
			char c_buffer = buffer[x][y];
			world[x][y] = c_buffer;
		}
	}
	free(buffer);
}

void man_update(char **world){
//world[60][41] = '@';
//world[61][41] = '@';
//world[62][41] = '@';
//world[63][41] = '@';
//world[64][41] = '@';
//world[60][42] = '@';
//world[61][42] = '@';
//world[62][42] = '@';
//world[63][42] = '@';
//world[64][42] = '@';


	world[1][0] = '@';
	world[2][1] = '@';
	world[0][2] = '@';
	world[1][2] = '@';
	world[2][2] = '@';

}

void draw(char **world){
	for(int x = 0; x < WD; x++){
		for(int y = 0; y < WD; y++){
			putchar(world[x][y]);
		}
		printf("\n");
	}
}


void clear(){ printf("\x1b[2j"); }

void main_loop(char **world){
	for(;;){
		draw(world);
		getchar();
		update(world);
		clear();

	}
}

int main(int argc, char *argv[]) {
	
	//inicialização dinâmica da matriz
	char **world = create_empty_buffer();
	pilar(world);
	glider(world);

	//loop principal
	main_loop(world);

	return 0;
}

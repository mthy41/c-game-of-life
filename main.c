/* caution:
 *
 * this is very bad code!!!!
 * I'm still learning C and I made this
 * in rush.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "automatas.h"

#define WD 30 //world width
#define WH 30 //world heigth

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
		usleep(500000);
		//getchar();
		update(world);
		clear();

	}
}

int main(int argc, char *argv[]) {
	
	//inicialização dinâmica da matriz
	char **world = create_empty_buffer();
	pilar(world);
	glider(world);
	glider_2(world);
	thing_1(world);
	thing_2(world);
	thing_3(world);

	//loop principal
	main_loop(world);

	return 0;
}

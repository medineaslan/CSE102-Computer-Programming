#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct forest
{
	char **Map;
	int Width;
	int Height;
	int Flower_x;
	int Flower_y;

}Forest;

typedef struct botanist
{
	int Coord_x;
	int Coord_y;
	int Water_Bottle_Size;

}Botanist;

void init_game(Forest *forest, Botanist *botanist);
void print_map(Forest forest);
void search (Botanist *botanist, Forest *forest, int Coord_x, int Coord_y);

int main(){
	int j;

	srand(time(NULL));

	Forest forest;
	Botanist botanist;

	init_game(&forest, &botanist);

	print_map(forest);
	printf("\n");
	search(&botanist, &forest, botanist.Coord_x, botanist.Coord_y);

	//Free calloc.
	for(j=0; j < (forest.Height); j++){
		free(forest.Map[j]);
	}
	free(forest.Map);

}

//Initialize the forest.
void init_game(Forest *forest, Botanist *botanist){

	FILE *file;

	char *temp;
	int x=0, t=0, k, z;
	size_t size = 0;


	file = fopen("init.csv","r");

	//The first two lines of the file are read as integers.
	fscanf(file,"%d\n", &botanist->Water_Bottle_Size);
	fscanf(file,"%d,%d ", &forest->Height,&forest->Width);

	//Memory allocation using calloc.
	forest->Map = (char**)calloc(forest->Height,sizeof(char *));

	for(x=0; x<(forest->Width); x++){

		forest->Map[x] = (char*)calloc(forest->Width,sizeof(char));

	}

	//Size twice the width is created due to commas.
	size = (forest->Width) * 2;

	//Memory allocation using calloc.
	temp = (char*)calloc(size,sizeof(char));

	//The remaining lines of the file are retrieved line by line with the loop.
	for(k=0; k < (forest->Height) ; k++){
		
		getline(&temp , &size , file);

		for(z=0; z < (forest->Width)*2+1; z++){

			//Elements of the temp array are placed in the map array as long as they are not commas.
			if(temp[z] != ','){

				forest->Map[k][t] = temp[z];
				
				//Botanist positions are taken.
				if(forest->Map[k][t] == 'B'){

					botanist->Coord_x = k;
					botanist->Coord_y = t;
				}

				//Flowers positions are taken.
				else if(forest->Map[k][t] == 'F'){

					forest->Flower_x = k;
					forest->Flower_y = t;
				}

				t++;
			}
		}
		t=0;
	}
	free(temp);
	fclose(file);
}

//Prints map.
void print_map (Forest forest){ 
	int k,z;
	for(k=0; k < (forest.Height) ; k++){
		for(z=0; z < (forest.Width) ; z++){
			printf("%c ", forest.Map[k][z]);
		}
		printf("\n");
	}
}

//Search flower.
void search (Botanist *botanist, Forest *forest, int Coord_x, int Coord_y){

	int random; 
	int jump_x, jump_y;

	//It is a condition that the flower is found.
	if(forest->Map[botanist->Coord_x][botanist->Coord_y] == forest->Map[forest->Flower_x][forest->Flower_y]){
		printf("Searching...\n\n");
		print_map(*forest);
		printf("\n");
		printf("I have found it on (%d,%d)!\n\n", forest->Flower_x, forest->Flower_y);
		return;
	} 

	//It is the condition of running out of water.
	else if(botanist->Water_Bottle_Size == 0){
		printf("Searching...\n\n");
		print_map(*forest);
		printf("\n");
		printf("Help! I am on  (%d,%d)\n\n", botanist->Coord_x, botanist->Coord_y);

		return;
	}

	else{

		//Random action is assigned.
		random = 1 + rand() % 4;

		//If the random number is 1, it will move up.
		if(random == 1){
			//To check the next box, the current location of the botanist is updated according to the action to be made.
			jump_x = botanist->Coord_x - 1;
			jump_y = botanist->Coord_y;

			//The borders of the forest are checked, whether the next box is empty, and whether the next box is a flower.
			if(jump_x >= 0 && (forest->Map[jump_x][jump_y] == ' ' || forest->Map[jump_x][jump_y] == 'F')){
				-- botanist->Water_Bottle_Size;
				-- botanist->Coord_x;
				forest->Map[Coord_x][Coord_y] = ' ';
				forest->Map[jump_x][jump_y] = 'B';					
				search(botanist, forest, jump_x, Coord_y);
			}
			else{
				search(botanist, forest, Coord_x, Coord_y);
			}
		}

		//If the random number is 2, it will move down.
		else if(random == 2){
			//To check the next box, the current location of the botanist is updated according to the action to be made.
			jump_x = botanist->Coord_x + 1;
			jump_y = botanist->Coord_y;

			//The borders of the forest are checked, whether the next box is empty, and whether the next box is a flower.
	 		if(jump_x < forest->Height && (forest->Map[jump_x][jump_y] == ' ' || forest->Map[jump_x][jump_y] == 'F')){
 				-- botanist->Water_Bottle_Size;
				++ botanist->Coord_x;
				forest->Map[Coord_x][Coord_y] = ' ';
				forest->Map[jump_x][jump_y] = 'B';
 				search(botanist, forest, jump_x, Coord_y);
	 		}
	 		else{
	 			search(botanist, forest, Coord_x, Coord_y);	
	 		}
		}

		//If the random number is 3, move left.
	   	else if(random == 3){
	   		//To check the next box, the current location of the botanist is updated according to the action to be made.
	   		jump_x = botanist->Coord_x;
			jump_y = botanist->Coord_y - 1;

			//The borders of the forest are checked, whether the next box is empty, and whether the next box is a flower.
	 		if(jump_y >= 0 && (forest->Map[jump_x][jump_y] == ' ' || forest->Map[jump_x][jump_y] == 'F')){
 				-- botanist->Water_Bottle_Size;
				-- botanist->Coord_y;
				forest->Map[Coord_x][Coord_y] = ' ';
				forest->Map[jump_x][jump_y] = 'B';
 				search(botanist, forest, Coord_x, jump_y);
	 		}
	 		else{
	 			search(botanist, forest, Coord_x, Coord_y);	
	 		}
		}

		//If the random number is 4, move to the right.
		else if(random == 4){
			//To check the next box, the current location of the botanist is updated according to the action to be made.
			jump_x = botanist->Coord_x;
			jump_y = botanist->Coord_y + 1;

			//The borders of the forest are checked, whether the next box is empty, and whether the next box is a flower.
	 		if(jump_y < forest->Width && (forest->Map[jump_x][jump_y] == ' ' || forest->Map[jump_x][jump_y] == 'F')){
 				-- botanist->Water_Bottle_Size;
				++ botanist->Coord_y;
				forest->Map[Coord_x][Coord_y] = ' ';
				forest->Map[jump_x][jump_y] = 'B';
 		  		search(botanist, forest, Coord_x, jump_y);
	 		}
	 		else{
	 			search(botanist, forest, Coord_x, Coord_y);	
	 		}
		}
	
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {S,M,P,B,T,N} type;
typedef struct block
{
	type typ_t;
	char text[10];
	int data, pos_x, pos_y, jump_x, jump_y;

}block;

void init_board(block board[][10]);
void print_board(block board[][10]);
int single_play(block board[][10], int i, int j, int counter, int control);
void two_separate_game();

int main(){

	srand(time(NULL));

	block board[10][10];
	int selection;

	printf("-------------MENU--------------\n");
	printf("1:Singleplayer game\n");
	printf("2:MUltiplayer game\n");
	printf("Please enter your selection:");
	scanf("%d", &selection);

	//Choose single play or two seperate game.
	switch(selection){

		case 1 :

		print_board(board);
		printf("Counter:%d\n", single_play(board, 9, 9, 0, 1));
		break;

		case 2 :
		print_board(board);
		two_separate_game();	
		break;
	}
}

//Initialize board.
void init_board(block board[][10]){

	int i, j, counter=1;

	for(i=9; i >= 0; i--){

		if(i % 2 == 0){ //An even numbered row is progressed by increasing the columns.
			for(j=0; j <= 9; j++){
				board[i][j].pos_x = i; //row
				board[i][j].pos_y = j; //column
				board[i][j].typ_t = N; //Assingn N all row.
				board[i][j].data = counter; 
				counter++;	

				sprintf(board[i][j].text,"%d",board[i][j].data); //Data are assigned to texts.

				//Texts are assigned letters that should be and where they will jump.
				//Places to jump are assigned.
				sprintf(board[8][6].text, "%s", "M{28}");
				board[8][6].jump_x = 7;
				board[8][6].jump_y = 2;

				sprintf(board[8][2].text, "%s", "P");

				sprintf(board[6][1].text, "%s","M{52}");
				board[6][1].jump_x = 4;
				board[6][1].jump_y = 1;

				sprintf(board[6][5].text, "%s", "B");
				board[6][5].jump_x = 5;
				board[6][5].jump_y = 9;
			
				sprintf(board[6][9].text, "%s" ,"T");
				board[6][9].jump_x = 6;
				board[6][9].jump_y = 4;
			
				sprintf(board[4][3].text, "%s", "T");
				board[4][3].jump_x = 5;
				board[4][3].jump_y = 1;
			
				sprintf(board[4][6].text, "%s","M{77}");
				board[4][6].jump_x = 2;
				board[4][6].jump_y = 6;
			
				sprintf(board[4][9].text, "%s", "S{44}");
				board[4][9].jump_x = 5;
				board[4][9].jump_y = 6;
			
				sprintf(board[2][2].text, "%s", "S{68}");
				board[2][2].jump_x = 3;
				board[2][2].jump_y = 2;
			
				sprintf(board[2][5].text, "%s", "M{83}");
				board[2][5].jump_x = 1;
				board[2][5].jump_y = 7;
		
				sprintf(board[2][8].text, "%s", "T");
				board[2][8].jump_x = 2;
				board[2][8].jump_y = 3;
			
				sprintf(board[0][2].text, "%s" ,"T");
				board[0][2].jump_x = 1;
				board[0][2].jump_y = 2;
		
				sprintf(board[0][7].text, "%s", "S{72}");
				board[0][7].jump_x = 2;
				board[0][7].jump_y = 1;
			
				sprintf(board[0][8].text, "%s", "S{56}");
				board[0][8].jump_x = 4;
				board[0][8].jump_y = 5;

				sprintf(board[0][9].text, "%s" ,"100(Finish)");

				//Assign types.
				board[8][2].typ_t = P;
				board[8][6].typ_t = M;
				board[6][1].typ_t = M;
				board[6][5].typ_t = B;
				board[6][9].typ_t = T;
				board[4][3].typ_t = T;
				board[4][6].typ_t = M;
				board[4][9].typ_t = S;
				board[2][2].typ_t = S;
				board[2][5].typ_t = S;
				board[2][8].typ_t = T;
				board[0][2].typ_t = T;
				board[0][7].typ_t = S;
				board[0][8].typ_t = S;
			}
		}

		else if(i % 2 != 0){ //An odd numbered row is advanced by decreasing the columns.
			for(j=9; j >= 0; j--){
				board[i][j].pos_x = i;
				board[i][j].pos_y = j;	
				board[i][j].typ_t = N;
				board[i][j].data = counter;
				counter++;

				//The same operations performed on even rows are also made for odd rows.
				sprintf(board[i][j].text,"%d",board[i][j].data);

				sprintf(board[9][9].text, "%s", "1(Start)");
			
				sprintf(board[9][4].text, "%s", "S{1}");
				board[9][4].jump_x = 9;
				board[9][4].jump_y = 9;
			
				sprintf(board[9][3].text, "%s", "M{11}");					
				board[9][3].jump_x = 8;
				board[9][3].jump_y = 0;

				sprintf(board[7][1].text, "%s", "B");					
				board[7][1].jump_x = 6;
				board[7][1].jump_y = 3;

				sprintf(board[7][5].text, "%s", "S{12}");					
				board[7][5].jump_x = 8;
				board[7][5].jump_y = 1;

				sprintf(board[5][0].text, "%s", "B");
				board[5][0].jump_x = 4;
				board[5][0].jump_y = 4;					
			
				sprintf(board[5][2].text, "%s", "P");					
			
				sprintf(board[5][5].text, "%s", "S{22}");
				board[5][5].jump_x = 7;
				board[5][5].jump_y = 8;					
		
				sprintf(board[3][1].text, "%s", "M{77}");
				board[3][1].jump_x = 2;
				board[3][1].jump_y = 6;					
			
				sprintf(board[3][4].text, "%s", "B");	
				board[3][4].jump_x = 2;
				board[3][4].jump_y = 0;				
	
				sprintf(board[3][7].text, "%s", "S{52}");
				board[3][7].jump_x = 4;
				board[3][7].jump_y = 1;					
			
				sprintf(board[1][1].text, "%s", "M{94}");
				board[1][1].jump_x = 0;					
				board[1][1].jump_y = 3;

				sprintf(board[1][5].text, "%s", "P");					
			
				sprintf(board[1][8].text, "%s", "B");
				board[1][8].jump_x = 1;
				board[1][8].jump_y = 3;	

			    board[9][4].typ_t = S;
				board[9][3].typ_t = M;
				board[7][5].typ_t = S;				
				board[7][1].typ_t = B;			
				board[5][5].typ_t = S;
				board[5][2].typ_t = P;
				board[5][0].typ_t = B;
				board[3][7].typ_t = S;
				board[3][4].typ_t = B;
				board[3][1].typ_t = M;
				board[1][8].typ_t = B;
				board[1][5].typ_t = P;
				board[1][1].typ_t = M;				
			}
		}
	}
}
 //Prints board.
void print_board(block board[][10]){

	init_board(board);

	int i, j;

	for(i=0; i < 10; i++){

		for(j=0; j < 10; j++){

			printf("%s 	", board[i][j].text);
		}

		printf("\n");
	}
}

//The data is advanced until it reaches 100, when it exceeds 100, dice are thrown again and a move is made.
//The number of moves is returned.
int single_play(block board[][10], int i, int j, int counter,int control){

	init_board(board);

	int dice,final_x, final_y;

	counter = 1;

	//1 to 6 dice are rolled randomly.
	dice = 1 + rand() % 6; 
	
	//Find current coordinates.
	control = board[i][j].data + dice;

	if(control > 100){
		control = control - dice;
		return single_play(board,i,j,counter+1,control);	
	}

	//Find current coordinates.
	for(i=0; i < 10; i++){

		for(j=0; j < 10; j++){

			if(board[i][j].data == control){
				final_x = i;
				final_y = j;
			}
		}
	}

	//If Type M ve S done jump.
	if(board[final_x][final_y].typ_t == M || board[final_x][final_y].typ_t == S){

		if(board[final_x][final_y].data != 100 ){

			counter += single_play(board, board[final_x][final_y].jump_x, board[final_x][final_y].jump_y, counter+1, control);
			printf("Move data:%d\n", board[final_x][final_y].data);
		}
		else if(board[final_x][final_y].data == 100){
			return counter;
		}
	}

	//If Type B ve T done jump .
	else if(board[final_x][final_y].typ_t == B || board[final_x][final_y].typ_t == T){
		
		if(board[final_x][final_y].data != 100 ){
			counter += single_play(board, board[final_x][final_y].jump_x, board[final_x][final_y].jump_y, counter+1, control);
			printf("Move data:%d\n", board[final_x][final_y].data);
		}
		else if(board[final_x][final_y].data == 100){
			return counter;
		}
	}

	//If Type P return previous position.
	else if(board[final_x][final_y].typ_t == P){

		control = board[final_x][final_y].data - dice;

		for(i=0; i < 10; i++){

			for(j=0; j < 10; j++){

				if(board[i][j].data == control){
					final_x = i;
					final_y = j;
				}
			}
		}	
		
		if(board[final_x][final_y].data != 100 ){
			counter +=  single_play(board, final_x, final_y, counter+1, control);
			printf("Move data:%d\n", board[final_x][final_y].data);
		}
		else if(board[final_x][final_y].data == 100){
			return counter;
		}
	}

	//Use final coordinates if normal types.
	else if(board[final_x][final_y].typ_t == N){
		
		if(board[final_x][final_y].data != 100 ){
			counter += single_play(board, final_x, final_y, counter+1, control);
			printf("Move data:%d\n", board[final_x][final_y].data);
		}
		else if(board[final_x][final_y].data == 100){
			return counter;
		}
	}

	return counter;
}	

//Call single_play function 2 times and return 2 value.
//If value is smaller than other the player wins.
//In case of a draw, there is no winner.
void two_separate_game(){

	block board[10][10];

	init_board(board);

	int game1, game2;

	game1 = single_play(board, 9, 9, 0, 1);

	printf("Gamer1's count:%d\n", game1);

	game2 = single_play(board, 9, 9, 0, 1);

	printf("Gamer2's count:%d\n\n\n", game2);

	printf("Gamer1's count:%d\n", game1);
	printf("Gamer2's count:%d\n", game2);

	if(game1 > game2){
		printf("Gamer2 is winner.\n");
	}

	else if(game1 < game2){
		printf("Gamer1 is winner.\n");
	}
	else{
		printf("No winner!\n");
	}
}
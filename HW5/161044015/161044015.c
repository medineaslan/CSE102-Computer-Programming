#include <stdio.h>
#include <math.h>

typedef enum {white_man, black_man, white_king, black_king, empty} piece;
typedef enum {white = 10, black = 20} player;


void init_board(piece board[][8]);
void display_board(piece board[][8]);
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);
int check_end_of_game(piece board[][8]);
void sample_game_1();
void sample_game_2();

//Helper functions
int moveWhite(piece board[][8], int from_x, int from_y, int to_x, int to_y);
int moveBlack(piece board[][8], int from_x, int from_y, int to_x, int to_y);
void copyBoard(piece fromBoard[8][8], piece toBoard[8][8]);
int isBelong(piece board[][8], int from_x, int from_y, player p);
int isOneStepMove(int from_x, int from_y, int to_x, int to_y);
void init_board_sample_game_2(piece board[][8]);
int kingLeftToRight(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);
int kingRightToLeft(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);
int kingDownToUp(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);
int kingUpToDown(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);
int isAllowedCheck(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);

int main(){
	sample_game_2();
	sample_game_1();
}

void sample_game_2(){
	piece board[8][8];
	
	printf("Sample game 2\n");

	init_board_sample_game_2(board);
	display_board(board);
	move(board, 5, 1, 4, 1, white);
	display_board(board);
	move(board, 3, 1, 5, 1, black);
	display_board(board);
	move(board, 4, 3, 3, 3, white);
	display_board(board);
	move(board, 4, 5, 4, 1, black);
	display_board(board);
	move(board, 3, 3, 1, 1, white);
	display_board(board);
	move(board, 1, 2, 1, 0, black);
	display_board(board);
	move(board, 5, 3, 4, 3, white);
	display_board(board);
	move(board, 5, 1, 7, 5, black);
	display_board(board);
	move(board, 4, 3, 3, 3, white);
	display_board(board);
	move(board, 2, 3, 4, 3, black);
	display_board(board);
	move(board, 5, 6, 5, 5, white);
	display_board(board);
	move(board, 7, 5, 4, 5, black); 
	display_board(board);
	move(board, 4, 6, 0, 0, white); 
	display_board(board);
}

int check_end_of_game(piece board[][8]) {
	int i = 0, j = 0;
	int whiteManCount = 0, blackManCount = 0, whiteKingCount = 0, blackKingCount = 0;

	for(i = 0 ; i < 8 ; ++i){
		for(j = 0 ; j < 8 ;++j){
			if(board[i][j] == black_man)
				++blackManCount;
			if(board[i][j] == white_man)
				++whiteManCount;
			if(board[i][j] == black_king)
				++blackKingCount;
			if(board[i][j] == white_king)
				++whiteKingCount;
		}
	}	

	if((whiteKingCount + whiteManCount) == 0)
		return black;
	if((blackKingCount + blackManCount) == 0)
		return white;

	return -1;
}

void sample_game_1() {
	piece board[8][8];
	int turn = 1;
	init_board(board);
	//display_board(board);

	printf("Sample game 1\n\n");

	while(check_end_of_game(board) == -1){
		int from_x, from_y, to_x, to_y;
		display_board(board);
		//White
		if(turn % 2 == 1){
			int moveResult = 0;
			
			do {
				printf("\n***White***\n");
				printf("Enter the from x coordinate\n");
				scanf("%d", &from_x);
				printf("Enter the from y coordinate\n");
				scanf("%d", &from_y);
				printf("Enter the to x coordinate\n");
				scanf("%d", &to_x);
				printf("Enter the to y coordinate\n");
				scanf("%d", &to_y);
				
				moveResult = move(board, from_x, from_y, to_x, to_y, white);
				
				if(moveResult == -2){
					printf("\nThe move is not allowed.\n\n");
				}
				else if(moveResult == -1){
					printf("\nThe player white is trying to move a piece that does not belong to him.\n\n");		
				}
				else {		
					if(moveResult > 0)
						printf("Captured %d opponent piece.\n", moveResult);
				}
			} while(moveResult < 0);
		}
		else{		
			int moveResult = 0;
			
			do {
				printf("\n***Black***\n");
				printf("Enter the from x coordinate\n");
				scanf("%d", &from_x);
				printf("Enter the from y coordinate\n");
				scanf("%d", &from_y);
				printf("Enter the to x coordinate\n");
				scanf("%d", &to_x);
				printf("Enter the to y coordinate\n");
				scanf("%d", &to_y);

				moveResult = move(board, from_x, from_y, to_x, to_y, black);
				if(moveResult == -2){
					printf("\nThe move is not allowed.\n\n");
				}
				else if(moveResult == -1){
					printf("\nThe player black is trying to move a piece that does not belong to him.\n\n");		
				}
				else {		
					if(moveResult > 0)
						printf("Captured %d opponent piece.\n", moveResult);
				}
			} while(moveResult < 0);
		}
	
		++turn;
	}

	if(check_end_of_game(board) == white)
		printf("White won!\n");
	else
		printf("Black won!\n");
}

void init_board_sample_game_2(piece board[][8]){

	int i,j;

	for(i=0; i < 8; i++){

		for(j=0; j < 8; j++){

			if(i == 1 && j == 2){
				board[i][j] = black_man;
			}
			else if(i == 1 && j == 3){
				board[i][j] = black_man;
			}  
			else if(i == 1 && j == 4){
				board[i][j] = black_man;
			}
			else if(i == 1 && j == 5){
				board[i][j] = black_man;
			}
			else if(i == 2 && j == 1){
				board[i][j] = black_man;
			}
			else if(i == 2 && j == 2){
				board[i][j] = black_man;
			}
			else if(i == 2 && j == 3){
				board[i][j] = black_man;
			}
			else if(i == 2 && j == 4){
				board[i][j] = black_man;
			}
			else if(i == 2 && j == 6){
				board[i][j] = black_man;
			}
			else if(i == 2 && j == 7){
				board[i][j] = black_man;
			}
			else if(i == 3 && j == 0){
				board[i][j] = black_man;
			}
			else if(i == 3 && j == 1){
				board[i][j] = black_man;
			}
			else if(i == 3 && j == 2){
				board[i][j] = black_man;
			}
			else if(i == 3 && j == 5){
				board[i][j] = black_man;
			}
			else if(i == 3 && j == 7){
				board[i][j] = black_man;
			}
			else if(i == 4 && j == 2){
				board[i][j] = white_man;
			}
			else if(i == 4 && j == 3){
				board[i][j] = white_man;
			}
			else if(i == 4 && j == 4){
				board[i][j] = white_man;
			}
			else if(i == 4 && j == 5){
				board[i][j] = black_man;
			}
			else if(i == 4 && j == 6){
				board[i][j] = white_man;
			}
			else if(i == 4 && j == 7){
				board[i][j] = white_man;
			}
			else if(i == 5 && j == 0){
				board[i][j] = white_man;
			}
			else if(i == 5 && j == 1){
				board[i][j] = white_man;
			}
			else if(i == 5 && j == 2){
				board[i][j] = white_man;
			}
			else if(i == 5 && j == 3){
				board[i][j] = white_man;
			}
			else if(i == 5 && j == 4){
				board[i][j] = white_man;
			}
			else if(i == 5 && j == 6){
				board[i][j] = white_man;
			}
			else if(i == 5 && j == 7){
				board[i][j] = white_man;
			}
			else if(i == 6 && j == 2){
				board[i][j] = white_man;
			}
			else if(i == 6 && j == 3){
				board[i][j] = white_man;
			}
			else if(i == 6 && j == 4){
				board[i][j] = white_man;
			}
			else if(i == 6 && j == 5){
				board[i][j] = white_man;
			}
			else{
           		board[i][j] = empty;	
            }

		}
	}

}

void init_board(piece board[][8]){
	int i,j;
	
	for(i=0; i < 8; i++){
		for(j=0; j < 8; j++){
           	if(i==1){
           		board[i][j] = black_man;
           	}
           	else if(i==2){
           		board[i][j] = black_man;
           	}                                  
			else if(i==5){
	       		board[i][j] = white_man;
	       	}	        		
	        else if(i==6){
           		board[i][j] = white_man;
           	}           
            else{
           		board[i][j] = empty;	
            }
		}
	}
}

void display_board(piece board[][8]){

	int i,j;
	
	for(i=0; i < 8; i++){
		for(j=0; j < 8; j++){
			if(board[i][j] == black_man){
				printf("b");
			}
			else if( board[i][j] == white_man){
				printf("w");
			}
			else if(board[i][j] == empty){
				printf("-");
			}
			else if(board[i][j] == white_king){
				printf("W");
			}
			else if(board[i][j] == black_king){
				printf("B");
			}
		}
		printf("\n");
	}
	
	printf("\n");
}

int isOneStepMove(int from_x, int from_y, int to_x, int to_y){
	float xdiff = fabs((float)(from_x - to_x));
	float ydiff = fabs((float)(from_y - to_y));
	
	return (xdiff + ydiff) <= 2;
}

int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){
	int n;

	if(isBelong(board, from_x, from_y, p) == 0)
		return -1;
	if(isAllowedCheck(board, from_x, from_y, to_x, to_y, p) != 0)
		return -2;
		
	if(p == white){
		int moveResult = moveWhite(board, from_x, from_y, to_x, to_y);
		
		if(moveResult > 0)
			if(to_x == 0)
				board[to_x][to_y] = white_king;
		
		return moveResult;
	}
	else {
		int moveResult = moveBlack(board, from_x, from_y, to_x, to_y);
		
		if(moveResult > 0)
			if(to_x == 7)
				board[to_x][to_y] = black_king;
	
		return moveResult;
	}
}

int kingLeftToRight(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){
	int i = 0;
	int n = 0;

	if(p == white) {
		for(i = from_y + 1; i <= to_y; ++i)
			if(board[from_x][i] == white_man || board[from_x][i] == white_king )
				return -2;
	
		for(i = from_y + 1; i <= to_y; ++i){
			if(i < 7 && (board[from_x][i] == black_man && board[from_x][i + 1] == black_man) ||
				(board[from_x][i] == black_man && board[from_x][i + 1] == black_king) ||
				(board[from_x][i] == black_king && board[from_x][i + 1] == black_man))
				return -2;
		}
	
		for(i = from_y + 1; i < to_y; ++i){
			if (board[from_x][i] == black_man || board[from_x][i] == black_king)
				++n;
			board[from_x][i] = empty;
		}

		board[to_x][to_y] = white_king;
		board[from_x][from_y] = empty;
		return n;
	}
	else{
		for(i = from_y + 1; i <= to_y; ++i)
			if(board[from_x][i] == black_man || board[from_x][i] == black_king )
				return -2;
	
		for(i = from_y + 1; i <= to_y; ++i){
			if(i < 7 && (board[from_x][i] == white_man && board[from_x][i + 1] == white_man) ||
				(board[from_x][i] == white_man && board[from_x][i + 1] == white_king) ||
				(board[from_x][i] == white_king && board[from_x][i + 1] == white_man))
				return -2;
		}
	
		for(i = from_y + 1; i < to_y; ++i){
			if (board[from_x][i] == white_man || board[from_x][i] == white_king)
				++n;
			board[from_x][i] = empty;
		}

		board[to_x][to_y] = black_king;
		board[from_x][from_y] = empty;
		return n;
	}
}

int kingRightToLeft(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){
	int i = 0;
	int n = 0;

	if(p == white) {
		for(i = from_y - 1; i >= to_y; --i)
			if(board[from_x][i] == white_man || board[from_x][i] == white_king )
				return -2;
	
		for(i = from_y - 1; i >= to_y; --i){
			if(i > 0 && (board[from_x][i] == black_man && board[from_x][i -1] == black_man) ||
				(board[from_x][i] == black_man && board[from_x][i - 1] == black_king) ||
				(board[from_x][i] == black_king && board[from_x][i - 1] == black_man))
				return -2;
		}
	
		for(i = from_y - 1; i > to_y; --i){
			if (board[from_x][i] == black_man || board[from_x][i] == black_king)
				++n;
			board[from_x][i] = empty;
		}

		board[to_x][to_y] = white_king;
		board[from_x][from_y] = empty;
		return n;
	}
	else{

		for(i = from_y - 1; i >= to_y; --i)
			if(board[from_x][i] == black_man || board[from_x][i] == black_king )
				return -2;
	
		for(i = from_y - 1; i >= to_y; --i){
			if(i > 0 && (board[from_x][i] == white_man && board[from_x][i - 1] == white_man) ||
				(board[from_x][i] == white_man && board[from_x][i - 1] == white_king) ||
				(board[from_x][i] == white_king && board[from_x][i - 1] == white_man))
				return -2;
		}
	
		for(i = from_y - 1; i > to_y; --i){
			if (board[from_x][i] == white_man || board[from_x][i] == white_king)
				++n;
			board[from_x][i] = empty;
		}

		board[to_x][to_y] = black_king;
		board[from_x][from_y] = empty;
		return n;
	}
}

int kingDownToUp(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){
	int i = 0;
	int n = 0;

	if(p == white) {
		for(i = from_x - 1; i >= to_x; --i)
			if(board[i][from_y] == white_man || board[i][from_y] == white_king )
				return -2;
	
		for(i = from_x - 1; i >= to_x; --i){
			if(i > 0 && (board[i][from_y] == black_man && board[i - 1][from_y] == black_man) ||
				(board[i][from_y] == black_man && board[i - 1][from_y] == black_king) ||
				(board[i][from_y] == black_king && board[i - 1][from_y] == black_man))
				return -2;
		}
	
		for(i = from_x - 1; i > to_x; --i){
			if (board[i][from_y] == black_man || board[i][from_y] == black_king)
				++n;
			board[i][from_y] = empty;
		}

		board[to_x][to_y] = white_king;
		board[from_x][from_y] = empty;
		return n;
	}
	else{
		for(i = from_x - 1; i >= to_x; --i)
			if(board[i][from_y] == black_man || board[i][from_y] == black_king )
				return -2;
	
		for(i = from_x - 1; i >= to_x; --i){
			if(i > 0 && (board[i][from_y] == white_man && board[i - 1][from_y] == white_man) ||
				(board[i][from_y] == white_man && board[i - 1][from_y] == white_king) ||
				(board[i][from_y] == white_king && board[i - 1][from_y] == white_man))
				return -2;
		}
	
		for(i = from_x - 1; i > to_x; --i){
			if (board[i][from_y] == white_man || board[i][from_y] == white_king)
				++n;
			board[i][from_y] = empty;
		}

		board[to_x][to_y] = black_king;
		board[from_x][from_y] = empty;
		return n;
	}
}

int kingUpToDown(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){
	int i = 0;
	int n = 0;

	if(p == white) {
		for(i = from_x + 1; i <= to_x; ++i)
			if(board[i][from_y] == white_man || board[i][from_y] == white_king )
				return -2;
	
		for(i = from_x + 1; i <= to_x; ++i){
			if(i < 7 && (board[i][from_y] == black_man && board[i + 1][from_y] == black_man) ||
				(board[i][from_y] == black_man && board[i + 1][from_y] == black_king) ||
				(board[i][from_y] == black_king && board[i + 1][from_y] == black_man))
				return -2;
		}
	
		for(i = from_x + 1; i < to_x; ++i){
			if (board[i][from_y] == black_man || board[i][from_y] == black_king)
				++n;
			board[i][from_y] = empty;
		}

		board[to_x][to_y] = white_king;
		board[from_x][from_y] = empty;
		return n;
	} 
	else{
		for(i = from_x + 1; i <= to_x; ++i)
			if(board[i][from_y] == black_man || board[i][from_y] == black_king )
				return -2;
	
		for(i = from_x + 1; i <= to_x; ++i){
			if(i < 7 && (board[i][from_y] == white_man && board[i + 1][from_y] == white_man) ||
				(board[i][from_y] == white_man && board[i + 1][from_y] == white_king) ||
				(board[i][from_y] == white_king && board[i + 1][from_y] == white_man))
				return -2;
		}
	
		for(i = from_x + 1; i < to_x; ++i){
			if (board[i][from_y] == white_man || board[i][from_y] == white_king)
				++n;
			board[i][from_y] = empty;
		}

		board[to_x][to_y] = black_king;
		board[from_x][from_y] = empty;
		return n;
	}
}

int isAllowedCheck(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p) {
	
	if(p == white && board[from_x][from_y] == white_man && to_x - from_x > 0)
		return -2;
	if(p == black && board[from_x][from_y] == black_man && to_x - from_x < 0)
		return -2;
	if(from_x == to_x && from_y == to_y)
		return -2;
	if(board[to_x][to_y] != empty)
		return -2;

	return 0;
}

int isBelong(piece board[][8], int from_x, int from_y, player p)
{
	if(p == black && (board[from_x][from_y] == black_man || board[from_x][from_y] == black_king)) 
		return 1;
	else if(p == white && (board[from_x][from_y] == white_man || board[from_x][from_y] == white_king)) 
		return 1;
	else
		return 0;
}

void copyBoard(piece fromBoard[8][8], piece toBoard[8][8]){
	int i, j;

	for(i = 0 ; i < 8 ; ++i)
		for(j = 0; j < 8; ++j)
			toBoard[i][j] = fromBoard[i][j];
}

int moveWhite(piece board[][8], int from_x, int from_y, int to_x, int to_y){
	int n = 0, i = 0, j = 0;
	piece copiedBoard[8][8];
	copyBoard(board, copiedBoard);

	if(isOneStepMove(from_x, from_y, to_x, to_y) == 1){
		if(from_y == to_y){
			if(from_x > to_x){
				if(board[from_x - 1][from_y] == empty){
					board[from_x - 1][from_y] = white_man;
					board[from_x][from_y] = empty;
				}
				else if(board[from_x -1][from_y] == black_man || board[from_x -1][from_y] == black_king){
					board[from_x - 2][from_y] = white_man;
					board[from_x][from_y] = empty;
					board[from_x -1][from_y] = empty;
					n++;
				}
			}
		}
		else if(from_x == to_x){
			if(from_y > to_y){
				if(board[from_x][from_y - 1] == empty){
					board[from_x][from_y -1] = white_man;
					board[from_x][from_y] = empty;
				}
				else if(board[from_x][from_y - 1] == black_man || board[from_x][from_y - 1] == black_king){
					board[from_x][from_y - 2] = white_man;
					board[from_x][from_y] = empty;
					board[from_x][from_y - 1] = empty;
					n++;
				}
			}
			else if(from_y < to_y){
				if(board[from_x][from_y + 1] == empty){
					board[from_x][from_y + 1] = white_man;
					board[from_x][from_y] = empty;
				}
				else if(board[from_x][from_y + 1] == black_man || board[from_x][from_y + 1] == black_king){
					board[from_x][from_y + 2] = white_man;
					board[from_x][from_y] = empty;
					board[from_x][from_y + 1] = empty;
					n++;
				}
			}
		}
		return n;
	} //if from piece is king
	else if(board[from_x][from_y] == white_king){
	
		//LeftToRight		
		if(from_x == to_x && from_y < to_y)
			return kingLeftToRight(board, from_x, from_y, to_x, to_y, white);
		
		//RightToLeft
		if(from_x == to_x && from_y > to_y)
			return kingRightToLeft(board, from_x, from_y, to_x, to_y, white);

		//UpToDown
		if(from_y == to_y && from_x < to_x)
			return kingUpToDown(board, from_x, from_y, to_x, to_y, white);
		
		//DownToUp
		if(from_y == to_y && from_x > to_x)
			return kingDownToUp(board, from_x, from_y, to_x, to_y, white);
		
		//LeftDown
		if(from_y > to_y && from_x < to_x){
			int res1 = kingRightToLeft(board, from_x, from_y, from_x, to_y, white);
			
			if(res1 > 0){
				int res2 = kingUpToDown(board, from_x, to_y, to_x, to_y, white);
				if(res1 > 0)
					return res1 + res2;
			}
			
			//Restore board when not allowed
			copyBoard(copiedBoard, board);

			int res3 = kingUpToDown(board, from_x, from_y, to_x, from_y, white);
			
			if(res3 > 0){
				int res4 = kingRightToLeft(board, to_x, from_y, to_x, to_y, white);
				if(res4 > 0)
					return res3 + res4;
			}

			//Restore board when not allowed
			copyBoard(copiedBoard, board);
			return -2;
		}
		//RightDown
		if(from_y < to_y && from_x < to_x){
			int res1 = kingLeftToRight(board, from_x, from_y, from_x, to_y, white);
			
			if(res1 > 0){
				int res2 = kingUpToDown(board, from_x, to_y, to_x, to_y, white);
				if(res1 > 0)
					return res1 + res2;
			}
			
			//Restore board when not allowed
			copyBoard(copiedBoard, board);

			int res3 = kingUpToDown(board, from_x, from_y, to_x, from_y, white);
			
			if(res3 > 0){
				int res4 = kingLeftToRight(board, to_x, from_y, to_x, to_y, white);
				if(res4 > 0)
					return res3 + res4;
			}

			//Restore board when not allowed
			copyBoard(copiedBoard, board);
			return -2;
		}
		//LeftUp
		if(from_y > to_y && from_x > to_x){
			int res1 = kingRightToLeft(board, from_x, from_y, from_x, to_y, white);
			
			if(res1 > 0){
				int res2 = kingDownToUp(board, from_x, to_y, to_x, to_y, white);
				if(res1 > 0)
					return res1 + res2;
			}
			
			//Restore board when not allowed
			copyBoard(copiedBoard, board);

			int res3 = kingDownToUp(board, from_x, from_y, to_x, from_y, white);
			
			if(res3 > 0){
				int res4 = kingRightToLeft(board, to_x, from_y, to_x, to_y, white);
				if(res4 > 0)
					return res3 + res4;
			}

			//Restore board when not allowed
			copyBoard(copiedBoard, board);
			return -2;
		}
		//RightUp
		if(from_y < to_y && from_x > to_x){
			int res1 = kingLeftToRight(board, from_x, from_y, from_x, to_y, white);
			
			if(res1 > 0){
				int res2 = kingDownToUp(board, from_x, to_y, to_x, to_y, white);
				if(res1 > 0)
					return res1 + res2;
			}
			
			//Restore board when not allowed
			copyBoard(copiedBoard, board);

			int res3 = kingDownToUp(board, from_x, from_y, to_x, from_y, white);
			
			if(res3 > 0){
				int res4 = kingLeftToRight(board, to_x, from_y, to_x, to_y, white);
				if(res4 > 0)
					return res3 + res4;
			}

			//Restore board when not allowed
			copyBoard(copiedBoard, board);
			return -2;
		}
	}
	else { //Multiple captures.
		//Man Down to up
		if(to_x < from_x && to_y == from_y){
			for(i = from_x; i >= 0 && i != to_x; i-=2)
			{	
				if(i >= 0){
					if((board[i - 1][to_y] == black_man || board[i - 1][to_y] == black_king) && board[i - 2][to_y] == empty) {
						board[i - 1][to_y] = empty;
						++n;
					}
					else {
						//Restore board when not allowed
						copyBoard(copiedBoard, board);
						return -2;
					}
				} else {
					//Restore board when not allowed
					copyBoard(copiedBoard, board);
					return -2;
				}
			}

			board[to_x][to_y] = white_man;
			board[from_x][from_y] = empty;

			return n;
		}//Man Right to left 
		else if(from_x == to_x && from_y > to_y){
			for(i = from_y; i >= 0 && i != to_y; i-=2)
			{	
				if(i >= 0){
					if((board[to_x][i - 1] == black_man || board[to_x][i - 1] == black_king) && board[to_x][i - 2] == empty) {
						board[to_x][i - 1] = empty;
						++n;
					}
					else {
						//Restore board when not allowed
						copyBoard(copiedBoard, board);
						return -2;
					}
				} else {
					//Restore board when not allowed
					copyBoard(copiedBoard, board);
					return -2;
				}
			}

			board[to_x][to_y] = white_man;
			board[from_x][from_y] = empty;
			return n;
		}//Man Left to right
		else if(from_x == to_x && from_y < to_y){
			for(i = from_y; i < 8 && i != to_y; i+=2)
			{	
				if(i < 8){
					if((board[to_x][i + 1] == black_man || board[to_x][i + 1] == black_king) && board[to_x][i + 2] == empty) {
						board[to_x][i + 1] = empty;
						++n;
					}
					else {
						//Restore board when not allowed
						copyBoard(copiedBoard, board);
						return -2;
					}
				} else {
					//Restore board when not allowed
					copyBoard(copiedBoard, board);
					return -2;
				}
			}

			board[to_x][to_y] = white_man;
			board[from_x][from_y] = empty;
			return n;
		}//Man right up
		else if(to_x < from_x && to_y > from_y){
			int firstWaySuccess = 1, secondWaySuccess = 1;

			for(i = from_x ; i >= 0 ; i-=2){
				int isEnd = 0;
				if(i == to_x){
					isEnd = 1;
					for(j = from_y ; j < 8 && j != to_y; j+=2){
						if((board[to_x][j + 1] == black_man ||board[to_x][j + 1] == black_king) && board[to_x][j + 2] == empty) {
							board[to_x][j + 1] = empty;
							++n;
						}	
						else {
							//Restore board when not allowed
							copyBoard(copiedBoard, board);
							firstWaySuccess = 0;
							n = 0;
							break;
						}
					}
					firstWaySuccess = 1;
				}

				if(isEnd == 1)
					break;

				if((board[i - 1][from_y] == black_man || board[i - 1][from_y] == black_king) && board[i - 2][from_y] == empty) {
						board[i - 1][from_y] = empty;
						++n;
				}
				else {
					//Restore board when not allowed
					copyBoard(copiedBoard, board);
					firstWaySuccess = 0;
					n = 0;
				}
			}

			if(firstWaySuccess == 1){
				board[to_x][to_y] = white_man;
				board[from_x][from_y] = empty;
				return n;
			}
			else{
				for(i = from_y ; i < 8 ; i+=2){
					int isEnd = 0;
					if(i == to_y){
						isEnd = 1;
						for(j = to_x ; j >= 0 && j != to_x; j-=2){
							if((board[j - 1][to_y] == black_man || board[j - 1][to_y] == black_king)  && board[j - 2][to_y] == empty) {
								board[j - 1][to_y] = empty;
								++n;
							}	
							else {
								//Restore board when not allowed
								copyBoard(copiedBoard, board);
								secondWaySuccess = 0;
								n = 0;
								break;
							}
						}
						secondWaySuccess = 1;
					}

					if(isEnd == 1)
						break;

					if((board[from_x][i + 1] == black_man || board[from_x][i + 1] == black_king) && board[from_x][i + 2] == empty) {
							board[from_x][i + 1] = empty;
							++n;
					}
					else {
						//Restore board when not allowed
						copyBoard(copiedBoard, board);
						secondWaySuccess = 0;
						n = 0;
						break;
					}
				}
				if(secondWaySuccess == 0){
					//Restore board when not allowed
					copyBoard(copiedBoard, board);
					return -2;
				}
				else{
					board[to_x][to_y] = white_man;
					board[from_x][from_y] = empty;
					return n;
				}
			}
		}//Man left up
		else if(to_x < from_x && to_y < from_y){
			int firstWaySuccess = 1, secondWaySuccess = 1;

			for(i = from_x ; i >= 0 ; i-=2){
				int isEnd = 0;
				if(i == to_x){
					isEnd = 1;
					for(j = from_y ; j >= 0 && j != to_y; j-=2){
						if((board[to_x][j - 1] == black_man || board[to_x][j - 1] == black_king) && board[to_x][j - 2] == empty) {
							board[to_x][j - 1] = empty;
							++n;
						}	
						else {
							//Restore board when not allowed
							copyBoard(copiedBoard, board);
							firstWaySuccess = 0;
							n = 0;
							break;
						}
					}
					firstWaySuccess = 1;
				}

				if(isEnd == 1)
					break;

				if((board[i - 1][from_y] == black_man || board[i - 1][from_y] == black_king) && board[i - 2][from_y] == empty) {
						board[i - 1][from_y] = empty;
						++n;
				}
				else {
					//Restore board when not allowed
					copyBoard(copiedBoard, board);
					firstWaySuccess = 0;
					n = 0;
					break;
				}
			}

			if(firstWaySuccess == 1){
				board[to_x][to_y] = white_man;
				board[from_x][from_y] = empty;
				return n;
			}
			else{
				for(i = from_y ; i >= 0 ; i-=2){
					int isEnd = 0;
					if(i == to_y){
						isEnd = 1;
						for(j = from_x ; j >= 0 && j != to_x; j-=2){
							if((board[j - 1][to_y] == black_man || board[j - 1][to_y] == black_king) && board[j - 2][to_y] == empty) {
							   board[j - 1][to_y] = empty;
								++n;
							}	
							else {
								//Restore board when not allowed
								copyBoard(copiedBoard, board);
								secondWaySuccess = 0;
								n = 0;
								break;
							}
						}
						secondWaySuccess = 1;
					}

					if(isEnd == 1)
						break;

					if((board[from_x][i - 1] == black_man || board[from_x][i - 1] == black_king) && board[from_x][i - 2] == empty) {
							board[from_x][i - 1] = empty;
							++n;
					}
					else {
						//Restore board when not allowed
						copyBoard(copiedBoard, board);
						secondWaySuccess = 0;
						n = 0;
						break;
					}
				}
				if(secondWaySuccess == 0){					
					//Restore board when not allowed
					copyBoard(copiedBoard, board);
					return -2;
				} 
				else{
					board[to_x][to_y] = white_man;
					board[from_x][from_y] = empty;
					return n;
				}
			}
		}
		
		//Restore board when not allowed
		copyBoard(copiedBoard, board);
		return -2;
	}
}

int moveBlack(piece board[][8], int from_x, int from_y, int to_x, int to_y){
	int n = 0, i = 0, j = 0;
	piece copiedBoard[8][8];
	copyBoard(board, copiedBoard);

	if(isOneStepMove(from_x, from_y, to_x, to_y) == 1){
		if(from_y == to_y){
			if(from_x <  to_x){
				if(board[from_x + 1][from_y] == empty ){
					board[from_x + 1][from_y] = black_man;
					board[from_x][from_y] = empty;						
				}
				else if(board[from_x+1][from_y] == white_man || board[from_x+1][from_y] == white_king){
					board[from_x+ 2][from_y ] = black_man;
					board[from_x][from_y] = empty;
					board[from_x+1][from_y] = empty;
					n++;
				}
			}
		}
		else if(from_x == to_x){
			if(from_y < to_y){
				if(board[from_x ][from_y + 1 ] == empty ){
					board[from_x][from_y + 1] = black_man;
					board[from_x][from_y] = empty;				
				}
				else if(board[from_x ][from_y+ 1] == white_man || board[from_x ][from_y+ 1] == white_king){
					board[from_x ][from_y+ 2 ] = black_man;
					board[from_x][from_y] = empty;
					board[from_x ][from_y+ 1] = empty;
					n++;
				}
			}
			else if(from_y > to_y){
				if(board[from_x][from_y -1 ] == empty ){
					board[from_x ][from_y -1] = black_man;
					board[from_x][from_y] = empty;				
				}
				else if(board[from_x][from_y - 1] == white_man || board[from_x][from_y - 1] == white_king){
					board[from_x][from_y - 2] = black_man;
					board[from_x][from_y] = empty;
					board[from_x][from_y-1] = empty;
					n++;
				}
			}
		}
		return n;
	} //if from piece is king
	else if(board[from_x][from_y] == black_king){
	
		//LeftToRight		
		if(from_x == to_x && from_y < to_y)
			return kingLeftToRight(board, from_x, from_y, to_x, to_y, black);
		
		//RightToLeft
		if(from_x == to_x && from_y > to_y)
			return kingRightToLeft(board, from_x, from_y, to_x, to_y, black);

		//UpToDown
		if(from_y == to_y && from_x < to_x)
			return kingUpToDown(board, from_x, from_y, to_x, to_y, black);
		
		//DownToUp
		if(from_y == to_y && from_x > to_x)
			return kingDownToUp(board, from_x, from_y, to_x, to_y, black);
		
		//LeftDown
		if(from_y > to_y && from_x < to_x){
			int res1 = kingRightToLeft(board, from_x, from_y, from_x, to_y, black);
			
			if(res1 > 0){
				int res2 = kingUpToDown(board, from_x, to_y, to_x, to_y, black);
				if(res1 > 0)
					return res1 + res2;
			}
			
			//Restore board when not allowed
			copyBoard(copiedBoard, board);

			int res3 = kingUpToDown(board, from_x, from_y, to_x, from_y, black);
			
			if(res3 > 0){
				int res4 = kingRightToLeft(board, to_x, from_y, to_x, to_y, black);
				if(res4 > 0)
					return res3 + res4;
			}

			//Restore board when not allowed
			copyBoard(copiedBoard, board);
			return -2;
		}
		//RightDown
		if(from_y < to_y && from_x < to_x){
			int res1 = kingLeftToRight(board, from_x, from_y, from_x, to_y, black);
			
			if(res1 > 0){
				int res2 = kingUpToDown(board, from_x, to_y, to_x, to_y, black);
				if(res1 > 0)
					return res1 + res2;
			}
			
			//Restore board when not allowed
			copyBoard(copiedBoard, board);

			int res3 = kingUpToDown(board, from_x, from_y, to_x, from_y, black);
			
			if(res3 > 0){
				int res4 = kingLeftToRight(board, to_x, from_y, to_x, to_y, black);
				if(res4 > 0)
					return res3 + res4;
			}

			//Restore board when not allowed
			copyBoard(copiedBoard, board);
			return -2;
		}
		//LeftUp
		if(from_y > to_y && from_x > to_x){
			int res1 = kingRightToLeft(board, from_x, from_y, from_x, to_y, black);
			
			if(res1 > 0){
				int res2 = kingDownToUp(board, from_x, to_y, to_x, to_y, black);
				if(res1 > 0)
					return res1 + res2;
			}
			
			//Restore board when not allowed
			copyBoard(copiedBoard, board);

			int res3 = kingDownToUp(board, from_x, from_y, to_x, from_y, black);
			
			if(res3 > 0){
				int res4 = kingRightToLeft(board, to_x, from_y, to_x, to_y, black);
				if(res4 > 0)
					return res3 + res4;
			}

			//Restore board when not allowed
			copyBoard(copiedBoard, board);
			return -2;
		}
		//RightUp
		if(from_y < to_y && from_x > to_x){
			int res1 = kingLeftToRight(board, from_x, from_y, from_x, to_y, black);
			
			if(res1 > 0){
				int res2 = kingDownToUp(board, from_x, to_y, to_x, to_y, black);
				if(res1 > 0)
					return res1 + res2;
			}
			
			//Restore board when not allowed
			copyBoard(copiedBoard, board);

			int res3 = kingDownToUp(board, from_x, from_y, to_x, from_y, black);
			
			if(res3 > 0){
				int res4 = kingLeftToRight(board, to_x, from_y, to_x, to_y, black);
				if(res4 > 0)
					return res3 + res4;
			}

			//Restore board when not allowed
			copyBoard(copiedBoard, board);
			return -2;
		}
	}
	else { //Multiple captures.
		//Man down to up
		if(from_x < to_x && to_y == from_y){
			for(i = from_x; i < 8 && i != to_x; i+=2)
			{	
				if(i < 8){
					if((board[i + 1][to_y] == white_man || board[i + 1][to_y] == white_king) && board[i + 2][to_y] == empty) {
					   board[i + 1][to_y] = empty;
						++n;
					}
					else {
						//Restore board when not allowed
						copyBoard(copiedBoard, board);
						return -2;
					}
				} else {
					//Restore board when not allowed
					copyBoard(copiedBoard, board);
					return -2;
				}
			}

			board[to_x][to_y] = black_man;
			board[from_x][from_y] = empty;
			return n;
		} //Man right to left
		else if(from_x == to_x && from_y > to_y){
			for(i = from_y; i >= 0 && i != to_y; i-=2)
			{	
				if(i >= 0){
					if((board[to_x][i - 1] == white_man || board[to_x][i - 1] == white_king) && board[to_x][i - 2] == empty) {
						board[to_x][i - 1] = empty;
						++n;
					}
					else {
						//Restore board when not allowed
						copyBoard(copiedBoard, board);
						return -2;
					}
				} else {
					//Restore board when not allowed
					copyBoard(copiedBoard, board);
					return -2;
				}
			}

			board[to_x][to_y] = black_man;
			board[from_x][from_y] = empty;
			return n;
		}//Man left to right
		else if(from_x == to_x && from_y < to_y){
			for(i = from_y; i < 8 && i != to_y; i+=2)
			{	
				if(i < 8){
					if((board[to_x][i + 1] == white_man || board[to_x][i + 1] == white_king) && board[to_x][i + 2] == empty) {
						board[to_x][i + 1] = empty;
						++n;
					}
					else {
						//Restore board when not allowed
						copyBoard(copiedBoard, board);
						return -2;
					}
				} else {
					//Restore board when not allowed
					copyBoard(copiedBoard, board);
					return -2;
				}
			}

			board[to_x][to_y] = black_man;
			board[from_x][from_y] = empty;
			return n;
		}//Man left down
		else if(to_y < from_y && to_x > from_x){
			int firstWaySuccess = 1, secondWaySuccess = 1;

			for(i = from_y ; i >= 0 ; i-=2){
				int isEnd = 0;
				if(i == to_y){
					isEnd = 1;
					for(j = from_x ; j < 8 && j != to_x; j+=2){
						if((board[j + 1][to_y] == white_man || board[j + 1][to_y] == white_king) && board[j + 2][to_y] == empty) {
							board[j + 1][to_y] = empty;
							++n;
						}	
						else {
							//Restore board when not allowed
							copyBoard(copiedBoard, board);
							firstWaySuccess = 0;
							n = 0;
							break;
						}
					}
					firstWaySuccess = 1;
				}

				if(isEnd == 1)
					break;

				if((board[from_x][i - 1] == white_man || board[from_x][i - 1] == white_king) && board[from_x][i - 2] == empty) {
					board[from_x][i - 1] = empty;
					++n;
				}
				else {
					//Restore board when not allowed
					copyBoard(copiedBoard, board);
					firstWaySuccess = 0;
					n = 0;
					break;
				}
			}

			if(firstWaySuccess == 1){
				board[to_x][to_y] = white_man;
				board[from_x][from_y] = empty;
				return n;
			}
			else{
				for(i = from_x ; i < 8 ; i+=2){
					int isEnd = 0;
					if(i == to_x){
						isEnd = 1;
						for(j = from_y ; j >= 0 && j != to_y; j-=2){
							if((board[to_x][j - 1] == white_man || board[to_x][j - 1] == white_king) && board[to_x][j - 2] == empty) {
								board[to_x][j - 1] = empty;
								++n;
							}	
							else {
								//Restore board when not allowed
								copyBoard(copiedBoard, board);
								secondWaySuccess = 0;
								n = 0;
								break;
							}
						}
						secondWaySuccess = 1;
					}

					if(isEnd == 1)
						break;

					if((board[i + 1][from_y] == white_man || board[i + 1][from_y] == white_king) && board[i + 2][from_y] == empty) {
							board[i + 1][from_y] = empty;
							++n;
					}
					else {
						//Restore board when not allowed
						copyBoard(copiedBoard, board);
						secondWaySuccess = 0;
						n = 0;
					}
				}
				if(secondWaySuccess == 0){
					//Restore board when not allowed
					copyBoard(copiedBoard, board);
					return -2;
				}
				else {
					board[to_x][to_y] = black_man;
					board[from_x][from_y] = empty;
					return n;
				}
			}
		}//Man rigt down
		else if(to_x > from_x && to_y > from_y){
			int firstWaySuccess = 1, secondWaySuccess = 1;

			for(i = from_x ; i < 8 ; i+=2){
				int isEnd = 0;
				if(i == to_x){
					isEnd = 1;
					for(j = from_y ; j < 8 && j != to_y; j+=2){
						if((board[to_x][j + 1] == white_man || board[to_x][j + 1] == white_king) && board[to_x][j + 2] == empty) {
							board[to_x][j + 1] = empty;
							++n;
						}	
						else {
							//Restore board when not allowed
							copyBoard(copiedBoard, board);
							firstWaySuccess = 0;
							n = 0;
							break;
						}
					}
					firstWaySuccess = 1;
				}

				if(isEnd == 1)
					break;

				if((board[i + 1][from_y] == white_man || board[i + 1][from_y] == white_king) && board[i + 2][from_y] == empty) {
					board[i + 1][from_y] = empty;
					++n;
				}
				else {
					//Restore board when not allowed
					copyBoard(copiedBoard, board);
					firstWaySuccess = 0;
					n = 0;
					break;
				}
			}

			if(firstWaySuccess == 1){
				board[to_x][to_y] = black_man;
				board[from_x][from_y] = empty;
				return n;
			}
			else{
				for(i = from_y ; i < 8 ; i+=2){
					int isEnd = 0;
					if(i == to_y){
						isEnd = 1;
						for(j = from_x ; j < 8 && j != to_x; j+=2){
							if((board[j + 1][to_y] == white_man || board[j + 1][to_y] == white_king) && board[j + 2][to_y] == empty) {
							   board[j + 1][to_y] = empty;
								++n;
							}	
							else {
								//Restore board when not allowed
								copyBoard(copiedBoard, board);
								secondWaySuccess = 0;
								n = 0;
								break;
							}
						}
						secondWaySuccess = 1;
					}

					if(isEnd == 1)
						break;

					if((board[from_x][i + 1] == white_man || board[from_x][i + 1] == white_king) && board[from_x][i + 2] == empty) {
						board[from_x][i + 1] = empty;
						++n;
					}
					else {
						//Restore board when not allowed
						copyBoard(copiedBoard, board);
						secondWaySuccess = 0;
						n = 0;
						break;
					}
				}
				if(secondWaySuccess == 0){				
					//Restore board when not allowed
					copyBoard(copiedBoard, board);
					return -2;
				}
				else{
					board[to_x][to_y] = black_man;
					board[from_x][from_y] = empty;
					return n;
				}
			}
		}
		//Restore board when not allowed
		copyBoard(copiedBoard, board);
		return -2;
	}
}
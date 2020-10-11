#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void menu();
void triangleOfSequences();
void horseRacingGame();
void countOccurrence();
int getDigitNum();

int main(){ 

	srand(time(NULL));
	menu();

	return 0;
}

/*The function that creates the menu to make the selections.*/
void menu () {
	int selection=1;

	do{ /*It allows you to print unconditionally every time you enter.*/

		printf("-----------------------------\n");
		printf("1.Horse Racing Game\n");
		printf("2.Occurence Counter\n");
		printf("3.Triangle of Sequences\n");
		printf("0.Exit\n");
		printf("-----------------------------\n");
		printf("Enter the selection:");
		scanf("%d", &selection);
		printf("\n");

		/*It allows you to make a choice*/
		switch (selection){

			case 0 :
				selection=0;
				break;
			
			case 1 :
				horseRacingGame();
				break;

			case 2 :
				countOccurrence();
				break;

			case 3 : 
				triangleOfSequences();
				break;

			default :
				break;
		}
	}

	while (selection != 0); /*Iterate the menu as long as the selection is not 0*/
	
}

/*The function that creates a series of triangles according to the random number generated.*/
void triangleOfSequences(){ 

	int i, j, random=0;

	random = 2 + rand()%9; /* It generates number between 2 and 10.*/

	/*It generate rows as many as the random number generated and 
	it increments itself as much as the square of the number at the beginning of each line.*/
	for(i=1; i <= random; i++){ 
		for(j=i; j <= i * i; j=j+i){
			printf("%d ", j);
		}
	printf("\n");
	}
}

/*The function that checks if the number received from the user is within the desired range.*/
int getInt(int mini, int maxi){

	int number;

	printf("Horse Number:");
	scanf("%d", &number);

	/*As long as the number received from the user is not within the desired range.*/
	while(number > maxi){ 

		printf("Horse Number:");
		scanf("%d", &number);
	}

	return number;
}

/*To produce random numbers in the desired range.*/
int numberGeneratorBetweenRange(int min, int max){ 

	int random;

	random = min + rand()%(max); 

	return random;
}

/*Horse racing function.*/
void horseRacingGame(){ 

	int i, j, random_time=0, random_horse=0, min=21, winner=0;
	int mini_horse=3, mini=3, maxi=3, min_time=10, max_time=11;
	int number=0, temp=0, flag=0;

	random_horse = numberGeneratorBetweenRange(mini,maxi); /*The random number generated 
															in the desired range is assigned to a variable.*/

	printf("Number of Horse:%d", random_horse); //The number that assigned to a varible is prints.*/
	printf("\n");

	number = getInt(mini_horse, random_horse); /*The random number generated in the desired range is 
												assigned to a variable.*/
	printf("Racing starts...");
	printf("\n");

	for(i=1; i <= random_horse; i++){

		printf("Horse %d:",i);

		random_time = numberGeneratorBetweenRange(min_time, max_time);

		for(j=1; j <= random_time; j++){ /*It prints "-" as long as the random number generated.*/
			flag=2;
			printf("-");
		}

		if(random_time < min){ /*It is checked whether the generated number is the smallest.*/
			min = random_time; /*If it is the smallest, it is kept as a min variable.*/
			winner = i; /*The index with the smallest number is kept as the winner.*/
			flag=0;
		}

		if(flag != 0){ /*The draw condition is checked.*/
			if(min == random_time)
				temp = random_time;
		}

		printf("\n");
	}

	if(temp == min) /*In case of the draw, it prints "No Winner!"*/
		printf("No winner!\n");
	else{
		if(number == winner){ /*If the number is won, it prints "You win".*/
			printf("You win!Winner is Horse %d",winner);
			printf("\n");
		}
		if(number != winner){ /*If the number is not won it prints "You lose" and 
								it prints horse that won.*/
			printf("You lose!Winner is Horse %d",winner);
			printf("\n");
		}
	}
}

void countOccurrence(){

    int bigNumber = 0, searchNumber = 0, flag = 1, coeff = 1,
    splitted = 0, occurrence = 0, slideCounter = 1;

    printf("Big Number:");
    scanf("%d", &bigNumber);

    printf("Search Number:");
    scanf("%d", &searchNumber);
   
    int digitNum = getDigitNum(searchNumber);

    /*The number is multiplied by 10 for each digit in the number searched for the last step.*/
    while (flag == 1){

        coeff *= 10; 
        splitted = bigNumber % coeff; 

        if (getDigitNum(splitted) == getDigitNum(searchNumber)) {

            flag = 0;
        }
    }

    flag = 1;

    /*If search number found, occurence is increment by 1*/
    while (flag == 1){
    	
        if (splitted == searchNumber) /*Occurence is incremented by one.*/
            ++occurrence;
        if(coeff == 1000000000){ /*Calculation is provided for high-digit numbers.*/
        	slideCounter *= 10;
        	splitted = bigNumber;
        }
        else{
        	coeff *= 10;
        	slideCounter *= 10;
        	splitted = bigNumber % coeff;
        }
        if (splitted == bigNumber){ 
            flag = 0;
            splitted /= slideCounter;

            if (splitted == searchNumber){

                ++occurrence;
            }
        }
        else
            splitted /= slideCounter;
        
    }
    printf("Occurence:%d\n", occurrence);
}

/*Takes input from the user and calculates number of digit*/
int getDigitNum(int input){

    int coeff = 1, flag = 1, digitNum = 0;

    /*Calculates number of digit.*/
    while (flag == 1){

        coeff *= 10;

        if (input % coeff != input)
            ++digitNum;
        else{
            ++digitNum;
            flag = 0;
        }
    }

    return digitNum;
}


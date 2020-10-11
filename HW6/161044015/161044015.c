#include <stdio.h>

void reverse_line(char line[], int line_lenght);
int find_size_of_line(char line[]);
void menu();
void encrypt_open_msg();
void decrypt_secret_msg();

int main(){

	menu();
}

//Printing menu.
void menu(){

	int choice;

	do{

		printf("1. Encrypt");
		printf("\n");
		printf("2. Decrypt");
		printf("\n");
		printf("0. Exit");
		printf("\n");
		printf("Choice:");
		printf("\n");
		scanf("%d", &choice);
		
		switch (choice){

		case 0 :
			break;

		case 1 :
			encrypt_open_msg();
			break;

		case 2 :
			decrypt_secret_msg();
			break;

		default :
			break;
		}
	}

	while(choice != 0);

}

//Encode and printing.
void encrypt_open_msg(){

	int key, i, j;
	int lineLenght;

	do{

		printf("Key: ");
		scanf("%d", &key);

	}

	while(1 > key || key >= 26);

    FILE* open = fopen("open_msg.txt", "r"); //Open open_msg file.
	FILE *secret = fopen("secret_msg.txt", "w"); //Open secret_msg file. 
	if (secret == NULL){ 
	    printf("Error\n");
	    return;
	}

    char line[1024];

    if(open != NULL){ 

	    while(fgets(line, 1024 , open)) {
	   
	        lineLenght = find_size_of_line(line);        

	        for(i=0; i < lineLenght; i++){
	        	
	        	if(line[i] != '\0'){
		        	if(line[i] == '.'){ 
		        		line[i] = '*';
		        	}
		        	else if(line[i] == ' '){ 
		        		line[i] = '_';
		        	}
	        	}
	        }

	        reverse_line(line, lineLenght); 

	        for(i=0; i < lineLenght; i++){
	        	if(line[i] != '*' && line[i] != '_'){
	        		for(j=0; j < key; j++){ 
	        			if(line[i] == 'a'){
	      					line[i] = 'z';	        
	        			}
	        			else{ 
	        				line[i]--;
	        			}
	        		}
	        	}
	        }

	        fprintf(secret, "%s", line); //Printing secret file.
	        printf("%s\n",line );
        }
    } 
    else{
    	printf("Error");
    }

    fclose(open); //close open file.
	fclose(secret); //close secret file.
}

//Decoding and printing to the file and terminal.
void decrypt_secret_msg(){
	int key, i, j;
	int lineLenght;

	do{

		printf("Key:");
		scanf("%d", &key);

	}

	while(1 > key || key >= 26);

    FILE* secret = fopen("secret_msg.txt", "r"); 
    FILE* open = fopen("open_msg.txt", "w");

    char line[1024];

    if(secret != NULL){
	    while(fgets(line, 1024 , secret)) { //Lines in the secret file are retrieved.

	        lineLenght = find_size_of_line(line); //Finds lines length.	        

	        for(i=0; i < lineLenght; i++){
	        	if(line[i] != '\0'){
		        	if(line[i] == '*'){ 
		        		line[i] = '.';
		        	}
		        	else if(line[i] == '_'){ 
		        		line[i] = ' ';
		        	}
	        	}
	        }

	        reverse_line(line, lineLenght); 

	        for(i=0; i < lineLenght; i++){
	        	if(line[i] != '.' && line[i] != ' '){
	        		for(j=0; j < key; j++){	//Move up to the key entered.
	        			if(line[i] == 'z'){
	      					line[i] = 'a';	        
	        			}
	        			else{
	        				line[i]++;
	        			}
	        		}
	        	}
	        }
	        
	        fprintf(open, "%s", line);
	        printf("%s\n",line );
        }
    } 
    else{
    	printf("Error");
    }

    fclose(secret);
    fclose(open);
    
}

int find_size_of_line(char line[]){ //Finds length of string.

	int i, line_lenght=0;

	for(i=0; line[i] != '\0'; i++){

		line_lenght++;
	}

	return line_lenght - 1;
}

void reverse_line(char line[], int line_lenght){ //Reverses string.
	int i, temp;
	for(i=0; i < (line_lenght / 2); i++){
		temp = line[i];
		line[i] = line[line_lenght-1-i];
		line[line_lenght-1-i] = temp;
	}
}


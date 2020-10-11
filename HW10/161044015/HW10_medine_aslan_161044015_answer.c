#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
	int data;
	struct Node* next;
	struct Node* pre;
}Node;

int read_each_line(FILE *file, Node *list);
void find_prime_number_array(int data, FILE *file);
int is_prime_number(int number);
void record_linked_list(Node *list);
int find_size();
void record_array(FILE *file);

int main(){

	int data,size;
	Node list,*head;
	FILE *file;
	
	record_linked_list(&list);
	
	record_array(file);	

	return 0;
}

//It is the function that finds and returns the size of the file. According to the size coming from here memory allocated.
int find_size(FILE *file)
{
	int data,size = 0;
	
	file = fopen("data.txt","r");

 	while(fscanf(file, "%d,00\n", &data) != EOF){
 		size++;
 	}
 	fclose(file);
 	return size ;
}

//Reads file.
int read_each_line(FILE *file, Node *list){

	int data;
	
	if (fscanf(file, "%d,00\n", &data) != EOF)
	{
		return data;
	}
	
 	return 0;
}

//Finds given number prime or not.
int is_prime_number(int number){

	int i;
	if(number == 1){
		return 0;
	}

	for(i=2; i < number; i++){
		if(number % i == 0){
			return 0;
		}
	}
	return 1;
}

//The numbers cames from file assign a linked list and printed prime numbers.
void record_linked_list(Node *list){

	int data,flag1=1, flag2 = 1;
	FILE *file, *result_ll;
	clock_t five_border, seven_border,end_ll,start_ll;
	double fiveResult,sevenResult,totalResult;

	//Open files.
	file = fopen("data.txt","r");
	result_ll = fopen("output_prime_LiknedList.txt", "w+");

	Node *temp,*head;

	//Start time.
	start_ll = clock();

 	head = list;

 	//Head of the linked list.
	if (data = read_each_line(file,list))	
	{
		head->data = data;
		head->pre = NULL;
		head->next = NULL;
	}

	//Other elements.
	while(data = read_each_line(file,list)){
			
		temp = (Node*)malloc(sizeof (Node));
		temp->data = data;
 		temp->pre = head;
 		temp->next = NULL;
 		head->next = temp;
 		head = head->next;
 	}

	head = list;

	//Prime numbers printed into the file.
	while(head->next != NULL)
	{
		if(is_prime_number(head->data))
		{
			fprintf(result_ll,"%d\n", head->data);
			printf("%d\n", head->data);

			//Calculate time for 500000.
			if(head->data > 500000 && flag1){
				five_border = clock();
				fiveResult = (double)(five_border - start_ll) / CLOCKS_PER_SEC;
				flag1 = 0;
			}

			//Calculate time for 750000.
			else if(head->data > 750000 && flag2){
				seven_border = clock();
				sevenResult = (double)(seven_border - start_ll) / CLOCKS_PER_SEC;
				flag2 = 0;
			}
		}
		head = head->next;
	}

	if(is_prime_number(head->data))
	{
		fprintf(result_ll,"%d\n", head->data);
		printf("%d\n", head->data);
	}

	end_ll = clock();

	totalResult = (double)(end_ll - start_ll) / CLOCKS_PER_SEC;

	fprintf(result_ll,"500,000 result is %lf\n",fiveResult);
	printf("500,000 result is %lf\n",fiveResult);

	fprintf(result_ll,"750,000 result is %lf\n",sevenResult);
	printf("750,000 result is %lf\n",sevenResult);

	fprintf(result_ll,"Total result ıs %lf\n",totalResult );
	printf("Total result is %lf\n",totalResult);

	fclose(file);
	fclose(result_ll);
}

//The numbers cames from file assign an array and printed prime numbers.
void record_array(FILE *file){

	int *array;
	int size = 0, i, flag1=1, flag2=1;
	size = find_size(file);
	Node *list;
	clock_t five_border, seven_border,end_ll,start_ll;
	double fiveResult,sevenResult,totalResult;
	FILE *result_arr;

	file = fopen("data.txt","r");
	result_arr = fopen("output_prime_dynamic_array.txt","w+");

	//Start time.
	start_ll = clock();

	//Create dynamic array.
	array = (int*)malloc(size * sizeof(int));

	//Assign numbers to the array and print prime numbers.
	for(i=0; i < size ; i++){

		array[i] = read_each_line(file, list);
		
		//Prints prime numbers.
		if(is_prime_number(array[i]) == 1){
			fprintf(result_arr,"%d\n", array[i]);
			printf("%d\n", array[i]);
		}

		//Calculate time for 500000.
		if(array[i] > 500000 && flag1){	
			five_border = clock();
			fiveResult = (double)(five_border - start_ll) / CLOCKS_PER_SEC;
			flag1 = 0;
		}

		//Calculate time for 750000.
		else if(array[i] > 750000 && flag2){
			seven_border = clock();
			sevenResult = (double)(seven_border - start_ll) / CLOCKS_PER_SEC;
			flag2 = 0;
		}
	}

	//Calculate time for 1000000.
	end_ll = clock();

	totalResult = (double)(end_ll - start_ll) / CLOCKS_PER_SEC;

	fprintf(result_arr,"500,000 result is %lf\n",fiveResult);
	printf("500,000 result is %lf\n",fiveResult);

	fprintf(result_arr,"750,000 result is %lf\n",sevenResult);
	printf("750,000 result is %lf\n",sevenResult);

	fprintf(result_arr,"Total result is %lf\n",totalResult );
	printf("Total result is %lf\n",totalResult);

	fclose(file);
	fclose(result_arr);
}

#include <stdio.h>
int find_size_of_line(char line[]);

int main(){

	char date_first[10], date_final[10];
	int day_first, month_first, year_first, check=0, day_final, month_final, year_final;
	int i, j, k, final_m, final_d;

	 FILE *input;
	 input = fopen("input_date.txt", "w+");//Open input_date file.

	 if(input != NULL){

	 	do{
	 		check = 0;

		 	printf("Please enter the first date in dd/MM/yyyy format:");
		 	scanf("%s", date_first);

		 	//Convert char to integer.
		 	year_first = ((date_first[6] - 48) * 1000 + (date_first[7] - 48) * 100 + (date_first[8] - 48) * 10 + (date_first[9] - 48));
		 	day_first = ((date_first[0] - 48) * 10) + (date_first[1] - 48); 
		 	month_first = ((date_first[3] - 48) * 10) + (date_first[4] - 48);

		 	if(find_size_of_line(date_first) != 10){
		 		check = 1;
		 	}
		 
		 	if(day_first == 0 || month_first == 0 || year_first == 0 || month_first > 12){
		 		check = 1;
		 	}

		 	if(month_first == 1 || month_first == 3 || month_first == 5 || month_first == 7 || month_first == 8 || month_first == 10 || month_first == 12){
		 		if(day_first > 31){
		 			check = 1;
		 		}
		 	}

		 	else if(month_first == 4 || month_first == 6 || month_first == 9 || month_first == 11 ){
		 		if(day_first > 30){
		 			check = 1;
		 		}
		 	}

		 	//Month February
		 	else if(month_first == 2){
		 		if((year_first % 100) == 0){
		 			if((year_first % 400) != 0){
		 				if(day_first > 28){
			 				check = 1;
			 			}
			 		}
			 		else if((year_first % 400) == 0){
		 				if(day_first > 29){
		 					check = 1;
		 				}
		 			}
			 	}

		 		else if((year_first % 4) != 0 ){
		 			if(day_first > 28){
			 			check = 1;
			 		}
		 		}
		 	
		 		else if((year_first % 4) == 0 ){
		 			if(day_first > 29){
		 				check = 1;
			 		}
		 		}
		 	}

			} while(check == 1);

		do{

			check = 0;

		 	printf("Please enter the final date in dd/MM/yyyy format:");
		 	scanf("%s", date_final);

		 	day_final = ((date_final[0] - 48) * 10) + (date_final[1] - 48);
		 	month_final = ((date_final[3] - 48) * 10) + (date_final[4] - 48);
		 	year_final = ((date_final[6] - 48) * 1000 + (date_final[7] - 48) * 100 + (date_final[8] - 48) * 10 + (date_final[9] - 48));

		 	if(find_size_of_line(date_final) != 10){
		 		check = 1;
		 	}

		 	if(day_final == 0 || month_final == 0 || year_final == 0 || month_final > 12){
		 		check = 1;
		 	}

		 	if(month_final == 1 || month_final == 3 || month_final == 5 || month_final == 7 || month_final == 8 || month_final == 10 || month_final == 12){
		 		if(day_final > 31){
		 			check = 1;
		 		}
		 	}

		 	else if(month_final == 4 || month_final == 6 || month_final == 9 || month_final == 11){
		 		if(day_final > 30){
		 			check = 1;
		 		}
		 	}

		 	//Month February.
		 	else if(month_final == 2){
		 		if((year_final % 100) == 0){
		 			if((year_final % 400) != 0){
		 				if(day_final > 28){
			 				check = 1;
			 			}
			 		}
			 		else if((year_final % 400) == 0){
		 				if(day_final > 29){
		 					check = 1;
		 				}
		 			}
			 	}

		 		else if((year_final % 4) != 0 ){
		 			if(day_final > 28){
			 			check = 1;
			 		}
		 		}
		 	
		 		else if((year_final % 4) == 0 ){
		 			if(day_final > 29){
		 				check = 1;
			 		}
		 		}
		 	}

		}while(check == 1);

		//Iterate year times.
		for(i=year_first; i <= year_final; i++){
			if(i != year_first){
				month_first = 1;
			}

			if(i == year_final){
				final_m = month_final;
			}

			else{

				final_m = 12;
			}
			//Iterate month times.
			for(j=month_first; j <= final_m; j++){
				if(j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12){
					if(j==month_final && i == year_final){
						final_d = day_final;
					}
					else{
						final_d = 31;
					}
					//Iterate day times.
					for(k=day_first; k <= final_d; k++){
						fprintf(input, "%02d/%02d/%03d\n", k,j,i);
					}
					//End of the month.
					day_first = 1;
				}

				else if(j == 4 || j == 6 || j == 9 || j == 11){
					if(j== month_final && i == year_final){
						final_d = day_final;
					}

					else{
						final_d = 30;
					}

					for(k=day_first; k <= final_d; k++){
						fprintf(input, "%02d/%02d/%03d\n", k,j,i);
					}

					day_first = 1;
				}

				else if(j == 2){
					if((i % 100) == 0){
			 			if((i % 400) != 0){
			 				if(j== month_final && i == year_final){
								final_d = day_final;
							}
							//Control February 28.
							else{
								final_d = 28;
							}

							for(k=day_first; k <= final_d; k++){
								fprintf(input, "%02d/%02d/%03d\n", k,j,i);
							}

							day_first = 1;
				 		}

				 		else if((i % 400) == 0){
			 				if(j== month_final && i == year_final){
								final_d = day_final;
							}
							//Control February 29.
							else{
								final_d = 29;
							}

							for(k=day_first; k <= final_d; k++){
								fprintf(input, "%02d/%02d/%03d\n", k,j,i);
							}

							day_first = 1;
			 			}
				 	}

				 	//Month February is different.
			 		else if((i % 4) != 0 ){
			 			if(j== month_final && i == year_final){
							final_d = day_final;
						}
						else{
							final_d = 28;
						}

						for(k=day_first; k <= final_d; k++){
							fprintf(input, "%02d/%02d/%03d\n", k,j,i);		
						}

						day_first = 1;
				 		}
			 	
			 		else if((i % 4) == 0 ){
			 			if(j== month_final && i == year_final){
							final_d = day_final;
						}

						else{
							final_d = 29;
						}

						for(k=day_first; k <= final_d; k++){
							fprintf(input, "%02d/%02d/%03d\n", k,j,i);
						}

						day_first = 1;
				 	}
				}
			}	
		}
	}

	else{
	 	printf("Error\n");
	}

	fclose(input);

	FILE *new;
	char line[11];
	int days[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	int month, day, year, temp_day, temp_month, temp_year, calculate_day=0;
    
	input = fopen("input_date.txt", "r"); //Read input_date file.
    new = fopen("new_date.txt", "w+");//Create new_date file.
   
	while(fgets(line, 12, input) != NULL){ 

		//Convert date to integer.
		year = ((line[6] - 48) * 1000 + (line[7] - 48) * 100 + (line[8] - 48) * 10 + (line[9] - 48));
		day =  ((line[0] - 48) * 10) + (line[1] - 48);
   		month = ((line[3] - 48) * 10) + (line[4] - 48);
   		
   		//Keeping integer year day and month.
   		temp_day = day;
   		temp_month = month;
   		temp_year = year;

   		//Finds which day of the week a day is.
		temp_year -= temp_month < 3;
		calculate_day = (temp_year + (temp_year/4) - (temp_year/100) + (temp_year/400) + days[temp_month-1] + temp_day) % 7;
		
   		if(calculate_day == 1)
   			fprintf(new, "Monday,");
   		else if(calculate_day == 2)
   			fprintf(new, "Tuesday,");
   		else if(calculate_day == 3)
   			fprintf(new, "Wednesday,");
   		else if(calculate_day == 4)
   			fprintf(new, "Thursday,");
   		else if(calculate_day == 5)
   			fprintf(new, "Friday,");
   		else if(calculate_day == 6)
   			fprintf(new, "Saturday,");
   		else if(calculate_day == 0)
   			fprintf(new, "Sunday,");
   		
   		//Finds month and prints with day and year.
		if(month == 1)
			fprintf(new, "January %d,%d\n", day, year);
		else if(month == 2)
			fprintf(new, "February %d,%d\n", day, year);
		else if(month == 3)
			fprintf(new, "March %d,%d\n", day, year);
		else if(month == 4)
			fprintf(new, "April %d,%d\n", day, year);
		else if(month == 5)
			fprintf(new, "May %d,%d\n", day, year);
		else if(month == 6)
			fprintf(new, "June %d,%d\n", day, year);
		else if(month == 7)
			fprintf(new, "July %d,%d\n", day, year);	
		else if(month == 8)
			fprintf(new, "August %d,%d\n", day, year);	
		else if(month == 9)
			fprintf(new,"September %d,%d\n", day, year);
		else if(month == 10)
			fprintf(new, "October %d,%d\n", day, year);
		else if(month == 11)
			fprintf(new, "November %d,%d\n", day, year);
		else if(month == 12)
			fprintf(new, "December %d,%d\n", day, year);

	}
	//Close files.
	fclose(input);
	fclose(new);
}

int find_size_of_line(char line[]){ //Finds length of string.

	int i, line_lenght=0;

	for(i=0; line[i] != '\0'; i++){

		line_lenght++;
	}

	return line_lenght;
}


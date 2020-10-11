/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/


#include "hw4_io.h"
#include <stdio.h>

//3. dereceden polinom yazdırmak için kullanıcıdan 4 adet katsayı alan fonksiyondur.
int read_polynomial3(double * a0, double * a1, double * a2, double * a3){

	printf("a3:");
	scanf("%lf", a3);

	//Derecesi 3 olan terimin katsayısı 0 ise kullanıcıdan tekrar sayı alınır.
	if (*a3==0) {
		printf("Polynomial degree is not three.Please enter a new number:");
		scanf("%lf", a3);
	}

	printf("a2:");
	scanf("%lf", a2);
	
	printf("a1:");
	scanf("%lf", a1);
	
	printf("a0:");
	scanf("%lf", a0);

	return 0;
}

//4.dereceden polinom yazdırmak için kullanıcıdan 5 adet katsayı alan fonksiyondur.
int read_polynomial4(double * a0, double * a1, double * a2, double * a3, double * a4) {

	printf("a4:");
	scanf("%lf", a4);

	//Derecesi 4 olan terimin katsayısı 0 ise kullanıcıdan tekrar sayı alınır.
	if(*a4==0) {
		printf("Polynomial degree is not four.Please enter a new number:");
		scanf("%lf", a4);
	}

	printf("a3:");
	scanf("%lf", a3);

	printf("a2:");
	scanf("%lf", a2);
	
	printf("a1:");
	scanf("%lf", a1);
	
	printf("a0:");
	scanf("%lf", a0);

	return 0;
}

//read_polynomial3 fonksiyonunda alınan katsayılar ile 3. dereceden fonksiyon yazdırır.
//Alınan sayıların pozitif mi negatif mi oldukları kontrol edilir.
//Sayıların 0,1 ya da -1 eşit olma durumları da ayrıca kontrol edilir.
//Alınan sayı 0 ise hiçbir şey yazdırmaz.
//Sayıların virgülden sonraki kısımları 0 ise yalnızca virgülden önceki kısımları yazdırılır.
void write_polynomial3(double a0, double a1, double a2, double a3){

	if (a3 == 1) {
		printf("x^3");
	}
	else if (a3 == -1) {
		printf("-x^3");
	}
	else {
		if((int)(a3*10) % 10 != 0){
			printf("%.1lfx^3", a3);
		}
		else {
			printf("%dx^3", (int)a3);
		}
	}

	if (a2 == 1) {
		printf("+x^2");
	}
	else if (a2 == -1) {
		printf("-x^2");
	}

	if (a2 < 0 && a2 != -1) {
		if ((int)(a2*10) % 10 != 0) {
			printf("%.1lfx^2", a2);
		}
		else{
			printf("%dx^2", (int)a2);
		}
	}
	else if (a2 > 0 && a2 != 1) {
		if ((int)(a2*10) % 10 != 0) {
			printf("+%.1lfx^2", a2);
		}
		else {
			printf("+%dx^2", (int)a2);
		}
	}

	if (a1 == 1) {
		printf("+x");
	}
	else if (a1 == -1) {
		printf("-x");
	}

	if (a1 < 0 && a1 != -1) {
		if((int)(a1*10) % 10 != 0) {
			printf("%.1lfx", a1);
		}
		else {
			printf("%dx", (int)a1);
		}
	}
	else if (a1 > 0 && a1 != 1) {
		if ((int)(a1*10) % 10 != 0) {
			printf("+%.1lfx", a1);
		}
		else {
			printf("+%dx", (int)a1);
		}
	}

	if (a0 > 0){
		if((int)(a0*10) % 10 != 0) {
			printf("+%.1lf", a0);
		}
		else {
			printf("+%d", (int)a0);
		}
	}
	else if (a0 < 0) {
		if ((int)(a0*10) % 10 != 0) {
			printf("%.1lf", a0);
		}
		else {
			printf("%d", (int)a0);
		}
	}

	printf("\n");
	
}

//read_polynomial4 fonksiyonunda alınan katsayılar ile 4. dereceden fonksiyon yazdırır.
//Alınan sayıların pozitif mi negatif mi oldukları kontrol edilir.
//Sayıların 0,1 ya da -1 eşit olma durumları da ayrıca kontrol edilir.
//Alınan sayı 0 ise hiçbir şey yazdırmaz.
//Sayıların virgülden sonraki kısımları 0 ise yalnızca virgülden önceki kısımları yazdırılır.
void write_polynomial4(double a0, double a1, double a2, double a3, double a4){

	if (a4 == 1) {
		printf("x^4");
	}
	else if (a4 == -1) {
		printf("-x^4");
	}
	else {
		if ((int)(a4*10) % 10 != 0) {
			printf("%.1lfx^4", a4);
		}
		else {
			printf("%dx^4", (int)a4);
		}
	}
	
	if(a3 == 1) {
		printf("+x^3");
	}
	else if (a3 == -1) {
		printf("-x^3");
	}

	if (a3 < 0 && a3 != -1) {
		if((int)(a3*10) % 10 != 0) {
			printf("%.1lfx^3", a3);
		}
		else{
			printf("%dx^3", (int)a3);
		}
	}
	else if (a3 > 0 && a3 != 1) {
		if ((int)(a3*10) % 10 != 0) {
			printf("+%.1lfx^3", a3);
		}
		else {
			printf("+%dx^3", (int)a3);
		}
	}

	if (a2 == 1) {
		printf("+x^2");
	}
	else if (a2 == -1) {
		printf("-x^2");
	}

	if (a2 < 0 && a2 != -1) {
		if ((int)(a2*10) % 10 != 0) {
			printf("%.1lfx^2", a2);
		}
		else {
			printf("%dx^2", (int)a2);
		}
	}
	else if (a2 > 0 && a2 != 1) {
		if ((int)(a2*10) % 10 != 0) {
			printf("+%.1lfx^2", a2);
		}
		else {
			printf("+%dx^2", (int)a2);
		}
	}

	if (a1 == 1) {
		printf("+x");
	}
	else if(a1 == -1) {
		printf("-x");
	}

	if (a1 < 0 && a1 != -1) {
		if ((int)(a1*10) % 10 != 0) {
			printf("%.1lfx", a1);
		}
		else {
			printf("%dx", (int)a1);
		}
	}
	else if (a1 > 0 && a1 != 1) {
		if ((int)(a1*10) % 10 != 0) {
			printf("+%.1lfx", a1);
		}
		else {
			printf("+%dx", (int)a1);
		}
	}
	
	if (a0 > 0) {
		if((int)(a0*10) % 10 != 0) {
			printf("+%.1lf", a0);
		}
		else {
			printf("+%d", (int)a0);
		}
	}
	else if (a0 < 0) {
		if ((int)(a0*10) % 10 != 0) {
			printf("%.1lf", a0);
		}
		else {
			printf("%d", (int)a0);
		}
	}
	printf("\n");
}

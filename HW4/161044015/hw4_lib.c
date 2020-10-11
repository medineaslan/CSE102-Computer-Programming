/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include "hw4_lib.h"
#include <stdio.h>
#include <math.h>


//NOT: Fonksiyonlar test edilirken;
//epsilon:0.0001
//delta:0.001
//olarak kabul edilmiştir.

//Fonksiyonun xs ve xe sınırları arasında kalan bölgenin alanını bularak integral hesabı yapar.
double integral(double f(double x), double xs, double xe, double delta){

	double i, integral1=0;

	 for(i=xs; i < xe; i = i + delta){
	 	integral1 += (f(i) * delta);
	 }

	 return integral1;
}

//Fonksiyonun xs, xe ve ys,ye sınırları arasında kalan bölgenin hacmini bularak integral hesabı yapar.
double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta){

	double i, j, integral2=0;

	for(i=xs; i < xe; i = i + delta){
		for(j=ys; j < ye; j = j + delta){
			integral2 += delta * delta * f(i,j);
		}
	}

	return integral2;
}

//Ödevde verilen formüle göre numerik türev hesabı yapar.
int derivatives(double f(double a), double x, double eps, double * d1, double * d2){

	*d1 = (f(x + eps) - f(x - eps)) / (2 * eps);
	*d2 = (f(x + eps) - (2 * f(x)) + f(x - eps)) / (eps * eps);

	if (eps == 0) {
		return -1;
	}

	return 1;
}

//Numerik 1. ve 2. türev ile manuel olarak hesaplanan 1. ve 2. türevlerin 
//farkının mutlak değerini alarak hata hesabı yapar.
//NOT:Fark çok küçük olduğundan print ederken %.15f gibi
//bir değer ile görülebilmektedir.
int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double * e2){

	double compare_f1, compare_f2, compare_d1, compare_d2;

	derivatives(f, x, eps, &compare_f1, &compare_f2);

	compare_d1 = d1(x);
	compare_d2 = d2(x);
	
	*e1 = fabs(compare_f1 - compare_d1);
	*e2 = fabs(compare_f2 - compare_d2);
	
	return 1;
}

//Birinci ve ikinci türev kullanılarak implement edilen
//NewtonRapson algoritması ile verilen fonksiyonun bir kökünü bulur.
//MaxIter: İterasyon sayısı
//Root: Bulunan kök
//NOT:Bu fonksitonda math.h kütüphanesinden pow fonksiyonu kullanılmıştır
//link ederken -lm eklenmelidir.
int find_roots(double f(double x), double * x1, double * x2, double * x3, double * x4){
	double root = 10; 
	int maxIter = 100;
	int iteration = 0;

	while (iteration < maxIter){
		double d1, d2;
		derivatives(f, root, 0.001, &d1, &d2);
		root = root - ((f(root) * d1)) / (pow(d1,2) - (f(root) * d2));	
		iteration++;
	}

	*x1 = root;
   	return 0;
}
 



/*Medine Aslan 161044015*/

#include <stdio.h>
#include <math.h>

#define PI 3.14

int side1, side2;

double circle_area(double radius) { /*The function that calculates a circle's area.*/

	double area;
	area = PI * pow(radius,2);

	return area;
}

double calc_hypotenuse(int side1, int side2) { /*The function that calculates hypotenuse.*/

	double hypotenuse;
	hypotenuse = sqrt(pow(side1, 2) + pow(side2, 2));

	return hypotenuse;
}

double calc_radius_of_smallest_circle(int side1, int side2) { /*The function that calculates smallest circle's radius.*/

	double radius;
	radius = calc_hypotenuse(side1 , side2) / 2;

	return radius;
}

double calc_radius_of_largest_circle(int side1, int side2) { /*The function that calculates largest circle's radius.*/

	double radius;

	if(side1 > side2) 
		radius = side2 / 2.00;
	else 
		radius = side1 / 2.00;

	return radius;
}

double calc_area_of_smallest_circle(int side1, int side2) { /*The function that calculates smallest circle's area.*/

	double areasmallest;
	areasmallest = PI * pow(calc_radius_of_smallest_circle(side1, side2), 2);

	return areasmallest;
}

double calc_area_of_largest_circle(int side1, int side2) { /*The function that calculates largest circle's area.*/

	double arealargest;
	arealargest = PI * pow(calc_radius_of_largest_circle(side1, side2), 2);

	return arealargest;
}

double calc_area_of_square (int side) { /*The function that calculates a square's area.*/

	double areasquare;
	areasquare = pow(side, 2.0);

	return areasquare;
}

double calc_area_of_smallest_square(int side1, int side2) { /*The function that calculates smallest square's area.*/

	double area;

	if(side1 > side2) 
		area = calc_area_of_square (side1);
	else 
		area = calc_area_of_square (side2);

	return area;
}

double calc_area_of_largest_square (int side1, int side2) { /*The function that calculates largest square's area.*/

	double area;

	if(side1 > side2) 
		area = calc_area_of_square (side2);
	else 
		area = calc_area_of_square (side1);

	return area;
}

void display_results (double largest_circle, double largest_square, double smallest_circle, double smallest_square) { /*The function that prints results on the screen.*/

	largest_circle = calc_area_of_largest_circle(side1, side2);
	largest_square = calc_area_of_largest_square(side1, side2);
	smallest_circle = calc_area_of_smallest_circle(side1, side2);
	smallest_square = calc_area_of_smallest_square(side1, side2);

	printf("The area of the largest circle that fits inside a rectangle:	  	%.2lf\n", largest_circle);
	printf("The area of the largest square that fits inside a rectangle:	  	%.2lf\n", largest_square);
	printf("The area of the smallest circle that surrounds the same rectangle:	%.2lf\n", smallest_circle);
	printf("The area of the smallest square that surrounds the same rectangle:	%.2lf\n", smallest_square);

}

int main() { /*The function calls the function where the results are printed on the screen and requires the user to specify the edge lengths.*/

	double largest_circle, largest_square, smallest_circle, smallest_square;

	printf("Enter first side for rectangle:");
	scanf("%d", &side1);

	printf("Enter second side for rectangle:");
	scanf("%d", &side2);

	display_results(largest_circle, largest_square, smallest_circle, smallest_square);

	return 0;

}

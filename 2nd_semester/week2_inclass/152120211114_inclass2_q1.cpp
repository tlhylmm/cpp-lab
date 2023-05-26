#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define UZUNLUK 10
void foo(int dz[], int* x, int* y)
{
	//max1 en buyuk sayý, max2 en buyuk 2. sayý
	//min1 en kucuk sayi, min2 en kucuk 2. sayý
	int m, n, max1, max2, min1, min2;
	int min, min_index = 0, temp = 0;
	for (m = 0; m < UZUNLUK; m++) {
		min = dz[m];
		for (n = m + 1; n < 10; n++) {
			if (dz[n] < min) {
				min_index = n;
				min = dz[n];
			}
		}
		dz[m] = temp; //store the value in a temp integer
		dz[m] = dz[min_index]; //put minimum value before the others
		dz[n] = temp; //restore the value stored in temp
	}
	max2 = dz[8];
	min2 = dz[2];

}
void main()
{
	int i, sayilar[UZUNLUK], max2, min2;
	srand(time(NULL));
	for (i = 0; i < UZUNLUK; i++) {
		sayilar[i] = rand() % 100;
		printf("sayi [ %d ] = %d\n", i, sayilar[i]);
	}
	foo(sayilar, &max2, &min2);
	printf("%d %d\n", max2, min2);
}
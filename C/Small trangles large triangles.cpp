#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

double Calc_Area(triangle tr){
	double p = (tr.a + tr.b + tr.c) / 2.0;
	return p * (p-tr.a) * (p-tr.b) * (p-tr.c);
}

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
	int i,j;
	triangle temp;
	for(i =0; i<n-1; i++){
		for (j = i+1; j< n; j++){
			if (Calc_Area(tr[i]) > Calc_Area(tr[j])){
				temp = tr[i];
				tr[i] = tr[j];
				tr[j] = temp;
			}
		}
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = (triangle *)malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	getchar();
	return 0;
}

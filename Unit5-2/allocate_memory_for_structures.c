 #include <stdio.h>
#include <stdlib.h>

struct point{
	int x;
	int y;
};

void printPoint(struct point);
void printPoly(struct point *, int);
void initializePoly(struct point *, int);

int main(void) {

  struct point * polygon;
  int num;
    // Fill in your main function here
  scanf("%d", &num);
  polygon = (struct point *) malloc(num * sizeof(struct point));
  initializePoly( polygon, num );
  printPoly( polygon, num );
  free(polygon);

}

void printPoint(struct point pt) {
    printf("(%d, %d)\n", pt.x, pt.y);
}

void printPoly(struct point *ptr, int N) {
    int i;
    for (i=0; i<N; i++) {
        printPoint(ptr[i]);
    }
}

// Write your initializePoly() function here
void initializePoly(struct point * ptr, int num){

  int i;
  for ( i=0; i<num; i++ ){

    ptr[i].x = -i;
    ptr[i].y = i*i;

  }

}

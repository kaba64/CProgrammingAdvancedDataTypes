#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

void readDate(struct date *);
void printDate(struct date);

int main(void) {
	struct date today;
	readDate(&today);
	printDate(today);
	return 0;
}

void readDate(struct date * pointer){

   scanf("%d %d %d", &(* pointer).year, &(* pointer).month, &(* pointer).day);

}

void printDate(struct date data){

    printf("%d/%02d/%d", data.month, data.day, data.year);

}

#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

/* function prototypes */
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date);

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}

/* add your function definitions here */

void readDate(struct date * pointer){

   scanf("%d %d %d", &(* pointer).year, &(* pointer).month, &(* pointer).day);

}

void printDate(struct date data){

    printf("%02d/%02d/%d\n", data.month, data.day, data.year);

}

struct date advanceDay(struct date today){

  struct date tomorrow;

  if ( today.month == 2 ){

    if ( today.day == 28  ){

        tomorrow.day = 1;
        tomorrow.month = 3;
	tomorrow.year = today.year;

    } else{

        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
	tomorrow.year = today.year;
    }

    } else if ( today.month == 12 ){

    if ( today.day == 31  ){

        tomorrow.day = 1;
        tomorrow.month = 1;
	tomorrow.year = today.year + 1;

    } else{

        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
	tomorrow.year = today.year;
    }

  }else if( today.month == (1 || 3 || 5 || 7 || 8 || 10  )){

    if ( today.day == 31  ){

        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;

    } else{
        printf("hello");
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }

  }else{

    if ( today.day == 30  ){
       // printf("hello");
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
	tomorrow.year = today.year;

    } else{
        //printf("hello");
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }

  }
  return tomorrow;
}

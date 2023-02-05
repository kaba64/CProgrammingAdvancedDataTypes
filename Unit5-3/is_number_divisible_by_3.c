#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

// Write your prototypes here

struct digit *readNumber(void);
void printNumber(struct digit *);
struct digit * append(struct digit *, struct digit *);
void freeNumber(struct digit *);
int divisibleByThree(struct digit *);

int main(void) {
    struct digit *start;
    start = readNumber();
    printf("The number ");
    printNumber(start);
    if (divisibleByThree(start)) 
        printf("is divisible by 3.\n");
    else
        printf("is not divisible by 3.\n");
    freeNumber(start);
    return 0;
}

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit *readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

// Write your divisibleByThree() function here

int divisibleByThree( struct digit *ptr ){

  struct digit * tmp;
  int numb = 0, i = 1, out;
  
  while ( ptr != NULL ){

    tmp = ptr;
    numb = numb + i * ptr->num;
    i = i*10;
    ptr = tmp->next;

  }

  if(numb%3 == 0 ){

    out = 1;
    
  }else{

    out = 0;

  }
  return out;
}

// the solution of the edx
//int divisibleByThree(struct digit * start) {
//    struct digit * ptr = start;
//    int qsum = 0;
//    while (ptr!=NULL) {
//        qsum += ptr->num;
//        ptr = ptr->next;
//    }
//    if (qsum%3==0) return 1;
//    else return 0;
//}


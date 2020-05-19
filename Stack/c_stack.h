#include <stdio.h>
#include <stdlib.h>

/* typical C boolean set-up */
#define TRUE 1
#define FALSE 0

typedef struct StackStruct {
    char*    darr;  /* pointer to dynamic array of chars  */
    int     allocated;  /* amount of space allocated */
    int     inUse; /* top of stack indicator - counts how many values are on the stack   */
} Stack;

void init (Stack* s) {
    s->allocated = 4;
    s->darr = (char*) malloc ( sizeof (char) * s->allocated); /* sizeof (char) * allocated to make enough space for each char */
    s->inUse  = 0;
}

void push (Stack* s, char val, int debugMode) {
    /* check if enough space currently on stack and grow if needed */
    if(!(s->allocated > (s->inUse + 1))) { 
        char *temp;
        temp = s->darr;

        s->allocated = s->allocated + 4;
        s->darr = (char*) malloc(sizeof(char) * s->allocated);

        for(int i = 0; i < s->allocated - 4; i++)
        s->darr[i] = temp[i];

        free(temp);
        if ( debugMode == TRUE )
            printf("Old size: %d, New Size: %d. Number of Values Copied: %d\n", s->allocated - 4, s->allocated, s->inUse);
    }
    /* add val onto stack */
    s->darr[s->inUse] = val;
    s->inUse = s->inUse + 1;
}

int isEmpty (Stack* s) {
    if ( s->inUse == 0)
        return TRUE;
    else
        return FALSE;
}


char top (Stack* s) {
    return (s->darr[s->inUse-1]);
}

void pop (Stack* s) {
    s->inUse = s->inUse - 1;
}

void reset (Stack* s) {
    s->inUse = 0;
    s->allocated = 4;
    free(s->darr);
    s->darr = NULL;
}

void printStack(Stack *s) {
    
}
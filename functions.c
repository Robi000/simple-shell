#include "link.h"

void type_prompt()
{
    static int first_time=1;
    if ( first_time) {
        const char* CLEAR_SCREEN_ANSI = " \e[l;lH\e[2J";
        wirte(STDOUT_FILENO,CLEAR_SCREEN_ANSI,12);
        first_time = 0;
    }
    printf("$");
}

 
void read_command (  char cmd[], char *par[] ) {
    char line [1224];
    int count = 0, i = 0, j = 0;
    char *array[100], *pch;

    for (;;) {
        int c = getc ( stdin );
        line[count++] = (char) c;
        if ( c == '\n' ) break;
    }
    if ( count == 1 ) return;
    pch = strtok (line, " \n");
    while ( pch != NULL ) {
        array[i++] = strdup ( pch );
        pch = strtok (NULL, " /n");
    }
    strcpy ( cmd, array[0] );
    for ( int j = 0; j < i; j++)
        par[j] = array[j];
    par[i] = NULL;
}



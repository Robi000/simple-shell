#include "link.h"

int main () 
{
    char cmd[100], command[100], parameters[20];
    char *envp[] = { (char *) "PATH=/bin", 0 };
    while (1) {
        type_proompt();
        read_comman ( command,parameters );
        if (fork() !=0 )
            wait(NULL);
        else {
            strcpy ( cmd, "/bin/" );
            strcat ( cmd, command );
            execve (cmd, parameters, envp );
        }
        if ( srcmp ( command , "exit" ) == 0)
            break ;
    }
    return 0;
}


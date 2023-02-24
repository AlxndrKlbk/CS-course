#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pipe(fd);
    if( fork() == 0 ){
        close(fd[0]);
        dup2( fd[1], 1 );
        close( fd[1] );
        execlp( "ls", "ls", "-lR", NULL);
        perror( "ls" );
        exit( 1 );
    }
    if( fork()==0 ){
        close( fd[1] );
        dup2( fd[0], 0);
        close( fd[0] );
        execlp( "grep", "grep", "^d", NULL );
        perror( "grep" );
        exit( 1) ;
    }
    close( fd[0] );
    close( fd[1] );
    wait( NULL );
    wait( NULL );
    return 0;
}

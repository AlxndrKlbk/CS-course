#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main( int argc, char **argv )
{
    DIR *dir;
    struct dirent *dent;
    const char *name = ".";

    if( argc > 1 )
        name =argv[1];

    dir = opendir( name );
    if( !dir ){
        perror( name);
        return 1;
    }
    while(( dent = readdir( dir )) != NULL) {
        printf( "%s\n", dent->d_name );
    }
    closedir( dir );
    return 0 ;
}


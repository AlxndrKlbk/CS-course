#include <stdio.h>
#include <locale.h>
#include <libintl.h>

#define _(STR) (STR)
#define N_(STR) gettext(STR)

#define LOCALEBASEDIR "."
#define TEXTDOMAIN "prog"

int main()
{
    setlocale( LC_CTYPE, "" );
    setlocale( LC_MESSAGES, "" );
    bindtextdomain( TEXTDOMAIN, LOCALEBASEDIR );
    textdomain(TEXTDOMAIN);

    printf( _( "Hello, world!\n" ) );
    printf( _( "Good bye, world!\n" ) );
    return 0;
}


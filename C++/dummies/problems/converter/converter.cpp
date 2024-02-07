#include <stdio.h>
#include <iostream>


const double CELS_TO_FAHRENHEIT_MUL = 1.8;
const double CELS_TO_FAHRENHEIT_SUMMAND = 32;

int main( int argc, char **argv)
{
    double celsius = std::stod( argv[ 1 ] );
    double fahrenheit = CELS_TO_FAHRENHEIT_MUL * celsius + CELS_TO_FAHRENHEIT_SUMMAND;
    printf( "initial temperature %1.2f°C\n", celsius );
    printf( "temperature at fahrenheit %1.2f°F\n", fahrenheit );
    return 0;
}

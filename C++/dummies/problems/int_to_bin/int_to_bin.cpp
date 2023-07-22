#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"

using std::vector;

void to_negative( vector< int >& bits)
{
    for( auto& bit: bits )
        bit = !bit;

    vector< int >::iterator iter = bits.end();
    --iter;
    while( true )
    {
        if( *iter == 0)
        {
            *iter = 1;
            break;
        }
        else
            *iter = 0;

        --iter;
    }
}

vector< int > int_to_binary( long n )
{
    long tmp = abs( n );
    vector< int > bin_pres;
    while( tmp != 0  || bin_pres.size() < 64)
    {
        bin_pres.push_back( tmp % 2 );
        tmp /= 2;
    }

    std::reverse( bin_pres.begin(), bin_pres.end() );

    if( n < 0)
        to_negative( bin_pres );

    return bin_pres;
}

int main(int argc, char *argv[])
{

    vector< int > res = int_to_binary( atol(argv[1]) );
    for( auto& bit : res)
        std::cout << bit;
    std::cout << std::endl;

    return 0;
}

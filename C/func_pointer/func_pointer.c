#include <stdio.h>

const double (*func_ptr)(const double *, int);

double dbl_sum( const double *a, int size )
{
    return size > 0 ?*a + dbl_sum( a+1, size-1 ): 0;
}

double dbl_min( const double *a, int size )
{
    double d;
    if( size == 1 )
        return *a;
    d = dbl_min( a+1, size-1 );
    return *a < d? *a : d;
}

double dbl_average( const double *a, int size )
{
    return dbl_sum( a, size ) / (double) size;
}

int main()
{
    func_ptr = &dbl_min;
    printf( "%u function on this address\n", (unsigned int)&func_ptr );
    return (int)&func_ptr;
}

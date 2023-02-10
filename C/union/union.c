#include <stdio.h>

union sample_union {
    int int_val;
    double double_val;
    unsigned char bytes[ sizeof(int)];
};

int main()
{
    int i;
    union sample_union un_inst;
    printf( "Please enter an integer: " );
    scanf( "%d", &un_inst.int_val );
    for( i=0; i < sizeof( int ); i++)
        printf( "byte #%d is %02x\n", i, un_inst.bytes[i]);

    return 1;
}

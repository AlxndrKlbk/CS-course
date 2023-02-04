#include <stdio.h>
#include <math.h>

int main()
{
    FILE *file_ptr;
    int angel;
    double rads, sin_val, cos_val;
    
    file_ptr  = fopen("sincos.txt", "w");
    if( !file_ptr){
        perror("sincos.txt");
        return 1;
    }
    

    fprintf(file_ptr,"%s %s %s\n", "angel", "sin", "cos");
    for (angel = 0; angel < 360; angel++){
        rads = (double)angel * M_PI  / 180.0;
        sin_val = sin( rads );
        cos_val = cos ( rads );
        fprintf(file_ptr,"%03d %7.5f %7.5f\n", angel, sin_val, cos_val);
    }
    fclose(file_ptr);
    return 0;
}



#include <iostream>
#include <bitset>

using namespace std;

int main( int argc, char **argv)
{
    int val = atoi ( argv[1] );
    int position = atoi (argv[2] );

    bitset< 16 > bits( val );
    cout << "bitmask of value: " << val << " is " << bits << endl;
    cout << "bit in position: " << position << " is " << ( val & ( 1 << position) >> position) << endl;
    return 0;
}

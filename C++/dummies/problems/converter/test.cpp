#include <stdio.h>
#include <cstdio>

//void put_in_massive( int ( &mas )[] )  //combiple on g++, raise error on clang++
template<std::size_t N> void put_in_massive( int ( &mas )[N] )
{
    mas[0] = 1;
    mas[1] = 2;
}

void put_in_int( int n )
{
    n = 2;
}

int main()
{
    int massive[2] {};
    int i = 1;

    put_in_massive( massive );  // compilling and work with g++, clang++ raise error
    put_in_int( i );

    printf( "i val = %d\n-------\n", i );

    for(int val : massive)
        printf( "%d\n", val );

    return 0;
}

// DisplayString - display an array of characters both
//                 using a pointer and an array index
//#include <cstdio>
//#include <cstdlib>
//#include <iostream>
//using namespace std;

//int main(int argc, char* argv[])
//{
//    // declare a string
//    const char* szString = "Randy";
//    cout << "The array is '" << szString << "'" << endl;

//    // display szString as an array
//    cout << "Display the string as an array: ";
//    for(int i = 0; i < 5; i++)
//    {
//        cout << szString[i];
//    }
//    cout << endl;

//    // now using typical pointer arithmetic
//    cout << "Display string using a pointer: ";
//    const char* pszString = szString;
//    while(*pszString)
//    {
//        cout << *pszString++;
//    }
//    cout << endl;

//    // wait until user is ready before terminating program
//    // to allow the user to see the program results
//    cout << "Press Enter to continue..." << endl;
//    cin.ignore(10, '\n');
//    cin.get();
//    return 0;
//}




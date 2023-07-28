#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


int main( int argc, char *argv[] )
{
    void print = []( string% str) {  cout << str << endl ;};
    string str = argv[1];
    print( str );
    return 0
}

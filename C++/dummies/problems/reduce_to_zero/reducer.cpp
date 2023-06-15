#include <iostream>

class Solution {
public:
    int numberOfSteps(int num) {

        int current_val = num;
        int counter = 0;

        while( current_val != 0 )
        {
            if( current_val == ( current_val >> 1 << 1 ) )  // у битового представления четного числа первый бит равен 0
                current_val = current_val >> 1;
            else
                current_val--;
            counter += 1;
        }

        return counter;
    }
};

int main( int argc, char **argv )
{
    int reducible = atoi( argv[1] );
    Solution solver = Solution();
    std::cout << "Steps for reduce: " << solver.numberOfSteps( reducible )
              << " for value: " << reducible << std::endl;
    return 0;
}

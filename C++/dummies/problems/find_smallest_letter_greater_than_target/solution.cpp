#include <cassert>
#include <vector>

class Solution {
public:
    char nextGreatestLetter(std::vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;

        int res = 0;
        while (left <= right) {
            auto const&& mid = (right + left) / 2;
            if (letters[mid] == target) {
                left = mid + 1;
            } else if (letters[mid] > target) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return letters[res];
    }
};


int main (int argc, char** argv) {

    std::vector<char> letters = {'c','f', 'j'};

    Solution solution;
    auto&& res = solution.nextGreatestLetter(letters, 'c');
    assert(res == 'f');

    res = solution.nextGreatestLetter(letters, 'd');
    assert(res == 'f');

    res = solution.nextGreatestLetter(letters, 'i');
    assert(res == 'j');

    res = solution.nextGreatestLetter(letters, 'z');
    assert(res == 'c');

    return 0;
}

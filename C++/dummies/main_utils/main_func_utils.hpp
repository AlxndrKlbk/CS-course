#include <stdlib.h>

#include <vector>


// is that variable-template?

template<typename T>
struct is_vector
{
    static bool const value = false;
};

template<typename T>
struct is_vector<std::vector<T> > {
    static bool const value = true;
};


/**
 * @brief comand_line_args_to_vector - processing char** with comand line args and fill into given buffer
 *                                     check that given buffer is vector containing inregral types
 * @param start - start position over char**
 * @param stop - end position over char**
 * @param buff - vector<T> buffer
 * @param argv - char** with comand line args
 */
template<typename T>
std::enable_if_t<std::is_integral<typename T::value_type>::value &&
                 is_vector<T>::value, void>
comand_line_args_to_vector(int start, int stop, T& buff, char** argv)
{
    char* inputChar = nullptr;
    for (int i = start; i < stop; i++) {
        inputChar = argv[i];
        if constexpr (std::is_same<typename T::value_type, double>::value){
            buff.emplace_back(atof(inputChar));
        } else if constexpr (std::is_same<typename T::value_type, int>::value){
            buff.emplace_back(atoi(inputChar));
        }
    }
}

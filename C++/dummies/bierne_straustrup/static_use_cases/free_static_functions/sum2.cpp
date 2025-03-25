
// after add static become internal linkage visible,
// by devault extern linkage for functions
static int sum(int a, int b)
{
    int some_coefficient = 1;
    return a + b + some_coefficient;
}

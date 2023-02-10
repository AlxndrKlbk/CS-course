#include <stdlib.h>


struct dbl_list {
    double data;
    struct dbl_list *prev, *next;
};

int main()
{
    struct dbl_list *first = NULL, *last= NULL;
    struct dbl_list *current = NULL, *tmp;

    tmp = malloc(sizeof(struct dbl_list));
    return 1;
}

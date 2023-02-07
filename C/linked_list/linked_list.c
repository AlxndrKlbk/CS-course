
struct item{
    int data;
    struct item *next;
}

struct item *int_array_to_list(const int *arr, int len)
{
    struct item *first = NULL, *last = NULL, *tmp;
    int i;
    for(i=0; i<len; i++){
        tmp = malloc(sizeof(struct item));
        tmp->data = arr[i];
        tmp->next = NULL;
        if(last){
            last->next = tmp;
            last = last->next;
        } else {
            first = last = tmp;
        }
    }
    return first;
}

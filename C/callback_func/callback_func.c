#include <stdio.h>

struct min_max_count {
    int count, min, max;
};

void int_callback_min_max_count( int data, void *userdata)
{
    struct min_max_count *mmc = userdata;
    if( mmc->count == 0 ){
        mmc->min = mmc->max = data;
    } else {
        if( mmc->min > data)
            mmc->min = data;
        if( mmc->max < data)
            mmc->max = data;
    }
    mmc->count++;
}

void callback_function( int num, void *userdata );

void int_bin_tree_traverse( struct node *r,
                            void (*callback)(int, void*),
                            void *userdata )
{
    if( !r )
        return;
    int_bin_tree_traverse( r->left, callback, userdata);
    (*callback)( r->val, userdata );
    int_bin_tree_traverse( r->right, callback, userdata);
}

void int_callback_print( int data void *userdata)
{
    printf( "%d ", data );
}

void int_callback_sum( int data, void *userdata)
{
    int *sum = userdata;
    *sum += data;
}

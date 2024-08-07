#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>

#include "sockets.hpp"

FdHandler::~FdHandler()
{
    if( own_fd)
        close( fd );
}

EventSelector::~EventSelector()
{
    if( fd_array )
        delete[] fd_array;
}

void EventSelector::Add( FdHandler *h)
{
    int i;
    int fd = h->GetFd();
    if( !fd_array )
    {
        fd_array_len = fd > 15 ? fd + 1: 16;
        fd_array = new FdHandler *[fd_array_len];
        for( i = 0; i < fd_array_len; i++ )
            fd_array[i] = 0;
        max_fd = -1;
    }
    
    if( fd_array_len <= fd )
    {
        FdHandler **tmp = new FdHandler *[ fd + 1 ];
        for( i = 0; i <= fd; i++ )
            tmp[i] = i < fd_array_len ? fd_array[i] : 0;
        fd_array_len = fd + 1;
        delete[] fd_array;
        fd_array = tmp;
    }
    if( fd > max_fd )
        max_fd = fd;
    fd_array[fd] = h;
}

bool EventSelector::Remove( FdHandler *h )
{
    int fd = h->GetFd();
    if( fd >= fd_array_len || fd_array[fd] != h )
        return false;
    fd_array[fd] = 0;
    if( fd == max_fd )
    {
        while( max_fd >= 0 && !fd_array[max_fd] )
            max_fd--;
    }
    return true;
}

void EventSelector::Run()
{
    quit_flag = false;
    do
    {
        int i ;
        fd_set rds, wrs;
        FD_ZERO(&rds);
        FD_ZERO(&wrs);
        for( i = 0; i <= max_fd; i++)
        {
            if( fd_array[i] )
            {
                if( fd_array[i]->WantRead() )
                    FD_SET( i, &rds );
                if (fd_array[i]->WantWrite() )
                    FD_SET( i, &wrs );
            }
        }

        int res = select( max_fd+1, &rds, &wrs, 0, 0 );
        if( res < 0 )
        {
            if( errno == EINTR )
                continue;
            else
                break;
        }
        
        if( res > 0 )
        {
            for( i = 0; i <= max_fd; i++)
            {
                if( !fd_array[i])
                    continue;
                bool r = FD_ISSET( i, &rds );
                bool w = FD_ISSET( i, &wrs );
                if( r || w )
                    fd_array[i]->Handle(r, w);
            }
        }
    } while( !quit_flag );
}



class FdHandler
{
    int fd;
    bool own_fd;

public:
    FdHandler( int a_fd, bool own = true): fd( a_fd ), own_fd( own ) 
    {}
    
    virtual ~FdHandler();
    virtual void Handle( bool r, bool w) = 0;
    int GetFd() const { return fd; }
    virtual bool WantRead() const { return true; }
    virtual bool WantWrite() const { return true;  }
};

class EventSelector
{
    FdHandler **fd_array;
    int fd_array_len;
    int max_fd;
    bool quit_flag;

public:
    EventSelector(): fd_array( 0 ), quit_flag( false ) {}
    ~EventSelector();
    void Add( FdHandler *h );
    bool Remove( FdHandler *h );
    void BreakLoop() { quit_flag = true; }
    void Run();
};

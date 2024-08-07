#include "sockets.hpp"

enum {
    max_line_length = 1023,
    glen_for_listen = 16
};

class ChatSession;

class ChatServer : public FdHandler
{
    EventSelector *the_selector;
    struct item 
    {
        ChatSession *s;
        item *next;
    };

    item *first;
    ChatServer( EventSelector *sel, int fd );
public:
    ~ChatServer();
    static ChatServer* Start( EventSelector *sel, int port );
    void RemoveSession( ChatSession *s );
    void SendAll( const char *msg, ChatSession *except = 0 );
private:
    virtual void Handle( bool r, bool w);
};


class ChatSession : FdHandler 
{
    friend class ChatServer;
    char buffer[max_line_length+1];
    int buf_used;
    bool ignoring;
    char *name;
    ChatServer *the_master;

    ChatSession( ChatServer *a_master, int fd );
    ~ChatSession();
    void Send( const char *msg );
    virtual void Handle( bool r, bool w);
    void ReadAndIgnore();
    void ReadAndCheck();
    void CheckLines();
    void ProcessLine( const char *str );

}; 

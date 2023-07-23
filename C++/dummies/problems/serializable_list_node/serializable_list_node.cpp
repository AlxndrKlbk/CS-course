#include "serializable_list_node.hpp"

List::List( int node_count, char* data_arr[] )
{
    ListNode* prev = nullptr;
    ListNode* current = nullptr;

    for (int i = 1; i < node_count; ++i) {
        string data( data_arr[i]);

        current = new ListNode();
        if( prev != nullptr )
        {
            prev->next = current;
            current->prev = prev;
        }

        current->data = data;
        if( head == nullptr)
            head = current;
        prev = current;
        count += 1;
    }
    tail = current;
    AddRandomLinks();
}

void List::AddRandomLinks()
{
    ListNode* cur = head;
    int counter = 0;
    OrderAddrMap links_map;
    for( ; counter < count ; counter++ )
    {
        links_map[ counter ] = cur;
        cur = cur->next;
    }

    counter = 0;
    cur = head;
    srand( (long)&head );
    for( ; counter < count ; counter++ )
    {
        int num = UNDEFINED_RAND + rand() % (count - UNDEFINED_RAND);
        if( num == UNDEFINED_RAND )
            continue;
        cur->rand = links_map.find( num )->second;
        cur = cur->next;
    }
}

void List::Serialize( FILE* file )
{
    if( file == NULL )
        return;

    ListNode* cur = head;
    SerializableConnections links_map = GetConnections();

    // writing links
    int map_size = links_map.size();
    fwrite( &map_size, sizeof( map_size ), 1, file );
    for( auto it = links_map.begin(); it != links_map.end(); ++it)
    {
        fwrite( &it->first, sizeof(it->first), 1, file );
        fwrite( &it->second, sizeof(it->second), 1, file );
    }

    // writing nodes
    fwrite( &count, sizeof(count), 1, file );
    while( cur )
    {
        fwrite( &(cur->data), sizeof(cur->data), 1, file);
        cur = cur->next;
    }
    fclose( file );
}

void List::Deserialize( FILE* file )
{
    ListNode* cur = nullptr;
    SerializableConnections serializable;
    int map_size, key, value;

    // load random links info
    fread( (char *)&map_size, sizeof(map_size), 1, file );
    for(int i = 0; i < map_size; i++)
    {
        fread( (char *)&key, sizeof(key), 1, file );
        fread( (char *)&value, sizeof(value), 1, file );
        serializable[key] = value;
    }
    OrderAddrMap links_map = LoadNodes( file );
    fclose( file );
    RestoreRandom( links_map, serializable );
}

OrderAddrMap List::LoadNodes( FILE* file  )
{
    ListNode* cur = nullptr;
    int node_count, counter = 0;
    fread( (char *)&node_count, sizeof(node_count), 1, file );

    ListNode* prev = nullptr;
    OrderAddrMap links_map;
    for( ; counter < node_count; counter++ )
    {
        cur = new ListNode();
        links_map[ counter ] = cur;
        cur->prev = prev;
        fread( (char *)&cur->data, sizeof(cur->data), 1, file);
        if( this->head == nullptr )
            this->head = cur;
        if( prev != nullptr )
            prev->next = cur;
        prev = cur;
    }
    this->count = counter;
    this->tail = cur;
    return links_map;
}

void List::RestoreRandom( OrderAddrMap& links_map, SerializableConnections& rand_connectins)
{
    ListNode* cur = nullptr;
    for( auto it = links_map.begin(); it != links_map.end(); ++it)
    {
        cur = it->second;
        int rand_link_order = rand_connectins.find( it->first )->second;

        if( rand_link_order == UNDEFINED_RAND)
        {
            cur->rand = nullptr;
            continue;
        }
        cur->rand = links_map.find(rand_link_order)->second;
    }
}

SerializableConnections List::GetConnections()
{
    ListNode* cur = head;
    AddrOrderMap in_memory;
    SerializableConnections serializable;
    int counter = 0;
    in_memory[ nullptr ] = UNDEFINED_RAND;
    while( cur )
    {
        in_memory[ cur ] = counter;
        cur = cur->next;
        counter++;
    }

    cur = head;
    counter = 0;
    while( cur )
    {
        serializable[counter] = in_memory.find( cur->rand )->second;
        cur = cur->next;
        counter++;
    }
    return serializable;
}

void List::Show()
{
    ListNode* cur = head;
    while( cur )
    {
        cout << "data: " << cur->data << " /rand: ";
        if (cur->rand == nullptr)
            cout << "nullptr" << endl;
        else
            cout << cur->rand->data << endl;
        cur = cur->next;
    }
    cout << string( 30 , '_') << endl;
}

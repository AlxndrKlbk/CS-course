#include <string>
#include <unordered_map>
#include <utility>
#include <iostream>

using std::unordered_map, std::string, std::cout, std::endl;


struct ListNode
{
    ListNode* prev= nullptr;
    ListNode* next = nullptr;
    ListNode* rand = nullptr;
    string data = string();
};

typedef  unordered_map< ListNode* , int > AddrOrderMap;
typedef  unordered_map< int, ListNode* > OrderAddrMap;
typedef unordered_map< int , int > SerializableConnections;
const int UNDEFINED_RAND = -1;

class List
{
public:
    List(){};
    List( int node_count, char* data_arr[] );
    void Serialize( FILE* file );
    void Deserialize( FILE* file );
    void Show();


private:
    SerializableConnections GetConnections();
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int count = 0;

    /**
     * @brief init on heap nodes and load data from binary storrage
     * @param file - binary storrage
     * @return OrderAddrMap
     */
    OrderAddrMap LoadNodes( FILE* file  );

    /**
     * @brief restore random connections between nodes
     * @param links_map where node's order is key, memory addres a value
     * @param rand_connectins where node's irder is key, random linked node a value
     */
    void RestoreRandom( OrderAddrMap& links_map, SerializableConnections& rand_connectins);
    void AddRandomLinks();
};

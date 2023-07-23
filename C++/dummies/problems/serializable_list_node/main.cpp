#include "serializable_list_node.hpp"

FILE* open_file(char file_name[], char mode[] )
{
    FILE* file;
    file = fopen( file_name, mode );
    if ( file == NULL)
    {
        printf( "Cannot open file.\n" );
        exit(1);
    }
    return file;
}

int main(int argc, char *argv[])
{
    List list( argc, argv );
    char file_name[] = "list.bin";
    char write_mode[] = "w+b";
    char read_mode[] = "r+b";

    FILE* file = open_file( file_name, write_mode );
    cout << "initial list:" << endl;
    list.Show();
    list.Serialize( file );

    List deserialized_list = List();
    file = open_file( file_name, read_mode);
    deserialized_list.Deserialize( file );
    cout << "deserialized list:" << endl;
    deserialized_list.Show();

    return 0;
}

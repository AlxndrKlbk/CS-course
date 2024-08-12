#include <string>
#include <iostream>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>

/**
 * @brief lock
 * @param path - string to location to create blocking file
 * @return true if block file created
 */
bool lock(const std::string& path) {

    // O_EXCL used inly with O_CREAT and return error if file exist
    int f = open(path.c_str(), O_RDWR | O_CREAT | O_EXCL, 0666);
    if(f > 0) {
        close(f);
        return true;
    } else {
        return false;
    }
}

int main(int argc, char** argv) {
    const std::string path = "/tmp/test_block.lock";
    assert(lock(path));
    assert(lock(path) == false);

    auto isDeleted = unlink(path.c_str());
    if (isDeleted) {
        std::cout << "Blobking file wasnt deleted: \'" + path + "\'";
        return 1;
    }

    return 0;
}

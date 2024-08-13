#include <cstring>

#include <sys/types.h>

int main(int argc, char** argv) {
    char buff[4] = {0x00, 0x00, 0x00, static_cast<char>(0x80)};
    int littleEndianInt = (buff[3] << 24) | ((buff[2] & 0xFF) << 16) | ((buff[1] & 0xFF) << 8) | (buff[0] & 0xFF);
    int bigEndianInt = (buff[0] << 24) | ((buff[1] & 0xFF) << 16) | ((buff[2] & 0xFF) << 8) | (buff[3] & 0xFF);

    uint littleEndianUInt = (buff[3] << 24) | ((buff[2] & 0xFF) << 16) | ((buff[1] & 0xFF) << 8) | (buff[0] & 0xFF);
    uint bigEndianUInt = (buff[0] << 24) | ((buff[1] & 0xFF) << 16) | ((buff[2] & 0xFF) << 8) | (buff[3] & 0xFF);

    float littleEndianFloat = (buff[3] << 24) | (buff[2] << 16) | (buff[1] << 8) | buff[0];
    float bigEndianFloat = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | buff[3];
}

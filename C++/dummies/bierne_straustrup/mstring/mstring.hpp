#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>

class MString
{
public:
    MString();

    MString(const char* cstr);

    MString(const MString&);

    MString(MString&&);

    MString& operator=(const MString&);

    MString& operator=(MString&&);

    MString& operator+(const char);

    std::ostream& write(std::ostream& os) const;

    ~MString();

    std::vector<MString> split(const char sep = ' ') const;


private:
    void reallocate_buffer(const char* src);

private:
    char* mCstrPtr = nullptr;
    size_t mBuffSize = 0;
};

std::ostream& operator<<(std::ostream& os, const MString& str)
{
    str.write(os);
    return os;
}

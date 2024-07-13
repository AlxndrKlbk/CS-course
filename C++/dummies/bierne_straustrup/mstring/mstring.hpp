#pragma once

#include <stdio.h>


class MString
{
public:
    MString();

    MString(const char* cstr);

    MString(const MString&);

    MString& operator=(const MString&);

    ~MString();

private:
    void reallocate_buffer(const char* src);

private:
    char* mCstrPtr = nullptr;
    size_t mBuffSize = 0;
};


#include "mstring.hpp"

#include <algorithm>
#include <iostream>
#include <cstring>


MString::MString()
{
    std::cout << "MString()";
}

MString::MString(const char* cstr)
{
    std::cout << "MString(const char* cstr) for: " << cstr << std::endl;

    reallocate_buffer(cstr);
    strlcpy(mCstrPtr, cstr, mBuffSize);
}

MString::MString(const MString& rhs)
{
    std::cout << "MString(const MString& rhs)" << std::endl;

    reallocate_buffer(rhs.mCstrPtr);
    strlcpy(mCstrPtr, rhs.mCstrPtr, mBuffSize);
}

MString::MString(MString&& rhs)
{
    std::cout << "MString::MString(MString&& rhs) for: " << rhs.mCstrPtr << std::endl;

    std::swap(mCstrPtr, rhs.mCstrPtr);
    std::swap(mBuffSize, rhs.mBuffSize);
}

MString& MString::operator=(const MString& src)
{
    std::cout << "MString::operator=(const MString& src) for: " << src.mCstrPtr << std::endl;

    if (this == &src) {
        return *this;
    }
    reallocate_buffer(src.mCstrPtr);
    strlcpy(mCstrPtr, src.mCstrPtr, mBuffSize);
    return *this;
}

MString& MString::operator=(MString&& rhs)
{
    std::cout << "MString::operator=(MString&& rhs) for: " << rhs.mCstrPtr << std::endl;

    std::swap(mCstrPtr, rhs.mCstrPtr);
    std::swap(mBuffSize, rhs.mBuffSize);
    return *this;
}

MString::~MString()
{
    std::cout << "~MString() " << "for string: " << mCstrPtr << std::endl;
    delete[] mCstrPtr;
}


void MString::reallocate_buffer(const char* src)
{
    std::cout << "MString::reallocate_buffer(const char* src)" << std::endl;
    auto str_size = strlen(src) + 1;
    auto actual_size = mCstrPtr == nullptr ? 0: strlen(mCstrPtr) + 1;
    if (actual_size < str_size) {
        delete[] mCstrPtr;
        mBuffSize = str_size;
        mCstrPtr = new char[mBuffSize];
        std::cout << "buffer size increased" << std::endl;
    }
}

int main()
{
    MString str;    // default constructor
    MString str2{"some_str"};
    MString str3{"some_str_with_bigger_buff_size"};
    str = str2;
    str = str3;
    str = str2;
    str = MString{"rvalue_MString"};
}

#include "mstring.hpp"

#include <algorithm>
#include <iostream>
#include <cstring>
#include <assert.h>


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
    std::cout << "MString(const MString& rhs)" << rhs.mCstrPtr << std::endl;

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

MString& MString::operator+(const char chr)
{
    if (!mCstrPtr) {reallocate_buffer(""); };   // allocate memory if it is not cuptured before
    auto actualSize = mCstrPtr == nullptr ? 0: strlen(mCstrPtr) + 1;

    if (actualSize + 1 <= mBuffSize) {
        int newSize = mBuffSize * 2;
        char * tmp = new char[newSize];
        strlcpy(tmp, mCstrPtr, mBuffSize);
        std::swap(mCstrPtr, tmp);
        mBuffSize = newSize;
        delete[] tmp;
    }

    char * cursor = mCstrPtr + actualSize;
    *cursor = chr;
    *(cursor++) = '\0';
    return *this;
}

std::ostream& MString::write(std::ostream& os) const
{
    auto size = strlen(mCstrPtr);
    os.write(mCstrPtr, size);
    return os;
}

MString::~MString()
{
    if (mCstrPtr != nullptr){
        std::cout << "~MString() " << "for string: " << mCstrPtr << std::endl;
        delete[] mCstrPtr;
    }
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

std::vector<MString> MString::split(const char sep) const
{
    std::vector<MString> result;

    if (!mBuffSize) {
        return result;
    }

    const char * cursor = mCstrPtr;

    int size = 128;
    char buff[size];

    while(*cursor == sep) {
        cursor++;
    }
    const char * tmp = cursor;

    auto cstrSlice = [&]() {
        int i = 0;
        for(; i < size && tmp != cursor; i++)
        {
            buff[i] = *tmp;
            tmp++;
        }
        buff[i] = '\0';

        while(*cursor == sep) {
            cursor++;
        }
        tmp = cursor;
        MString singleWord{buff};
        result.emplace_back(std::move(singleWord));
    };

    while( *tmp != '\0')
    {   if (*cursor == sep) {
            cstrSlice();
        } else if (*cursor == '\0' && *tmp != '\0') {
            cstrSlice();
        }
        cursor++;
    }

    return result;
}


void test_c_cplit();

int main()
{
    MString str;    // default constructor
    MString str2{"some_str"};
    MString str3{"some_str_with_bigger_buff_size"};
    str = str2;
    str = str3;
    str = str2;
    str = MString{"rvalue_MString"};
    str = "char_equal";

    MString str4{str};

    std::cout << std::endl << "Start split test" << std::endl;
    MString toSplitStr{"  string    for   test  split"};
    assert(toSplitStr.split().size() == 4);

    toSplitStr = "    test2   ";
    assert(toSplitStr.split().size() == 1);

    toSplitStr = "test3   t3";
    auto res = toSplitStr.split();
    assert(res.size() == 2);

    for (auto const& str : res) {
        std::cout << str << std::endl;
    }

    toSplitStr = toSplitStr + 't';

    std::cout << std::endl << "c_split_test:" << std::endl;
    test_c_cplit();
}

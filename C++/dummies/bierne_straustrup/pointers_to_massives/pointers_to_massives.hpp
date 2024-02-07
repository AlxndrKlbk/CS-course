void implicitConversion();

void testByteDiff();

template<typename T>
int byte_diff(T* p, T* q)
{
    return reinterpret_cast<char *>(q) - reinterpret_cast<char *>(p);
}

/*  it is just test with allocator, list of problems:
    1) no defragmentation, should return smart pointers
    2) can stack buffer with usefull chunks if call Alloc(0) */

#include <iostream>

// 1 Mb
const int DEFAULT_CHUNK_SIZE = 1048576;

struct memControlBlock {
    int is_available;
    int size;
};

class SmallAllocator {
public:

    /**
     * @brief SmallAllocator - used to init memControlBlock
     */
    SmallAllocator() {
        auto* mcb = reinterpret_cast<memControlBlock *>(memStart);
        mcb->is_available = true;
        mcb->size = DEFAULT_CHUNK_SIZE - sizeof(memControlBlock);
    }

    void *Alloc(unsigned int size) {
        unsigned int realBlockSize = size + sizeof(memControlBlock);
        void * memoryLocation = nullptr;

        void * currentLocation = static_cast<void *>(memStart);

        while (currentLocation < memEnd) {

            auto* mcb = static_cast<memControlBlock *>(currentLocation);

            if (mcb->is_available) {
                if (mcb->size >= size) {
                    mcb->is_available = false;
                    mcb->size = realBlockSize;

                    memoryLocation = static_cast<char*>(currentLocation) + sizeof(memControlBlock);

                    break;
                }
            } else if (!mcb->is_available && !mcb->size) {
                mcb->is_available = false;
                mcb->size = realBlockSize;
                memoryLocation = static_cast<char*>(currentLocation) + sizeof(memControlBlock);
                break;
            }

            currentLocation = static_cast<char *>(currentLocation) + mcb->size;
        }
        return memoryLocation;
    };

    void *ReAlloc(void* pointer, unsigned int size) {
        void * memoryLocation = nullptr;
        if (size + sizeof(memControlBlock) < (static_cast<memControlBlock *>(pointer) - 1)->size) {
            memoryLocation = pointer;
            return memoryLocation;
        }

        memoryLocation = Alloc(size);
        if (!memoryLocation) {          // nullptr - cant allocate expected place of memory
            return memoryLocation;
        }

        // memory allocated, copy data to new place
        if (pointer != nullptr) {
            for (int i = 0; i < size; i++) {
                *(static_cast<char* >(memoryLocation) + i) = *(static_cast<char*>(pointer) + i);
            }
        }

        return memoryLocation;
    };

    void Free(void * pointer) {
        auto *mcb = static_cast<memControlBlock *>(pointer) - sizeof(memControlBlock);
        mcb->is_available = 1;
        return;
    };

private:
    char mMemory[DEFAULT_CHUNK_SIZE];
    void* memStart = mMemory;
    void* memEnd = static_cast<char*>(memStart) + sizeof(mMemory);
};



int main(int argc, char** argv) {

    SmallAllocator A1;
    int * A1_P1 = (int *) A1.Alloc(sizeof(int));
    A1_P1 = (int *) A1.ReAlloc(A1_P1, 2 * sizeof(int));
    A1.Free(A1_P1);
    SmallAllocator A2;
    int * A2_P1 = (int *) A2.Alloc(10 * sizeof(int));
    for(unsigned int i = 0; i < 10; i++){
        A2_P1[i] = i;
    }
    for(unsigned int i = 0; i < 10; i++) {
        if(A2_P1[i] != i) std::cout << "ERROR 1" << std::endl;
    }
    int * A2_P2 = (int *) A2.Alloc(10 * sizeof(int));
    for(unsigned int i = 0; i < 10; i++) {
        A2_P2[i] = -1;
    }
    for(unsigned int i = 0; i < 10; i++) if(A2_P1[i] != i) std::cout << "ERROR 2" << std::endl;
    for(unsigned int i = 0; i < 10; i++) if(A2_P2[i] != -1) std::cout << "ERROR 3" << std::endl;
    A2_P1 = (int *) A2.ReAlloc(A2_P1, 20 * sizeof(int));
    for(unsigned int i = 10; i < 20; i++) A2_P1[i] = i;
    for(unsigned int i = 0; i < 20; i++) if(A2_P1[i] != i) std::cout << "ERROR 4" << std::endl;
    for(unsigned int i = 0; i < 10; i++) if(A2_P2[i] != -1) std::cout << "ERROR 5" << std::endl;
    A2_P1 = (int *) A2.ReAlloc(A2_P1, 5 * sizeof(int));
    for(unsigned int i = 0; i < 5; i++) if(A2_P1[i] != i) std::cout << "ERROR 6" << std::endl;
    for(unsigned int i = 0; i < 10; i++) if(A2_P2[i] != -1) std::cout << "ERROR 7" << std::endl;
    A2.Free(A2_P1);
    A2.Free(A2_P2);

    return 0;
}

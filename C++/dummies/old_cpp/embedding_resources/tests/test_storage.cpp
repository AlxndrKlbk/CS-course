#include "resource_storage.h"

#include <iostream>
#include <array>

int main()
{
    auto storage = ResourceStorage::ResourceStorage::get_instance();

    std::array<const char*, 1> resource_names {{
        ResourceStorage::KnownResources::CARTOON_WOLF
    }};

    for (auto const& resource: resource_names) {
        auto optFile = storage->get_file_ptr(resource);

        if (!optFile) {
            std::cerr << resource << " file not found in storage" << std::endl;
            return 1;
        }

        std::string data(optFile->mStart);
        std::cout << data << std::endl;
    }

    return 0;
}

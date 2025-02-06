#pragma once

#include <string>
#include <map>
#include <vector>
#include <memory>
#include <optional>

namespace ResourceStorage
{

/**
 *  KnownResources is namespace
 *  for embedded file's identifiers in libresource
 */
namespace KnownResources {

inline constexpr char const *CARTOON_WOLF = "there_once_was_a_dog.txt";

}

struct FilePtr
{
    FilePtr(char *_start, char *_end) :
        mStart(_start),
        mEnd(_end)
    {};

    const char* const mStart;

    const char* const mEnd;
};

class ResourceStorage
{
public:

    static std::shared_ptr<ResourceStorage> get_instance();

    std::vector<std::string> get_file_names();

    std::optional<FilePtr> get_file_ptr(const std::string & file_name);

private:
    std::map<std::string, FilePtr> file_pointers;

    void set_file_pointers();

    ResourceStorage();
    ResourceStorage(const ResourceStorage&rhv) = delete;
    ResourceStorage(ResourceStorage &&rhv) = delete;
    ResourceStorage& operator =(ResourceStorage &rhv) = delete;
};

}   // ~namespace ResourceStorage

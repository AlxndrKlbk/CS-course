#include <iostream>
#include <fstream>
#include <vector>
#include <optional>

#include <assert.h>

template <typename T>
static int stairs(std::vector<T> nums, int A)
{
    int answer = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < i + A; ++j)
        {
            auto const& val = nums[j];
            if (val != j - i + 1)
            {
                break;
            } else if (j - i + 1 == A)
            {
                answer++;
            }
        }
    }

    return answer;
}

void pre_test() {
    int A_val = 3;
    std::vector<int> data = {0, 1, 2, 3, 4, 5, 2, 3, 1, 2, 3, 9};

    int res = stairs(data, A_val);
    assert(res == 2);

    data = {1, 2, 4, 5, 0, 0, 1, 2, 3, 1, 2, 3};
    res = stairs(data, A_val);
    assert(res == 2);

    data = {};
    res = stairs(data, A_val);
    assert(res == 0);

    data = {0, 0, 0, 1, 2, 4};
    res = stairs(data, A_val);
    assert(res == 0);

    data = {0, 0, 0, 1, 2, 3};
    res = stairs(data, A_val);
    assert(res == 1);
}


template<typename V>
struct TaskData {

    TaskData<V>(V&& data, int a): data{std::forward<V>(data)}, A_val(a) {}

    V data;
    int A_val;
};

template<typename ValueType>
std::optional<TaskData<std::vector<ValueType>>> load_from_file(const char* const filePath)
{
    std::ifstream file;
    file.open(filePath, std::ios::in);

    if (!file.is_open()) {
        std::cerr << "Error opening the file: " << filePath << std::endl;
        return std::nullopt;
    }

    std::string line;
    const std::string delimiter = " ";
    int readedVal = 0;

    // read size of array
    getline(file, line);
    auto pos_end = line.find(delimiter, 0);
    uint arrSize = atoi(line.substr(0, pos_end).c_str());
    std::vector<int> buff(arrSize);

    // read max value
    getline(file, line);
    pos_end = line.find(delimiter, 0);
    auto A_val = atoi(line.substr(0, pos_end).c_str());

    // fill array
    int counter = 0;
    while(getline(file, line)) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        while ((pos_end = line.find(delimiter, pos_start)) != std::string::npos) {
            readedVal = atoi(line.substr(pos_start, pos_end - pos_start).c_str());
            pos_start = pos_end + delim_len;
            buff[counter++] = std::move(readedVal);
        }
    }

    return TaskData<decltype(buff)>(std::move(buff), A_val);
}

int main(int argc, char** argv) {

    pre_test();

    for (int i = 1; i < argc; i++) {
        auto taskData = load_from_file<int>(argv[i]);
        if (!taskData) {
            return 1;
        }

        std::cout << stairs(taskData->data, taskData->A_val) << std::endl;
    }

    return 0;
}

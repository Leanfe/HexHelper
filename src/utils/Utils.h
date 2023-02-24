//
// Created by lkapi on 24.02.2023.
//

#ifndef HEXUTILS_UTILS_H
#define HEXUTILS_UTILS_H

#include <fstream>
#include <iostream>

using namespace std;

namespace FileUtils {

    class Utils {
    public:
        static void write_bytes_to_file(const string& filename, const char* data, size_t size);
    };

} // UTIL

#endif //HEXUTILS_UTILS_H

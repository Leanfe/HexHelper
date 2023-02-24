//
// Created by lkapi on 24.02.2023.
//

#include "Utils.h"

namespace FileUtils {
    void Utils::write_bytes_to_file(const string &filename, const char *data, size_t size) {
        std::ofstream outfile(filename, std::ios::out | std::ios::binary);
        if (!outfile.is_open()) {
            std::cerr << "Error: Could not open file " << filename << " for writing\n";
            return;
        }

        outfile.write(data, size);
        outfile.close();
    }
} // UTIL
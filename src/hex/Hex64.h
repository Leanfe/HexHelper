//
// Created by lkapi on 19.02.2023.
//

#pragma once

#ifndef HEXUTILS_HEX64_H
#define HEXUTILS_HEX64_H

#include <sstream>
#include <string>

using namespace std;

namespace Utils {

    class Hex64 {
    public:
        /**
         * Function to convert a string to hex64.
         * @param input string
         * @return hex.
         */
        static uint64_t stringToHex64(const std::string& input) {
            std::stringstream ss;
            for (char c : input) {
                ss << std::hex << static_cast<int>(c);
            }
            uint64_t hex_num;
            ss >> hex_num;
            return hex_num;
        }

        /**
         * Function to convert a hex64 to a string.
         * @param hex_num hex.
         * @return string.
         */
        static std::string hex64ToString(uint64_t hex_num) {
            std::stringstream ss;
            ss << std::hex << hex_num;
            std::string hex_str = ss.str();
            std::string result;
            for (size_t i = 0; i < hex_str.length(); i += 2) {
                std::string byte_str = hex_str.substr(i, 2);
                char byte = static_cast<char>(std::stoi(byte_str, nullptr, 16));
                result.push_back(byte);
            }
            return result;
        }
    };

} // Utils

#endif //HEXUTILS_HEX64_H

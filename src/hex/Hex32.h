//
// Created by lkapi on 19.02.2023.
//

#pragma once

#ifndef HEXUTILS_HEX32_H
#define HEXUTILS_HEX32_H

#include <sstream>
#include <string>

using namespace std;

namespace Utils {

    class Hex32 {
    public:
        /**
         * Function to convert a string to hex32.
         * @param hex_num hex string.
         * @return just string.
         */
        static string hex32ToString(uint32_t hex_num) {
            stringstream ss;
            ss << hex << hex_num;
            string hex_str = ss.str();
            string result;
            for (size_t i = 0; i < hex_str.length(); i += 2) {
                string byte_str = hex_str.substr(i, 2);
                char byte = static_cast<char>(stoi(byte_str, nullptr, 16));
                result.push_back(byte);
            }
            return result;
        }

        /**
         * Function to convert a hex32 to a string.
         * @param input string.
         * @return hex32 string.
         */
        static uint32_t stringToHex32(const string &input) {
            stringstream ss;
            for (char c : input) {
                ss << hex << static_cast<int>(c);
            }
            uint32_t hex_num;
            ss >> hex_num;
            return hex_num;
        }
    };

} // Utils

#endif //HEXUTILS_HEX32_H

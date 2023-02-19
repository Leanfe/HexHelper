//
// Created by lkapi on 19.02.2023.
//

#pragma once

#ifndef HEXUTILS_UNICODE_H
#define HEXUTILS_UNICODE_H

#include <string>

using namespace std;

namespace Encoding {

    class UNICODE {
    public:
        static string unicodeToAscii(const string& unicode_str) {
            string ascii_str;
            string hex_str;
            for (int i = 0; i < unicode_str.length(); i++) {
                if (unicode_str[i] == '\\' && unicode_str[i+1] == 'u') {
                    // Extract the four-digit hexadecimal value
                    hex_str = unicode_str.substr(i+2, 4);
                    // Convert to integer and cast to char
                    int val = stoi(hex_str, nullptr, 16);
                    char c = static_cast<char>(val);
                    ascii_str += c;
                    // Skip over the remaining three characters
                    i += 5;
                } else {
                    // Not a Unicode character - copy verbatim
                    ascii_str += unicode_str[i];
                }
            }
            return ascii_str;
        }
    };

} // Encoding

#endif //HEXUTILS_UNICODE_H

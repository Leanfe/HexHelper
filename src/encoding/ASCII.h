//
// Created by lkapi on 19.02.2023.
//

#pragma once

#ifndef HEXUTILS_ASCII_H
#define HEXUTILS_ASCII_H

#include <string>

using namespace std;

namespace Encoding {
    
    class ASCII {
    public:
        static string asciiToUnicode(const string& ascii_str) {
            string unicode_str;
            for (char c : ascii_str) {
                // Convert each character to its Unicode value and append to result string
                unicode_str += "\\u" + to_string(static_cast<int>(c));
            }
            return unicode_str;
        }
    };

} // Encoding

#endif //HEXUTILS_ASCII_H

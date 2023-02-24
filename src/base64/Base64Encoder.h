//
// Created by lkapi on 24.02.2023.
//

#ifndef HEXUTILS_BASE64ENCODER_H
#define HEXUTILS_BASE64ENCODER_H

#include <string>

using namespace std;

namespace Base64 {

    class Base64Encoder {
    public:
        static string base64_encode(const string& data) {
            const string base64_chars =
                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                    "abcdefghijklmnopqrstuvwxyz"
                    "0123456789+/";

            string encoded;
            size_t i = 0;
            unsigned char char_array_3[3];
            unsigned char char_array_4[4];

            while (i < data.length()) {
                char_array_3[0] = data[i++];
                char_array_3[1] = data[i++];
                char_array_3[2] = data[i++];

                char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
                char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
                char_array_4[3] = char_array_3[2] & 0x3f;

                for (unsigned char i : char_array_4) {
                    encoded += base64_chars[i];
                }
            }

            switch (data.length() % 3) {
                case 1:
                    char_array_3[0] = data[i++];
                    char_array_3[1] = 0;
                    char_array_3[2] = 0;

                    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
                    char_array_4[2] = '=';
                    char_array_4[3] = '=';

                    for (unsigned char i : char_array_4) {
                        encoded += base64_chars[i];
                    }
                    break;
                case 2:
                    char_array_3[0] = data[i++];
                    char_array_3[1] = data[i++];
                    char_array_3[2] = 0;

                    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
                    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
                    char_array_4[3] = '=';

                    for (unsigned char i : char_array_4) {
                        encoded += base64_chars[i];
                    }
                    break;
                default:
                    break;
            }

            return encoded;
        }

    };

} // Base64

#endif //HEXUTILS_BASE64ENCODER_H

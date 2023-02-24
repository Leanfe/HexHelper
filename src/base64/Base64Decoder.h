//
// Created by lkapi on 24.02.2023.
//

#ifndef HEXUTILS_BASE64DECODER_H
#define HEXUTILS_BASE64DECODER_H

#include <string>
#include <string_view>
#include <vector>
#include <ranges>
#include <bit>
#include <stdexcept>

using namespace std;

namespace Base64 {

    class Base64Decoder {
    public:
        static vector<byte> base64_decode(string_view encoded) {

            const auto lookup = [](char c) -> byte {
                if (c >= 'A' && c <= 'Z') return static_cast<byte>(c - 'A');
                if (c >= 'a' && c <= 'z') return static_cast<byte>(c - 'a' + 26);
                if (c >= '0' && c <= '9') return static_cast<byte>(c - '0' + 52);
                if (c == '+') return static_cast<byte>(62);
                if (c == '/') return static_cast<byte>(63);
                throw invalid_argument("Invalid character in base64 string");
            };

            // Skip padding characters
            size_t padding = !encoded.empty() && encoded.back() == '=' ? 1 : 0;
            padding += encoded.size() > 1 && encoded[encoded.size()-2] == '=' ? 1 : 0;
            encoded.remove_suffix(padding);

            // Decode base64 string
            vector<byte> decoded(encoded.size() * 3 / 4);
            size_t j = 0;
            for (size_t i = 0; i < encoded.size(); i += 4) {
                uint32_t value =
                        (static_cast<uint32_t>(lookup(encoded[i]))   << 18) |
                        (static_cast<uint32_t>(lookup(encoded[i+1])) << 12) |
                        (static_cast<uint32_t>(lookup(encoded[i+2])) << 6)  |
                        static_cast<uint32_t>(lookup(encoded[i+3]));
                decoded[j++] = static_cast<byte>((value >> 16) & 0xff);
                decoded[j++] = static_cast<byte>((value >> 8) & 0xff);
                decoded[j++] = static_cast<byte>(value & 0xff);
            }

            // Remove trailing zeros
            while (!decoded.empty() && decoded.back() == byte{0}) {
                decoded.pop_back();
            }

            return decoded;
        }
    };

} // Base64

#endif //HEXUTILS_BASE64DECODER_H

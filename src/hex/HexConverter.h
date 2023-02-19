//
// Created by lkapi on 19.02.2023.
//

#pragma once

#ifndef HEXUTILS_HEXCONVERTER_H
#define HEXUTILS_HEXCONVERTER_H

#include <cstdint>

namespace Utils {

    class HexConverter {
    public:
        /**
         * Function to convert a hex32 to hex64.
         * @param hex_num hex32
         * @return hex64.
         */
        static uint64_t hex32ToHex64(uint32_t hex_num) {
            return static_cast<uint64_t>(hex_num);
        }

        /**
         * Function to convert a hex64 to hex32.
         * @param hex_num hex64.
         * @return hex32.
         */
        static uint32_t hex64ToHex32(uint64_t hex_num) {
            return static_cast<uint32_t>(hex_num & 0xFFFFFFFF);
        }
    };

} // Utils

#endif //HEXUTILS_HEXCONVERTER_H

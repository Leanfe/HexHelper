//
// Created by lkapi on 19.02.2023.
//

#pragma once

#ifndef HEXUTILS_DISPLAYMANAGER_H
#define HEXUTILS_DISPLAYMANAGER_H

#include <iostream>
#include <codecvt>
#include <locale>

#include "../hex/Hex32.h"
#include "../hex/Hex64.h"
#include "../hex/HexConverter.h"

#include "../encoding/ASCII.h"
#include "../encoding/UNICODE.h"

#include "../base64/Base64Encoder.h"
#include "../base64/Base64Decoder.h"

#include "../utils/Utils.h"
using namespace std;

using namespace Utils;
using namespace Encoding;
using namespace Base64;
using namespace FileUtils;

namespace UI {

    class HexOptionHandler {
    public:
        static void handleStringToHex32Conversion() {
            string input;
            cout << "Enter a string to convert to hex32: ";
            cin.ignore();
            getline(cin, input);

            uint32_t hex_num = Hex32::stringToHex32(input);
            cout << "Hex32 representation: 0x" << hex << uppercase << hex_num << endl;
        }

        static void handleStringToHex64Conversion() {
            string input;
            cout << "Enter a string to convert to hex64: ";
            cin.ignore();
            getline(cin, input);

            uint64_t hex_num = Hex64::stringToHex64(input);
            cout << "Hex64 representation: 0x" << hex << uppercase << hex_num << endl;
        }

        static void handleHex32ToHex64Conversion() {
            uint32_t hex_num;
            cout << "Enter a hex32 number to convert to hex64: ";
            cin >> hex >> hex_num;

            uint64_t hex64_num = HexConverter::hex32ToHex64(hex_num);
            cout << "Hex64 representation: 0x" << hex << uppercase << hex64_num << endl;
        }

        static void handleHex64ToHex32Conversion() {
            uint64_t hex_num;
            cout << "Enter a hex64 number to convert to hex32: ";
            cin >> hex >> hex_num;

            uint32_t hex32_num = HexConverter::hex64ToHex32(hex_num);
            cout << "Hex32 representation: 0x" << hex << uppercase << hex32_num << endl;
        }

    };

    class EncodingOptionHandler {
    public:
        static void handleAsciiToUnicodeConversion() {
            string ascii_string;
            cout << "Enter ASCII string: ";
            getline(cin, ascii_string);

            wstring_convert<codecvt_utf8_utf16<char16_t>, char16_t> convert;
            u16string utf16_string = convert.from_bytes(ascii_string);

            cout << "Unicode string: ";
            for (const auto& c : utf16_string) {
                cout << hex << static_cast<int>(c) << " ";
            }
            cout << endl;
        }

        static void handleUnicodeToAsciiConversion() {
            cout << "\nEnter a Unicode string to convert to ASCII: ";
            wstring unicode_str;
            getline(wcin, unicode_str);

            // Convert Unicode to ASCII
            string ascii_str;
            for (wchar_t c : unicode_str) {
                if (c <= 0x7f) {
                    ascii_str += static_cast<char>(c);
                }
                else {
                    cerr << "Error: Unicode string contains non-ASCII characters.\n";
                    return;
                }
            }

            cout << "\nConverted ASCII string: " << ascii_str << "\n";
        }


    };

    class Base64OptionHandler {

    public:
        static void handleBase64Encode() {
            string base64_string;
            cout << "Enter string: ";
            getline(cin, base64_string);

            cout << "Result : " << Base64Encoder::base64_encode(base64_string) << '\n';
        }

        static void handleBase64Decode() {
            string base64_string;
            string filename;

            cout << "Enter Base64 string: ";
            getline(cin, base64_string);

            cout << "Enter filename for save: ";
            getline(cin, filename);

            vector<byte> decoded_bytes = Base64Decoder::base64_decode(base64_string);

            FileUtils::Utils::write_bytes_to_file(filename, reinterpret_cast<const char*>(decoded_bytes.data()), decoded_bytes.size());

            cout << "Done! \n";
        }
    };

    class DisplayManager {
    public:

        static void displayMainMenu() {
            cout << "\033[1;36m";
            cout << "*********************************************\n";
            cout << "*          Welcome to Hex Converter          *\n";
            cout << "* This program can convert between hex and   *\n";
            cout << "* ASCII/Unicode. Choose an option from below. *\n";
            cout << "*********************************************\n";
            cout << "1. Handle ASCII/Unicode conversion\n";
            cout << "2. Handle hex encoding/decoding\n";
            cout << "3. Base64 Encoder & Decoder.\n";
            cout << "4. Exit\n";
            cout << "*********************************************\n";
            cout << "\033[0m";
        }

        static void handleBase64() {
            int choice;
            do {
                displayBase64Menu();
                cin >> choice;

                switch (choice) {
                    case 1:
                        Base64OptionHandler::handleBase64Encode();
                        break;
                    case 2:
                        Base64OptionHandler::handleBase64Decode();
                        break;
                    case 3:
                        cout << "\033[1;32m";
                        cout << "Returning to main menu...\n";
                        cout << "\033[0m";
                        break;
                    default:
                        cout << "\033[1;31m";
                        cout << "Invalid choice, please try again.\n";
                        cout << "\033[0m";
                        break;
                }
            } while (choice != 3);
        }

        static void handleAsciiUnicodeConversion() {
            int choice;
            do {
                displayAsciiUnicodeMenu();
                cin >> choice;

                switch (choice) {
                    case 1:
                        EncodingOptionHandler::handleAsciiToUnicodeConversion();
                        break;
                    case 2:
                        EncodingOptionHandler::handleUnicodeToAsciiConversion();
                        break;
                    case 3:
                        cout << "\033[1;32m";
                        cout << "Returning to main menu...\n";
                        cout << "\033[0m";
                        break;
                    default:
                        cout << "\033[1;31m";
                        cout << "Invalid choice, please try again.\n";
                        cout << "\033[0m";
                        break;
                }
            } while (choice != 3);
        }

        static void handleHexEncoding() {
            int choice;
            do {
                displayHexMenu();
                cin >> choice;

                switch (choice) {
                    case 1:
                        HexOptionHandler::handleStringToHex32Conversion();
                        break;
                    case 2:
                        HexOptionHandler::handleStringToHex64Conversion();
                        break;
                    case 3:
                        HexOptionHandler::handleHex32ToHex64Conversion();
                        break;
                    case 4:
                        HexOptionHandler::handleHex64ToHex32Conversion();
                        break;
                    case 5:
                        cout << "\033[1;32m";
                        cout << "Returning to main menu...\n";
                        cout << "\033[0m";
                        break;
                    default:
                        cout << "\033[1;31m";
                        cout << "Invalid choice, please try again.\n";
                        cout << "\033[0m";
                        break;
                }
            } while (choice != 5);
        }

    private:
        static void displayHexMenu() {
            cout << "\nHexadecimal Conversion Menu" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Convert string to hex32" << endl;
            cout << "2. Convert string to hex64" << endl;
            cout << "3. Convert hex32 to hex64" << endl;
            cout << "4. Convert hex64 to hex32" << endl;
            cout << "5. Back to Main Menu" << endl;
        }

        static void displayAsciiUnicodeMenu() {
            cout << "\nASCII/Unicode Conversion Menu" << endl;
            cout << "-------------------------------" << endl;
            cout << "1. Convert ASCII to Unicode" << endl;
            cout << "2. Convert Unicode to ASCII" << endl;
            cout << "3. Back to Main Menu" << endl;
        }

        static void displayBase64Menu() {
            cout << "\nBase64 Conversion Menu" << endl;
            cout << "-------------------------------" << endl;
            cout << "1. Base64 encode." << endl;
            cout << "2. Base64 decode." << endl;
            cout << "3. Back to Main Menu" << endl;
        }

    };

} // UI

#endif //HEXUTILS_DISPLAYMANAGER_H

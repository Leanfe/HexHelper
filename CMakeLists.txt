cmake_minimum_required(VERSION 3.24)
project(HexUtils)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        src/main.cpp)

# Add header files to the project
set(HEADERS
        src/hex/Hex32.h
        src/hex/Hex64.h
        src/hex/HexConverter.h
        src/encoding/ASCII.h
        src/encoding/UNICODE.h
        src/ui/DisplayManager.h src/base64/Base64Encoder.h src/utils/Utils.cpp src/utils/Utils.h)

# Set the path to the icon file
set(ICON_PATH "resources/icon.ico" src/base64/Base64Decoder.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${ICON_PATH})
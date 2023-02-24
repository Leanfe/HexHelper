#include <iostream>

#include "ui/DisplayManager.h"

int main() {
    int choice;
    do {
        UI::DisplayManager::displayMainMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                UI::DisplayManager::handleAsciiUnicodeConversion();
                break;
            case 2:
                UI::DisplayManager::handleHexEncoding();
                break;
            case 3:
                UI::DisplayManager::handleBase64();
                break;
            case 4:
                std::cout << "\033[1;31m";
                std::cout << "Goodbye!\n";
                std::cout << "\033[0m";
                break;
            default:
                std::cout << "\033[1;31m";
                std::cout << "Invalid choice, please try again.\n";
                std::cout << "\033[0m";
                break;
        }
    } while (choice != 3);

    return 0;
}

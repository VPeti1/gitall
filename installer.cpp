#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#define clear std::cout << "\033[2J\033[1;1H";
using namespace std;




void dw() {
    std::string input;
    std::cout << "What distro are you using?" << std::endl;
    std::cout << "(arch,debian,fedora,opensuse or void)" << std::endl;
    std::cout << "(Derivatives included)" << std::endl;
    //derivatives like ubuntu,mint...
    std::cin >> input;
    if (input == "arch" || input == "Arch") {
        system("sudo pacman -S git wget gcc");
    }
    else if (input == "debian" || input == "Debian") {
        system("sudo apt-get install git wget build-essential");
    }
    else if (input == "fedora" || input == "Fedora") {
        system("sudo dnf install git wget gcc-c++");
    }
    else if (input == "opensuse" || input == "Opensuse") {
        system("sudo zypper install git wget gcc-c++");
    }
    else if (input == "void" || input == "Void") {
        system("sudo xbps-install git wget gcc");
    }
    else {
        std::cout << "Invalid input\n";
        dw();
    }
    
}


int main() {
    clear;
    std::cout << "Gitall Installer" << std::endl;
    std::cout << "By VPeti" << std::endl;
    sleep(2);
    dw();
    system("read -p 'Press Enter to continue...'");
    system("sudo wget https://raw.githubusercontent.com/VPeti1/gitall/main/main.cpp -O /usr/gitall/pm.cpp");
    //Compiles with blast processing technology :)
    system("sudo g++ /usr/gitall/pm.cpp -o /usr/bin/gitall");
    system("sudo chmod +x /usr/bin/gitall");
    std::cout << "Gitall Installer Completed!" << std::endl;
    system("exit");
}
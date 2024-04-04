#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <unistd.h>

void sudocheck() {
    if (getuid()) {
        printf("%s", "Please rerun the program as root!\n");
        exit(1);
    } 
}

int main(int argc, char* argv[]) {
    // Check the number of arguments
    if (argc < 2 || argc > 3) {
        std::cerr << "Usage: " << argv[0] << " <init|config|print|git> [git command]" << std::endl;
        return 1;
    }
    sudocheck();
    std::ifstream file("/usr/gitall.db");
    // Define the file name
    std::string filename = "/usr/gitall.db";
    // Handle the "init" argument
    if (std::string(argv[1]) == "init") {
        // Check if the file exists
        std::ifstream file(filename);
        if (!file.good()) {
            // File does not exist, create it
            std::ofstream new_file(filename);
            new_file.close();
            std::cout << "Created " << filename << std::endl;
        } else {
            std::cout << filename << " already exists." << std::endl;
            std::cout << "Do you want to reinit the database?\n";
            std::string input;
            std::getline(std::cin, input);
            if (input == "y" || input == "yes") {
                std::ofstream new_file(filename);
                new_file.close();
                std::cout << "Created " << filename << std::endl;
            }
        }
    }
    else if (std::string(argv[1]) == "config") {
    // Check if the file exists
    std::ifstream file(filename);
    if (!file.good()) {
        std::cerr << filename << " does not exist. Please run 'init' first." << std::endl;
        return 1;
    }
    // Check if the file already contains a name
    std::string existing_name;
    std::getline(file, existing_name);
    if (!existing_name.empty()) {
        std::cout << "Data already exists in " << filename << "! " << std::endl;
        return 0;
    }
    std::cout << "How many paths do you want?\n";
    std::string path;
    std::getline(std::cin, path);
    int lineint = std::stoi(path);
    std::ofstream outfile(filename, std::ios::app);
    if (outfile.is_open()) {
        for (int i = 1; i <= lineint; ++i) {
            std::string question;
            std::cout << "Path " << i << "? " << std::endl;
            std::getline(std::cin, question);
            if (question == "exit"){
                break;
            }
            outfile << question << std::endl;
        }
        std::cout << "Data saved to " << filename << std::endl;
        outfile.close();
    } else {
        std::cerr << "Error opening file " << filename << std::endl;
    }
}
else if (std::string(argv[1]) == "print") {
    std::ifstream file(filename);
    if (!file.good()) {
        std::cerr << filename << " does not exist. Please run 'init' first." << std::endl;
        return 1;
    }
    std::vector<std::string> lines;
    std::string line;
    for (int i = 0; i < 15 && std::getline(file, line); i++) {
        lines.push_back(line);
    }
    std::string strVars[15];
    for (int i = 0; i < lines.size() && i < 15; i++) {
        strVars[i] = lines[i];
    }
    for (int i = 0; i < lines.size() && i < 15; i++) {
        std::cout << strVars[i] << std::endl;
    }
    }
    else if (std::string(argv[1]) == "git") {
    std::ifstream file(filename);
    if (!file.good()) {
        std::cerr << filename << " does not exist. Please run 'init' first." << std::endl;
        return 1;
    }
    file.close();
    int line_count = 0;
    std::string linee;
    
    if (file.is_open()) {
        while (std::getline(file, linee)) {
            line_count++;
        }
        file.close();
    }
    std::cout << "Number of paths in the file: " << line_count << std::endl;
    std::string cmd = (argv[1]);
    std::cout << "Your command: git" + cmd + "\n";
    std::cout << "Do you want to continue?\n";
    std::cout << "Do you want to continue?\n";
    std::string input;
    std::getline(std::cin, input);
    if (input == "y" || input == "yes") {
  
    }
    else {
        return 1;
    }
    
    std::vector<std::string> lines;
    std::string line;
    for (int i = 0; i < 15 && std::getline(file, line); i++) {
        lines.push_back(line);
    }
    std::string strVars[15];
    for (int i = 0; i < lines.size() && i < line_count; i++) {
        strVars[i] = lines[i];
    }
    for (int i = 0; i < lines.size() && i < line_count; i++) {
        std::string directory = strVars[i];
        if (chdir(directory.c_str()) != 0) {
        std::cerr << "Error: failed to change directory to " << directory << std::endl;
        return 1;
        }
        std::cout << "Success: changed directory to " << directory << std::endl;
        system(("git " + cmd).c_str());
    }
    }
else {
    std::cout << "Invalid argument!\n";
}
}

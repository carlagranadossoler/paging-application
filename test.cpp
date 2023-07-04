#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]){
    string input = "";
    string output = "";
    if (argc > 2){
        input = argv[1];
        output = argv[2];
    }
    else if (argc > 1){ 
        output = argv[1];
    }
    string ruta = "main.cpp";
    string command = "g++ " + ruta + " -o main.exe && main.exe " + input + " " + output;
    int result = system(command.c_str());
}
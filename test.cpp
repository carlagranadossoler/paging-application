#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]){
    string ruta = "main.cpp";
    string command = "g++ " + ruta + " -o main.exe && main.exe";
    int result = system(command.c_str());
}
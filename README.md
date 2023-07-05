### General Info
***
This application in C++ paginates an input file into a document following the next requirements:
* Each line consists of 80 characters, if they are reached in the middle of a word, it is included completely.
* Each page consists of 25 lines, with a separation mark and the page number in between pages.
## Execution with test.exe
***
Before starting to use it, you must clone or download all the files from the repository in your local computer.

These are the instructions to run and test the application with default values:
1. Find the directory where test.exe is located.
2. Execute test.exe with the following command:
```
$ ./test.exe 
```
The result of the execution is a document named solution.txt which is the result of applying pagination to a default file named document.txt (the one contained in the repository).
## Execution without test.exe
***
If your computer does not allow you to execute any file with the extension .exe, or you want to test the program with other input and output values, you can compile and execute in your local device the main.cpp directly by using the following commands:
```
$ g++ main.cpp -o main 
$ ./main [param1] [param2]
```
Those parameters are the input and output files. The program by default has an input and output, so they are optional. 

If both parameters are introduced, the application will use them when executing. If just one parameter is introduced, the application will use it as an output file, and the input by default. If none of the parameters are introduced, the default ones will be used. 

The output file name by default is solution.txt, while the input file by default is the one contained in the repository downloaded.


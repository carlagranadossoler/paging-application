### General Info
***
This application in C++ paginates an input file into a document following the next requirements:
    - Each line consists of 80 characters, if they are reached in the middle of a word, it is included completely.
    - Each page consists of 25 lines, with a sepparation mark and the page number in between pages.

## Usage
***
Before starting to use it, you must clone or downlawd all the files in your local computer.
These are the instructions to run and test the application:
    1. Find the directory where test.cpp and test.exe are located.
    2. Compile the test.cpp code or simply execute test.exe with the followig command
        $ ./test.exe [param1] [param2]
Those parameters are the input and output files. The program by default has an input and output, so they are optional.
If both parameters are introduced, the application will use them when executing. If just one parameter is introduced, 
the application will use it as an output file, and the input by default. If none of the parameters are intriduced, de default ones will be used.
The output file name by default is solution.txt, while the input file by default is the one contained in the repository downlawded.

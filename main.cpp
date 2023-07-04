#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * @brief Function that converts an integer into a string
 * 
 * @param integerValue: integer that is being converted
 * @return string that represents the conversion of the integer value
*/
string convertToString(int integerValue){
    string result = to_string(integerValue);
    return result;
}
/**
 * @brief Function that writes the paggination mark and the page number to the output file
 * 
 * @param outputFile: output file that is being written 
 * @param page: number of page that is being completed 
 */
void separationMark(ofstream& outputFile, int page){
    string separation;
    int length = 80;
    outputFile << "\n";
    for (int i = 0; i< length; i++){
        if(i == 40){
            string stringPage = convertToString(page);
            separation += stringPage;
        }
        separation.push_back('*');
    }
    outputFile << separation;
    outputFile << "\n";
    outputFile << "\n";
}
/**
 * @brief Function that checks and avoids the split of a word in the middle of it
 * 
 * @param inputFile: input file that is being read 
 * @param line: actual line that is being written 
 * @param character: actual character that is pending to be written in the line
 */
void middleOfAWord(ifstream& inputFile, string& line, char character){
    //Case where the ending of a sentences does not split a word
    if (character == ' ' or character == ',' or character == '.'){
        return;
    }
    //Case where we must add the rest of the word at the end of the line
    else{
        char extraCharacter;
        while(inputFile.get(extraCharacter)){
            line.push_back(extraCharacter);
            if (extraCharacter == ' ' or extraCharacter == ',' or extraCharacter == '.'){
                return;
            }
        }

    }
}
/**
 * @brief Function that paginates according to the requirements
 * 
 * @param inputFile: input file that is being read 
 * @param outputFile: output file that is being written
 */
void readAndWrite(ifstream& inputFile, ofstream& outputFile){
    string line;
    int characters = 0;
    int lines = 0;
    char character;
    int page = 1;
    while (inputFile.get(character)){
        line.push_back(character);
        characters++; 

        //Avoids the addition of the space character at the beggining of a sentence
        if(character == ' ' and characters == 1){
            line.pop_back();
            characters--;
        }
        
        //Writiing of the line when it is full of characters
        if (characters == 80){
            middleOfAWord(inputFile, line, character);
            outputFile << line << endl;
            characters = 0;
            line = "";
            lines++;
        }

        //Adding a pagination mark when the number of lines reaches the maximum
        if (lines == 25){
            separationMark(outputFile, page);
            page++;
            lines = 0;
        }

    }
    outputFile << line << endl;
    separationMark(outputFile, page);
}


int main(int argc, char* argv[]){
    ifstream inputFile;
    ofstream outputFile;
    string oFileName;
    string iFileName;

    //Input and output files from the parameters introduced
    if (argc > 2){
        iFileName = argv[1];
        oFileName = argv[2];
        //inputFile.open(argv[1]);
        //outputFile.open(argv[2]);
    }
    //Output file from the parameter introduced and default input file
    else if (argc > 1){
        iFileName = "document.txt";
        oFileName = argv[1];
        //inputFile.open("document.txt");
        //outputFile.open(argv[1]);
    }
    //Default input and output files
    else{
        iFileName = "document.txt";
        oFileName = "solution.txt";
        //inputFile.open("document.txt");
        //outputFile.open("solution.txt");
    }

    inputFile.open(iFileName);
    outputFile.open(oFileName);

    //Check the correct opening of a file
    if(!inputFile.is_open()){
        cerr << "Unable to open input file with name " << iFileName << endl;
        exit(1);
    }

    //Check the correct opening of a file
    if(!outputFile.is_open()){
        cerr << "Unable to open output file with name " << oFileName << endl;
        exit(1);
    }
    
    //Apply pagination to the input file and write the results into te output file
    readAndWrite(inputFile, outputFile);

    //Close both files opened
    inputFile.close();
    outputFile.close();
}
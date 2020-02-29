#include "Boiler.h"

void makeCppFile(char * argv[], ifstream& headerFile) {
    ofstream outFile;
    string dirPath, fileName;
    fileDirName(argv, dirPath, fileName);
    dirPath += '/' + fileName + ".cpp";

    outFile.open(dirPath);

    copyHeaderComment(argv, headerFile, outFile, fileName);

    outFile << "// Enter function definitions below //" << endl;
    outFile.close();
}

void makeMainFile(char * argv[], ifstream& headerFile) {
    ofstream outFile;
    string dirPath, fileName;
    fileDirName(argv, dirPath, fileName);
    dirPath += "/Main.cpp";

    outFile.open(dirPath);

    copyHeaderComment(argv, headerFile, outFile, fileName);

    outFile << "int main(int argc, char * argv[]) {" << endl
            << "    cout << \"Hello World\" << endl;" << endl
            << "    return 0;" << endl
            << '}';
    outFile.close();
}

void makeHeaderFile(char * argv[], ifstream& headerFile) {
    ofstream outFile;
    string dirPath, fileName;
    fileDirName(argv, dirPath, fileName);
    dirPath += '/' + fileName + ".h";

    outFile.open(dirPath);

    string tempLine;
    while (!headerFile.eof()) {
        getline(headerFile, tempLine);
        outFile << tempLine << endl;
    }
    resetFile(headerFile);

    for (int i = 0; i < fileName.length(); i++) {
        fileName[i] = toupper(fileName[i]);
    }
    outFile << "#ifndef " << fileName << endl
            << "#define " << fileName << endl << endl
            << "#include <iostream>" << endl << endl
            << "using namespace std;" << endl << endl
            << "#endif";
    outFile.close();
}

void copyHeaderComment(char * argv[], ifstream& headerFile, ofstream& outFile, const string& fileName) {
    string tempLine;
    while (!headerFile.eof()) {
        getline(headerFile, tempLine);
        outFile << tempLine << endl;
    }
    resetFile(headerFile);

    tempLine = "#include \"" + fileName + ".h\"";
    outFile << endl << tempLine << endl << endl;
} 

void fileDirName(char * argv[], string& dirPath, string& fileName) {
    dirPath = toCppString(argv[1]);
    fileName = toCppString(argv[2]);
    fileName[0] = toupper(fileName[0]);
}

/*************************************************************
 * Function: resetFile()
 * Date Created: 2/25/2020
 * Date Last Modified: 2/27/2020
 * Description: clears the file flags and sets curser to the top
 *************************************************************/
void resetFile(ifstream& inFile) {
    inFile.clear();  //clears flags
    inFile.seekg(0, ios::beg);
}

string toCppString(char * cString) {
    string cppString = "";
    for (int i = 0; i < strlen(cString); i++) {
        cppString.push_back(*(cString + i));
    }
    return cppString;
}



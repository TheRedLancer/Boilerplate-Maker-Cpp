#include "Boiler.h"

int main(int argc, char * argv[]) { //argv[1] = directory path, argv[2] = file name
    ifstream commentHeader;
    commentHeader.open("header.txt");

    if (argc != 3) {
        cout << "ERROR: Two(2) command line arguments required: directory path, file name" << endl;
        exit(-1);
    }
    string dirPath, fileName;
    fileDirName(argv, dirPath, fileName);
    
    makeCppFile(argv, commentHeader);
    makeHeaderFile(argv, commentHeader);
    makeMainFile(argv, commentHeader);

    cout << "Succesfully created boilerplate code for " << fileName 
    << " in directory: " << dirPath << endl;

    commentHeader.close();
    return 0;
}
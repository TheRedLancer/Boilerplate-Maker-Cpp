#ifndef BOILER
#define BOILER

#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

void makeCppFile(char **, ifstream&);
void makeMainFile(char **, ifstream&);
void makeHeaderFile(char **, ifstream&);

void copyHeaderComment(char **, ifstream&, ofstream&, const string&);
void resetFile(ifstream&);
string toCppString(char *);
void fileDirName(char **, string&, string&);
#endif
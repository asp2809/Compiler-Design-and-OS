// Name - Anshu S Panda
// Roll No. - 39/CSE/16010/167


// These set of Programs are entirely built on Windows and hence I am using carriage return i.e. '\r'
#include<iostream>
#include<fstream>
#include<regex>
#include<string>

using namespace std;

#include "167.2.h"


int main(int argc, char* argv[]) {
    ifstream inputFile;
    string fileName = argv[1];
    stringstream buf;
    inputFile.open(fileName, ios::in);
    buf << inputFile.rdbuf();
    string fileContents = buf.str();
    long int lineNo = 1;
    token nToken;
    while(getline(buf, nToken.strline)) {
        nToken.pos=0;
        if(nToken.strline=="") {
            break;
        }
        while(nToken.strline!="\r") {
            nToken=nextToken(nToken);
            if(nToken.type!="DEFAULT")
                cout<<nToken.type<<": "<<nToken.value<<" <Line: "<<nToken.lineNo<<", Position: "<<nToken.pos+1<<">"<<endl;
        }
        nToken.prevLen=0;
        lineNo++;
        nToken.lineNo=lineNo;
    }
    cout<<"End of File:"<<endl;
    return 0;
}
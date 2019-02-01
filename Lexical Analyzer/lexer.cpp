// Name - Anshu S Panda
// Roll No. - 39/CSE/16010/167


#include<iostream>
#include<fstream>
#include<regex>
#include<string>

using namespace std;

#include "167.2.h"


token nextToken(token nToken) {
    //If-else to check for the regex
    smatch m;
    regex_search(nToken.strline, m, comment);
    if( m.str().length() ) {
        int pos=m.position(0);
        nToken.type="DEFAULT";
        int len=m[0].str().length();
        nToken.strline.erase(pos, len);
    }
    else {
        regex_search(nToken.strline, m, intConst);
        if( m[0].str().length() ) {
            nToken.type="IC";
        }
        else {
            regex_search(nToken.strline, m, binOp);
            if( m[0].str().length() ) {
                nToken.type="BINOP";
            }
            else {
                regex_search(nToken.strline, m, seperator);
                if( m[0].str().length() ) {
                    nToken.type="SEPERATOR";
                }
                else {
                    regex_search(nToken.strline, m, id);
                    if( m[0].str().length() ) {
                        nToken.type="ID";
                    }
                    else {
                        regex_search(nToken.strline, m, noToken);
                        if( m[0].str().length() ) {
                            nToken.type="NO TOKEN";
                        }
                        else {
                            regex_search(nToken.strline, m, space);
                            if( m[0].str().length() ) {
                                nToken.type="DEFAULT";
                            }
                        }
                    }
                }
            }
        }
        nToken.value=m[0].str();
        int pos=m.position(0);
        int len=m[0].str().length();
        nToken.pos=pos + nToken.prevLen;
        nToken.prevLen=len + nToken.prevLen;
        nToken.strline.erase(pos, len);
    }
    return nToken;
}
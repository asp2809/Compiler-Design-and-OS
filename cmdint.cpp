//Author - Anshu S Panda
//Roll No. - 39/CSE/16010

#include<iostream>
#include<cstring>
#include<stdio.h>
#include <vector>
#include <string>
#include <sys/stat.h>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<unistd.h>
#include<fstream>
#include<fcntl.h>
using namespace std;
int main()
{
    string cmd;
    int chpid, status;
    while(1)
    {
        cout<<getcwd(NULL, 0)<<": ";
        getline(cin, cmd);

        //Splitting the input on occurence of white spaces
        string buf;
        stringstream ss(cmd); 
        vector<string> tokens; 

        while (ss >> buf)
            tokens.push_back(buf);
        
        //Checking for the command
        if(tokens[0]=="exit")
            break;

        else if(tokens[0]=="pwd")
            cout<<getcwd(NULL, 0)<<endl;

        else if(tokens[0]=="cd")
        {
            if(chdir(tokens[1].c_str())==-1)
            {
                cout<<"tsh: Directory Not Found!"<<endl;
            }
        }
        else if(tokens[0]=="mkdir")
        {
            if(mkdir(tokens[1].c_str(), 0775)==-1)
                cout<<"tsh: Directory Exists!"<<endl;
        }
        else if(tokens[0]=="rmdir")
        {
            if(rmdir(tokens[1].c_str())==-1)
                cout<<"tsh: Directory Doesn't Exists!"<<endl;
        }
        else if(tokens[0]=="rm")
        {
            cout<<"Are you sure you want to continue?(Y/n): ";
            char t;
            cin>>t;
            if(t=='Y' || t=='y')
            {
                if(remove(tokens[1].c_str())!=0)
                    cout<<"tsh: File doesn't exists!"<<endl;
            }
            else
            {
                cout<<"tsh: Permission Denied!"<<endl;
            }
        }
        else if(tokens[0]=="mv")
        {
            if(rename(tokens[1].c_str(), tokens[2].c_str())!=0)
                cout<<"tsh: Some Error Occured!"<<endl;
        }
        else if(tokens[0]=="cp")
        {
            ofstream outfile;
            outfile.open(tokens[2].c_str());
            ifstream infile;
            infile.open(tokens[1].c_str());
            char c;
            while(infile >> noskipws >> c)
            {
                outfile << c;
            }
            outfile.close();
            infile.close();
        }
        else 
        {
            chpid=fork();
            if(chpid==0)
            {
                vector<char*> cmds;
                for(int i=0;i<tokens.size();i++)
                {
                    cmds.push_back(&tokens[i][0]);
                }
                if(strcmp(tokens[tokens.size()-1].c_str(),"&")==0)
                {
                    cmds.pop_back();
                }
                for(int i=0;i<cmds.size();i++)
                {
                    if(strcmp(cmds[i],">")==0)
                    {
                        close(fileno(stdout));
                        int fd;
                        fd=open(cmds[cmds.size()-1],  O_WRONLY | O_CREAT, 0666);
                        cmds.pop_back();
                        cmds.pop_back();

                    }
                    if(strcmp(cmds[i],"<")==0)
                    {
                        close(fileno(stdin));
                        int fd1;
                        fd1=open(cmds[cmds.size()-1], O_RDONLY, 0444);
                        cmds.pop_back();
                        cmds.pop_back();
                    }
                }
                cmds.push_back(NULL);
                if(execvp(cmds[0], &cmds[0])==-1)
                {
                    cout<<"tsh: Command Not Found!"<<endl;
                }
            }
            else
            {
                if(tokens[tokens.size()-1]!="&")
                {
                    waitpid(chpid, &status, 0);
                }
            }
        }
    }
}
#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <cctype>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <cstdio>
using namespace std;
/*struct arguments
{
    int argc;
    string argv;
};*/
char** argv;
int argc=0;

int getRows(string a);
char** parseCommandLine(string aCommandLine);
void putDaTokensIn(char** theData,int r);
char* sanitize(char* theData);
int recognizeCommands(arguments* data);
char** parseCommandLine(string aCommandLine)
{

    int row=getRows(aCommandLine)+50,col = 100;
    //initial set up
    arguments arg;
    char** allData = new char*[row];
    for(int i=0;i<row;i++)
    {
        allData[i] = new char[col];
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            allData[i][j]=' ';
        }
    }

    char temp[100];
    strcpy(temp,aCommandLine.c_str());
    temp[aCommandLine.length()]='\0';
    int pos=0,line=0,column=0;
    //check for special characters or stuff that isn't alphanumeric
    while(temp[pos]!='\0')
    {
        if(!isalnum(temp[pos]) || temp[pos]=='|' || temp[pos]=='<' || temp[pos]=='>')
        {
            if(temp[pos]=='|' || temp[pos]=='<' || temp[pos]=='>')
            {
                //cout<<temp[pos];
                allData[line][column]=temp[pos];
            }
            line++;
            column=-1;
            cout<<"\n";
        }
        else
        {
            allData[line][column]=temp[pos];
            //cout<<allData[line][column];
        }
        pos++;
        column++;
    }

    //put strings into array
    return allData;
}
int getRows(string inputStr)
{
    int whiteSpcs=0;
    int pos=0;
    while(inputStr[pos]!='\0')
    {
        if(inputStr[pos]==' ')
        {
            whiteSpcs++;
        }
        pos++;
    }
    return whiteSpcs+1;
}
char* sanitize(char* theData)
{
    int loc=0;
    while(isalnum(theData[loc]))
    {
        loc++;
    }
    theData[loc+1]='\0';
    return theData;
}
int recognizeCommands(arguments* data)
{
    cout<<data->argv[0];
}
int main()
{
    //arguments ar;
    string inputStr = "";
    getline(cin,inputStr);
    char** finalData = parseCommandLine(inputStr);
    //sanitize the data
    for(int i=0;i<getRows(inputStr);i++)
    {
        strcpy(argv[i],sanitize(finalData[i]));
    }

    recognizeCommands(ar);

    for(int i=0;i<getRows(inputStr);i++)
    {
        delete[] finalData[i];
    }
    delete[] finalData;
    return 0;
}

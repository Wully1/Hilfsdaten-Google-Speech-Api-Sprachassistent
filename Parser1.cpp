#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;
char* iPars(char* word)
{
ifstream list;
list.open("Commands.txt",ios::in);
int m1=0;
std::string lines[50];

while(!list.eof())
{
getline(list,lines[m1]);
++m1;
}

std::size_t found1[m1];
char sentence[60][m1];
char* command[m1];
for(int i1=0;i1<m1-1;++i1)
{
//std::cout<<lines[i1]<<std::endl;
found1[i1]=lines[i1].find("\"",1);
strncpy(sentence[i1],lines[i1].c_str(),found1[i1]);

sentence[i1][found1[i1]-1]='\0';
char *p1=const_cast <char*> (lines[i1].c_str());
	for (int i2=0;i2<=found1[i1];++i2)
	{
	++p1;
	}
	command[i1]=p1;


std::string sent=sentence[i1];
std::string wordstr=word;
//std::cout<<sentence[i1]<<","<<word<<std::endl;
if(strcmp(sentence[i1],word)==0)
	{
	//std::cout<<sent<<std::endl;
	return command[i1];
	//system(command[i1]);
	}

}
//std::cout<<"h"<<std::endl;
command[1]="0";
return command[1]; //ka wieso NULL geht nicht
}

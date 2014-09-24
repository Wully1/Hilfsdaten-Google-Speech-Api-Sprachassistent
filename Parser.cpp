#include<iostream>
#include"Parser1.cpp"
#include<cstdio>
#include<cstring>
#include<fstream>
#include<cstdlib>
using namespace std;
ifstream file;

int firstend=42;

int main()
{


std::string File[4];
file.open("stt.txt",ios::in);
int num=0;

while(!file.eof())
{
getline(file,File[num]);
++num;
}
std::size_t found =File[1].find("\"",firstend);
char *p1=const_cast <char*> (File[1].c_str());
for(int i=0;i<firstend;++i)
{
++p1;
}
char word[found-firstend-4];
strncpy(word,p1,found-firstend);
word[found-firstend]='\0';
system("clear");



//system("rm stt.txt");
FILE* pfile;
pfile=fopen("Words.txt","w");
fputs(word,pfile);
fclose(pfile);
char * command;
command=iPars(word);

if (command=="0")
{
system("echo 'I dont know what you want from me' | festival --tts");
}
else
{
//std::cout<<command<<std::endl;
system(command);
}
}

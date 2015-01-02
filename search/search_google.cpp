#include<iostream>
#include<cstdlib>
#include<cstring>
#include<fstream>

using namespace std;
std::string getWord()
{
ifstream file;
int firstend=42;
std::string File[5];
int j1=0;
file.open("stt.txt",ios::in);
while(!file.eof())
{
getline(file,File[j1]);
++j1;
}
std::size_t found =File[1].find("\"",firstend);
char *p1=const_cast <char*> (File[1].c_str());
for(int i=0;i<firstend;++i)
{
++p1;
}

char word[found-firstend-4];;


strncpy(word,p1,found-firstend);
word[found-firstend]='\0';
//std::cout<<word<<std::endl;
std::string wort=word;
return wort;
}
int main()
{
system("echo 'Ok,what would you like to search for?' | festival --tts");
system("search/Voice.sh");
std::string Part2=getWord();
std::cout<<Part2<<std::endl;
std::string Part1="firefox -search \"";
std::string Part3="\"";
std::string ges=Part1+Part2+Part3;
system(ges.c_str());
return 0;
}

#include <iostream>
#include<cstdlib>
using namespace std;
inline int len(char * test)
{
for(int i=0;i<50;++i)
	{
	if (test[i]=='\0')
		return i;
	}
}
int main()
{
system("gpio export 17 out");
int i=0;
bool no1=false;
bool no2=false;
bool no3=false;
char Text[50];
int old=0;
int oldold=0;
int current=0;
for(;cin>>Text;)
	{
	if(Text[len(Text)-1]=='%')
		{
	std::cout<<strtol(Text,NULL,10)<<std::endl;
		current=strtol(Text,NULL,10);
		if(no1)
			{
		
			if(no2)
				{
				
					if(no3)
						{
						std::cout<<"Doppelt"<<std::endl;
						system("gpio -g write 17 1");
					//	system("echo<\"Hallo\"");
						no1=false;
						no2=false;
						no3=false;
					
						}
					else
						{
						if(current-old>1)
							no3=true;
						else
							{
						
								if(i<2)
									++i;
								else
								{
									no1=false;
									no2=false;
									no3=false;
								}
							}
						}					
	
				}
			else
				{
				if(old-current>3)
					{
					//cout<<"Pause"<<std::endl;
					no2=true;
					i=0;
					}
				else
					{
					no1=false;
					}
	
				}
		
			}
		else
			{
				if (current-old>1)
					{
				//	std::cout<<"Klatsch"<<endl;
					no1=true;
					}
		
			}
		oldold=old;
		old=current;
		}
	}
}


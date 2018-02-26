#include <iostream>

int nlz(unsigned int x)
{
	int n=0;
    if((x>>16)==0)
	{
        n+=16;
        x<<=16;
	}
    if((x>>24)==0)
	{
        n+=8;
        x<<=8;
	}
    if((x>>28)==0)
	{	
        n+=4;
        x<<=4;
	}
    if((x>>30)==0)
	{
        n+=2;
        x<<=2;
	}	
    if((x>>31)==0)
    {
        n++;
    }


	return n;
}

unsigned long long int todegreeRL(unsigned int x, unsigned int y, unsigned int m)


{
   /* unsigned int  q=x;
    unsigned int  z;*/
    unsigned long long int q=(unsigned long long int)x;
     unsigned long long int  z;

    if(y&1)
        z=x;
    else
        z=1;
    while(y>>=1)
    {
        q=(q*q)%m;
        if(y&1) z=(z*q)%m;
    }
    return z;
}



unsigned long long int  todegreeLR(unsigned int x, unsigned int y,unsigned int m)
{
    unsigned long long int z=(unsigned long long int)x;

        std::cout<<"nlz(y)="<<nlz(y)<<std::endl;
        int tmp=0;
   for(int i=sizeof(y)*8-nlz(y)-1; i>=0; i--)
   {
         std::cout<<"tmp="<<tmp<<std::endl;
         std::cout<<"z="<<z<<std::endl;
        z=(z*z)%m;
        tmp++;
        if ( (y>>(sizeof(y)*8-tmp)) &1)
		{
			z=(z*x)%m;
		}
	}
	return z;
}


int main()
{
    std::cout<<todegreeRL(54,36319,36319)<<std::endl;
    std::cout<<todegreeLR(54,36319,36319)<<std::endl;

   /* int x,y,m;
    for(int i=0; i<10; i++)
	{
		std::cin>>x>>y>>m;
        std::cout<<"RL-->"<<todegreeRL(x,y,m)<<std::endl;
        std::cout<<"LR-->"<<todegreeLR(x,y,m)<<std::endl;
    }*/
}
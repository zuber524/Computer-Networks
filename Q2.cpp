//18/94087
//hamming code
#include<iostream>
#include<math.h>
using namespace std;

class hamming
{
    string data,code,check;int r,m;
    public:
    	void input()
    	{		cout<<"\nDataword=";    cin>>data;	}
        void sender()
        {
            m=data.length();	r=0;
            while(pow(2,r)<m+r+1)	r++;
            int j=0,k=m-1;
            for(int i=1;i<m+r+1;i++)
            {
            	if(i==pow(2,j))
            	{	code+='p';j++;	}
				else
				code+=data[k--];
			}
       		j=0;
      		while(j<r)
        	{	
        		code[pow(2,j)-1]=parity(pow(2,j));	
        		j++;	
        	}
		}
		
		char parity(int i)
		{
			int count=0;	
			for(int j=i-1;j<m+r;j=j+i)
			{
				for(int k=0;k<i;k++,j++)
				{
           			 if(j<m+r&&code[j]=='1')	
           			 count++;
           		}
           	}
			return (count%2==0)?'0':'1';
		}
		
	  	string zero()
        {	
        	string s="";
        	for(int i=0;i<r;i++)	s+='0';	return s;
        }
        
        void printcode()
        {
        	int n=code.length();
			for(int i = n-1; i!=0; i--)
			cout<<code[i];
		}
		
		int error()
		{
			int pos=0;
			for(int i=0; i<r; i++)	pos+=pow(2,i)*(check[i]-48);
			return pos;
		}
		
		void receiver()
		{
			check="";
        	for(int i=0;i<r;i++)
        	check+=parity(pow(2,i));
        	
			if(check==zero())
			cout<<"\nNo error in recieving data.";	
			else
			{
				int pos=error();
				cout<<"\nError is detected at position="<<(code.length()+1)-pos;
				code[pos-1]=(code[pos-1]=='1')?'0':'1';
			}
		}
		
		void hc()
		{
			char c='y';
			do{
				if(c=='y') input();
				sender();
				cout<<"\nData sent to receiver side...";	printcode();
				receiver();
				int a=rand()%code.length();
				cout<<"\nChanging the data of receiver side...";
				code[a-1]=(code[a-1]=='1')?'0':'1';
				cout<<"\nNew data at receiver side=";	printcode();
				receiver();
				cout<<"\nAfter correcting error bit=";	printcode();
				cout<<"\nDo you want to continue?(y/n) : ";	cin>>c;
			}while(c=='y');
		}
};

int main()
{
	hamming a;
	a.hc();
	return 0;
}

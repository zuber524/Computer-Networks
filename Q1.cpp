//18/94087
//q1.crc error detect

#include<iostream>
using namespace std;

class crc1
{
        string data,dsr,crc,rem;
    public:
        crc1()
		{
			data=dsr=crc=rem="";
			cout<<"\nDivisor=";	cin>>dsr;
        }
        
        string zero()
        {	string s="";
        	for(int i=0;i<dsr.length();i++)	s+='0';	return s;
        }
        
        string send()
        {
        	cout<<"\nData=";	cin>>data;
        	crc=zero();
        	crc=crc.substr(1,crc.length());
        	crc=div(data+crc);
        	crc=crc.substr(1,crc.length());
			cout<<"\nData sent to reciever.";
        	return data+crc;
        }
        
        void recieve(string data)
        {
        	rem=div(data);
  			if(rem!=zero())	cout<<"\nData not accepted.";
  			else	cout<<"\nData accepted.";
  		}
  		
  		string div(string data)
  		{
        	int i=dsr.length();
        	rem=data.substr(0,i);
        	while(i<data.length())
        	{
          		if(rem[0]=='1')	rem=Xor(rem,dsr)+data[i];
				else	rem=Xor(rem,zero())+data[i];
				i++;
				rem=rem.substr(1,rem.length());
			}
			if(rem[0]=='1')	rem=Xor(rem,dsr);
			else	rem=Xor(rem,zero());
			return rem;
		}
	
		string Xor(string s,string d)
		{
			string x="";
			for(int i=0;i<dsr.length();i++)
			if(s[i]==d[i])	x+='0';
			else 	x+='1';
			return x;
		}
		void menu()
		{
			char c;
			do
			{
				cout<<"\n1.Send\n2.Recieve\n3.Change Data\n0.Exit";
				cout<<"\nChoice=";
				int ch;cin>>ch;
				switch(ch)
				{
					case 1:data=send();
						break;
					case 2:recieve(data);
						break;
					case 3:cout<<"\nData=";cin>>data;
						cout<<"\nData changed.";
						break;
					case 0:exit(0);
					default:cout<<"\nInvalid input.";
				}
				cout<<"\nContinue(y/n)=";cin>>c;
			}while(c=='y');
		}
						
		
};
int main()
{
    crc1 obj;
    obj.menu();
    return 0;
}

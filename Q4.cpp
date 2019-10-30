//18/94087
//go back n
#include<iostream>
#include<math.h>
using namespace std;

class gbn
{
    int frame_sent;	//frames to be sent
    int m;
    int win_size;		//window size
    int frame_s_success;	//frame sent succesfully
    int frame_n;	//number of frames
    bool flag; 	//checking flag
    public:
    	gbn(){	flag=0;	frame_sent=1;	frame_s_success=1;	}
    	void input()
    	{
    		cout<<"\nNumber of bits in sequence number=";
    		cin>>m;
    		win_size=pow(2,m)-1;
    		cout<<"\nWindow size="<<win_size;
    		cout<<"\nNumber of frames=";
    		cin>>frame_n;
    	}
    		
        void gobackn()
        {
            if(!flag)
            {
            	for(int i=0;i<win_size;i++)
				cout<<"\nFrame "<<frame_sent++<<" sent.";
            }
            while(frame_s_success<=frame_n)
            {
            	int reciever=rand()%win_size;
            	if(reciever==1)
            	{
            		cout<<"\nAcknowledgement recieved.";
            		cout<<"\nFrame "<<frame_s_success<<" succesfully sent.";
            		flag=1;
            		frame_s_success++;
            	}
            	if(flag&&frame_sent<=frame_n)
            	{
            		cout<<"\nWindow shift....";
           			cout<<"\nFrame "<<frame_sent++<<" sent.";
           			flag=0;
           		}
           		else
           		{
           			cout<<"\nAcknowledgement not recieved.";
           			for(int i=frame_s_success;i<frame_sent;i++)
           			cout<<"\nFrame "<<i<<" needs to resend.";
           		}
           	}
           	cout<<"\n";
      	}		
};

int main()
{
	gbn a;
	a.input();
	a.gobackn();
	return 0;
}

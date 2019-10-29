//18/94087
//q3.stop and wait

#include<iostream>
#include<time.h>
using namespace std;

class saw
{
        int frame[20],n,seq,z;
    public:
       	saw()
		{
			seq=0;	z=1;
			cout<<"\nNumber of frame to be sent=";	cin>>n;
			cout<<"\nData in frame=";
			for(int i=1;i<=n;i++)	cin>>frame[i];
			send(0);
        }
        
        void send(int timer)
        {
        	cout<<"\n\n***SENDER***";
        	if(timer==-1)
        	cout<<"\nTimer stopped.\nAcknowledgement not recieved.";
        	cout<<"\nFrame sent to reciever ="<<z<<"\nData in frame ="<<frame[z];
        	cout<<"\nSequence number ="<<seq;
        	if(z>n){}
        	else	random();
        }
        
        void recieve()
        {
            cout<<"\n\n***RECIEVER***";
        	cout<<"\nFrame recieved from sender="<<z<<"\nData in frame ="<<frame[z];
        	cout<<"\nSequence number ="<<seq;
        	cout<<"\nAcknowledgement sent.\nPacket recieved successfully.";
  		}
  		
		void random()
		{
			int r=rand()%3+1;
			switch(r)
			{
				case 1:
					recieve();
					z++;seq=(seq+1)%2;
					send(0);	
					break;
				case 2:
					recieve();
					send(0);		
					break;
				case 3:
					cout<<"\nFrame lost.\nSequence number="<<seq;
					cout<<"\nNegative acknowledgement sent.";
					send(-1);
					break;
			}
		}		
};
int main()
{
    saw a;
    cout<<"\n";
    return 0;
}

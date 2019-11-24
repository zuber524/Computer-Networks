#include<iostream>
#include<unistd.h>
#include<conio.h>
#include<cstdlib>
#include<math.h>
#include<time.h>
int cf=0;
using namespace std;
int seq_range;
struct frame
{
int data;
int seq;
}*Frame,*Sender,*Rec;
class SEL
{
int n,sq,ws,ptr,ctr,t,y,nd,r_ind,c;
bool done;
public: 
void enter()
{
int data;
cout<<"\n Enter the number of bits int the sequence number";
cin>>sq;
ws=pow(2,sq)/2;
seq_range=pow(2,sq);
Sender=new struct frame[ws];
Rec=new struct frame[ws];
cout<<"\n Enter the number of frames:";
cin>>n;
Frame=new struct frame[n];
cout<<"\n Enter the data in frame:";
int temp=0;
r_ind=0;
for(int i=0;i<n;i++)
{
cin>>data;
Frame[i].data=data;
Frame[i].seq=temp;
temp=(temp+1)%seq_range;
}
}
void sender()
{
ctr=ptr=t=0,nd=0;
if((n-ctr)>=ws)
{
for(int i=0;i<ws;i++)
{
Sender[i].data=Frame[t].data;
Sender[i].seq=Frame[t].seq;
cout<<"\n Frame "<<t+1<<"sent";
t++;
nd++;
c=nd;
}
}
else
{
for(int i=0;i<(n-ctr);i++)
{
Sender[i].data=Frame[t].data;
Sender[i].seq=Frame[t].seq;
cout<<"\nFame"<<t+1<<"sent";
t++;
nd++;
c=nd;
}
}
while(ctr<n)
{
r_ind=0;
ptr=0;
while(1)
{
here:
int ack=rec(Sender[ptr].seq,Sender[ptr].data);
usleep(800000);
if(ack=(Sender[ptr].seq+1)%seq_range)
{
cout<<"\n Frame with data"<<Sender[ptr].data<<"sent successfully";
ctr++;
if(n-ctr>=ws)
c=ws;
else
c=n-ctr;
for(int h=ptr;h<c;h++)
Sender[h]=Sender[h+1];
if(t<n)
Sender[c-1]=Frame[t++];
cout<<"\n{{{value in sender}}}";
for(int i=0;i<c;i++)
cout<<Sender[i].data<<"==>>";
done=true;
}
else
{
cout<<"\n Error in sending frame with data"<<Sender[ptr].data;
ptr++;
done=false;
}
if(c==ptr)
ptr=0;
if(c==0)
break;
}
if(c==0)
break;
}
cout<<"\nFRAMES SENT SUCCESSFULLY";
}
int rec(int s,int d)
{
getch();
cout<<"\n\n SENDING ACK\n\n";
int r_no=rand()%2;
if(r_no==0)
{

cout<<"\n\n Frame with data "<<d<<"received at receiver side";
Rec[r_ind].data=d;
Rec[r_ind].seq=s;
r_ind++;
return (s+1)%seq_range;
}
else
return -1;
}
};
int main()
{
srand(time(NULL));
SEL s;
s.enter();
s.sender();
getch();
return 0;
}



//18/94087
//q6.ip address

#include<iostream>
#include<sstream>
using namespace std;
void check(string str)
{
	stringstream geek(str);
	int nid = 0;
	geek>>nid;
	char c='\0';
	if(0<=nid&&nid<=127)	c='A';
	else if(128<=nid&&nid<=191)	c='B';
	else if(192<=nid&&nid<=223)	c='C';
	else if(224<=nid&&nid<=239)	c='D';
	else if(240<=nid&&nid<=255)	c='E';
	else cout<<"Invalid range of IP address.";
	cout<<"IP Address belong to Class="<<c<<"\n";
}
int main()
{
	string ip;
	cout<<"IP_v4 address=";	cin>>ip;
	string x=ip.substr(0,3);
	check(x);
	return 0;
}

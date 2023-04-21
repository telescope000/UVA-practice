#include<bits/stdc++.h>
using namespace std;
string int_to_card(int i){
	int ii=i/13;
	if(ii==0)return "Clubs";  //0~12
	else if(ii==1)return "Diamonds"; //13~25
	else if(ii==2)return "Hearts"; //26~38
	else if(ii==3)return "Spades"; //39~51
}
int int_to_num(int i){
	int tmp;
	int num[15]={2,3,4,5,6,7,8,9,10,11,12,13,1};
	tmp=i%13;
	return num[tmp];	
}
int main(){
	int t,n,num[105][55],change,init[55],tmp,ttmp[52];
	char s[105];
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<52;j++)init[j]=j;
		for(int j=1;j<=n;j++){
			for(int k=0;k<52;k++){
				cin>>num[j][k];
				num[j][k]-=1;
			}
		}
		getchar();
		while(gets(s)){
			if(s[0]=='\n')break;
			if(s[0]=='\0')break;
			change=atoi(s);
			for(int j=0;j<52;j++){
				ttmp[j]=init[num[change][j]];
			}
			for(int k=0;k<52;k++){
				init[k]=ttmp[k];
			}
		}
		for(int j=0;j<52;j++){
			if(int_to_num(init[j])<=10 && int_to_num(init[j])!=1){
				cout<<int_to_num(init[j])<<" of "<<int_to_card(init[j])<<"\n";
			}
			else if(int_to_num(init[j])==11){
				cout<<"Jack"<<" of "<<int_to_card(init[j])<<"\n";
			}
			else if(int_to_num(init[j])==12){
				cout<<"Queen"<<" of "<<int_to_card(init[j])<<"\n";
			}
			else if(int_to_num(init[j])==13){
				cout<<"King"<<" of "<<int_to_card(init[j])<<"\n";
			}
			else if(int_to_num(init[j])==1){
				cout<<"Ace"<<" of "<<int_to_card(init[j])<<"\n";
			}
		}
		if(i!=t-1)cout<<"\n";
	}
}

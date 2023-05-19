/*
這題也是按這題意直接寫出來，沒想到寫了這麼多行(汗
查了一下別人的題解，好像也只有這種做法，那就這樣吧>_<
*/
#include<bits/stdc++.h>
using namespace std;
char board[10][10];
bool Rock(int r,int c,char t){
	char target;
	if(t=='r')target='K';
	else if(t=='R')target='k';
	else return false;
	for(int i=c-1;i>=1;i--){
		if(board[r][i]==target){
			return true;
		}
		else if(board[r][i]!='.'){
			break;
		}
	}
	for(int i=c+1;i<=8;i++){
		if(board[r][i]==target){
			return true;
		}
		else if(board[r][i]!='.'){
			break;
		}
	}
	for(int i=r-1;i>=1;i--){
		if(board[i][c]==target){
			return true;
		}
		else if(board[i][c]!='.'){
			break;
		}
	}
	for(int i=r+1;i<=8;i++){
		if(board[i][c]==target){
			return true;
		}
		else if(board[i][c]!='.'){
			break;
		}
	}
	return false;
}
bool Bishop(int r,int c,char t){
	char target;
	if(t=='b')target='K';
	else if(t=='B')target='k';
	else return false;
	//左上 
	for(int i=r-1,j=c-1;i>=1,j>=1;i--,j--){
		if(board[i][j]==target){
			return true;
		}
		else if(board[i][j]!='.'){
			break;
		}
	}
	//右上 
	for(int i=r-1,j=c+1;i>=1,j<=8;i--,j++){
		if(board[i][j]==target){
			return true;
		}
		else if(board[i][j]!='.'){
			break;
		}
	}
	//左下 
	for(int i=r+1,j=c-1;i<=8,j>=1;i++,j--){
		if(board[i][j]==target){
			return true;
		}
		else if(board[i][j]!='.'){
			break;
		}
	}
	//右下 
	for(int i=r+1,j=c+1;i<=8,j<=8;i++,j++){
		if(board[i][j]==target){
			return true;
		}
		else if(board[i][j]!='.'){
			break;
		}
	}
	return false;
}
bool Queen(int i,int j,char t){
	char target;
	if(t=='q'){
		if(Rock(i,j,'r')||Bishop(i,j,'b')){
			return true;
		}
		else return false;
	}
	else if(t=='Q'){
		if(Rock(i,j,'R')||Bishop(i,j,'B')){
			return true;
		}
		else return false;
	}
	else return false;
}
bool King(int r,int c,char t){
	char target;
	if(t=='k')target='K';
	else if(t=='K')target='k';
	else return false;
	for(int i=r-1;i<=r+1;i++){
		for(int j=c-1;j<=c+1;j++){
			if(board[i][j]==target){
				return true;
			}
		}
	}
	return false;
}
bool Knight(int i,int j,char t){
	char target;
	if(t=='n')target='K';
	else if(t=='N')target='k';
	else return false;
	if(board[i+2][j-1]==target ||
	board[i+2][j+1]==target ||
	board[i-2][j-1]==target ||
	board[i-2][j+1]==target ||
	board[i-1][j-2]==target ||
	board[i-1][j+2]==target ||
	board[i+1][j-2]==target ||
	board[i+1][j+2]==target )
		return true;
	else return false;
}
int main(){
	int case_num=1;
	int ans; // 1 white 0 no -1 black
	bool b=false,judge=false;
	while(1){
		b=false;
		judge=false;
		ans=0;
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				cin>>board[i][j];
				if(board[i][j]!='.')b=true;
			}
		}
		if(!b)break;
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				if(board[i][j]!='.'){
					if(Rock(i,j,board[i][j]) || Bishop(i,j,board[i][j]) || Queen(i,j,board[i][j]) || King(i,j,board[i][j]) || Knight(i,j,board[i][j])){
						//cout<<"come\n";
						if(board[i][j]>='a' && board[i][j]<='z'){
							ans=1;
							judge=true;
							break;
						}
						else if(board[i][j]>='A' && board[i][j]<='Z'){
							ans=-1;
							judge=true;
							break;	
						}
					}
					if(board[i][j]=='p'){
						if(board[i+1][j-1]=='K' || board[i+1][j+1]=='K'){
							ans=1;
							judge=true;
							break;
						}
					}
					if(board[i][j]=='P'){
						if(board[i-1][j-1]=='k' || board[i-1][j+1]=='k'){
							ans=-1;
							judge=true;
							break;
						}
					}
				}
			}
			if(judge)break;
		}
		
		//ans
		if(ans==1){
			cout<<"Game #"<<case_num<<": white king is in check.\n";
		} 
		else if(ans==-1){
			cout<<"Game #"<<case_num<<": black king is in check.\n";
		}
		else{
			cout<<"Game #"<<case_num<<": no king is in check.\n";
		}
		case_num++;
	}
}

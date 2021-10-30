#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
string result;

int Rand100(){
	
	int a=rand()%101;
	return a;
}
int Int_Rand10000(){
	int a=rand()%101;
	srand(a);
	int b=rand()%101;
	return a*b;
}
double Double_Rand10000(){
	srand(Int_Rand10000());
	int a=rand()%101;
	srand(a);
	int b=rand()%101;
	srand(b);
	int c=rand()%101;
	double d=(double)c/100;
	d+=a*b;
	return d;
}
int  Equation_Number(){
	int a=rand()%3+2;
	return a;
}
int Add_Sub_Choose(){
	int a=rand()%2;
	return a;
}
int Add_Sub_Multi_Divid_Choose(){
	int a=rand()%4;
	return a;
}
string Transform_Int_String(int a){
	string t;
	char save[20];
	int n=0;
	while(a>0){
		int i=a%10;
		a=a/10;
		save[n++]='0'+i;
	}
	for(int i=n-1;i>=0;i--){
		t+=save[i];
	}
	return t;
}
string Transform_Double_String(double a){
	string t;
	char save[20];
	int n=0;
	int b=a*100;
	while(b>0){
		int i=b%10;
		b=b/10;
		if(n!=2){
			save[n++]='0'+i;
		}
		else{
			save[n++]='.';
			save[n++]='0'+i;
		}
	}
	for(int i=n-1;i>=0;i--){
		t+=save[i];
	}
	return t;
}
char Get_Sign_low(int a){
	if(a==0)return '+';
	else if(a==1)return '-';
}
char Get_Sign_high(int a){
	if(a==0)return '+';
	else if(a==1)return '-';
	else if(a==2)return '*';
	else if(a==3)return '/';
}
int Left_Brackets(int a){
	if(a==2)return 0;
	else {
		int b=rand()%(a-1)+1;
		return b;
	}
}
int Right_Brackets(int a,int l){
	if(a==0)return 0; 
	int c=rand()%(a-l)+(l+1);
	return c;
} 
int main(){
	srand(time(NULL)); 
}

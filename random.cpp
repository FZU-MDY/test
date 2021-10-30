#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
string result;
int Rand100(){				//生成0-100整型的随机数 
}
int Int_Rand10000(){		//生成0-10000整型的随机数 
}
double Double_Rand10000(){	//生成0-10000浮点型的随机数 
}
int  Equation_Number(){
  srand(time(NULL));
	int a = rand() % 3 + 2;
	return a;
}
int Add_Sub_Choose() {
	srand(time(NULL));
	int a = rand() % 2;
	return a;
}
int Add_Sub_Multi_Divid_Choose() {
	srand(time(NULL));
	int a = rand() % 4;
	return a;
}
string Transform_Int_String(int a){
}
string Transform_Double_String(double a){
}
string Connect_eqution_low() {
	string number;
	string sign;
	int num = Equation_Number();
	int first_number = Rand100();
}

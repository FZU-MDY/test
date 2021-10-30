#include<bits/stdc++.h>

using namespace std;

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


double calculate(string s){
    double res = 0, cur_res = 0;
    int cnt0=0,flag=0;
	double num = 0;
    char op = '+';
    s += '+';
    for (int i = 0; i < s.size(); ++i) {
    	
        char c = s[i];
        if (isdigit(c))
            {if(flag==0)
            num = num * 10 + c - '0'; 
            if(flag==1)
            {
			cnt0++;
            num = num + (c - '0')*1.0/(cnt0*10);}
			}
        else if(c=='.'){
        	flag=1;continue;
		}
        else if (c == '(') {
        	flag=0;
        	cnt0=0;
            // 将括号中的子字符串作为一个表达式
            int left = i;
            int cnt = 0;  // 保证括号能够匹对的上
            for (; i < s.size(); ++i) {
                if (s[i] == '(') ++cnt;
                if (s[i] == ')') --cnt;
                if (cnt == 0) break;
            }
            num = calculate(s.substr(left + 1, i - left + 1 - 2));
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
        	flag=0;
        	cnt0=0;
            switch (op)  // 使用的是op，不是c
            {
            case '+': cur_res += num; break;
            case '-': cur_res -= num; break;
            case '*': cur_res *= num; break;
            case '/': cur_res =cur_res*1.0/ num; break;
            }

            if (c == '+' || c == '-') {
                res += cur_res;
                cur_res = 0;
            }
            op = c;
            num = 0;
        }
    }
    return res;
}

string create12(){
	string s;
	char sym;
	int len0=Equation_Number();
	
			for(int i=0;i<len0;i++) 
			{
				if(i==0)
				s=Transform_Int_String(Rand100());
				
				else
				{
				sym=Get_Sign_low(Add_Sub_Choose());
				s=s+sym;
				
				string num1=Transform_Int_String(Rand100());
				s=s.append(num1);}
				
								
			}
	return s;
}

string create34(){
	string s;
	char sym;
	int len0=Equation_Number();
			for(int i=0;i<len0;i++) 
			{
				if(i==0)
				s=Transform_Int_String(Int_Rand10000());
				
				else
				{
				sym=Get_Sign_high(Add_Sub_Multi_Divid_Choose());
				s=s+sym;
				string num1=Transform_Int_String(Int_Rand10000());
				s=s.append(num1);}
				
								
			}
	return s;
}

string create56(){
	string s;
	char sym;
	int len0=Equation_Number();
			for(int i=0;i<len0;i++) 
			{
				if(i==0)
				s=Transform_Double_String(Double_Rand10000());
				
				else
				{
				sym=Get_Sign_high(Add_Sub_Multi_Divid_Choose());
				s=s+sym;
				char sym0='(';
				char sym1=')';
				if(i==1&&len0>2)
				s+=sym0;
				
				string num1=Transform_Double_String(Double_Rand10000());
				s=s.append(num1);if(i==2)
				s+=sym1;}
				
								
			}
	return s;
}

void judge()
{	
	int daan,n,num0,sum=0;
	string s1;string s;
	cout<<"请输入你的年级？"<<endl;
	cin>>s1;
	cout<<"请输入题目数？"<<endl;
	cin>>n;
	if(s1=="一年级"||s1=="二年级")
	{
		for(int i=0;i<n;i++)
		{
			
			cout<<create12()<<endl;
			 s=create12();
			int answer;
			cin>>answer;
			
			if(answer==(int)(calculate(s)))
			{
				sum++;
				
			}
			
		 } 
		
	}
	
	else if(s1=="三年级"||s1=="四年级")
	{
		for(int i=0;i<n;i++)
		{
			
			cout<<create34()<<endl;
			 s=create34();
			cout<<calculate(s)<<endl;
			int answer;
			cin>>answer;
			
			if(answer==calculate(s))
			{
				sum++;
				
			}
			
		 } 
		
	}
	
	
	else if(s1=="五年级"||s1=="六年级")
	{
		for(int i=0;i<n;i++)
		{
			
			cout<<create56()<<endl;
			 s=create56();
			cout<<calculate(s)<<endl;
			int answer;
			cin>>answer;
			
			if(answer==calculate(s))
			{
				sum++;
				
			}
			
		 } 
		
	}
	
	
	
	
	if(sum==n)
	{
		cout<<"结束！全部正确，太棒了！"<<endl;
	}
	else cout<<"结束！错了"<<n-sum<<"题哦"<<endl; 
}



int main()
{
	srand(time(NULL));
	judge();
    
    return 0;
}

#include <iostream>
using namespace std;

int f(int x){
	
	return x;
	
}

int main(){
	
	int a;
	
	cout<<"数字を入力してください > "<<flush;
	cin>>a;
	
	f(a);
	
	cout<<f(a)<<endl;
	
}
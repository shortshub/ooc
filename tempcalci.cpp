#include<iostream>
using namespace std;

template<typename T>
 T calculator(T n1,T n2,char op){
 
 	switch(op){
 		case '+': return n1 + n2;
 		case '-': return n1-n2;
 		case '*': return n1*n2;
 		case '/': if(n2 != 0){
 				return n1/n2;
 				}
 				else{
 					cout<<"error"<<endl;
 					return 0;
 				}
 		default : cout<<"invalid option"<<endl;
 		return 0;		
 	}
 
 }
 
 int main(){
 	char op;
 	double n1, n2;
 	cout<<"n1 is "<<endl;
 	cin>>n1;
 	cout<<"op is "<<endl;
 	cin>>op;
 	cout<<"n2 is "<<endl;
 	cin>>n2;
 	
 	double result = calculator(n1, n2, op);
 	cout<<"result is "<<result<<endl;
 	return 0;
 	
 	
 }

#include<iostream>
#include<string>
using namespace std;

class student{
	public: 
		string name;
		int roll;
		int marks;
		string add;
		// default constructor
		student(){
			name = "default";
			roll = 0;
			marks = 00;
			add = "default";
		}
		//paramaterized
		
		student(string n,int r,int m,string a){
			name = n;
			roll = r;
			marks = m;
			add = a;
		}
		void setdata(){
			cout<<"name "<<endl;
			cin>>name;
			cout<<"roll "<<endl;
			cin>>roll;
			cout<<"marks "<<endl;
			cin>>marks;
			cout<<"address "<<endl;
			cin>>add;
		}
		void getdata(){
			cout<<" the name is "<<name<<endl;
			cout<<" the rol is "<<roll <<endl;
			cout<<" the marks is "<<marks<<endl;
			cout<<" the address is "<<add<<endl;
		}
		//copy
		student(student &obj){
			cout<<"copy constructor is called "<<endl;
			name = obj.name;
			roll = obj.roll;
			marks = obj.marks;
			add = obj.add;
		}
		//destructoer
		~student(){
			cout<<"destructor byu name "<<name<<endl;
		}
		
};

int main(){
	string n1,a1;
	int m1,r1;
	
	student a;
	cout<<"default constructor "<<endl;
	a.getdata();
	cin>>n1>>r1>>m1>>a1;
	student b(n1,r1,m1,a1);
	cout<<"paramaterized constructor "<<endl;
	//b.setdata();
	b.getdata();
	student c(b);
	c.getdata();
}

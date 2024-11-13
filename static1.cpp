#include<iostream>
using namespace std;

class student{
	private:
		int marks;
		static int count;
		friend student totalmarks(student stud);
	public:
		char name[10];
		int roll;
		student(){
			marks = 0;	
		}
		void setdata(){
			cout<<"enter the name "<<endl;
			cin>>name;
			cout<<"enter the roll "<<endl;
			cin>>roll;
			cout<<"enter the marks "<<endl;
			cin>>marks;
			count++;
		}
		
		void setmarks(int m){
			marks = m;
		}
		void getmarks(){
			cout<<"the student marks is "<<marks<<endl;
		}
		static void getcount(){
			cout<<"the count is "<<count<<endl;
		}
			
};

int student :: count  = 0;

student totalmarks (student stud){
	student total;
	total.setmarks(stud.marks);
	return total;
}

int main(){
	int n;
	cout<<"enter the number of the student "<<endl;
	cin>>n;
	int m;
	cout<<"enter the marks "<<endl;
	cin>>m;
	student a[n],b;
	for(int i =0 ;i<n;i++){
		a[i].setdata();
		//a[i].getdata();
		student :: getcount();
		a[i].setmarks(m);
		a[i].getmarks();
	}
	//b.setmarks(5);
	//b.getmarks();
	return 0;
}

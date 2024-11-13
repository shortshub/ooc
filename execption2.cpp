#include<iostream>
#include<stdexcept>
using namespace std;

int main(){

    double bal = 1000;
    try{
        double amt;
        //deposit;
        cout<<"enter the deposit amount "<<endl;
        cin>>amt;
        if(amt<=0){
           // cout<<"invalid amount "<<endl;
            throw invalid_argument("invalid deposit amount ");
        }
        bal = bal+amt;
        cout<<"availble amount is "<<bal<<endl;
        cout<<"withdrawn amount enter"<<endl;
        cin>>amt;
        if(amt<=0){
            //cout<<"invalid withdrawn amount "<<endl;
            throw invalid_argument("invalid withdrawn amount ");
        }
        if(amt>bal){
           throw runtime_error("insufficent fund ");
           // cout<<"insufficent balance "<<endl;
        }
        bal = bal-amt;
        cout<<"available amount is "<<bal<<endl;
    }
    catch(exception& e){
        cout<<e.what();
    }
    return 0;
}
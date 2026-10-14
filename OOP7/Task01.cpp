
#include<iostream>
using namespace std;

int Price  = 800;

int CalculateBill(){
	return Price;
}

int CalculateBill(int n){
	return n*Price;
}

int CalculateBill(int n,int delivery){
	return CalculateBill(n) + delivery;
}

int main(){

  int num;
  char d;
  cout<<"Enter number of Pizza's:";
  cin>>num;
  cout<<"Delivery Fee? (y/n) ";
  cin>>d;
  
  if(num == 1 && d == 'n'){
  	cout<<"Total Bill : "<<CalculateBill()<<endl;
  }else if(num > 0 && d=='y'){
  	cout<<"Total Bill : "<<CalculateBill(num,200)<<endl;
  }else{
  	cout<<"Total Bill : "<<CalculateBill(num)<<endl;
  }

	
	
	return 0;
}

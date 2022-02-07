#include <bits/stdc++.h>
#include <conio.h>
#include<string>
using namespace std;

//preFunctions
class stock;
void order();
void data();
void home(stock &owner, stock &client);
double money;

//Main Class
class stock{
private:
	int ct[100]={};
public:
	int orderCt = 0;
	string item[100];
	static int itemCt;
	friend void order(stock &obj,stock &data);
	friend void data(stock &obj);
};

int stock :: itemCt = 0;

//Test Products
stock test(stock obj){
	obj.item[obj.itemCt++] = "Monitor 69,000 TK";
	obj.item[obj.itemCt++] = "Laptop 150,000 TK";
	obj.item[obj.itemCt++] = "Keyboard 11,000 TK"; 
	return obj;
}

template<class t>
t addBalance(t amount){
	money += amount;
}

//Order form Customer // Friend function
void order(stock &obj,stock &data){
	system("cls");
	cout<<"\n\n\n\n\n\t\t\t\t\t\t";
	cout<<"Items aviable: "<<endl;
	for(int i=0;i<obj.itemCt;i++){
		cout<<i+1<<". "<<data.item[i]<<endl;
	}
	cout<<"\n\nEnter the product you want to Order: ";
	int x; cin>>x;
	data.ct[x-1]++;
	cout<<"Payment: ";
	double money; cin>>money;
	addBalance(money);
	data.orderCt++;
	cout<<"Order Placed. Press any key to contnue ";
	getch();
	home(data,obj);

}

//Owner Interface //Friend Function
void data(stock &obj){
	cout<<"\n\n\n\n\n\t\t\t\t\t\t";
	cout<<"\n\t\t\t\t\t\t1. Add items. \n\t\t\t\t\t\t";
	cout<<"2. See Orders";
	cout<<" ("<<obj.orderCt<<")"; 
	cout<<"\n\t\t\t\t\t\t3. See Balance\n\t\t\t\t\t\t4. Home"<<endl;
	cout<<"\n\n\n\n\n\t\t\t\t\t\t";
	string s;
	int j=0,x; cin>>x;
	switch(x){
		case 1 : system("cls");
		cout<<"Enter the item and Price: ";
		cin.ignore();
		getline(cin,s);
		obj.item[obj.itemCt] = s;
		obj.itemCt++;
		cout<<"Item added. Press any key to return";
		getch();
		data(obj);
		break;
		
		case 2 : system("cls");
		for(int i=0;i<obj.itemCt;i++){
			if(obj.ct[i] !=0){
				cout<<++j<<". "<<obj.item[i]<<endl;
			}
		}
		cout<<"Press any key to return";
		getch();
		data(obj);
		break;
		case 3 : system("cls");
		cout<<"Balance: "<<money<<endl;
		cout<<"Press any key to return";
		getch();
		data(obj);
		break;

	}
}

//Home Page
void home(stock &owner, stock &client){
	system("cls");
	cout<<"\n\n\n\n\n\t\t\t\t\t\t";
	cout<<"Log in as: "<<endl;
	cout<<"\n\t\t\t\t\t\t1. Owner";
	cout<<"\n\t\t\t\t\t\t2. Customer\n\t\t\t\t\t\t";
	int x; cin>>x;
	switch(x){
		case 1 :
		system("cls");
		data(owner);
		getch();
		home(owner,client);
		break;

		case 2 : system("cls");
		order(client,owner);
		getch();
		home(owner,client);
		break;
	}
}

int main(){
	stock owner, client;
	owner = test(owner);
	home(owner, client);
	return 0;
}

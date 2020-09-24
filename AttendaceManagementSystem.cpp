#include<iostream>
#include<conio.h>
#include <string>
#include<fstream>
using namespace std;

class Name{
	public:
		string name;
		string semester;
		string section;
		string roll;
		string attend;
		int choose;
		bool con=true;
	void names(){
		cout<<"Insert Informations"<<endl;
		cout<<"Enter roll number of a student"<<endl;
		cin>>roll;
		cout<<"Enter name of Student"<<endl;
		cin>>name;
		cin.ignore();
		cout<<"Enter semester of student"<<endl;
		cin>>semester;
		cin.ignore();
		cout<<"Enter Section of student"<<endl;
		cin>>section;
		cin.ignore();
		system("color 03");
		cout<<"Press Enter to store attendance of "<<name<<endl;
		cin.ignore();
		system("cls");
		while(con==true){
		cout<<"Enter\n1: Present\n2: Absent"<<endl;
		cin>>choose;
		cin.ignore();
		switch(choose){
			case 1:
				attend="Present";
				con=false;
				break;
				
			case 2:
				attend="Absent";
				con=false;
				break;
			default:
				cout<<"Invalid choose"<<endl;
				
		}
	}
	}
	
};
	Name n;

struct Node{
	string data;
	int roll;
	struct Node* next;
};

void display(struct Node* n){
	cout<<"\t\tDisplayed information"<<endl;
	while(n!=NULL){
		cout<<"\t\t"<<n->data<<endl;
		n=n->next;
	}
	cout<<"Press Enter to continue"<<endl;
	cin.ignore();
	
}
void firstwindow(){
	cout<<endl;
	cout<<"\t\t***************************************************"<<endl;
	cout<<"\t\t***************************************************"<<endl;
	cout<<"\t\t***\t\t\t\t\t\t***"<<endl;
	cout<<"\t\t***\t\t\t\t\t\t***"<<endl;
	cout<<"\t\t***\t\t\t\t\t\t***"<<endl;
	cout<<"\t\t***\t\t\t\t\t\t***"<<endl;
	cout<<"\t\t***\t   Attendace Management System\t\t***"<<endl;
	cout<<"\t\t***\t\t\t\t\t\t***"<<endl;
	cout<<"\t\t***\t\t\t\t\t\t***"<<endl;
	cout<<"\t\t***\t\t\t\t\t\t***"<<endl;
	cout<<"\t\t***\t\t\t\t\t\t***"<<endl;
	cout<<"\t\t***\t\t\t\t\t\t***"<<endl;
	cout<<"\t\t***************************************************"<<endl;
	cout<<"\t\t***************************************************"<<endl;
	cout<<"\t\tPress Enter to continue";
	cin.ignore();
	system("cls");
}
void login(){
	system("cls");
	system("color 06");
	string username;
	string password="";
	char ast;
	bool con=true;
	while(con=true){
		cout<<"Enter your username"<<endl;
		cin>>username;
		cout<<"Enter your password"<<endl;
//		cin>>password;
		ast = _getch();
	while(ast!=13)
	{
      password.push_back(ast);
      cout << '#';
      ast = _getch();
  }
		if(username=="sandesh"&&password=="sandesh"){
			con=false;
			
			break;
		}
		else{
			cout<<"Invalid username or password"<<endl;
		}
}
cout<<"press Enter to continue"<<endl;
			cin.ignore();
			system("cls");
}
void storeinfile(){

	cout<<n.name;
	getchar();
			ofstream ofile;
			
			ofile.open("Information.txt",ios::app);
			ofile<<endl;
			ofile<<"Name= "<<n.name<<endl;
			ofile<<"Semester= "<<n.semester<<endl;
			ofile<<"Section= "<<n.section<<endl;
			ofile<<"Attendance= "<<n.attend<<endl;
			ofile.close();
			system("cls");
			cout<<"Stored in file"<<endl;
			cout<<"press Enter to continue"<<endl;
			cin.ignore();
}

void takefromfile(){
	system("cls");
	system("color 06");
	ifstream ifile;
	string myText;
	ifile.open("Information.txt");
	while (getline (ifile, myText)) {
  // Output the text from the file
  	cout << myText<<endl;
}
	getchar();
	getchar();
}

int main(){
	
	firstwindow();
	
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	struct Node* fourth=NULL;
	struct Node* fifth=NULL;
	
	head=new Node();
	head =new Node();
	second=new Node();
	third=new Node();
	fourth=new Node();
	fifth=new Node();
	int choose;
	
	int cont=1;
	login();

	while(cont!=5){
		system("cls");
		cout<<"Enter\n1:store name and attendace\n2:Display attendace\n3:Store in file\n4:Display all information from file\n5:Exit"<<endl;
		cin>>choose;
		switch(choose){
		case 1:
			system("cls");
			n.names();
			head->data=n.name;
			head->next=second;
			
			second->data=n.semester;
			second->next=third;
			
			third->data=n.section;
			third->next=fourth;
			
			fourth->data=n.roll;
			fourth->next=fifth;
			
			fifth->data=n.attend;
			break;
		case 2:
			system("cls");
			cout<<"Press Enter to display information"<<endl;
			cin.ignore();
			system("cls");
			
			display(head);
			cout<<"press Enter to continue"<<endl;
			cin.ignore();
			if(n.attend=="Absent"){
				system("cls");
				cout<<n.name<<"	is absent today"<<endl;
			}
			if(n.attend=="Present"){
				system("cls");
				cout<<n.name<<" is Present today"<<endl;
				cin.ignore();
			}
			break;
		case 3:
			storeinfile();
			
			break;
		case 4:
			takefromfile();
			break;
			
		case 5:
			cont=5;
			break;
		default:
			cout<<"Invalid choose";
			break;
	}
}
	return 0;
	
}

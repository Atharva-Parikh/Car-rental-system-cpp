#include<iostream>
#include<sstream>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;

class Login{ 
	protected:		
		char username[100];
		char password[50];
		unsigned int access;
	public:
		void Register();
		void login(char user_n[], char pass[]);
};

void Login :: Register()
{
	ofstream fout("login_data.txt",ios::app);
	cout<<"Enter username(mail): ";
	cin>>username;
	cout<<"Enter your preferred password: ";
	cin>>password;
	cout<<"Press 1. Member 2.Admin: ";
	cin>>access;
	fout<<username<<" "<<password<<" "<<access<<" ";
	fout.close();
}

void Login :: login(char user_n[], char pass[])
{
	ifstream fin("login_data.txt",ios::in);
	while(!fin.eof())
	{
		fin>>username>>password>>access;
		if(strcmp(user_n,this->username)==0 && strcmp(pass,this->password)==0)
		{
			if(access==1)
			{
				cout<<"Welcome back "<<username<<endl;
			}
			else if(access==2)
			{
				cout<<"Another day at work, isn't it "<<username<<endl;
			}
		}
	}
	fin.close();
}



int main()
{
	Login l1;
    while(1)
    {
	    system("cls");
	    char username[100],password[50];
	    unsigned int ch;
	    cout<<" ********  Welcome to Car Rental System *********";
	    cout<<"\n 1. Login \n 2. Register \n 3. Exit"<<endl;
	    cout<<"Enter choice: ";
	    cin>>ch;
	    switch(ch)
	    {
	        case 1:
	           cout<<" Username : "; cin>>username;
	           cout<<" Password : "; cin>>password;
	           l1.login(username,password);
	        break;
	        case 2:
	                l1.Register();
	        break;
	        case 3:
	            exit(1);
	    }
	    getch();
  }
}

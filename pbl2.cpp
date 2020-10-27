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
		void Export();
		void Read();
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
	fout<<username<<" "<<password<<" "<<access<<endl;
	fout.close();
}

void Login::Read()
{
	ifstream fin("login_data.txt",ios::in);
	while(fin>>username>>password>>access)
	{
		cout<<"Username - "<<username<<"\n"<<"Password - "<<password<<"\n"<<"role - "<<access<<"\n"<<endl;
	}
	fin.close();
}

void Login :: login(char user_n[], char pass[])
{
	ifstream fin("login_data.txt",ios::in);
	while(fin>>username>>password>>access)
	{
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
		else if(strcmp(user_n,this->username)>0 && strcmp(pass,this->password)==0)
        {
            cout<<"Please enter valid username!"<<endl;
        }
        else if(strcmp(user_n,this->username)<0 && strcmp(pass,this->password)==0)
        {
            cout<<"Please enter valid username!"<<endl;
        }
        else if(strcmp(user_n,this->username)==0 && strcmp(pass,this->password)>0)
        {
            cout<<"Please enter valid password!"<<endl;
        }
        else if(strcmp(user_n,this->username)==0 && strcmp(pass,this->password)<0)
        {
            cout<<"Please enter valid password!"<<endl;
        }

        else{
            cout<<"It seems you are not registered memaber "<<endl;
        }
	}
	fin.close();
}

void Login::Export()
{
	ifstream fin("login_data.txt",ios::in);
	ofstream fout("Login_data.csv",ios::out);
	fout<<"USERNAME"<<","<<"PASSWORD"<<","<<"ROLE(1=Member 2=Admin)"<<endl;
	while(fin>>username>>password>>access)
	{
		if(access==1)
			fout<<username<<","<<password<<","<<"Member"<<endl;
		else if(access==2)
			fout<<username<<","<<password<<","<<"Admin"<<endl;
	}
	fin.close();
	fout.close();
}

int main()
{
	Login l1;
    while(1)
    {
	    system("cls");
	    char username[100],password[50];
	    unsigned int ch;
	    cout<<" ***  Welcome to Car Rental System ****";
	    cout<<"\n 1. Login \n 2. Register \n 3. Read \n 4.Export \n 5. Exit"<<endl;
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
	        		l1.Read();
	        	break;
	        case 4:
	        		l1.Export();

	        		cout<<"File has been made in the folder"<<endl;
	        	break;
	        case 5:
	            exit(1);
	    }
	    cout<<"Press anything to proceed: ";
	    getch();
  }
}

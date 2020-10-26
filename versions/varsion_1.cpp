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
	public:
		void Register();
		void login(char user_n[], char pass[]);
};

class Login_admin:public Login{
	public:
		void login_admin(char user_n[],char pass[]);
		void register_admin();
		void Export();
		void Read();
};

void Login_admin :: register_admin()
{
	ofstream fout("admin_data.txt",ios::app);
	cout<<"Enter username(mail): ";
	cin>>username;
	cout<<"Enter your preferred password: ";
	cin>>password;
	fout<<username<<" "<<password<<endl;
	fout.close();
}

void Login_admin::Read()
{
	ifstream fin("login_data.txt",ios::in);
	while(fin>>username>>password)
	{
		cout<<"Username - "<<username<<"\n"<<"Password - "<<password<<"\n"<<endl;
	}
	fin.close();
}

void Login_admin::login_admin(char user_n[], char pass[])
{
	int ch = 0;
	ifstream fin("admin_data.txt",ios::in);
	while(fin>>username>>password)
	{
		if(strcmp(user_n,this->username)==0 && strcmp(pass,this->password)==0)
		{
			cout<<"Hello "<<username<<endl;
			while(ch!=3){
				cout<<"Enter\n 1.To see all the users\n 2.To Export the file to Excel\n 3.Exit"<<endl;
				cin>>ch;
				switch(ch){
					case 1:
						cout<<"User Data"<<endl;
						this->Read();
						break;
					case 2:
						cout<<"Export file in process"<<endl;
						this->Export();
						break;
					case 3:
						cout<<"have a good day!!"<<endl;
						break;
					default:
						cout<<"Wrong option selected"<<endl;
				}
			}
			break;
		}
		else
		{
			char ans;
			string out = (strcmp(user_n,this->username)==0) ? "The entered password doesn't match":"The username is incorrect";
			cout<<out<<endl;
			cout<<"You might want to consider registering(y/n): ";
			cin>>ans;
			if(ans=='y'||ans=='Y'){
				this->register_admin();
			}
			else{
				cout<<"Allright see ya!"<<endl;
			}
			break;
		}
	}
	fin.close();
}

void Login_admin::Export()
{
	ifstream fin("login_data.txt",ios::in);
	ofstream fout("Login_data.csv",ios::out);
	fout<<"USERNAME"<<","<<"PASSWORD"<<endl;
	while(fin>>username>>password)
	{
		fout<<username<<","<<password<<endl;
	}
	fin.close();
	fout.close();
}

void Login :: Register()
{
	ofstream fout("login_data.txt",ios::app);
	cout<<"Enter username(mail): ";
	cin>>username;
	cout<<"Enter your preferred password: ";
	cin>>password;
	fout<<username<<" "<<password<<endl;
	fout.close();
}

void Login :: login(char user_n[], char pass[])
{
	ifstream fin("login_data.txt",ios::in);
	while(fin>>username>>password)
	{
		if(strcmp(user_n,this->username)==0 && strcmp(pass,this->password)==0)
		{
			cout<<"Welcome back "<<username<<endl;
			break;
		}
		else
		{
			char ans;
			string out = (strcmp(user_n,this->username)==0) ? "The entered password doesn't match":"The username is incorrect";
			cout<<out<<endl;
			cout<<"You might want to consider registering(y/n): ";
			cin>>ans;
			if(ans=='y'||ans=='Y'){
				this->Register();
			}
			else{
				cout<<"Allright see ya!"<<endl;
			}
			break;
		}
	}
	fin.close();
}

/*int main()
{
	Login l1;Login_admin la1;
    while(1)
    {
	    system("cls");
	    char username[100],password[50];
	    unsigned int ch;
	    cout<<" ********  Welcome to Car Rental System *********";
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
	        		la1.Read();
	        	break;
	        case 4:
	        		la1.Export();
	        		cout<<"File has been made in the folder"<<endl;
	        	break;
	        case 5:
	            exit(1);
	    }
	    cout<<"Press anything to proceed: ";
	    getch();
  }
}*/

int str_len(char c[])
{
	int length=0;
	while(c[length]!='\0')
	{
		length++;
	}
	return length;
}

string conv_to_str(char* a,int size)
{
	int i;
	string s = "";
	for(i=0;i<size;i++)
	{
		s = s + a[i];
	}
	return s;
}

int isSubstring(string s1, string s2) 
{ 
    int M = s1.length(); 
    int N = s2.length(); 
    for (int i = 0; i <= N - M; i++) { // A loop to slide pat[] one by one
        int j; 
        for (j = 0; j < M; j++) //For current index i, check for pattern match
            if (s2[i + j] != s1[j]) 
                break; 
        if (j == M) 
            return i; 
    } 
    return -1;
} 

int main()
{
	Login l;
	Login_admin la;
	char username[100],password[50];
	cout<<"\t\tLogin"<<endl;
	cout<<"\t\tUsername - ";
	cin>>username;
	cout<<"\t\tPassword - ";
	cin>>password;
	string user = conv_to_str(username,str_len(username));
	//cout<<"Converted string = "<<user<<endl;
	//cout<<"Function result = "<<isSubstring("admin",user)<<endl;
	if(isSubstring("admin",user)!=-1)
	{
		la.login_admin(username,password);
	}
	else{
		l.login(username,password);
	}

}

#include<iostream>
#include<sstream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include "selection.h"

class Cars
{
	protected:
		char name[100];
		int ID;
		char booked; // y or n
		char type[5];
	public:
		void getdata();
		void putdata();
		void modify();
		void Export();
		int get_ID(){
			return ID;
		}
}c;

class Login{
	protected:
		char username[100];
		char password[50];
};

class Login_user:public Login{
	public:
		void Register();
		void login(char user_n[], char pass[]);
		void show_cars();
		void book();
};

class Login_admin:public Login{
	public:
		void login_admin(char user_n[],char pass[]);
		void register_admin();
		void Export_user_data();
		void Read();
		//this is file class in original code
		void display();
		void search();
		void delete_c();
		void Export();
		void modify();
		void add();
		void do_work();
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************CAR CLASS FUNCTIONS****************************************************/
void Cars::getdata()
{
	cout<<"Enter name of car: ";
	scanf(" %[^\n]s",name);
	cout<<"Enter ID of the car: ";
	cin>>ID;
	cout<<"Booked status: ";
	cin>>booked;
	cout<<"Type of car: "; // hb = hatchback se = sedan lux = luxury suv = SUV
	cin>>type;
}

void Cars::putdata()
{
	cout<<"Car - "<<name<<endl;
	cout<<"ID - "<<ID<<endl;
	cout<<"booked? - "<<booked<<endl;
	cout<<"CarType - "<<type<<endl;
}
void Cars::modify() //function to modify the records
{
	int ch;
	cout<<"Current details are"<<endl;
	this->putdata();
	cout<<"Modify:\n 1.Name\n 2.ID\n 3.Booked?\n 4.Type\n 5.All\n Your choie: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Enter new name of the Car: ";
			cin>>this->name;
			break;
		case 2:
			cout<<"Enter new ID: ";
			cin>>this->ID;
			break;
		case 3:
			cout<<"Booking status?: ";
			cin>>this->booked;
			break;
		case 4:
			cout<<"Car-Type: ";
			cin>>this->type;
			break;
		case 5:
			this->getdata();
			break;
		default:
			cout<<"Wrong option selected, refer menu"<<endl;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**********************************************LOGIN ADMIN CODES****************************************************/
void Login_admin::add(){
	char ch='y';
	ofstream fout("cars.dat",ios::out|ios::app);
	while(ch=='y'|ch=='Y')
	{
		c.getdata();
		fout.write((char*)&c,sizeof(c));
		cout<<"\nDo you wish to add more(y/n): ";
		cin>>ch;
	}
	cout<<"\nData added to file\n"<<endl;
	fout.close();
}

void Login_admin::display()
{
	ifstream fin("cars.dat",ios::in);
	while(fin.read((char*)&c,sizeof(c)))
	{
		c.putdata();
		cout<<endl; 
	}
	fin.close();
}

void Login_admin::Export()
{
	char cn[100],bkd,type[5];
	int id;
	ifstream fin("cars.dat",ios::in);
	ofstream fout("cars.csv");
	while(fin>>cn>>id>>bkd>>type)
	{
		fout<<cn<<","<<id<<","<<bkd<<","<<type<<endl;
	}
	fin.close();
	fout.close();
}
void Login_admin::search()
{
	ifstream fin("cars.dat",ios::in);
	int rno,i=0;
	char found = 'n';
	cout<<"\nEnter the ID to be searched: ";
	cin>>rno;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==rno)
		{
			cout<<"Found at position "<<i+1<<endl;
			c.putdata();
			found = 'y';
		}
		i++;
	}
	if(found=='n')
		cout<<"\nCar of ID "<<rno<<"is not in the file.\n";
	fin.close();
}

void Login_admin::modify() //fuction to modify the records of file
{
	fstream fio("cars.dat",ios::in|ios::out);
	int rno;
	char found = 'n';
	fio.seekg(0);
	cout<<"\nEnter the ID of the Car: ";
	cin>>rno;
	while(1)
	{
		int loc = fio.tellg(); //storing the current location in loc
		fio.read((char*)&c,sizeof(c));
		if(c.get_ID()==rno)
		{
			c.modify(); //call to modify function
			found = 'y';
			fio.seekg(loc); //moving the pointer to current location
			fio.write((char*)&c,sizeof(c));
			cout<<"\nYour record of Roll No. "<<rno<<" has been updated"<<endl;
			break;
		}
	}
		if(found=='n')
			cout<<"\nThe Roll no "<<rno<<"is not in the Login_admin.\n";
	fio.close();
}


void Login_admin::delete_c() //function to delete the records of file
{
	int rno;
	char found ='n';
	fstream fio("cars.dat",ios::in|ios::out|ios::app);
	ofstream fout("temp.dat",ios::out|ios::app);
	ofstream out("trash.dat",ios::out|ios::app);
	cout<<"Enter ID of car to delete: ";
	cin>>rno;
	while(fio.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==rno)
		{
			out.write((char*)&c,sizeof(c)); //wiriting in trash Login_admin
			found = 'y';
		}
		else{
			fout.write((char*)&c,sizeof(c)); //writing to temp file
		}
	}
	if(found=='n')
		cout<<"\nThe ID "<<rno<<"is not in the Login_admin.\n";
	else
		cout<<"Record successfully deleted"<<endl;
	fio.close();
	fout.close();
	remove("cars.dat");
	rename("temp.dat","cars.dat"); //renaming the file 
	}

void Login_admin::do_work()
{
	int ch,op;
	do{
		cout<<"\nChoose option \n 1.Add Data \n 2.Display Data \n 3.Search Data \n 4.Modify Data \n 5.Delete Data\n 6.To see all the users\n 7.Export\n 8.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Add Car Data\n";
				this->add();
				break;
			case 2:
				cout<<"Display Record\n";
				this->display();
				break;
			case 3:
				cout<<"Search Record\n";
				this->search();
				break;
			case 4:
				cout<<"Modify Record\n";
				this->modify();
				break;
			case 5:
				cout<<"Delete Record\n";
				this->delete_c();
				break;
			case 6:
				cout<<"User Data"<<endl;
				this->Read();
				break;
			case 7:
				cout<<"Export file in process"<<endl;
				this->Export_user_data();
				break;
			case 8:
				cout<<"Thank You for using the program :)"<<endl;
				break;
			default:
				cout<<"Wrong choice\n";
		}
	}while(ch!=6);
	return;
}
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
			this->do_work();
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

void Login_admin::Export_user_data()
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/****************************************** LOGIN USER CODES **************************************************/
void Login_user :: Register()
{
	ofstream fout("login_data.txt",ios::app);
	cout<<"Enter username(mail): ";
	cin>>username;
	cout<<"Enter your preferred password: ";
	cin>>password;
	fout<<username<<" "<<password<<endl;
	fout.close();
}

//void Login_user::


void Login_user :: login(char user_n[], char pass[])
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
///////////////////////////////////////////////////////////////////////////////////////////
/******************************* STRING OPERATIONS **************************************/
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
////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	Login_user l;
	Login_admin la;
	char username[100],password[50];
	cout<<"\t\tLogin"<<endl;
	cout<<"\t\tUsername - ";
	cin>>username;
	cout<<"\t\tPassword - ";
	cin>>password;
	string user = conv_to_str(username,str_len(username));
	if(isSubstring("admin",user)!=-1)
	{
		la.login_admin(username,password);
	}
	else{
		l.login(username,password);
	}
}

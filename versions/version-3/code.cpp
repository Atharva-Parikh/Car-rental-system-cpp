#include<iostream>
#include<sstream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class Cars
{
	protected:
		char name[100];
		int ID;  //format 6 bit binary
		bool booked; // 1 or 0
	public:
		void getdata();
		void putdata();
		void modify();
		void Export();
		bool booked_status(){
			return booked;
		}
		int get_ID(){
			return ID;
		}
		char* get_name(){
			return name;
		}
		void bookit(){
			this->booked = 1;
			//return booked;
		}
		void unbookit(){
			this->booked = 0;			
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
		//display available cars
		void show_hatchback();
		void show_sedan();
		void show_suv();
		void show_luxury();
		//book the available cars
		void book_hatchback();
		void book_sedan();
		void book_suv();
		void book_luxury();
		//do work function
		void do_user_work();
		void unbook();
};

class Login_admin:public Login{
	public:
		void login_admin(char user_n[],char pass[]);
		//void register_admin();
		void Export_user_data();
		void Read_user_data();
		//this is file class in original code
		void search_car();
		void delete_c();
		void Export();
		void modify_car();
		void add_car_hatchback();
		void add_car_luxury();
		void add_car_sedan();
		void add_car_suv();
		//display versions
		void display_car_hatchback();
		void display_car_luxury();
		void display_car_sedan();
		void display_car_suv();
		//do work function
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
	cout<<"Booked status(1 for yes/0 for no): ";
	cin>>booked;
}

void Cars::putdata()
{
	cout<<"Car - "<<name<<endl;
	cout<<"ID - "<<ID<<endl;
	cout<<"booked? - "<<booked<<endl;
}
void Cars::modify() //function to modify the records
{
	int ch;
	cout<<"Current details are"<<endl;
	this->putdata();
	cout<<"Modify:\n 1.Name\n 2.ID\n 3.Booked?\n 4.All\n Your choie: ";
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
			cout<<"Booking status?(1 for yes/0 for no): ";
			cin>>this->booked;
			break;
		case 4:
			this->getdata();
			break;
		default:
			cout<<"Wrong option selected, refer menu"<<endl;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**********************************************LOGIN ADMIN CODES****************************************************/

void Login_admin::login_admin(char user_n[], char pass[])
{
	int ch = 0;
	ifstream fin("admin_data.txt",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No admin Data Available!"<<endl;
		fin.close();
		return;
	}
	else{
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
				cout<<"Try again"<<endl;
				/*cout<<"You might want to consider registering(y/n): ";
				cin>>ans;
				if(ans=='y'||ans=='Y'){
					this->register_admin();
				}
				else{
					cout<<"Allright see ya!"<<endl;
				}*/
				break;
			}
		}
	}
	fin.close();
}


/*void Login_admin :: register_admin()
{
	ofstream fout("admin_data.txt",ios::app);
	cout<<"Enter username(mail): ";
	cin>>username;
	cout<<"Enter your preferred password: ";
	cin>>password;
	fout<<username<<" "<<password<<endl;
	fout.close();
}*/

void Login_admin::Read_user_data()
{
	ifstream fin("login_data.txt",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No User Data Available!"<<endl;
		fin.close();
		return;
	}
	while(fin>>username>>password)
	{
		cout<<"Username - "<<username<<"\n"<<"Password - "<<password<<"\n"<<endl;
	}
	fin.close();
}


void Login_admin::Export_user_data()
{
	ifstream fin("login_data.txt",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No User Data Available!"<<endl;
		fin.close();
		return;
	}
	ofstream fout("Login_data.csv",ios::out);
	fout<<"USERNAME"<<","<<"PASSWORD"<<endl;
	while(fin>>username>>password)
	{
		fout<<username<<","<<password<<endl;
	}
	fin.close();
	fout.close();
}


void Login_admin::add_car_hatchback(){
	char ch='y';
	ofstream fout("HATCHBACK.dat",ios::out|ios::app);
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

void Login_admin::add_car_luxury(){
	char ch='y';
	ofstream fout("LUXURY.dat",ios::out|ios::app);
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

void Login_admin::add_car_sedan(){
	char ch='y';
	ofstream fout("SEDAN.dat",ios::out|ios::app);
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

void Login_admin::add_car_suv(){
	char ch='y';
	ofstream fout("SUV.dat",ios::out|ios::app);
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

void Login_admin::display_car_hatchback()
{
	ifstream fin("HATCHBACK.dat",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No HATCHBACK Data Available!"<<endl;
		fin.close();
		return;
	}
	while(fin.read((char*)&c,sizeof(c)))
	{
		c.putdata();
		cout<<endl; 
	}
	fin.close();
}

void Login_admin::display_car_luxury()
{
	ifstream fin("LUXURY.dat",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No LUXURY Data Available!"<<endl;
		fin.close();
		return;
	}
	while(fin.read((char*)&c,sizeof(c)))
	{
		c.putdata();
		cout<<endl; 
	}
	fin.close();
}

void Login_admin::display_car_sedan()
{
	ifstream fin("SEDAN.dat",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No SEDAN Data Available!"<<endl;
		fin.close();
		return;
	}
	while(fin.read((char*)&c,sizeof(c)))
	{
		c.putdata();
		cout<<endl; 
	}
	fin.close();
}

void Login_admin::display_car_suv()
{
	ifstream fin("SUV.dat",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No SUV Data Available!"<<endl;
		fin.close();
		return;
	}
	while(fin.read((char*)&c,sizeof(c)))
	{
		c.putdata();
		cout<<endl; 
	}
	fin.close();
}


void Login_admin::Export()
{	
	ofstream fout("cars.csv");
	//writing hatchback file to excel cars file
	ifstream fin1("HATCHBACK.dat",ios::in); //open hatchback
	fout<<"HATCHBACK"<<endl;
	while(fin1.read((char*)&c,sizeof(c)))
	{
		fout<<c.get_name()<<","<<c.get_ID()<<","<<c.booked_status()<<endl;
	}
	fin1.close();//close hatchback
	
	//writing hatchback file to excel cars file
	ifstream fin2("SEDAN.dat",ios::in); //open hatchback
	fout<<"SEDAN"<<endl;
	while(fin2.read((char*)&c,sizeof(c)))
	{
		fout<<c.get_name()<<","<<c.get_ID()<<","<<c.booked_status()<<endl;
	}
	fin2.close();//close hatchback
	
	//writing hatchback file to excel cars file
	ifstream fin3("HATCHBACK.dat",ios::in); //open hatchback
	fout<<"HATCHBACK"<<endl;
	while(fin3.read((char*)&c,sizeof(c)))
	{
		fout<<c.get_name()<<","<<c.get_ID()<<","<<c.booked_status()<<endl;
	}
	fin3.close();//close hatchback
	
	//writing hatchback file to excel cars file
	ifstream fin4("HATCHBACK.dat",ios::in); //open hatchback
	fout<<"HATCHBACK"<<endl;
	while(fin4.read((char*)&c,sizeof(c)))
	{
		fout<<c.get_name()<<","<<c.get_ID()<<","<<c.booked_status()<<endl;
	}
	fin4.close();//close hatchback
	fout.close();//close the excel file
}


void Login_admin::search_car()
{
	int entered_id;
	char found  = 'n';
	cout<<"\nEnter the ID to be searched: ";
	cin>>entered_id;
	//searching the hatchback file
	ifstream fin1("HATCHBACK.dat",ios::in);
	while(fin1.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==entered_id)
		{
			c.putdata();
			found = 'y';
		}
	}
	fin1.close();
	if(found =='y'){return;}
	
	//searching the sedan file
	ifstream fin2("SEDAN.dat",ios::in);
	while(fin2.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==entered_id)
		{
			c.putdata();
			found = 'y';
		}
	}
	fin2.close();
	if(found =='y'){return;}
	
	//searching the suv file
	ifstream fin3("SUV.dat",ios::in);
	while(fin3.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==entered_id)
		{
			c.putdata();
			found = 'y';
		}
	}
	fin3.close();
	if(found =='y'){return;}
	
	//searching the luxury file
	ifstream fin4("LUXURY.dat",ios::in);
	while(fin4.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==entered_id)
		{
			c.putdata();
			found = 'y';
		}
	}
	if(found =='n'){cout<<"\nCar of ID "<<entered_id<<"is not in the file.\n";}
	fin4.close();
	return;
}


void Login_admin::modify_car() //fuction to modify the records of file
{
	int entered_id;
	char found  = 'n';
	cout<<"\nEnter the ID to be searched: ";
	cin>>entered_id;
	
	//searching and modifying the hatchback file
	fstream fio1("HATCHBACK.dat",ios::in);
	fio1.seekg(0);
	while(1)
	{
		int loc = fio1.tellg(); //storing the current location in loc
		fio1.read((char*)&c,sizeof(c));
		if(c.get_ID()==entered_id)
		{
			c.modify();
			found = 'y';
			fio1.seekg(loc); //moving the pointer to current location
			fio1.write((char*)&c,sizeof(c));
			cout<<"\nYour record of ID "<<entered_id<<" has been updated"<<endl;
			break;
		}
	}
	fio1.close();
	if(found =='y'){return;}
	
	//searching and modifying the sedan file
	fstream fio2("SEDAN.dat",ios::in);
	fio1.seekg(0);
	while(1)
	{
		int loc = fio2.tellg(); //storing the current location in loc
		fio2.read((char*)&c,sizeof(c));
		if(c.get_ID()==entered_id)
		{
			c.modify();
			found = 'y';
			fio2.seekg(loc); //moving the pointer to current location
			fio2.write((char*)&c,sizeof(c));
			cout<<"\nYour record of ID "<<entered_id<<" has been updated"<<endl;
			break;
		}
	}
	fio2.close();
	if(found =='y'){return;}
	
	//searching and modifying the suv file
	fstream fio3("SUV.dat",ios::in);
	fio3.seekg(0);
	while(1)
	{
		int loc = fio3.tellg(); //storing the current location in loc
		fio3.read((char*)&c,sizeof(c));
		if(c.get_ID()==entered_id)
		{
			c.modify();
			found = 'y';
			fio3.seekg(loc); //moving the pointer to current location
			fio3.write((char*)&c,sizeof(c));
			cout<<"\nYour record of ID "<<entered_id<<" has been updated"<<endl;
			break;
		}
	}
	fio3.close();
	if(found =='y'){return;}
	
	//searching and modifying the hatchback file
	fstream fio4("LUXURY.dat",ios::in);
	fio4.seekg(0);
	while(1)
	{
		int loc = fio4.tellg(); //storing the current location in loc
		fio4.read((char*)&c,sizeof(c));
		if(c.get_ID()==entered_id)
		{
			c.modify();
			found = 'y';
			fio4.seekg(loc); //moving the pointer to current location
			fio4.write((char*)&c,sizeof(c));
			cout<<"\nYour record of ID "<<entered_id<<" has been updated"<<endl;
			break;
		}
	}
	fio4.close();
	if(found =='n'){cout<<"\nCar of ID "<<entered_id<<"is not in the file.\n";}
	return;
}


void Login_admin::delete_c() //function to delete the records of file
{	
	int entered_id;
	char found  = 'n';
	cout<<"\nEnter the ID to be deleted: ";
	cin>>entered_id;
	
	fstream fio1("HATCHBACK.dat",ios::in|ios::out|ios::app);
	ofstream fout1("temp1.dat",ios::out|ios::app);
	//ofstream out("trash.dat",ios::out|ios::app);
	while(fio1.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==entered_id)
		{
			//out.write((char*)&c,sizeof(c)); //wiriting in trash Login_admin
			found = 'y';
		}
		else{
			fout1.write((char*)&c,sizeof(c)); //writing to temp file
		}
	}
	fio1.close();
	fout1.close();
	remove("HATCHBACK.dat");
	rename("temp1.dat","HATCHBACK.dat");
	if(found=='y'){
		cout<<"Record successfully deleted"<<endl;
		return;
	}
	
	
	fstream fio2("SEDAN.dat",ios::in|ios::out|ios::app);
	ofstream fout2("temp2.dat",ios::out|ios::app);
	//ofstream out("trash.dat",ios::out|ios::app);
	while(fio2.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==entered_id)
		{
			//out.write((char*)&c,sizeof(c)); //wiriting in trash Login_admin
			found = 'y';
		}
		else{
			fout2.write((char*)&c,sizeof(c)); //writing to temp file
		}
	}	
	fio2.close();
	fout2.close();
	remove("SEDAN.dat");
	rename("temp2.dat","SEDAN.dat");
	if(found=='y'){
		cout<<"Record successfully deleted"<<endl;
		return;
	}
	
	fstream fio3("SUV.dat",ios::in|ios::out|ios::app);
	ofstream fout3("temp3.dat",ios::out|ios::app);
	//ofstream out("trash.dat",ios::out|ios::app);
	while(fio3.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==entered_id)
		{
			//out.write((char*)&c,sizeof(c)); //wiriting in trash Login_admin
			found = 'y';
		}
		else{
			fout3.write((char*)&c,sizeof(c)); //writing to temp file
		}
	}
	fio3.close();
	fout3.close();
	remove("SUV.dat");
	rename("temp3.dat","SUV.dat");
	if(found=='y'){
		cout<<"Record successfully deleted"<<endl;
		return;
	}
	
	fstream fio4("LUXURY.dat",ios::in|ios::out|ios::app);
	ofstream fout4("temp4.dat",ios::out|ios::app);
	//ofstream out("trash.dat",ios::out|ios::app);
	while(fio4.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==entered_id)
		{
			//out.write((char*)&c,sizeof(c)); //wiriting in trash Login_admin
			found = 'y';
		}
		else{
			fout4.write((char*)&c,sizeof(c)); //writing to temp file
		}
	}
	fio4.close();
	fout4.close();
	remove("LUXURY.dat");
	rename("temp4.dat","LUXURY.dat");
	if(found=='y'){
		cout<<"Record successfully deleted"<<endl;
		return;
	}
	else{
		cout<<"Record not found"<<endl;
	}
}

void Login_admin::do_work()
{
	int ch,op;
	int choose;
	do{
		cout<<"\nChoose option \n 1.Add Data \n 2.Display Data \n 3.Search Data \n 4.Modify Data \n 5.Delete Data\n 6.Export Car data\n 7.To see all the users\n 8.Export user data\n 9.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Add Car Data\n";
				cout<<"Enter\n 1.Hatchback\n 2.Sedan\n 3.SUV\n 4.Luxury\n Your choice: ";
				cin>>choose;
				switch(choose)
				{
					case 1:
						this->add_car_hatchback();
						break;
					case 2:
						this->add_car_sedan();
						break;
					case 3:
						this->add_car_suv();
						break;
					case 4:
						this->add_car_luxury();
						break;
					default:
						cout<<"Wrong option selected"<<endl;
				}
				break;
			case 2:
				choose = 0;
				cout<<"Display Record\n";
				cout<<"Enter\n 1.Hatchback\n 2.Sedan\n 3.SUV\n 4.Luxury\n 5.All\n Your choice: ";
				cin>>choose;
				switch(choose)
				{
					case 1:
						this->display_car_hatchback();
						break;
					case 2:
						this->display_car_sedan();
						break;
					case 3:
						this->display_car_suv();
						break;
					case 4:
						this->display_car_luxury();
						break;
					case 5:
						this->display_car_hatchback();
						this->display_car_sedan();
						this->display_car_suv();
						this->display_car_luxury();
					default:
						cout<<"Wrong option selected"<<endl;
				}
				break;
			case 3:
				cout<<"Search Record\n";
				this->search_car();
				break;
			case 4:
				cout<<"Modify Record\n";
				this->modify_car();
				break;
			case 5:
				cout<<"Delete Record\n";
				this->delete_c();
				break;
			case 6:
				cout<<"Export car data in process"<<endl;
				this->Export();
				break;
			case 7:
				cout<<"User Data"<<endl;
				this->Read_user_data();
				break;
			case 8:
				cout<<"Export file in process"<<endl;
				this->Export_user_data();
				break;
			case 9:
				cout<<"Thank You for using the program :)"<<endl;
				break;
			default:
				cout<<"Wrong choice\n";
		}
	}while(ch!=9);
	return;
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

void Login_user :: show_hatchback()
{
	ifstream fin("HATCHBACK.dat",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No HATCHBACK Data Available!"<<endl;
		fin.close();
		return;
	}
	cout<<"Available hatchback cars are"<<endl;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(c.booked_status()==0){
			c.putdata();
		}
	}
	fin.seekg(0,ios::beg);
	cout<<"\nUnvailable hatchback cars are"<<endl;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(c.booked_status()==1){
			c.putdata();
		}
	}
	fin.close();
}


void Login_user :: show_sedan()
{
	ifstream fin("SEDAN.dat",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No SEDAN Data Available!"<<endl;
		fin.close();
		return;
	}
	cout<<"Available SEDAN cars are"<<endl;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(c.booked_status()==0){
			c.putdata();
		}
	}
	fin.seekg(0,ios::beg);
	cout<<"\nUnvailable SEDAN cars are"<<endl;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(c.booked_status()==1){
			c.putdata();
		}
	}
	fin.close();
}

void Login_user :: show_suv()
{
	ifstream fin("SUV.dat",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No SUV Data Available!"<<endl;
		fin.close();
		return;
	}
	cout<<"Available SUV cars are"<<endl;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(c.booked_status()==0){
			c.putdata();
		}
	}
	fin.seekg(0,ios::beg);
	cout<<"\nUnvailable SUV cars are"<<endl;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(c.booked_status()==1){
			c.putdata();
		}
	}
	fin.close();
}

void Login_user :: show_luxury()
{
	ifstream fin("LUXURY.dat",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No LUXURY Data Available!"<<endl;
		fin.close();
		return;
	}
	cout<<"Available LUXURY cars are"<<endl;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(c.booked_status()==0){
			c.putdata();
		}
	}
	fin.seekg(0,ios::beg);
	cout<<"\nUnvailable LUXURY cars are"<<endl;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(c.booked_status()==1){
			c.putdata();
		}
	}
	fin.close();
}

void Login_user :: book_hatchback()
{
	int car_to_book;
	char found = 'n';
	cout<<"Enter the ID of car to book: ";
	cin>>car_to_book;
	fstream fio("HATCHBACK.dat",ios::in|ios::out);
	fio.seekg(0);
	while(1)
	{
		int loc = fio.tellg(); 
		fio.read((char*)&c,sizeof(c));
		if(c.get_ID() == car_to_book){
			c.bookit();
			found = 'y';
			fio.seekg(loc);
			fio.write((char*)&c,sizeof(c));
			break;
		}
	}
	fio.close();
	if(found=='n'){
		cout<<"Not Available!"<<endl;
		return;
	}
	else if(found == 'y'){
		//invoice function
		cout<<"Thank You for Booking!"<<endl;
		return;
	}
}

void Login_user :: book_sedan()
{
	int car_to_book;
	char found = 'n';
	cout<<"Enter the ID of car to book: ";
	cin>>car_to_book;
	fstream fio("SEDAN.dat",ios::in|ios::out);
	fio.seekg(0);
	while(1)
	{
		int loc = fio.tellg(); 
		fio.read((char*)&c,sizeof(c));
		if(c.get_ID() == car_to_book){
			c.bookit();
			found = 'y';
			fio.seekg(loc);
			fio.write((char*)&c,sizeof(c));
			break;
		}
	}
	fio.close();
	if(found=='n'){
		cout<<"Not Available!"<<endl;
		return;
	}
	else if(found == 'y'){
		//invoice function
		cout<<"Thank You for Booking!"<<endl;
		return;
	}
}

void Login_user :: book_suv()
{
	int car_to_book;
	char found = 'n';
	cout<<"Enter the ID of car to book: ";
	cin>>car_to_book;
	fstream fio("SUV.dat",ios::in|ios::out);
	fio.seekg(0);
	while(1)
	{
		int loc = fio.tellg(); 
		fio.read((char*)&c,sizeof(c));
		if(c.get_ID() == car_to_book){
			c.bookit();
			found = 'y';
			fio.seekg(loc);
			fio.write((char*)&c,sizeof(c));
			break;
		}
	}
	fio.close();
	if(found=='n'){
		cout<<"Not Available!"<<endl;
		return;
	}
	else if(found == 'y'){
		//invoice function
		cout<<"Thank You for Booking!"<<endl;
		return;
	}
}

void Login_user :: book_luxury()
{
	int car_to_book;
	char found = 'n';
	cout<<"Enter the ID of car to book: ";
	cin>>car_to_book;
	fstream fio("LUXURY.dat",ios::in|ios::out);
	fio.seekg(0);
	while(1)
	{
		int loc = fio.tellg(); 
		fio.read((char*)&c,sizeof(c));
		if(c.get_ID() == car_to_book){
			c.bookit();
			found = 'y';
			fio.seekg(loc);
			fio.write((char*)&c,sizeof(c));
			break;
		}
	}
	fio.close();
	if(found=='n'){
		cout<<"Not Available!"<<endl;
		return;
	}
	else if(found == 'y'){
		//invoice function
		cout<<"Thank You for Booking!"<<endl;
		return;
	}
}


void Login_user::unbook()
{
	int id_car;
	cout<<"Enter the ID of car you want to submit: ";
	cin>>id_car;
	char found = 'n';
	fstream fio1("HATCHBACK.dat",ios::in|ios::out);
	fio1.seekg(0);
	while(1)
	{
		int loc = fio1.tellg(); 
		fio1.read((char*)&c,sizeof(c));
		if(c.get_ID() == id_car){
			c.unbookit();
			found = 'y';
			fio1.seekg(loc);
			fio1.write((char*)&c,sizeof(c));
			break;
		}
	}
	fio1.close();
	if(found == 'y'){
		cout<<"Hope You liked the Hatchback :)"<<endl;
		cout<<"Thank You for using our services!!"<<endl;
		return;
	}
	
	fstream fio2("SEDAN.dat",ios::in|ios::out);
	fio2.seekg(0);
	while(1)
	{
		int loc = fio2.tellg(); 
		fio2.read((char*)&c,sizeof(c));
		if(c.get_ID() == id_car){
			c.unbookit();
			found = 'y';
			fio2.seekg(loc);
			fio2.write((char*)&c,sizeof(c));
			break;
		}
	}
	fio2.close();
	if(found == 'y'){
		cout<<"Hope You liked the Sedan :)"<<endl;
		cout<<"Thank You for using our services!!"<<endl;
		return;
	}
	
	fstream fio3("SUV.dat",ios::in|ios::out);
	fio3.seekg(0);
	while(1)
	{
		int loc = fio3.tellg(); 
		fio3.read((char*)&c,sizeof(c));
		if(c.get_ID() == id_car){
			c.unbookit();
			found = 'y';
			fio3.seekg(loc);
			fio3.write((char*)&c,sizeof(c));
			break;
		}
	}
	fio3.close();
	if(found == 'y'){
		cout<<"Hope You liked the Suv :)"<<endl;
		cout<<"Thank You for using our services!!"<<endl;
		return;
	}
	
	fstream fio4("HATCHBACK.dat",ios::in|ios::out);
	fio4.seekg(0);
	while(1)
	{
		int loc = fio4.tellg(); 
		fio4.read((char*)&c,sizeof(c));
		if(c.get_ID() == id_car){
			c.unbookit();
			found = 'y';
			fio4.seekg(loc);
			fio4.write((char*)&c,sizeof(c));
			break;
		}
	}
	fio4.close();
	if(found == 'y'){
		cout<<"Hope You liked the Luxury :)"<<endl;
		cout<<"Thank You for using our services!!"<<endl;
		return;
	}
	else if(found == 'n')
	{
		cout<<"OOPS! The Car you are submitting does not belong to us!!"<<endl;
	}
}

void Login_user :: do_user_work()
{
	int choice;
	cout<<"Menu\n 1.Book a car\n 2.Submit the car\n Your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			int ch;
			cout<<"Booking Point\n 1.Hatchback\n 2.Sedan\n 3.Suv\n 4.Luxury\n Your Choice: ";
			cin>>ch;
			switch(ch)
			{
				case 1:
					this->show_hatchback();
					this->book_hatchback();
					break;
				case 2:
					this->show_sedan();
					this->book_sedan();
					break;
				case 3:
					this->show_suv();
					this->book_suv();
					break;
				case 4:
					this->show_luxury();
					this->book_suv();
					break;
				default:
					cout<<"Seems You selected wrong option"<<endl;
			}
			break;
		case 2:
			this->unbook();
			break;
	}
	
}

void Login_user :: login(char user_n[], char pass[])
{
	ifstream fin("login_data.txt",ios::in);
	while(fin>>username>>password)
	{
		if(strcmp(user_n,this->username)==0 && strcmp(pass,this->password)==0)
		{
			cout<<"Welcome back "<<username<<endl;
			do_user_work();
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
				break;
			}
			else{
				cout<<"Allright see ya!"<<endl;
				break;
			}
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
/******************************** MAIN PROGRAM ***********************************************/
int main()
{
	Login_user l;
	Login_admin la;
	char username[100],password[50];
	int choosing;
	string user;
	string line;
	ifstream fin("decorate.txt");
	while(getline(fin,line))
	{
		cout<<line<<endl;
	}
	do{
		cout<<"\nEnter:\n 1.Login\n 2.User Registeration\n 3.Exit Program\n Your Choice: ";
		cin>>choosing;
		switch(choosing)
	{
		case 1: //login function will seperate the user and admin.
			system("cls");
			cout<<"------------------------------------------------------------"<<endl;
			cout<<"\t\t\tLogin"<<endl;
			cout<<"------------------------------------------------------------"<<endl;
			cout<<"\n\tUsername - ";
			cin>>username;
			cout<<"\tPassword - ";
			cin>>password;
			user = conv_to_str(username,str_len(username));
			if(isSubstring("@cadmin.ac.in",user)!=-1)
			{
				la.login_admin(username,password);
				choosing = 3;
			}
			else{
				l.login(username,password);
				choosing = 3;
			}
			break;
		case 2: //user registeration
			l.Register();
			cout<<"Thank You For Registering, We won't let you down!"<<endl;
			break;
		case 3:
			cout<<"Thank You for checking in, Have an Awesome Day!"<<endl;
			break;
		default:
			cout<<"Wrong option selected please refer menu"<<endl;
			exit(1);
	}
	}while(choosing!=3);
	return 0;
}

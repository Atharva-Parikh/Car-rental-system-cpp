#include<iostream>
#include<sstream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include "selection.h"
using namespace std;

class file{
	public:
		void add();
		void display();
		void search();
		void delete_c();
		void Export();
		void modify();
};

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

void file::add(){
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

void file::display()
{
	ifstream fin("cars.dat",ios::in);
	while(fin.read((char*)&c,sizeof(c)))
	{
		c.putdata();
		cout<<endl; 
	}
	fin.close();
}

void file::Export()
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
void file::search()
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

void file::modify() //fuction to modify the records of file
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
			cout<<"\nThe Roll no "<<rno<<"is not in the file.\n";
	fio.close();
}


void file::delete_c() //function to delete the records of file
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
			out.write((char*)&c,sizeof(c)); //wiriting in trash file
			found = 'y';
		}
		else{
			fout.write((char*)&c,sizeof(c)); //writing to temp file
		}
	}
	if(found=='n')
		cout<<"\nThe ID "<<rno<<"is not in the file.\n";
	else
		cout<<"Record successfully deleted"<<endl;
	fio.close();
	fout.close();
	remove("cars.dat");
	rename("temp.dat","cars.dat"); //renaming the file 
	}

void do_work()
{
	int ch,op;
	file f;
	Cars c;
	do{
		cout<<"\nChoose option \n 1.Add Data \n 2.Display Data \n 3.Search Data \n 4.Modify Data \n 5.Delete Data\n 6.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Add Car Data\n";
				f.add();
				break;
			case 2:
				cout<<"Display Record\n";
				f.display();
				break;
			case 3:
				cout<<"Search Record\n";
				f.search();
				break;
			case 4:
				cout<<"Modify Record\n";
				f.modify();
				break;
			case 5:
				cout<<"Delete Record\n";
				f.delete_c();
				break;
			case 6:
				cout<<"Thank You for using the program :)"<<endl;
				exit(1);
			default:
				cout<<"Wrong choice\n";
		}
	}while(ch!=6);
	return;
}
int main()
{
	do_work();
	return 0;
}

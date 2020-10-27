#include<iostream>
#include<sstream>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
class car
{
protected:
    char comp_nam[100];
    char model1[50];
    char model2[50];
    char model3[50];
    char model4[50];
    int n;
public:
    void getdata();
    void showdata();
    void selection();
};
void car::getdata()
{
    int n;
    ofstream fo("car_info.txt",ios::app);
    cout<<"Enter number of cars "<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    cout<<"Enter Car Name:"<<endl;
    cin>>comp_nam;
    cout<<"Enter M1 Name:"<<endl;
    cin>>model1;
    cout<<"Enter M2 Name:"<<endl;
     cin>>model2;
    cout<<"Enter M3 Name:"<<endl;
    cin>>model3;
    cout<<"Enter M4 Name:"<<endl;
     cin>>model4;

    fo<<comp_nam<<" "<<model1<<" "<<model2<<" "<<model3<<" "<<model4<<endl;
    }
    fo.close();


}
void car::showdata()
{
    int n;
    ifstream fin("car_info.txt",ios::in);
    while(fin>>comp_nam>>model1>>model2>>model3>>model4)
    {
        cout<<"car data"<<endl;
        cout<<"Companyname-"<<comp_nam<<"\n"<<"model1 --"<<model1<<"\n"<<"model2 --"<<model2<<"\n"<<"model3 --"<<model3<<"\n"<<"model4 --"<<model4<<endl;
    }
    fin.close();
}
int main()
{
	car l1;
  int c;

  cout<<"Enter exit condition\n";
  cin>>c;

do
    {

	    char comp_nam[100],model1[50],model2[50],model3[50],model4[50];
	    unsigned int ch;
	    cout<<" ***  Welcome to Car Rental System ****";
	    cout<<"\n 1.Enter data \n 2.Show Data"<<endl;
	    cout<<"Enter choice: ";
	    cin>>ch;
	    switch(ch)
	    {
	        case 1:

	           		l1.getdata();
	        	break;
	        case 2:
	                l1.showdata();
	        	break;
	        	case 3:
	            break;
	    }

	    cout<<"Press anything to proceed: ";

  } while(c!=3);
}

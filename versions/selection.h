#include<iostream>
using namespace std;
int select_car_hatchback()
{
	int choice;
	std::cout<<"SELECT:\n 1.FORD FIGO\n 2.MARUTI SWIFT\n 3.BALENO\n 4.MAHINDRA KUV 100\n";
	cout<<" 5.MARUTI RITZ\n 6.HYUNDAI 120 ELITE\n 7.JAZZ SMT 1.5 IDTEC\n 8.THE RAPTOR\n 9.GRAND I10\n Your Choice: ";
	switch(choice)
	{
		case 1:
			std::cout<<"You have selected FORD FIGO"<<std::endl;
			return 1;
		case 2:
			std::cout<<"You have selected MARUTI SWIFT"<<std::endl;
			return 2;
		case 3:
			std::cout<<"You have selected BALENO"<<std::endl;
			return 3;
		case 4:
			std::cout<<"You have selected MAHINDRA KUV 100"<<std::endl;
			return 4;
		case 5:
			std::cout<<"You have selected MARUTI RITZ"<<std::endl;
			return 5;
		case 6:
			std::cout<<"You have selected HYUNDAI 120 ELITE"<<std::endl;
			return 6;
		case 7:
			std::cout<<"You have selected JAZZ SMT 1.5 IDTEC"<<std::endl;
			return 7;
		case 8:
			std::cout<<"You have selected THE RAPTOR"<<std::endl;
			return 8;
		case 9:
			std::cout<<"You have selected GRAND I10"<<std::endl;
			return 9;
	}
}

int select_car_sedan()
{
	int choice;
	std::cout<<"SELECT:\n 1.HONDA AMAZE\n 2.HONDA CITY\n 3.MARUTI CIAZ\n 4.FORD ASPIRE\n";
	std::cout<<" 5.MARUTI CIAZ MT\n Your Choice: ";
	switch(choice)
	{
		case 1:
			std::cout<<"You have selected HONDA AMAZE"<<std::endl;
			return 10;
		case 2:
			std::cout<<"You have selected HONDA CITY"<<std::endl;
			return 11;
		case 3:
			std::cout<<"You have selected MARUTI CIAZ"<<std::endl;
			return 12;
		case 4:
			std::cout<<"You have selected FORD ASPIRE"<<std::endl;
			return 13;
		case 5:
			std::cout<<"You have selected MARUTI CIAZ MT"<<std::endl;
			return 14;
	}
}

int select_car_luxury()
{
	int choice;
	std::cout<<"SELECT:\n 1.MERCEDES GLA\n 2.AUDI Q3\n Your Choice: ";
	switch(choice)
	{
		case 1:
			std::cout<<"You have selected MERCEDES GLA"<<std::endl;
			return 15;
		case 2:
			std::cout<<"You have selected AUDI Q3"<<std::endl;
			return 16;
	}
}

int select_car_suv()
{
	int choice;
	std::cout<<"SELECT:\n 1.FORD ECOSPORT\n 2.MAHINDRA SCORPIO\n 3.MAHINDRA XUV\n 4.FORD ENDEAVOUR\n";
	std::cout<<" 5.HYUNDAI CRETA\n 6.TOYOTA FORTUNER\n Your Choice: ";
	switch(choice)
	{
		case 1:
			std::cout<<"You have selected FORD ECOSPORT"<<std::endl;
			return 17;
		case 2:
			std::cout<<"You have selected MAHINDRA SCORPIO"<<std::endl;
			return 18;
		case 3:
			std::cout<<"You have selected MAHINDRA XUV"<<std::endl;
			return 19;
		case 4:
			std::cout<<"You have selected FORD ENDEAVOUR"<<std::endl;
			return 20;
		case 5:
			std::cout<<"You have selected HYUNDAI CRETA"<<std::endl;
			return 21;
		case 6:
			std::cout<<"You have selected TOYOTA FORTUNER"<<std::endl;
			return 22;
	}
}

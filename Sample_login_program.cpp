//Sample login program:
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
using namespace std;
class Login
{
        /* File handling
        username
        password
        role   teacher, student admin    */
        protected:
            char username[50];
            char password[50];
            unsigned int role;
        public:
            void Register()
            {
               
                ofstream fs("logindata.txt",ios::app);   
                cout<<"Enter username: ";
                cin>>username;
                cout<<"Enter password: ";
                cin>>password;
                cout<<"Press 1. Student 2. Faculty 3. Admin"<<endl;
                cin>>role;
                fs<<username<<" "<<password<<" "<<role<<" ";   
                fs.close();
            }
            void login(char  un[],char pw[])
            {
                ifstream fs("logindata.txt",ios::in);
                while(!fs.eof())
                {
                fs>>username>>password>>role;   
               
                if(strcmp(un,this->username)==0 && strcmp(pw,this->password)==0)
                {
                    if(role==1)
                    {
                        cout<<"Welcome to student : "<<username;
                    }
                    else if(role==2)
                    {
                        cout<<"Welcome to faculty : "<<username;
                    }
                    else if(role==3)
                    {
                        cout<<"Welcome to admin : "<<username;
                    }
                }
           
                }
                fs.close();   
            }
};
int main()
{
   
    Login l1;
    while(1)
    {
    system("cls");
    char username[50],password[50];
    int ch;
    cout<<" ********  Welcome to SMS *********";
    cout<<"\n 1. Login \n 2. Register 3. Exit"<<endl;
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
  return 0;
}

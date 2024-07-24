#include<iostream>
#include<fstream>
 using namespace std;

class temp {
    string userName,Email,password;
    string searchName,searchEmail;
    fstream file;
    public:
    void login();
    void signUp();
    void forgot();
}obj;


 int main(){ 
    char choice;
    cout<<"\n1-login";
    cout<<"\n2-Sign-up";
    cout<<"\n3- Forget Password";
    cout<<"\n4- Exit";
    cout<<"\nEnter Your Choice ::";
    cin>>choice;
    switch(choice){ 
     case '1':
    obj.login();
     break;
     case '2':
    obj.signUp();
     break;
     case '3':
  obj.forgot();
     break;
     case '4':
   return 0;
    break;
    default :
    cout<<"Invalid Selection...";


    }

 }

 void temp ::signUp(){ 
    cout<<"\nEnter Your User Name ::"<<endl;
    getline(cin,userName);
    cout<<"Enter Your Email address ::"<<endl;
    getline(cin,Email);
    cout<<"Enter Your Password::"<<endl;
    getline(cin,password);

    file.open("loginData.txt",ios :: out | ios ::app);
    file<<userName<<"*"<<Email<<"*"<<password<<endl;
    file.close();

 }

 void temp :: login(){
    string searchName,searchPass;
    
    cout<<"---------------Login---------------"<<endl;
    cout<<"Enter Your User Name ::"<<endl;
    getline(cin,searchName);
    cout<<"Enter Your Password ::"<<endl;
    getline(cin,searchPass);

      file.open("loginData.txt",ios ::in);
      getline(file,userName,'*');
      getline(file,Email,'*');
      getline(file,password,'*');
      while(!file.eof()){ 
        if(userName==searchName){ 
            if(password==searchPass){ 
                cout<<"\nAccount Login Succesfull...|"<<endl;
                cout<<"\nUsername :: "<<userName<<endl;
                cout<<"\nEmail ::"<<Email<<endl;
            }else{
                cout<< "Password is Incorrect";
            }
        }
        getline(file,userName);
        getline(file,Email,'*');
        getline(file,password, '\n');
      }
      file.close();

 }

 void temp :: forgot(){ 
    cout<<"\nEnter Your Username";
    getline(cin,searchName);
    cout<<"\nEnter Your Email Address ::";
    getline(cin,searchEmail);

    file.open("loginData.txt",ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    while(!file.eof()){ 
        if(userName==searchName){
            if(Email==searchEmail){ 
               cout<<"\nAccount Found...";
               cout<<"Your Password is ::"<<password<<endl;
            }else{ cout<<"Not Found...\n";
            }
        }else{ 
            cout<<"Not Found...!\n";
        }
    }
    file.close();
 }
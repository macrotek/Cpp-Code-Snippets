#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;
bool IsloggedIn()
{
 string username,password,un,pw;
 cout<<"Enter username:- ";
 cin>>username;
 cout<<"Enter Password:- ";
 cin>>password;
 ifstream read("data\\"+username+".txt");
 getline(read,un);
 getline(read,pw);

 if (un == username && pw == password)
  {
	return true;
  }
 else
  {
	return false;
  }
};
int main()
{
	int choice;
	cout<<"1.Register\n2.Login\nYour choice: "<<endl;
	cin>>choice;
	if(choice == 1)
	{
	 string username,password;
	 cout<<"select a username:- ";
	 cin>>username;
	 cout<<"select a password:- ";
	 cin>>password;
	 ofstream file;
	 file.open("data\\"+username+".txt");
	 file<<username<<endl<<password;
	 file.close();
	 main();
	}
	else if(choice == 2)
	{
	 bool status;
	l1:
		status = IsloggedIn();
	 if(!status)
	{
	  cout<<"Invalid username or password!!!!!"<<endl<<"Please enter correct username and password"<<endl;
	  system("PAUSE");
	 goto l1;
	}
	else
	{l2:
	 {
int c;
cout<<"******Login successfull******"<<endl;

cout<<"\t*******Home*********"<<endl;
cout<<"1.Menu\n2.How to use\n3.Profile\n4.helpline\n5.logout\n";


cin >> c;
do{
switch(c)
{
case 1:
	cout<<"Menu"<<endl;
					
						{
						l3:
						{
						int ch;
						cout<<"\t*******Menu*********"<<endl;
						cout<<"1.Calculate your journey\n2.Past records of your journey\n3.Back to home\n";


						cin >> ch;
					        
						switch(ch)
						{
						 
							float a[1];
						case 1:
							cout<<"Calculate your journey"<<endl;

													
													{
												  int N, T; //N is speed (s+c) and T is distance
												  cout<<"Enter the input:- "<<endl; 
												  while (cin >> N >> T) 
												  {
												    double mn = -1e9, mx = 1e9;
												    vector<double> D(N), S(N);
												    for (int i = 0; i < N; i++)
												     { 
												      cin >> D[i] >> S[i];
												       mn = max(mn, -S[i]);
												     }

												    while (mx-mn > 1e-9) {
												      double c = (mx+mn)/2, t = 0.0;
												      for (int i = 0; i < N; i++) t += D[i] / (S[i] + c);
												      if (t > T) mn = c; 
												      else mx = c;
												    }
												     cout<<"The actual speed is:- "<<endl;
												     printf("%.9lf\n", (mx+mn)/2);
												     goto l3;
													 a[1] = (mx+mn)/2;
												  }
											
												
												{
													
													
													ofstream OFileObject; 
												    	OFileObject.open ("past.txt",ios::app);
													OFileObject <<"Past record of your journey is:- "<<a[1]<<endl<<endl;
													OFileObject.close(); 
													
												}
											 
											}
										
										
							
							
						case 2: 
							cout<<"Past records of your journey"<<endl;
							{
								string line;
								ifstream myfile ("past.txt");
								if (myfile.is_open())
								{
								  while ( getline (myfile,line) )
								 {
									  cout << line << '\n';
								 }
								  myfile.close();
								 }

								 else cout << "Unable to open file"; 

								goto l3;
								}
							
						case 3:  
							cout<< "Back to home..."<<endl;
							
							goto l2;
						default:
							cout<<"You entered wrong choice..."<<endl;
							goto l3;
						}
						
						}
						}
	
	break;
case 2: 
	cout<<"How to use"<<endl;
								 {
						  string line;
						  ifstream myfile ("HTU.txt");
						  if (myfile.is_open())
						  {
						    while ( getline (myfile,line) )
						    {
						      cout << line << '\n';
						    }
						    myfile.close();
						  }

						  else cout << "Unable to open file"; 

						  goto l2;
						}
        
case 3: 
	cout<<"Profile"<<endl;
	cout<<"This software is made by the developers of NFS"<<endl;
	cout<<"All Rights reserved to NFS group."<<endl;
	cout<<"Hope your all requirements are fullfilled now"<<endl;
	cout<<"Thanks for using our software"<<endl;
	goto l2;
case 4: 
	cout<< "\t*****helpline*****"<<endl;
	cout<<"\tCall us at 9765133593"<<endl;
	cout<<"\tEmail us: nfscse@gmail.com"<<endl;
	goto l2;
case 5: 
	cout<< "You're Logged out...."<<endl;
	goto l1;

default:
	cout<<"Wrong Choice..."<<endl;
	goto l2;
}
}while(c==5);
}
	 return 1;
	}
     }
}

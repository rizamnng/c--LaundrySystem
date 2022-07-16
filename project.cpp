#include<iostream>
#include<vector>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<iomanip>
using namespace std;
class laundry
{
	string date;
	string name;
	string address;
	string contact;
	int bill;
	
	public:
		void setData(string d,string n,string a,string c,int bl)
		{
			date=d;
			name=n;
			address=a;
			contact=c;
			bill=bl;	
		}
		string getdate()
		{
			return date;
		}
		string getname()
		{
			return name;
		}
		int getbill()
		{
			return bill;
		}
		void display()
		{
			cout<<endl<<endl<<endl;
			cout<<"\t\t\t============BILL============"<<endl<<endl;
			cout<<"\t\t\t\t"<<date<<endl;
			cout<<"\t\t\t\t"<<name<<" "<<endl;
			cout<<"\t\t\t\t"<<address<<endl;
			cout<<"\t\t\t\t"<<contact<<endl;
			cout<<"\t\t\t\t"<<"BILL: "<<bill<<endl<<endl<<endl;
		}
	
	
};
class LoginInfo
{
	string userName;
	string password;
	public:
		void setInfo(string us, string pass)
		{
			userName=us;
			password=pass;
		}
		string getUS()
		{
			return userName;
		}
		string getpass()
		{
			return password;
		}
		void display()
		{
			cout<<userName<<" "<<password<<endl;
		}
};

void login();
void title();
void mainscreen();
void add();
int calculate(int,int,int,int);
int press(int,int,int,int,string);
int delivery(string);
void viewall(vector <laundry> );
void search(vector <laundry> );
void load(vector <laundry> &);
void delet();
void prices();
void signup();
void totalIncome( );
void loadaccount(vector<LoginInfo> &);
void totalcostumers();
void edit();

int main()
{
	vector <laundry> P;
	vector <LoginInfo> D;
	string usrnm,pass,u,p,answer;
	bool found=false;
	while(!found)
	{
		system("CLS");
		cout<<endl<<endl<<endl<<"username: ";
		cin>>usrnm;
		cout<<"password: ";
		cin>>pass;
		loadaccount(D);
		for(int i=0;i<D.size();i++)
		{
			if(D[i].getUS()==usrnm && D[i].getpass()==pass)
			{
				char action;
				while(action!='9')
				{
					system("CLS");
					title();
					mainscreen();
					cout<<"\t\t\t\tCHOOSE ACTION=> ";
					cin>>action;
					system("cls");
					switch(action)
					{
						case '1':
							add();
							break;
						case '2':
							viewall(P);
							totalcostumers();
							break;
						case '3':
							load(P);
							search (P);
							break;
						case '4':
							delet();
							break;
						case '5':
							prices();
							break;
						case '6':
							signup();
							break;
						case '7':
							totalIncome();
							break;
						case '8':
							edit();
							break;
						case '9':
							break;	
					}
				}
				cout<<endl<<endl<<"\t\t\t\tTHANK YOU! "<<endl;
				do{
					cout<<" sign in? y/n: ";
					cin>>answer;
					if(answer=="n")
					{
						found=true;
					}
					else if(answer=="y")
					{
						action='1';
						found=false;
					}	
				}while(answer!="n" && answer!="y");
				break;
			}
			else
			{
				found=false;
			}
		}
		
	}

return 0;
}




void title()
{
	cout<<endl<<endl<<"\t\t\t==============SUMMACUM LAUNDRY SHOP=============="<<endl<<endl;
}


void mainscreen()
{
	cout<<"\t\t\t\t1 ADD TRANSACTION"<<endl;
	cout<<"\t\t\t\t2 VIEW ALL TRANSACTION"<<endl;
	cout<<"\t\t\t\t3 SEARCH INFORMATION"<<endl;
	cout<<"\t\t\t\t4 DELETE INFORMATION"<<endl;
	cout<<"\t\t\t\t5 PRICES"<<endl;
	cout<<"\t\t\t\t6 ADD ADMIN"<<endl;
	cout<<"\t\t\t\t7 TOTAL INCOME"<<endl;
	cout<<"\t\t\t\t8 EDIT"<<endl;
	cout<<"\t\t\t\t9 SIGN OUT"<<endl<<endl;
	
}
void add()
{
	int payment;
	laundry per1;
	vector <laundry> per2;
	int wash,regular,jeans,comforter,curtain;
	string name,address,contact,date,deliver,hanger;
	cout<<endl<<endl<<endl<<"\t\t\t\t1 WASH-DRY-FOLD"<<endl;
	cout<<"\t\t\t\t2 WASH-DRY-PRESS"<<endl<<endl;
	cout<<"\t\t\t\ttransaction=> ";
	cin>>wash;
	system("CLS");
	if(wash==1)
	{
		cout<<"\t\t\t=======PLEASE INPUT IN KILOGRAM ONLY======="<<endl<<endl;
		cout<<setw(50)<<"regular cloth: ";
		cin>>regular;
		cout<<setw(50)<<"jeans/maong: ";
		cin>>jeans;
		cout<<setw(50)<<"curtains/table cloth/bed sheet: ";
		cin>>curtain;
		cout<<setw(50)<<"comforter/sleeping bag/blanket: ";
		cin>>comforter;
		cout<<endl<<endl;
		cout<<"\t\t\t\tCOSTUMER'S INFORMATION"<<endl;
		cout<<setw(50)<<"date (mm/dd/yyyy): ";
		cin>>date;
		cin.ignore();
		cout<<setw(50)<<"name: ";
		getline(cin,name);
		cout<<setw(50)<<"address: ";
		getline(cin,address);
		cout<<setw(50)<<"contact number: ";
		cin>>contact;
		while(contact.size()!=11)
		{
			cout<<endl<<setw(50)<<"invalid contact number,"<<endl;
			cout<<setw(50)<<"please try again!"<<endl;
			cout<<setw(50)<<"contact number: ";
			cin>>contact;
		}
		do
		{
		cout<<setw(50)<<"pick-up/deliver: ";
		cin>>deliver;
		}while(deliver!="pick-up" && deliver!="deliver");
		payment=calculate(jeans,comforter,regular,curtain)+delivery(deliver);
		per1.setData(date,name,address,contact,payment);
	}
	else if(wash==2)
	{
		system("CLS");
		cout<<"\t\t\t=======PLEASE INPUT IN KILOGRAM ONLY======="<<endl<<endl;
		cout<<setw(50)<<"regular cloth: ";
		cin>>regular;
		cout<<setw(50)<<"jeans/maong: ";
		cin>>jeans;
		cout<<setw(50)<<"curtains/table cloth/bed sheet: ";
		cin>>curtain;
		cout<<setw(50)<<"comforter/sleeping bag/blanket: ";
		cin>>comforter;
		cout<<endl<<endl;
		cout<<"\t\t\t\tCOSTUMER'S INFORMATION"<<endl;
		cout<<setw(50)<<"date (mm/dd/yyyy): ";
		cin>>date;
		cin.ignore();
		cout<<setw(50)<<"name: ";
		getline(cin,name);
		cout<<setw(50)<<"address: ";
		getline(cin,address);
		cout<<setw(50)<<"contact number: ";
		cin>>contact;
		while(contact.size()!=11)
		{
			cout<<endl<<setw(50)<<"invalid contact number,"<<endl;
			cout<<setw(50)<<"please try again!"<<endl;
			cout<<setw(50)<<"contact number: ";
			cin>>contact;
		}
		do
		{
			cout<<setw(50)<<"hanger (with/without): ";
			cin>>hanger;
		}while(hanger!="with" && hanger!="without");
		do
		{
		cout<<setw(50)<<"pick-up/deliver: ";
		cin>>deliver;
		}while(deliver!="pick-up" && deliver!="deliver");
		payment=press(jeans,comforter,regular,curtain,hanger)+delivery(deliver);
		per1.setData(date,name,address,contact,payment);
	}
	else
	{
		cout<<"\t\t\tplease choose between 1 and 2 only!"<<endl;
	}
	per2.push_back(per1);
	ofstream write("laundry information.txt",ios::app);
	write<<date<<endl;
	write<<name<<endl;
	write<<address<<endl;
	write<<contact<<endl;
	write<<payment<<endl;
	write.close();
	system("CLS");
	per1.display();
	system("PAUSE");
}

int calculate(int j,int c,int re,int curt)
{
	int pay;
	pay=(j*30)+(c*70)+(re*25)+(curt*45);
	return pay;
}
int press(int j,int c,int re,int curt,string hang)
{
	int pay;
	if(hang=="with")
	{
		pay=(j*95)+(c*70)+(re*90)+(curt*45);
	}
	else
	{
		pay=(j*65)+(c*70)+(re*60)+(curt*45);
	}
	return pay;
}
int delivery(string answer)
{
	int additional;
	if(answer=="pick-up")
	{
		additional=0;
		
	}
	else if(answer=="deliver")
	{
		additional=20;
	}
	return additional;
}

void load(vector <laundry> &person2)
{
	person2.erase(person2.begin(),person2.begin()+person2.size());
	laundry person;
	string da,na,ad,con;
	string bi;
	int num=0;
	ifstream read("laundry information.txt");
	while(getline(read,da),getline(read,na),getline(read,ad),getline(read,con),getline(read,bi))
	{
		stringstream geek(bi);
		geek>>num;
		person.setData(da,na,ad,con,num);
		person2.push_back(person);	
	}
	read.close();	
}

void viewall(vector <laundry> person2)
{
	system("CLS");
	laundry person;
	string da,na,ad,con,linebuffer;
	string bi;
	int num=0;
	ifstream read("laundry information.txt");
	if(read.is_open())
	{
	
	while(getline(read,da),getline(read,na),getline(read,ad),getline(read,con),getline(read,bi))
	{
		stringstream geek(bi);
		geek>>num;
		person.setData(da,na,ad,con,num);
		person2.push_back(person);
		person.display();	
		
	}
	read.close();
	}
	else
	{
		cout<<"\t\t\t\tnot being read";
	}	
}

void search(vector <laundry> R)
{
	string name;
	string date,answer="y";
	cout<<endl<<endl;
	cout<<"\t\t\t======SEARCH INFORMATION======="<<endl<<endl;
	while(answer=="y")
	{
		bool found=false;
		cout<<setw(40)<<"date: ";
		cin>>date;
		cin.ignore();
		cout<<setw(40)<<"name: ";
		getline(cin,name);
		for(int i=0;i<R.size();i++)
		{
			if(R[i].getname()==name && R[i].getdate()==date)
			{
				R[i].display();
				found=true;
				
			}
		
		}
		if(!found)
		{
			cout<<setw(50)<<"no record!"<<endl;	
		}
		cout<<endl<<endl<<"\t\t\t\tsearch again? y/n: ";
		cin>>answer;
		while(answer!="y" && answer!="n")
		{
			cout<<endl<<endl<<"\t\t\t\tsearch again? y/n: ";
			cin>>answer;
		}
	}
}
void delet()
{
	string date,name;
	string answer;
	string da,na,ad,con;
	string bi;
	int num=0,n=0;
	cout<<endl<<endl;
	cout<<"\t\t\t\t\t========DELETE======="<<endl<<endl;
	do{
		n=0;
		cout<<setw(50)<<"date: ";
		cin>>date;
		cin.ignore();
		cout<<setw(50)<<"name: "; 
		getline(cin,name);
		ifstream read("laundry information.txt");
		ofstream write("new.txt",ios::app);
		while(getline(read,da),getline(read,na),getline(read,ad),getline(read,con),getline(read,bi))
		{
			stringstream geek(bi);
			geek>>num;
			if(date!=da || name!=na)
			{
				write<<da<<endl;
				write<<na<<endl;
				write<<ad<<endl;
				write<<con<<endl;
				write<<num<<endl;	
			}
			else
			{
				cout<<endl<<endl;
				cout<<"\t\t\t\t    deleted successfully!"<<endl<<endl;
				n++;
			}
		}
		if(n==0)
		{
			cout<<"\t\t\t\t\t no record found!"<<endl;
		}
		read.close();
		write.close();
		remove("laundry information.txt");
		rename("new.txt","laundry information.txt");
		cout<<endl<<endl<<"\t\t\t\texit? y/n: ";
		cin>>answer;
		while(answer!="y" && answer!="n")
		{
			cout<<endl<<endl<<"\t\t\t\texit? y/n: ";
			cin>>answer;
		}
	}while(answer=="n");
}
void prices()
{
	int choice;
	cout<<endl<<endl;
	cout<<"\t\t\t1 WASH-DRY-FOLD "<<endl;
	cout<<"\t\t\t2 WASH-DRY-PRESS"<<endl<<endl;
	cout<<"\t\t\ttransaction=> ";
	cin>>choice;
	system("CLS");
	cout<<"\t\t===========================PRICES==========================="<<endl;
	if(choice==1)
	{
		cout<<"\t\t=======================WASH-DRY-FOLD========================"<<endl<<endl<<endl;
		cout<<setw(60)<<"REGULAR CLOTH= P25/kl"<<setw(60)<<endl;
		cout<<"JEANS/ MAONG/= P30/kl"<<setw(60)<<endl;
		cout<<"CURTAINS/ TABLE CLOTH/ BEDSHEET/= P45/kl"<<setw(60)<<endl;
		cout<<"COMFORTER/ SLEEPING BAG/ BLANKET= P70/kl"<<endl<<endl;
		cout<<"\t\tNOTE:"<<endl<<"\t\t    for delivery an additional charge of P20"<<endl<<"\t\t     but we deliver within the city only "<<endl<<endl<<endl;
	}
	else if(choice==2)
	{
		cout<<"\t\t=======================WASH-DRY-PRESS======================="<<endl<<endl<<endl;
		cout<<setw(60)<<"REGULAR CLOTH without HANGER= P60/kl"<<setw(60)<<endl;
		cout<<"REGULAR CLOTH with HANGER= P90/kl"<<setw(60)<<endl;
		cout<<"JEANS/ MAONG without HANGER= P65/kl"<<setw(60)<<endl;
		cout<<"JEANS/ MAONG with HANGER= P95/kl"<<setw(60)<<endl;
		cout<<"CURTAINS/ TABLE CLOTH/ BEDSHEET/= P45/kl"<<setw(60)<<endl;
		cout<<"COMFORTER/ SLEEPING BAG/ BLANKET= P70/kl"<<endl<<endl;
		cout<<"\t\tNOTE:"<<endl<<"\t\t    for delivery an additional charge of P20"<<endl<<"\t\t     but we deliver within the city only "<<endl<<endl<<endl;
	}
	else
	{
		cout<<"wrong input!"<<endl;
	}
	
	system("PAUSE");
}
void signup()
{
	ofstream Write("ADMIN ACCOUNTS.txt",ios::app);
	string u,p;
	cout<<endl<<endl;
	cout<<"\t\t\t\t=========ADD ADMIN========"<<endl<<endl;
	cout<<setw(50)<<"username: ";
	cin>>u;
	cout<<setw(50)<<"password: ";
	cin>>p;
	Write<<u<<" "<<p<<endl;
	Write.close();
	cout<<endl<<"\t\t\t\t\tadded sucessfully!"<<endl<<endl;
	system("PAUSE");
}

void totalIncome()
{
	vector <laundry> A;
	load(A);
	int income=0;
	for(int i=0;i<A.size();i++)
	{
		income=income+A[i].getbill();	
	}
	cout<<endl<<endl<<"\t\t\t\tTOTAL INCOME: ";
	cout<<"P"<<income<<endl<<endl;
	system("PAUSE");
}
void loadaccount(vector <LoginInfo> &S)
{
	ifstream read("ADMIN ACCOUNTS.txt");
	LoginInfo L;
	string u, p;
	while(read>>u>>p)
	{
		L.setInfo(u,p);
		S.push_back(L);
	}
	read.close();

}
void totalcostumers()
{
	vector <laundry> Y;
	load(Y);
	cout<<endl<<"\t\t\tTOTAL NUMBER OF COSTUMERS: ";
	cout<<Y.size()<<endl<<endl;
	system("PAUSE");
}
void edit()
{
	string det,nem;
	string answer,contin;
	string da,na,ad,con;
	string bi;
	int payment;
	laundry per1;
	vector <laundry> per2;
	int wash,regular,jeans,comforter,curtain;
	string name,address,contact,date,deliver,hanger;
	int num=0,n=0;
	cout<<endl<<endl;
	do
	{
		n=0;
		cout<<setw(50)<<"date: ";
		cin>>det;
		cin.ignore();
		cout<<setw(50)<<"name: "; 
		getline(cin,nem);
		ifstream read("laundry information.txt");
		ofstream write("new.txt",ios::app);
		while(getline(read,da),getline(read,na),getline(read,ad),getline(read,con),getline(read,bi))
		{
			
			stringstream geek(bi);
			geek>>num;
			if(det!=da || nem!=na)
			{
				write<<da<<endl;
				write<<na<<endl;
				write<<ad<<endl;
				write<<con<<endl;
				write<<num<<endl;	
			}
			else
			{
				n++;
				system("cls");
				cout<<endl<<endl<<endl<<"\t\t\t\t "<<da<<endl;
				cout<<"\t\t\t\t "<<na<<endl;
				cout<<"\t\t\t\t "<<ad<<endl;
				cout<<"\t\t\t\t "<<con<<endl;
				cout<<"\t\t\t\t "<<num<<endl;	
				cout<<endl<<endl;
				cout<<"\t\t\t\t continue to edit? (y/n)=> ";
				cin>>contin;
				if(contin=="y")
				{
					system("cls");
					cout<<"\t\t\t\t==========EDIT=========";
					cout<<endl<<endl<<endl<<"\t\t\t\t1 WASH-DRY-FOLD"<<endl;
					cout<<"\t\t\t\t2 WASH-DRY-PRESS"<<endl<<endl;
					cout<<"\t\t\t\ttransaction=> ";
					cin>>wash;
					system("CLS");
					if(wash==1)
					{
						cout<<"\t\t\t=======PLEASE INPUT IN KILOGRAM ONLY======="<<endl<<endl;
						cout<<setw(50)<<"regular cloth: ";
						cin>>regular;
						cout<<setw(50)<<"jeans/maong: ";
						cin>>jeans;
						cout<<setw(50)<<"curtains/table cloth/bed sheet: ";
						cin>>curtain;
						cout<<setw(50)<<"comforter/sleeping bag/blanket: ";
						cin>>comforter;
						cout<<endl<<endl;
						cout<<"\t\t\t\tCOSTUMER'S INFORMATION"<<endl;
						cout<<setw(50)<<"date (mm/dd/yyyy): ";
						cin>>date;
						cin.ignore();
						cout<<setw(50)<<"name: ";
						getline(cin,name);
						cout<<setw(50)<<"address: ";
						getline(cin,address);
						cout<<setw(50)<<"contact number: ";
						cin>>contact;
						while(contact.size()!=11)
						{
							cout<<endl<<setw(50)<<"invalid contact number,"<<endl;
							cout<<setw(50)<<"please try again!"<<endl;
							cout<<setw(50)<<"contact number: ";
							cin>>contact;
						}
						do
						{
						cout<<setw(50)<<"pick-up/deliver: ";
						cin>>deliver;
						}while(deliver!="pick-up" && deliver!="deliver");
						payment=calculate(jeans,comforter,regular,curtain)+delivery(deliver);
						per1.setData(date,name,address,contact,payment);
					}
					else if(wash==2)
					{
						system("CLS");
						cout<<"\t\t\t=======PLEASE INPUT IN KILOGRAM ONLY======="<<endl<<endl;
						cout<<setw(50)<<"regular cloth: ";
						cin>>regular;
						cout<<setw(50)<<"jeans/maong: ";
						cin>>jeans;
						cout<<setw(50)<<"curtains/table cloth/bed sheet: ";
						cin>>curtain;
						cout<<setw(50)<<"comforter/sleeping bag/blanket: ";
						cin>>comforter;
						cout<<endl<<endl;
						cout<<"\t\t\t\tCOSTUMER'S INFORMATION"<<endl;
						cout<<setw(50)<<"date (mm/dd/yyyy): ";
						cin>>date;
						cin.ignore();
						cout<<setw(50)<<"name: ";
						getline(cin,name);
						cout<<setw(50)<<"address: ";
						getline(cin,address);
						cout<<setw(50)<<"contact number: ";
						cin>>contact;
						while(contact.size()!=11)
						{
							cout<<endl<<setw(50)<<"invalid contact number,"<<endl;
							cout<<setw(50)<<"please try again!"<<endl;
							cout<<setw(50)<<"contact number: ";
							cin>>contact;
						}	
						do
						{
							cout<<setw(50)<<"hanger (with/without): ";
							cin>>hanger;
						}while(hanger!="with" && hanger!="without");
						do
						{
							cout<<setw(50)<<"pick-up/deliver: ";
							cin>>deliver;
						}while(deliver!="pick-up" && deliver!="deliver");
						payment=press(jeans,comforter,regular,curtain,hanger)+delivery(deliver);
						per1.setData(date,name,address,contact,payment);
					}
					else
					{
						cout<<"\t\t\tplease choose between 1 and 2 only!"<<endl;
					}
					per2.push_back(per1);
					write<<date<<endl;
					write<<name<<endl;
					write<<address<<endl;
					write<<contact<<endl;
					write<<payment<<endl;
					write.close();
					system("CLS");
					per1.display();
					system("PAUSE");	
				}
				else
				{
					write<<da<<endl;
					write<<na<<endl;
					write<<ad<<endl;
					write<<con<<endl;
					write<<num<<endl;	
				}
				
			}
		}
		if(n==0)
		{
			cout<<"\t\t\t\t\t no record found!"<<endl;
		}
		read.close();
		write.close();
		remove("laundry information.txt");
		rename("new.txt","laundry information.txt");
		cout<<endl<<endl<<"\t\t\t\texit? y/n: ";
		cin>>answer;
		while(answer!="y" && answer!="n")
		{
			cout<<endl<<endl<<"\t\t\t\texit? y/n: ";
			cin>>answer;
		}
	}while(answer=="n");
}

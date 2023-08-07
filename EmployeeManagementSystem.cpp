#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip.h>
#include<dos.h>
fstream empDB("database.dat",ios::in | ios::out | ios::app | ios::binary);
class employee
{
	long id, salary;
	char name[20], dob[12], prcs[20], desg[30], contact[12];
	public:
	void enterData()
	{
		char a;
		int i=0;
		cout<<setw(60)<<"||||||||||||||||||||||||||||||||||||||||";
		cout<<endl<<setw(52)<<"Enter Employee Details";
		cout<<endl<<setw(60)<<"||||||||||||||||||||||||||||||||||||||||";
		cout<<"\nEnter Employee ID: \t\t";
		cin>>id;
		if(id==0)
		{
			cout<<setw(50)<<"\nEnter another ID!"<<endl;
			getch();
			clrscr();
			enterData();
		}
		if(checkID(id)==0)
		{
			cout<<"Enter Name of Employee: \t";
			gets(name);
			cout<<"Enter Date of Birth: \t\t";
			for(i=0;i<10;i++)
			{
				cin>>a;
				dob[i]=a;
			}
			cout<<"Enter Department: \t\t";
			gets(prcs);
			cout<<"Enter Designation: \t\t";
			gets(desg);
			cout<<"Enter Contact number: \t\t";
			for(i=0;i<10;i++)
			{
				cin>>a;
				contact[i]=a;
			}
			if(strcmp(desg,"Manager")==0)
			{
				salary=55000;
			}
			if(strcmp(desg,"AM")==0)
			{
				salary=42000;
			}
			if(strcmp(desg,"Employee")==0)
			{
				salary=28000;
			}
			if(strcmp(desg,"Trainer")==0)
			{
				salary=30000;
			}
			if(strcmp(desg,"Trainee")==0)
			{
				salary=15000;
			}
			if(strcmp(prcs,"Staff")==0)
			{
				salary=18000;
			}
			cout<<"Salary of the employee is "<<salary;

		}
		else
		{
			cout<<endl<<"___________________________________________";
			cout<<endl<<"Employee ID Exists!\n"<<"Try Another ID";
			getch();
			clrscr();
			enterData();
		}

	}

	void readData()
	{
		cout<<endl;
		cout<<setw(8)<<id<<setw(20)<<name<<setw(15)<<prcs<<setw(20)<<desg<<setw(15)<<contact<<endl;
	}
	void showRecord()
	{
		cout<<endl<<"Name of Employee: \t\t";
		puts(name);
		cout<<"Date of Birth: \t\t\t";
		puts(dob);
		cout<<"Department: \t\t\t";
		puts(prcs);
		cout<<"Designation: \t\t\t";
		puts(desg);
		cout<<"Contact number: \t\t";
		puts(contact);
		cout<<"Salary of the employee is \t"<<salary;

	}
	long getID()
	{
		return id;
	}
	char* getName()
	{
		return name;
	}
	char* getPrcs()
	{
		return prcs;
	}
	char* getDesg()
	{
		return desg;
	}
	char* getContact()
	{
		return contact;
	}
	int checkID(long eID)
	{
		fstream empDB("database.dat",ios::in | ios::out | ios::app | ios::binary);
		int flag=0;
		empDB.seekg(0,ios::beg);
		empDB.read((char*)&e,sizeof(e));
		while(empDB.good())
		{
			if(e.getID()==eID)
			{
				flag=1;
				break;
			}
			empDB.read((char*)&e,sizeof(e));
		}
		empDB.clear();
		return flag;
	}
	void update();
}emp,e;
void employee::update()
{
	fstream empDB("database.dat",ios::in | ios::out | ios::ate|ios::binary);
	int flag=0,inp;
	char nm[10], dpt[20],dsg[30],db[10],cnt[12];
	long eID;
	cout<<setw(60)<<"||||||||||||||||||||||||||||||||||||||||";
	cout<<endl<<setw(50)<<"Update Employee Details";
	cout<<endl<<setw(60)<<"||||||||||||||||||||||||||||||||||||||||"<<endl<<endl;
	cout<<"___________________________________________";
	cout<<endl<<"Enter Employee ID to be updated: ";
	cin>>eID;
	empDB.seekg(0);
	while(empDB.read((char*)&e,sizeof(e)))
	{
		if(e.id==eID)
		{
			clrscr();
			cout<<setw(60)<<"||||||||||||||||||||||||||||||||||||||||";
			cout<<endl<<setw(50)<<"Update Employee Details";
			cout<<endl<<setw(60)<<"||||||||||||||||||||||||||||||||||||||||"<<endl<<endl;
			cout<<endl<<setw(55)<<"Previous Record with Employee ID "<<eID<<endl<<endl;
			cout<<setw(8)<<"EmpID"<<setw(20)<<"Employe Name"<<setw(15)<<"Department"<<setw(20)<<"Designation"<<setw(15)<<"Contact"<<endl;
			cout<<"_______________________________________________________________________________";
			e.readData();
			flag=1;
			break;
		}
	}

	if(flag==0)
	{
	cout<<endl<<setw(40)<<"Employee ID "<<eID<<" doesn't exists!";
	}
	else
	{
		empDB.clear();
		cout<<endl<<"_________________________________________";
		cout<<endl<<"1 Update Name";
		cout<<endl<<"2 Update Date of Birth";
		cout<<endl<<"3 Update Department";
		cout<<endl<<"4 Update Designation";
		cout<<endl<<"5 Update Contact";
		cout<<endl<<endl<<"____________________________________";
		cout<<endl<<"Enter your choice: ";
		cin>>inp;
		empDB.clear();
		int x=0;
		switch(inp)
		{
			case 1:
				cout<<endl<<endl<<"____________________________________";
				cout<<endl<<"Enter New Name:";
				gets(nm);
				strcpy(e.name,nm);
				empDB.seekp(empDB.tellp()-sizeof(e));
				empDB.write((char*)&e,sizeof(e));
				cout<<endl<<"_______________________________________";
				cout<<endl<<"Data is being updated";
				while(x<4)
				{
					delay(500);
					cout<<".";
					x++;
				}
				delay(1000);
				cout<<endl<<endl<<"_________________________________________";
				cout<<endl<<"Data Updated Successfully!";
				empDB.clear();
				empDB.close();
			break;
			case 2:
				cout<<endl<<endl<<"____________________________________";
				cout<<endl<<"Enter Date of Birth:";
				gets(db);
				strcpy(e.dob,db);
				empDB.seekp(empDB.tellp()-sizeof(e));
				empDB.write((char*)&e,sizeof(e));
				empDB.clear();
				empDB.close();
				cout<<endl<<"Data is being updated";
				while(x<4)
				{
					delay(500);
					cout<<".";
					x++;
				}
				delay(1000);
				cout<<endl<<endl<<"_________________________________________";
				cout<<endl<<"Data Saved Successfully!";
			break;
			case 3:
				cout<<endl<<endl<<"____________________________________";
				cout<<endl<<"Enter New Department:";
				gets(dpt);
				strcpy(e.prcs,dpt);
				empDB.seekp(empDB.tellp()-sizeof(e));
				empDB.write((char*)&e,sizeof(e));
				empDB.clear();
				empDB.close();
				cout<<endl<<"Data is being updated";
				while(x<4)
				{
					delay(500);
					cout<<".";
					x++;
				}
				delay(1000);
				cout<<endl<<endl<<"_________________________________________";
				cout<<endl<<"Data Saved Successfulyl!";
			break;
			case 4:
				cout<<endl<<endl<<"____________________________________";
				cout<<endl<<"Enter New Designation:";
				gets(dsg);
				strcpy(e.desg,dsg);
				empDB.seekp(empDB.tellp()-sizeof(e));
				empDB.write((char*)&e,sizeof(e));
				empDB.clear();
				if(strcmp(e.desg,"Manager")==0)
				{
					e.salary=55000;
				}
				if(strcmp(e.desg,"AM")==0)
				{
					e.salary=42000;
				}
				if(strcmp(e.desg,"Employee")==0)
				{
					e.salary=28000;
				}
				if(strcmp(e.desg,"Trainer")==0)
				{
					e.salary=30000;
				}
				if(strcmp(e.desg,"Trainee")==0)
				{
					e.salary=15000;
				}
				empDB.seekp(empDB.tellp()-sizeof(e));
				empDB.write((char*)&e,sizeof(e));
				empDB.clear();
				empDB.close();
				cout<<endl<<"Data is being updated";
				while(x<4)
				{
					delay(500);
					cout<<".";
					x++;
				}
				delay(1000);
				cout<<endl<<endl<<"_________________________________________";
				cout<<endl<<"Data Saved Successfully!";
			break;
			case 5:
				cout<<endl<<endl<<"____________________________________";
				cout<<endl<<"Enter Contact:";
				gets(cnt);
				strcpy(e.contact,cnt);
				empDB.seekp(empDB.tellp()-sizeof(e));
				empDB.write((char*)&e,sizeof(e));
				empDB.clear();
				empDB.close();
				cout<<endl<<"Data is being updated";
				while(x<4)
				{
					delay(500);
					cout<<".";
					x++;
				}
				delay(1000);
				cout<<endl<<endl<<"_________________________________________";
				cout<<endl<<"Data Saved Successfully!";
			break;
			default:
			cout<<endl<<endl<<"________________________________________";
			cout<<"Invalid Input";
			break;
		}
	}
}
void main()
{
clrscr();
int inp, flag=0, search, loop=0, x=0, read;
long eID;
char ask, name[20], prc[20], dsg[30], cont[12], admin[10], pass[10];
while(ask!='n' && ask!='N')
{
	clrscr();
	cout<<"\n\t\t------------------------------------------------";
	cout<<endl<<setw(55)<<"Employee Management System\n";
	cout<<"\t\t------------------------------------------------";
	cout<<endl<<endl<<setw(43)<<"LogIn";
	cout<<endl<<"________________________________________________________________________________"<<endl;
	cout<<"Enter Username: ";
	gets(admin);
	if(strcmp(admin,"Admin")==0)
	{
		int i=0;
		char p=NULL;
		cout<<"Enter Password: ";
		while(p!='\r')
		{
		p=getch();
		pass[i]=p;
			if(pass[i]!='\r' && pass[i]!=char(8))
			{
				cout<<"*";
				i++;
			}
			if(p=='\r')
			{
				pass[i]='\0';
			}
			if(pass[i]==char(8))
			{
				pass[i]='\0';
				pass[i-1]='\0';
				cout<<char(8);
				i--;
			}
		}
		if(strcmp(pass,"Password")==0)
		{
			while(loop==0)
			{
				clrscr();
				fstream empDB("database.dat",ios::in | ios::out | ios::app | ios::binary);
				cout<<"\n\t\t------------------------------------------------";
				cout<<endl<<setw(55)<<"Employee Management System\n";
				cout<<"\t\t------------------------------------------------";
				cout<<"\n\t\t1 Enter new Record";
				cout<<"\n\t\t2 Display All Employee";
				cout<<"\n\t\t3 Search an Employee's Details";
				cout<<"\n\t\t4 Delete a Record";
				cout<<"\n\t\t5 Update Employee's Details";
				cout<<"\n\t\t6 Exit\n";
				cout<<endl<<setw(45)<<"Enter Choice: ";
				cin>>inp;
				switch(inp)
				{
					case 1:
						enter:
						clrscr();
						empDB.seekp(0,ios::end);
						emp.enterData();
						empDB.write((char*)&emp,sizeof(emp));
						cout<<endl<<"_________________________________________"<<endl;
						cout<<"Do you want to add more employees (y/n): ";
						cin>>ask;
						if(ask=='y' || ask=='Y')
							goto enter;
						cout<<endl<<endl<<"_________________________________________";
						cout<<endl<<"Data is being Saved";
						while(x<4)
						{
							delay(500);
							cout<<".";
							x++;
						}
						delay(1000);
						cout<<endl<<endl<<"_________________________________________";
						cout<<endl<<"Data Saved Successfull!";
					break;
					case 2:
						clrscr();
						x=0, read=0;
						cout<<setw(60)<<"||||||||||||||||||||||||||||||||||||||||";
						cout<<endl<<setw(50)<<"Employee Database";
						cout<<endl<<setw(60)<<"||||||||||||||||||||||||||||||||||||||||"<<endl<<endl;
						cout<<endl<<"_________________________________________";
						cout<<endl<<"Data is being Fetched";
						while(x<4)
						{
							delay(500);
							cout<<".";
							x++;
						}
						delay(1000);
						clrscr();
						cout<<setw(60)<<"||||||||||||||||||||||||||||||||||||||||";
						cout<<endl<<setw(50)<<"Employee Database";
						cout<<endl<<setw(60)<<"||||||||||||||||||||||||||||||||||||||||"<<endl<<endl;
						cout<<endl<<endl;
						cout<<setw(8)<<"EmpID"<<setw(20)<<"Employe Name"<<setw(15)<<"Department"<<setw(20)<<"Designation"<<setw(15)<<"Contact"<<endl;
						cout<<"_______________________________________________________________________________";
						empDB.seekg(0,ios::beg);
						empDB.read((char*)&e,sizeof(e));
						while(empDB.good())
						{
							e.readData();
							empDB.read((char*)&e,sizeof(e));
							read=1;
						}
						if(read==0)
						{
							cout<<endl<<"__________________________________";
							cout<<endl<<"No Data is to be displayed";
						}
						empDB.clear();
					break;
					case 3:
						sch:
						flag=0;
						clrscr();
						cout<<setw(60)<<"||||||||||||||||||||||||||||||||||||||||";
						cout<<endl<<setw(48)<<"Search Employee";
						cout<<endl<<setw(60)<<"||||||||||||||||||||||||||||||||||||||||";
						cout<<"\n1 Search by Employee ID";
						cout<<"\n2 Search by Employee Department";
						cout<<"\n3 Search by Employee Designation";
						cout<<"\n4 Search by Employee Contact no.\n";
						cout<<endl<<"_________________________________________";
						cout<<endl<<"Enter your choice: ";
						cin>>search;
						clrscr();
						cout<<setw(60)<<"||||||||||||||||||||||||||||||||||||||||";
						cout<<endl<<setw(48)<<"Search Employee";
						cout<<endl<<setw(60)<<"||||||||||||||||||||||||||||||||||||||||";

						switch(search)
						{
							case 1:
								cout<<endl<<"_________________________________________"<<endl;
								cout<<"Enter Employee ID to be searched: ";
								cin>>eID;
								cout<<endl<<endl;
								empDB.seekg(0,ios::beg);
								empDB.read((char*)&e,sizeof(e));
								while(empDB.good())
								{
									if(e.getID()==eID)
									{

										cout<<endl<<"_______________________________________________________________________________";
										e.showRecord();
										flag=1;
										break;
									}
									empDB.read((char*)&e,sizeof(e));
								}
								empDB.clear();
								if(flag==0)
								{
									cout<<endl<<"_________________________________________"<<endl;
									cout<<"Employee ID hasn't found"<<endl;
									cout<<"Enter Valid Employee ID";
								}
								cout<<endl<<"_________________________________________"<<endl;
								cout<<"Do you want to search again (y/n): ";
								cin>>ask;
								if(ask=='y' || ask=='Y')
									goto sch;
							break;
							case 2:
								cout<<endl<<"_________________________________________"<<endl;
								cout<<"Enter Department to be searched: ";
								cin>>prc;
								cout<<endl<<endl;
								cout<<setw(8)<<"EmpID"<<setw(20)<<"Employe Name"<<setw(15)<<"Department"<<setw(20)<<"Designation"<<setw(15)<<"Contact"<<endl;
								cout<<"_______________________________________________________________________________";
								empDB.seekg(0,ios::beg);
								empDB.read((char*)&e,sizeof(e));
								while(empDB.good())
								{
									if(strcmp(e.getPrcs(),prc)==0)
									{
										e.readData();
										flag=1;
									}
									empDB.read((char*)&e,sizeof(e));
								}
								empDB.clear();
								if(flag==0)
								{
									cout<<endl<<"_________________________________________"<<endl;
									cout<<"Process hasn't found"<<endl;
									cout<<"Enter Valid Department";
								}
								cout<<endl<<"_________________________________________"<<endl;
								cout<<"Do you want to search again (y/n): ";
								cin>>ask;
								if(ask=='y' || ask=='Y')
									goto sch;
							break;
							case 3:
								cout<<endl<<"_________________________________________"<<endl;
								cout<<"Enter Designation to be searched: ";
								cin>>dsg;
								cout<<endl<<endl;
								cout<<setw(8)<<"EmpID"<<setw(20)<<"Employe Name"<<setw(15)<<"Department"<<setw(20)<<"Designation"<<setw(15)<<"Contact"<<endl;
								cout<<"_______________________________________________________________________________";
								empDB.seekg(0,ios::beg);
								empDB.read((char*)&e,sizeof(e));
								while(empDB.good())
								{
									if(strcmp(e.getDesg(),dsg)==0)
									{
										e.readData();
										flag=1;
									}
									empDB.read((char*)&e,sizeof(e));
								}
								empDB.clear();
								if(flag==0)
								{
									cout<<endl<<"_________________________________________"<<endl;
									cout<<"Designation hasn't found";
									cout<<endl<<"Enter Valid Designation";
								}
								cout<<endl<<"_________________________________________"<<endl;
								cout<<"Do you want to search again (y/n): ";
								cin>>ask;
								if(ask=='y' || ask=='Y')
									goto sch;
							break;
							case 4:
								flag=0;
								cout<<endl<<"_________________________________________"<<endl;
								cout<<"Enter Contact to be searched: ";
								cin>>cont;
								cout<<endl<<endl;
								empDB.seekg(0,ios::beg);
								empDB.read((char*)&e,sizeof(e));
								cout<<"_______________________________________________________________________________";
								while(empDB.good())
								{
									if(strcmp(e.getContact(),cont)==0)
									{
										e.showRecord();
										flag=1;
									}
									empDB.read((char*)&e,sizeof(e));
								}
								empDB.clear();
								if(flag==0)
								{
									cout<<"_____________________________________________"<<endl;
									cout<<"Contact Number hasn't found";
									cout<<endl<<"Enter Valid Contact Number";
								}
								cout<<endl<<"_________________________________________"<<endl;
								cout<<"Do you want to search again (y/n): ";
								cin>>ask;
								if(ask=='y' || ask=='Y')
									goto sch;
							break;
							default:
								cout<<endl<<"_________________________________________"<<endl;
								cout<<"Invalid Input!"<<endl<<"Do you want to search again (y/n): ";
								cin>>ask;
								if(ask=='y' || ask=='Y')
									goto sch;
							break;
						}
					break;
					case 4:
						deletion:
						clrscr();
						cout<<setw(60)<<"||||||||||||||||||||||||||||||||||||||||";
						cout<<endl<<setw(48)<<"Remove Employee";
						cout<<endl<<setw(60)<<"||||||||||||||||||||||||||||||||||||||||"<<endl<<endl;
						cout<<"Enter Employee ID: ";
						cin>>eID;
						cout<<endl<<endl;
						if(emp.checkID(eID)==1)
						{
							fstream temp("temp.dat", ios::in | ios::out | ios::app | ios::binary);
							cout<<endl<<setw(57)<<"_________________________________"<<endl;
							cout<<endl<<setw(52)<<"Record with Employee ID "<<eID<<endl<<endl;
							cout<<setw(8)<<"EmpID"<<setw(20)<<"Employe Name"<<setw(15)<<"Department"<<setw(20)<<"Designation"<<setw(15)<<"Contact"<<endl;
							cout<<"_______________________________________________________________________________";
							e.readData();
							cout<<endl<<endl<<"_________________________________"<<endl;
							cout<<"Delete the record (y/n): ";
							cin>>ask;
							if(ask=='y' || ask=='Y')
							{
								x=0;
								cout<<endl<<"_________________________________________";
								cout<<endl<<"Deletion in Progress";
								while(x<4)
								{
									delay(500);
									cout<<".";
									x++;
								}
								delay(1000);
								empDB.seekg(0,ios::beg);
								empDB.read((char*)&e,sizeof(e));
								while(empDB.good())
								{
									if(e.getID()!=eID)
									{
										temp.write((char*)&e,sizeof(e));
									}
									empDB.read((char*)&e,sizeof(e));
								}
								empDB.clear();
								temp.close();
								empDB.close();
								remove("database.dat");
								rename("temp.dat","database.dat");
								cout<<endl<<endl<<"_________________________________"<<endl;
								cout<<endl<<"Record Deleted Successfully!"<<endl;
							}
							else
							{
								cout<<endl<<"_________________________________"<<endl;
								cout<<"Delete Unsuccessfull";
							}
						}
						else
						{
							cout<<setw(50)<<"Employee ID doesn't exists!\n"<<setw(50)<<"Try Another ID";
						}
						cout<<"Do you want to delete another record (y/n):";
						cin>>ask;
						if(ask=='y' || ask=='Y')
							goto deletion;
					break;
					case 5:
						clrscr();
						emp.update();
					break;
					case 6:
					clrscr();
					cout<<"\n\t\t------------------------------------------------";
					cout<<endl<<setw(55)<<"Employee Management System\n";
					cout<<"\t\t------------------------------------------------";
					cout<<endl<<endl<<"_________________________________________";
					cout<<endl<<"Exiting the system";
					x=0;
					while(x<4)
					{
						delay(500);
						cout<<".";
						x++;
					}
					exit(1);
					break;
					default:
					cout<<endl<<endl<<"___________________________________"<<endl;
					cout<<"Invalid input!";
					getch();
					continue;
				}
				empDB.close();
				cout<<endl<<endl<<"_________________________________"<<endl;
				cout<<endl<<"Press Enter for Main Menu";
				getch();
				empDB.close();
			}
		}
		else
		{
			cout<<endl<<setw(45)<<"Wrong Password!";
			cout<<endl<<endl<<"___________________________________________"<<endl;
			cout<<endl<<"Enter Username and Password again";
			getch();
			clrscr();
		}
	}
	else
	{
	cout<<setw(45)<<"Invalid Username!";
	cout<<endl<<endl<<"_______________________________________________________"<<endl;
	cout<<endl<<"Do you want to enter Username again (y/n): ";
	cin>>ask;
	clrscr();
	if(ask=='n' || ask=='N')
	{
	clrscr();
	cout<<"\n\t\t------------------------------------------------";
	cout<<endl<<setw(55)<<"Employee Management System\n";
	cout<<"\t\t------------------------------------------------";
	cout<<endl<<endl<<"_________________________________________";
	cout<<endl<<"Exiting the system";
	x=0;
	while(x<4)
	{
		delay(500);
		cout<<".";
		x++;
	}
	delay(1000);
	exit(1);
	}
	}
}
}
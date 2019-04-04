#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
using namespace std;

class log
{
public:
void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
	{
	
    	printf("\n  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\  LOGIN FIRST  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\  ");
    	printf(" \n\n                  ENTER USERNAME:=");
		scanf("%s", &uname); 
		printf(" \n\n                  ENTER PASSWORD:=");
		while(i<10)
		{
	    	pword[i]=getch();
	    	c=pword[i];
	    	if(c==13)
				break;
	    	else
				printf("*");
	    	i++;
		}
		pword[i]='\0';
		i=0;
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
		{
			printf("  \n\n\n       WELCOME TO TOURIST INFORMATION SYSTEM !!!! LOGIN IS SUCCESSFUL");
			printf("\n\n\n\t\t\t\tPress any key to continue...");
			getch();
			break;
		}
		else
		{
			printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
			a++;
			getch();
		}
	}while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		getch();
		exit(0);
	}
	system("cls");
	
}
void loop()
{
	FILE *fp, *ft;
    char another, choice;
    int flag=0;
	struct tourist
	{
	    char first_name[50], last_name[50], gender[10];
		char address[100];
        int id, age;
    };
    struct tourist e;
    int xid;
    long int recsize;
    fp=fopen("users.txt","rb+");
    if (fp == NULL) {
        fp = fopen("users.txt","wb+");
        if (fp==NULL)
        {
             puts("Cannot open file");
        }
    }
	recsize = sizeof(e);
	while(1) 
	{
     	system("cls");
		cout << "\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TOURIST INFORMATION SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ";
	 	cout <<"\n\n                                          ";
     	cout << "\n\n";
     	cout<<" \n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ";
     	cout << "\n \t\t\t  Press 1> To Add    Records";
     	cout << "\n \t\t\t  Press 2> To View   Records";
     	cout << "\n \t\t\t  Press 3> To Modify Records";
     	cout << "\n \t\t\t  Press 4> To Remove Records";
     	cout << "\n \t\t\t  Press 5> To Exit   Program";
     	cout<<" \n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ";
     	cout << "\n\n";
     	cout << "\t\t\t Select Your Choice ::";
     	fflush(stdin);
     	choice = getche();
     	switch(choice)
     	{
      		case '1' :
            	fseek(fp,0,SEEK_END);
            	another ='Y';
            	while(another == 'Y' || another == 'y')
            	{
                	system("cls");
                	cout << "Enter the ID : ";
                	cin >> e.id;
                	cout << "Enter the First Name : ";
                	cin >> e.first_name;
                	cout << "Enter the Last Name  : ";
                	cin >> e.last_name;
                	cout << "Enter the Gender     : ";
                	cin >> e.gender;
                	cout << "Enter the Age        : ";
                	cin >> e.age;
                	cout << "Enter the Address    : ";
                	scanf("\n");
    				scanf("%[^\n]%*c",&e.address);
                	fwrite(&e,recsize,1,fp);
                	cout << "\n Add Another Record (Y/N) ";
                	fflush(stdin);
                	another = getchar();
            	}
            	break;
   			case '2':
            	system("cls");
           		rewind(fp);
           		cout << "\xB2\xB2 View the Records in the Database \xB2\xB2 ";
           		cout << "\n";
           		while (fread(&e,recsize,1,fp) == 1)
				{
           			cout << "\n";
           			cout <<"\nID       :: " <<e.id;
					cout <<"\nName     :: " <<e.first_name <<" "<<e.last_name;
           			cout <<"\nGender   :: " <<e.gender;
           			cout <<"\nAge      :: " <<e.age;
           			cout <<"\nAddress  :: " <<e.address;
           		}
           		cout << "\n\n";
           		system("pause");
           		break;
  			case '3' :
				system("cls");
          		another = 'Y';
          		while (another == 'Y'|| another == 'y')
          		{
              		cout << "\n Enter the id of the tourist : ";
              		cin >> xid;
	            	rewind(fp);
    	        	while (fread(&e,recsize,1,fp) == 1)
        	    	{
            	    	if (e.id==xid)
                		{	
                			flag=1;
                			cout << "Enter the First Name : ";
                			cin >> e.first_name;
                			cout << "Enter the Last Name  : ";
                			cin >> e.last_name;
                			cout << "Enter the Gender     : ";
                			cin >> e.gender;
                			cout << "Enter the Age        : ";
                			cin >> e.age;
                			cout << "Enter the Address    : ";
                			scanf("\n");
                			scanf("%[^\n]%*c",&e.address);
                			fseek(fp, - recsize, SEEK_CUR);
                			fwrite(&e,recsize,1,fp);
                			break;
                		}
            		}
            		if(flag==0)
            			cout<<"Record not found";
            		cout << "\n Modify Another Record (Y/N) ";
                	fflush(stdin);
                	another = getchar();
            	}
            	break;
		    case '4':
       			system("cls");
           		another = 'Y';
          		while (another == 'Y'|| another == 'y')
          		{
              		cout << "\n Enter the ID of the tourist to delete : ";
              		cin >> xid;
	              	ft = fopen("temp.dat", "wb");
			        rewind(fp);
              		while (fread (&e, recsize,1,fp) == 1)
						if (e.id!=xid)
                    		fwrite(&e,recsize,1,ft);
                	fclose(fp);
                	fclose(ft);
                	remove("users.txt");
                	rename("temp.dat","users.txt");
                	fp=fopen("users.txt","rb+");
					cout << "\n Delete Another Record (Y/N) ";
                	fflush(stdin);
                	another = getchar();
              	}
				break;
            case '5':
              	fclose(fp);
              	cout << "\n\n";
              	cout << "\t\t     THANK YOU.";
              	cout << "\n\n";
              	exit(0);
        }
    }
}
};


int main() 
{
	log p;
	p.login();
	p.loop();    
	return 0;
}


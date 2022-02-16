#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

void Register();
void login();
void profile(char[],char[]);
void viewBooks();
void deleteBooks();
void updateBooks();
void adminLogin();
void addBooks();
void viewCustomers();
void view(int choice);
void deleteCustomers();
int validation(char *name ,int id);
void adminLogin();
void loadingProgressBar();
void header();
void header2();
void footer();
int alreadyValidation(char *name ,int id);
int bookIdAlreadyValidation(int id);
int discountIdAlreadyValidation(int id);
int discountpriceAlreadyValidation(double price);
int discountpriceAsceingOderMaker(double price);
void customerMenu();
void adminMenu();
void findPassword();
void updateProfile(char[],char[]);
void deleteProfile(char[],char[]);
void deleteCProfile(char[]);
void buyBooks();
void shoppingCart(int bookid, int quantity);
void addDiscount();
void viewDiscounts();
void makePayment(double total, double discountprice, double amount,double rate);
void payOnline(double amount);
void cashOnDelivery(double fullamount);
void deliveryProduct();
void viewDistance();
void searchBooks();
void printBill(double total, double discountPrice, double amount,double rate);
void viewSales();
void endAll();
void makeReport();
void paidCustomers();
void unpaidCustomers();
void payonlineCustomers();
void boughtBooks();
void viewPayments();

int count=0;
double total=0;

const double cardValue=100000; // If Your Card Have Rs. 100000.000


struct data{
	char fname[100];
	char lname[100];
	char nic[12];
	char phone[10];
	int age;
	char password[10];
	char city[10];

};

struct book{
	int bookId;
	char bookName[100];
	char authorName[100];
	double price;
	int quantity;
	double total;
};


struct order{
    char fname[20];
    char nic[12];
    char address[100];
    double deliveryCost;
    double customerTotal;

};

struct discount{
    double price;
    double rate;
    int discountId;
};

struct payOnline{
    int year;
    char name[100];
    int month;
    char phone[10];
    int cvc;
    char nic[10];
    char cardNumber[16];
};

struct delivery{
    double distance;
    char address[100];
    double cost;
};

struct report{
	int quantity;
    int bookId;
    char nic[10];
	double price;
	char address[10];
	double dcost;
};

struct payments{
    double discount;
    double total;
    double deliveryCost;
    double fullAmount;
};


int main() {

    remove ("order.dat");
    remove("cart.dat");
    remove("delivery.dat");

	int j,i,flag;

    loadingProgressBar();

do{
	system("COLOR 09");
	header();

	printf("\t\t     Welcome!\n\n");
	printf("\tYour Are the,\n\n");
	printf("\t1.Admin\n");
	printf("\t2.Customer\n");
	printf("\t3.Exit\n\n");
	printf("\t-----------------------------------\n\n");
	printf("\tEnter your Option (1 or 2 or 3): ");
	scanf("%d",&j);

	flag=1;

	if(j==1){

	adminLogin();

	}else if(j==2){

    int p=1;
 do{
    p=1;
	system("COLOR 0B");
	header();

	printf("\t\t     Welcome!\n\n");
	printf("\n\tDo you want to : \n\n");
	printf("\t1. Register \n");
	printf("\t2. Login \n");
	printf("\t3. Exit\n\n");
	printf("\n\n\t-----------------------------------\n\n");
	printf("\tWhat do you want (1 or 2 or 3): ");
	scanf("%d",&i);

	if(i==1){
		Register();
		}
	else if(i==2){
		login();
		}
	else if(i==3){
        system("CLS");
        printf("\t\n\n\t\tWelcome !  Good Bye");
        footer();
        exit(1);
	}else{
        printf("\t\n\n\tInvalid Input\n");
        sleep(1);
        p=0;
	}
 }while(p==0);

	}else if(j==3){

		system("CLS");
        printf("\t\n\n\t\tWelcome !  Good Bye");
        footer();
		break;
	}else{
		printf("\t\n\n\tInvalid Input\n");
		sleep(1);
		system("CLS");
		flag=0;
	}
}while(flag==0);
	return 0;
}


void loadingProgressBar()
{
 system("cls");


    char a = 177, b = 219;
    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\tLoading...\n\n");
    printf("\t\t");

    int i;
    for (i = 0; i < 26; i++)
        printf("%c", a);

    printf("\r");
    printf("\t\t");

    for (i = 0; i < 26; i++)
    {
        printf("%c", b);
        Sleep(50);
    }
}

void header(){
    system("CLS");


	printf("\n");
	printf("\n\n");
    int i=0;
    printf("\t");
	for(i=0; i<=35; i++){

        printf("%c",219);
	}

	printf("\n\n\n");
	printf("\t");

	for(i=0; i<=35; i++){

        printf("%c",236);
	}

    printf("\n\n\n\t\tGURUKULA BOOK SHOP\n\n");

	printf("\n\n\t-----------------------------------\n\n");

}

void header2(){

    system("CLS");


	printf("\n");
	printf("\n\n");

    printf("\n");
	printf("\n\n");
    int i=0;
    printf("\t");
	for(i=0; i<=77; i++){

        printf("%c",219);
	}

	printf("\n\n\n");
	printf("\t");

	for(i=0; i<=77; i++){

        printf("%c",236);
	}


    printf("\n\n\t\t\t\t  GURUKULA BOOK SHOP\n\n");

	printf("\n\n\t\t\t  -----------------------------------\n\n");
}

void footer(){

        printf("\n\n");
        printf("\n\n");

         int i=0;
    printf("\t");
	for(i=0; i<=35; i++){

        printf("%c",236);
	}

	printf("\n\n\n");
	printf("\t");

	for(i=0; i<=35; i++){

        printf("%c",219);
	}

	printf("\n\n\n");

for(i=0; i<5; i++){
    printf("\t%c",254);
    sleep(1);
}

      printf("\n");
}

void Register(void){
	int i,found;
	sleep(1);
	system("CLS");
	system("COLOR 09");

	char password[10];

	FILE *file1;
	FILE *file2;
	file1=fopen("customer.dat","a");
	file2=fopen("order.dat","a");
	struct data d;
	struct order o;

		if(file1==NULL)
        {
        printf("File could not be opened\n");
        exit(1);
        }

	do{
    header();
    printf("\t\t   Registration");
    printf("\n\t-----------------------------------\n");
	printf("\n\n\tEnter Your First name : ");
	scanf("%s",&d.fname);
	i=1;
	found=validation(d.fname,i);
	if(found==0){

	printf("\n\n\tInvalid Input try Again");
	sleep(1);
	system("CLS");
	}

	}while(found==0);



	do{

    header();
    printf("\t\t   Registration");
    printf("\n\t-----------------------------------\n");
	printf("\n\tEnter Your Last name : ");
	scanf(" %s",d.lname);
	i=1;
	found=validation(d.lname,i);
	if(found==0){

	printf("\n\n\tInvalid Input try Again");
	sleep(1);
	system("CLS");
	}

	}while(found==0);


	do{

	header();
    printf("\t\t   Registration");
    printf("\n\t-----------------------------------\n");
	printf("\n\tEnter Your Mobile Phone Number : ");
	scanf("%s",d.phone);
	i=2;
	found=validation(d.phone,i);
	if(found==0 || strlen(d.phone)!=10 || d.phone[0]!='0' || d.phone[1]!='7'){
		found=0;
	printf("\n\n\tInvalid Input try Again");
	sleep(1);
	system("CLS");
	}

	int found4=0;
    int i=1;

    found4=alreadyValidation(d.phone,i);
    if(found4==1){
        found=0;
        printf("\n\n\tAlready Added Number. Try Again");
        sleep(1);
        }
	}while(found==0);



	int v=0;
do{
    v=1;


	do{

    header();
    printf("\t\t   Registration");
    printf("\n\t-----------------------------------\n");
    int found1=0,j=0;
	printf("\n\tEnter Your NIC : ");
	scanf("%s",d.nic);
	i=3;
	j=2;
	found=validation(d.nic,i);

    if(found==0 || strlen(d.nic)!=10){
        found=0;
        printf("\n\n\tInvalid Input try Again");
        sleep(1);
        system("CLS");

	}

	found1=validation(d.nic,j);


	if(found1==1 && strlen(d.nic)==10 && (d.nic[0]!='1'|| d.nic[0]!='9'|| d.nic[0]!='3'||d.nic[0]!='4'||d.nic[0]!='5'||d.nic[0]!='6'||d.nic[0]!='7'||d.nic[0]!='8'||d.nic[0]!='0')){
        found=1;
	}else if(found1==0 && (strlen(d.nic)==10) && (d.nic[9]=='v' || d.nic[9]=='V') && (d.nic[0]!='1'|| d.nic[0]!='2'|| d.nic[0]!='3'||d.nic[0]!='4'||d.nic[0]!='5'||d.nic[0]!='6'||d.nic[0]!='7'||d.nic[0]!='8'||d.nic[0]!='0')){
	    int u=0;
	    found=1;
	    for(u=0; u<=8; u++){
            if(!isdigit(d.nic[u])){
                found=0;
                printf("\n\n\tInvalid Input try Again");
                sleep(1);
                system("CLS");
                }
	    }
	}else{
	    found=0;
	    printf("\n\n\tInvalid Input try Again");
        sleep(1);
        system("CLS");
	}

	}while(found==0);


	int found4=0;
    int i=2;

    found4=alreadyValidation(d.nic,i);
    if(found4==1){
        v=0;
        printf("\n\n\tAlready Added NIC. Try Again");
        sleep(2);
        }

}while(v==0);



	do{

	header();
    printf("\t\t   Registration");
    printf("\n\t-----------------------------------\n");
	printf("\n\tEnter Your City : ");
	scanf("%s",d.city);
	i=1;
	found=validation(d.city,i);
	if(found==0){

	printf("\n\n\tInvalid Input try Again");
	sleep(1);
	system("CLS");
	}
	}while(found==0);



	int temp, status;

	header();
    printf("\t\t   Registration");
    printf("\n\t-----------------------------------\n");
	printf("\n\tEnter Your Age : ");
	status=scanf("%d",&d.age);

	while(status!=1){

		while((temp=getchar()) != EOF && temp != '\n');
			printf("\n\n\tInvalid Input try Again");
			sleep(1);
			header();
            printf("\t\t   Registration");
            printf("\n\t-----------------------------------\n");
			printf("\n\tEnter Your Age : ");
			status = scanf("%d", &d.age);
	}



do{
    v=1;
    int h=0;
    int m=0;

    do{
        do{
        h=0;
        m=1;
        header();
        printf("\t\t   Registration");
        printf("\n\t-----------------------------------\n\n");

        printf("\tEnter password(Above 6 characters): ");
        scanf("%s",d.password);

        if(strlen(d.password)<7){
           m=0;
           printf("\n\n\tPassword Shortly. Try Again");
           sleep(2);
        }

        }while(m==0);


        printf("\n\tRe enter password : ");
        scanf("%s",password);



        h=strcmp(password,d.password);


        if(h!=0){
        h=1;
        printf("\n\tYour Confirm Password is Incorrect. Try Again\n\n");
        sleep(1);
        }

        }while(h!=0);

        int found4=0;
        int i=3;

        found4=alreadyValidation(d.password,i);
        if(found4==1){
        v=0;
        printf("\n\n\tAlready Added Password. Try Again");
        sleep(2);
        }

}while(v==0);



        fprintf(file1,"%s %s %s %s %s %d %s\n",d.fname,d.lname,d.nic,d.phone,d.city,d.age,d.password);

        fclose(file1);

        printf("\n\n");

        login();
    }


int validation(char *name, int id){
	int numbers=0;
	int characters=0;
	int i;

	switch(id){

		case 1:
		for(i=0; i<strlen(name);i++){

		if(!isalpha(name[i]))
		return 0;
		}
		return 1;
		break;



		case 2:
		for(i=0; i<strlen(name); i++){

		if(isdigit(name[i]))
		return 1;
		}
		return 0;
		break;

		case 3:
        for(i=0; i<strlen(name);i++){

		if(!isalnum(name[i]))
		return 0;
		}
		return 1;
		break;
	}

}


int alreadyValidation(char *name ,int id){

    FILE *file1;
	file1=fopen("customer.dat","r");
	struct data d;


   	fscanf(file1,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password);

   	while(!feof(file1)) {

        switch(id){

        case 1:
   		if(strcmp(name,d.phone)==0){
		   return 1;
        break;
   		}

        case 2:
   		if(strcmp(name,d.nic)==0){
		   return 1;
        break;
   		}

   		case 3:
   		if(strcmp(name,d.password)==0){
		   return 1;
        break;
   		}
    }
    fscanf(file1,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password);
   }
	fclose(file1);

}


void findPassword(){

	system("COLOR 0E");

	char nic[20];
	header();

    printf("\t\t   Find Password");
    printf("\n\t-----------------------------------\n");

    printf("\n\tEnter  your NIC: ");
	scanf("%s",nic);
	struct data d;
	FILE *file1;

   	file1=fopen("customer.dat","r");

   	 fscanf(file1,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );
   	while(!feof(file1)) {
   			if(strcmp(nic,d.nic)==0){
                    header();
		   	printf("\n\tUser Name  : %s",d.fname);
   			printf("\n\tPassword   : %s",d.password);
            printf("\n\t-----------------------------------");
   			printf("\n\n\tPress any key to Login");
            getch();
            login();
   		}
     fscanf(file1,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );
   }


   if(strcmp(nic,d.nic)!=0 ){
            printf("\n");
   			printf("\tInvalid NIC\n");
   			sleep(2);

            int i=0,choice=0;
          do{

            i=1;

            header();
            printf("\tIf You Forgot Your NIC. You Can, \n");
            printf("\n\t-----------------------------------\n");
            printf("\t1. Try Again \n");
            printf("\t2. Create New Account \n");
            printf("\t3. Exit \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tWhat do you want (1 or 2): ");
            scanf("%d",&choice);

            if(choice==1){
                findPassword();
            }else if(choice==2){
                Register();
            }else if(choice==3){
                system("CLS");
                printf("\t\n\n\t\tWelcome !  Good Bye");
                footer();
                sleep(1);
                exit(1);
            }else{
                printf("\t\n\n\tInvalid Input\n");
                sleep(1);
                i=0;
                system("CLS");
            }

		   }while(i==0);



   		}


	fclose(file1);

	printf("\n");


}

void login(){

	loadingProgressBar();

	system("COLOR 0B");
    header();

    printf("\t\t    Login");
    printf("\n\t-----------------------------------\n");

	char password1[10];
	char name[10];

	FILE *file1;
	file1=fopen("customer.dat","r");
	struct data d;

    FILE *file2;

	struct order o;


	printf("\n\n\tEnter your User Name(First Name) : ");
	scanf("%s",name);


	printf("\n\tEnter  your password : ");
	scanf("%s",password1);


   	fscanf(file1,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password);

   	while(!feof(file1)) {


   		if((strcmp(name,d.fname)==0) && (strcmp(password1,d.password)==0)){
            int i=0,choice=0;

            file2=fopen("order.dat","a");
            strcpy(o.fname,d.fname);
            strcpy(o.nic,d.nic);
             fprintf(file2,"%s %s",o.fname,o.nic);
            fclose(file2);

          do{

            i=1;

            header();
            printf("\t\t   Welcome");
            printf("\n\t-----------------------------------\n");
            printf("\n\tDo you want to : \n\n");
            printf("\t1. View Profile \n");
            printf("\t2. Main Menu \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tWhat do you want (1 or 2): ");
            scanf("%d",&choice);

            if(choice==1){
                profile(name,password1);
                sleep(1);
            }else if(choice==2){
                customerMenu();
            }else{
                printf("\t\n\n\tInvalid Input\n");
                sleep(1);
                i=0;
                system("CLS");
            }

		   }while(i==0);
   		}

		  fscanf(file1,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password);
   }

   		if((strcmp(name,d.fname)!=0) || (strcmp(password1,d.password)!=0) ){
            printf("\n");
   			printf("\tInvalid User Name or Password\n");
   			sleep(1);

   			count=count+1;

            if(count>=2){

            int i=0,choice=0;
          do{

            i=1;

            header();
            printf("\tIf You Forgot Your User Name or Password. You Can, \n");
            printf("\n\t-----------------------------------\n");
            printf("\t1. Login Again \n");
            printf("\t2. Find Password \n");
            printf("\t3. Exit \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tWhat do you want (1 or 2): ");
            scanf("%d",&choice);

            if(choice==1){
                login();
            }else if(choice==2){
                findPassword();
            }else if(choice==3){
                system("CLS");
                printf("\t\n\n\t\tWelcome !  Good Bye");
                footer();
                sleep(1);
                exit(1);
            }else{
                printf("\t\n\n\tInvalid Input\n");
                sleep(1);
                i=0;
                system("CLS");
            }

		   }while(i==0);

            }else{
                login();
            }


   		}

	fclose(file1);

	printf("\n");

}

void adminLogin(){

   int i=0;
    loadingProgressBar();
    system("CLS");
do{
    i=0;
	system("CLS");
	system("COLOR 0B");
    header();

	char password1[10];
	char name[10];

	printf("\n\n\tEnter your User Name: ");
	scanf("%s",name);


	printf("\n\tEnter  your password : ");
	scanf("%s",password1);


	if((strcmp(name,"admin")==0) && (strcmp(password1,"admin123")==0) ){

		printf("\n\tPress any key to login\n");
		getch();
		system("CLS");
		system("COLOR 0B");
        adminMenu();

    }else{
        printf("\t\n\n\tInvalid User Name or Password. Try Again\n");
        sleep(2);
        i=1;
    }
    }while(i==1);

}


void profile(char name[20],char password1[20]){


	system("COLOR 0E");

	header();

    printf("\t\t   My Profile");
    printf("\n\t-----------------------------------\n");

	struct data d;
	FILE *file1;

   	file1=fopen("customer.dat","r");

   	 fscanf(file1,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );
   	while(!feof(file1)) {
   			if((strcmp(name,d.fname)==0) && (strcmp(password1,d.password)==0) ){
		   	printf("\n\tFirst Name : %s",d.fname);
   			printf("\n\tLast Name  : %s",d.lname);
   			printf("\n\tNIC        : %s",d.nic);
   			printf("\n\tPhone Num  : %s",d.phone);
   			printf("\n\tCity       : %s",d.city);
   			printf("\n\tAge        : %d",d.age);
   			printf("\n\tPassword   : %s",d.password);
            printf("\n\t-----------------------------------");
   			printf("\n\n\tPress any key view Menu");
            getch();
            system("CLS");

            int i=0,choice=0;
            do{

            i=1;

            header();
            printf("\t\t    Welcome");
            printf("\n\t-----------------------------------\n");
            printf("\n\tDo you want to : \n\n");
            printf("\t1. View Profile \n");
            printf("\t2. Update Profile \n");
            printf("\t3. Delete Account \n");
            printf("\t4. Main Menu \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tWhat do you want : ");
            scanf("%d",&choice);

            if(choice==1){
                profile(name,password1);
                sleep(1);
            }else if(choice==2){
                updateProfile(name,password1);
            }else if(choice==3){
                deleteProfile(name,password1);
            }else if(choice==4){
                customerMenu();
            }else{
                printf("\t\n\n\tInvalid Input\n");
                sleep(1);
                i=0;
                system("CLS");
            }

		   }while(i==0);

   		}
     fscanf(file1,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );
   }

	fclose(file1);

	printf("\n");


}

void updateProfile(char name[20],char password1[20]){

char name1[20];
char password2[20];

    system("COLOR 0B");

	header();

    printf("\t\t   My Profile");
    printf("\n\t-----------------------------------\n");

	struct data d;
	FILE *file1;
    FILE *file2;

   	file1=fopen("customer.dat","r");
   	file2=fopen("updateProfile.dat","w");

   	 fscanf(file1,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );
   	while(!feof(file1)) {
   			if((strcmp(name,d.fname)==0) && (strcmp(password1,d.password)==0) ){
		   	printf("\n\tFirst Name : %s",d.fname);
   			printf("\n\tLast Name  : %s",d.lname);
   			printf("\n\tNIC        : %s",d.nic);
   			printf("\n\tPhone Num  : %s",d.phone);
   			printf("\n\tCity       : %s",d.city);
   			printf("\n\tAge        : %d",d.age);
   			printf("\n\tPassword   : %s",d.password);
            printf("\n\t-----------------------------------");
            printf("\n\n\tPress any key to Update");
            getch();
            system("CLS");


            int i,found;

            char password[10];

            do{
            header();
            printf("\t\t  Update Profile");
            printf("\n\t-----------------------------------\n");
            printf("\n\n\tEnter Your First name : ");
            scanf("%s",&d.fname);
            i=1;
            found=validation(d.fname,i);
            if(found==0){

            printf("\n\n\tInvalid Input try Again");
            sleep(1);
            system("CLS");
            }

            }while(found==0);



            do{

            header();
            printf("\t\t  Update Profile");
            printf("\n\t-----------------------------------\n");
            printf("\n\tEnter Your Last name : ");
            scanf(" %s",d.lname);
            i=1;
            found=validation(d.lname,i);
            if(found==0){

            printf("\n\n\tInvalid Input try Again");
            sleep(1);
            system("CLS");
            }

            }while(found==0);


            do{

            header();
            printf("\t\t  Update Profile");
            printf("\n\t-----------------------------------\n");
            printf("\n\tEnter Your Mobile Phone Number : ");
            scanf("%s",d.phone);
            i=2;
            found=validation(d.phone,i);
            if(found==0 || strlen(d.phone)!=10 || d.phone[0]!='0' || d.phone[1]!='7'){
                found=0;
            printf("\n\n\tInvalid Input try Again");
            sleep(1);
            system("CLS");
            }

            int found4=0;
            int i=1;

            found4=alreadyValidation(d.phone,i);
            if(found4==1){
                found=0;
                printf("\n\n\tAlready Added Number. Try Again");
                sleep(2);
                }
            }while(found==0);


            	int v=0;
            do{
                v=1;


                do{

                header();
                printf("\t\t  Update Profile");
                printf("\n\t-----------------------------------\n");
                int found1=0,j=0;
                printf("\n\tEnter Your NIC : ");
                scanf("%s",d.nic);
                i=3;
                j=2;
                found=validation(d.nic,i);

                if(found==0 || strlen(d.nic)!=10){
                    found=0;
                    printf("\n\n\tInvalid Input try Again");
                    sleep(1);
                    system("CLS");

                }

                found1=validation(d.nic,j);


                if(found1==1 && strlen(d.nic)==10){
                    found=1;
                }else if(found1==0 && (strlen(d.nic)==10) && (d.nic[9]=='v' || d.nic[9]=='V') && d.nic[0]!='1'){
                    int u=0;
                    found=1;
                    for(u=0; u<=8; u++){
                        if(!isdigit(d.nic[u])){
                            found=0;
                            printf("\n\n\tInvalid Input try Again");
                            sleep(1);
                            system("CLS");
                            }
                    }
                }else{
                    found=0;
                    printf("\n\n\tInvalid Input try Again");
                    sleep(1);
                    system("CLS");
                }

                }while(found==0);


                int found4=0;
                int i=2;

                found4=alreadyValidation(d.nic,i);
                if(found4==1){
                    v=0;
                    printf("\n\n\tAlready Added NIC. Try Again");
                    sleep(2);
                    }

            }while(v==0);


            do{

            header();
            printf("\t\t  Update Profile");
            printf("\n\t-----------------------------------\n");
            printf("\n\tEnter Your City : ");
            scanf("%s",d.city);
            i=1;
            found=validation(d.city,i);
            if(found==0){

            printf("\n\n\tInvalid Input try Again");
            sleep(1);
            system("CLS");
            }
            }while(found==0);



            int temp, status;

            header();
            printf("\t\t  Update Profile");
            printf("\n\t-----------------------------------\n");
            printf("\n\tEnter Your Age : ");
            status=scanf("%d",&d.age);

            while(status!=1){

                while((temp=getchar()) != EOF && temp != '\n');
                    printf("\n\n\tInvalid Input try Again");
                    sleep(1);
                    header();
                    printf("\t\t  Update Profile");
                    printf("\n\t-----------------------------------\n");
                    printf("\n\tEnter Your Age : ");
                    status = scanf("%d", &d.age);
            }


        do{
            v=1;
            int h=0;
            int m=0;

            do{
                do{
                h=0;
                m=1;
                header();
                printf("\t\t  Update Profile");
                printf("\n\t-----------------------------------\n\n");

                printf("\tEnter password(Above 6 characters): ");
                scanf("%s",d.password);

                if(strlen(d.password)<7){
                   m=0;
                   printf("\n\n\tPassword Shortly. Try Again");
                   sleep(2);
                }

                }while(m==0);


                printf("\n\tRe enter password : ");
                scanf("%s",password);



                h=strcmp(password,d.password);


                if(h!=0){
                h=1;
                printf("\n\tYour Confirm Password is Incorrect. Try Again\n\n");
                sleep(1);
                }

                }while(h!=0);

                int found4=0;
                int i=3;

                found4=alreadyValidation(d.password,i);
                if(found4==1){
                v=0;
                printf("\n\n\tAlready Added Password. Try Again");
                sleep(2);
                }

        }while(v==0);

        strcpy(name1,d.fname);
        strcpy(password2,d.password);
   		}

     fprintf(file2,"%s %s %s %s %s %d %s\n",d.fname,d.lname,d.nic,d.phone,d.city,d.age,d.password);
     fscanf(file1,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );
   }

	fclose(file1);
    fclose(file2);

    file1=fopen("customer.dat","w");
   	file2=fopen("updateProfile.dat","r");


    fscanf(file2,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );

    while(!feof(file2)){
        fprintf(file1,"%s %s %s %s %s %d %s\n",d.fname,d.lname,d.nic,d.phone,d.city,d.age,d.password);
        fscanf(file2,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );
    }

    fclose(file1);
    fclose(file2);

    header();
    printf("\n\n\tPress any key to View Profile");
    getch();
    profile(name1,password2);
	printf("\n");

}

void deleteCProfile(char name[20]){

    system("COLOR 04");

	struct data d;
	FILE *file1;
    FILE *file2;

   	file1=fopen("customer.dat","r");
   	file2=fopen("deleteProfile.dat","w");

    fscanf(file1,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );
   	while(!feof(file1)) {
   			if(strcmp(name,d.nic)!=0){
              fprintf(file2,"%s %s %s %s %s %d %s\n",d.fname,d.lname,d.nic,d.phone,d.city,d.age,d.password);
   		}


     fscanf(file1,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );

   }

	fclose(file1);
    fclose(file2);

    file1=fopen("customer.dat","w");
   	file2=fopen("deleteProfile.dat","r");


    fscanf(file2,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );

    while(!feof(file2)){
        fprintf(file1,"%s %s %s %s %s %d %s\n",d.fname,d.lname,d.nic,d.phone,d.city,d.age,d.password);
        fscanf(file2,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );
    }

    fclose(file1);
    fclose(file2);

    int k=0;

do{
    k=1;
    int choice=0;
	system("COLOR 0D");
    header();
    printf("\n\n\tDeleted Successfully");
    printf("\n\t-----------------------------------\n");
	printf("\t1.View Customer\n");
	printf("\t2.Main Menu\n\n");
	printf("\t-----------------------------------\n\n");

	printf("\tWhat do you want : ");
	scanf("%d",&choice);

	if(choice==1){
        viewCustomers();
	}else if(choice==2){
	    adminMenu();
	}else{
	    printf("\t\n\n\tInvalid Input\n");
		sleep(1);
		k=0;
		system("CLS");
	}

}while(k==0);
	printf("\n");

}


void deleteProfile(char name[20],char password1[20]){

    system("COLOR 04");

	struct data d;
	FILE *file1;
    FILE *file2;

   	file1=fopen("customer.dat","r");
   	file2=fopen("deleteProfile.dat","w");

    fscanf(file1,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );
   	while(!feof(file1)) {
   			if((strcmp(name,d.fname)!=0) && (strcmp(password1,d.password)!=0) ){
              fprintf(file2,"%s %s %s %s %s %d %s\n",d.fname,d.lname,d.nic,d.phone,d.city,d.age,d.password);
   		}


     fscanf(file1,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );

   }

	fclose(file1);
    fclose(file2);

    file1=fopen("customer.dat","w");
   	file2=fopen("deleteProfile.dat","r");


    fscanf(file2,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );

    while(!feof(file2)){
        fprintf(file1,"%s %s %s %s %s %d %s\n",d.fname,d.lname,d.nic,d.phone,d.city,d.age,d.password);
        fscanf(file2,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );
    }

    fclose(file1);
    fclose(file2);

    int k=0;

do{
    k=1;
    int choice=0;
	system("COLOR 0D");
    header();

    printf("\n\n\tDeleted Successfully");
    printf("\n\t-----------------------------------\n");
	printf("\t1.Register Again\n");
	printf("\t2.Exit\n\n");
	printf("\t-----------------------------------\n\n");

	printf("\tWhat do you want : ");
	scanf("%d",&choice);

	if(choice==1){
        Register();
	}else if(choice==2){
	    system("CLS");
        printf("\t\n\n\t\tWelcome !  Good Bye");
        footer();
        exit(1);
	}else{
	    printf("\t\n\n\tInvalid Input\n");
		sleep(1);
		k=0;
		system("CLS");
	}

}while(k==0);
	printf("\n");

}


void customerMenu(){

    loadingProgressBar();
    int k=0;
    char name[20];
    char password1[20];
do{
    k=1;
    int choice=0;
	system("COLOR 0B");
    header();

    printf("\t\t      Menu");
    printf("\n\t-----------------------------------\n");
	printf("\t1.View Profile\n");
	printf("\t2.Update Profile\n");
	printf("\t3.View Books\n");
	printf("\t4.Buy Books\n");
	printf("\t5.Search Books\n");
	printf("\t6.View Discount\n");
	printf("\t7.View Delivery Details\n");
	printf("\t8.Exit\n\n");
	printf("\t-----------------------------------\n\n");

	printf("\tWhat do you want : ");
	scanf("%d",&choice);

	if(choice==1){
        login();
	}else if(choice==2){
	    login();
	}else if(choice==3){

                        int found2=0,choice=0,found1=0,found3=0;
                        do{
                            found1=0;
                            header();

                            printf("\t\t  View Books");
                            printf("\n\t-----------------------------------\n\n");

                            printf("\n\tDo you want to View : \n\n");
                            printf("\t1. Novels \n");
                            printf("\t2. Short Stories \n");
                            printf("\t3. Translations \n");
                            printf("\t4. Children Stories \n");
                            printf("\t5. Magazines \n");
                            printf("\t6. All Books \n");
                            printf("\n\t-----------------------------------\n\n");
                            printf("\tEnter Your Choice : ");
                            scanf("%d",&choice);

                    if(choice==1 || choice==2 || choice==3 || choice==4 || choice==5 || choice==6 ){
                        found1=0;
                    }else{
                        found1=1;
                        printf("\n\n\tYou Entered Invalid Number. Try Again");
                        sleep(1);
                        system("CLS");
                    }

                    }while(found1==1);


                    header2();
                    printf("\t\t\t\t     View Books");
                    printf("\n\t\t\t  -----------------------------------\n\n");
                    printf("\tBook ID\t             Name\t             Author\t      Price(Rs)\n\n\n");

                    view(choice);

                printf("\n\n\tPress any key to Main Menu......");
                getch();
                customerMenu();

	}else if(choice==4){
        buyBooks();
	}else if(choice==5){
        searchBooks();
	}else if(choice==6){
        viewDiscounts();
        printf("\n\n\n\tPress any key to Go to Menu......");
        getch();
        customerMenu();

	}else if(choice==7){
        viewDistance();
        printf("\n\n\n\tPress any key to Go to Menu......");
        getch();
        customerMenu();

	}else if(choice==8){
        system("CLS");
        printf("\t\n\n\t\tWelcome !  Good Bye");
        footer();
        exit(1);
    }else{
	    printf("\t\n\n\tInvalid Input\n");
		sleep(1);
		k=0;
		system("CLS");
	}

}while(k==0);

}

void searchBooks(){

    char bookName[100];
    double price=0;
    int bookid=0;
    struct book b;
    int j=0,found=0,status=0,temp=0,quantity=0;
    int i=0,choice=0;

do{
    j=0;
    found=0;
    header();
    printf("\t\t   Search Book");
    printf("\n\t-----------------------------------\n");
    fflush(stdin);
	printf("\n\n\tEnter Book Name : ");
	scanf("%[^\n]s",&bookName);

	FILE *file1;

    file1=fopen("books.dat","r");

   	while(fread(&b,sizeof(struct book),1,file1)) {

   		if(strcmp(b.bookName,bookName)==0){
        price=b.price;
        bookid=b.bookId;
        j=1;

        header2();
        printf("\t\t\t\t     Search Books");
        printf("\n\t\t\t  -----------------------------------\n\n");
        printf("\tBook ID\t             Name\t             Author\t      Price(Rs)\n\n\n");
        printf("\t%d\t %20s\t %20s\t    Rs %8.2lf\n",b.bookId,b.bookName,b.authorName,b.price);

        printf("\n\n\tPress any key to View Menu......");
        getch();


            do{

            i=1;

            header();
            printf("\t\t    Search Books");
            printf("\n\t-----------------------------------\n");
            printf("\n\tDo you want to : \n\n");
            printf("\t1. Buy This \n");
            printf("\t2. Search Again \n");
            printf("\t3. Main Menu \n");
            printf("\t4. Exit \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tWhat do you want : ");
            scanf("%d",&choice);

            if(choice==1){

                    found=0;
                        i=0;
                        header();

                        printf("\t\t  Search Books");
                        printf("\n\t-----------------------------------\n\n");
                        printf("\n\tEnter Quantity : ");
                        status=scanf("%d",&quantity);

                        while(status!=1){

                            while((temp=getchar()) != EOF && temp != '\n');
                                printf("\n\n\tInvalid Input try Again");
                                sleep(1);
                                header();

                                printf("\t\t  Search Books");
                                printf("\n\t-----------------------------------\n\n");
                                printf("\n\tEnter Quantity : ");
                                status=scanf("%d",&quantity);
                        }

                shoppingCart(bookid,quantity);
                sleep(1);
            }else if(choice==2){
                found=1;
            }else if(choice==3){
                customerMenu();
            }else if(choice==4){
                system("CLS");
                printf("\t\n\n\t\tWelcome !  Good Bye");
                footer();
                exit(1);
            }else{
                printf("\t\n\n\tInvalid Input\n");
                sleep(1);
                i=0;
                system("CLS");
            }

		   }while(i==0);
   		}
    }

	fclose(file1);

	if(j==0){
      printf("\n\tThis Book Does Not Exit.\n\n");
      sleep(1);

                    do{

                    i=1;

                    header();
                    printf("\t\t    Search Books");
                    printf("\n\t-----------------------------------\n");
                    printf("\n\tDo you want to : \n\n");
                    printf("\t1. Try Again \n");
                    printf("\t2. Main Menu \n");
                    printf("\t3. Exit \n");
                    printf("\n\t-----------------------------------\n\n");
                    printf("\tWhat do you want : ");
                    scanf("%d",&choice);

                    if(choice==1){
                            found=1;
                    }else if(choice==2){
                       customerMenu();
                    }else if(choice==3){
                        system("CLS");
                        printf("\t\n\n\t\tWelcome !  Good Bye");
                        footer();
                        exit(1);
                    }else{
                        printf("\t\n\n\tInvalid Input\n");
                        sleep(1);
                        i=0;
                        system("CLS");
                    }

                   }while(i==0);

	}
}while(found==1);

}

void buyBooks(){

   system("COLOR 0F");
   loadingProgressBar();

    struct book b;

    int found2=0,choice=0,found1=0,found3=0;
    int bookid,found=0,i=0,quantity=0;
    double total=0;
    int temp, status;


        do{
            found1=0;
            header();

            printf("\t\t  Buy Books");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tDo you want to Buy : \n\n");
            printf("\t1. Novels \n");
            printf("\t2. Short Stories \n");
            printf("\t3. Translations \n");
            printf("\t4. Children Stories \n");
            printf("\t5. Magazines \n");
            printf("\t6. All Books \n");
            printf("\t7. Search Books \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&choice);

    if(choice==1 || choice==2 || choice==3 || choice==4 || choice==5 || choice==6 ){
        found1=0;
    }else if(choice==7){
        searchBooks();
    }else{
        found1=1;
        printf("\n\n\tYou Entered Invalid Number. Try Again");
        sleep(1);
        system("CLS");
	}

	}while(found1==1);


    header2();
    printf("\t\t\t\t     Buy Books");
    printf("\n\t\t\t  -----------------------------------\n\n");
    printf("\tBook ID\t             Name\t             Author\t      Price(Rs)\n\n\n");

    view(choice);

printf("\n\n\tPress any key to Enter Book ID......");
getch();

do{
    found=0;
    i=0;
    header();

    printf("\t\t  Buy Books");
    printf("\n\t-----------------------------------\n\n");
	printf("\n\tEnter Book ID to Buy : ");
	status=scanf("%d",&bookid);

	while(status!=1){

		while((temp=getchar()) != EOF && temp != '\n');
			printf("\n\n\tInvalid Input try Again");
			sleep(1);
			header();

            printf("\t\t  Buy Books");
            printf("\n\t-----------------------------------\n\n");
            printf("\n\tEnter Book ID to Buy : ");
            status=scanf("%d",&bookid);
	}

	int count1=0;

    count1=(bookid==0)?1:log10(bookid)+1;

	if(count1<5){
        i=1;
        printf("\n\n\tShortly Number. Try Again");
        sleep(1);
	}

	found=bookIdAlreadyValidation(bookid);

	if(found==0){
        i=1;
        printf("\n\n\tThe Book id Does Not Exist. Try Again");
        sleep(1);
	}


}while(i==1);



    found=0;
    i=0;
    header();

    printf("\t\t  Buy Books");
    printf("\n\t-----------------------------------\n\n");
	printf("\n\tEnter Quantity : ");
	status=scanf("%d",&quantity);

	while(status!=1){

		while((temp=getchar()) != EOF && temp != '\n');
			printf("\n\n\tInvalid Input try Again");
			sleep(1);
			header();

            printf("\t\t  Buy Books");
            printf("\n\t-----------------------------------\n\n");
            printf("\n\tEnter Quantity : ");
            status=scanf("%d",&quantity);
	}


	do{
            found1=0;
            header();

            printf("\t\t  Buy Books");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tDo you want to  : \n\n");
            printf("\t1. Add to Cart \n");
            printf("\t2. Reject and Buy New One \n");
            printf("\t3. Exit\n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&choice);

            int success=0;

    if(choice==1){
        shoppingCart(bookid,quantity);

    }else if(choice==2){
        buyBooks();
    }else if(choice==3){
        system("CLS");
        printf("\t\n\n\t\tWelcome !  Good Bye");
        footer();
        exit(1);
    }else{
        found1=1;
        printf("\n\n\tYou Entered Invalid Number. Try Again");
        sleep(1);
        system("CLS");
	}

	}while(found1==1);


}

void shoppingCart(int bookid, int quantity){

    struct book b;
    struct discount d;
    struct order o;

    int found=0,found1=0,choice=0;

    FILE *file1;
	FILE *file7;
	FILE *file8;
	FILE *file9;


	    file1=fopen("books.dat","r");
	    file7=fopen("cart.dat","a");


		if(file1==NULL || file7==NULL)
        {
        printf("File could not be opened\n");
        exit(1);
        }

       while(fread(&b,sizeof(struct book),1,file1)){

         if(bookid==b.bookId){
               b.quantity=quantity;
               b.total=b.price*quantity;
               total=total+b.total;
               fwrite(&b,sizeof(struct book),1,file7);

            }
        }
        fclose(file1);
        fclose(file7);

	    file7=fopen("cart.dat","r");

	    header2();
        printf("\t\t\t\t       My Cart");
        printf("\n\t\t\t  -----------------------------------\n\n");
        printf("\tBook ID\t\t          Name\t     Price(Rs)\t  Quantity\tTotal(Rs)\n\n");

        while(fread(&b,sizeof(struct book),1,file7)){
                printf("\t%d\t %20s\t  %10.2lf\t %4d        %12.2lf\n",b.bookId,b.bookName,b.price,b.quantity,b.total);

            }
        fclose(file7);

        double discountPrice=0,discount=0;
        file8=fopen("discount.dat","r");

          while(fread(&d,sizeof(struct discount),1,file8)){

         if(total>=d.price){
               discount=d.rate;
               discountPrice=((d.rate)/100)*total;
            }
        }
        fclose(file8);
            double amount=0;
            amount=total-discountPrice;

        printf("\n\n\t-------------------------------------------------------------------------");
        printf("\n\tMy Total     is      \t\t\t\t\t: Rs %.2lf",total);
        printf("\n\tMy Discount Rate is  \t\t\t\t\t: %.lf %%",discount);
        printf("\n\tMy Discount  is      \t\t\t\t\t: Rs %.2lf",discountPrice);
        printf("\n\tMy Amount    is      \t\t\t\t\t: Rs %.2lf",amount);



          printf("\n\n\n\tPress any key to Go to Menu......");
          getch();


            do{
            found1=0;
            header();

            printf("\t\t  Buy Books");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tDo you want to  : \n\n");
            printf("\t1. Buy Again \n");
            printf("\t2. View Discount \n");
            printf("\t3. Go to Payment \n");
            printf("\t4. Reject and Go to main Menu \n");
            printf("\t5. Remove item From Cart \n");

            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&choice);

            if(choice==1){
                buyBooks();
            }else if(choice==2){
                viewDiscounts();
                printf("\n\n\n\tPress any key to Go to View Menu......");
                getch();
                found1=1;
            }else if(choice==3){

                /*file9=fopen("order.dat","a");
                fwrite(&o,sizeof(struct order),1,file9);
                fclose(file9);*/

                makePayment(total,discountPrice,amount,discount);
            }else if(choice==4){
                total=0;
                remove("cart.dat");
                customerMenu();
	}else if(choice==5){

	}else{
	    printf("\t\n\n\tInvalid Input\n");
		sleep(1);
		found1=1;
		system("CLS");
	}


	}while(found1==1);

}

void makeReport(){

    	FILE *file10;
    	FILE *file7;
    	FILE *file2;
    	FILE *file11;

    	struct order o;
    	struct report r;
    	struct book b;

    	char nic[10];
    	char address[100];
    	double dcost;

  file2=fopen("order.dat","r");

    fscanf(file2,"%s %s %lf %[^\n]s",o.fname,o.nic,&o.deliveryCost,o.address);
    strcpy(nic,o.nic);
    strcpy(address,o.address);
    dcost=o.deliveryCost;
    fclose(file2);


    	file10=fopen("admin.dat","a");
    	file7=fopen("cart.dat","r");
        file11=fopen("allboook.dat","a");

       while(fread(&b,sizeof(struct book),1,file7)){

               strcpy(r.address,address);
               r.dcost=dcost;
               r.price=b.price;
               r.quantity=b.quantity;
               r.bookId=b.bookId;
               strcpy(r.nic,nic);

               fprintf(file10,"%d %lf %d %lf %s %s\n",r.quantity,r.dcost,r.bookId,r.price,r.nic,r.address);
               fwrite(&b,sizeof(struct book),1,file11);
        }

        fclose(file7);
        fclose(file10);
        fclose(file11);

}

void makePayment(double total, double discountPrice, double amount,double rate){

    struct book b;
    int found1=0;
    int choice =0;
    FILE *file7;
    FILE *file8;

    file7=fopen("cart.dat","r");


	    header2();
        printf("\t\t\t\t       My Bill");
        printf("\n\t\t\t  -----------------------------------\n\n");
        printf("\tBook ID\t\t          Name\t     Price(Rs)\t  Quantity\tTotal(Rs)\n\n");

        while(fread(&b,sizeof(struct book),1,file7)){
                printf("\t%d\t %20s\t  %10.2lf\t %4d        %12.2lf\n",b.bookId,b.bookName,b.price,b.quantity,b.total);

            }
        fclose(file7);

        printf("\n\n\t-------------------------------------------------------------------------");
        printf("\n\tMy Total     is      \t\t\t\t\t: Rs %.2lf",total);
        printf("\n\tMy Discount Rate is  \t\t\t\t\t: %.lf %%",rate);
        printf("\n\tMy Discount  is      \t\t\t\t\t: Rs %.2lf",discountPrice);
        printf("\n\tMy Amount    is      \t\t\t\t\t: Rs %.2lf",amount);

        printf("\n\n\n\tPress any key to Go to Delivery......");
        getch();

        struct delivery d;
        double cost=0,fullamount=0;

        deliveryProduct();

            file8=fopen("delivery.dat","r");

            header();
            printf("\t\t   My Bill");
            printf("\n\t-----------------------------------\n");

            while(fread(&d,sizeof(struct delivery),1,file8)){

            printf("\n\tAddress  : %s",d.address);
   			printf("\n\tDistance : %.3lf km",d.distance);
   			printf("\n\tCost     : Rs %.2lf",d.cost);
               cost= d.cost;
            }
            printf("\n\t-----------------------------------");
   			fclose(file8);
   			fullamount=amount+cost;
            printf("\n\tDiscount : Rs %.2lf",discountPrice);
            printf("\n\tAmount   : Rs %.2lf",fullamount);
            printf("\n\n\n\tPress any key to Go to Create Bill......");
            getch();

            printBill(total,discountPrice,amount,rate);

}

void payOnline(double amount){

    int i=0,found;

	system("CLS");
	system("COLOR 09");

	FILE *file1;
	file1=fopen("payonline.dat","a");

	struct data d;
    struct payOnline p;

    int j=0;

do{
    j=1;


    do{

	header();
    printf("\t\t   Pay Online");
    printf("\n\t-----------------------------------\n");
    printf("\n\tEnter Your Card Number  ");
	printf("\n\t16 Numbers(no Spaces)  : ");
	scanf("%s",p.cardNumber);
	i=2;
	found=validation(p.cardNumber,i);
	if(found==0 || strlen(p.cardNumber)!=16){
		found=0;
	printf("\n\n\tInvalid Input try Again");
	sleep(1);
	system("CLS");
        }

	}while(found==0);



    header();
    printf("\t\t   Pay Online");
    printf("\n\t-----------------------------------\n");
    fflush(stdin);
	printf("\n\n\tEnter Card Holder Name : ");
	scanf("%[^\n]s",&p.name);




		int flag=1,m,y,status,temp,found=1;

do{


	do{

	flag=1;
	found=1;
    header();
    printf("\t\t   Pay Online");
    printf("\n\t-----------------------------------\n");
	printf("\n\tEnter Expire Year(20xx) : ");
	status =scanf("%d",&p.year);

	while(status!=1){

		while((temp=getchar()) != EOF && temp != '\n');
		printf("\n\tInvalid input... \n ");
		sleep(1);
		header();
        printf("\t\t   Pay Online");
        printf("\n\t-----------------------------------\n");
        printf("\n\tEnter Expire Year(20xx) : ");
		status = scanf("%d", &p.year);
	}

		if(p.year<2000){
			printf("\n\tYour Card Was Expired.Try Again\n ");
			sleep(1);
		found=0;
	}


}while(found==0);

do{

	found=1;
	header();
    printf("\t\t   Pay Online");
    printf("\n\t-----------------------------------\n");
	printf("\n\tEnter Expire Month(mm) : ");
	status =scanf("%d",&p.month);

	while(status!=1){

		while((temp=getchar()) != EOF && temp != '\n');
		printf("\n\tInvalid input... \n ");
		sleep(1);
		header();
        printf("\t\t   Pay Online");
        printf("\n\t-----------------------------------\n");
        printf("\n\tEnter Expire Month(mm) : ");
		status = scanf("%d", &p.month);
	}

	if(p.month>12 || p.month<1){
			printf("\n\t Invalid Month. Try Again\n ");
			sleep(1);
		found=0;
	}

}while(found==0);


	time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);



 if((tm.tm_year+1900==p.year && tm.tm_mon+1>p.month)||(tm.tm_year+1900>p.year))
 {
 	printf("Your Card is Already Expired. Try Again\n ");
 	sleep(1);
 	flag=0;

 }

}while(flag==0);



	do{

	header();
    printf("\t\t   Pay Online");
    printf("\n\t-----------------------------------\n");
	printf("\n\tEnter Your Mobile Phone Number : ");
	scanf("%s",p.phone);
	i=2;
	found=validation(p.phone,i);
	if(found==0 || strlen(p.phone)!=10 || p.phone[0]!='0' || p.phone[1]!='7'){
		found=0;
	printf("\n\n\tInvalid Input try Again");
	sleep(1);
	system("CLS");
        }

	}while(found==0);

	int v=0;
do{
    v=1;

	do{

    header();
    printf("\t\t   Pay Online");
    printf("\n\t-----------------------------------\n");
    int found1=0,j=0;
	printf("\n\tEnter Your NIC : ");
	scanf("%s",p.nic);
	i=3;
	j=2;
	found=validation(p.nic,i);

    if(found==0 || strlen(p.nic)!=10){
        found=0;
        printf("\n\n\tInvalid Input try Again");
        sleep(1);
        system("CLS");

	}

	found1=validation(p.nic,j);


	if(found1==1 && strlen(p.nic)==10 && (p.nic[0]!='1'|| p.nic[0]!='9'|| p.nic[0]!='3'||p.nic[0]!='4'||p.nic[0]!='5'||p.nic[0]!='6'||p.nic[0]!='7'||p.nic[0]!='8'||p.nic[0]!='0')){
        found=1;
	}else if(found1==0 && (strlen(d.nic)==10) && (p.nic[9]=='v' || p.nic[9]=='V') && (p.nic[0]!='1'|| p.nic[0]!='2'|| p.nic[0]!='3'||p.nic[0]!='4'||p.nic[0]!='5'||p.nic[0]!='6'||p.nic[0]!='7'||p.nic[0]!='8'||p.nic[0]!='0')){
	   int u=0;
	    found=1;
	    for(u=0; u<=8; u++){
            if(!isdigit(p.nic[u])){
                found=0;
                printf("\n\n\tInvalid Input try Again");
                sleep(1);
                system("CLS");
                }
	    }
	}else{
	    found=0;
	    printf("\n\n\tInvalid Input try Again");
        sleep(1);
        system("CLS");
	}

	}while(found==0);



}while(v==0);


	header();
    printf("\t\t   Pay Online");
    printf("\n\t-----------------------------------\n");
	printf("\n\tEnter CVC Number : ");
	status=scanf("%d",&p.cvc);

	while(status!=1){

		while((temp=getchar()) != EOF && temp != '\n');
			printf("\n\n\tInvalid Input try Again");
			sleep(1);
			header();
            printf("\t\t   Pay Online");
            printf("\n\t-----------------------------------\n");
            printf("\n\tEnter CVC Number : ");
			status = scanf("%d", &p.cvc);
	}



            header();
            printf("\t\t   My Card Details");
            printf("\n\t-----------------------------------\n");
            printf("\n\tHolder Name : %s",p.name);
   			printf("\n\tExpire Year : %d",p.year);
   			printf("\n\tExpire month: %d",p.month);
   			printf("\n\tCVC Number  : %d",p.cvc);
   			printf("\n\tNIC         : %s",p.nic);
   			printf("\n\tPhone Num   : %s",p.phone);


            printf("\n\t-----------------------------------");
   			printf("\n\n\tPress any key view Menu");
            getch();

            int i=0,choice=0;
            do{

            i=1;

            header();
            printf("\t\t   My Card Details");
            printf("\n\t-----------------------------------\n");
            printf("\n\tDo you want to : \n\n");
            printf("\t1. Pay \n");
            printf("\t2. Edit Details \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tWhat do you want : ");
            scanf("%d",&choice);

            if(choice==1){
                j=1;
            }else if(choice==2){
                j=0;
            }else{
                printf("\t\n\n\tInvalid Input\n");
                sleep(1);
                i=0;
                system("CLS");
            }

		   }while(i==0);


  }while(j==0);

        fwrite(&p,sizeof(struct payOnline),1,file1);
        fclose(file1);


            header();
            printf("\t\t   My Payment");
            printf("\n\t-----------------------------------\n");
            printf("\n\tCard value  : Rs %.2lf",cardValue);
   			printf("\n\tFull Amount : Rs %.2lf",amount);
   			printf("\n\tBalanceValue: Rs %.2lf",cardValue-amount);

            printf("\n\n\n\tWe Success Your Order Within 5 Days");
            printf("\n\n\n\tPress Any Key to Exit");
            getch();


    	FILE *file7;
    	FILE *file2;


    	struct order o;

        file2=fopen("order.dat","r");
        file7=fopen("paidCustomers.dat","a");

        fscanf(file2,"%s %s %lf %[^\n]s",o.fname,o.nic,&o.deliveryCost,o.address);

        fwrite(&o,sizeof(struct order),1,file7);
        fclose(file2);
        fclose(file7);

            endAll();


}

void cashOnDelivery(double fullamount){

            struct delivery d;

            FILE *file8;
            file8=fopen("delivey.dat","r");

            header();
            printf("\t\t   My Bill");
            printf("\n\t-----------------------------------\n");

            while(fread(&d,sizeof(struct delivery),1,file8)){

            printf("\n\t Your Address  : %s",d.address);
   			printf("\n\tYour Disrance  : %.3lf km",d.distance);
   			printf("\n\tDelivery Cost  : Rs %.2lf",d.cost);
            }
            printf("\n\t-----------------------------------");
   			fclose(file8);
            printf("\n\tAmount         : Rs %.2lf",fullamount);

            printf("\n\n\n\tWe Success Your Order Within 5 Days");
            printf("\n\n\n\tPress Any Key to Exit");
            getch();

            FILE *file7;
            FILE *file2;

            struct order o;

            file2=fopen("order.dat","r");
            file7=fopen("unpaidCustomers.dat","a");

            fscanf(file2,"%s %s %lf %[^\n]s",o.fname,o.nic,&o.deliveryCost,o.address);

            fwrite(&o,sizeof(struct order),1,file7);
            fclose(file2);
            fclose(file7);

            endAll();

}

void deliveryProduct(){

        system("CLS");
        system("COLOR 0A");

        viewDistance();

        printf("\n\t-----------------------------------");
        printf("\n\n\tPress any key to Add Delivery Details");
        getch();

        int i=0,found;

        FILE *file1;
        FILE *file2;

        file1=fopen("delivery.dat","a");

        struct delivery d;
        struct order o;

        int j=0;

do{
    j=1;

    header();
    printf("\t\t   Delivery");
    printf("\n\t-----------------------------------\n");
    fflush(stdin);
	printf("\n\n\tEnter Your Address : ");
	scanf("%[^\n]s",&d.address);



		double status,temp;


	header();
    printf("\t\t   Delivery");
    printf("\n\t-----------------------------------\n");
	printf("\n\tEnter Distance(Km) : ");
	status=scanf("%lf",&d.distance);

	while(status!=1){

		while((temp=getchar()) != EOF && temp != '\n');
			printf("\n\n\tInvalid Input try Again");
			sleep(1);
			header();
            printf("\t\t   Delivery");
            printf("\n\t-----------------------------------\n");
            printf("\n\tEnter Distance(Km) : ");
            status=scanf("%lf",&d.distance);
	}


	if(d.distance<=10){
        d.cost=0;
	}else if(d.distance<=50){
        d.cost=(d.distance-10)*50;
	}else if(d.distance<=100){
        d.cost=2000+(d.distance-50)*75;
	}else{
        d.cost=5750+(d.distance-100)*100;
	}



            header();
            printf("\t\t   My Delivery");
            printf("\n\t-----------------------------------\n");
            printf("\n\tAddress  : %s",d.address);
   			printf("\n\tDisrance : %.3lf km",d.distance);
   			printf("\n\tCost     : Rs %.2lf",d.cost);


            printf("\n\t-----------------------------------");
   			printf("\n\n\tPress any key view Menu");
            getch();

            int i=0,choice=0;
            do{

            i=1;

            header();
            printf("\t\t   My Delivery");
            printf("\n\t-----------------------------------\n");
            printf("\n\tDo you want to : \n\n");
            printf("\t1. Go to Payments \n");
            printf("\t2. Edit Details \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tWhat do you want : ");
            scanf("%d",&choice);

            if(choice==1){
                    file2=fopen("order.dat","a");
                    strcpy(o.address,d.address);
                    o.deliveryCost=d.cost;
                    fprintf(file2," %lf %s",o.deliveryCost,o.address);
                    fclose(file2);
                    makeReport();
                j=1;
            }else if(choice==2){
                j=0;
            }else{
                printf("\t\n\n\tInvalid Input\n");
                sleep(1);
                i=0;
                system("CLS");
            }

		   }while(i==0);


  }while(j==0);

        fwrite(&d,sizeof(struct delivery),1,file1);

        fclose(file1);

}

void viewDistance(){

            header();

            printf("\n\t\t     Delivery Cost\n\n");
            printf("\t-----------------------------------\n\n");
            printf("\tDistance(Km)                   Cost\n\n");
            printf("\t1-10  Km             Free Of Charge\n");
            printf("\t10-50 Km                  Rs. 50.00\n");
            printf("\t50-100Km                  Rs. 75.00\n");
            printf("\tAbove 100Km               Rs.100.00\n");

}

void adminMenu(){

int k=0,w=0,found=0, found1=0,choice=0;
     do{
        w=0;

            header();

            printf("\n\t\t     Welcome\n\n");
            printf("\t-----------------------------------\n");

            printf("\n\tDo you want to ,");
            printf("\n\t1  View Customers");
            printf("\n\t2  Delete Customers");
            printf("\n\t3  Delete All Customers");
            printf("\n\t4  Add Books");
            printf("\n\t5  View Books");
            printf("\n\t6  Delete Books");
            printf("\n\t7  Update Books");
            printf("\n\t8  Delete All Books");
            printf("\n\t9  Add Discounts");
            printf("\n\t10 View Discounts");
            printf("\n\t11 Delete All Discounts");
            printf("\n\t12 View Sales");
            printf("\n\t13 View paid Customers");
            printf("\n\t14 View Unpaid Customers");
            printf("\n\t15 View Pay Online Details");
            printf("\n\t16 View Bought Books");
            printf("\n\t17 View Payments");
            printf("\n\t18 Exit");

            printf("\n\n\tEnter Your Option : ");
            scanf("%d",&k);


            if(k==1){
                viewCustomers();
            }else if(k==2){
                viewCustomers();
            }else if(k==3){

                do{
            found1=0;
            header();

            printf("\t\t  Delete All");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tAre You Sure  : \n\n");
            printf("\t1. Yes \n");
            printf("\t2. No \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&choice);

            int success=0;

                    if(choice==1){
                        remove("customer.dat");
                        header();

                        printf("\n\t\t    Delete All\n\n");
                        printf("\t-----------------------------------\n");
                        printf("\t\n\n\tDelete All Customers Successfully\n");
                        sleep(1);
                        adminMenu();

                    }else if(choice==2){
                         adminMenu();
                    }else {
                        found1=1;
                        printf("\n\n\tYou Entered Invalid Number. Try Again");
                        sleep(1);
                        system("CLS");
                    }

                    }while(found1==1);

            }else if(k==4){
                addBooks();
            }else if(k==5){
                viewBooks();
            }else if(k==6){
                deleteBooks();
            }else if(k==7){
                updateBooks();
            }else if(k==8){
                do{
            found1=0;
            header();

            printf("\t\t  Delete All");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tAre You Sure  : \n\n");
            printf("\t1. Yes \n");
            printf("\t2. No \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&choice);

            int success=0;

                    if(choice==1){
                        remove("novels.dat");
                        remove("books.dat");
                        remove("magazines.dat");
                        remove("childrenStories.dat");
                        remove("Translations.dat");
                        remove("shortStories.dat");

                        header();

                        printf("\n\t\t    Delete All\n\n");
                        printf("\t-----------------------------------\n");
                        printf("\t\n\n\tDelete All Books Successfully\n");
                        sleep(1);
                        adminMenu();

                    }else if(choice==2){
                         adminMenu();
                    }else {
                        found1=1;
                        printf("\n\n\tYou Entered Invalid Number. Try Again");
                        sleep(1);
                        system("CLS");
                    }

                    }while(found1==1);
            }else if(k==9){
                addDiscount();
            }else if(k==10){
                viewDiscounts();
                printf("\n\n\n\tPress any key to Go to Menu......");
                getch();
                adminMenu();
            }else if(k==11){
                do{
            found1=0;
            header();

            printf("\t\t  Delete All");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tAre You Sure  : \n\n");
            printf("\t1. Yes \n");
            printf("\t2. No \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&choice);

            int success=0;

                    if(choice==1){
                        remove("discount.dat");

                        header();

                        printf("\n\t\t    Delete All\n\n");
                        printf("\t-----------------------------------\n");
                        printf("\t\n\n\tDelete All Discounts Successfully\n");
                        sleep(1);
                        adminMenu();

                    }else if(choice==2){
                         adminMenu();
                    }else {
                        found1=1;
                        printf("\n\n\tYou Entered Invalid Number. Try Again");
                        sleep(1);
                        system("CLS");
                    }

                    }while(found1==1);

            }else if(k==12){
                viewSales();
            }else if(k==13){
                paidCustomers();
            }else if(k==14){
                unpaidCustomers();
            }else if(k==15){
                payonlineCustomers();
            }else if(k==16){
                boughtBooks();
            }else if(k==17){
                viewPayments();
            }else if(k==18){
                system("CLS");
                printf("\t\n\n\t\tWelcome !  Good Bye");
                footer();
                exit(1);
            }else{
                w=1;
                printf("\t\n\n\tInvalid Input Try Again\n");
                sleep(1);
                system("CLS");
            }

        }while(w==1);
}

void viewPayments(){

    double discount;
    double total;
    double deliveryCost;
    double fullAmount;

    FILE *file1;
    struct payments p;

    header2();
    printf("\t\t\t\t     View Payments");
    printf("\n\t\t\t  -----------------------------------\n\n");
    printf("\tTotal\t           Discount\t         Delivery Cost\t      Full Amount\n\n\n");


    file1=fopen("payments.dat","r");

		if(file1==NULL)
        {
        printf("File could not be opened\n");
        exit(1);
        }

        while(fread(&p,sizeof(struct payments),1,file1)){
           printf("\tRs %8.2lf\t    Rs %8.2lf\t         Rs %8.2lf\t      Rs %8.2lf\n",p.total,p.discount,p.deliveryCost,p.fullAmount);

           total=total+p.total;
           discount=discount+p.discount;
           deliveryCost=deliveryCost+p.deliveryCost;
           fullAmount=fullAmount+p.fullAmount;
        }
        fclose(file1);

         printf("\n\t-------------------------------------\n\n");
         printf("\n\tTotal Price is         : Rs %.2lf",total);
         printf("\n\tTotal Discount is      : Rs %.2lf",discount);
         printf("\n\tTotal Delivery Cost is : Rs %.2lf",deliveryCost);
         printf("\n\tFull Amount         is : Rs %.2lf",fullAmount);

            printf("\n\n\n\tPress Any Key to Go to menu");
            getch();
            adminMenu();

}

void boughtBooks(){

    FILE *file1;
    struct book b;

    header2();
    printf("\t\t\t\t     View Books");
    printf("\n\t\t\t  -----------------------------------\n\n");
    printf("\tBook ID\t             Name\t             Author\t      Price(Rs)\n\n\n");


    file1=fopen("allboook.dat","r");

		if(file1==NULL)
        {
        printf("File could not be opened\n");
        exit(1);
        }

        while(fread(&b,sizeof(struct book),1,file1)){
           printf("\t%d\t %20s\t %20s\t    Rs %8.2lf\n",b.bookId,b.bookName,b.authorName,b.price);
        }
        fclose(file1);

        printf("\n\n\n\tPress Any Key to Go to menu");
        getch();
        adminMenu();

}


void paidCustomers(){

            FILE *file7;
            struct order o;


            file7=fopen("paidCustomers.dat","r");

            header();
            printf("\t\t   Paid Customers");
            printf("\n\t-----------------------------------\n");

             while(fread(&o,sizeof(struct order),1,file7)){
            printf("\n\tCustomer Name : %s",o.fname);
   			printf("\n\tCustomer NIC  : %s",o.nic);

            printf("\n\t-----------------------------------");
             }
            fclose(file7);
            printf("\n\n\n\tPress Any Key to Go to menu");
            getch();
            adminMenu();

}

void unpaidCustomers(){

            FILE *file7;
            struct order o;


            file7=fopen("unpaidCustomers.dat","r");

            header();
            printf("\t\t   Unpaid Customers");
            printf("\n\t-----------------------------------\n");

             while(fread(&o,sizeof(struct order),1,file7)){
            printf("\n\tCustomer Name : %s",o.fname);
   			printf("\n\tCustomer NIC  : %s",o.nic);

            printf("\n\t-----------------------------------");
             }
            fclose(file7);
            printf("\n\n\n\tPress Any Key to Go to menu");
            getch();
            adminMenu();

}

void payonlineCustomers(){

            FILE *file7;
            struct payOnline p;


            file7=fopen("payonline.dat","r");

            header();
            printf("\t\t   Paid Online");
            printf("\n\t-----------------------------------\n");

             while(fread(&p,sizeof(struct payOnline),1,file7)){
            printf("\n\tCustomer Name : %s",p.name);
   			printf("\n\tCustomer NIC  : %s",p.nic);
   			printf("\n\tYear          : %d",p.year);
   			printf("\n\tMonth         : %d",p.month);
   			printf("\n\tPhone Number  : %s",p.phone);

            printf("\n\t-----------------------------------");
             }
            fclose(file7);
            printf("\n\n\n\tPress Any Key to Go to menu");
            getch();
            adminMenu();

}

int discountIdAlreadyValidation(int id){

    struct discount d;
    FILE *file1;
	file1=fopen("discount.dat","r");

   	while(fread(&d,sizeof(struct discount),1,file1)) {

   		if(id==d.discountId){
        return 1;
   		}
    }

	fclose(file1);
	return 0;

}

int discountpriceAlreadyValidation(double price){

    struct discount d;
    FILE *file1;
	file1=fopen("discount.dat","r");

   	while(fread(&d,sizeof(struct discount),1,file1)) {

   		if(price==d.price){
        return 1;
   		}
    }

	fclose(file1);
	return 0;

}

int discountpriceAsceingOderMaker(double price){

    struct discount d;
    FILE *file1;
	file1=fopen("discount.dat","r");

   	while(fread(&d,sizeof(struct discount),1,file1)) {

   		if(price<d.price){
        return 1;
   		}
    }

	fclose(file1);
	return 0;

}

void addDiscount(){

    struct discount d;
    int choice=0,i=0,found=0,found1=0,found2=0;
    system("COLOR 0B");

	FILE *file1;


    do{

        file1=fopen("discount.dat","a");

		if(file1==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }
        found2=0;




	int temp, status;
do{

    header();
    printf("\t\t   Add Discount");
    printf("\n\t-----------------------------------\n");

    printf("\n\n\n\tYou Should Add Price Range Ascending Order ");
    printf("\n\tLike 200 Then 300 Then 400..... ");
    printf("\n\n\n\tPress any key to Add Discount......");
    getch();


    found=0;
    i=0;
	header();
    printf("\t\t   Add Discount");
    printf("\n\t-----------------------------------\n");
	printf("\n\tEnter Discount ID : ");
	status=scanf("%d",&d.discountId);

	while(status!=1){

		while((temp=getchar()) != EOF && temp != '\n');
			printf("\n\n\tInvalid Input try Again");
			sleep(1);
			header();
            printf("\t\t   Add Discount");
            printf("\n\t-----------------------------------\n");
            printf("\n\tEnter Discount ID : ");
            status=scanf("%d",&d.discountId);
	}

	int count1=0;

    count1=(d.discountId==0)?1:log10(d.discountId)+1;

	if(count1<3){
        i=1;
        printf("\n\n\tShortly Number. Try Again");
        sleep(1);
	}

	found=discountIdAlreadyValidation(d.discountId);

	if(found==1){
        i=1;
        printf("\n\n\tAlready Added Discount ID. Try Again");
        sleep(1);
	}


}while(i==1);




double temp1, status1;
do{
        i=0;
found=0;
	header();
    printf("\t\t   Add Discount");
    printf("\n\t-----------------------------------\n");
	printf("\n\tEnter Price Range Lower Price : Rs. ");
	status1=scanf("%lf",&d.price);

	while(status1!=1){

		while((temp1=getchar()) != EOF && temp1 != '\n');
			printf("\n\n\tInvalid Input try Again");
			sleep(1);
			header();
            printf("\t\t   Add Discount");
            printf("\n\t-----------------------------------\n");
            printf("\n\tEnter Price Range Lower Price : Rs. ");
            status1=scanf("%lf",&d.price);
	}

    found=discountpriceAlreadyValidation(d.price);

	if(found==1){
        i=1;
        printf("\n\n\tAlready Added Price Range. Try Again");
        sleep(1);
	}

	int found4=0;
	found4=discountpriceAsceingOderMaker(d.price);

	if(found4==1){
        i=1;
        printf("\n\n\tInvalid. Your Added Value is Smaller Than Before value");
        printf("\n\t Try Again...........");
        sleep(2);
	}


}while(i==1);



do{
    double temp1, status1;

        i=0;
found=0;
	header();
    printf("\t\t   Add Discount");
    printf("\n\t-----------------------------------\n");
	printf("\n\tEnter Discount (Below 100 Rate) %% : ");
	status1=scanf("%lf",&d.rate);

	while(status1!=1){

		while((temp1=getchar()) != EOF && temp1 != '\n');
			printf("\n\n\tInvalid Input try Again");
			sleep(1);
			header();
            printf("\t\t   Add Discount");
            printf("\n\t-----------------------------------\n");
            printf("\n\tEnter Discount(Below 100 Rate) %%: ");
            status1=scanf("%lf",&d.rate);
            }

    if(d.rate>99){
        i=1;
        printf("\n\n\tToo Long. Try Again");
        sleep(1);
    }

}while(i==1);

        fwrite(&d,sizeof(struct discount),1,file1);
        fclose(file1);



            int addNew=0;
        do{
            i=0;

            header();

            printf("\t\t  Add Discounts");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tDo you want to Add Another one: \n\n");
            printf("\t1. Yes \n");
            printf("\t2. No \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&addNew);

            if(addNew==1){
                found2=1;;
            }else if(addNew==2){
                found2=0;
            }else{
                printf("\t\n\n\tInvalid Input\n");
                sleep(1);
                i=1;
                system("CLS");
            }
        }while(i==1);

}while(found2==1);



  do{
            found1=0;
            header();

            printf("\t\t  Add Discounts");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tDo you want to go to : \n\n");
            printf("\t1. View Discounts \n");
            printf("\t2. Main Menu\n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&choice);

    if(choice==1){
        viewDiscounts();
        printf("\n\n\n\tPress any key to Go to Menu......");
        getch();
        adminMenu();
    }else if(choice==2){
        adminMenu();
    }else{
        found1=1;
        printf("\n\n\tYou Entered Invalid Number. Try Again");
        sleep(1);
        system("CLS");
	}

	}while(found1==1);

}

void viewDiscounts(){

    struct discount d;
    FILE *file2;
    header2();
    printf("\t\t\t\t     View Discounts");
    printf("\n\t\t\t  -----------------------------------\n\n");
    printf("\tDiscount ID\t             Price Range(Rs)\t                Rate %%\n\n\n");

     file2=fopen("discount.dat","r");

        if(file2==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }
         while(fread(&d,sizeof(struct discount),1,file2)){
           printf("\t%d\t\t\t Rs %8.2lf\t \t\t     %8.lf\n",d.discountId,d.price,d.rate);
        }
        fclose(file2);

}

void viewSales(){

        FILE *file10;

    	struct report r;

        file10=fopen("admin.dat","r");

            header2();
            printf("\t\t\t\t     View Sales");
            printf("\n\t\t\t  -----------------------------------\n\n");
            printf("\tCustomer NIC\t  Bought Book ID\t Quantity \t   Deliver Address\n\n\n");

                fscanf(file10,"%d %lf %d %lf %s %[^\n]s",&r.quantity,&r.dcost,&r.bookId,&r.price,&r.nic,&r.address);
         while(!feof(file10)){
                printf("\t%.10s\t     %4d\t         %4d %30s\n",r.nic,r.bookId,r.quantity,r.address);
                fscanf(file10,"%d %lf %d %lf %s %[^\n]s",&r.quantity,&r.dcost,&r.bookId,&r.price,&r.nic,&r.address);
        }
        fclose(file10);

        printf("\n\t Press Any Key To Go to Main Menu");
        getch();
        adminMenu();

}


void viewCustomers(){

    system("COLOR 0E");

    header2();
    printf("\t\t\t\t     Customer Details");
    printf("\n\t\t\t  -----------------------------------\n\n");
	struct data d;
	FILE *file1;

   	file1=fopen("customer.dat","r");

   	if(file1==NULL)
    {
        printf("File could not be opened\n");
        sleep(1);
        adminMenu();
    }

    printf("\tFirst Name \t Last Name\t  NIC\t          Phone Number\t  Age\t       City\n");
    fscanf(file1,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );
   	while(!feof(file1)) {

		   	printf("\n\t%10s\t%10s\t%12s\t%12s\t%4d\t%12s",d.fname,d.lname,d.nic,d.phone,d.age,d.city);


     fscanf(file1,"%s %s %s %s %s %d %s",d.fname,d.lname,d.nic,d.phone,d.city,&d.age,d.password );
   }


	printf("\n\t-----------------------------------");
    printf("\n\n");
    char nic[10];
    int k=0,w=0;
     do{
        w=0;

            printf("\t-----------------------------------\n");

            printf("\n\tDo you want to,");
            printf("\n\t1 Delete Customers");
            printf("\n\t2 Main Menu");

            printf("\n\n\tEnter Your Option : ");
            scanf("%d",&k);


            if(k==1){

                printf("\n\tEnter Customer NIC, Do you want to delete : ");
                scanf("%s",nic);
                deleteCProfile(nic);

            }else if(k==2){
                adminMenu();
            }else {
                w=1;
                printf("\t\n\n\tInvalid Input Try Again\n");
                sleep(1);
                system("CLS");
            }

        }while(w==1);

	printf("\n");

}


int bookIdAlreadyValidation(int id){

    struct book b;
    FILE *file1;
	file1=fopen("books.dat","r");

   	while(fread(&b,sizeof(struct book),1,file1)) {

   		if(id==b.bookId){
        return 1;
   		}
    }

	fclose(file1);
	return 0;
}


void addBooks(){

struct book b;
int choice=0,i=0,found=0,found1=0,found2=0;
system("COLOR 0F");


	FILE *file1;
	FILE *file2;
	FILE *file3;
	FILE *file4;
	FILE *file5;
	FILE *file6;


    do{

        file1=fopen("books.dat","a");

		if(file1==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }
        found2=0;

        do{
            found1=0;
            header();

            printf("\t\t  Add Books");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tDo you want to Add : \n\n");
            printf("\t1. Novels \n");
            printf("\t2. Short Stories \n");
            printf("\t3. Translations \n");
            printf("\t4. Children Stories \n");
            printf("\t5. Magazines \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&choice);

    if(choice==1 || choice==2 || choice==3 || choice==4 || choice==5 ){
        found1=0;
    }else{
        found1=1;
        printf("\n\n\tYou Entered Invalid Number. Try Again");
        sleep(1);
        system("CLS");
	}

	}while(found1==1);


	int temp, status;
do{
    found=0;
    i=0;
	header();
    printf("\t\t   Add Book");
    printf("\n\t-----------------------------------\n");
	printf("\n\tEnter Book ID : ");
	status=scanf("%d",&b.bookId);

	while(status!=1){

		while((temp=getchar()) != EOF && temp != '\n');
			printf("\n\n\tInvalid Input try Again");
			sleep(1);
			header();
            printf("\t\t   Add Book");
            printf("\n\t-----------------------------------\n");
            printf("\n\tEnter Book ID (above 4 Numbers): ");
            status=scanf("%d",&b.bookId);
	}

	int count1=0;

    count1=(b.bookId==0)?1:log10(b.bookId)+1;

	if(count1<5){
        i=1;
        printf("\n\n\tShortly Number. Try Again");
        sleep(1);
	}

	found=bookIdAlreadyValidation(b.bookId);

	if(found==1){
        i=1;
        printf("\n\n\tAlready Added Book ID. Try Again");
        sleep(1);
	}


}while(i==1);


double temp1, status1;

	header();
    printf("\t\t   Add Book");
    printf("\n\t-----------------------------------\n");
	printf("\n\tEnter Price : Rs. ");
	status1=scanf("%lf",&b.price);

	while(status1!=1){

		while((temp1=getchar()) != EOF && temp1 != '\n');
			printf("\n\n\tInvalid Input try Again");
			sleep(1);
			header();
            printf("\t\t   Add Book");
            printf("\n\t-----------------------------------\n");
            printf("\n\tEnter Price : Rs. ");
            status1=scanf("%lf",&b.price);
	}



    header();
    printf("\t\t   Add Book");
    printf("\n\t-----------------------------------\n");
    fflush(stdin);
	printf("\n\n\tEnter Book Name : ");
	scanf("%[^\n]s",&b.bookName);



    header();
    printf("\t\t   Add Book");
    printf("\n\t-----------------------------------\n");
    fflush(stdin);
	printf("\n\n\tEnter Author Name : ");
	scanf("%[^\n]s",&b.authorName);

	if(choice==1){

        file2=fopen("novels.dat","a");

        if(file2==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }
        fwrite(&b,sizeof(struct book),1,file2);
        fclose(file2);

	}else if(choice==2){

	    file3=fopen("shortStories.dat","a");

        if(file3==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }
        fwrite(&b,sizeof(struct book),1,file3);
        fclose(file3);

	}else if(choice==3){

        file4=fopen("Translations.dat","a");

        if(file4==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }
        fwrite(&b,sizeof(struct book),1,file4);
        fclose(file4);

	}else if(choice==4){

        file5=fopen("childrenStories.dat","a");

        if(file5==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }
        fwrite(&b,sizeof(struct book),1,file5);
        fclose(file5);

	}else{

        file6=fopen("magazines.dat","a");

        if(file6==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }
        fwrite(&b,sizeof(struct book),1,file6);
        fclose(file6);

	}

	fwrite(&b,sizeof(struct book),1,file1);
    fclose(file1);
            int addNew=0;
        do{
            i=0;

            header();

            printf("\t\t  Add Books");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tDo you want to Add Another one: \n\n");
            printf("\t1. Yes \n");
            printf("\t2. No \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&addNew);

            if(addNew==1){
                found2=1;;
            }else if(addNew==2){
                found2=0;
            }else{
                printf("\t\n\n\tInvalid Input\n");
                sleep(1);
                i=1;
                system("CLS");
            }
        }while(i==1);

}while(found2==1);



  do{
            found1=0;
            header();

            printf("\t\t  Add Books");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tDo you want to go to : \n\n");
            printf("\t1. View Books \n");
            printf("\t2. Main Menu\n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&choice);

    if(choice==1){
        viewBooks();
    }else if(choice==2){
        adminMenu();
    }else{
        found1=1;
        printf("\n\n\tYou Entered Invalid Number. Try Again");
        sleep(1);
        system("CLS");
	}

	}while(found1==1);

}


void view(int choice){


    int found1=0,found2=0;
    struct book b;


    FILE *file1;
	FILE *file2;
	FILE *file3;
	FILE *file4;
	FILE *file5;
	FILE *file6;

    if(choice==1){

        file2=fopen("novels.dat","r");

        if(file2==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }
         while(fread(&b,sizeof(struct book),1,file2)){
           printf("\t%d\t %20s\t %20s\t    Rs %8.2lf\n",b.bookId,b.bookName,b.authorName,b.price);
        }
        fclose(file2);

	}else if(choice==2){

	    file3=fopen("shortStories.dat","r");

        if(file3==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }
         while(fread(&b,sizeof(struct book),1,file3)){
           printf("\t%d\t %20s\t %20s\t    Rs %8.2lf\n",b.bookId,b.bookName,b.authorName,b.price);
        }
        fclose(file3);

	}else if(choice==3){

        file4=fopen("Translations.dat","r");

        if(file4==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }
         while(fread(&b,sizeof(struct book),1,file4)){
           printf("\t%d\t %20s\t %20s\t    Rs %8.2lf\n",b.bookId,b.bookName,b.authorName,b.price);
        }
        fclose(file4);

	}else if(choice==4){

        file5=fopen("childrenStories.dat","r");

        if(file5==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }
         while(fread(&b,sizeof(struct book),1,file5)){
           printf("\t%d\t %20s\t %20s\t    Rs %8.2lf\n",b.bookId,b.bookName,b.authorName,b.price);
        }
        fclose(file5);

	}else if(choice==5){

        file6=fopen("magazines.dat","r");

        if(file6==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }
         while(fread(&b,sizeof(struct book),1,file6)){
           printf("\t%d\t %20s\t %20s\t    Rs %8.2lf\n",b.bookId,b.bookName,b.authorName,b.price);
        }
        fclose(file6);

	}else{

	    file1=fopen("books.dat","r");

		if(file1==NULL)
        {
        printf("File could not be opened\n");
        exit(1);
        }

        while(fread(&b,sizeof(struct book),1,file1)){
           printf("\t%d\t %20s\t %20s\t    Rs %8.2lf\n",b.bookId,b.bookName,b.authorName,b.price);
        }
        fclose(file1);

	}
}

void viewBooks(){

system("COLOR 06");

int found1=0,choice=0,found2=0;
struct book b;


    FILE *file1;
	FILE *file2;
	FILE *file3;
	FILE *file4;
	FILE *file5;
	FILE *file6;

    do{
        found2=0;

        do{
            found1=0;
            header();

            printf("\t\t  View Books");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tDo you want to View : \n\n");
            printf("\t1. Novels \n");
            printf("\t2. Short Stories \n");
            printf("\t3. Translations \n");
            printf("\t4. Children Stories \n");
            printf("\t5. Magazines \n");
            printf("\t6. All Books \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&choice);

    if(choice==1 || choice==2 || choice==3 || choice==4 || choice==5 || choice==6 ){
        found1=0;
    }else{
        found1=1;
        printf("\n\n\tYou Entered Invalid Number. Try Again");
        sleep(1);
        system("CLS");
	}

	}while(found1==1);


    header2();
    printf("\t\t\t\t     View Books");
    printf("\n\t\t\t  -----------------------------------\n\n");
    printf("\tBook ID\t             Name\t             Author\t      Price(Rs)\n\n\n");


	view(choice);


printf("\n\tPress any key to View Menu......\n");
getch();

	do{
            found1=0;
            header();

            printf("\t\t  View Books");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tDo you want to  : \n\n");
            printf("\t1. View Another \n");
            printf("\t2. Delete Books \n");
            printf("\t3. Update Books \n");
            printf("\t4. Main Menu \n");
            printf("\t5. Exit \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&choice);

    if(choice==1){
        found2=1;
    }else if(choice==2){
        deleteBooks();
    }else if(choice==3){
        updateBooks();
    }else if(choice==4){
         adminMenu();
    }else if(choice==5){
        system("CLS");
        printf("\t\n\n\t\tWelcome !  Good Bye");
        footer();
        exit(1);
    }else{
        found1=1;
        printf("\n\n\tYou Entered Invalid Number. Try Again");
        sleep(1);
        system("CLS");
	}

	}while(found1==1);

	}while(found2==1);

}

void deleteBooks(){

system("COLOR 0C");

int found1=0,choice=0,found2=0,found=0;
struct book b;


    FILE *file1;
	FILE *file2;
	FILE *file3;
	FILE *file4;
	FILE *file5;
	FILE *file6;

    do{
        found2=0;

        do{
            found1=0;
            header();

            printf("\t\t  Delete Books");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tDo you want to Delete : \n\n");
            printf("\t1. Novels \n");
            printf("\t2. Short Stories \n");
            printf("\t3. Translations \n");
            printf("\t4. Children Stories \n");
            printf("\t5. Magazines \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&choice);

    if(choice==1 || choice==2 || choice==3 || choice==4 || choice==5 ){
        found1=0;
    }else{
        found1=1;
        printf("\n\n\tYou Entered Invalid Number. Try Again");
        sleep(1);
        system("CLS");
	}

	}while(found1==1);

    header2();
    printf("\t\t\t\t     Delete Books");
    printf("\n\t\t\t  -----------------------------------\n\n");
    printf("\tBook ID\t             Name\t             Author\t      Price(Rs)\n\n\n");


	view(choice);


	int found3=0;

do{

    found3=1;



int bookid,found=0,i=0;
int temp, status;
do{
    found=0;
    i=0;
	printf("\n\tEnter Book ID : ");
	status=scanf("%d",&bookid);

	while(status!=1){

		while((temp=getchar()) != EOF && temp != '\n');
			printf("\n\n\tInvalid Input try Again");
			sleep(1);
            printf("\n\tEnter Book ID : ");
            status=scanf("%d",&bookid);
	}

	int count1=0;

    count1=(bookid==0)?1:log10(bookid)+1;

	if(count1<5){
        i=1;
        printf("\n\n\tShortly Number. Try Again");
        sleep(1);
	}

	found=bookIdAlreadyValidation(bookid);

	if(found==0){
        i=1;
        printf("\n\n\tThe Book id Does Not Exist. Try Again");
        sleep(1);
	}


}while(i==1);

FILE *file7;
FILE *file8;

found1=1;

    if(choice==1){

        file2=fopen("novels.dat","r");
        file8=fopen("delete.dat","w");

        if(file2==NULL || file8==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }

         while(fread(&b,sizeof(struct book),1,file2)){

         if(bookid==b.bookId){
            found=1;
         }else{

            fwrite(&b,sizeof(struct book),1,file8);
         }
        }
        fclose(file2);
        fclose(file8);

        if(found){

        file2=fopen("novels.dat","w");
        file8=fopen("delete.dat","r");

        while(fread(&b,sizeof(struct book),1,file8)){

            fwrite(&b,sizeof(struct book),1,file2);
            }
        fclose(file2);
        fclose(file8);
        }else{
          found3=0;
          printf("\n\t Can not Find Book ID\n");
          sleep(1);
        }

	}else if(choice==2){

	    file3=fopen("shortStories.dat","r");
        file8=fopen("delete.dat","w");

        if(file3==NULL || file8==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }

         while(fread(&b,sizeof(struct book),1,file3)){

         if(bookid==b.bookId){
            found=1;
         }else{

            fwrite(&b,sizeof(struct book),1,file8);
         }
        }
        fclose(file3);
        fclose(file8);

        if(found){

        file3=fopen("shortStories.dat","w");
        file8=fopen("delete.dat","r");

        while(fread(&b,sizeof(struct book),1,file8)){

            fwrite(&b,sizeof(struct book),1,file3);
            }
        fclose(file3);
        fclose(file8);
        }else{
         found3=0;
          printf("\n\t Can not Find Book ID\n");
          sleep(1);
        }

	}else if(choice==3){

        file4=fopen("Translations.dat","r");
        file8=fopen("delete.dat","w");

        if(file4==NULL || file8==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }

         while(fread(&b,sizeof(struct book),1,file4)){

         if(bookid==b.bookId){
            found=1;
         }else{

            fwrite(&b,sizeof(struct book),1,file8);
         }
        }
        fclose(file4);
        fclose(file8);

        if(found){

        file4=fopen("Translations.dat","w");
        file8=fopen("delete.dat","r");

        while(fread(&b,sizeof(struct book),1,file8)){

            fwrite(&b,sizeof(struct book),1,file4);
            }
        fclose(file4);
        fclose(file8);
        }else{
          found3=0;
          printf("\n\t Can not Find Book ID\n");
          sleep(1);
        }

	}else if(choice==4){

        file5=fopen("childrenStories.dat","r");
        file8=fopen("delete.dat","w");

        if(file5==NULL || file8==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }

         while(fread(&b,sizeof(struct book),1,file5)){

         if(bookid==b.bookId){
            found=1;
         }else{

            fwrite(&b,sizeof(struct book),1,file8);
         }
        }
        fclose(file5);
        fclose(file8);

        if(found){

        file5=fopen("childrenStories.dat","w");
        file8=fopen("delete.dat","r");

        while(fread(&b,sizeof(struct book),1,file8)){

            fwrite(&b,sizeof(struct book),1,file5);
            }
        fclose(file5);
        fclose(file8);
        }else{
          found3=0;
          printf("\n\t Can not Find Book ID\n");
          sleep(1);
        }

	}else{

        file6=fopen("magazines.dat","r");
        file8=fopen("delete.dat","w");

        if(file6==NULL || file8==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }

         while(fread(&b,sizeof(struct book),1,file6)){

         if(bookid==b.bookId){
            found=1;
         }else{

            fwrite(&b,sizeof(struct book),1,file8);
         }
        }
        fclose(file6);
        fclose(file8);

        if(found){

        file6=fopen("magazines.dat","w");
        file8=fopen("delete.dat","r");

        while(fread(&b,sizeof(struct book),1,file8)){

            fwrite(&b,sizeof(struct book),1,file6);
            }
        fclose(file6);
        fclose(file8);
        }else{
          found3=0;
          printf("\n\t Can not Find Book ID\n");
          sleep(1);
        }

	}

found=0;

	    file1=fopen("books.dat","r");
	    file7=fopen("deleteBooks.dat","w");


		if(file1==NULL || file7==NULL)
        {
        printf("File could not be opened\n");
        exit(1);
        }

       while(fread(&b,sizeof(struct book),1,file1)){

         if(bookid==b.bookId){
            found=1;
         }else{

            fwrite(&b,sizeof(struct book),1,file7);
         }
        }
        fclose(file1);
        fclose(file7);

        if(found){

        file1=fopen("books.dat","w");
	    file7=fopen("deleteBooks.dat","r");

        while(fread(&b,sizeof(struct book),1,file7)){

            fwrite(&b,sizeof(struct book),1,file1);
            }
        fclose(file1);
        fclose(file7);
        }else{
          found3=0;
          printf("\n\t Can not Find Book ID\n");
          sleep(1);
        }

        if(found3==0){
            printf("\n\t Can not Find Book ID. Try Again\n");
            found3=0;
        }


}while(found3==0);

            header();

            printf("\t\t    Delete Books");
            printf("\n\t-----------------------------------\n\n");
            printf("\t\t  Delete Successfully\n");
            sleep(1);

	do{
            found1=0;
            header();

            printf("\t\t  Delete Books");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tDo you want to  : \n\n");
            printf("\t1. Delete Another \n");
            printf("\t2. View Books \n");
            printf("\t3. Main Menu \n");
            printf("\t4. Exit \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&choice);

    if(choice==1){
        found2=1;
    }else if(choice==2){
        viewBooks();
    }else if(choice==3){
        adminMenu();
    }else if(choice==4){
        system("CLS");
        printf("\t\n\n\t\tWelcome !  Good Bye");
        footer();
        exit(1);
    }else {
        found1=1;
        printf("\n\n\tYou Entered Invalid Number. Try Again");
        sleep(1);
        system("CLS");
	}

	}while(found1==1);

	}while(found2==1);


}

void updateBooks(){


    system("COLOR 0A");

int found1=0,choice=0,found2=0,found=0;
struct book b;


    FILE *file1;
	FILE *file2;
	FILE *file3;
	FILE *file4;
	FILE *file5;
	FILE *file6;

    do{
        found2=0;

        do{
            found1=0;
            header();

            printf("\t\t  Update Books");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tDo you want to Update : \n\n");
            printf("\t1. Novels \n");
            printf("\t2. Short Stories \n");
            printf("\t3. Translations \n");
            printf("\t4. Children Stories \n");
            printf("\t5. Magazines \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&choice);

    if(choice==1 || choice==2 || choice==3 || choice==4 || choice==5 ){
        found1=0;
    }else{
        found1=1;
        printf("\n\n\tYou Entered Invalid Number. Try Again");
        sleep(1);
        system("CLS");
	}

	}while(found1==1);

    header2();
    printf("\t\t\t\t     Update Books");
    printf("\n\t\t\t  -----------------------------------\n\n");
    printf("\tBook ID\t             Name\t             Author\t      Price(Rs)\n\n\n");


	view(choice);


	int found3=0;

do{

    found3=1;



int bookid,found=0,i=0;
int temp, status;
do{
    found=0;
    i=0;
	printf("\n\tEnter Book ID to Update : ");
	status=scanf("%d",&bookid);

	while(status!=1){

		while((temp=getchar()) != EOF && temp != '\n');
			printf("\n\n\tInvalid Input try Again");
			sleep(1);
            printf("\n\tEnter Book ID to Update: ");
            status=scanf("%d",&bookid);
	}

	int count1=0;

    count1=(bookid==0)?1:log10(bookid)+1;

	if(count1<5){
        i=1;
        printf("\n\n\tShortly Number. Try Again");
        sleep(1);
	}

	found=bookIdAlreadyValidation(bookid);

	if(found==0){
        i=1;
        printf("\n\n\tThe Book id Does Not Exist. Try Again");
        sleep(1);
	}


}while(i==1);

double price=0;
char bookName[20];
char authorName[20];
double temp1, status1;

	header();
    printf("\t\t  Update Book");
    printf("\n\t-----------------------------------\n");
	printf("\n\tEnter New Price : Rs. ");
	status1=scanf("%lf",&price);

	while(status1!=1){

		while((temp1=getchar()) != EOF && temp1 != '\n');
			printf("\n\n\tInvalid Input try Again");
			sleep(1);
			header();
            printf("\t\t  Update Book");
            printf("\n\t-----------------------------------\n");
            printf("\n\tEnter New Price : Rs. ");
            status1=scanf("%lf",&price);
	}



    header();
    printf("\t\t  Update Book");
    printf("\n\t-----------------------------------\n");
    fflush(stdin);
	printf("\n\n\tEnter Book Name : ");
	scanf("%[^\n]s",&bookName);



    header();
    printf("\t\t  Update Book");
    printf("\n\t-----------------------------------\n");
    fflush(stdin);
	printf("\n\n\tEnter Author Name : ");
	scanf("%[^\n]s",&authorName);

FILE *file7;
FILE *file8;

found1=1;
found=0;
    if(choice==1){

        file2=fopen("novels.dat","r");
        file8=fopen("updateBook.dat","w");

        if(file2==NULL || file8==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }

         while(fread(&b,sizeof(struct book),1,file2)){

         if(bookid==b.bookId){
                b.price=price;
                 strcpy(b.bookName,bookName);
                 strcpy(b.authorName,authorName);
            found=1;
         }
         fwrite(&b,sizeof(struct book),1,file8);

        }
        fclose(file2);
        fclose(file8);

        if(found){

        file2=fopen("novels.dat","w");
        file8=fopen("updateBook.dat","r");

        while(fread(&b,sizeof(struct book),1,file8)){

        fwrite(&b,sizeof(struct book),1,file2);
            }
        fclose(file2);
        fclose(file8);
        }else{
          found3=0;
        }

	}else if(choice==2){

	    file3=fopen("shortStories.dat","r");
        file8=fopen("updateBook.dat","w");

        if(file3==NULL || file8==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }

         while(fread(&b,sizeof(struct book),1,file3)){

         if(bookid==b.bookId){
                b.price=price;
                 strcpy(b.bookName,bookName);
                 strcpy(b.authorName,authorName);
            found=1;
         }

            fwrite(&b,sizeof(struct book),1,file8);

        }
        fclose(file3);
        fclose(file8);

        if(found){

        file3=fopen("shortStories.dat","w");
        file8=fopen("updateBook.dat","r");

        while(fread(&b,sizeof(struct book),1,file8)){

            fwrite(&b,sizeof(struct book),1,file3);
            }
        fclose(file3);
        fclose(file8);
        }else{
         found3=0;
        }

	}else if(choice==3){

        file4=fopen("Translations.dat","r");
        file8=fopen("updateBook.dat","w");

        if(file4==NULL || file8==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }

         while(fread(&b,sizeof(struct book),1,file4)){

         if(bookid==b.bookId){
                 b.price=price;
                 strcpy(b.bookName,bookName);
                 strcpy(b.authorName,authorName);
            found=1;
         }

            fwrite(&b,sizeof(struct book),1,file8);

        }
        fclose(file4);
        fclose(file8);

        if(found){

        file4=fopen("Translations.dat","w");
        file8=fopen("updateBook.dat","r");

        while(fread(&b,sizeof(struct book),1,file8)){

            fwrite(&b,sizeof(struct book),1,file4);
            }
        fclose(file4);
        fclose(file8);
        }else{
          found3=0;
        }

	}else if(choice==4){

        file5=fopen("childrenStories.dat","r");
        file8=fopen("updateBook.dat","w");

        if(file5==NULL || file8==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }

         while(fread(&b,sizeof(struct book),1,file5)){

         if(bookid==b.bookId){
                 b.price=price;
                 strcpy(b.bookName,bookName);
                 strcpy(b.authorName,authorName);
            found=1;
         }

            fwrite(&b,sizeof(struct book),1,file8);

        }
        fclose(file5);
        fclose(file8);

        if(found){

        file5=fopen("childrenStories.dat","w");
        file8=fopen("updateBook.dat","r");

        while(fread(&b,sizeof(struct book),1,file8)){

            fwrite(&b,sizeof(struct book),1,file5);
            }
        fclose(file5);
        fclose(file8);
        }else{
          found3=0;
        }

	}else{

        file6=fopen("magazines.dat","r");
        file8=fopen("updateBook.dat","w");

        if(file6==NULL || file8==NULL)
        {
        printf("File could not be opened\n");
        sleep(1);
        exit(1);
        }

         while(fread(&b,sizeof(struct book),1,file6)){

         if(bookid==b.bookId){
                 b.price=price;
                 strcpy(b.bookName,bookName);
                 strcpy(b.authorName,authorName);
            found=1;
         }

            fwrite(&b,sizeof(struct book),1,file8);

        }
        fclose(file6);
        fclose(file8);

        if(found){

        file6=fopen("magazines.dat","w");
        file8=fopen("updateBook.dat","r");

        while(fread(&b,sizeof(struct book),1,file8)){

            fwrite(&b,sizeof(struct book),1,file6);
            }
        fclose(file6);
        fclose(file8);
        }else{
          found3=0;
        }

	}

    if(found){
        found=0;

	    file1=fopen("books.dat","r");
	    file7=fopen("updateBooks.dat","w");


		if(file1==NULL || file7==NULL)
        {
        printf("File could not be opened\n");
        exit(1);
        }

       while(fread(&b,sizeof(struct book),1,file1)){

         if(bookid==b.bookId){
                 b.price=price;
                 strcpy(b.bookName,bookName);
                 strcpy(b.authorName,authorName);
            found=1;
         }

            fwrite(&b,sizeof(struct book),1,file7);

        }
        fclose(file1);
        fclose(file7);

        if(found){

        file1=fopen("books.dat","w");
	    file7=fopen("updateBooks.dat","r");

        while(fread(&b,sizeof(struct book),1,file7)){

            fwrite(&b,sizeof(struct book),1,file1);
            }
        fclose(file1);
        fclose(file7);
        }else{
          found3=0;
        }
	}
        if(found3==0){
            printf("\n\t Can not Find Book ID. Try Again\n");
            sleep(1);
            header();
            found3=0;
        }


}while(found3==0);

            header();

            printf("\t\t    Update Books");
            printf("\n\t-----------------------------------\n\n");
            printf("\t\t  Update Successfully\n");
            sleep(1);

	do{
            found1=0;
            header();

            printf("\t\t  Update Books");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tDo you want to  : \n\n");
            printf("\t1. Update Another \n");
            printf("\t2. View Books \n");
            printf("\t3. Main Menu \n");
            printf("\t4. Exit \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&choice);

    if(choice==1){
        found2=1;
    }else if(choice==2){
        viewBooks();
    }else if(choice==3){
        adminMenu();
    }else if(choice==4){
        system("CLS");
        printf("\t\n\n\t\tWelcome !  Good Bye");
        footer();
        exit(1);
    }else {
        found1=1;
        printf("\n\n\tYou Entered Invalid Number. Try Again");
        sleep(1);
        system("CLS");
	}

	}while(found1==1);

	}while(found2==1);
}

void printBill(double total, double discountPrice, double amount,double rate){

  int found1=0,choice=0;
  double fullamount;
  struct book b;
  struct payments p;

    FILE *file7;
    FILE *file8;
    FILE *file10;

    file7=fopen("cart.dat","r");
    file10=fopen("payments.dat","a");

	    header2();
        printf("\t\t\t\t       My Bill");
        printf("\n\t\t\t  -----------------------------------\n");

        time_t t;
        t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("\n\tDate : %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
        printf("\n\n\tTime : %d:%d:%d", tm.tm_hour, tm.tm_min, tm.tm_sec);
        printf("\n\t--------------------------------------------------------------------------");
        printf("\n\n\tBook ID\t\t          Name\t     Price(Rs)\t  Quantity\tTotal(Rs)\n\n");

        while(fread(&b,sizeof(struct book),1,file7)){
        printf("\t%d\t %20s\t  %10.2lf\t %4d        %12.2lf\n",b.bookId,b.bookName,b.price,b.quantity,b.total);

            }
        fclose(file7);

        struct delivery d;
        double cost=0;
            printf("\n\t--------------------------------------------------------------------------");
            printf("\n\tTotal                : Rs %.2lf",total);
            printf("\n\tMy Discount Rate is  : %.lf %%",rate);
            printf("\n\tDiscount             : Rs %.2lf",discountPrice);
            printf("\n\tPrice                : Rs %.2lf",total-discountPrice);
            file8=fopen("delivery.dat","r");

            while(fread(&d,sizeof(struct delivery),1,file8)){

            printf("\n\tAddress              : %s",d.address);
   			printf("\n\tDistance             : %.3lf km",d.distance);
   			printf("\n\tDelivery Cost        : Rs %.2lf",d.cost);
            cost= d.cost;
            }

   			fclose(file8);
   			fullamount=amount+cost;

   			p.total=total;
   			p.deliveryCost=cost;
   			p.discount=discountPrice;
   			p.fullAmount=fullamount;

   			fwrite(&p,sizeof(struct payments),1,file10);

   			fclose(file10);

            printf("\n\tFull Total Cost Is   : Rs %.2lf",fullamount);
            printf("\n\t--------------------------------------------------------------------------");

            printf("\n\n\tPress any key to Go Menu......");
            getch();


  do{
            found1=0;
            header();

            printf("\t\t  Payment");
            printf("\n\t-----------------------------------\n\n");

            printf("\n\tDo you want to Pay : \n\n");
            printf("\t1. Pay Online \n");
            printf("\t2. Cash On Delivery \n");
            printf("\n\t-----------------------------------\n\n");
            printf("\tEnter Your Choice : ");
            scanf("%d",&choice);

    if(choice==1 ){
        payOnline(fullamount);
    }else if(choice==2){
        cashOnDelivery(fullamount);
    }else{
        found1=1;
        printf("\n\n\tYou Entered Invalid Number. Try Again");
        sleep(1);
        system("CLS");
	}

	}while(found1==1);


}


void endAll(){

            header();
            printf("\t\tThank You. Come Again");
            printf("\n\t-----------------------------------\n\n");

            footer();
            exit(1);
}

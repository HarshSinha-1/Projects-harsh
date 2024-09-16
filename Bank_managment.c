#include<stdio.h>
#include<stdlib.h>
int fth_pwd=0 ,fth_acNo=0 ,wid_amt=0 ,dep_amt=0;
struct create_account* start=NULL;
struct create_account
{
   char name[20];
   int pwd;
   int acc_no; 
   int ini_amt;
   int final_amt;
   struct create_account* add;
};
void create_acc(){
     struct create_account* node = (struct create_account*)malloc(sizeof(struct create_account));
    node->add = NULL;
    printf("\nEnter Name of Account Holder:");
    scanf("%s",node->name);
    printf("\nEnter the User Password:");
    scanf("%d",&node->pwd);
    node->acc_no = rand();
    printf("\nYour New A/C Number is:%d",node->acc_no);
    printf("\nEnter the inital amount to Deposit:");
    scanf("%d",&node->ini_amt);
    node->final_amt=node->ini_amt;
    if (start==NULL)
       start = node;
    else{
         struct create_account* ptr = start;
         while (ptr->add!=NULL)
         {
            ptr=ptr->add;
         }
         ptr->add=node;
    }    
}
void withdraw(){
           printf("\n To Login Enter your Credintial.!");
           printf("\nEnter user account Number:");
           scanf("%d",&fth_acNo);
           printf("\nEnter Password:");
           scanf("%d",&fth_pwd);
           struct create_account* ptr = start;
           while (ptr!=NULL)
           {
                if (ptr->acc_no==fth_acNo && ptr->pwd==fth_pwd)
                {
                      printf("Login Succesfully\n");
                      printf("Enter the amount to be withdrawl:");
                      scanf("%d",&wid_amt);
                      if(ptr->final_amt > 500){
                        ptr->final_amt = ptr->final_amt - wid_amt;
                        printf("\n%d Amount has withdrawl from account\nDear custumer, your updated balance is %d ",wid_amt,ptr->final_amt);
                         }
                     else{
                      printf("Low Balance..! Can't widraw");
                      return;
                     }
                }
                 ptr=ptr->add;
           }
           
         dep_amt=0,fth_acNo=0,fth_pwd=0; 
}
void deposit(){
           printf("\n To Login Enter your Credintial.!");
           printf("\nEnter user account Number:");
           scanf("%d",&fth_acNo);
           printf("\nEnter Password:");
           scanf("%d",&fth_pwd);
           struct create_account* ptr = start;
           while (ptr!=NULL)
           {
                if (ptr->acc_no==fth_acNo && ptr->pwd==fth_pwd)
                {
                      printf("Login Succesfully\n");
                      printf("Enter the amount to be Deposited:");
                      scanf("%d",&dep_amt);
                      ptr->final_amt = ptr->final_amt + dep_amt;
                       printf("\n%d Amount Deposited in your account\nDear custumer, your updated balance is %d ",dep_amt,ptr->final_amt);
                }
                 ptr=ptr->add;
           }
          
           dep_amt=0,fth_acNo=0,fth_pwd=0; 
}
void display(){
      struct create_account* ptr = start;
      printf("Credential of all account:");
    while (ptr!=NULL)
    {
        printf("\nName:%s\nAccount no:%d\nPassword:%d\n",ptr->name,ptr->acc_no,ptr->pwd);
        ptr=ptr->add;
    }
}
int main()
{
    printf("Welcome to SBI E-Banking.!\n");
    int n;
    printf("ENTER 1 for CREATE NEW ACCOUNT\n");
    printf("Enter 2 for WITHDRAWL\n");
    printf("Enter 3 for DEPOSIT\n");
    printf("Enter 4 for LoGIN CREDINTIALS(for admin only)\n");
    printf("Enter 5 for EXIT\n");
    do {
        printf("\nEnter Your Choice :");
        scanf("%d", &n);
        switch (n) {
            case 1:
              create_acc();
                break;
            case 2:
     		  withdraw();
                break;
            case 3:
              deposit();
                break;
            case 4:
            display();
                break;
			default:
			     printf("\nYOU ENTERED INVALID CHOICE\n");    
		            }
	 }while(n!=5);
     return 0;
}


           
           
              
          
           
        

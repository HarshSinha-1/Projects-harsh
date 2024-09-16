  #include<stdio.h>
#include<stdlib.h>
struct link* start=NULL;
struct link{
	int info;
	struct link* add;
};
int county=0;
int count(){
     if (start==NULL)
        printf("\nLinklist is empty..!");
      else{
             struct link* ptr = start;
               while (ptr!=NULL)
               {
                  county++;
                  ptr=ptr->add;      
               }
      }
      return county;
}
void display(){
     //int cnt = count();
    if (start==NULL)
        printf("\nLinklist is empty..!");
    else{
          struct link* ptr = start;
          printf("\nElements are:");
          while(ptr!=NULL)
          {
            printf("%d \t",ptr->info);
            ptr=ptr->add;
          }
        }
}
void push()  //Insertion of new node
{
 struct link *temp=(struct link*)malloc(sizeof(struct link));//creating new node
 printf("\nEnter the data:");
 scanf("%d",&temp->info);
 temp->add=NULL;
 if (start==NULL)
    start=temp;
   else{
       struct link* ptr=start;
        while (ptr->add!=NULL)
       {
           ptr=ptr->add;
       }
        ptr->add=temp;
      }
    display();
}
void insertion_begning(){
	struct link *temp=(struct link*)malloc(sizeof(struct link));//creating at begning 
	printf("\nEnter the data:");
    scanf("%d",&temp->info);
	temp->add=start;
	start=temp;
	display();
}
void insertion_atlocation(){
	int location,i=1;
	printf("\nEnter the specified location of the node:");
	scanf("%d",&location);
	struct link *temp=(struct link*)malloc(sizeof(struct link)); 
	printf("\nEnter the data:");
    scanf("%d",&temp->info);
	temp->add=NULL;
	 if (start==NULL)
        printf("\nLinklist is empty..!");
    else{
          struct link* ptr = start;
          while(ptr!=NULL){
			      ptr = ptr->add;
                  i++;
                  if(i==location - 1){
                     temp->add = ptr->add;
					 ptr->add = temp;
				  }
		  }
	  display();   					   
       }
}
void deletion_atlocation(){
	int location,i=1;
	printf("\nEnter the specified location of the node:");
	scanf("%d",&location);
	 if (start==NULL)
        printf("\nLinklist is empty..!");
    else{
          struct link* ptr = start;
		  struct link *temp;
          while(ptr!=NULL){
		  
			      ptr = ptr->add;
                  i++;
                  if(i==location - 1){
                    temp = ptr->add;
					ptr->add = ptr->add->add;
                    free(temp);
 				  }
		  }
	  display();   					   
       }
}
void insertion_last(){
	struct link *temp=(struct link*)malloc(sizeof(struct link));//creating at last
	printf("Enter the data:");
    scanf("%d",&temp->info);
	struct link* ptr = start;
	temp->add=NULL;
	while(ptr->add!= NULL){
		ptr=ptr->add;
	}
	ptr->add = temp;
	display();
}
void deleteatbegin(){
    if (start == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct link *ptr;
    ptr = start;

    if (ptr->add == NULL) {
        printf("Deleted element=%d\n", ptr->info);
        start = NULL;
    } else {
        printf("Deleted Element=%d\n", ptr->info);
        start = ptr->add;
    }

    free(ptr);
	display();
}
void deletion_end(){
	struct link* ptr = start;
	while(ptr!=NULL){
		ptr=ptr->add;
	}
	free(ptr);
	display();
}
void reverse_linklist()
{
	struct link *prev= NULL;
	struct link *current = start;
	struct link *next = NULL;
	while(current != NULL){
		//store next
         next = current->add ;
       // use previous
        current->add = prev ;
      //reassign previous and move next
        prev = current;
        current = next;		
	}
	start = prev ;
	display();
}
void create_linkloop(){
    struct link* ptr = start;
	while(ptr->add!=NULL){
		ptr = ptr->add;
	}
	ptr->add = start->add;
}
void detect_loop() {
    struct link* slow = start;
    struct link* fast = start;
    //struct link* prev = NULL;
    while (fast != NULL && slow != NULL) {
        slow = slow->add;
        fast = fast->add->add;
        if (slow == fast){
			printf("\n Loop DETECTED..!");
            break;
        }
    }  
    
}

int main()
{
    int n;
    printf("ENTER 1 FOR INSERT AT BEGIN\n");
    printf("Enter 2 for insert At end\n");
    printf("Enter 3 for create link list\n");
    printf("Enter 4 for delete Node at begin\n");
    printf("Enter 5 for delete Node at End\n");
	printf("Enter 6 for insertion at dezired location\n");
    printf("Enter 7 for deletion at dezired location\n");
    printf("Enter 8 for Reverse the loops\n");
	printf("Enter 9 for CREATE LOOP\n");
    printf("Enter 10 for DETECT LOOP\n");
    printf("Enter 11 for EXIT\n");
    do {
        printf("\nEnter Your Choice :");
        scanf("%d", &n);
        switch (n) {
            case 1:
                insertion_begning();
                break;
            case 2:
     			 insertion_last();
                break;
            case 3:
                 push();
                break;
            case 4:
               deleteatbegin();
                break;
            case 5:
                deletion_end();
                break;
		    case 6:
			    insertion_atlocation();
				break;
            case 7:
                deletion_atlocation();
                break;
			case 8:
			    reverse_linklist();
				break;
            case 9:
                create_linkloop();
                break;
            case 10:
			    detect_loop();
			   break;
			default:
			     printf("YOU ENTERED INVALID CHOICE\n");    
		            }
	 }while(n!=11);    
	return 0;
}

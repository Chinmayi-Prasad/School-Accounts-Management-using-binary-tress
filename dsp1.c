#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tnode
{
  char name[100];
  int flag;
  int roll;
  struct tnode *left;
  struct tnode *right;
};


struct tnode *one ;
struct tnode *two ;
struct tnode *three;
struct tnode *four ;
struct tnode *five ;
struct tnode *six ;
struct tnode *seven ;
struct tnode *eight ;
struct tnode *nine ;
struct tnode *ten ;


void insert(struct tnode**,struct tnode * );
void delete(struct tnode**, struct tnode *);
void mid_year();
struct tnode display(struct tnode *);
int search(struct tnode *, char* );


void update_dataS();
int fee(struct tnode*,int);
 void overdue(struct tnode*);

int main()

{

one = NULL;
two =NULL;
three = NULL;
four =NULL;
five =NULL;
six = NULL;
seven =NULL;
eight =NULL;
nine = NULL;
ten =NULL;



  //CREATE BINARY TREE FUNCTION FOR DATA AVAILABLE
    int ch,num,cla,class,no,i,k;
    char n[100],noo[100];
    struct tnode  *temp , *deln ;
    temp=(struct tnode *)malloc(sizeof(struct tnode));
    deln=(struct tnode *)malloc(sizeof(struct tnode));

	for(k=0;k<3;k++)
   {
    printf("Enter the name of the student ");
    scanf("%s",n);
    
    printf("Enter the roll no ");
    scanf("%d",&num);
    printf("Enter the class the student is joining.(1 to 10)");
	scanf("%d",&cla);
	printf("Has the fee for the upcoming semester been paid???\n1.Yes   2.No");
	scanf("%d",&i);
    strcpy(temp->name,n);
    printf("\nName is %s \n"  , temp->name);
	temp->roll = num;
switch(i)
{
	case 1:temp->flag = 1;
			break;
	case 2:temp->flag = 0;break;
}

switch(cla)
       {
         case 1 :insert(&one , temp);
                 
                 break;
        case 2:insert(&two , temp);
                 break; 
        case 3: insert(&three , temp);
                 break;
        case 4:insert(&four , temp);
                 break;
        case 5: insert(&five , temp);
                 break;
         case 6:insert(&six , temp);
                 break;
         case 7:insert(&seven , temp);
                 break;
         case 8:insert(&eight , temp);
                 break;
         case 9:insert(&nine, temp);
                break;
         case 10:insert(&ten , temp);
                  break;
       }
    }
	

 while(1)
 {
      printf("\n1.Update data for Students"); //insert for now
      printf("\n2.Mid year additions");  
      printf("\n3. Fee payment list display ");
      printf("\n4.Complete data display");
      printf("\n5.search for a student");
      printf("\n6.List Of students with fee over due");
      printf("\n7.Exit");
      scanf("%d",&ch);
       switch(ch)
       {
        case 1: update_dataS();
                 break;
        case 2: mid_year();
                 break; 
        case 3: printf("\nFee Details\n");
               printf("\nEnter class in which student is studying\n");
               scanf("%d",&class);
               printf("Enter student's roll number");
               scanf("%d",&no);
			  // printf("Enter the student's name");
			   //scanf("%s",na);
			   struct tnode *temp;
               switch(class)
               {
                case 1: temp=one;
                  break;
                case 2: temp=two;
                  break;
                case 3: temp=three;
                  break;
                case 4: temp=four;
                  break;
                case 5: temp=five;
                  break;
                case 6: temp=six;
                  break;
                case 7: temp=seven;
                  break;
                case 8: temp=eight;
                  break;
                case 9: temp=nine;
                  break;
                case 10: temp=ten;
                  break;
                default: printf("Invalid Class");
              }   
                if(fee(temp,no))
					printf("Fees paid");
				else
					printf("Fees not paid");
                 break;
                 
                 break;
        case 4: printf("\nDisplay Student Details\n");
         printf("\nEnter which class\n");
         scanf("%d",&class);
         printf("Roll Number\tStudent's Name\n");
              switch(class)
              {
                case 1: display(one);
                  break;
                case 2: display(two);
                  break;
                case 3: display(three);
                  break;
                case 4: display(four);
                  break;
                case 5: display(five);
                  break;
                case 6: display(six);
                  break;
                case 7: display(seven);
                  break;
                case 8: display(eight);
                  break;
                case 9: display(nine);
                  break;
                case 10: display(ten);
                  break;
                default: printf("Invalid Class");
              }
			  
        case 5:  printf("\nSearch Student Details\n");
         printf("\nEnter class in which student is studying\n");
               scanf("%d",&class);
               printf("\nEnter student's name\n");
               scanf("%s",noo);
			   struct tnode *t;
               switch(class)
               {
                case 1: t=one;
                  break;
                case 2: t=two;
                  break;
                case 3: t=three;
                  break;
                case 4: t=four;
                  break;
                case 5: t=five;
                  break;
                case 6: t=six;
                  break;
                case 7: t=seven;
                  break;
                case 8: t=eight;
                  break;
                case 9: t=nine;
                  break;
                case 10: t=ten;
                  break;
                default: printf("Invalid Class");
              }   
			  if(search(t,noo))
					printf("Student found\n");
				else
					printf("Student not found\n");
                 break;

                 
         case 6:printf("Enter which class");
        scanf("%d",&class);
        printf("Roll Number\tStudent's Name\n");
              switch(class)
              {
                case 1: overdue(one);
                  break;
                case 2: overdue(two);
                  break;
                case 3: overdue(three);
                  break;
                case 4: overdue(four);
                  break;
                case 5: overdue(five);
                  break;
                case 6: overdue(six);
                  break;
                case 7: overdue(seven);
                  break;
                case 8: overdue(eight);
                  break;
                case 9: overdue(nine);
                  break;
                case 10: overdue(ten);
                  break;
                default: printf("Invalid Class");
              }
              break;
         case 7: exit(0);
                 break;
        
                  
         
       }
    }

    return 0;
  }
  

void insert(struct tnode **t,struct tnode *addnode)
  {
    struct tnode *temp,*prev,*curr;
    temp=(struct tnode*)malloc(sizeof(struct tnode));
    strcpy(temp->name,addnode->name) ;
    temp->roll=addnode->roll;
	temp->flag=addnode->flag;
    temp->left=temp->right=NULL;

    curr=*t;
    prev=NULL;
     if(curr==NULL)//first node
      *t=temp;
    else
    {
      while(curr!=NULL) 
      {
         prev=curr;
         if(strcmp(addnode->name,curr->name)<0)
           curr=curr->left;
         else
           curr=curr->right;
      }
      if(strcmp(addnode->name,prev->name)<0)
      prev->left=temp;
      else 
      prev->right=temp;

    }
  }

  void delete(struct tnode **t , struct tnode *ntodel)
   {
    struct tnode *temp,*curr, *prev, *q, *insucc;

    temp=(struct tnode*)malloc(sizeof(struct tnode));
    temp->roll=ntodel->roll;
    strcpy(temp->name,ntodel->name);
    temp->left=temp->right=NULL;

    printf("Delete function has started  ");
    printf("%s ",temp->name);
    printf("%d\n ",temp->roll);
    //preorder(ntodel);
     curr=*t;
     prev=NULL;

    //search for x
    while((curr!=NULL)&&(curr->roll!=temp->roll))
    {
      prev=curr;
      if(ntodel->roll <curr->roll)
          curr=curr->left;
       else
          curr=curr->right;
     }

    if(curr==NULL || strcmp(curr->name,temp->name)!=0)
     printf("Node not found...\n");
    else
      {
        if(curr->left==NULL)//no left sub tree
           q=curr->right;//get right subtree 
        else if(curr->right==NULL)//no right subtree
           q=curr->left;//get left subtree
        else
        {
          //both subtrees present
          //find inorder successor
          insucc=curr->right;
          while(insucc->left!=NULL)
             insucc=insucc->left;
          //inorder found(insucc)
          //attach left subtree of curr to left of inorder successor
          insucc->left=curr->left;
          q=curr->right;
        }
          if (prev==NULL) //deleting the root, return new root(q)
             *t = q;
          else if(prev->left==curr)
             prev->left=q; //attach q to the left of prev
          else
             prev->right=q;//attach q to the right of prev
     }
  }



int fee(struct tnode *tree, int rno)
  {
    if(!tree)
        return 0 ;
    if((tree->flag==1) && (tree->roll == rno)) {
		
		return 1;
	}
	
	if (fee(tree->left, rno)) return 1;
	if (fee(tree->right, rno)) return 1;
	return 0;
  } 
  
   void overdue(struct tnode *t)
  {
    if(t!=NULL)
    {
      overdue(t->left);

      if((t->flag)==0)
            printf("\nOVERDUE:%d\t%s\n ",t->roll,t->name);

      overdue(t->right);
    }
  }
  
  int search(struct tnode *tree, char *nam)
  {
    if(!tree)
        return 0 ;
	if(strcmp(tree->name,nam)==0){
    //if(strcmp((tree->name,nam)==0)) {
		
		return 1;
	}
	
	if (search(tree->left, nam)) return 1;
	if (search(tree->left, nam)) return 1;
	return 0;
  } 
  


 struct tnode display(struct tnode *tree)
  {
    
    if (tree)
    {
        display(tree->left);
        printf("   %d\t   %s\n",tree->roll,tree->name);
        display(tree->right);
    }
    
  }


void mid_year()
{
int c=0;
int  num;
char n[100];
int class , i;
struct tnode *temp;
temp=(struct tnode *)malloc(sizeof(struct tnode));

printf("This function is to update the database in case of any mid year addmissions or deletions\n ");
printf("Choose if there is a new addition or there is a deletion of a student\n1.New Addmission 2.A student leaving school");
scanf("%d",&c);

if(c==1)
{
printf("Enter the data for the new student\n ");
printf("Enter name \n");
scanf("%s",n);
printf("Enter the class the student is joining.(1 to 10)");
scanf("%d",&class);
printf("Has the fee for the upcoming semester been paid???\n1.Yes   2.No");
scanf("%d",&i);
strcpy(temp->name,n);
temp->roll = 0;
switch(i)
{
  case 1:temp->flag = 1;break;
  case 2:temp->flag = 0;break;
}

switch(class)
       {
         case 1 :insert(&one , temp);
                 break;
        case 2:insert(&two , temp);
                 break; 
        case 3: insert(&three , temp);
                 break;
        case 4:insert(&four , temp);
                 break;
        case 5: insert(&five , temp);
                 break;
         case 6:insert(&six , temp);
                 break;
         case 7:insert(&seven , temp);
                 break;
         case 8:insert(&eight , temp);
                 break;
         case 9:insert(&nine, temp);
                break;
         case 10:insert(&ten , temp);
                  break;
       }
   }

else if(c==2)
{

printf("Enter the data for the  student leaving school\n ");
printf("Enter name \n");
scanf("%s",n);
printf("Enter the class the student is joining.(1 to 10)");
scanf("%d",&class);
printf("Enter the roll no ");
scanf("%d",&num);
strcpy(temp->name,n);
temp->roll = 0;


switch(class)
       {
         case 1 :delete(&one , temp);
                 break;
        case 2:delete(&two , temp);
                 break; 
        case 3: delete(&three , temp);
                 break;
        case 4:delete(&four , temp);
                 break;
        case 5: delete(&five , temp);
                 break;
         case 6:delete(&six , temp);
                 break;
         case 7:delete(&seven , temp);
                 break;
         case 8:delete(&eight , temp);
                 break;
         case 9:delete(&nine, temp);
                break;
         case 10:delete(&ten , temp);
                  break;
       }
}


}


void update_dataS()//Function to add or delete a student or to promote students at the end of the year 
{
int c=0;
int  num;
char n[100];
int class , i;
struct tnode *temp;
temp=(struct tnode *)malloc(sizeof(struct tnode));

printf("Choose if there is a new Addmission or deletion of a student\n");
scanf("%d",&c);

if(c==1)//To add a newly addmitted student
{

printf("Enter the name of the student\n");
scanf("%s",n);
printf("Enter the class the student is joining.(1 to 10)");
scanf("%d",&class);
strcpy(temp->name,n);
temp->roll = 0;


switch(class)
       {
         case 1 :insert(&one , temp);
                 break;
        case 2:insert(&two , temp);
                 break; 
        case 3: insert(&three , temp);
                 break;
        case 4:insert(&four , temp);
                 break;
        case 5: insert(&five , temp);
                 break;
         case 6:insert(&six , temp);
                 break;
         case 7:insert(&seven , temp);
                 break;
         case 8:insert(&eight , temp);
                 break;
         case 9:insert(&nine, temp);
                break;
         case 10:insert(&ten , temp);
                  break;
       }
   }


else if(c==2)//To delete a student
{

printf("Enter the name of the student to be deleted\n");
scanf("%s",n);
printf("Enter the class the student\n");
scanf("%d",&class);
printf("Enter the roll no ");
scanf("%d",&num);
strcpy(temp->name,n);
temp->roll = 0;


switch(class)
       {
         case 1 :delete(&one , temp);
                 break;
        case 2:delete(&two , temp);
                 break; 
        case 3: delete(&three , temp);
                 break;
        case 4:delete(&four , temp);
                 break;
        case 5: delete(&five , temp);
                 break;
         case 6:delete(&six , temp);
                 break;
         case 7:delete(&seven , temp);
                 break;
         case 8:delete(&eight , temp);
                 break;
         case 9:delete(&nine, temp);
                break;
         case 10:delete(&ten , temp);
                  break;
       }
}


ten=nine;//Promotion of students
nine=eight;
eight=seven;
seven=six;
six=five;
five=four;
four=three;
three=two;
two=one;
one=NULL;


printf("Students of tenth standard\n"); /*Displaying the list of students after promotion and insertion or deletion*/
display(ten);



printf("Students of ninth standard\n");
display(nine);


printf("Students of eighth standard\n");
display(eight);


printf("Students of seventh standard\n");
display(seven);


printf("Students of sixth standard\n");
display(six);


printf("Students of fifth standard\n");
display(five);


printf("Students of fourth standard\n");
display(four);


printf("Students of third standard\n");
display(three);


printf("Students of second standard\n");
display(two);

printf("Students of first standard\n");
display(one);


}



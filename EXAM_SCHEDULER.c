#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 10
int x[size];
int adj[size][size];
void insert_end(int n,int s1,int s2,int s3);
void adjmat();
void schedule(int rno);

struct node
{
  int roll_no,sub1,sub2,sub3;
  struct node * next;
};
struct node * start= NULL;


void graphColour(int k, int m)
{
  int c;  
  for (c = 1; c <= m; c++)
  {
    if (isSafe(k,c))
    {
      x[k] = c;
      if (k+1 < size)
      {
        graphColour(k+1,m);
      }
      else
      {
          for (int i = 0; i < size; i++)
          {
            printf("\t\t\tSubject %d: slot %d\n",i,x[i]);
          }
      } 
      return;
    }    
  } 
  
}

int isSafe(int k, int c)
{
  for (int i = 0; i < size; i++)
  {
    if (adj[k][i] == 1 && c == x[i])
    {
      return 0;
    }    
  }
  return 1;  
}
int main()
{ 
    int n,s,rno,flag = 0;
    int m = 1;
    int ch;
    int adj[10][10];
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    while(ch!=4)
    {
        printf("____________________________________________________________________________________________________________________________\n");
        printf("\t\t\t MAIN MENU\t\t\t\n");
        printf("____________________________________________________________________________________________________________________________\n");
        printf("\n\n\t\t\tEnter:\n\t\t\t1)To enter details\n\t\t\t2)Display all slots\n\t\t\t3)Display my time slots\n\t\t\t4)Exit\t\t\t\n");
        printf("____________________________________________________________________________________________________________________________\n");
        printf("\t\t\tYour choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            {
                printf("\n______________________________________________________________________________________________________________________________\n");
                int n,s1,s2,s3;
                printf("\t\t\tEnter your roll number: ");
                scanf("%d",&n);
                printf("\n\t\t\tEnter:\n\t\t\t00.Physics\n\t\t\t01.Chemistry\n\t\t\t02.Biology\n\t\t\t03.Mathematics\n\t\t\t04.English Literature\n\t\t\t05.English Grammar\n\t\t\t06.History\n\t\t\t07.Geography\n\t\t\t08.Computer\n\t\t\t09.Hindi\n");
                printf("\n\t\t\tEnter subject code for first subject: ");
                scanf("%d",&s1);
                printf("\n\t\t\tEnter subject code for second subject: ");
                scanf("%d",&s2);
                printf("\n\t\t\tEnter subject code for third subject: ");
                scanf("%d",&s3);
                insert_end(n,s1,s2,s3);
                break;
            }
            case 2:
            {
                printf("\n______________________________________________________________________________________________________________________________\n");
                for(int i=0;i<10;i++)
                {
                    for(int j=0;j<10;j++)
                    {
                        adj[i][j]=0;
                    }
                }
                adjmat();
                for(int i=0; i<size; i++)
                {
                    x[i] = -1;
                }
                A:
                for (int i = 0; i < size; i++)
                {
                    if (x[i] == -1)
                    {
                        flag = -1;

                    }        
                }
                if (flag == -1)
                {
                    m = m + 1;
                    flag = 0;
                    graphColour(0,m);
                    goto A;
                }
    
                break;
            }
            
            case 3:
            {
                printf("\n_____________________________________________________________________________________________________________________________\n");
                printf("\n\t\t\tEnter your Roll no: ");
                scanf("%d",&rno);
                schedule(rno);
                break;
            }
            
            case 4:
            {
                printf("\n_____________________________________________________________________________________________________________________________\n");
                 break;
            }
           
            
            default:
                printf("\n\t\t\twrong choice entered");
        }
    }
        
}
     
     
void insert_end(int n,int s1,int s2,int s3)
{
    struct node * newnode, * temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->roll_no=n;
    newnode->sub1=s1;
    newnode->sub2=s2;
    newnode->sub3=s3;
    newnode->next=NULL;
    if(start==NULL)
        start=newnode;
    else
    {
        temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
}


void adjmat()
{
    struct node * temp;
    temp=start;
    if(start==NULL)
    {
        printf("\n\t\t\tNo data found\n");
    }
    while(temp!=NULL)
    {
        adj[temp->sub1][temp->sub1]=1;
        adj[temp->sub1][temp->sub2]=1;
        adj[temp->sub1][temp->sub3]=1;
        adj[temp->sub2][temp->sub1]=1;
        adj[temp->sub2][temp->sub2]=1;
        adj[temp->sub2][temp->sub3]=1;
        adj[temp->sub3][temp->sub1]=1;
        adj[temp->sub3][temp->sub2]=1;
        adj[temp->sub3][temp->sub3]=1;
        temp=temp->next;
    }
} 

void schedule(int rno)
{
    char s[10][30]= {"Physics","Chemistry","Biology","Mathematics","English Literature","English Grammar","History","Geography","Computer","Hindi"};
    struct node * temp;
    temp=start;
    if(start==NULL)
    {
        printf("\n\t\t\tList is empty\n");
        return;
    }
    while(temp!=NULL)
    {
        if (temp -> roll_no == rno)
        {
            int subj1=temp->sub1;
            int subj2=temp->sub2;
            int subj3=temp->sub3;
            printf("\n\t\t\tThe time slots for roll number %d are:\n",temp->roll_no);
            printf("\t\t\t");
            for(int i=subj1, j=0;j<30;j++)
                  {
                    printf("%c",s[i][j]);
                  }
                printf(": %d:00 pm",x[subj1]);
                printf("\n");
             printf("\t\t\t");
            for(int i=subj2, j=0;j<30;j++)
                  {
                    printf("%c",s[i][j]);
                  }
                printf(": %d:00 pm",x[subj2]);
                printf("\n");
            printf("\t\t\t");
            for(int i=subj3, j=0;j<30;j++)
                  {
                    printf("%c",s[i][j]);
                  }
                printf(": %d:00 pm",x[subj3]);
                printf("\n");  
                break;
         }     
        temp=temp->next;
    }
}


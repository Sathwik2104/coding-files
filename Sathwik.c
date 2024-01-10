#include<stdio.h>
#include<string.h>

int main()
{
 struct Emp
 {
  int Ecode,Esal;
  char Ename[20],Etit[10];
 };
struct Emp V[10];
int i,size,ch,flag,k,temp;
printf("ENTER THE NUMBER OF EMPLOYEES:\n");
scanf("%d",&size);
for(i=0;i<size;i++)
{
printf("ENTER EMPLOYEE CODE:\n");
scanf("%d",&V[i].Ecode);
printf("ENTER EMPLOYEE NAME:\n");
gets(V[i].Ename);
printf("ENTER EMPLOYEE TITLE\n");
gets(V[i].Etit);
printf("ENTER EMPLOYEE SALARY\n");
scanf("%d",&V[i].Esal);
}
do
{
printf("\t\t\t\tMENU\n");
printf("\t\t\t1.DISPLAY ALL EMPLOYEE INFORMATION\n");
printf("\t\t\t2.SORT BY SALARY\n");
printf("\t\t\t3.SEARCH AN EMPLOYEE\n");
printf("ENTER YOUR CHOICE");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
printf("EMPLOYEE CODE\tEMPLOYEE NAME\tEMPLOYEE TITLE\tEMPLOYEE SALARY\n");
for(i=0;i<size;i++)
printf("%d\t%s\t%s\t%d\n",V[i].Ecode,V[i].Ename,V[i].Etit,V[i].Esal);
break;    
}
case 2:
{
for(i=0;i<size;i++)
{
if(V[i].Esal<V[i+1].Esal)
{
temp=V[i].Esal;
V[i].Esal=V[i+1].Esal;
V[i+1].Esal=temp;    
}    
}
printf("EMPLOYEE CODE\tEMPLOYEE NAME\tEMPLOYEE TITLE\tEMPLOYEE SALARY\n");
for(i=0;i<size;i++)
printf("%d\t%s\t%s\t%d\n",V[i].Ecode,V[i].Ename,V[i].Etit,V[i].Esal);
break;   
}
case 3:
{
printf("ENTER EMPLOYEE CODE TO SEARCH: ");
scanf("%d",&k);
flag=0;
for(i=0;i<size;i++)
{
if(V[i].Ecode==k)
{
flag=1;
printf("EMPLOYEE CODE\tEMPLOYEE NAME\tEMPLOYEE TITLE\tEMPLOYEE SALARY\n");
printf("%d\t%s\t%s\t%d\n",V[i].Ecode,V[i].Ename,V[i].Etit,V[i].Esal);
break;       
}
else
printf("EMPLOYEE CODE NOT FOUND");
break;    
}
}
case 4:
break;
default:
{
printf("ENTER VALID CHOICE\n");
break;
}
}    
}
while(ch!=4);
return 0;
//lets see what happens
}
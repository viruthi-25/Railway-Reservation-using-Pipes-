#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
struct travel
{
    char id[5];
    char name[20];
    int phoneno;
    int count;
    int aadharno;
    char mode[20];
    char city[30];
};
int main()
{
struct travel e[20];
int a[2],b[2],n;
int a1,b1,i,v,sum=0,total;
char mo[20];
int p1=pipe(a);
int p2=pipe(b);
if(p1==-1 ||p2==-1)
{
        printf("pipe cannot be created:");
}
else
{
printf("\npipe created:");
printf("\nenter the no of customer details:");
scanf("%d",&n);
printf("\nEnter the total capacity :");
scanf("%d",&total);
for(i=0;i<n;i++)
{
printf("\nEnter the customer id :");
scanf("%s",&e[i].id);
printf("\nEnter the customer name:");
scanf("%s",&e[i].name);
printf("\nEnter phone no:");
scanf("%d",&e[i].phoneno);
printf("\nEnter count:");
scanf("%d",&e[i].count);
printf("\nEnter aadharno:");
scanf("%d",&e[i].aadharno);
printf("\nEnter the mode of transport:");
scanf("%s",&e[i].mode);
printf("\nEnter the city:");
scanf("%s",&e[i].city);
}
printf("\nEnter the mode of transport : ");
scanf("%s",&mo);
a1=fork();
b1=fork();
if(a1<0||b1<0)
{
        printf("\nFork cannot be created:");
}
if(a1>0 && b1>0)
{
close(b[0]);
close(a[1]);
close(b[1]);
printf("\n\n*******PROCESS 1*******\n\n");
printf("\n|Customerid|\t\tCustomername|\t\tPhoneno|\tCount|\t       Aaadharno|\t      Mode|\t      City|\n");
for(i=0;i<n;i++)
{
printf("|\t\t%s|\t\t%s|\t\t %d|\t\t %d|\t\t%d|\t\t%s|\t%s|",e[i].id,e[i].name,e[i].phoneno,e[i].count,e[i].aadharno,e[i].mode,e[i].city);
printf("\n");
}
}
if(a1==0 && b1>0)
{
  close(b[0]);
        close(a[0]);
        close(b[1]);
        i=0;
        printf("\n\n*******PROCESS 2*******\n\n");
        while( i<n && (e[i].mode==mo))
        {
                        printf("Employee name is: %s",e[i].name);
                        printf("Count of members is : %d",e[i].count);
                        printf("Mode of transport: %s",e[i].mode);
                        printf("City is : %s",e[i].city);
                        i++;
        }
        for(i=0;i<n;i++)
        {
                printf("%d",i);
        }
}
for(i=0;i<n;i++)
{
        if (e[i].mode==mo)
        {
                        printf("Employee name is: %s",e[i].name);
                        printf("Count of members is : %d",e[i].count);
                        printf("Mode of transport: %s",e[i].mode);
                        printf("City is : %s",e[i].city);
                        i++;
        }
}
printf("\nEnter the index to be retrieved !:");
scanf("%d",&v);
if(a1>0 && b1==0)
{
close(a[0]);
close(a[1]);
close(b[1]);
printf("\n\n*******PROCESS 3*******\n\n");
printf("\nEmployee details in %d",v);
printf("\nEmployee name is: %s",e[v].name);
printf("\nCount of members is : %d",e[v].count);
printf("\nMode of transport: %s",e[v].mode);
printf("\nCity is : %s",e[v].city);
}
if(a1==0 &&  b1==0)
{
printf("\n\n*******PROCESS 4*******");
for(i=0;i<n;i++)
{
sum+=(e[i].count);
}
if(sum>total)
{
printf("\nNot Enough Space !!!!");
}
else
printf("\nEnough Space!!!!");
}
}
}

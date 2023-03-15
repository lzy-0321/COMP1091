
#include<stdio.h>
int main()
{
    int d=0,a=0,b=0;
    printf("Enter a two-digit number:");
    scanf("%d",&d);
    if(d/10==0|| (d/100)!=0)
    {
      perror("d");
      exit(1);
    }
    a=d/10;
    b=d%10;
    printf("You entered the number ");
    switch(a)
    {
        case 2:printf("twenty");break;
        case 3:printf("thirty");break;
        case 4:printf("forty");break;
        case 5:printf("fifty");break;
        case 6:printf("sixty");break;
        case 7:printf("seventy");break;
        case 8:printf("eighty");break;
        case 9:printf("ninty");break;
        case 1:
            if(b==1)
            {printf("eleven");break;}
            else if (b==2)
             {printf("twelve");break;}
            else if(b==3)
             {printf("thirteen");break;}
            else if(b==4)
              {printf("forteen");break;}
            else if(b==5)
              {printf("fifteen");break;}
            else if(b==6)
              {printf("sixteen");break;}
            else if(b==7)
              {printf("seventeen");break;}
            else if(b==8)
              {printf("eighteen");break;}
            else if(b==9)
              {printf("ninteen");break;}
            else
              {printf("ten");break;}
 
    }
    if(a!=1){
    switch(b)
    {
 
       case 1:printf("-one");break;
       case 2:printf("-two");break;
       case 3:printf("-three");break;
       case 4:printf ("-four");break;
       case 5:printf("-five");break;
       case 6: printf("-six");break;
       case 7:printf("-seven");break;
       case 8:printf("-eight");break;
       case 9:printf("-nine");break;
       case 0:printf("-zero");break;
    }
    }
    getch();
}


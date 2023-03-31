#include <stdio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>
#include<ctype.h>
struct currency
{
    float sell,buy,moneysell,moneybuy,rate,change,get,getint;
    struct currentname
    {
        char name[100];
    } cn;
} A[100],B[100],C[100],Buy[100],Sell[100],Buyprint[100],Sellprint[100]; // c ÊÓËÃÑº fscanf printf
FILE *fp;
FILE *hb;
FILE *hs;
int i;
void NFE()
{
    printf("\t\t\t====================================================================\n");
    printf("\t\t\t\t\t\t    NO FILE EXIST \n");
    printf("\t\t\t====================================================================\n");
    printf("\t\t\tNO FILE EXIST so you have to add currency and their respective rates \n");
    printf("\t\t\t\t   Please Insert Number according to choices below\n");
    printf("\t\t\t====================================================================\n");
    printf("\t\t\t1. USD\n");
    printf("\t\t\t2. YUAN\n");
    printf("\t\t\t3. YEN\n");
    printf("\t\t\t4. POND\n");
    printf("\t\t\t5. EURO\n");
    printf("\t\t\t0. QUIT\n");
}
void NFC()
{
    printf("\t\t\t====================================================================\n");
    printf("\t\t\t\t\t\t    ENTER NEW RATE \n");
    printf("\t\t\t====================================================================\n");
    printf("\t\t\t1. USD\n");
    printf("\t\t\t2. YUAN\n");
    printf("\t\t\t3. YEN\n");
    printf("\t\t\t4. POND\n");
    printf("\t\t\t5. EURO\n");
    printf("\t\t\t0. QUIT\n");
}
void printbuy()
{

    hb = fopen("HistoryBuy.txt","r");
    int resb;
    fseek(hb,0,SEEK_END);
    resb = ftell(hb);
    fclose(hb);
    printf("\t\t\t\t--------------->>>Buy  History<<<---------------\n");
    printf("\n  Currency |  Money (inserted)  |   Exchange rate   |    Expected Exchange    |    Real Exchange    |     Change     |\n");
    if(resb==0)
    {
        printf("\n\t\t\t\t\t\tNo buy history !!!\n");
    }
    else
    {
        hb = fopen("HistoryBuy.txt","r");
        while(!feof(hb))
        {
            fscanf(hb,"\n%s %f %f %f %f %f",C[i].cn.name,&C[i].moneybuy,&C[i].rate,&C[i].get,&C[i].getint,&C[i].change);
            printf("\n  %-5s    |    %-10.2f Baht |    %-10.2f     |   %-10.2f %-5s      |      %-6.0f %-5s   |   %-6.0f Baht  |\n",C[i].cn.name,C[i].moneybuy,C[i].rate,C[i].get,C[i].cn.name,C[i].getint,C[i].cn.name,C[i].change);
            i++;
        }
        fclose(hb);
    }

}
void printsell()
{
    hs = fopen("HistorySell.txt","r");
    int ress;
    fseek(hs,0,SEEK_END);
    ress = ftell(hs);
    fclose(hs);
    printf("\n\t\t\t\t--------------->>>Sell History<<<---------------\n");
    printf("\n  Currency |   Money (inserted)   |   Exchange rate   |   Expected Exchange   |   Real Exchange   |\n");
    if(ress==0)
    {
        printf("\n\t\t\t\t\t\tNo sell history !!!\n");
    }
    else
    {
        hs = fopen("HistorySell.txt","r");
        while(!feof(hs))
        {
            fscanf(hs,"\n%s %f %f %f %f",C[i].cn.name,&C[i].moneysell,&C[i].rate,&C[i].get,&C[i].getint);
            printf("\n  %-5s    |     %-10.2f %-5s |    %-10.2f     |   %-10.2f Baht     |      %-6.0f Baht  |\n",C[i].cn.name,C[i].moneysell,C[i].cn.name,C[i].rate,C[i].get,C[i].getint);
            i++;
        }
        fclose(hs);
    }

}

int BS(void) //v=1 buy v=0 sell
{
    char confirm[5];
    int cf, n,v;
    printf("\t\t\tBuy or Sell (B/S)\n");
    do
    {
        fflush(stdin);
        printf("\t\t\tPlease Enter : ");
        gets(confirm);
    }
    while(strcmp(confirm,"S") != 0 && strcmp(confirm,"B") !=0&& strcmp(confirm,"b") !=0&& strcmp(confirm,"s") !=0);
    if(strcmp(confirm,"B")==0||strcmp(confirm,"b")==0)
    {
        v=1;
    }
    else
    {
        v=0;
    }
    return v;
}
char current[5][20] = {"USD","YUAN","YEN","POND","EURO"};

void menu()
{
    printf("\n\t\t\t=========================================\n");
    printf("                      \t\t           MENU\n");
    printf("\t\t\t=========================================\n");
    printf("\t\t\t1. Do transaction\n");
    printf("\t\t\t2. Change buy rate\n");
    printf("\t\t\t3. Change sell rate\n");
    printf("\t\t\t4. Rewrite buy&sell rate\n");
    printf("\t\t\t5. Check history\n");
    printf("\t\t\t6. Clear history\n");
    printf("\t\t\t0. Quit\n");
    printf("\t\t\t=========================================\n");
}
int firstopen()
{
    int t=0,x=0,tn=0,id=1,c1=0,c2=0,c3=0,c4=0,c5=0,pat=0,n1=0,n2=0,n3=0,n4=0,n5=0;
    float buy,sell;
    char name[20];
    if((fp=fopen("Exchangerate.txt","r"))==NULL)
    {
        fclose(fp);
        fp = fopen("Exchangerate.txt","w");//change to write

        do
        {
ple:
            x=9999;
            do
            {
                NFE();
                printf("\t\t\tSelect Number : ");
                scanf("%d",&x);
                fflush(stdin);
                system("cls");
            }
            while(x!=1&&x!=2&&x!=3&&x!=4&&x!=5&&x!=0);
            NFE();
            switch(x)
            {
            case 1:
            {

                if(c1==1)
                {
                    system("cls");
                    printf("\t\t\t\t\t       Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==1)
                {
                    printf("\t\t\t====================================================================");
                    printf("\n\t\t\t\t\t\t    Currency:%s\n",current[x-1]);
                    printf("\t\t\t====================================================================\n");
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("\t\t\tBuy  Rate : ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("\t\t\tSell Rate : ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c1=1;
                    system("cls");
                    break;
                }
            }
            case 2:
            {

                if(c2==1)
                {
                    system("cls");
                    printf("\t\t\t\t\t       Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==2)
                {
                    printf("\t\t\t====================================================================");
                    printf("\n\t\t\t\t\t\t    Currency:%s\n",current[x-1]);
                    printf("\t\t\t====================================================================\n");
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("\t\t\tBuy  Rate : ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("\t\t\tSell Rate : ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c2=1;
                    system("cls");
                    break;
                }
            }
            case 3:
            {

                if(c3==1)
                {
                    system("cls");
                    printf("\t\t\t\t\t       Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==3)
                {
                    printf("\t\t\t====================================================================");
                    printf("\n\t\t\t\t\t\t    Currency:%s\n",current[x-1]);
                    printf("\t\t\t====================================================================\n");
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("\t\t\tBuy  Rate : ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("\t\t\tSell Rate : ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c3=1;
                    system("cls");
                    break;
                }
            }
            case 4:
            {

                if(c4==1)
                {
                    system("cls");
                    printf("\t\t\t\t\t       Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==4)
                {
                    printf("\t\t\t====================================================================");
                    printf("\n\t\t\t\t\t\t    Currency:%s\n",current[x-1]);
                    printf("\t\t\t====================================================================\n");
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("\t\t\tBuy  Rate : ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("\t\t\tSell Rate : ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c4=1;
                    system("cls");
                    break;
                }
            }
            case 5:
            {

                if(c5==1)
                {
                    system("cls");
                    printf("\t\t\t\t\t       Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==5)
                {
                    printf("\t\t\t====================================================================");
                    printf("\n\t\t\t\t\t\t    Currency:%s\n",current[x-1]);
                    printf("\t\t\t====================================================================\n");
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("\t\t\tBuy  Rate : ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("\t\t\tSell Rate : ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c5=1;
                    system("cls");
                    break;
                }
            }
            case 0:
            {
                id=0;
                system("cls");
                goto BREAK;
            }
            default :
            {
                break;
            }
            }
        }
        while(id!=0);
    }
    id=1;
BREAK:
    fclose(fp);
}
int secondopen()
{
    int t=0,x=0,tn=0,id=1,c1=0,c2=0,c3=0,c4=0,c5=0,pat=0,n1=0,n2=0,n3=0,n4=0,n5=0;
    float buy,sell;
    char name[20];
    fp = fopen("Exchangerate.txt","w");
    do
        {
ple:
            x=9999;
            do
            {
                NFC();
                printf("\t\t\tSelect Number : ");
                scanf("%d",&x);
                fflush(stdin);
                system("cls");
            }
            while(x!=1&&x!=2&&x!=3&&x!=4&&x!=5&&x!=0);
            NFC();
            switch(x)
            {
            case 1:
            {

                if(c1==1)
                {
                    system("cls");
                    printf("\t\t\t\t\t       Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==1)
                {
                    printf("\t\t\t====================================================================");
                    printf("\n\t\t\t\t\t\t    Currency:%s\n",current[x-1]);
                    printf("\t\t\t====================================================================\n");
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("\t\t\tBuy  Rate : ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("\t\t\tSell Rate : ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c1=1;
                    system("cls");
                    break;
                }
            }
            case 2:
            {

                if(c2==1)
                {
                    system("cls");
                    printf("\t\t\t\t\t       Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==2)
                {
                    printf("\t\t\t====================================================================");
                    printf("\n\t\t\t\t\t\t    Currency:%s\n",current[x-1]);
                    printf("\t\t\t====================================================================\n");
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("\t\t\tBuy  Rate : ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("\t\t\tSell Rate : ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c2=1;
                    system("cls");
                    break;
                }
            }
            case 3:
            {

                if(c3==1)
                {
                    system("cls");
                    printf("\t\t\t\t\t       Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==3)
                {
                    printf("\t\t\t====================================================================");
                    printf("\n\t\t\t\t\t\t    Currency:%s\n",current[x-1]);
                    printf("\t\t\t====================================================================\n");
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("\t\t\tBuy  Rate : ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("\t\t\tSell Rate : ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c3=1;
                    system("cls");
                    break;
                }
            }
            case 4:
            {

                if(c4==1)
                {
                    system("cls");
                    printf("\t\t\t\t\t       Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==4)
                {
                    printf("\t\t\t====================================================================");
                    printf("\n\t\t\t\t\t\t    Currency:%s\n",current[x-1]);
                    printf("\t\t\t====================================================================\n");
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("\t\t\tBuy  Rate : ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("\t\t\tSell Rate : ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c4=1;
                    system("cls");
                    break;
                }
            }
            case 5:
            {

                if(c5==1)
                {
                    system("cls");
                    printf("\t\t\t\t\t       Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==5)
                {
                    printf("\t\t\t====================================================================");
                    printf("\n\t\t\t\t\t\t    Currency:%s\n",current[x-1]);
                    printf("\t\t\t====================================================================\n");
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("\t\t\tBuy  Rate : ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("\t\t\tSell Rate : ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c5=1;
                    system("cls");
                    break;
                }
            }
            case 0:
            {
                id=0;
                system("cls");
                goto BREAK;
            }
            default :
            {
                break;
            }
            }
        }
        while(id!=0);
    id=1;
BREAK:
    fclose(fp);
}
int table()
{
    int t;
    t=0;
    fp = fopen("Exchangerate.txt","r");
    printf("\t\t\t-----------------------------------------\n");
    printf("\t\t\tCurrency    \t  Buy              Sell\n");
    printf("\t\t\t-----------------------------------------\n");
    while(!feof(fp))
    {
        fscanf(fp,"%s %f %f",A[t].cn.name,&A[t].buy,&A[t].sell);
        printf("\t\t\t%-10s %10.2f   %15.2f\n",A[t].cn.name,A[t].buy,A[t].sell);
        t++;
    }
    printf("\t\t\t-----------------------------------------\n");
    fclose(fp);
    return t;

}
void welcomemenu()
{

    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t  ______          _                              __  __            _     _               _____    ____    _______ \n");
    printf("\t\t\t\t |  ____|        | |                            |  \\/  |          | |   (_)             / ____|  / __ \\  |__   __|\n");
    printf("\t\t\t\t | |__  __  _____| |__   __ _ _ __   __ _  ___  | \\  / | __ _  ___| |__  _ _ __   ___  | |      | |  | |    | |   \n");
    printf("\t\t\t\t |  __| \\ \\/ / __| '_ \\ / _` | '_ \\ / _` |/ _ \\ | |\\/| |/ _` |/ __| '_ \\| | '_ \\ / _ \\ | |      | |  | |    | |   \n");
    printf("\t\t\t\t | |____ >  < (__| | | | (_| | | | | (_| |  __/ | |  | | (_| | (__| | | | | | | |  __/ | |____  | |__| |    | |   \n");
    printf("\t\t\t\t |______/_/\\_\\___|_| |_|\\__,_|_| |_|\\__, |\\___| |_|  |_|\\__,_|\\___|_| |_|_|_| |_|\\___|  \\_____|  \\____/     |_|   \n");
    printf("\t\t\t\t                                     __/ |                                                                        \n");
    printf("\t\t\t\t                                    |___/                                                                         \n");

    printf("\n\n\t\t\t\t\t\t\t\t\t\t PRESS ANY KEY \n");
    getch();

}

void exittext()
{


    printf("\t_______ _                 _       __     __           _\n");
    printf("\t|__  __| |               | |      \\ \\   / /          | |\n");
    printf("\t  | |  | |__   __ _ _ __ | | __    \\ \\_/ /__  _   _  | |\n");
    printf("\t  | |  | '_ \\ / _` | '_ \\| |/ /     \\   / _ \\| | | | | |\n");
    printf("\t  | |  | | | | (_| | | | |   <       | | (_) | |_| | |_|\n");
    printf("\t  |_|  |_| |_|\\__,_|_| |_|_|\\_\\      |_|\\___/ \\__,_| (_)\n");
}
main()
{
    hs = fopen("HistorySell.txt","a");
    hb = fopen("HistoryBuy.txt","a");
    fclose(hs);
    fclose(hb);
    int choice,i,t,cc,v,b=0,s=0,z=0; // t,i choice 1 cc=currencychoice v=BS b=amount of buy his s=amount of sell his
    float m,zx;; //m=money input
    welcomemenu();
    system("cls");
start:
    do
    {
        choice=99999;
        firstopen();
        t=table();
        menu();
        printf("\t\t\tSelect Number : ");
        scanf("%d",&choice);
        system("cls");
        fflush(stdin);
        if(choice==1)
        {
            system("cls");
            printf("\t\t\t====================================================================");
            printf("\n\t\t\t\t\t\t    Do transaction\n");
            printf("\t\t\t====================================================================\n");
            for(i=0; i<t; i++)
            {
                printf("\t\t\t%d. %s\n",i+1,A[i].cn.name);
            }
            do
            {
                cc=9999;
                printf("\t\t\tChoose your currency type according to number above \n");
                printf("\t\t\t(0) to menu : ");
                scanf("%d",&cc);
                fflush(stdin);
                cc= cc+1;
                cc= cc-1;
            }
            while(cc>t||cc<0);
            if(cc==0)
            {
                system("cls");
                goto start;
            }
            printf("\t\t\t\t========================================================\n");
            printf("\t\t\t\t\tCurrency             Buy             Sell\n");
            printf("\t\t\t\t\t%-10s    %10.2f   %14.2f\n",A[cc-1].cn.name,A[cc-1].buy,A[cc-1].sell);
            printf("\t\t\t\t========================================================\n");
            v=BS();
            if(v==1)
            {
                do
                {
                    m=0;
                    printf("\t\t\tEnter money (Baht) : ");
                    scanf("%f",&m);
                    fflush(stdin);
                    m=m+1;
                    m=m-1;
                }
                while(m<=0);
                Buy[cc-1].get = m/A[cc-1].buy;
                Buy[cc-1].getint = (int)(m/A[cc-1].buy);
                Buy[cc-1].change = (int)(m-((int)(m/A[cc-1].buy)*A[cc-1].buy));
                printf("\t\t\t--------------------------------------------------------------------\n");
                printf("\t\t\t%.2f/%.2f = %.2f\n",m,A[cc-1].buy,Buy[cc-1].get);
                printf("\t\t\t--------------------------------------------------------------------\n");
                printf("\t\t\tMoney Exchange = %.0f %s\n",Buy[cc-1].getint,A[cc-1].cn.name);
                printf("\t\t\tChange         = %.0f Baht",Buy[cc-1].change);
                Buyprint[b].change= Buy[cc-1].change;
                Buyprint[b].moneybuy=m;
                strcpy(Buyprint[b].cn.name,A[cc-1].cn.name);
                Buyprint[b].get= Buy[cc-1].get;
                Buyprint[b].getint = Buy[cc-1].getint;
                Buyprint[b].rate = A[cc-1].buy;
                hb = fopen("HistoryBuy.txt","a");
                fprintf(hb,"\n%s %.2f %.2f %.2f %.0f %.0f",Buyprint[b].cn.name,Buyprint[b].moneybuy,Buyprint[b].rate,Buyprint[b].get,Buyprint[b].getint,Buyprint[b].change);
                fclose(hb);
                b++;
                m=0;
            }
            else if(v==0)
            {
                do
                {
                    m=0;
                    printf("\t\t\tEnter money %s : ",A[cc-1].cn.name);
                    scanf("%f",&m);
                    fflush(stdin);
                    m=m+1;
                    m=m-1;
                }
                while(m<=0);
                Sell[cc-1].get = A[cc-1].sell*m;
                Sell[cc-1].getint = (int)Sell[cc-1].get;
                printf("\t\t\t--------------------------------------------------------------------\n");
                printf("\t\t\t%.2fx%.2f = %.2f Baht\n",A[cc-1].sell,m,Sell[cc-1].get);
                printf("\t\t\t--------------------------------------------------------------------\n");
                printf("\t\t\tMoney Exchange = %.0f Baht\n",Sell[cc-1].getint);
                Sellprint[s].moneysell=m;
                strcpy(Sellprint[s].cn.name,A[cc-1].cn.name);
                Sellprint[s].get = Sell[cc-1].get;
                Sellprint[s].getint=Sell[cc-1].getint;
                Sellprint[s].rate = A[cc-1].sell;
                hs = fopen("HistorySell.txt","a");
                fprintf(hs,"\n%s %.2f %.2f %.2f %.0f",Sellprint[s].cn.name,Sellprint[s].moneysell,Sellprint[s].rate,Sellprint[s].get,Sellprint[s].getint);
                fclose(hs);
                s++;
                m=0;
            }
            printf("\n\n\t\t\t\t\t\t     PRESS ANY KEY \n");
            getch();
            system("cls");
        }
        if(choice==2)
        {
            system("cls");
            fp = fopen("Exchangerate.txt","r");
            fclose(fp);
            do
            {
                printf("\t\t\t====================================================================");
                printf("\n\t\t\t\t\t\t Change Buy Rate\n");
                printf("\t\t\t====================================================================\n");
                cc=9999;
                for(i=0; i<t; i++)
                {
                    printf("\t\t\t%d. %s\n",i+1,A[i].cn.name);
                }
                printf("\t\t\tChoose which currency type you want to change buy rate \n\t\t\t(0) to menu : ");
                scanf("%d",&cc);
                fflush(stdin);
                cc=cc+1;
                cc=cc-1;
                system("cls");
                if(cc==0)
                {
                    goto start;
                }
            }
            while(cc!=1&&cc!=2&&cc!=3&&cc!=4&&cc!=5);
            printf("\t\t\t====================================================================");
            printf("\n\t\t\t\t\t\t Change Buy Rate\n");
            printf("\t\t\t====================================================================\n");
            printf("\t\t\t%s %.2f change to?\n",A[cc-1].cn.name,A[cc-1].buy);
            printf("\n\t\t\tEnter New Rate for %s : ",A[cc-1].cn.name);
            scanf("%f",&A[cc-1].buy);
            fp = fopen("Exchangerate.txt","w");
            for(i=0; i<t; i++)
            {
                fprintf(fp,"\n%s %.2f %.2f",A[i].cn.name,A[i].buy,A[i].sell);
            }
            printf("\t\t\t====================================================================\n");
            printf("\t\t\t\t\t\t    ...Saved");
            printf("\n\n\t\t\t\t\t\t  PRESS ANY KEY \n");
            getch();
            fclose(fp);
            system("cls");
        }
        if(choice==3)
        {
            system("cls");
            do
            {
                printf("\t\t\t====================================================================");
                printf("\n\t\t\t\t\t\t Change Sell Rate\n");
                printf("\t\t\t====================================================================\n");
                cc=9999;
                for(i=0; i<t; i++)
                {
                    printf("\t\t\t%d. %s\n",i+1,A[i].cn.name);
                }
                printf("\t\t\tChoose which currency type you want to change sell rate \n\t\t\t(0) to menu : ");
                scanf("%d",&cc);
                fflush(stdin);
                cc=cc+1;
                cc=cc-1;
                system("cls");
                if(cc==0)
                {
                    goto start;
                }
            }
            while(cc!=1&&cc!=2&&cc!=3&&cc!=4&&cc!=5);
            printf("\t\t\t====================================================================");
            printf("\n\t\t\t\t\t\t Change Sell Rate\n");
            printf("\t\t\t====================================================================\n");
            printf("\t\t\t%s %.2f change to?\n",A[cc-1].cn.name,A[cc-1].sell);
            printf("\n\t\t\tEnter New Rate for %s : ",A[cc-1].cn.name);
            scanf("%f",&A[cc-1].sell);
            fp = fopen("Exchangerate.txt","w");
            for(i=0; i<t; i++)
            {
                fprintf(fp,"\n%s %.2f %.2f",A[i].cn.name,A[i].buy,A[i].sell);
            }
            printf("\t\t\t====================================================================\n");
            printf("\t\t\t\t\t\t    ...Saved");
            printf("\n\n\t\t\t\t\t\t  PRESS ANY KEY \n");
            getch();
            fclose(fp);
            system("cls");
        }
        if(choice==4)
        {
            char con1[100];
            do
            {
                printf("\n\n");
                printf("\t\t\t\t\t*Note* You need to rewrite all rate\n");
                printf("\t\t\t====================================================================\n");
                printf("\t\t\t\t\tDo you want to delete all Rate Y/N\n");
                printf("\t\t\t====================================================================\n");
                printf("\t\t\tPlease Enter : ");
                gets(con1);
                fflush(stdin);
                system("cls");

            }
            while(strcmp(con1,"Y")!=0&&strcmp(con1,"N")!=0&&strcmp(con1,"y") != 0 && strcmp(con1,"n") !=0);
            if(strcmp(con1,"Y")==0||strcmp(con1,"y")==0)
            {
                system("cls");
                secondopen();
            }
            else
            {
                system("cls");
                goto start;
            }
        }
        if(choice==5)
        {
            system("cls");
            printbuy();
            printsell();
            printf("\n\n\t\t\t\t\t\tPRESS ANY KEY \n");
            getch();
            system("cls");
        }
        if(choice==6)
        {
            char con[100];
            do
            {
                printf("\n\n");
                printf("\t\t\t====================================================================\n");
                printf("\t\t\tDo you want to delete all history Y/N : \n");
                printf("\t\t\t====================================================================\n");
                printf("\t\t\tPlease Enter : ");
                gets(con);
                fflush(stdin);
                system("cls");
            }
            while(strcmp(con,"Y")!=0&&strcmp(con,"N")!=0&&strcmp(con,"y") != 0 && strcmp(con,"n") !=0);
            if(strcmp(con,"Y")==0||strcmp(con,"y")==0)
            {
                hb = fopen("HistoryBuy.txt","w");
                hs = fopen("HistorySell.txt","w");
                fclose(hb);
                fclose(hs);
                system("cls");
                printf("\n\t\t\t\tHistory cleared successfully !\n");
            }
            else
            {
                system("cls");
                goto start;
            }
        }
        else if(choice>6)
        {
            goto start;
        }
    }
    while(choice!=0);
    if(choice==0)
    {
        system("cls");
        exittext();
    }
}


/*
Name: Aamod Paudel
Purpose: To use functions to write to and to read the data from a file. Also, use array.
Date:3/3/2017
*/


#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

typedef struct
{
    int year;
    int month;
    int day;
}time;

typedef struct
{
    char name[SIZE];
    int count;
    float rate;
    int prod_id;
    time modified_date;
    time expiry_date;
    char status[SIZE];
}prod_desc;

void read_data(prod_desc *);
void print_data(prod_desc);

int main()
{
    int i,total;
    prod_desc items[SIZE];

    printf("How many products do you want to buy?\n");
    scanf("%d",&total);

    FILE *fp;
    fp=fopen("product.txt","w");
    printf("NOTE: IF YOU BUY 3 ITEMS, YOU GET 1 FOR FREE\t BUY MORE AND YOU GET 2 OF THEM!!\nALSO, THE MORE PRODUCTS YOU BUY, THE MORE DISCOUNT YOU GET!\n");

    for(i=1;i<=total;i++)
    {
    printf("\nFor Prdouct no.%d:\n\n",i);
    read_data(&items[i]);
    fwrite(&items[i],sizeof(prod_desc),1,fp);
    }
    fclose(fp);

    fp=fopen("product.txt","r");
    printf("****************************************");
    printf("\n\nThe Datas you entered are:\n");

    for(i=1;i<=total;i++)
    {
    fread(&items[i],sizeof(prod_desc),1,fp);
    print_data(items[i]);
    }
    fclose(fp);
}

void read_data(prod_desc *items)
    {
     printf("\nEnter the product name: ");
     fflush(stdin);
     gets(items->name);

     printf("\nHow many items do you want to buy? ");
     scanf("%d",&items->count);

     printf("\nEnter the price of the the product: ");
     scanf("%f",&items->rate);

     printf("\nEnter product ID: ");
     scanf("%d",&items->prod_id);

     printf("\nEnter the Modified date:\n");
     printf("Year:");
     scanf("%d",&items->modified_date.year);
     printf("Month:");
     scanf("%d",&items->modified_date.month);
     printf("Day:");
     scanf("%d",&items->modified_date.day);

     printf("Enter the Expiry Date:\n");
     printf("Year:");
     scanf("%d",&items->expiry_date.year);
     printf("Month:");
     scanf("%d",&items->expiry_date.month);
     printf("Day:");
     scanf("%d",&items->expiry_date.day);

     printf("Status:(Just Brought or Old)\n");
     fflush(stdin);
     gets(items->status);
    }

void print_data(prod_desc items)
    {
        float price;
        price=items.rate*items.count;
    printf("\nProduct name: %s\n",items.name);
    printf("\nNo. of items: %d\n",items.count);
    printf("\nProduct rate: %f\n",price);
    printf("\nID: %d\n",items.prod_id);
    printf("\nModified Date:\n");
    printf("Year:%d\tMonth:%d\tDay:%d\n",items.modified_date.year, items.modified_date.month, items.modified_date.day);
    printf("\nExpiry Date:\n");
    printf("Year:%d\tMonth:%d\tDay:%d\n",items.expiry_date.year, items.expiry_date.month, items.expiry_date.day);
    printf("\nStatus: %s\n",items.status);

    if((price)>100 && (price)<=200)
    {
        printf("\nDiscount Percentage:5%\n");
        printf("\nDiscounted rate = %f\n",price-(0.05*price));
    }
    else if((price)>200 && (price)<=1000)
    {
        printf("\nDiscount Percentage:10%\n");
        printf("\nDiscounted rate = %f\n",(price)-(0.10*price));
    }
     else if((price)>1000 && (price)<=5000)
    {
        printf("\nDiscount Percentage:15%\n");
        printf("\nDiscounted rate = %f\n",(price)-(0.15*price));
    }
     else if((price)>5000 && (price)<=10000)
    {
        printf("\nDiscount Percentage:20%\n");
        printf("\nDiscounted rate = %f\n",(price)-(0.20*price));
    }
    else
    {
        printf("\nDiscount Percentage:25%\n");
        printf("\nDiscounted rate = %f\n",(price)-(0.25*price));
    }

    if(items.count==3)
    {
        printf("\nYou got 1 free %s!!\n\n",items.name);
        printf("*************************************\n\n");
    }
    else if(items.count>3)
    {
        printf("\nYou got 2 free %s!!\n\n",items.name);
        printf("*************************************\n\n");
    }
    }





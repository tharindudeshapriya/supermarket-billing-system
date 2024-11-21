#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdalign.h>



void billing();
void readBill();
void priceList();
void drawLines();


int main(){
    printf("\n\n\t\t\t======= Group 40 mini Project =======\n");
    printf("\n\n\t\t\t=======   Keels Super Market  =======\n");

    printf("\n\nselect :=>\n");
    printf("\n\t\t<1> Billing\n");
    printf("\t\t<2> Saved Bills\n");
    printf("\t\t<3> Exit\n");

    int ans1;
    printf("\nAnswer : ");
    scanf("%d",&ans1);

    switch(ans1){
        case 1:
            billing();
        break;
        case 2:
            readBill();
        break;
        case 3:
            printf("\nThank you ! come again..\n\n");
        break;
        default:
        printf("\n\n\t\t*****Invalid Input*****");
        main();
        break;
    }
    return 0;
}
struct sellItems{

    int fCode;
    char name[30];
    float UnitPrice;
    int qty;
    float itemTotal;
};

//billing funcion
void billing(){

    struct sellItems sell_val[50];

    float total=0;
    int Qty,foodcode;
    float discount = 0;
    char letter;
    int i;

    //display price list
    printf("\n\n");
    priceList();

    int sellCount1=0;
    int sellCount=0;
      char itemName[60][20] ={"Carrot","Bringol","Beans","Cabbage","Mushroom",
                              "Potatoes","Tomatoes","Drumstick","Apple","Avocado",
                              "Grapes","Orange","Strawberry","Banana", "Guava","Egg_Buns",
                              "Fish_Buns","Toast_Breads","Normal_Breads","Donut","Bagels",
                              "Cream_Buns","Veg_Cakes","Egg_Cakes","Chicken","Pork","Fish",
                              "Crab","Red_Meat","Mutton","Cuttle_Fish","Beef","Toothbrush",
                              "Face_Cream","Makeup_Cream","Vitamin_C_Face_Serum","Soap","Shampoos",
                              "Conditioners","Brooms","Toys","Dolls","Statues","Gifts","Marble_Jugs",
                              "Milk_Powder","White_Flour","Dhal","Sugar","Rice","Soda","Apple_Juice",
                              "Wood_Apple_Juice","Pine_Apple_Juice","Mango_Juice","Ice_Cream","Books",
                              "Pens","pencils","Erasers"};
    float unitPrice[60] = {50,100,150,50,50,80,100,200,50,100,150,50,50,60,70,50,40,100,80,50,150,50,50,45,100,150,50,50,100,90,200,400,100,150,50,50,100,230,50,200,150,300,400,350,500,680,450,160,180,90,150,100,70,80,90,50,50,20,10,5};


    printf("\n\t\t**Input 0 to get Total**\n");

    while(1){
        printf("\nEnter the food code : ");
        scanf("%d",&foodcode);

        if(foodcode<=60 && foodcode>=0){

            if(foodcode == 0){
            break;
            }

            printf("Enter the Quantity : ");
            scanf("%d",&Qty);
            printf("Item Name : %s\n",itemName[foodcode-1]);
            printf("Unit Price : Rs %.2f\n",unitPrice[foodcode-1]);
            printf("Item Total : Rs %.2f\n",unitPrice[foodcode-1]*Qty);
            total = total +  unitPrice[foodcode-1]*Qty;

            sell_val[sellCount].fCode = foodcode;
            strcpy(sell_val[sellCount].name,itemName[foodcode-1]);
            sell_val[sellCount].UnitPrice = unitPrice[foodcode-1];
            sell_val[sellCount].qty = Qty;
            sell_val[sellCount].itemTotal = unitPrice[foodcode-1]*Qty;

            sellCount++;
            sellCount1 = sellCount1 + Qty;
        }else printf("\n\t\t**Invalid Input..! Re-Enter**\n");


    }
    printf("\nTotal Items  : %d",sellCount1);
    //printf("\nTotal Items : %d",sellCount);
    printf("\nTotal : Rs %.2f",total);
    if(sellCount1>=5 && sellCount1<10){
        discount=0.05;
    }else if (sellCount1>=10){
        discount = 0.1;
    }
    printf("\nDiscount : Rs %.2f",total*discount);
    printf("\nTotal Bill :==> Rs %.2f\n",total-total*discount);

    char ans1;
    char temp;
    printf("\nDo you need bill[y/n] : ");
    scanf("%c",&temp); //temp value
    scanf("%c",&ans1);


    if ((ans1 == 'y') || (ans1 == 'Y')){

        //get current date and time
        time_t currentTime;
        //remove \n from ctime()
        currentTime = time(NULL);
        char *DateTime = ctime(&currentTime);
        DateTime[strcspn(DateTime, "\n")] = '\0'; //replace \0 instead of \n

        char createFileName[30];
        strcpy(createFileName,DateTime);

        //remove ':' from the flie name
        createFileName[strcspn(DateTime, ":")] = '-';
        createFileName[strcspn(createFileName, ":")] = '-';

            //save file name to receipts name ledger
            FILE *nameLog = fopen("billNames.txt", "a+");
            fprintf(nameLog,"\n%s",createFileName);
            fclose(nameLog);

        strcat(createFileName,".txt"); // add ".txt" to end of the file name
        char fileNameWithDir[50]="Bill Database/";
        strcat(fileNameWithDir,createFileName);
        printf("\nfile name : %s\n",fileNameWithDir);

        // char *fileName = "wdk.txt";
        FILE *file = fopen(fileNameWithDir, "w");

        printf("\n\n\t\t\t======= Keels Super Market Bill =======\n");
        fprintf(file,"\n\n\t\t\t======= Keels Super Market Bill =======\n");

        printf("\n\nDate & Time : %s\n",DateTime);
        fprintf(file,"\n\nDate & Time : %s\n",DateTime);

        drawLines();
        //draw line in textfile
        for(int i=0; i<100;i++){
        fprintf(file,"_");
        }
        fprintf(file,"\n");


        for (int i=0; i<sellCount; i++){

            printf("\nItem Code : %d \tName : %s \tUnit Price : %.2f \tQty : %d \tTotal Price : %.2f\n",sell_val[i].fCode,sell_val[i].name,sell_val[i].UnitPrice,sell_val[i].qty,sell_val[i].itemTotal);
            fprintf(file,"\nItem Code : %d \tName : %s \tUnit Price : %.2f \tQty : %d \tTotal Price : %.2f\n",sell_val[i].fCode,sell_val[i].name,sell_val[i].UnitPrice,sell_val[i].qty,sell_val[i].itemTotal);
            drawLines();

            //draw line in textfile
            for(int i=0; i<100;i++){
            fprintf(file,"_");
            }
            fprintf(file,"\n");

        }
        printf("\nTotal Items : %d",sellCount1);
        fprintf(file,"\nTotal Items : %d",sellCount1);
        printf("\nTotal : Rs %.2f",total);
        fprintf(file,"\nTotal : Rs %.2f",total);
        printf("\n[@]Discount   :==> Rs %.2f\n",total*discount);
        fprintf(file,"\n[@]Discount   :==> Rs %.2f\n",total*discount);
        printf("[@]Total Bill :==> Rs %.2f\n",total-total*discount);
        fprintf(file,"[@]Total Bill :==> Rs %.2f\n",total-total*discount);
        printf("\n\n");
        fclose(file);

    }

    printf("\nNext Customer :=>\n");
    printf("\n\t\t<1> YES\n");
    printf("\t\t<2> NO\n");

    int ans2;
    printf("\nAnswer : ");
    scanf("%d",&ans2);

    switch(ans2){
        case 1:
            billing();
        break;
        case 2:
            main();
        break;

        default:
        printf("\n\n\t\t*****Invalid Input*****");
        break;
    }
}

//read bill function
void readBill(){

    //print saved bills names
    printf("\n\n\t=====Saved Bills====\n\n");

    char *fileName = "billNames.txt";
    FILE *file = fopen(fileName, "r");

    if (file == NULL){
        printf("\nFile not found!\n %s", fileName);
    }

    char chr;

    while ((chr = fgetc(file)) != EOF)
        putchar(chr);

    fclose(file);


    //read bill
    char billName[30];
    char tempC;
    printf("\n\nEnter the Bill Name : ");
    scanf("%c",&tempC);
    gets(billName);

    strcat(billName,".txt"); // add ".txt" to end of the file name
    char fileNameWithDir[50]="Bill Database/";
    strcat(fileNameWithDir,billName);

    //*************
    FILE *fileD = fopen(fileNameWithDir, "r");

    if (fileD == NULL){
        printf("\nBile not found!\n %s", fileNameWithDir);
    }

    char chrD;
    while ((chrD = fgetc(fileD)) != EOF)
        putchar(chrD);

    fclose(fileD);

    printf("\n");

    printf("\nNext Bill :=>\n");
    printf("\n\t\t<1> YES\n");
    printf("\t\t<2> NO\n");

    int ans3;
    printf("\nAnswer : ");
    scanf("%d",&ans3);

    switch(ans3){
        case 1:
            readBill();
        break;
        case 2:
            main();
        break;

        default:
        printf("\n\n\t\t*****Invalid Input*****");
        break;
    }

}

void drawLines(){

    for(int i=0; i<100;i++){
        printf("_");
    }
    printf("\n");
}

//Print Price List from priceList text file
void priceList(){

    char *fileName = "priceList.txt";
    FILE *file = fopen(fileName, "r");

    if (file == NULL){
        printf("\nFile not found!\n %s", fileName);
    }

    char chr;

    while ((chr = fgetc(file)) != EOF)
        putchar(chr);

    fclose(file);

}


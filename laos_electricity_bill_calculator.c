//
//  laos_electricity_bill_calculator.c
//  
//
//  Created by Syvanonh Boualaphanh on 22/2/22.
//

#include<stdio.h>

void red(){
  printf("\033[0;31m");
}

void reset () {
  printf("\033[0m");
}
int main(){
    int usage, cost, tCost, payabl, roundTax, roundDiscnt;
    float discnt, tax;
    int c1 = 25*355;
    int c2 = 125*422;
    int c3 = 150*815;
    int c4 = 100*898;
    int c5 = 100*984;
    int c6 = 0;
    int maintn = 24700;
    
    printf("\nEnter this month's electricity usage (in kWh):\n");
    scanf("%d", &usage);
    
    if (usage>=501){
        c6 = (usage-500)*1019;
    }
    else if (usage>=401){
        c5 = (usage-400)*984;
    }
    else if (usage>=301){
        c5 = 0;
        c4 = (usage-300)*898;
    }
    else if (usage>=151){
        c5 = 0;
        c4 = 0;
        c3 = (usage-150)*815;
    }
    else if (usage>=26){
        c5 = 0;
        c4 = 0;
        c3 = 0;
        c2 = (usage-25)*422;
    }
    else{
        c5 = 0;
        c4 = 0;
        c3 = 0;
        c2 = 0;
        c1 = usage*355;
    }
    
    cost = c1+c2+c3+c4+c5+c6;
    discnt = (cost+maintn)*0.03;
    tax = (cost+maintn-discnt)*0.07;

    int tempDiscnt, tempTax, tempCheckDiscnt, tempCheckTax, rnddiscnt, rndtax;
    
    tempDiscnt = discnt*10;
    tempTax = tax*10;
    tempCheckDiscnt = tempDiscnt%10;
    tempCheckTax = tempTax%10;
    
    if (tempCheckDiscnt>=5){
        roundDiscnt = discnt;
        roundDiscnt++;
    }else{
        roundDiscnt = discnt;
    }
    if (tempCheckTax>=5){
        roundTax = tax;
        roundTax++;
    }else{
        roundTax = tax;
    }
    
    printf("\nEnter payable from last month:\n");
    scanf("\n%d", &payabl);
    
    tCost = cost+maintn-roundDiscnt+roundTax+payabl;
    
    printf("\nElectricity cost is ");
    red();
    printf("%d", cost);
    reset();
    printf(".\n");
    
    printf("\nMaintenance (fixed) is ");
    red();
    printf("%d", maintn);
    reset();
    printf(".\n");
    
    printf("\nDiscount (3%%) is ");
    red();
    printf("%d", roundDiscnt);
    reset();
    printf(".\n");
    
    printf("\nTax (7%%) is ");
    red();
    printf("%d", roundTax);
    reset();
    printf(".\n");
    
    printf("\nThis month's total cost is ");
    red();
    printf("%d", tCost);
    reset();
    printf(".\n\n");
    return 0;
}

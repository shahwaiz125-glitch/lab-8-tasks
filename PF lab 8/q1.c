#include<stdio.h>
void packages();
int pack_number();
long long mobile_number();
int pack_amount(int pack_number);
float bonus(int amount);
float new_amount(int amount);
void print(long long mobile_number,int amount, float tax_amount, float bonus_amount);

int main(){
    long long mobile_num;
    mobile_num = mobile_number();
    packages();

    int recharge;
    do
    {
        printf("how many times do you want to recharge(max 3)\n");
        scanf(" %d", &recharge);
        if(recharge < 1 || recharge > 3){
            printf("Invalid value - Please enter again\n");
        }
    } while (recharge < 1 || recharge > 3);

    int amount=0;
    int pack_num;
    float n_amount;
    float Bonus;
    float total_money;
    for(int i=0; i<recharge;i++){
        pack_num = pack_number();
        amount = pack_amount(pack_num);
        n_amount = new_amount(amount);
        Bonus = bonus(amount);
        total_money += (amount + n_amount);
        print(mobile_num,amount,n_amount,Bonus);
    }
    printf("\n");
    printf("total money spent: %f\n", total_money);
    
    return 0;
}

void packages(){
    printf("---Here is our package list---\n");
    printf("package 1: Rs. 100\n");
    printf("package 2: Rs. 200\n");
    printf("package 3: Rs. 500\n");
    printf("package 4: Rs. 1000\n");
    return;
}
int pack_number(){
    int num;
    do
    {
        printf("Which package would you like?\n");
        scanf(" %d", &num);
        if(num <1 || num > 4){
            printf("Invalid value - Please enter again\n");
        }
    } while (num <1 || num > 4);
    return num;
}
long long mobile_number(){
    long long mob_num;
    do{
        printf("Enter mobile number(11 digits)\n");
        scanf(" %lld",&mob_num);
        if(mob_num < 10000000000LL || mob_num > 99999999999LL){
            printf("Number not 11 digits - Please ente again\n");
        }
    }while(mob_num < 10000000000LL || mob_num > 99999999999LL);
    return mob_num;
}
int pack_amount(int pack_number){
    int amount=0;
    switch (pack_number)
    {
    case 1:
        amount +=100;
        break;
    case 2:
        amount+= 200;
        break;
    case 3:
        amount+=500;
        break;
    case 4:
        amount+=1000;
        break;
    }
    return amount;
}
float new_amount(int amount){
    return (amount * 0.15);
}
float bonus(int amount){
    if(amount >= 500){
        return (amount * 0.10);
    }else{
        return 0.0;
    }
}
void print(long long mobile_number,int amount, float tax_amount, float bonus_amount){
    float total_balance = amount+bonus_amount;
    float payable_amount = amount + tax_amount;
    printf("-------Here is your slip-------\n");
    printf("Mobile Number : %lld\n",mobile_number);
    printf("Base amount: %d\n", amount);
    printf("Bonus Package: %f\n", bonus_amount);
    printf("Total balance: %f\n", total_balance);
    printf("Tax: %f\n", tax_amount);
    printf("payable amount: %f\n", payable_amount);
    printf("-------------------------------\n");
    printf("\n");
    return;
}
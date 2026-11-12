#include<stdio.h>
void hospital_detail(){
    printf("---Welcome to Cleveland Clinic---\n");
    printf("Here is our chargers:\n");
    printf("1.General ward: Rs.1500/day\n");
    printf("2.Semi Private: Rs.3500/day\n");
    printf("3.Private: Rs.6000/day\n");
    printf("\n");
    return;
}
int room_type(){
    int type;
    do{
        printf("Enter your room type\n");
        scanf(" %d",&type);
        if(type<1 || type>3){
            printf("Invalid Type - Please enter again");
        }
    }while(type<1 || type>3);
    return type;
}
int num_of_days(){
    int days;
    do{
        printf("Enter number of days stayed\n");
        scanf(" %d", &days);
        if(days < 1 || days > 30){
            printf("Invalid days - Please enter again\n");
        }
    }while(days < 1 || days > 30);
    return days;
}
int room_charges(int type,int days){
    int charge;
    switch (type)
    {
    case 1:
        charge = 1500;
        break;
    case 2:
        charge = 3500;
        break;
    case 3:
        charge = 6000;
        break;
    }
    return(days * charge);
}
float medicine_charge(){
    int medicine_bill;
    printf("Enter your medicine bill\n");
    scanf(" %d", &medicine_bill);
    printf("5 percent service charge added\n");
    return medicine_bill * 105/100;
}
float discount(float total,int days){
    if(days > 7){
        float n_total;
        printf("8 percent discount recieved\n");
        n_total = total*92/100;
        return n_total;
    }else{
        printf("No discount");
        return 0.0;
    }
}
void print_bill(int room_type , int days , int room_charges , float medicine_charges , float final_amount){
    printf("--------Your Final Bill--------\n");
    printf("%d. ", room_type);
    switch (room_type)
    {
    case 1:
        printf("General Ward\n");
        break;
    case 2:
        printf("Semi Private\n");
        break;
    case 3:
        printf("Private\n");
        break;
    }
    printf("Days stayed: %d\n",days);
    printf("Room Charges: %d\n",room_charges);
    printf("Medicine Charges: %f\n", medicine_charges);
    printf("Final Amount: %f\n",final_amount);
    printf("---------------------------------------");
    return;
}
int main(){
    hospital_detail();
    int room = room_type();
    int days = num_of_days();
    int r_charges = room_charges(room,days);
    float medicine_bill = medicine_charge();
    float total = r_charges + medicine_bill;
    float final_amount = discount(total,days);
    char senior_citizen;
    do{
        printf("is patient a senior citizen(Y = yes, N = no)");
        scanf(" %c", &senior_citizen);
        if((senior_citizen == 'Y' || senior_citizen == 'y') && final_amount > 1000){
            final_amount -= 1000;
        }else if(senior_citizen == 'N' || senior_citizen == 'n'){
            printf("No senior citizen discount\n");
        }else{
            printf("invalid value\n");
        }
    }while(senior_citizen != 'Y' && senior_citizen != 'y' && senior_citizen != 'N' && senior_citizen != 'n');
    print_bill(room,days,r_charges,medicine_bill,final_amount);

}
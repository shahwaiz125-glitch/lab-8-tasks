void routes(){ //1
    printf("---WELCOME TO PAKISTAN BUS SERVICE---\n");
    printf("1. Karachi to Hyderabad : Rs.800\n");
    printf("2. Karachi to Sukkur : Rs.2200\n");
    printf("3. Karachi to Multan : Rs.3500\n");
    printf("-----------------------------------\n");
    return;
}
int route_number(){ //2
    int route_num;
    do{
        printf("Enter route number(1 to 3): ");
        scanf(" %d", &route_num);
        if(route_num < 1 || route_num > 3){
            printf("\n");
            printf("Invalid value - Please enter again");
        }
    }while(route_num < 1 || route_num > 3);
    return route_num;
}
int no_of_seats(){ //3
    int seats;
    do{
        printf("Enter the number of seats you would like(1 to 6): ");
        scanf(" %d", &seats);
        if(seats <1 || seats > 6){
            printf("\n");
            printf("Invalid value - Please enter again");
        }
    }while(seats <1 || seats > 6);
    return seats;
}
int seat_fare(int route_number){ //4
    int fare;
    switch (route_number)
    {
    case 1:
        printf("your fare is 800 for this seat\n");
        fare = 800;
        break;
    case 2:
        printf("your fare is 2200 for this seat\n");
        fare = 2200;
        break;
    case 3:
        printf("your fare is 3500 for this seat\n");
        fare = 3500;
        break;
    }
    return fare;
}
int total_fare(int seat_fare , int no_of_seats){ //5
    int total =0;
    total = seat_fare * no_of_seats;
    return total;
}
float type_charge(int total , char* type){ //6
    char seat_type;
    float new_total;
    do{
        printf("Enter seat type (E = Economy , B = Buisness): ");
        scanf(" %c", &seat_type);
        if((seat_type != 'E' && seat_type != 'e') && (seat_type != 'B' && seat_type != 'b')){
            printf("\n");
            printf("Invalid Value - Please enter again \n");
        }
    }while((seat_type != 'E' && seat_type != 'e') && (seat_type != 'B' && seat_type != 'b'));
    if(seat_type == 'E' || seat_type == 'e'){
        printf("No extra charges \n\n\n");
        *type = 'E';
        new_total = total;
    }else{
        printf("30 percent extra charges\n\n\n");
        *type = 'B';
        new_total = total * 130/100;
    }
    return new_total;
}
void print_ticket(int route_number, int no_of_seats, char type, float new_total){ //7
    printf("--------TICKET--------\n\n");
    printf("Route Name: ");
    switch(route_number)
    {
        case 1:
            printf("Karachi To Hyderabad\n");
            break;
        case 2:
            printf("Karachi To Sukkur\n");
            break;
        case 3:
            printf("Karachi To Multan\n");
            break;
    }
    printf("Number of seats you booked: %d\n",no_of_seats);
    printf("Seat type: %c\n", type);
    printf("Final Fare: %.2f\n", new_total);
    printf("-----------------------\n\n");
    return;
}

int main(){
    routes();
    int r_no = route_number();
    int no_of_s = no_of_seats();
    int fare = seat_fare(r_no);
    int total = total_fare(fare, no_of_s);
    printf("total %d\n", total);
    char type;
    float new_total = type_charge(total, &type);
    print_ticket(r_no, no_of_s, type, new_total);
}
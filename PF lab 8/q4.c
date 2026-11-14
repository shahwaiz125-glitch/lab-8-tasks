#include <stdio.h>
void printRules() {
    printf("========================================\n");
    printf("          TAXI FARE CALCULATOR          \n");
    printf("========================================\n");
    printf("Fare Rules:\n");
    printf("- Base fare: Rs. 150\n");
    printf("- Distance charge: Rs. 60 per km for the first 10 km, then Rs. 45 per km after that.\n");
    printf("- Waiting charge: First 5 minutes are free, then Rs. 10 per minute.\n");
    printf("- Night charge: 25%% extra if the trip hour is 22 or later, or before 6.\n");
    printf("----------------------------------------\n");
}
float getDistance() {
    float distance;
    do {
        printf("Enter trip distance in km (0 < distance <= 200): ");
        scanf("%f", &distance);
        if (distance <= 0 || distance > 200) {
            printf("Invalid distance! Please enter a value between 0 and 200.\n");
        }
    } while (distance <= 0 || distance > 200);
    return distance;
}
int getWaitingTime() {
    int waitingTime;
    do {
        printf("Enter waiting time in minutes (0 to 120): ");
        scanf("%d", &waitingTime);
        if (waitingTime < 0 || waitingTime > 120) {
            printf("Invalid waiting time! Please enter a value between 0 and 120.\n");
        }
    } while (waitingTime < 0 || waitingTime > 120);
    return waitingTime;
}
float calculateDistanceCharge(float distance) {
    float baseFare = 150.0;
    float distanceCharge = 0.0;
    
    if (distance <= 10) {
        distanceCharge = baseFare + (distance * 60.0);
    } else {
        distanceCharge = baseFare + (10 * 60.0) + ((distance - 10) * 45.0);
    }
    
    return distanceCharge;
}
float calculateWaitingCharge(int waitingTime) {
    if (waitingTime <= 5) {
        return 0.0;
    } else {
        return (waitingTime - 5) * 10.0;
    }
}
float applyNightCharge(float currentFare) {
    int hour;
    do {
        printf("Enter the hour of the trip (0 to 23): ");
        scanf("%d", &hour);
        if (hour < 0 || hour > 23) {
            printf("Invalid hour! Please enter a value between 0 and 23.\n");
        }
    } while (hour < 0 || hour > 23);
    
    if (hour >= 22 || hour < 6) {
        currentFare += currentFare * 0.25;
    }
    
    return currentFare;
}
void printReceipt(int tripNumber, float distance, int waitingTime, float finalFare) {
    printf("\n--- Trip #%d Receipt ---\n", tripNumber);
    printf("Distance Traveled : %.2f km\n", distance);
    printf("Waiting Time      : %d minutes\n", waitingTime);
    printf("Total Final Fare  : Rs. %.2f\n", finalFare);
    printf("------------------------\n\n");
}

int main() {
    float totalEarnings = 0.0;
    float highestFare = 0.0;
    int totalTrips = 3;

    printRules();

    for (int i = 1; i <= totalTrips; i++) {
        printf("\nProcessing Trip %d of %d:\n", i, totalTrips);
        
        float distance = getDistance();
        int waitingTime = getWaitingTime();
        float fare = calculateDistanceCharge(distance);
        
        fare += calculateWaitingCharge(waitingTime);
        fare = applyNightCharge(fare);
        printReceipt(i, distance, waitingTime, fare);
        totalEarnings += fare;

        if (fare > highestFare) {
            highestFare = fare;
        }
    }
    printf("========================================\n");
    printf("           END OF DAY SUMMARY           \n");
    printf("========================================\n");
    printf("Total Earnings for %d trips : Rs. %.2f\n", totalTrips, totalEarnings);
    printf("Highest Fare of the Day     : Rs. %.2f\n", highestFare);
    printf("========================================\n");
}
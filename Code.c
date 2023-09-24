#include <stdio.h>
int cities[100][100], visited_cities[100], limit, cost = 0;
 
int find(int c){
    int count, nearest_city = 999;
    int minimum = 999, temp;
    for(count = 0; count < limit; count++){
        if((cities[c][count] != 0) && (visited_cities[count] == 0)){
            if(cities[c][count] < minimum){
                minimum = cities[count][0] + cities[c][count];
            }
            temp = cities[c][count];
            nearest_city = count;
        }
    }
    if(minimum != 999){
        cost = cost + temp;
    }
    return nearest_city;
}
 
void mincost(int city){
    int nearest_city;
    visited_cities[city] = 1;
    printf("%d ", city + 1);
    nearest_city = find(city);
    if(nearest_city == 999){
        nearest_city = 0;
        printf("%d", nearest_city + 1);
        cost = cost + cities[city][nearest_city];
        return;
    }
    mincost(nearest_city);
}
 
int main(){
    printf("\t\tWelcome to our delivery system.\n");
    printf("Enter total number of cities you want to deliver: ");
    scanf("%d", &limit);
    printf("Enter the cost of travelling in between the cities:\n");
    for(int i = 0; i < limit; i++){
        printf("Enter %d Elements in Row%d\n", limit, i + 1);
        for(int j = 0; j < limit; j++){
            scanf("%d", &cities[i][j]);
        }
        visited_cities[i] = 0;
    }
    printf("Entered costs for travelling through cities:\n");
    for(int i = 0; i < limit; i++){
        printf("\n");
        for(int j = 0; j < limit; j++){
            printf("%d ", cities[i][j]);
        }
    }
    printf("\n\nPath:\t");
    mincost(0);
    printf("\n\nMinimum Cost: \t");
    printf("%d\n", cost);
    return 0;
}   

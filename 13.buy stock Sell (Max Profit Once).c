#include <stdio.h>
#include <limits.h> // For INT_MAX

// Function to find max profit
void findMaxProfit(int prices[], int n) {
    if (n < 2) {
        printf("Not enough data to trade.\n");
        return;
    }
    
    int min_price_so_far = INT_MAX;
    int max_profit = 0;
    int buy_day = 0;
    int sell_day = 0;
    int temp_buy_day = 0;
    
    for (int i = 0; i < n; i++) {
        // Check for new minimum price
        if (prices[i] < min_price_so_far) {
            min_price_so_far = prices[i];
            temp_buy_day = i;
        }
        
        // Check if selling today gives more profit
        if (prices[i] - min_price_so_far > max_profit) {
            max_profit = prices[i] - min_price_so_far;
            buy_day = temp_buy_day;
            sell_day = i;
        }
    }
    
    printf("Max Profit: %d\n", max_profit);
    printf("Buy on day %d (Price %d)\n", buy_day, prices[buy_day]);
    printf("Sell on day %d (Price %d)\n", sell_day, prices[sell_day]);
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);
    
    findMaxProfit(prices, n); // Buy at 1, Sell at 6
    
    return 0;
}
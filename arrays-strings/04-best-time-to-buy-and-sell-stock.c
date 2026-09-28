#include <stdio.h>

// LeetCode solution function
int maxProfit(int *prices, int pricesSize)
{
    if (pricesSize < 2)
    {
        return 0;
    }

    int minimumPrice = prices[0];
    int bestProfit = 0;
    // Treat each day as the sale day and use the cheapest earlier price.
    for (int day = 1; day < pricesSize; day++)
    {
        int profit = prices[day] - minimumPrice;
        if (profit > bestProfit)
        {
            bestProfit = profit;
        }
        if (prices[day] < minimumPrice)
        {
            minimumPrice = prices[day];
        }
    }
    return bestProfit;
}

// Local testing
static void runTest(const char *label, const int *prices, int size, int expected,
                    const char *input)
{
    int actual = maxProfit((int *)prices, size);
    printf("%s\nInput: %s\nExpected Output: %d\nActual Output: %d\nResult: %s\n\n",
           label, input, expected, actual, actual == expected ? "PASS" : "FAIL");
}

int main(void)
{
    int typical[] = {7, 1, 5, 3, 6, 4};
    int falling[] = {7, 6, 4, 3, 1};
    runTest("Test Case 1", typical, 6, 5, "prices=[7,1,5,3,6,4]");
    runTest("Test Case 2", falling, 5, 0, "prices=[7,6,4,3,1] (no profitable trade)");
    return 0;
}
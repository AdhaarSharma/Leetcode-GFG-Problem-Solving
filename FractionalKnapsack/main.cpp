class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, [](const Item &a, const Item &b){
            double num1 = (double) a.value / (double) a.weight; 
            double num2 = (double) b.value / (double) b.weight; 
            return (num1 > num2);
        });
        int cur = 0;
        double res = 0;
        for(int i = 0; i<n; i++){
            if(cur + arr[i].weight <= W){
                cur += arr[i].weight;
                res += arr[i].value;
            }
            else {
                int remain = W - cur;
                res += arr[i].value * ((double) remain / (double) arr[i].weight);
                break;
            }
        }
        return res;
    }
        
};
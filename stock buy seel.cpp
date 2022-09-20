#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
     int n=prices.size(), maxprofit = 0;
        
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               if(prices[j]>prices[i]){
                   int diff=prices[j] - prices[i];
                   if(diff>maxprofit){
                        maxprofit=diff;
                   }
               }
           }
       }
        return maxprofit;
}

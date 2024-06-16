/*
https://www.geeksforgeeks.org/problems/sum-of-prime4751/1
Given a number n, find out if n can be expressed as a+b, where both a and b are prime numbers.
If such a pair exists, return the values of a and b, otherwise return [-1,-1] as an array of size 2.
Note: If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, and a < c then  [a, b] is considered as our answer.
*/

class Solution {
  public:
    vector<int> getPrimes(int n) {
        // code here
        vector<bool>isPrime(n+1,true);
        for(int i = 2;i<=n;i++)
        {
            if(isPrime[i])
            {
               for(int j = i*2;j<=n;j+=i)
                {
                    isPrime[j] = false;
                } 
            }
            
        }
        
        
        for(int i = 2;i<n;i++)
        {
            if(isPrime[i] && isPrime[n-i])
            {
                vector<int>tem;
                tem.push_back(i);
                tem.push_back(n-i);
                return tem;
            }
        }
        
        vector<int>tem;
        tem.push_back(-1);
        tem.push_back(-1);
        return tem;
    }
};
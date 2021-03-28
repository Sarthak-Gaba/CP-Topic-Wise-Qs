int maxSubarraySum(int a[], int n){
    
    int x=0,maxm=INT_MIN;
    for(int i=0; i<n; i++)
    {
        x += a[i];
        if(x<0)
            x=0;
        maxm = max(x,maxm);
    }
    return maxm;
}

//Note: Special Case -> When all elements are negative, you need to output the smallest -ve number
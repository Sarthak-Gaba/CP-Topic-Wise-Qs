int gcd(int a, int b)
{
    if(b==0)
		return a;
	return gcd(b,a%b);
}

int nCr(int n, int r)
{
    if(r==0 || r==n)
        return 1;
    r = min(r,n-r);
    int a = n, b = r;
    for(int i=1; i<=r-1; i++)
    {
        a *= (n-i);
        b *= i;
        int temp = gcd(a,b);
        a = a/temp;
        b = b/temp;
    }
    return a;
}
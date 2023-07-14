int power(int a,int x)
{
    if(x==0)return 1;
    if(x==1)return a;
    else return a*power(a,x-1);
}
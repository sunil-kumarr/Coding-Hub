#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        char* s = new char[n*sizeof(char)];
        cin>>n>>s;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')count++;
        }
        long long int ans= (count*(count+1))/2;
        cout<<ans<<endl;
    }
    return 0;
}
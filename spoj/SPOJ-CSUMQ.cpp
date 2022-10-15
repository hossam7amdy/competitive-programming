#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
    int N;
    scanf("%d", &N);
    N++;
    vector<int> v(N, 0);
    for(int i=1; i<N; i++)
    {
        scanf("%d", &v[i]);
        v[i] = v[i] + v[i-1];
    }

    scanf("%d", &N); // queries
    unsigned long long int sum = 0;
    while(N--)
    {
        int i, j;
        scanf("%d%d", &i,&j);
        sum = v[j+1] - v[i];
        printf("%d\n", sum);
    }

    return 0;
}

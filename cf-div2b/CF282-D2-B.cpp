#include<bits/stdc++.h>
using namespace std;



int main(){
    int n, A = 0, G = 0;
    cin >> n;

    while(n--){
        int a, g;
        scanf("%d%d", &a,&g);

        if(abs((A+a) - G) <= 500){
            A+=a;
            printf("A");
        }else{
            G+=g;
            printf("G");
        }
    }

    return 0;
}

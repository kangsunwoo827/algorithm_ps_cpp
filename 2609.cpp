#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int choidae(int a, int b){
    while (1){
    if (a<b){
        swap(a,b);
    }
    a=a%b;
    if (a==0){
        return b;
    }
    else{
        continue;
    }
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int a, b;

    cin >> a >> b;
    int choidae_num = choidae(a,b);
    cout << choidae_num << '\n' << a*b/choidae_num;


    return 0;
}
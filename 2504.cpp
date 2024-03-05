#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int calculate(string s){
    int cnt1 =0, cnt2=0 ;
    if (s.empty()){
        return 0;
    }
    else if (s=="()"){
        return 2;
    }
    else if (s=="[]"){
        return 3;
    }
    for (int i =0 ; i < s.length(); i++){        
        if (s[i] == '('){
            cnt1++;
        }
        else if (s[i] == ')'){
            cnt1--;
        }
        else if (s[i] == '['){
            cnt2++;
        }
        else if (s[i] == ']'){
            cnt2--;
        }
        if (cnt1==0 && cnt2==0){
            int result1 = calculate(s.substr(1,i-1));
            if (s[0]=='('){
                if (i==1){
                    result1= 2;
                }
                else {
                result1*=2;
                }
            }
            else if (s[0]=='[') {
                if (i==1){
                    result1= 3;
                }
                else {
                result1*=3;
                }
            }

            if (i==s.length()-1){
                return result1;
            }

            else{
                int result2 = calculate(s.substr(i+1));
                
                if (result2>0){
                    return result1+result2;
                }
                else {
                    return 0;
                }
            }
        }
    }
    return 0;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    string str;
    cin >> str;

    cout << calculate(str);
    return 0;
}

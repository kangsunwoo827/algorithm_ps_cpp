#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

bool visited[1000010][10];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int k; string nums;
    cin >> nums;
    cin >> k;

    queue<pair<string,int>> q; // string과 바꾼 횟수
    int res=-1;
    q.push(make_pair(nums,0));
    while(!q.empty()) {
        string cur_nums = q.front().first;
        int cur_change = q.front().second;
        q.pop();
        if (visited[stoi(cur_nums)][cur_change]) continue;
        visited[stoi(cur_nums)][cur_change]=true;

        if (cur_nums[0]=='0') continue;
        if (cur_change == k){
            res = max(stoi(cur_nums),res);
        }
        if (cur_change < k){
            for (int i=0; i< cur_nums.length(); i++){
                for (int j=i+1; j<cur_nums.length();j++){
                    swap(cur_nums[i],cur_nums[j]);
                    q.push(make_pair(cur_nums,cur_change+1));
                    swap(cur_nums[i],cur_nums[j]);
                }
            }
        }
    }

    cout << res <<"\n";

    return 0;
}
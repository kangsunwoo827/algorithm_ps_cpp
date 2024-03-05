#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> linked[10010];

queue<int> q;
int nums[10001]; // v를 넣으면 node 번호를 알려줌
bool is_danger[10001] ; // 특정 번호에 대해 단절점인지 알려줌

int num_cnt = 1;
int findDanger(int cur_node, bool isRoot){
    int child = 0;
    nums[cur_node] = num_cnt ++;
    int ret = nums[cur_node];
    for (int i=0; i< linked[cur_node].size() ; i++){
        int next_node = linked[cur_node][i];

        if (nums[next_node]==0) {
            child ++;
            int root_of_subtree = findDanger(next_node,false);

            if (!isRoot && root_of_subtree >= nums[cur_node]){
                is_danger[cur_node] = true;
            }

            ret = min(ret,root_of_subtree);
        }
        else{
            ret = min(ret, nums[next_node]);
        }
    }
    if (isRoot && child>=2) {
        is_danger[cur_node] = true;}


    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    // 루트를 하나 지정한다.

    // 타고 가면서. 번호를 메긴다.

    // 특정 node에 대해 그 node의 자식이 본인을 거치지 않고 올라갈 수 있다면 (node보다 작은 번호를 찾는다면) 그 node는 단절점이다

    // root에 대해서는 자식이 2개이상이면 단절점이다.

    int v,e ;
    cin >> v >> e;

    while (e--){
        int a,b;
        cin >> a >> b;
        linked[a].push_back(b);
        linked[b].push_back(a);
    }

    for (int i=1; i<=v; i++){
        findDanger(i,true);
    }

    vector<int> answer;
    int danger_cnt=0;
    for (int i=1; i<=v; i++){
        if (is_danger[i]==1){
            danger_cnt++;
            answer.push_back(i);
        }
    }
    cout << danger_cnt <<"\n";

    for (int i=0; i<answer.size(); i++){
        cout << answer[i] << " ";
    }



    return 0;
}
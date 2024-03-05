    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    pair<int,int> nums[1000010*10]; // idx and nums
    int origin_nums[1000010*10];
    int tree[1000010*10];
    int dp[1000010*10];
    int before[1000010*10];

    int ret_idx;

    pair<int,int> query(int cur_node, int start, int end, int q1, int q2){ // max value, max idx
        if (end<q1||q2<start) return make_pair(0,0);
        if (start==end) {
            return make_pair(tree[cur_node],start);
        }
        int mid = (start + end) /2;

        pair<int,int> res1 = query(cur_node*2,start,mid,q1,q2);
        pair<int,int> res2 = query(cur_node*2+1,mid+1,end,q1,q2);

        if (res1.first > res2.first) return res1;
        else return res2;

    }

    void update(int cur_node, int start, int end, int target, int value){
        if (target< start || end < target) return;
        if (start==end) {
            tree[cur_node] = value;
            return;
        }

        int mid = (start+end)/2;

        update(cur_node*2,start,mid,target,value);
        update(cur_node*2+1,mid+1,end,target,value);

        tree[cur_node] = max(tree[cur_node*2],tree[cur_node*2+1]);
    }

    void print_lis(int lis_end_idx,int cnt){
            if (cnt==0) return;
            print_lis(before[lis_end_idx],cnt-1);
            cout << origin_nums[lis_end_idx] << " ";
            return;
        }

    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        freopen("input.txt", "r", stdin);

        int n;
        
        cin >> n;

        for (int i=1; i<=n;i++){
            cin >> origin_nums[i];
            nums[i]= make_pair(origin_nums[i],-i);
        }

        // 자식에 깔리는 값은 상대적인 숫자의 크기.
        sort(nums+1,nums+n+1);
        int tree_size = 1;
        while (tree_size < n) tree_size*=2;
        
        // int size_num = 0;
        int cur_num,cur_idx;
        for (int i=1; i<=n; i++){
            cur_num = nums[i].first;
            cur_idx = -nums[i].second;
            pair<int,int> query_res = query(1,1,n,1,cur_idx-1);
            dp[cur_idx] = query_res.first+1;
            before[cur_idx] = query_res.second;
            update(1,1,n,cur_idx,dp[cur_idx]);
        }
        pair<int,int> max_res = query(1,1,n,1,n);

        vector<int> lis;
        int lis_end_idx= max_res.second;

        cout << max_res.first << "\n";

        print_lis(lis_end_idx,max_res.first);

        return 0;
    }
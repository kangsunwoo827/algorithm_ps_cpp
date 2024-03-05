#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> node[31][31];
int myobi[31][31];
int distance_matrix[31][31];
int is_exist_teleport[31][31];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);

    int w,h, g, e;

    while (1){
        cin >> w >> h;
        if (w==0 && h==0){
            return 0;
        }
        
        vector<vector<int>> node[31][31];
        int myobi[31][31];
        int distance_matrix[31][31];
        int is_exist_teleport[31][31];

        cout << sizeof(myobi) <<endl;
        cout << sizeof(distance_matrix) <<endl;
        cout << sizeof(is_exist_teleport) <<endl;
        for (int i = 0; i <w; i++) {
            for (int j=0; j<h ; j++){
                myobi[i][j] = 0;
                distance_matrix[i][j] = 10000*w*h+1;
                is_exist_teleport[i][j] = 0;

                if (i==0 && j==0) distance_matrix[i][j] = 0;
                vector<vector<int>> vec = node[i][j];
                for (int iter=0; iter < vec.size(); iter++){
                    vec[iter].clear();
                }
                vec.clear();
            }
        }


        cin >> g;

        while (g--){
            int x,y;
            cin >>  x >> y;
            myobi[x][y] = 1;
        }
        
        cin >> e;
        while(e--){
            int x1,y1,x2,y2,cost;
            cin >> x1 >> y1 >> x2 >> y2 >> cost;

            node[x1][y1].push_back(vector<int>{x2,y2,cost});
            is_exist_teleport[x1][y1] =1;

        }

        for (int i=0; i<w; i++){
            for (int j=0; j<h; j++){
                if (i==w-1 && j==h-1) continue;
                if (is_exist_teleport[i][j]==1) continue;
                if (i!=0) {
                    node[i][j].push_back(vector<int>{i-1,j,1});
                }
                if (i!=w-1) {
                    node[i][j].push_back(vector<int>{i+1,j,1});
                }
                if (j!=0) {

                    node[i][j].push_back(vector<int>{i,j-1,1});
                }
                if (j!=h-1) {
                    node[i][j].push_back(vector<int>{i,j+1,1});
                }
            }
        }

        int x1,x2,y1,y2, cost;
        int never=0;
        for (int i=1; i<=w*h; i++){
            for (int x1=0; x1<w ; x1++){
                for (int y1=0; y1<h; y1++){
                    if (distance_matrix[x1][y1]==10000*w*h+1) continue;
                        vector<int> vec;
                    for (int idx=0; idx < node[x1][y1].size() ; idx++){
                        vec= node[x1][y1][idx];
                        x2 = vec[0];
                        y2 = vec[1];
                        cost = vec[2];
                        if (myobi[x2][y2]==1) continue;
                        if (distance_matrix[x2][y2] > distance_matrix[x1][y1]+ cost) {
                            distance_matrix[x2][y2] = distance_matrix[x1][y1]+cost;
                            if (i==w*h){
                                cout << "Never\n";
                                never= 1;
                                break;
                            }
                        }
                    }
                    if (never==1) break;
                }
                if (never==1) break;
            }
            if (never==1) break;
        }
        if (never==1) continue;
        if (distance_matrix[w-1][h-1] == 10000*w*h+1){
            cout << "Impossible" << "\n";
        }
        else{
            cout <<distance_matrix[w-1][h-1] <<"\n";
        }


        // for (int j=h-1; j>=0 ; j--){
        //     for (int i=0; i<w ;i++){
        //         cout << distance_matrix[i][j];
        //     }
        //     cout <<" " << "\n";
        // }

    }
    return 0;
}
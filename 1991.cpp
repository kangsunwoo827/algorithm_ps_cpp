#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<char,char> nodes[26]; 

void preorder(char root){
    if (root=='.'){
        return;
    }
    cout << root;
    preorder(nodes[root-65].first);
    preorder(nodes[root-65].second);
}
void inorder(char root){
    if (root=='.'){
        return;
    }
    inorder(nodes[root-65].first);
    cout << root;
    inorder(nodes[root-65].second);
}
void postorder(char root){
    if (root=='.'){
        return;
    }
    postorder(nodes[root-65].first);
    postorder(nodes[root-65].second);
    cout << root;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n;
    for (int i=0 ; i< n ; i++){
        char parent,left_child, right_child;
        cin >> parent >> left_child>>right_child;
        nodes[parent-65].first = left_child;
        nodes[parent-65].second = right_child;
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    return 0;
}
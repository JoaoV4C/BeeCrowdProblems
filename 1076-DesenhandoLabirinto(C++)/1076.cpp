// Joao Victor Alves Cerqueira - 02/06/2022
#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

void DFS(vector<set<int>> &adj_list, int V, int N){
    vector<bool> visited(V, false);
    stack<int> stack;
    int value, counter = 0;
    stack.push(N);
    while(!stack.empty()){
        value = stack.top();
        visited[value] = true;
        stack.pop();
        for(auto adj: adj_list[value]){
            if(!visited[adj]){
                counter += 2;
                stack.push(adj);
            }
        }
    }
    cout << counter << endl;
}

void createGraph(vector<set<int>> &adj_list, int E, int V){
    adj_list.resize(V);
    for(int i = 0; i < E; i++){
        int n1, n2;
        cin >> n1 >> n2;
        adj_list[n1].insert(n2);
        adj_list[n2].insert(n1);
    }
}

int main(){
    int V, E, N, tests;
    cin >> tests;
    for(int i = 0; i < tests; i++){
        vector<set<int>> adj_list;
        cin >> N;
        cin >> V >> E;
        createGraph(adj_list, E, V);
        DFS(adj_list, V, N);
    }
    return 0;
}
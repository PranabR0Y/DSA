//Remove loops and parallel edges
#include<bits/stdc++.h>
using namespace std;
map<int, vector<pair<int, int>>> graph; // source -> {dest, weight}
map<int, vector<pair<int, int>>> MST;   // source -> {dest, weight}
int main()
{
    graph[0].push_back({1, 4});
    graph[1].push_back({0, 4});
    
    graph[1].push_back({2, 8});
    graph[2].push_back({1, 8});
    
    graph[0].push_back({7, 8});
    graph[7].push_back({0, 8});
    
    graph[1].push_back({7, 11});
    graph[7].push_back({1, 11});
    
    graph[7].push_back({8, 7});
    graph[8].push_back({7, 7});
    
    graph[7].push_back({6, 1});
    graph[6].push_back({7, 1});
    
    graph[2].push_back({8, 2});
    graph[8].push_back({2, 2});
    
    graph[2].push_back({5, 4});
    graph[5].push_back({2, 4});
    
    graph[2].push_back({3, 7});
    graph[3].push_back({2, 7});
    
    graph[8].push_back({6, 6});
    graph[6].push_back({8, 6});
    
    graph[6].push_back({5, 2});
    graph[5].push_back({6, 2});
    
    graph[3].push_back({5, 14});
    graph[5].push_back({3, 14});
    
    graph[4].push_back({4, 1}); // loop (optional removal)
    
    graph[3].push_back({4, 9});
    graph[4].push_back({3, 9});
    
    graph[5].push_back({4, 10});
    graph[4].push_back({5, 10});



    for (auto& i : graph) {
        int source = i.first;
        auto& neighbors = i.second;
        int j = 0;
        while (j < neighbors.size()) {
            if (neighbors[j].first == source) { // loop edge
                neighbors.erase(neighbors.begin() + j); // don't increment j
            } else {
                ++j;
            }
        }
    }
    
    
    for(auto i:graph)
    {
        cout << i.first << " ->";
        for(pair<int,int>j:i.second)
        {
            cout << "( " << j.first << " " << j.second << " )";
        }
        cout << endl;
    }
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> minHeap;//weights->(source,dest)
    vector<bool>visited(100,false);

    visited[0]=true;
    for(auto& edge:graph[0]){
        minHeap.push({edge.second,{0,edge.first}});
    }

    while(!minHeap.empty()){

        pair<int,pair<int,int>>Top=minHeap.top();
        minHeap.pop();
        int weight = Top.first;
        int src = Top.second.first,dst = Top.second.second;
        if(!visited[dst]){
            MST[src].push_back({dst,weight});
            visited[dst]=1;
            for(auto& edge:graph[dst]){
                minHeap.push({edge.second,{dst,edge.first}});
            }

        }




    }
    cout << "MST " << endl;
    for(auto i:MST)
    {
        cout << i.first << " ->";
        for(pair<int,int>j:i.second)
        {
            cout << "( " << j.first << " " << j.second << " )";
        }
        cout << endl;
    }


   
    return 0;
}
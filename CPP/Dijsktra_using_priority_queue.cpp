vector<int> dijsktra(int source , vector<pair<int,int>> gr[] , int n){
        vector<int> dist(n+1,INT_MAX);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        dist[source] = 0;
        pq.push({0,source});


        while(!pq.empty()){
            auto [weighttillnow,node] = pq.top();
            pq.pop();
            if(dist[node] < weighttillnow) continue;
            for(auto nbrs : gr[node]){
                auto [nbrnode,weight] = nbrs;

                if(weighttillnow+weight < dist[nbrnode]){
                    dist[nbrnode] = weighttillnow+weight;
                    pq.push({dist[nbrnode],nbrnode});
                }
            }
        }
        return dist;
    }


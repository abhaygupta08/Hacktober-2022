    vector<int> dijsktra(int source , vector<pair<int,int>> gr[] , int n){
        vector<int> dist(n+1,INT_MAX);

        set<pair<int,int>> s;
        // weight , node
        dist[source] = 0;
        s.insert({0,source}); // adding source
        while(!s.empty()){
            auto it = s.begin();
            int node = (*it).second;
            int weighttillnow = (*it).first;
            s.erase(it);

            for(auto nbrs : gr[node]){
                int nbrnode = nbrs.first;
                int weight = nbrs.second;
                if(weighttillnow+weight < dist[nbrnode]){
                    auto find = s.find({dist[nbrnode],nbrnode});
                    if(find!=s.end()) s.erase(find);

                    dist[nbrnode] = weighttillnow+weight;
                    s.insert({dist[nbrnode],nbrnode});
                }
            }
        }
        return dist;
    }


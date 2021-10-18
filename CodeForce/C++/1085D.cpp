# include <iostream>
# include <unordered_set>
# include <unordered_map>

using namespace std;

/* Undirected Sparse Graph */
class USG {
private:
    int v, e;
    unordered_map<int, unordered_set<int>> graph;

    bool is_endpoint(int v){
        return graph[v].size() == 1;
    }

public:
    USG(): v(0), e(0) {}
    int V(){ return v; }
    int E(){ return e; }

    void add_edge(int from, int to){
        if (graph.find(from) == graph.end()){
            graph[from] = unordered_set<int>();
            ++v;
        }
        if (graph.find(to) == graph.end()){
            graph[to] = unordered_set<int>();
            ++v;
        }
        graph[from].insert(to);
        graph[to].insert(from);
        ++e;
    }

    int interval_points(){
        int ret = v;
        for (auto & cur : graph)
            if (is_endpoint(cur.first))
                --ret;
        return ret;
    }
};

int main(void){
    USG graph;
    int pt;
    double s;
    cin >> pt >> s;
    for (int i = 0; i < pt - 1; ++i){
        int a, b;
        cin >> a >> b;
        graph.add_edge(a, b);
    }
    cout << (s / (double) (graph.V() - graph.interval_points())) * 2.;
}
# include <iostream>
# include <vector>
# include <unordered_set>
# include <unordered_map>

using namespace std;

/* Undirected Sparse Graph */
class USG {
private:
    int v, e;
    unordered_map<int, unordered_set<int>> graph;
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

    bool is_endpoint(int v){
        return graph[v].size() == 1;
    }

    int interval_points(){
        int ret = graph.size();
        for (auto & cur : graph)
            if (is_endpoint(cur.first))
                --ret;
        return ret;
    }

    /* 將所有橋接邊刪除，以合併節點，非 endpoint 者都可壓縮 */
    void relax(){
        for (auto & cur : graph){
            // cout << "Cur : " << cur.first << endl;
            /* 可能要 relax */
            if (!is_endpoint(cur.first)){
                for (auto it = cur.second.begin(); it != cur.second.end();){
                    /* 是否需要 relax */
                    if (!is_endpoint(*it)){
                        cout << "delete " << *it << endl;
                        /* Relaxing */
                        for (auto _c : graph[*it]){
                            if (_c != cur.first){
                                cur.second.insert(_c);
                                graph[_c].insert(cur.first);
                                graph[_c].erase(*it);
                            }
                        }
                        graph.erase(*it);
                        --v;
                        --e;
                        it = cur.second.erase(it);
                        // cout << "After deletion\n";
                        // show();
                    }
                    else 
                        ++it;
                }
            }
        }
    }

    void show(){
        cout << "--------------------\n";
        cout << v << " vertices and " << e << " edges\n"; 
        for (auto & cur : graph){
            cout << cur.first;
            for (auto & n : cur.second)
                cout << " --> " << n;
            cout << endl;
        }
        cout << "--------------------\n";
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
    // cout << graph.V() << endl;
    // cout << graph.interval_points() << endl;
    // cout << graph.V() - graph.interval_points() << endl;
    // cout << (s / (double) (graph.V() - graph.interval_points())) * 2. << endl;
    printf("%f", (s / (double) (graph.V() - graph.interval_points())) * 2.);
    
    
    
    // graph.add_edge(1, 2);
    // graph.add_edge(1, 3);
    // graph.add_edge(1, 4);
    // graph.add_edge(2, 1);
    // graph.add_edge(2, 3);
    // graph.add_edge(2, 5);
    // graph.add_edge(5, 4);
    // graph.add_edge(5, 6);
    // graph.add_edge(6, 7);
    // graph.show();
    // cout << "Intervals : " << graph.interval_points() << endl;
    // graph.relax();
    // graph.show();
    // cout << "Intervals : " << graph.interval_points() << endl;
}
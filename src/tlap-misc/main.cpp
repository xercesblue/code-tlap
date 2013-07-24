#include <iostream>
#include <vector>
#include <set>

#include <tlap-lib.h>

// Francisco De La Cruz
// dlcs.frank@gmail.com
// July 5, 2013

// See cpp/src/tlap-lib/tlap-lib.(h|cpp) for up to date code.

void insertion_sort(int n[], const int N_SIZE) {
    if (N_SIZE < 1) return;
    int start = 0;
    for (int i = start + 1; i < N_SIZE; ++i) { // forward
        for (int j = i; j > start && n[j - 1] > n[j] ; --j) { // backward
            // Swap
            int tmp = n[j];
            n[j] = n[j - 1];
            n[j - 1] = tmp;
        }
    }
}
// 4 5 5 -1 1 2
// l r.
//   l r
//      l r
// 4 5 -1 5 1 2
//   l  r
// 4 -1 5 5 1 2
// l  r
// -1 4 5 5 1 2
//        l r
// -1 4 5 1 5 2
//      l r
// -1 4 1 5 5 2
//    l r
// -1 1 4 5 5 2
//          l r
// -1 1 4 5 2 5
//        l r
// -1 1 4 2 5 5
//      l r
// -1 1 2 4 5 5

void insertion_sort_fixed(int n[], const int N_SIZE, int fixed) {
    if (N_SIZE < 1) return;
    int start = 0;
    for (int i = start + 1; i < N_SIZE; ++i) {
        int right = i;
        if (n[right] != fixed) {
            for (int left = right - 1; left >= start && (n[left] > n[right] || n[left] == fixed); --left) {
                if (n[left] != fixed) {
                    // swap
                    int tmp = n[left];
                    n[left] = n[right];
                    n[right] = tmp;
                    right = left;
                }
            }
        }
    }
}

template<typename T>

class UGraph {

public:

    UGraph() : hasCycle_(false) {  }
    UGraph(int vCount) : hasCycle_(false) { }


    typedef std::array<bool, 10> VertexVisited;
    typedef std::array<std::set<int>, 10> VertexAdj;


    void addEdgeU(T src, T dst) {
        addEdgeD(src, dst);
        addEdgeD(dst, src);
    }

    // TODO: Cache this
    bool hasCycle() {

        visited_.fill(false);
        dfs(1, -1);
        return hasCycle_;
    }

private:

    void dfs(int u, int w);
    void addEdgeD(const T src, const T dst) {
        if (src < 0) return;
        std::set<int>& vlist = vertices_[src];
        vlist.insert(dst);
    }

private:
    VertexAdj vertices_;
    VertexVisited visited_;
    bool hasCycle_;

};

template<typename T>
void UGraph<T>::dfs(int u, int w) {
    visited_[u] = true;
    std::set<int>& vlist = vertices_[u];
    for(std::set<int>::iterator adj = vlist.begin(); adj != vlist.end(); ++adj) {
        if (!visited_[*adj])
            dfs(*adj, u);
        else if (w != *adj) { hasCycle_ = true; }
    }

}

int main(int argc, char* argv[]) {
    const int N_SIZE = 6;
    int n[N_SIZE] = { 2, 5, 5, -1, 1, 2 };
    tlap::print_arr(n, N_SIZE);
    insertion_sort_fixed(n, N_SIZE, 2);
    tlap::print_arr(n, N_SIZE);

    UGraph<int> ug(10);
    ug.addEdgeU(1, 2);
    ug.addEdgeU(1, 3);
    ug.addEdgeU(2, 3);
    if (ug.hasCycle()) { std::cout << "Found Cycle" << std::endl; }
    else { std::cout << "No cycle Found!" << std::endl; }

	return 0;
}

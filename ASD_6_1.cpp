#include <iostream>
#include <vector>

void DFS(int wierzcholek, std::vector<int> graf[], bool odwiedzone[], std::vector<int> &skladowa) {
    odwiedzone[wierzcholek] = true;
    skladowa.push_back(wierzcholek);

    for(int sasiad : graf[wierzcholek]) {
        if(!odwiedzone[sasiad]) {
            DFS(sasiad, graf, odwiedzone, skladowa);
        }
    }
}

void sortuj(std::vector<int> &skladowa) {
    for(size_t i = 0; i < skladowa.size(); i++) {
        for(size_t j = i + 1; j < skladowa.size(); j++) {
            if(skladowa[i] > skladowa[j]) {
                std::swap(skladowa[i], skladowa[j]);
            }
        }
    }
}

void Test() {
    int liczbaKrawedzi;
    std::cin >> liczbaKrawedzi;

    std::vector<int> graf[101];
    bool odwiedzone[101] = {false};
    int maxWierzcholek = 0;

    for(int i = 0; i < liczbaKrawedzi; i++) {
        int u, v;
        std::cin >> u >> v;
        graf[u].push_back(v);
        graf[v].push_back(u);
        maxWierzcholek = std::max(maxWierzcholek, std::max(u, v));
    }

    int numerSkladowej = 0;

    for(int i = 1; i <= maxWierzcholek; i++) {
        if(!odwiedzone[i]) {
            std::vector<int> skladowa;
            DFS(i, graf, odwiedzone, skladowa);
            numerSkladowej++;

            sortuj(skladowa);

            std::cout << numerSkladowej << ": ";
            for(int wierzcholek : skladowa) {
                std::cout << wierzcholek << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    int liczbaTestow;
    std::cin >> liczbaTestow;

    while(liczbaTestow--) {
        Test();

        if (liczbaTestow > 0) {
            std::cout << std::endl;
        }
    }

    return 0;
}

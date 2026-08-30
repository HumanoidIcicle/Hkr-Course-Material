#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

void show(auto it) {
    for (auto& item : it) {
        std::cout << item <<", ";
    }
    std::cout << std::endl;
}

int accumulation(std::vector<int> v) {
    return std::accumulate(v.begin(), v.end(), 0);
}

int main() {
    std::vector<int> v;
    v.push_back(20);
    v.push_back(5);
    v.push_back(1);
    v.push_back(29);
    v.push_back(5);
    v.push_back(25);

    show(v);

    std::cout << "\n========Reversed======" <<std::endl;
    reverse(v.begin(), v.end());
    sort(v.rbegin(), v.rend());
    show(v);

    std::cout << "\n=======Sorted=======" <<std::endl;
    std::sort(v.begin(), v.end(), std::greater<>());
    show(v);

    std::cout << "\n=======Accumulation=======" <<std::endl;
    std::cout << "Sum: " << accumulation(v);

    std::cout << "\n=======Other=======" <<std::endl;
    std::cout << v.back() <<std::endl;
    std::cout << v.front() <<std::endl;
    std::cout << v.at(3) <<std::endl;
    std::cout << v.capacity() <<std::endl;
    std::cout << v.size() <<std::endl; //return size of v
    std::cout << v.empty() <<std::endl;

    v.emplace(v.begin()+3, 4) ;//insert 4 at position 3
    v.pop_back(); //remove last item


    show(v);


    return 0;
}

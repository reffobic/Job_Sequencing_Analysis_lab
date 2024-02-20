#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct job {
    char id;
    int deadline;
    int profit;
};


int main() {

    job jobs[] = {
            {'a', 2, 20},
            {'b', 2, 15},
            {'c', 1, 21},
            {'d', 3, 8},
            {'e', 3, 2}
    };

    sort(begin(jobs), end(jobs), [](const job &a, const job &b){return a.profit>b.profit;});

    queue <char> j;

    for (int i = 0; i < 5; i++){
        for (int k = i; k < 5; k++){
            if (jobs[k].deadline == i+1){
                j.push(jobs[k].id);
                break;
            }
        }
    }

    while (!j.empty()){
        cout << j.front() << endl;
        j.pop();
    }

    return 0;
}

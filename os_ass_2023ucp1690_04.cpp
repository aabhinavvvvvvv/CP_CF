#include <bits/stdc++.h>
using namespace std;

struct Request {
    int arrival, size, duration;
};

struct Block {
    int start, size;
    bool free;
    int end_time; 
};

class MemoryAllocator {
    int totalMemory;
    vector<Block> blocks;   
    int nextFitIndex = 0;   
    int currentTime = 0;

    int requestCount = 0, successCount = 0;
    int internalFrag = 0, externalFrag = 0;

public:
    MemoryAllocator(int mem) : totalMemory(mem) {
        blocks.push_back({0, mem, true, -1}); 
    }

    void mergeFreeBlocks() {
        vector<Block> merged;
        for (auto &b : blocks) {
            if (!merged.empty() && merged.back().free && b.free) {
                merged.back().size += b.size;
            } else merged.push_back(b);
        }
        blocks.swap(merged);
    }

    void freeExpired() {
        for (auto &b : blocks) {
            if (!b.free && b.end_time == currentTime) {
                b.free = true;
                b.end_time = -1;
            }
        }
        mergeFreeBlocks();
    }

    pair<int,int> fragmentationStats() {
        int freeSum = 0, maxFree = 0;
        for (auto &b : blocks) {
            if (b.free) {
                freeSum += b.size;
                maxFree = max(maxFree, b.size);
            }
        }
        return {freeSum, maxFree};
    }
    bool allocate(Request req, string policy) {
        int idx = -1;

        if (policy == "FirstFit") {
            for (int i = 0; i < blocks.size(); i++) {
                if (blocks[i].free && blocks[i].size >= req.size) { idx = i; break; }
            }
        } else if (policy == "BestFit") {
            int best = INT_MAX;
            for (int i = 0; i < blocks.size(); i++) {
                if (blocks[i].free && blocks[i].size >= req.size && blocks[i].size < best) {
                    best = blocks[i].size;
                    idx = i;
                }
            }
        } else if (policy == "WorstFit") {
            int worst = -1;
            for (int i = 0; i < blocks.size(); i++) {
                if (blocks[i].free && blocks[i].size >= req.size && blocks[i].size > worst) {
                    worst = blocks[i].size;
                    idx = i;
                }
            }
        } else if (policy == "NextFit") {
            int n = blocks.size();
            for (int k = 0; k < n; k++) {
                int i = (nextFitIndex + k) % n;
                if (blocks[i].free && blocks[i].size >= req.size) {
                    idx = i;
                    nextFitIndex = (i+1)%n;
                    break;
                }
            }
        }

        if (idx == -1) return false;

        Block &b = blocks[idx];
        int leftover = b.size - req.size;

        b.free = false;
        b.size = req.size;
        b.end_time = currentTime + req.duration;

        if (leftover > 0) {
            blocks.insert(blocks.begin()+idx+1, {b.start + req.size, leftover, true, -1});
        }

        internalFrag += leftover;
        successCount++;
        return true;
    }
    void run(vector<Request> &requests, string policy) {
        queue<Request> waiting;
        int i = 0, n = requests.size();

        while (i < n || !waiting.empty() || !allFree()) {
            freeExpired();
            while (i < n && requests[i].arrival == currentTime) {
                waiting.push(requests[i]);
                i++;
            }

            if (!waiting.empty()) {
                Request r = waiting.front();
                if (allocate(r, policy)) waiting.pop();
            }

            requestCount++;
            if (requestCount % 10 == 0) printStats();

            currentTime++;
        }

        if (requestCount % 10 != 0) printStats();
    }

    bool allFree() {
        for (auto &b : blocks) if (!b.free) return false;
        return true;
    }
    void printStats() {
        auto [freeSum, maxFree] = fragmentationStats();

        double successRate = (100.0 * successCount) / requestCount;
        double intFragPct = (100.0 * internalFrag) / totalMemory;
        double extFragPct = (100.0 * (freeSum - maxFree)) / totalMemory;

        cout << "After " << requestCount << " requests:\n";
        cout << "  Success rate: " << successRate << "%\n";
        cout << "  Internal frag: " << intFragPct << "%\n";
        cout << "  External frag: " << extFragPct << "%\n\n";
    }
};

int main() {
    ifstream in("alloc.dat");
    if (!in) {
        cerr << "Error: alloc.dat missing\n";
        return 1;
    }

    int totalMem;
    in >> totalMem;
    vector<Request> reqs;
    while (true) {
        int a,s,d;
        in >> a >> s >> d;
        if (a == -1) break;
        reqs.push_back({a,s,d});
    }

    MemoryAllocator sim(totalMem);
    sim.run(reqs, "FirstFit");   
}

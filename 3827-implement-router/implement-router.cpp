#include <bits/stdc++.h>
using namespace std;

class Router {
private:
    int MAX_SIZE;  
    unordered_map<string, vector<int>> packetStore;  
    unordered_map<int, vector<int>> destTimestamps; // destination -> sorted timestamps
    queue<string> que;  

    string makeKey(int source, int destination, int timestamp) {
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

public:
    Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);

        if (packetStore.find(key) != packetStore.end()) {
            return false;  // duplicate
        }

        if ((int)packetStore.size() >= MAX_SIZE) {
            forwardPacket();
        }

        packetStore[key] = {source, destination, timestamp};
        que.push(key);

        // insert in sorted order
        auto &vec = destTimestamps[destination];
        auto it = lower_bound(vec.begin(), vec.end(), timestamp);
        vec.insert(it, timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (packetStore.empty())
            return {};  

        string key = que.front(); 
        que.pop();

        vector<int> packet = packetStore[key];
        packetStore.erase(key);

        int dest = packet[1];
        int timestamp = packet[2];

        auto &vec = destTimestamps[dest];
        auto it = lower_bound(vec.begin(), vec.end(), timestamp);
        if (it != vec.end() && *it == timestamp) {
            vec.erase(it);
        }

        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimestamps.find(destination);
        if (it == destTimestamps.end() || it->second.empty())
            return 0;

        auto &vec = it->second;

        int i = lower_bound(vec.begin(), vec.end(), startTime) - vec.begin();
        int j = upper_bound(vec.begin(), vec.end(), endTime) - vec.begin();

        return j - i;
    }
};

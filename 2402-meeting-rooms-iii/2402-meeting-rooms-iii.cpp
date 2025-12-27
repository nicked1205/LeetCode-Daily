class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        priority_queue<int, vector<int>, greater<int>> freeRooms;

        vector<int> count(n, 0);

        for (int i = 0; i < n; i++) {
            freeRooms.push(i);
        }

        for (int i = 0; i < meetings.size(); i++) {
            long long start = meetings[i][0];
            long long end = meetings[i][1];
            long long duration = end - start;

            while (!pq.empty() && pq.top().first <= start) {
                freeRooms.push(pq.top().second);
                pq.pop();
            }

            int room;
            long long newEnd;

            if (!freeRooms.empty()) {
                room = freeRooms.top();
                freeRooms.pop();
                newEnd = end;
            } else {
                auto [t, r] = pq.top();
                pq.pop();
                room = r;
                newEnd = t + duration;
            }

            pq.push({newEnd, room});
            count[room]++;
        }

        int maxCnt = 0;
        int maxRoom = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > maxCnt) {
                maxCnt = count[i];
                maxRoom = i;
            }
        }

        return maxRoom;
    }
};

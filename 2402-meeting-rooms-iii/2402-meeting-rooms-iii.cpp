class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort meetings by their start time
        sort(meetings.begin(), meetings.end());

        // Min-heap for busy rooms: {endTime, roomIndex}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        // Min-heap for available rooms (by index)
        priority_queue<int, vector<int>, greater<>> available;
        for (int i = 0; i < n; ++i) available.push(i);

        vector<int> count(n); // Number of meetings per room

        for (const auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1];

            // Free up rooms whose meetings have ended
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                // Assign to available room
                int room = available.top(); available.pop();
                count[room]++;
                busy.push({end, room});
            } else {
                // No room available; wait for the earliest one
                auto [freeTime, room] = busy.top(); busy.pop();
                count[room]++;
                long long duration = end - start;
                busy.push({freeTime + duration, room});
            }
        }

        // Find room with max meetings (smallest index in case of tie)
        int maxRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (count[i] > count[maxRoom]) {
                maxRoom = i;
            }
        }

        return maxRoom;
    }
};

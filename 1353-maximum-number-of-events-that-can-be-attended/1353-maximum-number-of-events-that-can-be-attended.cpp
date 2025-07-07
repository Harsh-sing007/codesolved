class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by start day
        sort(events.begin(), events.end());

        // Min-heap to store end days
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int day = 1, eventIndex = 0, n = events.size(), count = 0;

        // Find the last day among all events
        int lastDay = 0;
        for (auto& e : events) {
            lastDay = max(lastDay, e[1]);
        }

        // Go through each day
        for (day = 1; day <= lastDay; ++day) {
            // Add events starting today
            while (eventIndex < n && events[eventIndex][0] == day) {
                minHeap.push(events[eventIndex][1]);
                eventIndex++;
            }

            // Remove events that already ended
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            // Attend one event
            if (!minHeap.empty()) {
                minHeap.pop();
                count++;
            }
        }

        return count;
    }
};

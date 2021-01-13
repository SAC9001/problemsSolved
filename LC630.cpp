class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int> pque;
        int cnt = 0;
        for(int i = 0; i < courses.size(); ++i) {
            if(cnt + courses[i][0] <= courses[i][1]) {
                cnt += courses[i][0];
                pque.push(courses[i][0]);
            }
            else {
                if(!pque.empty() && courses[i][0] < pque.top()) {
                    cnt = cnt + courses[i][0] - pque.top();
                    pque.pop();
                    pque.push(courses[i][0]);
                }
            }
        }

        return pque.size();
    }
};
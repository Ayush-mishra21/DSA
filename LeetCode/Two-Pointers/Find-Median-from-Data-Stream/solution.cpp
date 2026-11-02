class MedianFinder {
public:
    priority_queue<int> pqmax;
    priority_queue<int, vector<int>, greater<int>> pqmin;
    MedianFinder() {}

    void addNum(int num) {
        if (pqmax.empty() || num <= pqmax.top()) {
            pqmax.push(num);
        } else {
            pqmin.push(num);
        }
        if (abs((int)pqmax.size() - (int)pqmin.size()) > 1) {
            if (pqmax.size() > pqmin.size()) {
                pqmin.push(pqmax.top());
                pqmax.pop();
            } else {
                pqmax.push(pqmin.top());
                pqmin.pop();
            }
        }
    }

    double findMedian() {
        if (pqmax.size() == pqmin.size()) {
            return (pqmax.top() + pqmin.top()) / 2.0;
        } else {
            return pqmin.size() > pqmax.size() ? pqmin.top() : pqmax.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
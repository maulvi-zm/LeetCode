class MedianFinder {
private:
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        // Requirements:
        // 1. The top of the left must be < top of the right
        // 2. The left length must be equal to the right or at most + 1

        // If its empyt or odd then add to the left
        if (low.empty() && high.empty()){
            low.push(num);
            return;
        }

        // If one of them is empty, there is an impossible cond: left is empty and right is filled, because left will be filled first
        if (high.empty()){
            if (low.top() > num){
                high.push(low.top());
                low.pop();
                low.push(num);
            } else {
                high.push(num);
            }

            return;
        }

        // If neither of them is empty
        if (low.size() > high.size()){ // need to fill the right
            if (low.top() > num){
                high.push(low.top());
                low.pop();
                low.push(num);
            } else {
                high.push(num);
            }
        } else { // need to fill the left
            if (high.top() < num){
                low.push(high.top());
                high.pop();
                high.push(num);
            } else {
                low.push(num);
            }
        }
    }
    
    double findMedian() {
        if ((low.size() + high.size()) % 2 != 0){
            return low.top();
        }

        return  ((double) (low.top()) + (double) (high.top())) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
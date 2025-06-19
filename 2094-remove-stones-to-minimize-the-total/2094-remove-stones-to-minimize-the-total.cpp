class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        priority_queue<int>pq;
        int sum=0;
        for(int i=0;i<n;i++){
            pq.push(piles[i]);
            sum+=piles[i];
        }

        for(int i=0;i<k;i++){
            int max=pq.top();
            pq.pop();
            int remove=max/2;
            sum-=remove;
            max-=remove;
            pq.push(max);
        }
        return sum;
    }
};
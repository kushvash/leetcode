class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas=0, sumCost=0, n=gas.size();

        for(int i=0; i<n; i++){
            sumGas+=gas[i];
            sumCost+=cost[i];
        }

        if(sumGas<sumCost){
            return -1;
        }

        int total=0, start=0;

        for(int i=0; i<n; i++){
            total+=(gas[i]-cost[i]);

            if(total<0){
                total=0;
                start=i+1;
            }
        }

        return start;
    }
};
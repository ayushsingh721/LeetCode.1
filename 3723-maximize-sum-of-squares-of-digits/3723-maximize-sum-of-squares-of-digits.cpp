class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        if((num * 9) < sum) return "";

        int x = min(9, sum);

        string res(num, '0');

        int remSum = sum;

        for(int i = 0; i < num;)
        {
            if(remSum >= x)
            {
                remSum -= x;
                res[i] = x + '0';
                i++;
            }
            else
                x--;
        }

        return res;
    }
};
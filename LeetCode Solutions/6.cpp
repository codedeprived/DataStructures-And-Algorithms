
/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

*/
  class Solution {
    public:  
    
    string convert(string s, int numRows) {
        // vector to store each rows;
        vector<string> str(numRows);
        //if numRows == 1 we return s not change!
        if(numRows == 1)
        {
            return s;
        }
        // i variable to traverse in s
        int i = 0; 
        // n initialised to -1;

        int n = -1;
        bool flag = true;
        /*
            intuition : we can traverse the array and fill rows from top to botton when botton is reached we simple traverse upwards he we can use n variable to keep track of rows and flag to keep track of upward and downward direction we star filling rows from upwards when last rows is reached we set flag to flase then we move reverse from last towards first row and vice versa. 
        
        */
        while(i<s.size())
        {
            if(n<numRows && flag )
            {
                n++;
                str[n] += s[i];
                i++;
                if(n == numRows-1)
                {
                    flag = false;
                }
            }

            else
            {
                n--;
                str[n] += s[i];
                i++;
                if(n == 0)
                {
                    flag = true;
                }
            }
        }
        string ans; 
        for(int i = 0; i < str.size() ; i++)
        {
            ans+=str[i];
        }
        return ans;
    }
};
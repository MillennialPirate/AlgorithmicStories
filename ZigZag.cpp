class Solution {
public:
    string convert(string s, int numRows) {
        //OM GAN GANAPATHAYE NAMO NAMAH 
        //JAI SHRI RAM 
        //JAI BAJRANGBALI 
        //AMME NARAYANA, DEVI NARAYANA, LAKSHMI NARAYANA, BHADRE NARAYANA
        //if the number of rows is one then directly return the string
        if(numRows == 1)
            return s;
        int n = s.length();
        string arr[10000];//array of strings
        //row variable to keep track of the number of rows
        int row = 0;
        //direction variable to keep track of the direction 
        //'D' for down 
        //'U' for up
        char dir = 'D';
        //traverse the string character by character
        for(int i = 0; i < n; i++)
        {
            //store the characters in the particular indexes in the array arr
            arr[row].push_back(s[i]);
            //reached the bottom 
            if(row == numRows - 1)
            {
                //now start travelling upwards
                dir = 'U';
            }
            else if(row == 0)//reached the top
            {
                //start travelling down
                dir = 'D';
            }
            //if travelling down
            if(dir == 'D')
                row++;
            else if(dir == 'U')//if travelling up
                row--;
        }
        //store all of the strings in the array arr in the new string str
        string str;
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < arr[i].length(); j++)
            {
                str.push_back(arr[i][j]);
            }
        }
        return str;
    }
};

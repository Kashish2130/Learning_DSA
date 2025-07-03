//? Given an integer N , Print all binary strings of size N.
// A binary string is that string which contains only 0 and 1.

//* NOTE : this works exactly same as generate all permutations wiht some changes but the same logic goes here!

class Solution
{
public:
    void backtrack(vector<int> input, int num, vector<int> &path, vector<string> &result)
    {

        //! base case: if path is complete
        if (path.size() == num)
        {
            string s;
            for (int bit : path)
            {
                s += (bit + '0');
            }
            result.push_back(s);
            return;
        }

        //! recursive case: explore further
        // try all numbers
        for (int i = 0; i < input.size(); i++)
        {

            path.push_back(input[i]);

            // explore
            backtrack(input, num, path, result);

            // un-choose (backtrack)
            path.pop_back();
        }
    }

    vector<string> generateBinaryStrings(int num)
    {
        vector<int> input = {0, 1};
        vector<string> result;
        vector<int> path;

        backtrack(input, num, path, result);

        return result;
    };
}

// tc : o(n)
// sc : o(n)

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (asteroids[i] > 0)
            {
                st.push(asteroids[i]);
            }
            else
            {
                while (!st.empty() && st.top() > 0 &&
                       st.top() < abs(asteroids[i]))
                {
                    st.pop();
                }

                if (!st.empty() && st.top() == abs(asteroids[i]))
                {
                    st.pop(); // both explode
                    // This checks whether the incoming negative asteroid can
                    // safely be added to the stack — meaning it won’t collide
                    // with anything. or if the stack is empty
                }
                else if (st.empty() || st.top() < 0)
                {
                    st.push(asteroids[i]);
                }
            }
        }

        // Stack to vector in reverse order
        int m = st.size();
        vector<int> ans(m);
        for (int i = m - 1; i >= 0; i--)
        {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};


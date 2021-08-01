#include <bits/stdc++.h>

uisng namespace std;
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
public:
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> st;
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        st.emplace(nestedList.begin(), nestedList.end());
    }

    int next()
    {
        cout << st.top().first->getInteger();
        st.top().first++;
    }

    bool hasNext()
    {
        while (!st.empty())
        {
            auto &c = st.top();
            if(c.first==c.second)
            {
                st.pop();
                continue;
            }
            if(p.first->isInteger())
                return true;
            else
            {
                auto &lt=p.first->getList();
                st.emplace(lt.begin(),lt.end());
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
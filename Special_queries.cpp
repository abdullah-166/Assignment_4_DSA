#include <bits/stdc++.h>
using namespace std;
int main()
{
    int Q;
    cin >> Q;
    queue<string> t;
    while (Q--)
    {
        int c;
        cin >> c;
        if (c == 0)
        {
            string name;
            cin >> name;
            t.push(name);
        }
        else if (c == 1)
        {
            if (!t.empty())
            {
                cout << t.front() << endl;
                t.pop();
            }
            else
            {
                cout << "Invalid" << endl;
            }
        }
    }
    
    return 0;
}

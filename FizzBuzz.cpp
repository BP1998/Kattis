#include <iostream>

using namespace std;

int main()
{
    int x, y, n;
    cin >> x >> y >> n;
    bool fizz, buzz;
    
    for(int i = 1; i <= n; i++)
    {
        if(i%x == 0)
        {
            cout << "Fizz";
            fizz = true;
        }
        if(i%y == 0)
        {
            cout << "Buzz";
            buzz = true;
        }
        if(!fizz && !buzz)
        {
            cout << i;
        }
        fizz = false;
        buzz = false;
        cout << endl;
    }
    
    return 0;
}
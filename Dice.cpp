#include <iostream>

using namespace std;

int main()
{
    int G1, G2, G3, G4;
    int E1, E2, E3, E4;
    int highG, highE, lowG, lowE;
    int gunnar, emma;
    

    cin >> G1 >> G2 >> G3 >> G4;
    cin >> E1 >> E2 >> E3 >> E4;
    
    highG = G2 + G4;
    highE = E2 + E4;
    
    lowG = G1 + G3;
    lowE = E1 + E3;
    
    gunnar = highG + lowG;
    emma = highE + lowE;
    
    if(gunnar > emma)
    {
        cout << "Gunnar";
    }
    else if (gunnar < emma)
    {
        cout << "emma";
    }
    else
    {
        cout << "tie";
    }
    
    cout << endl;
    
    return 0;
}
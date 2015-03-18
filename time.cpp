#include "st.h"
#include <ctime>

using namespace std;

int main()
{
    //cout<<"root...."<<endl;
    init();
    //cout<<"built."<<endl;


    string strand;
    int strand_size;
    //char strand[strand_size] = {'a', 'b', 'c', 'a', 'b', 'd'};
    
    //const int strand_size = 7;
    //char strand[strand_size] = {'c', 'd', 'd', 'd', 'c', 'd', 'c'};
    
    
    std::clock_t    start;
    start = std::clock();
    //cout<<"Suffix Tree..."<<endl;
    while (getline(cin,strand))
    {
        strand_size = strand.size();

        for (int i = 0; i < strand_size; i++)
        {
            build(strand[i]);
        }
    }
    
    cout << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << endl; 
    return 0;
}

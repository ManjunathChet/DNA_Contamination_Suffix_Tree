#include "st.h"

using namespace std;

int main()
{
    cout<<"root...."<<endl;
    init();
    cout<<"built."<<endl;

    const int strand_size = 6;
    char strand[strand_size] = {'a', 'b', 'c', 'a', 'b', 'd'};
    
    //const int strand_size = 7;
    //char strand[strand_size] = {'c', 'd', 'd', 'd', 'c', 'd', 'c'};


    cout<<"Suffix Tree..."<<endl;
    for (int i = 0; i < strand_size; i++)
    {
        build(strand[i]);
    }
    cout<<"built."<<endl<<endl;
    cout<<"SUFFIX TREE DATA"<<endl<<endl;
    cout<<"complete string: "<<endl;
    for (int i = 0; i < strand_size; i++)
    {
        cout<<input[i];
    }

    cout<<endl<<endl;
    cout<<"suffix tree: "<<endl;
    for (int i = 1; i <= 20; i++)
    {
        cout<<"NODE #"<<i<<": "<<endl;
        if (suffix_tree[i].start == -5) {break;}
        suffix_tree[i].output();
    }

    return 0;
}

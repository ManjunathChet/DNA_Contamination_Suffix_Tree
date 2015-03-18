#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int a_node = 0;
int a_edge = 0;
int a_length = 0;

int root = 0;
int current_end = 0;
int position = -1;
int suffix_link = 0;
int remainder = 0;

int huge = 65000;
char input[65000];

struct node 
{
    public:
        int start;
        int end;
        int local_link;
        //node *parent;
        int children[256];    
    
        node()
        {
            start = -5;
            end = huge;
            local_link = 0;
            
            for (int i = 0; i < 256; i++)
            {
                children[i] = 0;
            }
        }

        int edge_length() 
        {
            return min(end, position + 1) - start;
        }

        void output()
        {
            char letters[5] = {'a', 'b', 'c', 'd', 'e'};

            cout<<"=========="<<endl;
            cout<<"NODE ["<<start<<", "<<edge_length()<<"]"<<endl;
            cout<<"Children Edges: "<<endl;
            for(int k = 0; k < 5; k++)
            {
                cout<<letters[k]<<": ";
                cout<<children[97 + k]<<endl;
            }
            cout<<endl;
            cout<<"Suffix link present: ";
            if (local_link != 0)
            {
                cout<<"YES."<<endl;
                cout<<local_link<<endl;
            }
            else {cout <<"NO."<<endl;}
            
            //cout<<"Parent: ["<< parent -> start<<endl;
            cout<<"EDGE LENGTH: "<<edge_length()<<endl;
            cout<<"EDGE: ";
            if (start == -1)
            {
                cout<<"root"<<endl;
            }
            else
            {
                for(int k = start; k < start + edge_length(); k++)
                {
                    cout<<input[k];
                }
            }
            cout<<endl<<"=========="<<endl;
            cout<<endl;
        }
};

node suffix_tree[99999];

int new_node(int s, int e = huge) 
{
    node n1;
    n1.start = s;
    n1.end = e;
    n1.local_link = 0;
    //n1.parent -> NULL;

    for (int i = 0; i < 256; i++)
    {
        n1.children[i] = 0;
    }

    current_end++;
    suffix_tree[current_end] = n1;

    return current_end;
}

//int new_node(int s) 
//{
//    node n1;
//    n1.start = s;
//    n1.end = -1;
//    n1.local_link = 0;
//
//    for (int i = 0; i < 256; i++)
//    {
//        n1.children[i] = '\0';
//    }
//
//    current_end++;
//    suffix_tree[current_end] = n1;
//
//    return current_end;
//}
//

void init()
{
    a_node = new_node(-1, -1);
    root = a_node;
}

char active_edge() 
{
    return input[a_edge];
}

bool traverse(int node) 
{

    if (a_length >= suffix_tree[node].edge_length()) 
    {
        a_edge = a_edge + suffix_tree[node].edge_length();
        a_length = a_length - suffix_tree[node].edge_length();
        a_node = node;

        return true;
    }

    return false;
}

void insert_suffix_link(int node) 
{
    if (suffix_link > 0) 
    {
        suffix_tree[suffix_link].local_link = node;
    }
    
    suffix_link = node;
}

void build(char c) 
{
    input[++position] = c;
    suffix_link = 0;
    remainder++;

    while(remainder > 0) 
    {
        if (a_length == 0)
        {
            a_edge = position;
        }

        if (suffix_tree[a_node].children[active_edge()] == 0) 
        {
            int leaf;

            leaf = new_node(position);
            //suffix_tree[leaf - 1].parent -> suffix_tree[a_node];
            suffix_tree[a_node].children[active_edge()] = leaf;
            insert_suffix_link(a_node);
        } 
        else 
        {
            int child = suffix_tree[a_node].children[active_edge()];
            
            if (traverse(child)) 
            {
                continue;
            }
            if (input[suffix_tree[child].start + a_length] == c) 
            {
                //cout<<"FOUND."<<endl;
                a_length++;
                insert_suffix_link(a_node);
                //cout<<"SLINK ADDED"<<endl;
                break;
            }
            
            int split = new_node(suffix_tree[child].start, suffix_tree[child].start + a_length);
            
            suffix_tree[a_node].children[active_edge()] = split;
            
            int leaf = new_node(position);
            //suffix_tree[leaf - 1].parent -> suffix_tree[a_node];
         
            suffix_tree[split].children[c] = leaf;
            suffix_tree[child].start = suffix_tree[child].start + a_length;
            suffix_tree[split].children[input[suffix_tree[child].start]] = child;
            insert_suffix_link(split);
        }

        remainder--;
        
        if (a_node == root && a_length > 0) 
        {
            a_length--;
            a_edge = position - remainder + 1;
        } 
        
        else
        {    
            if (a_node == suffix_tree[a_node].local_link > 0)
            {
                a_node = suffix_tree[a_node].local_link;
            } 
            else
            {
                a_node = root;
            }
        }
    }
}

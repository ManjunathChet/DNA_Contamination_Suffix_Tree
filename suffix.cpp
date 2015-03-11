#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct TreeNode 
{
    public:
        int start;
        int finish;
        TreeNode* parent;
        vector<TreeNode*> children;

        TreeNode(int s, int f)
        {
            start = s;
            finish = f;
            parent = NULL;
            vector<TreeNode* > children;
        }

};

void InsertNode(TreeNode *root, int s, int f)
{
    //EMPTY CASE
    if (root == NULL)
    {
        root = new TreeNode(s,f);
        return;
    }
    else
    {
        TreeNode *current = new TreeNode(s,f);
        root -> children.push_back(current);
        current -> parent = root;
    }
}

void OutputChildren(TreeNode *Node)
{
    cout << "FRONT:  " << Node -> children.front() <<endl;
    cout << "SIZE:  " << Node -> children.size() <<endl;
    for (int i = 0; i < Node -> children.size(); i++)
    {
        cout << "CHILD "<<i<<": "<<endl;
        cout <<"    START: "<< Node -> children.at(i) -> start <<endl;
        cout << "   FINISH: " <<Node -> children.at(i) -> finish <<endl <<endl;
    }
}
int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(0,0);
    InsertNode(root, 5, 6);
    InsertNode(root, 10, 20);
    InsertNode(root, 1, 2);
    OutputChildren(root);

    return 0;
}



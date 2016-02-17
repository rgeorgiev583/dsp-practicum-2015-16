#include<iostream>
#include<random>
#include<list>
#include<vector>
using namespace std;

struct TreeNode
{
    int data;
    vector<TreeNode*> naslednici;

    TreeNode(int data0, vector<TreeNode*> naslednici0)
    {
        data = data0;
        naslednici = naslednici0;
    }
};

void deleteTreeNode(TreeNode*& root)
{
    if(root == NULL)
        return;
    for(TreeNode* tn : root->naslednici)
        deleteTreeNode(tn);
    cout<<"triene na "<<root->data<<endl;
    delete root;
    root = NULL;
}

bool member(TreeNode* root, int x)
{
    if(root == NULL)
        return false;
    if(root->data == x)
        return true;
    for(TreeNode* tn : root->naslednici)
        if(member(tn, x))
            return true;
    return false;
}

void filterOdd (TreeNode*& root)
{
    if(root == NULL)
        return;
    for(TreeNode* tn : root->naslednici)
        filterOdd(tn);
    if(root->data % 2 == 1)
    {
        //cout<<"triene na "<<root->data<<endl;
        deleteTreeNode(root);
    }
}

list<int> createList(int n)
{
    list<int> l = list<int>();
    for(int i = 0; i < n; i++)
        l.push_back(1 + rand() % 10000);
    return l;
}

void countingSort(list<int>& l)
{
    int max = 10000, min = 1;
    vector<int> a = vector<int>(max - min + 1);
    for(int i : l)
        a[i - 1]++;
    l = list<int>();
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < a[i]; j++)
        {
            l.push_back(i + 1);
        }
    }
}

list<int> merge(list<int> l1, list<int> l2)
{
    list<int> l = list<int>();
    while(l1.size() > 0 && l2.size() > 0)
        if(l1.front() < l2.front())
        {
            l.push_back(l1.front());
            l1.pop_front();
        }
        else
        {
            l.push_back(l2.front());
            l2.pop_front();
        }
    while(l1.size() > 0)
    {
        l.push_back(l1.front());
        l1.pop_front();
    }
    while(l2.size() > 0)
    {
        l.push_back(l2.front());
        l2.pop_front();
    }
    return l;
}

void razdelianeISlivane(list<int>& l)
{
    int max = 10000, min = 1;
    list<int> l1 = list<int>(), l2 = list<int>();
    vector<int> a = vector<int>(max - min + 1);
    for(int i : l)
        a[i - 1]++;
    l = list<int>();
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < a[i]; j++)
        {
            l1.push_back(i + 1);
            swap(l1, l2);
        }
    }
    l = merge(l1, l2);
}

int main()
{

    list<int> l = createList(100);
    //countingSort(l);
    razdelianeISlivane(l);
    for(int i : l)
        cout<<i<<" ";
    cout<<"--------------------------------------------------"<<endl;

    TreeNode* t1 = new TreeNode(1, vector<TreeNode*>());
    TreeNode* t2 = new TreeNode(2, vector<TreeNode*>());
    TreeNode* t3 = new TreeNode(3, vector<TreeNode*>());
    TreeNode* t4 = new TreeNode(4, vector<TreeNode*>());
    TreeNode* t5 = new TreeNode(5, vector<TreeNode*>());
    TreeNode* t6 = new TreeNode(6, vector<TreeNode*>());
    TreeNode* t7 = new TreeNode(7, vector<TreeNode*>());

    vector<TreeNode*> v1 = vector<TreeNode*>();
    v1.push_back(t1);

    vector<TreeNode*> v2 = vector<TreeNode*>();
    v2.push_back(t2);
    v2.push_back(t5);

    vector<TreeNode*> v3 = vector<TreeNode*>();
    v3.push_back(t3);
    v3.push_back(t4);
    v3.push_back(t6);
    v3.push_back(t7);

    TreeNode* t8 = new TreeNode(8, v1);
    TreeNode* t9 = new TreeNode(9, v2);
    TreeNode* t10 = new TreeNode(10, v3);

    vector<TreeNode*> v4 = vector<TreeNode*>();
    v4.push_back(t8);
    v4.push_back(t9);
    v4.push_back(t10);

    TreeNode* t12 = new TreeNode(12, v4);

    cout<<member(t12, 7)<<endl;
    filterOdd(t10);
    cout<<member(t12, 7)<<endl;
    return 0;
}

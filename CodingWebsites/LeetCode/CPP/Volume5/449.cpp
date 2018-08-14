#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
#include <map>
#include <set>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "*";
        //val(lchild,rchild)
        string ret = to_string(root->val);
        return ret + "(" + serialize(root->left) + "," + serialize(root->right) + ")";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int end;
        TreeNode *ret = D(data,0,end,data.length());
        if(end == data.length()){
            return ret;
        }
        else{
            printf("ERROR in deserialization, end = %d should be %lu\n",end,data.length());
            return NULL;
        }
    }
    //Tree = val(Tree,Tree) or *
    TreeNode * D(string &data, int start, int &end, int Len){
        //check out of range
        if(start >= Len) {
            end = Len;
            return NULL;
        }
        //check for empty tree
        if(data[start] == '*'){
            end = start + 1;
            return NULL;
        }
        
        //[start,end) is a tree
        //calculate and return end
        //val(lchild,rchild)
        auto LP = data.find('(',start);
        if(LP == string::npos || LP == start) {end = Len; return NULL;}
        //val range = [L,LP)
        int val = stoi(data.substr(start,LP - start),NULL,10);
        //printf("val = %d, LP = %lu\n",val,LP);
        int Lend,Rend;
        //LeftRange = [LP+1,Lend)
        TreeNode *LeftChild = D(data,LP+1,Lend,Len);
        if(data[Lend] != ','){
            printf("ERROR!\n");
            end = Len;
            return NULL;
        }
        //RightRange = [Lend+1,Rend)
        TreeNode *RightChild = D(data,Lend+1,Rend,Len);
        if(data[Rend] != ')'){
            printf("ERROR!\n");
            end = Len;
            return NULL;
        }
        
        end = Rend + 1;
        
        TreeNode *root = new TreeNode(val);
        root->left = LeftChild;
        root->right = RightChild;
        return root;
    }
    void DeleteTree(TreeNode *t){
        if(!t) return;
        DeleteTree(t->left);
        DeleteTree(t->right);
        delete t;
    }
    void Test(){
        string data = "5(*,4(*,*))";
        TreeNode *t = deserialize(data);
        string data2 = serialize(t);
        cout<<data2<<endl;
        DeleteTree(t);
    }
};

int main(){
    Codec S;
    S.Test();
	return 0;
}

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(unordered_map<Node*,Node*>& mp, Node* root){
       if(!root) return nullptr;
       if(mp.find(root)==mp.end()){
            Node* clone_root = new Node(root->val);
            mp[root] = clone_root;
            for(auto it: root->neighbors){
                clone_root->neighbors.push_back(dfs(mp,it));
            }
            return clone_root;
       }else{
            return mp[root];
       }
    
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> mp;
        Node* newNode = new Node();
        newNode = nullptr;
        return dfs(mp, node);

    }
};
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
    Node* recur(Node* node, unordered_map<Node*,Node*>&visited){
        Node* new_root = new Node(node->val);
        visited[node] = new_root;
        for(auto n:node->neighbors){
            if(!visited[n])
                new_root->neighbors.push_back(recur(n, visited));
            else
                new_root->neighbors.push_back(visited[n]);
        }
        return new_root;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> visited;
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0)
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return recur(node, visited);
    }
};
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
    unordered_set<Node*> visited;
    void dfs(unordered_map<Node*, Node*>& oldtonew,
             unordered_map<Node*, vector<Node*>>& mp, Node* node) {
        if (node == nullptr || visited.count(node)) {
            return;
        }
        visited.insert(node);
        if (oldtonew.find(node) == oldtonew.end()) {
            oldtonew[node] = new Node(node->val);
        }
        for (Node* temp : node->neighbors) {
            dfs(oldtonew, mp, temp);
        }
        mp[node] = node->neighbors;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, vector<Node*>> mp;
        unordered_map<Node*, Node*> oldtonew;
        dfs(oldtonew, mp, node);
        Node* head = oldtonew[node];
        for (auto neighbors_ : mp) {
            Node* par = neighbors_.first;
            vector<Node*> neighborss = neighbors_.second;
            vector<Node*> new_neighbors_arr;
            for (Node* temp : neighborss) {
                new_neighbors_arr.push_back(oldtonew[temp]);
            }
            oldtonew[par]->neighbors = new_neighbors_arr;
        }
        return head;
    }
};
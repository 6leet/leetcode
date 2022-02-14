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
    vector<bool> visited;
    vector<Node*> clone_nodes;
    queue<Node*> q;
    Node* cloneGraph(Node* node) {
        visited.resize(105);
        clone_nodes.resize(105);
        for (int i = 0; i < clone_nodes.size(); i++) {
            visited[i] = false;
            clone_nodes[i] = (Node*) NULL;
        }
        if (node != NULL) {
            bfs(node);
        }
        return clone_nodes[1];
    }
    void bfs(Node* node) {
        q.push(node);
        clone_nodes[1] = new Node(1);
        visited[1] = true;
        while (!q.empty()) {
            Node* n = q.front();
            q.pop();
            for (int i = 0; i < n->neighbors.size(); i++) {
                int neigh = n->neighbors[i]->val;
                if (clone_nodes[neigh]) {
                    clone_nodes[n->val]->neighbors.push_back(clone_nodes[neigh]);
                } else {
                    clone_nodes[neigh] = new Node(neigh);
                    clone_nodes[n->val]->neighbors.push_back(clone_nodes[neigh]);
                }
                if (!visited[neigh]) {
                    q.push(n->neighbors[i]);
                    visited[neigh] = true;
                }
            }
        }
    }
};

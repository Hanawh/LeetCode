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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
			return NULL;
        map<Node*, Node*> m;
        queue<Node*> q;
        q.push(node);

        Node* clone = new Node(node->val);
        m[node] = clone;

        while(!q.empty()){
            Node* tmp = q.front();
            q.pop();
            for(Node* t : tmp->neighbors){
                if(!m.count(t)){
                    m[t] = new Node(t->val);
                    q.push(t);
                }
                m[tmp]->neighbors.push_back(m[t]);
            }
        }
        return clone;
    }
};

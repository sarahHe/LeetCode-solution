// Clone an undirected graph. Each node in the graph 
// contains a label and a list of its neighbors.
//important! Deep copy
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)  return NULL;
        
        UndirectedGraphNode *res = new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> table;
        table[node] = res;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        
        while (!q.empty()) {
            UndirectedGraphNode *cur = q.front();
            q.pop();
            
            for (int i = 0; i < (int)cur->neighbors.size(); i++) {
                if (!table[cur->neighbors[i]]) {
                    table[cur->neighbors[i]] = new UndirectedGraphNode(cur->neighbors[i]->label);
                    q.push(cur->neighbors[i]);
                }
                table[cur]->neighbors.push_back(table[cur->neighbors[i]]);
            }
        }
        return res;
    }
};


2015.4.26 update time reduce from 160ms to 77ms
class Solution {
public:
    UndirectedGraphNode *dfs(unordered_map<int, UndirectedGraphNode*> &myMap, UndirectedGraphNode *node) {
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        myMap[newNode->label] = newNode;
        
        for (auto i : node->neighbors) {
            if (myMap[i->label])
                (newNode->neighbors).push_back(myMap[i->label]);
            else
                (newNode->neighbors).push_back(dfs(myMap, i));
        }
        return newNode;
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)  return NULL;
        
        unordered_map<int, UndirectedGraphNode*> myMap;
        return dfs(myMap, node);
    }
};

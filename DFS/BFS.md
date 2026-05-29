# Binary Tree Level Order Traversal
URL:https://leetcode.com/problems/binary-tree-level-order-traversal/

## Approach

This solution uses **Breadth-First Search (BFS)** with a queue to traverse the binary tree level by level.

### Steps

1. If the root is `nullptr`, return an empty result.
2. Push the root node into a queue.
3. While the queue is not empty:
   - Store the current queue size (`levelSize`), which represents the number of nodes in the current level.
   - Create a temporary vector `currentLevel`.
   - Process exactly `levelSize` nodes:
     - Remove a node from the front of the queue.
     - Add its value to `currentLevel`.
     - Push its left child into the queue if it exists.
     - Push its right child into the queue if it exists.
   - Add `currentLevel` to the final result.
4. Return the result.

## Example

Input Tree:

```text
        1
       / \
      2   3
     / \ / \
    4  5 6  7
```

Output:

```text
[[1], [2,3], [4,5,6,7]]
```

## Dry Run

<h2>Detailed Dry Run</h2>

<table>
  <tr>
    <th width="8%">Step</th>
    <th width="28%">Action</th>
    <th width="18%">Current Level</th>
    <th width="23%">Result</th>
    <th width="23%">Queue</th>
  </tr>

  <tr>
    <td>0</td>
    <td>Push root (1)</td>
    <td>—</td>
    <td>[]</td>
    <td>[1]</td>
  </tr>

  <tr>
    <td>1</td>
    <td>Poll 1, push children</td>
    <td>[1]</td>
    <td>[]</td>
    <td>[2,3]</td>
  </tr>

  <tr>
    <td>2</td>
    <td>Store level</td>
    <td>[1]</td>
    <td>[[1]]</td>
    <td>[2,3]</td>
  </tr>

  <tr>
    <td>3</td>
    <td>Poll 2, push children</td>
    <td>[2]</td>
    <td>[[1]]</td>
    <td>[3,4,5]</td>
  </tr>

  <tr>
    <td>4</td>
    <td>Poll 3, push children</td>
    <td>[2,3]</td>
    <td>[[1]]</td>
    <td>[4,5,6,7]</td>
  </tr>

  <tr>
    <td>5</td>
    <td>Store level</td>
    <td>[2,3]</td>
    <td>[[1],[2,3]]</td>
    <td>[4,5,6,7]</td>
  </tr>

  <tr>
    <td>6</td>
    <td>Poll 4,5,6,7</td>
    <td>[4,5,6,7]</td>
    <td>[[1],[2,3]]</td>
    <td>[]</td>
  </tr>

  <tr>
    <td>7</td>
    <td>Store level</td>
    <td>[4,5,6,7]</td>
    <td>[[1],[2,3],[4,5,6,7]]</td>
    <td>[]</td>
  </tr>

  <tr>
    <td>8</td>
    <td>Queue empty → Return result</td>
    <td>—</td>
    <td>[[1],[2,3],[4,5,6,7]]</td>
    <td>—</td>
  </tr>
</table>

Queue becomes empty, so the traversal is complete.

## Complexity Analysis

### Time Complexity
- Each node is visited exactly once.
- **O(N)**

### Space Complexity
- The queue may contain up to one full level of the tree.
- **O(N)** in the worst case.

## C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = q.front();
                q.pop();

                currentLevel.push_back(currentNode->val);

                if (currentNode->left != nullptr) {
                    q.push(currentNode->left);
                }

                if (currentNode->right != nullptr) {
                    q.push(currentNode->right);
                }
            }

            result.push_back(currentLevel);
        }

        return result;
    }
};
```

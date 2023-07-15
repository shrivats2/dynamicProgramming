void leftboundary(node* root, vector<int>& v) 
{
  node* cur = root->left;
  while (cur) {
    if (cur->left || cur->right)
      v.push_back(cur->data);
    if (cur->left)
      cur = cur->left;
    else
      cur = cur->right;
  }
}

void rightboundary(node* root, vector<int>& v)
{
  node* cur = root->right;
  vector<int> temp;
  while (cur) {
    if (cur->left || cur->right)
      temp.push_back(cur->data);
    if (cur->right)
      cur = cur->right;
    else
      cur = cur->left;
  }
  for (int i = temp.size() - 1; i >= 0; --i) {
    v.push_back(temp[i]);
  }
}

void leaves(node* root, vector<int>& v) 
{
  if (!root)
    return;
  if (!root->left && !root->right)
    v.push_back(root->data);
  leaves(root->left, v);
  leaves(root->right, v);
}

vector<int> printBoundary(node* root)
{
  vector<int> v;
  if (!root)
    return v;

  if (root->left || root->right)
    v.push_back(root->data);

  leftboundary(root, v);

  // Add leaf nodes
  leaves(root, v);

  rightboundary(root, v);
  return v;
}

bool RoottoNode(node * root, vector < int > & ans, int x)
{

  if (!root)
    return false;
  ans.push_back(root -> data);

  if (root -> data == x)
    return true;
    
  if (RoottoNode(root -> left, ans, x) ||RoottoNode(root -> right, ans, x))
    return true;

  ans.pop_back();

  return false;
}

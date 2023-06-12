int find(int parent[],int root)
{
    if(root == parent[root]) return root;
    return parent[root] = find(parent , parent[root]);
       //add code here
}
void unionSet(int parent[],int X,int Y)
{
    X = find(parent , X);
    Y = find(parent , Y);
    if(X == Y) return;
    else parent[X] = Y;
	//add code here.
}

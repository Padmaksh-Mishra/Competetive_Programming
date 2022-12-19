# include <bits/stdc++.h>

using namespace std;
 
struct Node {
    int data;
    Node* left;
    Node* right;
}*root = NULL;

bool insertionWarning; //checks if we have tried to insert a duplicate element

// Function to create a new node
Node* CreateNode(int data)
{
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
// Function to insert element in BST
void InsertNode(int key)
{	
	Node *t = root;
	Node *r = NULL,*p;
	// If the tree is empty, assign new node address to root
	if(root==NULL){
		p = CreateNode(key);
		root = p;
		return;
	}
	while(t!=NULL){
		r=t;
		if(key==t->data)
		{
			insertionWarning = true;
			return;
		}
		else if(key<t->data)
		{
			t=t->left;
		}
		else
		{
			t=t->right;
		}
	}
	p = CreateNode(key);
	if(key<r->data)
	{
		r->left = p;
	}
	else
	{
		r->right = p;
	}
	return;
}
 

// Preorder traversal of a binary tree 
 
void preOrder(Node* temp)
{
    if (temp == NULL)
        return;
    cout << temp->data << '-'; 
    preOrder(temp->left);
    preOrder(temp->right);
}
// find height of the tree
int Height(Node *node)
{
	int x,y;
	Node *p = node;
	if(p==NULL)
	{
		return 0;
	}
	x = Height(p->left);
	y = Height(p->right);
	return max(x,y)+1;
}
// finding immediate predessor 
Node* imPre(Node* node){
	Node *p = node;
	while(p && p->right)
	{
		p = p->right;
	}
	return p;
} 
// finding immediate successor
Node* imSuc(Node* node){
	Node *p = node;
	while(p && p->left)
	{
		p = p->left;
	}
	return p;
}
// delete the requested node form binary tree
Node *Delete(Node *p,int key)
{
	Node *q;
	if(p==NULL)
	{
		return NULL;
	}
	if(p->left==NULL&&p->right==NULL)
	{
		if(p==root)
		{
			root = NULL;
		}
		free(p);
		return NULL;
	}

	if(key<p->data)
	{
		p->left = Delete(p->left,key);
	}
	else if (key>p->data)
	{
		p->right = Delete(p->right,key);
	}
	else
	{
		if (Height(p->left)>Height(p->right))
		{
			q = imPre(p->left);
			p->data = q->data;
			p->left = Delete(p->left,q->data);
			
		}
		else
		{
			q = imSuc(p->right);
			p->data = q->data;
			p->right = Delete(p->right,q->data);
		}
	}
	return p;
}

Node *Search(int key)
{	
	Node *t = root;
	while(t!=NULL)
	{
		if(key==t->data)
		{
			return t;
		}
		else if (key<(t->data))
		{
			t = t->left;
		}
		else
		{
			t = t->right;
		}
	}
	return t;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> A(n),B(k);
    for(int i=0;i<n;++i)
    {
    	cin >> A[i];
    }
 	for(int i=0;i<k;++i)
 	{
 		cin >> B[i];
 	}
 	//Inserting elements in BST
 	for(auto val : A)
 	{
 		InsertNode(val);
 	}
 	cout << "Insertion-warning: ";
 	if(insertionWarning)
 	{
		cout << "Cannot enter duplicate elements in a BST" << endl;			 
 	}
 	else
 	{
 		cout << "None" << endl;
 	}
 	cout << "Pre-order: ";
 	preOrder(root);
 	cout << endl;
 	for(auto val : B)
 	{
 		Node *p = Search(val);
 		cout << "Pre-order after deleting " << val << ": ";
 		if(p==NULL)
 		{
 			cout << "There is no element with key " << val << " in the BST" << endl;
 		}
 		else
 		{
 			Delete(p,val);
 			preOrder(root);
 			cout << endl;
 		}
 	}
    return 0;
}

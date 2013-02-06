#include <iostream>

using namespace std;

class searchTree;
class treeElement{
public:
       treeElement(const int &in):val(in),left(NULL),right(NULL),parent(NULL){}
       bool operator>(const treeElement &rhs) const
       {
		return val > rhs.val;
       }
private:
       friend std::ostream& operator<<(std::ostream &out, const treeElement &in);
       friend class searchTree;
       int val;
       treeElement *left;
       treeElement *right;
       treeElement *parent;
};


class searchTree
{
public:
	searchTree(void):root(NULL){}
	int insert(const int &val)
	{
		treeElement *key = new treeElement(val);			//create new element
		treeElement *p, *n;
		if(root == NULL){
			root = key;
			return 0;
		}
		p = NULL;
		n = root;
		while(n){							//find the pos
			p = n;
			if(*key > *n)
				n = n->right;
			else
				n = n->left;	
		}
		
		if(*key > *p)							//link it into tree
				p->right = key;
			else
				p->left  = key;
		key->parent = p;
	}
	treeElement *maxNum(void)
	{
		return max(root);
	}
	treeElement *minNum(void)
	{
		return min(root);
	}
	int print(std::ostream &out)
	{
		treeElement *index = root;
		output(out, index);
		return 0;
	}
	treeElement * prev(treeElement *key){
			if(key == NULL)
				return NULL;
			if(key->left != NULL)
					return max(key);
			while(key->parent != NULL && key->parent->left == key){
					key = key->parent;
			}
			if(key->parent != NULL)
					return key->parent;
			else
					return NULL;	

	}
	treeElement * next(treeElement *key){
			if(key == NULL)
				return NULL;
			if(key->right != NULL)
					return min(key);
			while(key->parent != NULL && key->parent->right == key){
					key = key->parent;
			}
			if(key->parent != NULL)
					return key->parent;
			else
					return NULL;	
	}

	int del(const int &val)
	{
			treeElement *key = search(val);
			if(key == NULL)
				return -1;
			// With no child
			if(key->left == NULL && key->right == NULL){		
					if(key->parent == NULL)	
						root = NULL;
					else{
						if(key->parent->left == key)
							key->parent->left = NULL;
						else
							key->parent->right = NULL;
					}		
				delete key;
				return 0;	
			}
			//With only left child
			if(key->left && !(key->right)){  //left child
				key->left->parent = key->parent;
				if(key->parent == NULL){
					root = key->left;
				}else if(key->parent->left == key){
					key->parent->left = key->left;
				}else{
					key->parent->right = key->left;
				}				
				delete key;
				return 1;								
			}
			//with only right child
			if(key->right && !(key->left)){  //left child
				key->right->parent = key->parent;
				if(key->parent == NULL){
					root = key->right;
				}else if(key->parent->left == key){
					key->parent->left = key->right;
				}else{
					key->parent->right = key->right;
				}				
				delete key;
				return 2;								
			}
			//with two child
			if(key->right && key->left){
				treeElement *ptr = next(key);	
				int tmp = ptr->val;	
				del(tmp);
				key->val = tmp;
				return 3; 
			}
			return -1;
	}

	treeElement * search(const int &val)
	{	
		treeElement *key = root;
		while(key && key->val != val){
			if(val < key->val)
					key = key->left;
			else
					key = key->right;

		}
		return key;
	}
private:

	treeElement* max(treeElement *key)
	{		
			treeElement *n = key;
			while(n != NULL && n->right != NULL){
				n = n->right;
			}
		return n;
	}
	treeElement* min(treeElement *key)
	{		
			treeElement *n = key;
			while(n != NULL && n->left != NULL){
				n = n->left;
			}
		return n;
	}
	int output(std::ostream &out, treeElement *p)
	{
		if(p){
			output(out, p->left);
			out << *p << " ";
			output(out, p->right);
		}
	 	return 0;	
	}
	
	treeElement *root;
};

inline std::ostream& operator<<(std::ostream &out, const treeElement &in)
{
	out << in.val;
	return out;
}




int main()
{
	searchTree a;
	a.insert(21);	
	a.insert(10);
	a.insert(9);
	a.insert(42);
	a.insert(19);
	a.insert(20);
	a.print(cout);
	std::cout << std::endl;
	std::cout << "max: "  <<*(a.maxNum()) << std::endl;
	std::cout << "min: "  <<*(a.minNum()) << std::endl;
	std::cout << "prev: " <<*a.prev(a.search(20)) << std::endl;
	std::cout << "next: " <<*a.next(a.search(20)) << std::endl;
	a.del(10);
	cout << "afer del 10:";
	a.print(cout);
	cout << endl;
return 0;
}


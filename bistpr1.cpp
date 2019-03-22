
#include<iostream>
using namespace std;
class node{
public:
int data;
node*left;
node*right;
node*parent;
	node(int value){
	data=value;
	left=NULL;
	right=NULL;
	parent=NULL;
	}
};
class bist{
public:
node*root;
int count;
	bist(){
	root=NULL;
	count=0;		
	}
	void insert(int value){
		if(root==NULL){
			root=new node(value);
		}
		else{
			inserthelper(root,value);		
		}
	}
	void inserthelper(node*current,int value){
		if(current->data >= value){
			if(current->left == NULL){
				current->left = new node(value);
				current->left->parent= current;
				count++;
			}		
	          	else{
				inserthelper(current->left,value);			
			}
		}
		else{
			if(current->right == NULL){
				current->right = new node(value);
				current->right->parent= current;
				count++;
			}		
	          	else{
				inserthelper(current->right,value);			
			}
		}
	}
	void display(){
		displayhelper(root);
		cout<<"NULL"<<endl;	
	}
	void displayhelper(node*current){
		if(current==NULL) return ;
		else{
			displayhelper(current->left);
			cout<<current->data;
			cout<<"->";
			displayhelper(current->right);		
		}
	}
	node*search(int value){
		return searchhelper(root,value);		
	}
	node*searchhelper(node*current,int value){
		if(current==NULL or current->data==value){
			return current;
		}
		else{
			if(current->data >= value) return searchhelper(current->left,value);
			else return searchhelper(current->right,value);		
		}	
	}
	void print2d(){
		print2dhelper(root,0);	
	}
	void print2dhelper(node*current,int space){
		if(current==NULL) return;
		else{
			print2dhelper(current->right,space+1);
			cout<<current->data<<endl;
			for(int i=0;i< space;i++){
				cout<<"  ";		
			}
			print2dhelper(current->left,space+1);		
		}
	}
	int Count(){
		return count;	
	}
	int height(){
		int a=0;
		heighthelper(root,0,a);
		return a;
	}
	void heighthelper(node*current,int i,int &p){
		if(current == NULL){
			if(p<i-1) p=i-1;
			else return;		
		}
		else{
			heighthelper(current->left,i+1,p);
			heighthelper(current->right,i+1,p);		
		}
	}
	node*find_min(node*current){
		if(current==NULL or current->left==NULL) return current;
		else find_min(current->left);
	}
	node*find_max(node*current){
		if(current==NULL or current->right==NULL) return current;
		else find_max(current->right);
	}
	void replace_at_parent(node*a,node*b){
	 	if(a->left==b) a->parent->left= b;
		else a->parent->right= b;	
	}
	void pop(int a, int b){
		replace_at_parent(search(a),search(b));
	}

};

int main(){
bist b;
    b.insert(4);
    b.insert(2);
    b.insert(3);
    b.insert(1);
    b.insert(6);
    b.insert(5);
    b.insert(7);
    b.insert(8);
b.display();
if(b.search(3) != NULL) cout<<"3 is in the tree"<<endl;
else cout<<"it is not in the tree"<<endl;
b.print2d();
cout<<"The nos of elements in the tree is :-"<<b.Count()<<endl;
cout<<"the height of the tree is :- "<<b.height()<<endl;
cout<<"the minimum element of the tree is :- "<<b.find_min(b.root)->data<<endl;
cout<<"the maximum element of the tree is :- "<<b.find_max(b.root)->data<<endl;
b.pop(7,8);

return 0;
}











typedef struct _tree{
	void* data;
	struct _tree *left;
	struct _tree *right;
} TreeNode;

void insertNode(TreeNode** root,COMPARE compare,void* data){
	TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	if(*root == NULL){
		*root = node;
		return;
	}

	while(1){
		if(compare((*root)->data,data) > 0){
			if((*root)->left != NULL){
				*root = (*root)->left;
			}else{
				(*root)->left = node;
				break;
			}
		}else{
			if((*root)->right != NULL){
				*root = (*root)->right;
			}else{
				(*root)->right = node;
				break;
			}		
		}
	
	}
}

void inOrder(TreeNode* root,DISPLAY display){
	if(root != NULL){
		inOrder(root->left,display);
		display(root->data);
		inOrder(root->right,display);

	}
}

void postOrder(TreeNode* root,DISPLAY display){
	if(root != NULL){
		postOrder(root->left,display);
		postOrder(root->right,display);
		display(root->data);
	}
}

void preOrder(TreeNode* root,DISPLAY display){
	if(root != NULL){
		display(root->data);
		preOrder(root->left,display);
		preOrder(root->right,display);
	}
}

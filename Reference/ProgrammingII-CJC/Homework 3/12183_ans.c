#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef enum node_type {
	OP_AND, OP_OR, ID
} NodeType;


typedef struct _Node {
	NodeType type;
	// For variable nodes.
	int var_id;
	// The boolean value the node's expression evaluates to. Initialized as false.
	bool eval_value;
	struct _Node* parent_op;
	struct _Node* left_expr;
	struct _Node* right_expr;
} Node;

// Array of node pointers that point to variable nodes.
Node** var_node;

// Construct a syntax tree from a string of inputs.
void construct_syntax_tree(Node** root) {
	char input = getchar();
	switch (input) {
		case '\n':
			return;
		case '&':
		case '|': // Operators.
			(*root) = (Node*)calloc(1, sizeof(Node));
			if (input == '&') (*root)->type = OP_AND;
			else (*root)->type = OP_OR;
			construct_syntax_tree(&(*root)->left_expr);
			(*root)->left_expr->parent_op = (*root);
			construct_syntax_tree(&(*root)->right_expr);
			(*root)->right_expr->parent_op = (*root);
			(*root)->eval_value = false;
			break;
		case '[': // Read in an integer, the variable's id.
			(*root) = (Node*)calloc(1, sizeof(Node));
			(*root)->type = ID;
			scanf("%d", &(*root)->var_id);
			var_node[(*root)->var_id] = (*root);
			(*root)->left_expr = NULL;
			(*root)->right_expr = NULL;
			(*root)->eval_value = false;
			
			getchar(); // A right bracket is expected. Read and skip.
			break;
	}
}

// Keep negating the given node and traveling upwards until it is no longer necessary.
void negate_and_eval(Node* curNode) {
	if (curNode->eval_value) curNode->eval_value = false;
	else curNode->eval_value = true;
	if (curNode->parent_op == NULL) return;

	switch (curNode->parent_op->type) {
	case OP_AND:
		if (curNode->parent_op->eval_value ^ (curNode->parent_op->left_expr->eval_value & curNode->parent_op->right_expr->eval_value)) {
			return negate_and_eval(curNode->parent_op);
		}
		break;
	case OP_OR:
		if (curNode->parent_op->eval_value ^ (curNode->parent_op->left_expr->eval_value | curNode->parent_op->right_expr->eval_value)) {
			return negate_and_eval(curNode->parent_op);
		}
		break;
	}
}

void free_tree(Node* root) {
	if (root != NULL) {
		free_tree(root->left_expr);
		free_tree(root->right_expr);
		free(root);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int var_count, flip_count;
		scanf("%d %d\n", &var_count, &flip_count);
		var_node = (Node**)malloc((var_count + 1) * sizeof(Node*));
		Node* root = NULL;
		construct_syntax_tree(&root);
		root->parent_op = NULL;
		while (flip_count--) {
			int id;
			scanf("%d", &id);
			negate_and_eval(var_node[id]);
			printf("%d\n", root->eval_value);
		}
		free(var_node);
		free_tree(root);
	}

	return 0;
}

// By IntSys
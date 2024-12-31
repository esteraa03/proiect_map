/*Traversarea arborilor binari ordonați – Se dă un arbore binar ordonat care se 
populează cu elemente aleatorii. Să se afișeze elementele în urmă traversării 
arborelui în „pre-ordine”,  „in-ordine”, „post-ordine” și pe „nivel” (level-order 
traversal).*/

#include <iostream>
#include <fstream>

struct Node {
	int val;
	struct Node *left;
	struct Node* right;

	Node(int data):val(data), left(nullptr), right(nullptr){}
	
};

void pre_ordine(Node *root) {
	if (root == nullptr) return;

	std::cout << root->val << " ";
	pre_ordine(root->left);	
	pre_ordine(root->right);	
}

void in_ordine(Node *root) {
	if (root == nullptr) return;

	in_ordine(root->left);
	std::cout << root->val << " ";
	
	in_ordine(root->right);
}

void post_ordine(Node *root) {
	if (root == nullptr) return;

	post_ordine(root->left);
	post_ordine(root->right);
	std::cout << root->val<<" ";

}

void nivel(Node *root) {
	//coada

}

Node *add(Node *root, int value) {
	//daca nu am niciun nod, creez unul
	if (root == nullptr)
	{
		return new Node(value);
	}
	//daca valoarea de add este mai mare decat nodul, se adauga in dr
	if (value>root->val)
	{
		root->right = add(root->right, value);
	}
	//else in stanga
	else if (value < root->val)
	{
		root->left = add(root->left, value);
	}
	return root;
}

//functia pt pagina html

int main()
{
	Node *root = new Node(10); //radacina initializata cu 10
	add(root, 15);
	add(root, 12);
	add(root, 3);
	add(root, 9);
	add(root, 18);
	add(root, 2);
	
	std::cout << "PRE_ORDINE: \n";
	pre_ordine(root);
	std::cout << "\n========================";
	
	std::cout << "\nIN-ORDINE: \n";
	in_ordine(root);
	std::cout << "\n========================";

	std::cout << "\nPOST-ORDINE: \n";
	post_ordine(root);
	
	return 0;
}
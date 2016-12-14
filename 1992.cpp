#include <iostream>

using namespace std;
char **board;

typedef struct Tree {
	int x, y;
	int size;
	Tree *n1;
	Tree *n2;
	Tree *n3;
	Tree *n4;
	char chk;
} Node;
Node *newNode(int ax, int ay, int asize);
bool check(int x, int y, int size);
void Div(Node *P, int size);
void addTree(Node *P, int size);
void PreOrder(Node *T);

int main(void)
{
	int T; cin >> T; cin.clear(); cin.ignore();
	board = new char*[T];
	for (int i = 0; i < T; i++)
		board[i] = new char[T];

	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < T; j++)
			cin >> board[i][j];
	}

	Node *root = newNode(0, 0, T);
	Div(root, T);
	PreOrder(root);
	for (int i = 0; i < T; i++)
		delete[] board[i];
	delete board;
	return 0;
}

bool check(int x, int y, int size){
	char init = board[x][y];
	for (int i = x; i < x+size; i++)
	{
		for (int j = y; j < y+size; j++)
		{
			if (init != board[i][j])
				return false;
		}
	}
	return true;
}
Node *newNode(int ax, int ay, int asize) {
	Node *newT;
	newT = new Node;


	newT->size = asize;
	newT->x = ax;
	newT->y = ay;
	newT->n1 = NULL;
	newT->n2 = NULL;
	newT->n3 = NULL;
	newT->n4 = NULL;
	newT->chk = false;

	return newT;
}
void Div(Node *P, int size) {
	if (check(P->x, P->y, size) == false)
	{
		addTree(P, size / 2);
	}
	else
		return;

	
	if (P->n1 != NULL)
	{
		Div(P->n1, size / 2);
	}
	if (P->n2 != NULL)
		Div(P->n2, size / 2);
	if (P->n3 != NULL)
	{
		Div(P->n3, size / 2);
	}
	if (P->n4 != NULL)
		Div(P->n4, size / 2);
}
void addTree(Node *P, int size) {
	Node *ptr;
	Node *newT;
	ptr = P;

	if(ptr->n1 == NULL) {
		newT = newNode(P->x, P->y,size);
		ptr->n1 = newT;
	}

	if (ptr->n2 == NULL) {
		newT = newNode(P->x, P->y +size, size);
		ptr->n2 = newT;
	}

	if (ptr->n3 == NULL) {
		newT = newNode(P->x+size, P->y, size);
		ptr->n3 = newT;
	}

	if (ptr->n4 == NULL) {
		newT = newNode(P->x+size, P->y+size, size);
		ptr->n4 = newT;

	}
}

void PreOrder(Node *T) {
	if (T->n1) { cout << "("; PreOrder(T->n1); }
	if (T->n2) { PreOrder(T->n2); }
	if (T->n3) { PreOrder(T->n3); }
	if (T->n4) { PreOrder(T->n4); }
		
	if(T->n1 ==NULL)
	{
		cout << board[T->x][T->y];
		
	}
	if (T->n4 !=NULL)
		cout << ")";
}

#ifndef NULL
#define Null 0
#endif
typedef int eleType;
typedef struct Node{
	eleType ele;
	struct Node* next;
}Node, *pNode;
pNode Create();
pNode Reverse(pNode a);
pNode Reverse2(pNode a);
void Display(pNode a);
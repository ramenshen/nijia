﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ostream>
#include <iomanip>
#include <stack>
#include <map>
#include <fstream>
#define NOTLEAFNODE 0X7F
using namespace std;
char* hf_encode(char key);
struct HFNode {
	char c;
	int weight;
	int code;
	HFNode* lchild;
	HFNode* rchild;
	HFNode() {}
	HFNode(char t) {
		c = t;
	}
	bool operator()(const HFNode* a) {
		return this->c == a->c;
	}
	bool operator==(const HFNode& t) {
		return this->c == t.c;
	}
	friend ostream& operator<<(ostream& out, const HFNode* a) {
		out << setw(2) << a->c << setw(4) << a->weight << endl;
		return out;
	}
};
bool HFNode_cmp(const HFNode* a, const HFNode* b) {
	return a->weight > b->weight;
}
vector<HFNode*> v;
void readData() {
	freopen("data.in", "r", stdin);
	char t;
	while (cin.get(t)) {
		vector<HFNode*>::iterator result;
		HFNode* n=new HFNode;
		n->c = t;
		//result = find(v.begin(), v.end(), n);
		result = find_if(v.begin(), v.end(), HFNode(t));
		if (result == v.end()) {
			n->weight = 1;
			n->lchild = NULL;
			n->rchild = NULL;
			v.push_back(n);
		}
		else {
			(*result)->weight++;
		}
	}
	sort(v.begin(), v.end(), HFNode_cmp);
	copy(v.begin(), v.end(), ostream_iterator<HFNode*>(cout, " "));
	freopen("CON", "r", stdin);
}
map<char, string> encode_m;
map<string, char> decode_m;

void encodeData() {
	char t;
	ifstream fi("data.in");
	ofstream fo("data.out");
	//freopen("data.out", "w", stdout);
	while (fi.get(t)) {
		int max_size = encode_m.max_size();
		map<char, string>::iterator it = encode_m.find(t);
		if (it != encode_m.end()) {	
			cout << t << "has been encoded" << endl;
			fo << it->second;
		}
		else {
			cout << t << " is been encoded first time" << endl;
			fo << hf_encode(t);
		}
	}
	fi.close();
	fo.close();
}
void decodeData() {
	char t;
	ifstream fi("data.out");
	ofstream fo("data.out.decode");
	//freopen("data.out", "w", stdout);
	string s;
	//6s.resize(0);
	cout << decode_m["0"] << endl;
	cout << decode_m["10"] << endl;
	while (fi.get(t)) {
		s.append(1, t);
		cout <<"try to decode "<< s << endl;
		map<string, char>::iterator it = decode_m.find(s);
		if (it != decode_m.end()) {
			cout << s << " ------> "<< it->second << endl;
			fo << it->second;
			s.clear();
		}		
	}
	fi.close();
	fo.close();
}
HFNode* root = NULL;
void buildHFTree() {
	if (v.size() >= 2) {
		int size = v.size();
		HFNode* t1, * t2;
		t1 = v[size - 1];
		//t1->c = v[size - 1]->c;
		//t1->weight = v[size - 1]->weight;
		t1->code = 1;
		//t1->lchild = v[size - 1]->lchild;
		//t1->rchild = v[size - 1]->rchild;
		v.pop_back();
		size = v.size();
		t2 = v[size - 1];
		//t2->c = v[size - 1]->c;
		//t2->weight = v[size - 1]->weight;
		t2->code = 0;
		//t2->lchild = v[size - 1]->lchild;
		//t2->rchild = v[size - 1]->rchild;
		v.pop_back();
		HFNode* t3 = new HFNode;
		t3->c = NOTLEAFNODE;
		t3->code = 1;
		t3->weight = t1->weight + t2->weight;
		t3->lchild = t2;
		t3->rchild = t1;
		root = t3;
	}
	while (v.size()) {
		int size = v.size();
		HFNode* t1;
		t1 = v[size - 1];
		//t1->c = v[size - 1]->c;
		t1->code = 0;
		//t1->weight = v[size - 1]->weight;
		//t1->lchild = v[size - 1]->lchild;
		//t1->rchild = v[size - 1]->rchild;
		v.pop_back();
		HFNode* t3 = new HFNode;
		t3->c = NOTLEAFNODE;
		t3->code = 1;
		t3->weight = t1->weight + root->weight;
		t3->lchild = t1;
		t3->rchild = root;
		root = t3;
	}
}
void preorder(HFNode* t) {
	if (t) {
		cout << t;
		preorder(t->lchild);
		preorder(t->rchild);
	}
}
char encode[256] = { 0 };
char* hf_encode(char key) {
	if (root == NULL)
		return NULL;
	memset(encode, 0, sizeof(encode));
	HFNode* p = root;
	stack<HFNode*> s;
	map<HFNode*, HFNode*> parent;
	if (root)
		parent[root] = NULL;
	while (!s.empty() || p) {
		while (p) {
			s.push(p);
			if (p->lchild)
				parent[p->lchild] = p;
			p = p->lchild;
		}
		if (!s.empty()) {
			p = s.top();
			s.pop();
			//cout << p->c << " ";
			if (p->c == key) {
				//cout << "key:" << key<<" ";
				stack<int> code_stack;
				while (p != root) {
					code_stack.push(p->code);
					p = parent[p];
				}
				while (!code_stack.empty()) {
					//cout << code_stack.top() << " ";
					sprintf(encode, "%s%d", encode, code_stack.top());
					code_stack.pop();
				}
				//cout << endl;
				//cout << "encode " << key << endl;
				encode_m[key] = string(encode);
				//encode_m.insert( make_pair( key, string(encode) ) );
				decode_m[string(encode)] =key ;
				return encode;
				break;
			}
			if (p->rchild)
				parent[p->rchild] = p;
			p = p->rchild;
		}
	}
}
void printTopToBottomPath(HFNode* n, map<HFNode*, HFNode*>& p) {
	cout << n->c << ":";
	stack<int> tmp;
	while (n != root) {
		tmp.push(n->code);
		n = p[n];
	}
	while (tmp.size()) {
		cout << tmp.top() << " ";
		tmp.pop();
	}
	cout << endl;
}
void printRootToLeaf(HFNode* root)
{
	// Corner Case 
	if (root == NULL)
		return;

	// Create an empty stack and push root to it 
	stack<HFNode*> nodeStack;
	nodeStack.push(root);

	// Create a map to store parent pointers of binary 
	// tree nodes 
	map<HFNode*, HFNode*> parent;

	// parent of root is NULL 
	parent[root] = NULL;

	/* Pop all items one by one. Do following for
	   every popped item
		a) push its right child and set its parent
		   pointer
		b) push its left child and set its parent
		   pointer
	   Note that right child is pushed first so that
	   left is processed first */
	while (!nodeStack.empty())
	{
		// Pop the top item from stack 
		HFNode* current = nodeStack.top();
		nodeStack.pop();

		// If leaf node encountered, print Top To 
		// Bottom path 
		if (!(current->lchild) && !(current->rchild))
			printTopToBottomPath(current, parent);

		// Push right & left children of the popped node 
		// to stack. Also set their parent pointer in 
		// the map 
		if (current->rchild)
		{
			parent[current->rchild] = current;
			nodeStack.push(current->rchild);
		}
		if (current->lchild)
		{
			parent[current->lchild] = current;
			nodeStack.push(current->lchild);
		}
	}
}
int main()
{
	readData();
	buildHFTree();
	preorder(root);
	printRootToLeaf(root);
	encodeData();
	decodeData();
	//std::cout << "Hello World!\n";
}
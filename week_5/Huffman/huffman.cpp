#include <vector>
#include <iostream>
#include <string>
#include <queue>

using std::vector;
using std::endl;
using std::cout;
using std::string;
using std::priority_queue;

struct Node {
	Node *left;
	Node *right;
	int freq;
	char letter;
	Node() {
		left = nullptr;
		right = nullptr;
		freq = 0;
	}
	Node(int f, char l) {
		left = nullptr;
		right = nullptr;
		freq = f;
		letter = l;
	}
	Node(Node *l, Node *r, int f) {
		left = l;
		right = r;
		freq = f;
	}
	Node &operator=(const Node &n) {
		left = n.left;
		right = n.right;
		freq = n.freq;
		letter = n.letter;
	}
	Node(const Node &n) {
		left = n.left;
		right = n.right;
		freq = n.freq;
		letter = n.letter;
	}
};

class myComp {
	public:
		bool operator()(const Node &n1, const Node &n2) const { 
			return (n1.freq > n2.freq);
		}
};

void printCounts(vector<int> &counts) {
	cout << "[ ";
	for (auto itr = counts.begin(); itr != counts.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "] " << endl;
}

void printQueue(priority_queue<Node, vector<Node>, myComp> Nodes) {
	cout << "[ ";
	while (!Nodes.empty()) {
		Node t = Nodes.top();
		cout << "(" << t.freq << ", " << t.letter << " ";
		if (t.left == nullptr) cout << " l:N ";
		if (t.right == nullptr) cout << " r:N ";
		cout << ")";
		Nodes.pop();
	}
	cout << "] " << endl;
}

void printTree(Node const * const n) {
	if (n != nullptr) {
		cout << "(" << n->freq << ") ";
		if (n->left != nullptr) {
			printTree(n->left);
		}
		if (n-> right != nullptr) {
			printTree(n->right);
		}
	}
}

vector<int> getCounts(const string &message) {
	vector<int> counts(256,0);
	for (auto itr = message.begin(); itr != message.end(); ++itr) {
		++counts[*itr];	
	}
	return counts;
}

//class myComp
Node buildHuffTree(priority_queue<Node, vector<Node>, myComp> pq) {
	int sz = pq.size();
	for (int i = 1; i < sz; ++i) {
		Node l = pq.top();
		pq.pop();
		cout << "POPPED: " << l.freq << " " << l.letter << " ";
		if (l.left == nullptr) cout << " l:N ";
		if (l.right == nullptr) cout << " r:N ";
		cout << endl;
		Node r = pq.top();
		pq.pop();
		cout << "POPPED: " << r.freq << " " << r.letter << " ";
		if (r.left == nullptr) cout << " l:N ";
		if (r.right == nullptr) cout << " r:N ";
		cout << endl;
		Node z(&l, &r, l.freq + r.freq);
		pq.push(z);
		cout << "PUSHED: " << z.freq << " " << z.letter << " ";
		cout << "z.left: " << (*z.left).freq << "z.right: " << (*z.right).freq << " ";
		cout << endl;
	}
	printQueue(pq);
	printTree(&pq.top());
	return pq.top();
}

Node buildTree2() {
	Node n1(5, 'a');
	Node n2(3, 'b');
	Node tempTree(&n1, &n2, 8);
	printTree(&tempTree);
	return tempTree;
}

void huffman(const string &message, vector<bool> &encoding) {
	vector<int> counts = getCounts(message);
	priority_queue<Node, vector<Node>, myComp> pq;
	for (unsigned int l = 0; l < counts.size(); ++l) {
		int c = counts[l];
		if (c >= 1) {
			Node n(c, l);
			pq.push(n);
		}
	}
	printQueue(pq);
	Node tree = buildHuffTree(pq);
//	printTree(&tree);
//	cout << "ROOT: " << tree.freq << endl;
//	Node tempTree = buildTree2();
//	cout << endl;
	//Node n1(5, 'a');
	//Node n2(3, 'b');
	//Node tempTree(&n1, &n2, 8);
//	printTree(&tempTree);
}

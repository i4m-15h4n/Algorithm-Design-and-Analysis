#include <bits/stdc++.h>
using namespace std;

struct minHeapNode
{
	char data;
	unsigned freq;
	minHeapNode *left,*right;

	minHeapNode(char data,unsigned freq) {
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	
	}
};

struct compare{
	bool operator() (minHeapNode *l,minHeapNode *r) {
		return (l->freq > r->freq);
	}
};

void printCodes(struct minHeapNode* root,string str) {
	if(!root) return;
	if(root->data != '$')
		cout<< root->data << ": " << str << "\n";

		printCodes(root->left,str+"0");
		printCodes(root->right,str+"1");
}

void huffManCodes(char data[],int freq[],int size)
{
	struct minHeapNode *left,*right,*top;
	priority_queue<minHeapNode*,vector<minHeapNode*>,compare> minHeap;

	for(int i=0;i<size;++i) {
		minHeap.push(new minHeapNode(data[i],freq[i]));
	}

	while(minHeap.size()>1) {
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();

		top = new minHeapNode('$',left->freq + right->freq);

		top->left = left;
		top->right = right;

		minHeap.push(top);
	}
	printCodes(minHeap.top(),"");
}

int main(int argc, char const *argv[])
{
	char data[] = {'a','b','c','d','e','f'};
	int freq[] = {5,9,12,13,16,45};

	int size = sizeof(data)/sizeof(data[0]);
	huffManCodes(data,freq,size);
	return 0;
}

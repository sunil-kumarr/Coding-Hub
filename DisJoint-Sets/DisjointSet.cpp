#include <iostream>
using namespace std;
class DisjSet {
	int *rank, *parent, n;

public:
	// Constructor to create and
	// initialize sets of n items
	DisjSet(int n)
	{
		rank = new int[n];
		parent = new int[n];
		this->n = n;
		makeSet();
	}

	// Creates n single item sets
    // with equal rank
	void makeSet()
	{
		for (int i = 0; i < n; i++) {
			parent[i] = i;
            rank[i]=0;
		}
	}
    void rankPrint()
    {
        cout<<"Parent[]: ";
        for (int i = 0; i < n; i++) {
            cout<<parent[i]<<" ";
		}
        cout<<endl;
        cout<<"RankXY[]: ";
        for (int i = 0; i < n; i++) {
            cout<<rank[i]<<" ";
		}
        cout<<endl;
         cout<<"----------------\n";
    }

	int find(int x)
	{
        // When parent[x]==x means the node is representive
        //otherwise the node have a parent somewhere
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void Union(int x, int y)
	{
		// Find current sets of x and y
		int xset = find(x);
		int yset = find(y);
        cout<<"Nodes: "<<x<<" "<<y<<endl;
        cout<<"Parnt: "<<xset<<" "<<yset<<endl;
		// If they are already in same set
		if (xset == yset)
			return;

		// Put smaller ranked item under
		// bigger ranked item if ranks are
		// different
		if (rank[xset] < rank[yset]) {
			parent[xset] = yset;
		}
		else if (rank[xset] > rank[yset]) {
			parent[yset] = xset;
		}

		// If ranks are same, then increment
		// rank.
		else {
			parent[yset] = xset;
			rank[xset] = rank[xset] + 1;
		}
	}
    void isSameSet(int x,int y)
    {
        if(find(x)==find(y))cout<<"Same set\n";
        else cout<<"DisJoint Set\n";
    }
};

int main()
{
	DisjSet obj(5);
    obj.rankPrint();
	obj.Union(0, 2);
    obj.rankPrint();
	obj.Union(4, 2);
    obj.rankPrint();
	obj.Union(3, 1);
    obj.rankPrint();
    obj.Union(1,4);
    obj.rankPrint();
	obj.isSameSet(0,4);
    obj.isSameSet(2,3);
	return 0;
}

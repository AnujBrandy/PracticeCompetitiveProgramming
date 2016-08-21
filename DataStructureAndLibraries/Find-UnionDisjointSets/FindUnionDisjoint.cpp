#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define REP(i, a, b) for(int i=int(a); i<=int(b); i++)
#define vi vector<int>
#define si set<int>

vi parentSet;

void initSet(int _size){
	parentSet.resize(_size);
	REP(i, 0, _size - 1){
		parentSet[i] = i;
	}
}

int findSet(int i){
	//this algorithm returns the element that represents the set ..
	//also it does the path compression on the way .. please do check the figures for a clear understanding .. in the union-find disjoint set folder
	return parentSet[i] == i ? i : parentSet[i] = findSet(parentSet[i]);
}

void unionSet(int i, int j){
	//findset j gives the representative of the set that has the item j .. findset i does the same ..
	//now the representative of i's parent is representative of j ..
	//refer the figures for the more accuracte understanding of the algorithms ..
	parentSet[findSet(i)]=findSet(j);
}

bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}

int NumberOfSets(){
	si uniqueParent;
	REP(i, 0, parentSet.size() - 1){
		uniqueParent.insert(findSet(i));
	}
	return uniqueParent.size();
}

int sizeOfSet(int j){
	int counter = 0;
	REP(i, 0, parentSet.size() - 1){
		if (isSameSet(i, j)){
			counter++;
		}
	}
	return counter;
}
int main(void){
	initSet(6);
	unionSet(0, 1);
	unionSet(1, 2);
	unionSet(0, 4);
	printf("Total number of sets: %d\n", NumberOfSets());
	printf("Size of set containing {put your element here}: %d", sizeOfSet(5));
	int x;
	cin >> x;
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class DSU{
private:
	int n;
	vector<int> parent;
	vector<int> rank;


	bool isvalid(int u){
		if(u >=0 && u < this -> n) return true;
		return false;
	}

public:
	// constructor to initialize dsu
	DSU(int n){
		this -> n = n;
		this -> parent = vector<int> (n);
		this -> rank = vector<int> (n, 1);
		for(int i = 0; i < n; i++)
			this -> parent[i] = i;
	}

	// making a new set 
	void makeSet(){
		int id = this -> parent.size();
		this-> n++;
		this -> parent.push_back(id);
		rank.push_back(1);
	}

	int findParent(int u){
		if(!isvalid(u)) return -1;
		if(u == this -> parent[u]) return u;
		return this -> parent[u] = findParent(this -> parent[u]);
	}

	void Union(int u, int v){
		if(! (isvalid(u) && isvalid(v)) ){
			return;
		} 
		u = findParent(u);
		v = findParent(v);
		if(this -> rank[u] > this -> rank[v]){
			this -> parent[v] = u;
			this -> rank[u] += this -> rank[v];
		} 
		else if(this -> rank[v] > this -> rank[u]){
			this -> parent[u] = v;
			this -> rank[v] += this -> rank[u];
		}
		else{
			this -> parent[u] = v;
			this -> rank[v] += this -> rank[u];
		}
 	}

 	int sizeofset(int u){
 		if(!isvalid(u)) return -1;
 		return this -> rank[findParent(u)];
 	}

};



int main(){

	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE



	int n;
	cin >> n;
	DSU ds(n);

	int m; cin >> m;
	while(m--){
		int u, v;
		cin >> u >> v; 
		ds.Union(u, v);

	}
	
	ds.makeSet();
	ds.Union(6,4);
	cout << ds.findParent(6) << endl;
	cout << ds.sizeofset(6);


	return 0;
}
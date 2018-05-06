#include<bits/stdc++.h>
#include<vector>
#define nMAX 6000

using namespace std;

ifstream in_file;
vector<string> word;
vector<int> road;
int num , **Graph , Queue[nMAX] = {0} , solt = 0 , vitri[2] = {0,0} , truoc[nMAX];
bool flag[nMAX] = {false};

void input() {
	in_file.open("int.txt");
	string str;
	int i = 0;
	while(!in_file.eof()) {
		in_file >> str;
		word.push_back(str);
		i++;
	}
	num = i;
	in_file.close();
}

bool checkString(string s1 , string s2) {
	int dem = 0;
	for(int i = 0; i < 5; i++) {
		if(s1[i] != s2[i]) dem++;
	}
	if(dem == 1) return true;
	return false;
}

void allocMatrix(int ** &Graph , const int num ) {
	Graph = new int * [num];
	for(int i = 0; i < num; i++) {
		Graph[i] = new int[num];
	}
	if( *Graph == NULL) {
		cout<<"Not enough memory!"<<endl;
		exit(0);
	}
	for(int i = 0; i < num ; i++) {
		for(int j = 0;  j < num; j++) Graph[i][j] = 0;
	}
}

void freeMatrix(int ** &Graph ,const int num ) {
	for(int i = 0; i < num; i++) {
		delete[] Graph[i];
	}
	delete[] Graph;
}


void CreatGraph() {
	allocMatrix(Graph,num);
	for(int i = 0; i < num ; i++) {
		for(int j = 0; j < i ; j++) {
			if(checkString(word[i],word[j])) {
				Graph[i][j] = 1;
				Graph[j][i] = 1;
			}
		}
	}
}

// Breadth First Search 
void BFS(int i) {
	int u , dauQ, cuoiQ ;
	dauQ = 1;
	cuoiQ = 1;
	flag[i] = true;
	Queue[cuoiQ] = i;
	while( dauQ <= cuoiQ ) {
		u = Queue[dauQ];
		dauQ += 1;
		for(int j = 0; j < num ; j++) {
			if(Graph[u][j] == 1 && flag[j] == false) {
				cuoiQ += 1;
				Queue[cuoiQ] = j;
				flag[j] = true;
				truoc[j] = u;
			}
		}
	}	
}
void DFS(int i) {
	int u;
	flag[i] = solt;
	for(int u = 0; u < num; u++) {
		if(Graph[i][u] == 1 && flag[u] == 0) {
			DFS(u);
		}
	}
}

int lienThong() {
	for(int i = 0; i < num; i++) flag[i] = false;
	for(int i = 0; i < num ; i++) {
		if(flag[i] == false) {
			solt++;
			BFS(i);
			//DFS[i];
		}
	}
	return solt;
}

bool findWord(string s1 , string s2) {
	for(int i = 0 ; i < num; i++) {
		if(s1 == word[i]) vitri[0] = i;
		if(s2 == word[i]) vitri[1] = i;
	}
	if(vitri[0] == 0 && vitri[1] == 0) return false;
	return true;
}

void outputRoad() {
	if(truoc[vitri[1]] == -1 ) cout<<"Miss!"<<endl;
	else {
		int j = vitri[1];
		road.push_back(j);
		while(truoc[j] != vitri[0]) {
			road.push_back(truoc[j]);
			j = truoc[j];
		}
		road.push_back(vitri[0]);
		int lenght = road.size() - 1;
	    for(int i = lenght ; i > 0; i--) {
		cout<<word[road[i]]<<",";
	    }
	    cout<<word[road[0]];
	}

}

void findRoad() {
	for(int i = 0 ; i < num; i++) {
		truoc[i] = -1;
		//flag[i] = false;
	}
	BFS(vitri[0]);
	outputRoad();
}

int main() {
	input();
	CreatGraph();
	cout<<lienThong()<<endl;
	string str1, str2;
	cin>>str1>>str2;
	if(findWord(str1,str2)) findRoad();
	else cout<<"MISS!";
	return 0;
}

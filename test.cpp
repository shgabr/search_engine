
#include <iostream>
#include <vector>
#include <extra.h>
using namespace std;
#define s 4

int partition (vector<string*> & A, int p, int r){

    string * pivot = A[p];
    int i=p, j=r;

    do {
        do {i++;} while(*A[i]>*pivot && i<(A.size()-1));
        do {j--;} while(*A[j]<*pivot);
        if (i<j) swap(A[i], A[j]);
    } while (i<j);

    A[p] = A[j];
    A[j] = pivot;
    return j;
}

void mysort (vector<string*> & A, int p, int r){

        if (p<r){
            int q = partition (A, p, r+1);
            mysort(A, p, q-1);
            mysort(A, q+1, r);
        }

}

int main (){

         vector < vector<int> > graph;
        // double rank = 1;
        // double pr [s] = {1,1,1,1};
        // double npr [s] = {0,0,0,0};
        // int links [s];
        //
         graph.resize (s);
         for (int i=0; i<s; i++)
                 graph [i].resize(s);
        //
        // for (int i=0; i<s; i++)
        //         pr [i] = pr[i] / s;
        //
        // links [0] = 0;
        // graph [1][0] = 1;
        // graph [1][2] = 1;
        // links [1] = 2;
        // graph [2][0] = 1;
        // links [2] = 1;
        // graph [3][0] = 1;
        // graph [3][1] = 1;
        // graph [3][2] = 1;
        // links [3] = 3;
        //
        //
        // // for (auto l=graph.begin(); l!=graph.end(); l++, i++){
        // //         for (auto m=graph[i].begin(); m!=graph[i].end(); m++, j++)
        // for (int i=0; i<s; i++){
        //         for (int j=0; j<s; j++)
        //                 cout << graph[i][j] << " ";
        //         cout << endl;
        // }
        //
        // for (int j=0; j<s; j++){
        //         cout << "--->" << j << endl;
        //         for (int i=0; i<s; i++){
        //                 if (graph[i][j] == 1){
        //                         npr [j] += pr [i] / links [i];
        //                         cout << pr [i] << " " << links [i] << "\n";
        //                 }
        //         }
        // }
        //
        // for (int i=0; i<s; i++){
        //         if (npr[i] != 0) pr[i] = npr[i];
        //         cout << pr [i] << " ";
        // }
        // cout << "\n";

        // vector <string*> keywords(s);
        //
        // string n1="Z", n2="Y", n3="A", n4="B";
        //
        // string * p1 = &n1;
        // string * p2 = &n2;
        // string * p3 = &n3;
        // string * p4 = &n4;
        //
        //
        // keywords[0] = p1;
        // keywords[1] = p2;
        // keywords[2] = p3;
        // keywords[3] = p4;
        //
        // //sort(keywords.begin(),keywords.end());
        // //extra::Sort(keywords);
        // vector <string*> rankedURL = keywords;
        //
        // mysort (rankedURL, 0, rankedURL.size()-1);
        //
        // for (int i=0; i<s; i++)
        //         cout << *rankedURL[i] << endl;
        //
        // for (int i=0; i<s; i++)
        //         cout << *keywords[i] << endl;

        //string str = "\"Hello\"";
        //str.erase(remove(str.begin(), str.end(), '\"'), str.end());
        // remove(str.begin(), str.end(), '\"');
        // str.erase(str.end()-2, str.end());
        //cout << str << endl;

        //vector <vector<int> > temp (s);
        // for (int i=0; i<s; i++){
        //     temp [i] = i+1;
        //     cout << temp [i] << " ";
        // }
        // cout << endl;
        int k=0;
        for (int i=0; i<s; i++)
                for (int j=0; j<s; j++,k++)
                        graph [i][j] = k;

        for (int i=0; i<s; i++){
                for (int j=0; j<s; j++,k++)
                        cout << graph [i][j] << " ";
                cout << endl;
        }

         graph.erase (graph.begin()+1);
         for (int j=0; j<graph.size(); j++,k++)
                graph[j].erase (graph[j].begin()+1);

        for (int i=0; i<graph.size(); i++){
                for (int j=0; j<graph[i].size(); j++,k++)
                        cout << graph [i][j] << " ";
                cout << endl;
        }

        // for (int i=0; i<temp.size(); i++){
        //     cout << temp [i] << " ";
        // }
        // cout << endl;



}

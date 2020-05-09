#include <URL.h>

URL::URL (string link_name)
{
        linkname = link_name;
        rank = 0;
        pr = 0;
        prn = 0;
        ct = 0;
        imp = 0;
        edge = 0;
        counterA = 0;
        counterC = 0;
        counterAC = 0;
}
string URL::getLinkname (){
        return linkname;
}
void URL::computeRank (){

        counterC++;
        if (imp !=0){    ctr = ct/imp;    counterA++; }
        else            ctr = 0;

        double impt = ((0.1*imp)/(1+0.1*imp));
        double temp1 = prn * (1-impt);
        double temp2 = ctr * (impt);
        rank = 0.4*prn + 0.6*(temp1+temp2);
        counterA+=11;
}
double URL::getRank (){
        return rank;
}
void URL::setPR (double num){
        pr = num;
}
double URL::getPR (){
        return pr;
}
void URL::setPRN (double num){
        prn = num;
}
double URL::getPRN (){
        return prn;
}
void URL::setCT (double num){
        ct = num;
}
void URL::incCT (){
        counterA++;
        ct++;
}
double URL::getCT (){
        return ct;
}
void URL::setIMP (double num){
        imp = num;
}
double URL::getIMP (){
        return imp;
}
void URL::incIMP (){
        counterA++;
        imp++;
}
int URL::getEdges (){
        return edge;
}
void URL::incEdge (){
        counterA++;
        edge++;
}
void URL::decEdges (){
        counterA++;
        edge--;
}
void URL::insertKeyword (string kw){
        keywords.insert(keywords.end(),kw);
}
void URL::sortKeywords (){
        quick_sort (keywords,0,keywords.size()-1);
}
bool URL::findKeyword (string key){

        return binarySearch(keywords, key, 0, keywords.size()-1);
}
int URL::partition (vector <string> & A, int p, int r){

        string pivot = A[p];
        counterAC++;
        int i=p, j=r;

        do {
            do {i++; counterAC++; counterC+=2; counterA++;} while(A[i]<pivot && i<(A.size()-1));
            do {j--; counterAC++; counterC++; counterA++;} while(A[j]>pivot);
            counterC+=2;
            if (i<j) swap(A[i], A[j]);
        } while (i<j);

        A[p] = A[j];
        A[j] = pivot;
        counterAC+=3;
        return j;

}
void URL::quick_sort (vector <string> & A, int p, int r){

        counterC++;
        if (p<r){
            int q = partition (A, p, r+1);
            quick_sort(A, p, q-1);
            quick_sort(A, q+1, r);
        }
}
bool URL::binarySearch (vector <string> A, string key, int x, int z){

        counterC++;
        if (x>z) return false;
        int mid = (x+z)/2;
        counterA+=2;
        if (key < A[mid]){ counterC++; return binarySearch (A, key, x, mid-1);  }
        if (key > A[mid]){ counterC+=2; return binarySearch (A, key, mid+1, z); }
        return true;
}
void URL::getcounts (int & cA, int & cC, int & cAC){

        cA = counterA;
        cC = counterC;
        cAC = counterAC;
        counterA = 0;
        counterC = 0;
        counterAC = 0;
}
URL::~URL ()
{




}

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
}
string URL::getLinkname (){
        return linkname;
}
void URL::computeRank (){

        if (imp !=0)    ctr = ct/imp;
        else            ctr = 0;

        double impt = ((0.1*imp)/(1+0.1*imp));
        double temp1 = prn * (1-impt);
        double temp2 = ctr * (impt);
        rank = 0.4*prn + 0.6*(temp1+temp2);
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
        imp++;
}
int URL::getEdges (){
        return edge;
}
void URL::incEdge (){
        edge++;
}
void URL::insertKeyword (string kw){
        keywords.insert(keywords.end(),kw);
}
void URL::sortKeywords (){
        sort(keywords.begin(),keywords.end());
}
bool URL::findKeyword (string key){

        return binaySearch(key, 0, keywords.size()-1);
}
bool URL::binaySearch (string key, int x, int z){

        if (x>z) return false;
        int mid = (x+z)/2;
        if (key < keywords[mid]) return binaySearch (key, x, mid-1);
        if (key > keywords[mid]) return binaySearch (key, mid+1, z);
        return true;
}
URL::~URL ()
{




}

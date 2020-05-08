// #ifndef EXTRA_H_
// #define EXTRA_H_
//
//
// #include <includes.h>
// #include <URL.h>
//
// class extra{
//     public:
//         template <typename T>
//         int WebPage::partition (T & A, int p, int r){
//
//                 T pivot = A[p];
//                 int i=p, j=r;
//
//                 do {
//                     do {i++;} while(*A[i]>*pivot);
//                     do {j--;} while(*A[j]<*pivot);
//                     if (i<j) swap(A[i], A[j]);
//                 } while (i<j);
//
//                 A[p] = A[j];
//                 A[j] = pivot;
//                 return j;
//
//         }
//         void WebPage::sortURLRank (vector <URL*> & A, int p, int r){
//
//                 if (p<r){
//                     int q = partition (A, p, r+1);
//                     sortURLRank(A, p, q-1);
//                     sortURLRank(A, q+1, r);
//                 }
//         }
// };
//
// #endif

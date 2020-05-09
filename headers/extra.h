#ifndef EXTRA_H_
#define EXTRA_H_


#include <includes.h>
#include <URL.h>

class extra{
    public:
        template <typename T>
        static int partition (vector <T> & A, int p, int r){

                T pivot = A[p];
                int i=p, j=r;

                do {
                    do {i++;} while(A[i]<pivot && i<(A.size()-1));
                    do {j--;} while(A[j]>pivot);
                    if (i<j) swap(A[i], A[j]);
                } while (i<j);

                A[p] = A[j];
                A[j] = pivot;
                return j;

        }
        template <typename T>
        static void quick_sort (vector <T> & A, int p, int r){

                if (p<r){
                    int q = partition (A, p, r+1);
                    quick_sort(A, p, q-1);
                    quick_sort(A, q+1, r);
                }
        }
        template <typename T>
        static bool binarySearch (vector <T> A, T key, int x, int z){

                if (x>z) return false;
                int mid = (x+z)/2;
                if (key < A[mid]) return binarySearch (A, key, x, mid-1);
                if (key > A[mid]) return binarySearch (A, key, mid+1, z);
                return true;
        }
        template <typename T>
        static void print1D (T A, int s1){
                for (int i=0; i<s1; i++)
                        cout << A[i] << " ";
                printf("\n");
        }
        template <typename T>
        static void print2D (T A, int s1, int s2){
                for (int i=0; i<s1; i++){
                        for (int j=0; j<s2; j++)
                                cout << A[i][j] << " ";
                        printf("\n");
                }
        }

};

#endif

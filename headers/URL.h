#ifndef URL_H_
#define URL_H_

#include <includes.h>
#include <extra.h>


class URL
{
    private:
            vector <string> keywords;                           //vector of keywords
            string linkname;                                    //the name of the URL
            double rank;                                        //the rank of the URL
            double pr;                                          //the page rank of the URL
            double prn;                                         //the page rank normalized
            double ct;                                          //the click-through
            double imp;                                         //number of impressions
            double ctr;                                         //the click_through rate
            int edge;                                           //the number of outbound edges the URL has
            long counterA;                                      //counter for arithmetic operations
            long counterC;                                      //counter for comparisons
            long counterAC;                                     //counter for array accesses
            int partition (vector <string> & A, int p, int r);
            void quick_sort (vector <string> & A, int p, int r);
            bool binarySearch (vector <string> A, string key, int x, int z);
    public:
            URL (string link_name);                             //constructor
            string getLinkname ();                              //getter for link name
            double getPR ();                                    //getter for page rank
            void setPR (double num);                            //setter for page rank
            double getPRN ();                                   //getter for page rank normalized
            void setPRN (double num);                           //setter for page rank normalized
            double getIMP ();                                   //getter for impressions
            void setIMP (double num);                           //setter for impressions
            void incIMP ();                                     //increment impressions
            double getCT ();                                    //getter for click-through
            void setCT (double num);                            //setter for click-through
            void incCT ();                                      //increment click-through
            double getRank ();                                  //getter for rank
            void computeRank ();                                //computes rank for URL
            void incEdge ();                                    //increment the number of edges
            void decEdges ();                                   //decrement the number of edges
            int getEdges ();                                    //getter for number of edges
            void insertKeyword (string keyword_p);              //insert keywords in vector
/*O(nlogn)*/void sortKeywords ();                               //sorts the keyword vector
/*O(logn)*/ bool findKeyword (string key);                      //find the keyword inside the vector
            void getcounts (int & cA, int & cC, int & cAC);     //getter for all counters
            bool operator < (URL x){                            //operator overloading for less than operator
                    return (this->rank < x.rank);
            };
            bool operator > (URL x){                            //operator overloading for greater than operator
                    return (this->rank > x.rank);
            };
            ~URL();                                             //destructor
};




#endif

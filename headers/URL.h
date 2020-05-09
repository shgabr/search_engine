#ifndef URL_H_
#define URL_H_

#include <includes.h>


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
            bool binaySearch (string key, int x, int z);
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
            void sortKeywords ();                               //sorts the keyword vector
            bool findKeyword (string key);                      //find the keyword inside the vector

            bool operator < (URL x){                            //operator overloading for less than operator
                    return (this->rank < x.rank);
            };
            bool operator > (URL x){                            //operator overloading for greater than operator
                    return (this->rank > x.rank);
            };
            ~URL();                                             //destructor
};




#endif

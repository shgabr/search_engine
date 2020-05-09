#ifndef WEBPAGE_H_
#define WEBPAGE_H_

#include <includes.h>
#include <URL.h>
#include <extra.h>

class WebPage
{
    private:
        FILE * gFile;                                                   //contains graph initialization file
        FILE * kFile;                                                   //contains keywords initialization file
        FILE * uFile;                                                   //contains update file
        vector <URL*> webSites;                                         //stores the object URL
        vector <string> links;                                          //stores the link names
        vector < vector<int> > graph;                                   //graph of links
        long counterA;                                                  //counter for arithmetic operations
        long counterC;                                                  //counter for comparisons
        long counterAC;                                                 //counter for array accesses
/*O(n^2+ngu)*/  void uFile_handler (string U_file);                             //handles update file
/*O(n)*/        int cmdUPD (string link, int imp, int ct);                      //handles UPDATE link command
/*O(n)*/        int cmdADD (string link);                                       //handles ADD link command when coming from Ufile
/*O(n)*/        void cmdADD (string linkfrom, string linkto, int loc);          //handles ADD link command when coming from update command
/*O(ng)*/       void cmdRMV (string link);                                      //handles REMOVE link command when coming from Ufile
/*O(n)*/        void cmdRMV (string linkfrom, string linkto, int loc);          //handles REMOVE link command when coming from update command
/*O(nlogm)*/   long AND_handler (string keywords);                             //handles AND command
/*O(nlogm)*/   long OR_handler (string keywords);                              //handles OR command
/*O(n)*/        int find (string link);                                         //finds location of link
/*O(n^2)*/      void computePR ();                                              //computes the page rank of each link
/*O(nlogn)*/    void sortURLRank (vector <URL*> &, int, int);                   //sort the URL based on rank (quick sort)
/*^^^^*/        int partition (vector <URL*> &, int, int);                      //calculates partition for quick sort
/*O(n^2)*/      void printGraph ();
/*O(n)*/        void printLinks ();
    public:
/*O(ng)*/               WebPage (string G_file, string K_file);                         //constructor
/*O(g+w+nlogm+n^2)*/    void initialize ();                                             //initializes URL, graph, and links using initialization files
/*O(n^2+ngu)*/          long handler (string cmd);                                      //handles the command coming in
/*----*/                void counters ();                                               //prints all counters
/*O(1)*/                ~WebPage();                                                     //destructor
};




#endif

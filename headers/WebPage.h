#ifndef WEBPAGE_H_
#define WEBPAGE_H_

#include <includes.h>
#include <URL.h>


class WebPage
{
    private:
        FILE * gFile;                                                   //contains graph initialization file
        FILE * kFile;                                                   //contains keywords initialization file
        FILE * uFile;                                                   //contains update file
        vector <URL*> webSites;                                         //stores the object URL
        vector <string> links;                                          //stores the link names
        vector < vector<int> > graph;                                   //graph of links
        void uFile_handler (string U_file);                             //handles update file
        void cmdADD (string link);                                      //handles ADD link command when coming from Ufile
        void cmdADD (string linkfrom, string linkto);                   //handles ADD link command when coming from update command
        void cmdRMV (string link);                                      //handles REMOVE link command when coming from Ufile
        void cmdRMV (string linkfrom, string linkto);                   //handles REMOVE link command when coming from update command
        void AND_handler (string keywords);                             //handles AND command
        void OR_handler (string keywords);                              //handles OR command
        int find (string link);                                         //finds location of link
        void computePR ();                                              //computes the page rank of each link
        void sortURLRank (vector <URL*> &, int, int);                     //sort the URL based on rank (quick sort)
        int partition (vector <URL*> &, int, int);                        //calculates partition for quick sort
        void printGraph ();
    public:
        WebPage (string G_file, string K_file);                         //constructor
        void initialize ();                                             //initializes URL, graph, and links using initialization files
        void handler (string cmd);                                      //handles the command coming in
        ~WebPage();                                                     //destructor
};




#endif
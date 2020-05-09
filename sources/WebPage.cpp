#include <WebPage.h>

WebPage::WebPage (string G_file, string K_file)
{       //open initialization files and create graph

        gFile = fopen (G_file.c_str(),"r");

        kFile = fopen (K_file.c_str(),"r");

        uFile = NULL;

        if (gFile == NULL){
                printf("Unable to open graph file: %s. Terminating!!!\n",G_file.c_str());
                exit (1);
        }
        if (kFile == NULL){
                printf("Unable to open keywords file: %s. Terminating!!!\n",K_file.c_str());
                exit (1);
        }


        fseek(gFile, 0, SEEK_END);
        int size_gf = 2 * ftell(gFile);
        fseek(gFile, 0, SEEK_SET);

        graph.resize(size_gf);
        for (int i=0; i<size_gf; i++)
                graph[i].resize(size_gf);

        printf("Opened Graph file\n");
        printf("Opened Keywords file\n");

}
void WebPage::initialize ()
{
        char lineC [200];
        string lineS;


        //reading from graph initialization file
        string linkFrom, linkTo;
        int g = fscanf (gFile, "%[^\n]\n", lineC);

        while (g != EOF) {
                lineS = lineC;
                stringstream S(lineS);
                getline (S,linkFrom,',');
                getline (S,linkTo,'\n');

                int lf = find (linkFrom);
                int lt = find (linkTo);
                if (lf == -1){
                        webSites.insert(webSites.end(), new URL(linkFrom));
                        links.insert(links.end(), linkFrom);
                        lf = links.size()-1;
                }
                if (lt == -1){
                        webSites.insert(webSites.end(), new URL(linkTo));
                        links.insert(links.end(), linkTo);
                        lt = links.size()-1;
                }

                graph [lf][lt] = 1;
                webSites[lf]->incEdge();

                g = fscanf (gFile, "%[^\n]\n", lineC);

        }


        //reading from keywords initialization file
        string link, kw;
        int k = fscanf (kFile, "%[^\n]\n", lineC);

        while (k != EOF) {
                lineS = lineC;
                stringstream S(lineS);
                getline (S,link,',');
                int index = find(link);
                if (index == -1) printf("Link not available: %s\n",link.c_str());
                else{
                        while (getline(S, kw, ',')) {
                                webSites[index]->insertKeyword(kw);
                        }
                }
                k = fscanf (kFile, "%[^\n]\n", lineC);
        }

        // set page rank and sort keyowrds for every URL
        double s = links.size();
        for (int i=0; i<s; i++){
                webSites[i]->setPR(1.0/s);
                webSites[i]->sortKeywords();
        }

        computePR ();

}
long WebPage::handler (string cmd)
{

        // checks the command is which type
        if (cmd[0] == '-')
                uFile_handler (cmd);

        else if (cmd[0] == '\"')
                return AND_handler (cmd);
        else
                return OR_handler (cmd);

        return 0;
}
long WebPage::AND_handler (string keywords)
{

        // create a new URL vector and sort it depending on rank
        vector <URL*> rankedURL = webSites;
        double s = rankedURL.size();
        for (int i=0; i<s; i++){
                rankedURL[i]->computeRank();
        }
        sortURLRank (rankedURL, 0, s-1);

        // parses the strings into seperate words (max 10) also removing quotations
        stringstream S (keywords);
        string kw [10], temp;
        int k=0;
        while (getline (S,temp,' ') && k<10){
                kw[k] = temp;
                k++;
        }
        for (int i=0; i<k; i++){
                kw[i].erase(remove(kw[i].begin(), kw[i].end(), '\"'), kw[i].end());
        }

        // checks if all keywords exists in a URL and prints if all exists
        map <int, URL*> results;
        int count = 0;
        for (int i=0; i<s; i++){
                bool successful = true;
                for (int j=0; j<k; j++){
                        if (!rankedURL[i]->findKeyword(kw[j]))
                                successful = false;
                }
                if (successful){
                        rankedURL[i]->incIMP();
                        cout << rankedURL[i]->getLinkname() << "\n";
                        results.insert(pair<int,URL*>(count,rankedURL[i]));
                        count++;
                }
        }

        // getting the link number to click on to increment click-through
        auto checkStart = high_resolution_clock::now();
        if (count){
                int clickno;
                printf("Enter link number to click on: ");
                cin >> clickno;
                while (clickno < 1 || clickno > count){
                        string no;
                        printf("Error link number does not exist! Re-enter: ");
                        cin >> no;
                        clickno = stoi(no);
                }
                results[clickno-1]->incCT();
                cin.ignore();
        } else
                printf("No links with keywords searched!\n");

        auto checkStop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(checkStop - checkStart);
        return duration.count();

}
long WebPage::OR_handler (string keywords)
{

        // create a new URL vector and sort it depending on rank
        vector <URL*> rankedURL = webSites;
        double s = rankedURL.size();
        for (int i=0; i<s; i++){
                rankedURL[i]->computeRank();
        }
        sortURLRank (rankedURL, 0, s-1);

        // parses the strings into seperate words (max 10)
        stringstream S (keywords);
        string kw [10], temp;
        int k=0;
        while (getline (S,temp,' ') && k<10){
                kw[k] = temp;
                k++;
        }
        // checks if a keyword exists in a URL and prints URL if one exists
        map <int, URL*> results;
        int count = 0;
        for (int i=0; i<s; i++){
                bool successful = false;
                for (int j=0; j<k; j++){
                        if (rankedURL[i]->findKeyword(kw[j]))
                                successful = true;
                }
                if (successful){
                        rankedURL[i]->incIMP();
                        cout << rankedURL[i]->getLinkname() << "\n";
                        results.insert(pair<int,URL*>(count,rankedURL[i]));
                        count++;
                }
        }

        // getting the link number to click on to increment click-through
        auto checkStart = high_resolution_clock::now();
        if (count){
                int clickno;
                printf("Enter link number to click on: ");
                cin >> clickno;
                while (clickno < 1 || clickno > count){
                        printf("Error link number does not exist! Re-enter: ");
                        cin >> clickno;
                }
                results[clickno-1]->incCT();
                cin.ignore();
        } else
                printf("No links with keywords searched!\n");

        auto checkStop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(checkStop - checkStart);
        return duration.count();
}

void WebPage::uFile_handler (string U_file)
{
        if (uFile != NULL) fclose (uFile);

        U_file.erase(0,1);

        uFile = fopen (U_file.c_str(),"r");

        if (uFile == NULL){
                printf("Unable to open update file: %s. Terminating!!!\n",U_file.c_str());
                exit (1);
        }
        printf("Opened Update file\n");

        //reading from update file
        int imp, upd;
        char lineC [200];
        string cmd, temp, link, lineS;
        int u = fscanf (uFile, "%[^\n]\n", lineC);

        //read until end of file
        while (u != EOF) {

                lineS = lineC;
                stringstream S(lineS);
                getline (S,cmd,',');

                if (cmd == "A"){
                        getline (S,link,'\n');
                        cmdADD (link);
                }
                else if (cmd == "R"){
                        getline (S,link,'\n');
                        cmdRMV (link);
                }
                else if (cmd == "U"){
                        getline (S,link,',');
                        getline (S,temp,',');
                        imp = stoi(temp);
                        getline (S,temp,',');
                        upd = stoi(temp);
                        int loc = cmdUPD (link, imp, upd);

                        //parse string until spaces to get command and link
                        while (getline (S,temp,' ')){
                                string link2;
                                cmd = temp;
                                getline (S,temp,' ');
                                link2 = temp;
                                if (cmd == "A"){
                                        cmdADD (link, link2, loc);
                                } else if (cmd == "R"){
                                        cmdRMV (link, link2, loc);
                                }
                        }

                }
                // read until end of line and save in lineC
                u = fscanf (uFile, "%[^\n]\n", lineC);
        }
        // since the number of edges could have changed then we need to compute page rank again
        computePR();

}
int WebPage::cmdUPD (string link, int imp, int ct){

        // finds location of link (if doesn't exist then add it)
        int loc = find (link);
        if (loc == -1){
                cmdADD (link);
                loc = links.size()-1;
        }
        //update the impressions and click-through counters
        webSites[loc]->setIMP(imp);
        webSites[loc]->setCT(ct);
        printf("Successfully updated impressions and click_through of %s\n",link.c_str());
        return loc;

}
int WebPage::cmdADD (string link){

        //if link doesnt exist then create it
        int loc = find(link);
        if (loc == -1){
                webSites.insert(webSites.end(), new URL(link));
                links.insert(links.end(), link);
                printf("Successfully added %s\n",link.c_str());
                loc = links.size()-1;
        }
        return loc;

}
void WebPage::cmdADD (string linkfrom, string linkto, int loc){

        // finds second link and if it doesnt exist then create it
        int loc2 = find (linkto);
        if (loc2 == -1){
                loc2 = cmdADD (linkto);
        }

        // create an edge between linkfrom to linkto and increment edges of linkfrom
        graph [loc][loc2] = 1;
        webSites [loc]->incEdge();
        printf("Successfully added edge between %s and %s\n",linkfrom.c_str(),linkto.c_str());

}
void WebPage::cmdRMV (string link){

        //find the location of link then remove the link URL and graph
        int loc = find(link);
        if (loc != -1){
                webSites.erase(webSites.begin()+loc);
                links.erase(links.begin()+loc);
                graph.erase (graph.begin()+loc);
                for (int j=0; j<graph.size(); j++)
                       graph[j].erase (graph[j].begin()+loc);
                printf("Successfully removed %s\n",link.c_str());
        }

}
void WebPage::cmdRMV (string linkfrom, string linkto, int loc){

        // if linkto exists then remove the edge between linkfrom to linkto
        int loc2 = find (linkto);
        if (loc2 != -1){
                graph [loc][loc2] = 0;
                webSites [loc]->decEdges ();
                printf("Successfully removed edge between %s and %s\n",linkfrom.c_str(),linkto.c_str());
        }

}

int WebPage::find (string link){

        // loop on link vector and get location of link
        int j=0;
        for (auto i=links.begin(); i!=links.end(); i++,j++){
                if (*i == link){
                        return j;
                }
        }
        return -1;

}
void WebPage::computePR (){

        int s = links.size();
        double * npr = new double [s];

        for (int i=0; i<s; i++)
                npr[i] = 0;

        // calculate page rank by dividing the page rank of the parent link by their number of edges
        double max = 0;
        for (int j=0; j<s; j++){
                for (int i=0; i<s; i++){
                        if (graph[i][j] == 1){
                                npr [j] += webSites[i]->getPR() / webSites[i]->getEdges();
                        }
                }
                if (npr[j]>max){
                        max = npr[j];
                }
        }

        // set page rank and page rank normalizaed in each URL
        for (int i=0; i<s; i++){
                if (npr[i] != 0){
                        webSites[i]->setPR(npr[i]);
                        webSites[i]->setPRN(npr[i]/max);
                }
                if (npr[i] == 0) webSites[i]->setPRN(webSites[i]->getPR()/max);
        }

        delete [] npr;

}
int WebPage::partition (vector <URL*> & A, int p, int r){

        // pivot is first element
        URL * pivot = A[p];
        int i=p, j=r;

        // sort descendingly based on rank
        do {
            do {i++;} while(*A[i]>*pivot && i<A.size()-1);
            do {j--;} while(*A[j]<*pivot);
            if (i<j) swap(A[i], A[j]);
        } while (i<j);

        A[p] = A[j];
        A[j] = pivot;
        return j;

}
void WebPage::sortURLRank (vector <URL*> & A, int p, int r){

        // quick sort
        if (p<r){
            int q = partition (A, p, r+1);
            sortURLRank(A, p, q-1);
            sortURLRank(A, q+1, r);
        }
}
void WebPage::printGraph (){

        int s = links.size();
        for (int i=0; i<s; i++){
                for (int j=0; j<s; j++)
                        cout << graph[i][j] << " ";
                cout << endl;
        }

}
void WebPage::printLinks (){

        for (int i=0; i<links.size(); i++)
                cout << links[i] << endl;

}
WebPage::~WebPage ()
{
        // if files are not closed then close them
        if (gFile != NULL) fclose (gFile);
        if (kFile != NULL) fclose (kFile);
        if (uFile != NULL) fclose (uFile);
}

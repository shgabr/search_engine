#include <includes.h>
#include <URL.h>
#include <WebPage.h>


int main (){

        string Ginit_f, Kinit_f;

        printf("Enter graph initialization file name: ");
        //std::cin >> Ginit_f;
        Ginit_f = "graph.txt";
        printf("Enter keywords initialization file name: ");
        //std::cin >> Kinit_f;
        Kinit_f = "keywords.txt";
        
        WebPage search_engine (Ginit_f, Kinit_f);
        search_engine.initialize();

        printf("The commands that can performed: \n");
        printf("1) input keywords with or without quotations to indicate AND or OR\n");
        printf("2) input file name starting with \"-\" to update webpage\n");
        printf("To end program, enter \"end!\" or press enter\n");


        string command;
        while (true){
                cin.ignore();
                printf("-- Enter command > ");
                getline (cin, command);

                if (command == "end!" || command == "")
                        break;

                search_engine.handler(command);

        }

        printf("Program Ending\n");
        return 0;

}

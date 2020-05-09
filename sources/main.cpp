#include <includes.h>
#include <URL.h>
#include <WebPage.h>


int main (){

        auto absoluteStart = high_resolution_clock::now();

        string Ginit_f, Kinit_f;

        printf("Enter graph initialization file name: ");
        std::cin >> Ginit_f;
        //Ginit_f = "graph.txt";
        printf("Enter keywords initialization file name: ");
        std::cin >> Kinit_f;
        //Kinit_f = "keywords.txt";

        WebPage search_engine (Ginit_f, Kinit_f);
        search_engine.initialize();

        printf("The commands that can performed: \n");
        printf("1) input keywords with or without quotations to indicate AND or OR\n");
        printf("2) input file name starting with \"-\" to update webpage\n");
        printf("To end program, enter \"end!\" or press enter\n");


        string command;
        long long total_time = 0;
        cin.ignore();
        while (true){
                printf("-- Enter command > ");
                getline (cin, command);

                if (command == "end!" || command == "")
                        break;


                auto start = high_resolution_clock::now();

                long removeT = search_engine.handler(command);

                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                total_time = total_time + duration.count() - removeT;
                printf ("$ Total time to handle command (%s): %lld microseconds\n",command.c_str(),duration.count()-removeT);

        }
        printf("Program Ending\n");

        printf("$$ Total time for running all commands: %lld microseconds\n",total_time);

        auto absoluteEnd = high_resolution_clock::now();
        auto absoluteDuration = duration_cast<seconds>(absoluteEnd - absoluteStart);
        printf("$$ Total running time of program: %lld seconds\n",absoluteDuration.count());
        return 0;

}

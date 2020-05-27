
## To build program:

Write on command line: make
In order of makefile to work:
- The source code must be inside the sources directory
- The headers code (includes) must be inside the headers directory
- Directory (obj) must exist
- All of these directories must exist inside a command directory as the makefile


## To run program:

After building the program, type the command ./webpage on terminal opened to the directory of the makefile to run the program.


Program Functionalities:

- The program takes an input file that initializes how the links are connected. It should be in the same directory as the executable. The file format should be the following:
	
   	  linkfrom,linkto
		www.test1.com,www.test2.com
		www.test2.com,www.test3.com
		www.test3.com,www.test5.com
		www.test1.com,www.test3.com

- The program takes a second input file that initializes the keywords for each URL. It should be in the same directory as the executable. The file format should be the following:

      URL_name,Any,number,of,keywords,max,10
		www.test1.com,data,structures,complexity
		www.test2.com,machine,learning
		www.test3.com,programming,complexity,procedural,objects
		www.test5.com,graph,complex,learning,algorithms

- Then the program asks for a specific command. There are 2 main commands (query or updating)

	- Query: searching for specific keywords that belong to a certain link. There are 2 ways to issue a query.
		1.	AND: finds URL that contains all keywords. Format: 
		
				“data” “complexity”
		2.	OR: finds URL that contains at least one keyword: Format: 
			
				data complexity

	-	Update: input a file that updates state of link. For entering a file, format: 
	
			-update.txt 
		 The dash must be entered for program to know that we are inputting a file to update URLs. Webpage can be updated by adding a new URL, removing an existent URL, or updating some parameters of the URL like its impressions, click-through, and its links to other URLs.
		3.	ADD: adds new URL. Format: 
		
				 A,www.test1.com
		5.	REMOVE: removes an existent URL. Format: 
		
				R,www.test2.com
		6.	UPDATE: update parameters. Format: 
		 
				 U,www.test3.com,20,4,A www.test4.com R www.test5.com. 
		It can as many parameters to add and remove links to other URLs.

		So the general format of an update file:
       
       Command,link_name.com,parameters if update command
		 A,www.test1.com
		 R,www.test2.com
		 U,www.test3.com,20,4,A www.test4.com R www.test5.com
		 A,www.test6.com


## Extra:

For convenience, a single source file of the whole program is added to remove that the hassle of directories.
To build the program, run 

	make fullwebpage
And it runs by 

	./fullwebpage

However, it is not advisable to use this version. The first method for building program is to be always and this method is kept for backup.



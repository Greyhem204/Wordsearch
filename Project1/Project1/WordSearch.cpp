/*Read in a file that contains a list of 10 words.

Then, scan another file that contains at least 3 paragraphs from your favorite book.
Count the number of the words from the first file that are contained in the second.

Write the results to a file in the format of :

Word1 – Found x times
Word2 – Found y times
(repeat for all 10 words)*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


int main()
{
	//ifstream to read our counting and reading file
	std::ifstream CountFile("inputfile1.txt");
	std::ifstream ReadFile("inputfile2.txt");
	//separate string to hold the words to compare
	std::string words;
	//vector to hold the words needed to count
	std::vector <std::string> wrdcnt;
	//vector to hold the words we are reading
	std::vector <std::string> wrdrd;
	//number to count each word
	int cnt = 0;

	//if countfile is open
	if (CountFile.is_open()) 
	{
		//loop for the first vector to read the word in
		while (CountFile >> words) 
		{
			wrdcnt.push_back(words);
		}
		CountFile.close();
	}

	//if the Read file is open which it should
	if (ReadFile.is_open())
	{
		//loop for the second vector for comparison
		while (ReadFile >> words)
		{
			wrdrd.push_back(words);
		}
		ReadFile.close();
	}
	
	//check to make sure our two variables are not empty
	if (!wrdcnt.empty() && !wrdrd.empty())
	{
		//temp string to input the wordcount vector
		for (std::string tcnt : wrdcnt)
		{
			//tempstring for our word read vector
			for (std::string trd : wrdrd)
			{
				//if words match increase the number
				if (tcnt == trd)
				{
					cnt++;
				}

			}
			//outputting result
			std::cout << tcnt << ": " << cnt << std::endl;
			//reset count
			cnt = 0;
		}
	}
	//if there were no words
	else
	{
		std::cout << "No words detected" << std::endl;
	}
	system("pause");
}
#include "HashTable.h"
#include "WordEntry.h"

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) 
{
	size = s; //s is the size
	hashTable = new list<WordEntry>[size]; //initialize array
	
}


/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(string s) 
{
	int sum = 0; //initialize
	for (int i = 0; i < s.size(); i++)
	{
		sum += (int)s[i]; //sum of the characters in integer
	}
	return (sum*2+size-39)%size; //alogrithm for hash
	
}


/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(string s, int score) 
{
	//calculate hash
	int hash = computeHash(s);
	//cout << "hash: " << hash << " : " << s << endl;//test
	list<WordEntry>::iterator iter;
	//loop through the linked list of that hash element
	iter = hashTable[hash].begin();
	while (iter != hashTable[hash].end())
	{ 
		if (iter->getWord() == s) 
		{   
		//compare WordEntry's word to the input string
		iter->addNewAppearance(score);
		return;
		}
		iter++;
    	}
    
    //only get here if string is not in the hash table
    //create new WordEntry
    WordEntry e(s,score);

    //put it in the list at the appropriate hash
    hashTable[hash].push_back(e); 

}

/* getAverage
*  input: string word 
*  output: the result of a call to getAverage()
*          from the WordEntry
*  Must first find the WordEntry in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

double HashTable::getAverage(string s) 
{
	//computer Hash
	int hash = computeHash(s);
	list<WordEntry>::iterator iter;
	//loop through the linked list of that hash element	
	iter = hashTable[hash].begin();
	while (iter != hashTable[hash].end())
	{
		if (iter->getWord() == s) 
		{     
			return iter->getAverage(); //get the average from WordEntry if word is found
		}
		iter++;
	}
	return 2.0;
}

/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
*/
bool HashTable::contains(string s) 
{
	 //compute hash
	int hash = computeHash(s);
	list<WordEntry>::iterator iter;
	//loop through the linked list of that hash element
	iter = hashTable[hash].begin();
	while (iter != hashTable[hash].end())
	{
		if (iter->getWord() == s)
		{
			return true; //true if word is in hash table
		}
		iter++;
	}

	return false; //false if word is not in hash table
}

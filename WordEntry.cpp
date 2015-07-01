#include "WordEntry.h"

/* WordEntry contructor
* input: the string text (word) and the intial score the
*         word should be assigned to
*  note that numAppearances should be set to 1 here
*/

WordEntry::WordEntry(string text, int score)
{
	word = text; //text is word
	totalScore = score; //initialize score
	numAppearances = 1;//initialize numAppearances
}

/* addNewAppearance
* input integer that is a new score for a word that is
* already in the hash table
* function should increase total score by s
* also should increase numAppearances
*/
void WordEntry::addNewAppearance(int s)
{
	totalScore += s; //running totalScore
	numAppearances++;//increment numAppearances
}

/*getWord
* this accessor function is needed
* particularly in the HashTable code to get the word to be
* used for the hash value
* simple accessor function  
*/
string WordEntry::getWord()
{
	return word; //retrieve word
}

/* getAverage
*  returns the average score of the word
*  based on totalScore and numAppearances
*  note that typecasting -- turning one of the integers
*  to a double will be necessary to avoid integer division
*/
double WordEntry::getAverage()
{
	return (double)totalScore/numAppearances; //average in double
}
#include<iostream> 
#include <vector>

using namespace std; 


//BRUTE FORCE!
template <typename T> 
int sequentialSearch(vector<T> list, T targetValue)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] == targetValue)
		{
			return i;
		}
	}
	//O():?
	
	return -1;
}


//DIVIDE AND CONQUER
int binarySearch(std::vector<int> sortedNums, int searchValue)
{
	bool found = false;
	int first = 0;
	int last = sortedNums.size() - 1;
	int middle = (first + last)/2;

	while (first <= last and !found)
	{
		//nums = 11, 22, 33, 44, 55 (searching for 66) 
		//first while loop iter: middle = (0 + 4) /2 = 2 
		if (sortedNums[middle] == searchValue) //33 == 66?
		{
			found = true;
		} 
		else if (sortedNums[middle] > searchValue)
		{
			last = middle - 1;//shift last one to the "left" of middle
		}
		else
		{
			first = middle + 1;
		}
	
		middle = (first + last) / 2; //use ceil() or floor() for odd lengths … be cautious
	
	}//end while
	if (found)
	{
		return middle;
	}
	else
	{
		return -1;//element is not in array
	}
}

int main()
{
	//vector<string> vowels = {"alpha", "beta", "cheeseburgers", "delta"};


	//string targetValue; ; //a BAD case
	//targetValue = 66; //A WORST case
	//targetValue = 1; //at "front" (pedantic)
	
	//targetValue = "cheeseburgers"; //O(N/2)
	vector<int> sortedNums = { 11, 22, 33, 44, 55, 66, 77, 88 };

	int targetValue = 88; 
	cout << "Found? the element " << targetValue << " at index: " 
		<< binarySearch(sortedNums, targetValue);

	//cout << "The element " << targetValue << " was found at index: " 
	//	<< sequentialSearch(vowels, targetValue);
	cout << "\n\n";
	
}
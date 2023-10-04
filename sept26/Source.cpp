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
	
	int comparisonCount = 0; 
	
	int whileLoopCount = 0; 
	while (first <= last and !found)
	{
		whileLoopCount++; 
		cout << "\n\nOn iteration " << whileLoopCount
			<< " , `first` changed to " << first << endl;

		cout << "\n\nOn iteration " << whileLoopCount
			<< " , `middle` changed to " << middle << endl;

		cout << "\n\nOn iteration " << whileLoopCount
			<< " , `last` changed to " << last << endl;

		//second iter: middle = 0; last = 1; first = 0
		//nums = 11, 22, 33, 44, 55 (searching for 66) 
		//first while loop iter: middle = (0 + 4) /2 = 2 
		if (sortedNums[middle] == searchValue) 
		{
			//comparisonCount++;
			found = true;
		} 



		//searchValue = 11;0

		else if (sortedNums[middle] > searchValue)
		{
			comparisonCount++;
			last = middle - 1;//shift last 1 to the "left" of middle



			//last = 2 - 1
			// last = 1;
		}
		else
		{
			comparisonCount++;
			first = middle + 1; //shift first 1 position to the "right" of middle



		}
	
		middle = (first + last) / 2; //use ceil() or floor() for odd lengths … be cautious



		//middle = (0 + 1) / 2 = 0
	}//end while
	
	//cout << "Comparison count: " << comparisonCount << endl; 

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
	//vector<int> sortedNums = { 11, 22, 33, 44, 55, 66, 77, 88, 99 };

	//int targetValue = 99; 
	//cout << "Found? the element " << targetValue << " at index: " 
	//	<< binarySearch(sortedNums, targetValue);

	////cout << "The element " << targetValue << " was found at index: " 
	////	<< sequentialSearch(vowels, targetValue);
	//cout << "\n\n";

	std::vector<int> primes = { 1, 2, 3, 5, 7, 11, 13, 17, 19, 23 };
	cout << binarySearch(primes, 13) << endl;
	//std::vector<int> nums64;
	//for (int i = 1; i <= 64; i++) {
	//	nums64.push_back(i); //{1, 2, 3, ...64}
	//}
	//std::vector<int> nums1024;
	//for (int i = 1; i <= 1024; i++) {
	//	nums1024.push_back(i);
	//}

	//binarySearch(nums64, 64);
	//binarySearch(nums1024, 1024);

}
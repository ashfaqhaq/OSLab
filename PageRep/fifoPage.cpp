/*compilation 
	g++ -std=c++11 fifoPage.cpp
*/
#include<bits/stdc++.h>
#include<set>
#include<iostream>
#include<queue>
using namespace std;

int pageFaults(int pages[], int n, int capacity)
{
    
    unordered_set<int> s;
  
    queue<int> indexes;
  

    int page_faults = 0;
    for (int i=0; i<n; i++)
    {
        // Check if the set can hold more pages
        if (s.size() < capacity)
        {
            // Insert it into set if not present
            // already which represents page fault
            if (s.find(pages[i])==s.end()) //we are traversing till end to find
            {
                s.insert(pages[i]);
  

                page_faults++;
  
                // Push the current page into the queue
                indexes.push(pages[i]);
            }
        }
  
        // If the set is full then need to perform FIFO
        // i.e. remove the first page of the queue from
        // set and queue both and insert the current page
        else
        {
            // Check if current page is not already
            // present in the set
            if (s.find(pages[i]) == s.end())
            {
                //Pop the first page from the queue
                int val = indexes.front();
  
                indexes.pop();
  
                // Remove the indexes page
                s.erase(val);
  
                // insert the current page
                s.insert(pages[i]);
  
                // push the current page into
                // the queue
                indexes.push(pages[i]);
  
                // Increment page faults
                page_faults++;
            }
        }
    }
  
    return page_faults;
}
  

int main()
{
	int n;
	
	cout<<"Enter number of process";
int pages[20];	
cin>>n;
	int i,a;
	for(i=0;i<n;i++)
	{
		cin>>pages[i];
	}
	//n = sizeof(pages)/sizeof(pages[0]);
	int capacity;
	cout<<"capacity";
	cin>>capacity;
	cout << pageFaults( pages, n, capacity);
	return 0;
} 

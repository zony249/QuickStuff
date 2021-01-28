#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void scramble(vector<int> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		swap(vec[i], vec[rand()%(vec.size()-i) + i]);
	}
}

int partition(vector<int> &vec, int low, int high)
{
	int j = low;
	for (int i = low; i < high; i++)
	{
		if (vec[i] < vec[high])
		{
			swap(vec[i], vec[j]);
			j++;
		}
	}

	swap(vec[j], vec[high]);
	return j;
}

void quicksort(vector<int> &vec, int low = 0, int high = -1)
{
	if (high == -1)
	{
		high = vec.size() - 1;
	}

	if (low < high)
	{
		int pi = partition(vec, low, high);

		quicksort(vec, low, pi - 1);
		quicksort(vec, pi + 1, high);
	}
}

int quickselect(vector<int> vec, int k, int low = 0, int high = -1)
{
	if (high == -1)
	{
		high = vec.size() - 1;
	}

	//cout << "Low: " << low << endl;
	//cout << "High: " << high << endl;
	//cout << "k: " << k << endl;



	if (low <= high)
	{
		int pi = partition(vec, low, high);
		//cout << "Pi: " << pi << endl;
		//for (auto x : vec)
		//{
		//	cout << x << " ";

		//}

		//cout << endl << endl;

		if (pi == k)
		{
			return vec[k];
		}
		else if (pi > k)
		{
			return quickselect(vec, k, low, pi-1);
		}
		else 
		{
			return quickselect(vec, k, pi + 1, high);
		}
	}
	return -11111111;
}

int main()
{
	vector<int> vec = {};
	for (int i = 0; i < 1000; i++)
	{
		vec.push_back(i);
	}

	scramble(vec);
	cout << "Scrambled vec: " << endl;
	for (auto x : vec)
	{
		cout << x << " ";
	}

	cout << endl;

	int select = quickselect(vec, 452);
	
	cout << "Sorted vec: " << endl;
	quicksort(vec);
	for (auto x : vec)
	{
		cout << x << " ";
	}
	cout << endl;

	


	cout << "quickselect output: " << select << endl; 
	return 0;
}

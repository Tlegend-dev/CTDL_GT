#include<iostream>
using namespace std;

struct dsd {
	int *a;
	int capacity;
	int n;

	dsd(int cap = 100)
	{
		a = new int[cap];
		capacity = cap;
		n = 0;
	}

	void import()
	{
		cout << "Nhap n: ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "a[" << i << "] = ";
			cin >> a[i];
		}
	}

	void exportt()
	{
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << "   ";
		}
		cout << endl;
	}

	void swap(int &a, int &b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}

	void selectionSort()
	{
		for (int i = 0; i < n - 1; i++)
		{
			int min_pos = i;
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] < a[min_pos])
					min_pos = j;
			}
			swap(a[min_pos], a[i]);
		}
	}

	void interchangeSort()
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] > a[i])
					swap(a[i], a[j]);
			}
		}
	}

	void insertionSort()
	{
		for (int i = 1; i < n; i++)
		{
			int x = a[i];
			int j = i - 1;
			while (j >= 0 && a[j] > x)
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = x;
		}
	}

	void bubleSort()
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = n - 1; j > i; j--)
			{
				if (a[j - 1] > a[j])
					swap(a[j - 1], a[j]);
			}
		}
	}

	int linearSearch(int x)
	{
		int i = 0;
		while (i < n&&a[i] != x)
			i++;

		if (i == n)
			return -1;
		return i;
	}

	int binarySearch(int x)
	{
		bubleSort();
		int l = 0;
		int r = n - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (a[mid] == x)
				return mid;
			else if (x < a[mid])
				r = mid - 1;
			else
				l = mid + 1;
		}
		return -1;
	}

	int binarySearch_by_recursion(int x,int l,int r)
	{
		if (l > r)
			return -1;
		else
		{
			int mid = (l + r) / 2;
			if (a[mid] == x)
				return mid;
			else if (x < a[mid])
				return binarySearch_by_recursion(x, l, mid - 1);
			return binarySearch_by_recursion(x, mid + 1, r);
		}
	}

};
int main()
{
	dsd a[100];
	cout << "=======MENU======\n"
		<< "1.Nhap danh sach.\n"
		<< "2.Xuat danh sach.\n"
		<< "3.Selection Sort.\n"
		<< "4.Interchange Sort.\n"
		<< "5.Insertion Sort.\n"
		<< "6.Buble Sort.\n";
	int bai;
	cin >> bai;
	while (bai != 0)
	{
		switch (bai)
		{
		case 1:
			a->import();
			break;
		case 2:
			a->exportt();
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
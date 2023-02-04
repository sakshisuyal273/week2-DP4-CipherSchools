//Kth smallest element

class element {

	static int kthSmallest(int[] arr, int N, int K)
	{

		
		List<int> pq = new List<int>();

		for (int i = 0; i < K; i++) {

			pq.Add(arr[i]);
		}
		for (int i = K; i < N; i++) {

			
			if (arr[i] < pq[0]) {
				pq.Sort();
				pq.Reverse();

				pq.RemoveAt(0);
				pq.Add(arr[i]);
			}
		}

		return pq[0];
	}

	
	public static void Main()
	{
		
		int[] vec= { 10, 5, 4, 3, 48, 15, 6, 2, 33, 53, 10 };

		
		int N = vec.Length;

		
		int K = 4;

		
		cout<<("Kth Smallest Element: "+ kthSmallest(vec, N, K));
	}
}




//median for finite integers
class element{

static int binarySearch(float[] arr, float item, int low, int high)
{
	if (low >= high) {
	return (item > arr[low]) ? (low + 1) : low;
	}

	int mid = (low + high) / 2;

	if (item == arr[mid])
	return mid + 1;

	if (item > arr[mid])
	return binarySearch(arr, item, mid + 1, high);

	return binarySearch(arr, item, low, mid - 1);
}

static void printMedian(float[] arr, int n)
{
	int i, j, pos;
	float num;
	int count = 1;

	Console.WriteLine( "Median after reading 1"		+ " element is " + arr[0]);

	for (i = 1; i < n; i++) {
	float median;
	j = i - 1;
	num = arr[i];

	
	pos = binarySearch(arr, num, 0, j);

	
	while (j >= pos) {
		arr[j + 1] = arr[j];
		j--;
	}

	arr[j + 1] = num;

	count++;

	if (count % 2 != 0) {
		median = arr[count / 2];
	}
	else {
		median = (arr[(count / 2) - 1] + arr[count / 2])/ 2;
	}

	Console.WriteLine( "Median after reading " + (i + 1)+ " elements is " + median );
	}
}


public static void Main(String[] args)
{
	float[] arr = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };
	int n = arr.Length;

	printMedian(arr, n);
}
}




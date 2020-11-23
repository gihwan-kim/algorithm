#include <iostream>

using namespace std;

void merge(int first, int last, int mid, int arr[]){
	int lArrIdx = first;
	int rArrIdx = mid+1;
	int i = first;
	int* temp = new int[last+1];
	while(lArrIdx<=mid&&rArrIdx<=last)
	{
		if(arr[lArrIdx] <= arr[rArrIdx])
			temp[i] = arr[lArrIdx++];
		else
			temp[i] = arr[rArrIdx++];
		i++;
	}

	if(lArrIdx>mid)
	{
		for(rArrIdx; rArrIdx<=last; rArrIdx++,i++)
			temp[i] = arr[rArrIdx];
	}else
	{
		for(lArrIdx;lArrIdx<=mid;lArrIdx++,i++)
			temp[i] = arr[lArrIdx];
	}

	for(i=first; i<=last;i++)
		arr[i] = temp[i];

	delete temp;
}

void sort(int first, int last, int arr[]){
	int mid = (first + last)/2;
	if(first<last)
	{
		sort(first, mid, arr);
		sort(mid+1, last, arr);
		merge(first,last, mid, arr);
	}
}

int main(int argc, char** argv) {

	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int K = 0;
	int i = 0;
	cin>>N;
	cin>>K;
	int* intArr = new int[N];

	for(i; i<N; i++){
		cin>>intArr[i];
	}

	sort(0,N-1, intArr);
	cout<<intArr[K-1];

	delete intArr;
	return 0;
}

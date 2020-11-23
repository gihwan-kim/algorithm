#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;



typedef struct info
{
	int year;
	int inputOrder;
	char* namePtr;
}PERSON;

int compare(const void* first, const void* second){
	const void* p1 = first;
	const void* p2 = second;
	if( ((PERSON*)p1)->year>((PERSON*)p2)->year )
	{
		return 1;
	}else if( ((PERSON*)p1)->year==((PERSON*)p2)->year )
	{
		if(((PERSON*)p1)->inputOrder< ((PERSON*)p2)->inputOrder)
		{
			return -1;
		}else
		{
			return 1;
		}
	}
	return 0;
}

int main(int argc, char** argv) {

	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N = 0;
	cin>>N;
	PERSON* personArr = new PERSON[N];
	int i=0;
	for(i; i<N; i++)
	{
		string temp;
		cin>>personArr[i].year;
		cin>>temp;
		char* arrPtr = new char[temp.length()];
		strcpy(arrPtr,temp.c_str());
		personArr[i].namePtr = arrPtr;
		personArr[i].inputOrder = i;
	}

	qsort(personArr,N, sizeof(PERSON), compare);
	for(i=0; i<N; i++)
	{
		cout<<personArr[i].year<<" "<<personArr[i].namePtr<< '\n';
	}
	delete personArr;

	return 0;
}
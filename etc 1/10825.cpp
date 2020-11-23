#include <iostream>
#include <cstring>

// merge sort 로 구현하였습니다.
// 시간 복잡도 O(n log n)

using namespace std;
class student
{
	public:
		string name;
		int kor;
		int eng;
		int mat;
};

// arry =  a(left) + b(right)
// a,b 배열은 각각 정렬이 완료된 상태
void merge(int start, int mid, int end, student *arry)
{
	int idx_a = start; // a 끝 : mid
	int idx_b = mid+1; // b 끝 : end
	int idx_t = 0;
	int check = 0;
	student *tmp = new student[end - start + 1];

	while(idx_a <= mid && idx_b <= end)
	{
		// 국어 점수가 감소하는 순서
		if (arry[idx_a].kor > arry[idx_b].kor)
		{
			tmp[idx_t++] = arry[idx_a++];
		}
		else if(arry[idx_a].kor == arry[idx_b].kor)
		{
			// 국어 점수가 같고
			// 영어 점수가 증가하는 순서
			if (arry[idx_a].eng > arry[idx_b].eng)
			{
				tmp[idx_t++] = arry[idx_b++];
			}
			else if(arry[idx_a].eng == arry[idx_b].eng)
			{
				// 국어 점수, 영어 점수가 같고
				// 수학 점수가 감소하는순서
				if (arry[idx_a].mat > arry[idx_b].mat)
				{
					tmp[idx_t++] = arry[idx_a++];
				}
				else if (arry[idx_a].mat == arry[idx_b].mat)
				{
					// 모든 점수가 같은 경우
					// 사전순으로 증가하는 순서
					if (arry[idx_a].name > arry[idx_b].name)
						tmp[idx_t++] = arry[idx_b++];
					else
						tmp[idx_t++] = arry[idx_a++];
				}
				// a 쪽 수학점수가 더 큰 경우
				else
					tmp[idx_t++] = arry[idx_b++];
			}
			// a 쪽 영어점수가 더 작은 경우
			else
				tmp[idx_t++] = arry[idx_a++];
		}
		// a 쪽 국어점수가 더 작은 경우
		else
			tmp[idx_t++] = arry[idx_b++];
	}
	while (idx_a <= mid) // 0 0
		tmp[idx_t++] = arry[idx_a++];
	while (idx_b <= end) // 1 1
		tmp[idx_t++] = arry[idx_b++];
	int j = 0;
	for (int i = start; i <= end; i++)
	{
		arry[i] = tmp[j++];
	}
	delete [] tmp;
	return ;
}

void recursive(int start, int end, student *arry)
{
	int mid;
	if (start >= end)
		return ;
	mid = (start + end)/2;
	recursive(start, mid, arry);
	recursive(mid+1, end, arry);
	merge(start, mid, end, arry);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	student *arry  = nullptr;

	cin >> n;
	arry = new student[n];
	for (int i = 0; i < n; i++)
		cin >> arry[i].name >> arry[i].kor >> arry[i].eng >> arry[i].mat;
	if (n > 1)
		recursive(0, n-1, arry);
	for (int i = 0; i < n; i++)
		cout << arry[i].name << '\n';
	delete [] arry;
	return 0;
}
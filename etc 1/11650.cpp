#include <iostream>
#include <cstdlib>

typedef struct location
	{
		int x;
		int y;
	}loc;


int compare(const void *p1,const void *p2)
{
    const void* first = p1;
    const void* second = p2;
    if( ((loc*)first)->x > ((loc*)second)->x)
    {
        return 1;
    }else if(  ((loc*)first)->x == ((loc*)second)->x){
        if( ((loc*)first)->y > ((loc*)second)->y){
            return 1;
        }else{
            return 0;
        }
    }
    return 0;
}

int main(int argc, char** argv) {

	using namespace std;

	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int i = 0;
	cin>>N;
	loc* locArry = new loc[N];
	for(i; i<N; i++){
		cin>>locArry[i].x;
		cin>>locArry[i].y;
	}

    qsort(locArry, N, sizeof(loc), compare);

	for(i = 0; i<N; i++){
		cout<<locArry[i].x<<" "<<locArry[i].y<<"\n";
	}
	return 0;
}

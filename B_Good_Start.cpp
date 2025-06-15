#include<iostream>
#include<cassert>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(int i=0;i<T;i++)
	{
		int w,h,a,b;
		cin>>w>>h>>a>>b;
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<(x1!=x2&&(x2-x1)%a==0||y1!=y2&&(y2-y1)%b==0?"Yes\n":"No\n");
	}
}

#include <bits/stdc++.h>
const int maxn = 1e4 + 10;
typedef long long ll;
int a[110];
int dp[110][maxn];//dp[i][j]��ʾǰi���ľ���jʱ�ߵ����ĸ߶�
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++)
            cin >> a[i];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= maxn; j++)
        {
            dp[i][j] = dp[i - 1][j]; //���ŵ�ǰ���ľ
            if(j - a[i] >= 0 && dp[i - 1][j - a[i]] != -1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + a[i]);//�Ÿ�
            if(dp[i - 1][j + a[i]] != -1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j + a[i]]);//�Ű���û����
            if(a[i] - j >= 0 && dp[i - 1][a[i] - j] != -1)
                dp[i][j] = max(dp[i][j], dp[i - 1][a[i] - j] + j);//�Ű��ҳ���
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}


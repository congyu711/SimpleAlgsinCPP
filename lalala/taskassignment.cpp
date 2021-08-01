#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
const int n = 10;
const int m = 5;
class task
{
public:
    int no, w;
    vector<int> rejworkstations, rejtks, deptks;
};
class workstations
{
public:
    int no, mxw;
};
task taskarr[30];
workstations wsarr[20];

bool cmpws(const workstations &a, const workstations &b)
{
    return a.mxw > b.mxw;
}
vector<int> sizew(20, 0); //第i个工作站的当前容量
vector<int> inM(20, 0);   //储存当前解
priority_queue<pair<int, vector<int>>> ans;
void dfs(int i, int j)
{
    //搜索树层数最大值=任务个数=n
    if (i == n + 1)
        return;
    if (j != 0)
    {
        //判断第j个工作站的容量剪枝
        if (wsarr[j].mxw <= sizew[j])
            return;
        //判断同一个工作站是否有是否有不能在同一个工作站上执行的任务
        for (int k = 0; k < taskarr[i].rejtks.size(); k++)
            if (inM[taskarr[i].rejtks[k]] == j)
                return;
        //判断是否执行在了不能使用的工作站上
        for (int k = 0; k < taskarr[i].rejworkstations.size(); k++)
            if (taskarr[i].rejworkstations[k] == j)
                return;
        //判断是否有必须执行在共一个工作站的任务执行在了其他工作站
        for (int k = 0; k < taskarr[i].deptks.size(); k++)
            if (taskarr[i].deptks[k] != 0 && taskarr[i].deptks[k] != j)
                return;
    }
    //处理当前解...
    int tmp = 0;
    for (int k = 1; k <= i; k++)
    {
        if (inM[k] != 0)
            tmp += taskarr[k].w;
    }
    //将当前解放入优先队列
    ans.push(make_pair(tmp, inM));

    //递归搜索树的下一层和回溯
    for (int k = 0; k <= m; k++)
    {
        inM[i + 1] = k;
        sizew[k] += taskarr[i + 1].w;
        dfs(i + 1, k);
        sizew[k] -= taskarr[i + 1].w;
        inM[i + 1] = 0;
    }
}

class bigtsk
{
public:
    int totw;
    vector<int> no;
};
bool check[20];
vector<bigtsk> arr;
bool cmptks(const bigtsk &a, const bigtsk &b)
{
    return a.totw < b.totw;
}
bool checkrej(bigtsk h, int x)
{
    for (int i = 0; i < h.no.size(); i++)
    {
        for (int j = 0; j < taskarr[h.no[i]].rejworkstations.size(); j++)
        {
            if (taskarr[h.no[i]].rejworkstations[j] == x)
                return false;
        }
        for (int j = 0; j < taskarr[h.no[i]].rejtks.size(); j++)
        {
            for (int k = 1; k <= n; k++)
                if (inM[k] == x && k == taskarr[h.no[i]].rejtks[j])
                    return false;
        }
    }
    return true;
}
void greed()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        bigtsk tmp;
        tmp.no.push_back(i);
        tmp.totw = taskarr[i].w;
        int c = taskarr[i].deptks.size();
        if (c != 0 && !check[i])
        {
            //此处暂且假设有依赖的任务的依赖信息都等价
            for (int k = 0; k < c; k++)
            {
                tmp.no.push_back(taskarr[i].deptks[k]);
                tmp.totw += taskarr[taskarr[i].deptks[k]].w;
                check[taskarr[i].deptks[k]] = 1;
            }
        }
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end(), cmptks);
    sort(wsarr + 1, wsarr + 1 + m, cmpws);
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (sizew[j] + arr[i].totw <= wsarr[j].mxw && checkrej(arr[i], wsarr[j].no))
            {
                res += arr[i].totw;
                sizew[j] += arr[i].totw;
                for (int y = 0; y < arr[i].no.size(); y++)
                {
                    inM[arr[i].no[y]] = wsarr[j].no;
                }
                break;
            }
        }
    }
    cout << res;
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << inM[i] << ' ';
}
int main()
{
    ifstream fin;
    fin.open("ta2.in");
    for (int i = 1; i <= n; i++)
    {
        auto *it = taskarr + i;
        fin >> it->no >> it->w;
        int c = 0;
        while (c != -1 && fin >> c)
            if (c != -1)
                it->rejworkstations.push_back(c);
        c = 0;
        while (c != -1 && fin >> c)
            if (c != -1)
                it->rejtks.push_back(c);
        c = 0;
        while (c != -1 && fin >> c)
            if (c != -1)
                it->deptks.push_back(c);
    }
    for (int i = 1; i <= m; i++)
    {
        auto *it = wsarr + i;
        fin >> it->no >> it->mxw;
    }

    for (int i = 0; i <= m; i++)
    {
        inM[1] = i;
        sizew[i] += taskarr[1].w;
        dfs(1, i);
        sizew[i] -= taskarr[1].w;
        inM[1] = 0;
    }
    //greed();
    /*
    for (int i = 0; i < n; i++)
    {
        auto *it = taskarr + i;
        cout << it->no << ' ' << it->w << endl;
        for (auto e : it->rejworkstations)
            cout << e << ' ';
        cout << endl;
        for (auto e : it->rejtks)
            cout << e << ' ';
        cout << endl;
        for (auto e : it->deptks)
            cout << e << ' ';
        cout << endl;
    }
    for (int i = 0; i < m; i++)
    {
        cout << wsarr[i].no << ' ' << wsarr[i].mxw << endl;
    }
    */
    cout << ans.top().first << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << ans.top().second[i] << ' ';
    }
    cout << endl;
}
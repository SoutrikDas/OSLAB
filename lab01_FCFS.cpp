#include <bits/stdc++.h>

using namespace std;

class Process
{
public:
    int pid; //process id
    int at;  //arrival time
    int bt;  //burst time
    int wt;  //waiting time
    int tat; //turn around time
    int ct;  //completion time
    Process()
    {
        pid = -1;
        at = -1;
        bt = 0;
        wt = 0;
        tat = 0;
        ct = 0;
    }
};
bool processCmp(Process p1, Process p2)
{
    // to Sort According to AT
    if (p1.at < p2.at)
        return true;
    if (p1.at == p2.at)
        return p1.pid < p2.pid; //if arrival times are equal compare pid
    return false;
}
void display(vector<Process> &, int);
int main()
{
    int randNum, i = 0;

    int n;
    cout << "Enter no. of processes\n";
    cin >> n;
    vector<Process> v(n, Process());

    cout << "Input , enter one process on one line <Pid> <AT> <BT> \n";
    for (i = 0; i < n; i++)
    {
        cin >> v[i].pid >> v[i].at >> v[i].bt;
    }
    sort(v.begin(), v.end(), processCmp); // to sort acc to AT

    double tsum = 0, wsum = 0;
    v[0].ct = v[0].bt + v[0].at;
    v[0].tat = v[0].ct - v[0].at;
    v[0].wt = v[0].tat - v[0].bt;

    tsum = v[0].tat;
    wsum = v[0].wt;
    for (i = 1; i < n; i++)
    {
        // v[i].ct = v[i - 1].ct >= v[i].at ? v[i - 1].ct : v[i].at + v[i].bt; has problems
        if (v[i - 1].ct > v[i].at)
        {
            v[i].ct = v[i - 1].ct + v[i].bt;
        }
        else
        {
            v[i].ct = v[i].at + v[i].bt;
        }
        v[i].tat = v[i].ct - v[i].at;
        v[i].wt = v[i].tat - v[i].bt;
        tsum += v[i].tat;
        wsum += v[i].wt;
    }
    double tavg = tsum / n;
    double wavg = wsum / n;

    //print
    display(v, n);
    cout << "Tsum = " << tsum << " \t WT sum =" << wsum << endl;
    cout << "Tavg = " << tavg << " \t WT avg =" << wavg;
    return 0;
}

void display(vector<Process> &v, int n)
{
    int i = 0;
    cout << "Pid \t AT \t BT \t CT \t TAT \t WT" << endl;
    for (i = 0; i < n; i++)
    {
        cout << v[i].pid << "\t" << v[i].at << "\t" << v[i].bt << "\t" << v[i].ct << "\t" << v[i].tat << "\t" << v[i].wt << endl;
    }
}
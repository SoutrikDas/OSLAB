// Round Robin
// Criteria : TQ + AT
// Mode : Preemptive
#include <bits/stdc++.h>
using namespace std;
class Process
{
public:
    int pid; //process id
    int at;  //arrival time
    int at2; // copy of at for modification
    int bt;  //burst time
    int wt;  //waiting time
    int tat; //turn around time
    int ct;  //completion time
    int bt2; // copy of bt for modification
    Process()
    {
        pid = -1;
        at = -1;
        at2 = 0; // at2 for sending to the back of queue using at2= clock 
        bt = 0;
        wt = 0;
        tat = 0;
        ct = 0;
        bt2 = 0;
    }
};

bool processCmpAT(Process p1, Process p2)
{
    // to Sort According to AT
    if (p1.at < p2.at)
        return true;
    if (p1.at == p2.at)
        return p1.pid < p2.pid; //if arrival times are equal compare pid
    return false;
}
bool processCmpAT2(Process p1, Process p2)
{
    // to Sort According to AT
    if (p1.at2 < p2.at2)
        return true;
    if (p1.at2 == p2.at2)
        return p1.pid > p2.pid; 
    return false;
}
bool processCmpPid(Process p1, Process p2)
{
    // to Sort According to AT
    if (p1.pid < p2.pid)
        return true;
    return false;
}
bool processCmpBT(Process p1, Process p2)
{
    // to Sort According to AT
    if (p1.bt > p2.bt)
        return true;
    if (p1.bt == p2.bt)
        return p1.pid < p2.pid; //if arrival times are equal compare pid
    return false;
}
bool processCmpBT2(Process p1, Process p2)
{
    // to Sort According to AT
    if (p1.bt2 > p2.bt2)
        return true;
    if (p1.bt2 == p2.bt2)
        return p1.pid < p2.pid; //if arrival times are equal compare pid
    return false;
}
void display(vector<Process> &v, int n)
{
    int i = 0;
    cout << "\nPid \t AT \t BT \t CT \t TAT \t WT \t BT2" << endl;
    for (i = 0; i < n; i++)
    {
        cout << v[i].pid << "\t" << v[i].at << "\t" << v[i].bt << "\t" << v[i].ct << "\t" << v[i].tat << "\t" << v[i].wt << "\t" << v[i].bt2 << endl;
    }
    // cout<<"display end";
}
int main()
{
    int n, i = 0, tq = 0;
    cout << "Enter no. of processes and TQ\n";
    cin >> n >> tq;
    vector<Process> incoming(n, Process());
    vector<Process> ready;
    vector<Process> completed;

    cout << "Input , enter one process on one line <Pid> <AT> <BT> \n";
    for (i = 0; i < n; i++)
    {
        cin >> incoming[i].pid >> incoming[i].at >> incoming[i].bt;
        incoming[i].bt2 = incoming[i].bt;
        incoming[i].at2 = incoming[i].at;
    }
    sort(incoming.begin(), incoming.end(), processCmpAT2);
    // cout << "before while";
    // display( incoming, n );
    int tc = 0; // no of tasks or process completed
    int clock = 0;
    double tsum = 0, wsum = 0;
    // cout << "before while";
    while (completed.size() < n)
    {
        // cout << "\nclock=" << clock << endl;
        for (int j = 0; j < incoming.size(); j++)
        {
            // cout << "inside for outside if";
            // cout << "\nincoming \n";
            // display(incoming, incoming.size());
            if (incoming[j].at <= clock)
            {
                // cout << "inside for if ";
                // erase from incoming , put it into ready for processing
                ready.push_back(incoming[j]);
                incoming.erase(incoming.begin() + j);
                j--;
            }
        }
        sort(ready.begin(), ready.end(), processCmpAT2);
        // display(ready, ready.size());
        // cout << "\nclock=" << clock << endl;
        // display(ready, ready.size());
        if (!ready.empty())
        {
            // ready[0].bt2--;
            if (ready[0].bt2 < tq)
            {
                //completed
                clock += ready[0].bt2;
                ready[0].bt2 = 0;
            }
            else
            {
                //not completed 
                // send to the back of the ready queue ie at = clock

                clock += tq;
                ready[0].bt2 -= tq;
                ready[0].at2 = clock;
            }

            if (ready[0].bt2 == 0)
            {
                // cout << "inside final if";
                ready[0].ct = clock;
                ready[0].tat = ready[0].ct - ready[0].at;
                ready[0].wt = ready[0].tat - ready[0].bt;
                tsum += ready[0].tat;
                wsum += ready[0].wt;
                completed.push_back(ready[0]);
                ready.erase(ready.begin());
            }
        }
        else
        {
            clock++;
        }
        // display(incoming, incoming.size());
        // cout << "just below display";

        // display(ready, ready.size());
        // clock++;
        // cout << "helo";
        // cout << incoming.empty();
    }
    double tavg = tsum / n;
    double wavg = wsum / n;
    sort(completed.begin(), completed.end(), processCmpPid);
    display(completed, n);
    cout << "Tsum = " << tsum << " \t WT sum =" << wsum << endl;
    cout << "Tavg = " << tavg << " \t WT avg =" << wavg;
    return 0;
}

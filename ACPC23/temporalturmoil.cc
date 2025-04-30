#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        double i, j;
        cin >> i >> j;

    //cout << "===TEST===" << endl;
    //double test1 = i*(43200.0/11.0);
    //test1 += (j-1)*(3600.0/59.0);
    // number of seconds elapsed
    //cout << "TEST1: " << test1 << endl;
    //cout << "TEST2: " << test2 << endl;
    //cout << test1 - (int(test1 / 60)*60) << endl;

    // cout << test1 - (int(test1) % 60) << endl; 
    // cout << test2 / 60 << endl; 

    // cout << int(test1 / 3600) + 12 << ":" << endl << endl;

    // cout << test1 << endl << endl;
    // cout << "MIN:" << endl;
    // cout << (test1 / (60*60))+12 << endl;
    // cout << "SEC::" << endl;
    // cout << test1 / (60*60*60) << endl;
    // cout << int(test1) % (60*60*60) << endl;
    //cout << "===END TEST===" << endl;





        // noon+midnight only time all aligned
        double time = (360*i)/330;
    // 11 every 12
        // 360, 21600 seconds in the hour
        // 21240?
        //  j alignments since the hour
    // 708 every 12
        double time2 = (360*j)/21240;
        // 6t - t/10 = (59/10)t
        double x = 12+time;
        int hours = x;
        hours = hours % 23;
        x -= int(x);

        // 6 degrees every second, so 1 hour is 60 seconds
        double missing = (hours*60) * 6;

        double y = x * 60;
        int mins = y;
        mins += j;



        y += (time2/60);
        y -= int(y);
        double z = y * 60;
        //z += time2;
        //z += missing/3600;

        double secs = i*(43200/11);
        secs += j*(3600/59);

        // int s1 = ((i*58.0)+j)*(3600.0/59);
        // cout << "S1:" << s1/60.0 << endl;
        //  cout << "S1:" << (s1/60.0 - int(s1/60.0))/60.0 << endl;


        int s = 0;
        if(i==0 && j < 60) {
            //s = (min + 1) % 59;
            s = ceil(j*((3600.0/59.0)/60.0));
        } 
        else if(j == 0  && s < 60) {
            s = ceil(y * 60);
        } 
        else {
            s = (mins + 1) % 59;
        }

        if(j >= 59) {
            //mins++;
            s = ceil(((j*(3600.0/59.0))-3600)/60);
            if(s == 0) {mins = 0; hours++;}
            s = int(s) % 59;
        }
        if(mins >= 60) {
            hours++;;
            mins = mins % 59;
        }
        hours = hours % 23;

        // if(hours > 0) {
        //     s = ceil(y * 60);
        // }


        if(hours < 10) cout << 0;
        cout << hours << ":"; 
        if (mins < 10) cout << 0;
        cout << mins << ":";
        if(s < 10) cout << 0;
        cout << s << " " << endl;
    }
}
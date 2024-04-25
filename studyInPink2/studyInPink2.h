/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

string notebook1(string ntb1) {
    // Complete this function to gain point
    ifstream n1(ntb1);
    string str,astr;
    stringstream ss;
    ostringstream sn;
    int a;
    getline(n1, str);
    int len = str.length();
    for (int i = 11; i < len; i++) {
        if (str[i] < 48 || str[i]>57) return "000000000";
        else ss<<str[i];
    }
    ss >> a;
    ss.clear();
    if(a==0) return "000000000";
    getline(n1, str);
    n1.close();
    len = a * 2 - 1;
    int b[10] = {};
    for (int i = 0; i < len; i++) {
        switch (str[i]) {
            case '1': {
            b[1]++;
            break;
            }
            case '2': {
                b[2]++;
            break;
            }
            case '3': {
                b[3]++;
            break;
            }
            case '4': {
                b[4]++;
            break;
            }
            case '5': {
                b[5]++;
            break;
            }
            case '6': {
                b[6]++;
            break;
            }
            case '7': {
                b[7]++;
            break;
            }
            case '8': {
                b[8]++;
            break;
            }
            case '9': {
                b[9]++;
            break;
            }
            case '0': {
                b[0]++;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        if (b[i] > 9) b[i] %= 10;
    }
    for (int i = 0; i < 10; i++) {
        sn << b[i];
        astr = sn.str();
    }
    return astr;
}

string notebook2(string ntb2) {
    // Complete this function to gain point
    ifstream n2(ntb2);
    string str;
    stringstream ss;
    getline(n2, str);
    int len = str.length();
    if(len!=5) return "1111111111";
    for (int i = 0; i < 5; i++) {
        if (str[i] < 48 || str[i]>57) return "1111111111";
        else ss << str[i];
    }
    int a;
    ss >> a;
    int b = 0;
    int c = 0;
    int cntP = 0;
    if(a<5||a>100) return "1111111111";
    for (int i = 0; i < a; i++) {
        getline(n2, str);
        len = str.length();
        for (int b = 0; b < len; b++) {
            b = str.find("pink", b);
            if (b != -1) {
                cntP++;
            }
            else break;
        }
        for (int c = 0; c < len; c++) {
            c = str.find("Pink", c);
            if (c != -1) {
                cntP++;
            }
            else break;
        }
    }
    n2.close();
    if (cntP < 10000) cntP *= cntP;
    ostringstream st;
    st << cntP;
    string astr;
    astr = st.str();
    int lena = astr.length();;
    if (lena < 10) {
        for (int i = 0; i < 10 - lena; i++) {
            astr.push_back('9');
        }
    }
    return astr;
}

bool isSNT(int x) {
    if (x < 2) return 0;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
int SNTgannhat(int x) {
    if (x == 1) return 2;
    while (!isSNT(x)) x++;
    return x;
}
bool isFibo(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    int f0 = 1;
    int f1 = 1;
    int fn = 0;
    while (fn < x) {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }
    if (fn == x) return 1;
    return 0;
}
int Fibogannhat(int x) {
    if (x == 0) return 1;
    while (!isFibo(x)) x++;
    return x;
}
string notebook3(string ntb3) {
    // Complete this function to gain point
    int arr[10][10] = {};
    ifstream n3(ntb3);
    int a;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            n3 >> a;
            if (a < 0) a *= (-1);
            arr[i][j] = a;
            if (j < 9) n3.ignore();
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i < j) {
                if (!isSNT(arr[i][j])) arr[i][j] = SNTgannhat(arr[i][j]);
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i > j) {
                if (!isFibo(arr[i][j])) arr[i][j] = Fibogannhat(arr[i][j]);
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        if (arr[i][7] > arr[i][8]) {
            int r = arr[i][7];
            arr[i][7] = arr[i][8];
            arr[i][8] = r;
        }
        if (arr[i][7] > arr[i][9]) {
            int r = arr[i][7];
            arr[i][7] = arr[i][9];
            arr[i][9] = r;
        }
        if (arr[i][8] > arr[i][9]) {
            int r = arr[i][8];
            arr[i][8] = arr[i][9];
            arr[i][9] = r;
        }
    }
    n3.close();
    int count = 0;
    int max = arr[0][0];
    ostringstream ss;
    string s;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if(max<=arr[i][j]) {
                max = arr[i][j];
                count = j;
            }
        }
        ss << count;
    }
    s = ss.str();
    return s;
}
string toHopPass(string s1, string s2) {
    int c = 0;
    ostringstream ss;
    for (int i = 0; i < 10; i++) {
        int num1 = s1[i] - 48;
        int num2 = s2[i] - 48;
        int sum = num1 + num2 + c;
        if (sum > 9) {
            sum -= 10;
            c = 1;
        }
        else c = 0;
        ss << sum;
    }
    string s;
    s = ss.str();
    return s;
}
string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    // Complete this function to gain point
    string a0, a1, a2, a3, a4, a5,a6,a7,a8;
    stringstream ss;
    a0 = pwd1;
    ss << a0;
    ss << ';';
    a1 = pwd2;
    ss << a1;
    ss << ';';
    a2 = pwd3;
    ss << a2;
    ss << ';';
    a3 = toHopPass(pwd1, pwd2);
    ss << a3;
    ss << ';';
    a4 = toHopPass(pwd1, pwd3);
    ss << a4;
    ss << ';';
    a5 = toHopPass(pwd2, pwd3);
    ss << a5;
    ss << ';';
    a6 = toHopPass(a3, pwd3);
    ss << a6;
    ss << ';';
    a7 = toHopPass(pwd1, a5);
    ss << a7;
    ss << ';';
    a8 = toHopPass(a3, a4);
    ss << a8;
    string s;
    ss >> s;
    return s;
}

bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string & outTimes,
    string & outCatchUps
) {
    // Complete this function to gain point
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            arr[i][j] = -9;
        }
    }
    int m = 0;
    int n = 0;
    arr[m][n] = 0;
    for (int t = 0; moves[t]!='\0'; t++) {
        if (moves[t] == 'R') {
            if (n == 99) continue;
            arr[m][n + 1] = arr[m][n] + 9;
            n++;
        }
        if (moves[t] == 'U') {
            if (m == 0) continue;
            else arr[m - 1][n] = arr[m][n] + 9;
            m--;
        }
        if (moves[t] == 'D') {
            if (m == 99) continue;
            else arr[m + 1][n] = arr[m][n] + 9;
            m++;
        }
        if (moves[t] == 'L') {
            if (m == 0) continue;
            else arr[m][n - 1] = arr[m][n] + 9;
            n--;
        }
    }
    stringstream st,si, sj,sc;
    int x0 = 0;
    int y0 = 0;
    int x1 = 0;
    int y1 = 0;
    int d = 0;
    int time = 0;
    for (int i = 0; points[i] != '\0'; i++) {
        if (points[i] == 40) {
            if (points[i + 2] != 44) {
                si << points[i + 1];
                si << points[i + 2];
                si >> x1;
                si.clear();
            }
            else {
                si << points[i + 1];
                si >> x1;
                si.clear();
            }
        }
        if (points[i] == 44) {
            if (points[i + 2] != 41) {
                sj << points[i + 1];
                sj << points[i + 2];
                sj >> y1;
                sj.clear();
            }
            else {
                sj << points[i + 1];
                sj >> y1;
                sj.clear();
            }
        }
        if (points[i] == 41) {
            d = abs(x1 - x0) + abs(y1 - y0);
            time = time + d * 14;
            if (time <= arr[x1][y1]) {
                sc << "Y;";
                st << time;
                st << '.';
            }
            else {
                sc << "N;";
                st << time;
                st << ';';
            }
            x0 = x1;
            y0 = y1;
        }
    }
    st >> outTimes;
    sc >> outCatchUps;
    int lent = outTimes.length();
    int lenc = outCatchUps.length();
    outCatchUps.erase(lenc - 1, 1);
    outTimes.erase(lent - 1, 1);
    lent = outTimes.length();
    lenc = outCatchUps.length();
    for (int i = 1; outCatchUps[i] != '\0'; i++) {
        if (outCatchUps[i] == ';' && (outCatchUps[i - 1] == 'Y' || outCatchUps[i - 1] == '-')) {
            outCatchUps[i + 1] = '-';
        }
    }
    string rpl = outCatchUps;
    int vt1 = 0;
    for (int i = 0; rpl[i] != '\0'; i++) {
        if (rpl[i] == 'Y') {
            rpl.erase(0, i + 1);
            vt1 = i - 1;
        }
    }
    int find0 = 0;
    int vt2 = 0;
    for (int i = 0; outTimes[i] != '\0'; i++) {
        find0 = outTimes.find(';', find0 + 1);
        vt2++;
        if (vt2 == vt1) outTimes.replace(find0, lent, rpl);
    }
    for (int i = 0; outCatchUps[i] != '\0'; i++) {
        if (outCatchUps[i] == 'Y') {
            return 1;
        }
    }
    return false;
}

string enterLaptop(string tag, string message) {
    // Complete this function to gain point
    string str;
    int n3;
    ifstream tg(tag);
    tg >> str;
    tg >> str;
    stringstream ss;
    ss << str;
    ss << ';';
    tg >> str;
    tg >> n3;
    tg.close();
    string pwdL;
    for (int i = 0; i < n3; i++) {
        pwdL += message;
    }
    ss << pwdL;
    string r;
    ss >> r;
    return r;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */

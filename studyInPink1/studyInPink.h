/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

int firstMeet(int& EXP1, int& EXP2, const int& E1) {
    //Complete this function to gain point on task 1
    //TH1
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 900) EXP1 = 900;
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 900) EXP2 = 900;
    int xp1 = EXP1;
    int xp2 = EXP2;
    if (E1 <= 399 && E1 >= 0) {
        {if (E1 >= 0 && E1 <= 49) EXP2 = EXP2 + 25;
        else if (E1 >= 50 && E1 <= 99) EXP2 = EXP2 + 50;
        else if (E1 >= 100 && E1 <= 149) EXP2 = EXP2 + 85;
        else if (E1 >= 150 && E1 <= 199) EXP2 = EXP2 + 25 + 50;
        else if (E1 >= 200 && E1 <= 249) EXP2 = EXP2 + 25 + 85;
        else if (E1 >= 250 && E1 <= 299) EXP2 = EXP2 + 50 + 85;
        else if (E1 >= 300 && E1 <= 399) EXP2 = EXP2 + 25 + 50 + 85;
        }
        {if (E1 % 2 == 1) EXP1 = ceil(EXP1 + E1 * 0.1);
        else EXP1 = ceil(EXP1 - E1 * 0.2); }
    }
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 900) EXP1 = 900;
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 900) EXP2 = 900;
    //TH2
    if (E1 >= 400 && E1 <= 999) {
        if (E1 >= 400 && E1 <= 499) EXP2 = ceil(EXP2 + E1 / 7.00 + 9);
        else if (E1 >= 500 && E1 <= 599) EXP2 = ceil(EXP2 + E1 / 9.00 + 11);
        else if (E1 >= 600 && E1 <= 699) EXP2 = ceil(EXP2 + E1 * 0.2 + 6);
        else if (E1 >= 700 && E1 <= 799) {
            EXP2 = ceil(EXP2 + E1 / 7.00 + 9);
            if (EXP2 > 200) EXP2 = ceil(EXP2 + E1 / 9.00 + 11);
        }
        else if (E1 >= 800 && E1 <= 999) {
            EXP2 = ceil(EXP2 + E1 / 7.00 + 9);
            EXP2 = ceil(EXP2 + E1 / 9.00 + 11);
            if (EXP2 > 600) {
                EXP2 = ceil(EXP2 + E1 * 0.2 + 6);
                EXP2 = ceil(1.15 * EXP2);
            }
        }
        EXP1 = ceil(EXP1 - 0.1 * E1);
    }
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 900) EXP1 = 900;
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 900) EXP2 = 900;
    if (E1 < 0 || E1>999) {
        EXP1 = xp1;
        EXP2 = xp2;
    }
    int output = EXP1 + EXP2;
    if (E1 < 0 || E1>999) return -999;
    else return output;
}

int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2) {
    //Complete this function to gain point on task 2
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 900) EXP1 = 900;
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 900) EXP2 = 900;
    if (HP2 < 0) HP2 = 0;
    if (HP2 > 999) HP2 = 999;
    if (M2 < 0) M2 = 0;
    if (M2 > 2000) M2 = 2000;
    int hp = HP2;
    int xp1 = EXP1;
    int xp2 = EXP2;
    int m2 = M2;
    double d, d1, d2;
    d1 = E2 / 9.00 + 10;
    d2 = 0.35 * E2;
    d = 0.17 * (d1 + d2);
    //GD1
    if (E2 >= 0 && E2 <= 299) {
        EXP2 = ceil(EXP2 + d1);
        EXP1 = ceil(EXP1 + d1 / 3.00);
    }
    else if (E2 >= 300 && E2 <= 499) {
        EXP2 = ceil(EXP2 + d1);
        EXP1 = ceil(EXP1 + d1 / 3.00);
        EXP2 = ceil(EXP2 + d2);
        EXP1 = ceil(EXP1 + d2 / 3.00);
    }
    else if (E2 >= 500 && E2 <= 999) {
        EXP2 = ceil(EXP2 + d1);
        EXP1 = ceil(EXP1 + d1 / 3.00);
        EXP2 = ceil(EXP2 + d2);
        EXP1 = ceil(EXP1 + d2 / 3.00);
        EXP2 = ceil(EXP2 + d);
        EXP1 = ceil(EXP1 + d / 3.00);
    }
    //GD2
    if (E2 < 0 || E2>999) {
        HP2 = hp;
        EXP1 = xp1;
        EXP2 = xp2;
        M2 = m2;
    }
    else HP2 = ceil(HP2 - pow(E2, 3) / pow(2, 23));
    if (E2 % 2 == 0) M2 = ceil(M2 + E2 * E2 * 0.02);
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 900) EXP1 = 900;
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 900) EXP2 = 900;
    if (HP2 < 0) HP2 = 0;
    if (HP2 > 999) HP2 = 999;
    if (M2 < 0) M2 = 0;
    if (M2 > 2000) M2 = 2000;
    int output = EXP2 + HP2 + M2 + EXP1;
    if (E2 < 0 || E2>999) return -999;
    else return output;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3) {
    //Complete this function to gain point on task 3
    int P1[9] = {}, P2[7] = { 2,3,5,7,11,13,17 }, P3[20] = {}, P4[12] = {};
    int i, j, k;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 900) EXP1 = 900;
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 999) HP1 = 999;
    if (M1 < 0) M1 = 0;
    if (M1 > 2000) M1 = 2000;
    int hp = HP1;
    int xp = EXP1;
    int m1 = M1;
    int m0 = M1;
    //STREET1
    for (i = 0, j = 1; i < 9 && j < 19; i++, j = j + 2) {
        P1[i] = j;
    }
    for (i = 0; i < 9; i++) {
        P1[i] = (P1[i] + E3) % 26 + 65;
    }
    for (i = 0; i < 9; i++) {
        M1 = m1;
        if (P1[i] == 80) {
            k = i + 1;
            HP1 = HP1 - P1[i] * k * 2;
            EXP1 = EXP1 + (1000 - P1[i] * k) % 101;
            M1 = ceil(M1 - k * E3 / 9.00);
            break;
        }
        else {
            M1 = ceil(M1 - 9 * 9 * E3 / 9.00);
            continue;
        }
    }
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 900) EXP1 = 900;
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 999) HP1 = 999;
    if (M1 < 0) M1 = 0;
    if (M1 > 2000) M1 = 2000;
    m1 = M1;
    //STREET2
    int s = 0;
    int m = 0;
    for (i = 0; i < 7; i++) {
        P2[i] = (P2[i] + E3) % 26;
        s = s + P2[i];
    }
    m = ceil(s / 7.00);
    for (i = 0; i < 7; i++) {
        P2[i] = (P2[i] + s + m) % 26 + 65;
    }
    for (i = 0; i < 7; i++) {
        M1 = m1;
        if (P2[i] == 80) {
            k = i + 1;
            HP1 = HP1 - P2[i] * k * 2;
            EXP1 = EXP1 + (1000 - P2[i] * k) % 101;
            M1 = ceil(M1 - k * E3 / 9.00);
            break;
        }
        else {
            M1 = ceil(M1 - 7 * 7 * E3 / 9.00);
            continue;
        }
    }
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 900) EXP1 = 900;
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 999) HP1 = 999;
    if (M1 < 0) M1 = 0;
    if (M1 > 2000) M1 = 2000;
    m1 = M1;
    //STREET3
    int x, max;
    for (i = 0, j = 2; i < 20 && j < 41; i++, j = j + 2) {
        P3[i] = j * j;
    }
    for (i = 0; i < 20; i++) {
        P3[i] = (P3[i] + E3 * E3) % 113;
    }
    max = P3[0];
    for (i = 0; i < 20; i++) {
        if (max < P3[i]) { max = P3[i]; }
    }
    for (i = 0; i < 20; i++) {
        double b = (((double)P3[i] + E3) / max);
        P3[i] = ceil(b);
        P3[i] = P3[i] % 26 + 65;
    }
    for (i = 19; i >= 0; i--) {
        M1 = m1;
        if (P3[i] == 80) {
            k = 20 - i;
            HP1 = HP1 - P3[i] * k * 3;
            EXP1 = EXP1 + (3500 - P3[i] * k) % 300;
            M1 = ceil(M1 - k * E3 / 9.00);
            break;
        }
        else {
            M1 = ceil(M1 - 20 * 20 * E3 / 9.00);
            continue;
        }
    }
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 900) EXP1 = 900;
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 999) HP1 = 999;
    if (M1 < 0) M1 = 0;
    if (M1 > 2000) M1 = 2000;
    m1 = M1;
    //STREET4
    for (i = 0; i < 12; i++) {
        switch (i) {
        case 0: P4[i] = 31;
            break;
        case 2: P4[i] = 31;
            break;
        case 4: P4[i] = 31;
            break;
        case 6: P4[i] = 31;
            break;
        case 7: P4[i] = 31;
            break;
        case 9: P4[i] = 31;
            break;
        case 11: P4[i] = 31;
            break;
        case 3: P4[i] = 30;
            break;
        case 5: P4[i] = 30;
            break;
        case 8: P4[i] = 30;
            break;
        case 10: P4[i] = 30;
            break;
        default: P4[1] = 28;
        }
    }
    for (i = 0; i < 12; i++) {
        double b = pow(E3 / 29.00, 3);
        P4[i] += ceil(b);
        P4[i] = P4[i] % 9;
    }
    double min = P4[0];
    int min_idx = 1;
    for (i = 0; i < 12; i++) {
        if (min > P4[i]) {
            min = P4[i];
            min_idx++;
        }
    }
    int c = ceil(min / min_idx);
    for (i = 0; i < 12; i++) {
        P4[i] = ((P4[i] + E3) * c) % 26 + 65;
    }
    for (i = 11; i >= 0; i--) {
        M1 = m1;
        if (P4[i] == 80) {
            k = 12 - i;
            HP1 = HP1 - P4[i] * k * 4;
            EXP1 = EXP1 + (4500 - P4[i] * k) % 400;
            M1 = ceil(M1 - k * E3 / 9.00);
            break;
        }
        else {
            M1 = ceil(M1 - 12 * 12 * E3 / 9.00);
            continue;
        }
    }
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 900) EXP1 = 900;
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 999) HP1 = 999;
    if (M1 < 0) M1 = 0;
    if (M1 > 2000) M1 = 2000;
    m1 = M1;
    if (E3 < 0 || E3>999) {
        M1 = m0;
        HP1 = hp;
        EXP1 = xp;
    }
    else M1 = m1;
    int output3 = HP1 + EXP1 + M1;
    if (E3 < 0 || E3>999)  return -999;
    else {
        if (HP1 = hp && EXP1 == xp) {
            HP1 = HP1 - (59 * E3) % 900;
            EXP1 = EXP1 - (79 * E3) % 300;
            return -1;
        }
        else return output3;

    }
}
////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */

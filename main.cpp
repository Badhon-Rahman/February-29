#include <iostream>
#include <sstream>

using namespace std;

int CounLeapYear(string fMonth, string sMonth, int fYear, int sYear, int sDay, int coun){
    if((fMonth == "January") && (fMonth != "")){
        fMonth = "";
        return CounLeapYear(fMonth, sMonth, fYear, sYear, sDay, coun);
    }
     if((fMonth == "February") && (fMonth != "")){
        fMonth = "";
        return CounLeapYear(fMonth, sMonth, fYear, sYear, sDay, coun);
    }
    if((fMonth != "January" || fMonth != "February") && (fMonth != "")){
        fMonth = "";
        fYear += 1;
        return CounLeapYear(fMonth, sMonth, fYear, sYear, sDay, coun);
    }
    if(sMonth == "February" && sDay > 28){
        sMonth = "";
        return CounLeapYear(fMonth, sMonth, fYear, sYear, sDay, coun);
    }
    if((sMonth == "January" || sMonth == "February") && (sMonth != "")){
        sMonth = "";
        sYear -= 1;
        return CounLeapYear(fMonth, sMonth, fYear, sYear, sDay, coun);
    }
    else{
    if(fYear <= sYear){
     if(fYear % 4 == 0){
        if(fYear % 100 == 0){
            if(fYear % 400 == 0){
                coun++;
            }
        }
        else{
            coun++;
        }
     }
     return CounLeapYear(fMonth, sMonth, fYear + 1, sYear, sDay, coun);
    }
    else{
        return coun;
    }
    }
}

int SplitYear(string strF, string strS, int fSize, int sSize){
     string sMonth = "", eMonth = "", sYear = "", eYear = "", sDay = "";
     int len1 = 0, len2 = 0;
       while(strF[len1] != ' '){
          sMonth.push_back(strF[len1]);
          len1++;
       }
       len1++;
       while(strS[len2] != ' '){
        eMonth.push_back(strS[len2]);
        len2++;
       }
       len2++;
       while(strF[len1] != ' '){
        len1++;
       }
       len1++;
       while(strS[len2] != ','){
        sDay.push_back(strS[len2]);
        len2++;
       }
       len2 += 2;
       while(len1 <= fSize){
          sYear.push_back(strF[len1]);
          len1++;
       }
       while(len2 <= sSize){
        eYear.push_back(strS[len2]);
        len2++;
       }

       stringstream convFD(sYear);
       stringstream convSD(eYear);
       stringstream convSDay(sDay);
       int firstYear = 0;
       int secondYear = 0;
       int secondDay = 0;
       convFD >> firstYear;
       convSD >> secondYear;
       convSDay >> secondDay;
       int numberOfLeapYeay = CounLeapYear(sMonth, eMonth, firstYear, secondYear, secondDay, 0);
       return numberOfLeapYeay;
}

int main()
{
    string firstDate, secondDate;
    string firstDay = "", firstMonth = "", firstYear = "";
    string secondDay = "", secondMonth = "", secondYear = "";
    int caseNumber, i = 0, fSize, sSize;
    cout << "Enter First Date: ";
    getline(cin, firstDate);
    cout << "Enter second date: ";
    getline(cin, secondDate);
    fSize = firstDate.length();
    sSize = secondDate.length();
    int l = SplitYear(firstDate, secondDate, fSize, sSize);
    cout << l << endl;
    return 0;
}

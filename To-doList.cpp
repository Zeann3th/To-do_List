#include<bits/stdc++.h>
using namespace std;
// Những biến toàn cục
int dem = 0;
vector<string> a;
// Function
void addToList() {
    cout << "Describe your activity" << endl;
    dem++;
    string s;
    cin.clear();
    cin.sync();
    getline(cin , s);
    a.push_back(s);
}
void deleteFromList() {
        int choice;
        cout << "Select an activity to delete from the list" << endl;
        cout << "(If you wish to exit, please enter 0)" << endl;
        cin >> choice;
        while  (choice > dem) {
            cout << "Please enter an appropriate number: " << endl;
            cin >> choice;
        }
        // deleteFile();
        a.erase(a.begin()+choice-1);
        dem--;
}
fstream myLog;
void Save() {
    myLog.open ("Log.txt", ios::out);
    if (myLog.fail()) {
        cout << "No Log file" << endl;
    }
    else {
        for (int i = 0; i < a.size(); i++) {
            myLog << a[i] << endl;
        }
        myLog.close();
    }
}
void loadDataFile() { // Vẫn chưa hoạt động
    myLog.open("Log.txt", ios::in);
    if (myLog.fail()) {
        cout << "No Log file" << endl;
    }
    else {
        string b;
        while(getline(myLog, b)) {
            cout << b << endl;
            dem++;
        }
        myLog.close();
    }
}
// Main ??
int main() {
    int flag = 1; // Quyết định file dừng hay đóng
    int choice;
    do {
        system("cls"); // Reset lại màn hình
        cout << "--------------------To-do List--------------------" << endl;
        if (dem == 0) {
        cout << "----------------------(EMPTY)---------------------" << endl;
        cout << endl;
        }
        else {
            for (int i = 0; i < dem; i++) {
                cout << i+1 << ". " << a[i] << endl;
            }
            cout << "--------------------------------------------------" << endl; 
        }
        cout << "1. Add an activity" << endl;
        cout << "2. Delete an activity" << endl;
        cout << "3. Load data from existing file" << endl;
        cout << "4. Save" << endl; 
        cout << "5. Exit" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                addToList();
                break;
            case 2:
                deleteFromList();
                break;
            case 3:
                loadDataFile();
                break;
            case 4:
                Save();
                break;
            case 5:
                flag = 0; //Exit();
                break;
            default: // Vẫn đang lỗi khi nhập chữ, số thập phân, nhập từ 0-9 thì không bị lỗi
                cout << "Please enter a number from 1-5" << endl;
                system("pause");
                break;
        }
    } while (flag == 1);
    return 0;
}
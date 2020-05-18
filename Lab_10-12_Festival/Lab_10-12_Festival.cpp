#include <iostream>
#include <string>
#include <vector>
#include "Exceptions.h"
#include "ValidationMovie.h"
#include "ValidationArtist.h"
#include "Repo.h"
#include "RepoCSV.h"
#include "RepoTXT.h"
#include "Service.h"
#include "Tests.h"
#include "UI.h"

using namespace std;

int main(){
    TestMovie();
    TestArtist();
    TestUser();
    ValidationShow* ValidateS = new ValidationShow();
    Repo* CSV = new RepoCSV("TestObjects.csv", ValidateS);
    Repo* TXT = new RepoTXT("TestObjects.txt", ValidateS);
    TestRepo(CSV);
    TestRepo(TXT);
    TestService(CSV);
    TestService(TXT);
    Exceptions Exception();
    ValidationShow* ValidateM = new ValidationMovie();
    ValidationShow* ValidateA = new ValidationArtist();
    Repo* R;
    cout << endl;
    cout << "Insert 1 for CSV files and 2 for TXT files : ";
    int cmd;
    cin >> cmd;
    if (cmd == 2) {
        R = new RepoTXT("Objects.txt", ValidateS);
        Service S(R, ValidateS);
        UI UI(S);
        UI.RunLogin();
    }
    if (cmd == 1) {
        R = new RepoCSV("Objects.csv", ValidateS);
        Service S(R, ValidateS);
        UI UI(S);
        UI.RunLogin();
    }
    else {
        cout << endl;
        cout << "Non-existent command!" << endl;
    }
    delete ValidateA;
    delete ValidateM;
    return 0;

}

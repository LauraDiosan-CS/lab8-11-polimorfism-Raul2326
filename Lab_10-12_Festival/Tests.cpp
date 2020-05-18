#include "Tests.h"

void TestMovie() {
	string name1 = "Home_Alone";
	string name2 = "Dracula_Untold";
	string name3 = "Jumanji";
	vector<string>actors1 = { "Klaus" };
	vector<string>actors2 = { "Elijah" };
	vector<string>actors3 = { "Rebekah" };
	string date1 = "1";
	string date2 = "2";
	string date3 = "3";
	string location1 = "1";
	string location2 = "2";
	string location3 = "3";
	string time1 = "1";
	string time2 = "2";
	string time3 = "3";

	Movie m1(name1, actors1, date1, location1, time1, 100, 100);
	Movie m2(name2, actors2, date2, location2, time2, 200, 200);
	m2.setName(name3);
	m2.setActors(actors3);
	m2.setDate(date3);
	m2.setLocation(location3);
	m2.setTime(time3);
	m2.setAva_places(300);
	m2.setSold_places(300);

	assert(m1.getName().compare(name1) == 0);
	assert(m1.getActors() == actors1);
	assert(m1.getDate().compare(date1) == 0);
	assert(m1.getLocation().compare(location1) == 0);
	assert(m1.getTime().compare(time1) == 0);
	assert(m1.getAva_places() == 100);
	assert(m1.getSold_places() == 100);

	assert(m2.getName().compare(name3) == 0);
	assert(m2.getActors() == actors3);
	assert(m2.getDate().compare(date3) == 0);
	assert(m2.getLocation().compare(location3) == 0);
	assert(m2.getTime().compare(time3) == 0);
	assert(m2.getAva_places() == 300);
	assert(m2.getSold_places() == 300);
}

void TestArtist() {
	string name1 = "Martin_Garrix";
	string name2 = "Kygo";
	string name3 = "Alan_Walker";
	string date1 = "1";
	string date2 = "2";
	string date3 = "3";
	string location1 = "1";
	string location2 = "2";
	string location3 = "3";
	string time1 = "1";
	string time2 = "2";
	string time3 = "3";

	Artist a1(name1, date1, location1, time1, 100, 100);
	Artist a2(name2, date2, location2, time2, 200, 200);
	a2.setName(name3);
	a2.setDate(date3);
	a2.setLocation(location3);
	a2.setTime(time3);
	a2.setAva_places(300);
	a2.setSold_places(300);

	assert(a1.getName().compare(name1) == 0);
	assert(a1.getDate().compare(date1) == 0);
	assert(a1.getLocation().compare(location1) == 0);
	assert(a1.getTime().compare(time1) == 0);
	assert(a1.getAva_places() == 100);
	assert(a1.getSold_places() == 100);

	assert(a2.getName().compare(name3) == 0);
	assert(a2.getDate().compare(date3) == 0);
	assert(a2.getLocation().compare(location3) == 0);
	assert(a2.getTime().compare(time3) == 0);
	assert(a2.getAva_places() == 300);
	assert(a2.getSold_places() == 300);
}

void TestUser() {
	string name1 = "Alex";
	string name2 = "Vlad";
	string name3 = "George";
	string password1 = "1234";
	string password2 = "0000";
	string passwors3 = "1111";

	User u1(name1, password1);
	User u2(name2, password2);
	u2.setName(name3);
	u2.setPassword(passwors3);

	assert(u1.getName().compare(name1) == 0);
	assert(u1.getPassword().compare(password1) == 0);

	assert(u2.getName().compare(name3) == 0);
	assert(u2.getPassword().compare(passwors3) == 0);
}

void TestRepo(Repo* R) {
	string mname1 = "mname1";
	string mname2 = "mname2";
	string mname3 = "mname3";

	string mdate1 = "mdate1";
	string mdate2 = "mdate2";
	string mdate3 = "mdate3";

	string mtime1 = "mtime1";
	string mtime2 = "mtime1";
	string mtime3 = "mtime1";

	string mlocation1 = "mlocation1";
	string mlocation2 = "mlocation1";
	string mlocation3 = "mlocation1";

	vector<string>actors1 = { "actord1" };
	vector<string>actors2 = { "actord2" };
	vector<string>actors3 = { "actord3" };

	string uname1 = "uname1";
	string uname2 = "uname2";
	string uname3 = "uname3";

	string upassword1 = "upassword1";
	string upassword2 = "upassword2";
	string upassword3 = "upassword3";

	Movie* m1 = new Movie(mname1, actors1, mdate1, mtime1, mlocation1, 1, 1);
	Movie* m2 = new Movie(mname2, actors2, mdate2, mtime2, mlocation2, 2, 2);
	Movie* m3 = new Movie(mname3, actors3, mdate3, mtime3, mlocation3, 3, 3);

	User* u1 = new User(uname1, upassword1);
	User* u2 = new User(uname2, upassword2);
	User* u3 = new User(uname3, upassword3);

	R->AddS(m1);
	R->AddS(m2);
	R->AddS(m3);

	R->AddU(u1);
	R->AddU(u2);
	R->AddU(u3);

	R->UpdateS(m2, m3);
	R->UpdateU(u2, u3);

	R->DeleteS(m3);
	R->DeleteU(u3);

	assert(R->getSizeS() == 4);
	assert(R->getSizeU() == 3);

	assert(*(R->getShow(2)) == *m1);
	assert(*(R->getShow(3)) == *m3);
	assert(*(R->getUser(1)) == *u1);
	assert(*(R->getUser(2)) == *u3);

	R->DeleteS(m1);
	R->DeleteS(m3);
	R->DeleteU(u1);
	R->DeleteU(u3);
}

void TestService(Repo* R) {
	string mname = "Madagascar";
	string mdate = "18.08.2000";
	string mtime = "15:30";
	string mlocation = "PolulNord";

	string aname = "Picasso";
	string adate = "15.09.1500";
	string atime = "13:13";
	string alocation = "Venezuela";

	string uname1 = "Iuzar";
	string uname2 = "Mike";

	string upassword1 = "asta";
	string upassword2 = "4321";

	vector<string>mactors = { "Flaviu" };

	ValidationShow* ValidateS = new ValidationShow();
	Service S(R, ValidateS);
	Movie* m = new Movie(mname, mactors, mdate, mtime, mlocation, 10, 10);
	Artist* a = new Artist(aname, adate, atime, alocation, 1000, 0);
	User* u1 = new User(uname1, upassword1);
	User* u2 = new User(uname2, upassword2);

	assert(*(S.getShows()[0]) == *m);
	assert(*(S.getShows()[1]) == *a);
	assert(S.LogIn(uname1, upassword1) == 0);
	assert(S.LogIn(uname2, upassword2) == -1);
	assert(S.CreateAccount(uname1, upassword1) == -1);
	assert(S.CreateAccount(uname2, upassword2) == 0);

	R->DeleteU(u2);
}
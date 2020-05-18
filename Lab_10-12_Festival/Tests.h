#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include "Movie.h"
#include "Artist.h"
#include "Repo.h"
#include "RepoCSV.h"
#include "RepoTXT.h"
#include "User.h"
#include "Service.h"
#include "ValidationException.h"
#include "Exceptions.h"

void TestMovie();
void TestArtist();
void TestUser();
void TestRepo(Repo* R);
void TestService(Repo* R);
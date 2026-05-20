/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <random>
#include <sstream>

std::string kYourName = "Deyue Li"; // Don't forget to change this!

std::string get_initial(const std::string& name) {
  std::string ret;
  std::stringstream ss(name);
  std::string word;
  while (ss >> word) {
    ret += toupper(word[0]);
  }
  return ret;
}

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::set<std::string> names;

  std::ifstream ifile(filename);

  if (!ifile.is_open()) {
    std::cerr << "Fail to open file\n";
    return {};
  }

  std::string name;
  while (getline(ifile, name)) {
    if (name != "") {
      names.insert(name);
    }
  }

  return names;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> ret;
  std::string my_initial = get_initial(kYourName);

  for (const std::string& stu : students) {
    if (get_initial(stu) == my_initial) {
      ret.push(&stu);
    }
  }
  return ret;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  if (matches.empty()) {
    return "NO MATCHES FOUND.";
  }

  std::random_device r;
  std::default_random_engine e(r());

  std::uniform_int_distribution<> dis(0, matches.size()-1);

  int random_id = dis(e);

  std::string match;

  for (int i = 0; i < random_id; i++) {
    matches.pop();
  }
  const std::string* m = matches.front();
  match = *m;
  return match;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"

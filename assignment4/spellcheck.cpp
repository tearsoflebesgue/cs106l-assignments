#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  /* TODO: Implement this method */
  Corpus result;

  auto space_iters = find_all(source.begin(), source.end(), [](int ch){return std::isspace(ch);});

  std::transform(space_iters.begin(), space_iters.end() - 1, 
                space_iters.begin() + 1,
                std::inserter(result, result.end()),
              [&source](auto left, auto right) {
                return Token {source, left, right};
              });

  std::erase_if(result, [](Token t) {return t.content.empty();});
  return result;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  namespace rv = std::ranges::views;
  auto view = source
            | rv::filter([&dictionary](Token t){return !dictionary.contains(t.content);})
            | rv::transform([&dictionary](Token t) {
                auto view = dictionary | rv::filter([&t](std::string s){return levenshtein(t.content, s) == 1;});
                std::set<std::string> suggestions(view.begin(), view.end());
                return Misspelling { t, suggestions };
            })
            | rv::filter([](Misspelling m){
              return !m.suggestions.empty();
            });


  // auto view = std::ranges::views::filter(source, [&dictionary](Token t){return dictionary.contains(t.content);});

  return std::set<Misspelling>(view.begin(),view.end());
};

/* Helper methods */

#include "utils.cpp"
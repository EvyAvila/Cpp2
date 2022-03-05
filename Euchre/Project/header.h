
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <functional>
#include <map>
#include <algorithm>
#include <ostream>
#include <utility>

enum Suits {Heart, Diamond, Spade, Club, empty};
enum Names {Jack, Ace, Queen, King};

struct TheCard;
struct TheDeck;

class ThePlayer;
class GetTrumpCard;

double Team1Points;
double Team2Points;


std::string EachRoundResult();

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

enum TheTeam {Team1, Team2};
enum Suits {Heart, Diamond, Spade, Club, empty};
enum Names {Jack, Ace, Queen, King};

struct TheCard;
struct TheDeck;

class ThePlayer;
class GetTrumpCard;

int Team1Points;
int Team2Points;

bool Changevalue(ThePlayer *tp);

TheTeam team();

std::string FinalRoundResult(TheTeam rr);


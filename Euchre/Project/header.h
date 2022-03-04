#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>

enum RoundResult {Win, Lose};
enum Suits {Heart, Diamond, Spade, Club};
enum Name {Ace, Jack, Queen, King};

struct TheCard;
struct TheDeck;

class ThePlayers;

class ComparingAnswerKey;

int Team1Points;
int Team2Points;

bool Changevalue(ThePlayers *tp);

RoundResult TheRouldResult();

std::string FinalRoundResult(RoundResult rr);
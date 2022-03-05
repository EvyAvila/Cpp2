#include "header.h"
#include <string>
#include <iostream>

struct TheCard
{
    public:
        int CardValue;
        Suits Suit;
        Names Name;

        TheCard(int value, Suits suit)
        {
            //Cards for normal numbers with suit - heart, diamond, etc
            CardValue = value;
            Suit = suit;
        }

        TheCard(int value, Suits suit, Names name)
        {
            //Cards with special names: Jack, Ace, etc
            CardValue = value;
            Suit = suit;
            Name = name;
        }
};

struct TheDeck
{
    public:
        std::vector<TheCard> TheCardDeck = std::vector<TheCard>();
        //24 cards total
        // 9 - 9, 10 - 10, Queen - 11, King - 12, Ace - 13, Jack - 14

       TheDeck()
       {
            for(int theSuit = 0; theSuit < 4; theSuit++)
            {
                for(int cardValue = 9; cardValue <= 14; cardValue++)
                {
                    if(cardValue == 11)
                    {
                        TheCardDeck.push_back(std::move(TheCard(cardValue, (Suits)theSuit, (Names)2)));
                    }
                    else if(cardValue == 12)
                    {
                        TheCardDeck.push_back(std::move(TheCard(cardValue, (Suits)theSuit, (Names)3)));
                    }
                    else if(cardValue == 13)
                    {
                        TheCardDeck.push_back(std::move(TheCard(cardValue, (Suits)theSuit, (Names)1)));
                    }
                    else if(cardValue == 14)
                    {
                        TheCardDeck.push_back(std::move(TheCard(cardValue, (Suits)theSuit, (Names)0)));
                    }
                    else
                    {
                        TheCardDeck.push_back(std::move(TheCard(cardValue, (Suits)theSuit)));
                    } 
                }
            }
       }

       void ShuffleTheDeck()
       {
            auto seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::shuffle(TheCardDeck.begin(), TheCardDeck.end(), std::default_random_engine(seed));
       }

       TheCard DealingCard()
       {
          TheCard dealing = TheCardDeck.back();
          TheCardDeck.pop_back();
          return std::move(dealing);
       }
};

class ThePlayer
{
    public:
        std::vector<TheCard> playerHand;

        ThePlayer()
        {
            playerHand = std::vector<TheCard>();
        }

        int LookAtHand()
        {
            int theCardAmount = 0;

            for(std::vector<TheCard>::iterator totalAmount = playerHand.begin(); totalAmount != playerHand.end(); totalAmount++)
            {
                theCardAmount += totalAmount->CardValue;
            }

            return theCardAmount;
        }
};

class GetTrumpCard
{
    public:
        Suits TrumpCard;

        GetTrumpCard()
        {
            TrumpCard = Suits(rand() % empty);

        }
};


std::string EachRoundResult()
{
    TheDeck td = TheDeck();
    td.ShuffleTheDeck();
   
    
    ThePlayer *Maker1 = new ThePlayer();
    ThePlayer *Maker2 = new ThePlayer();
    ThePlayer *Defender1 = new ThePlayer();
    ThePlayer *Defender2 = new ThePlayer();

    GetTrumpCard gtc = GetTrumpCard();
    gtc.TrumpCard;

    for(int i = 0; i < 6; i++)
    {
        Maker1->playerHand.push_back(td.DealingCard());
        Defender1->playerHand.push_back(td.DealingCard());
        Maker2->playerHand.push_back(td.DealingCard());
        Defender2->playerHand.push_back(td.DealingCard());
    }

    for(int i = 0; i < Maker1->LookAtHand(); i++)
    {
        if(Maker1->playerHand[i].Name == Names(Jack) && Maker1->playerHand[i].Suit == gtc.TrumpCard)
        {
            Team1Points += 5;
        }
        else if(Maker1->playerHand[i].Name == Names(Jack) && Maker1->playerHand[i].Suit != gtc.TrumpCard)
        {
            Team1Points += 3;
        }
        else if(Maker1->playerHand[i].CardValue < 14 && Maker1->playerHand[i].Suit == gtc.TrumpCard)
        {
            Team1Points += 1;
        }
        else if(Maker1->playerHand[i].CardValue < 14 && Maker1->playerHand[i].Suit != gtc.TrumpCard)
        {
            Team1Points += 0.05;
        }
    }

    for(int i = 0; i < Defender1->LookAtHand(); i++)
    {
        if(Defender1->playerHand[i].Name == Names(Jack) && Defender1->playerHand[i].Suit == gtc.TrumpCard)
        {
            Team2Points += 5;
        }
        else if(Defender1->playerHand[i].Name == Names(Jack) && Defender1->playerHand[i].Suit != gtc.TrumpCard)
        {
            Team2Points += 3;
        }
        else if(Defender1->playerHand[i].CardValue < 14 && Defender1->playerHand[i].Suit == gtc.TrumpCard)
        {
            Team2Points += 1;
        }
        else if(Defender1->playerHand[i].CardValue < 14 && Defender1->playerHand[i].Suit == gtc.TrumpCard)
        {
            Team2Points += 0.05;
        }
    }

    for (int i = 0; i < Maker2->LookAtHand(); i++)
    {
        if (Maker2->playerHand[i].Name == Names(Jack) && Maker2->playerHand[i].Suit == gtc.TrumpCard)
        {
            Team1Points += 5;
        }
        else if (Maker2->playerHand[i].Name == Names(Jack) && Maker2->playerHand[i].Suit != gtc.TrumpCard)
        {
            Team1Points += 3;
        }
        else if (Maker2->playerHand[i].CardValue < 14 && Maker2->playerHand[i].Suit == gtc.TrumpCard)
        {
            Team1Points += 1;
        }
        else if (Maker2->playerHand[i].CardValue < 14 && Maker2->playerHand[i].Suit != gtc.TrumpCard)
        {
            Team1Points += 0.5;
        }

    }

    for(int i = 0; i <Defender1->LookAtHand(); i++)
    {
        if (Defender2->playerHand[i].Name == Names(Jack) && Defender2->playerHand[i].Suit == gtc.TrumpCard)
        {
            Team2Points += 5;
        }
        if (Defender2->playerHand[i].Name == Names(Jack) && Defender2->playerHand[i].Suit != gtc.TrumpCard)
        {
            Team2Points += 3;
        }
        else if (Defender2->playerHand[i].CardValue < 14 && Defender2->playerHand[i].Suit == gtc.TrumpCard)
        {
            Team2Points += 1;
        }
        else if (Defender2->playerHand[i].CardValue < 14 && Defender2->playerHand[i].Suit != gtc.TrumpCard)
        {
            Team2Points += 0.5;
        }

    }

    if(Team1Points > Team2Points)
    {
        return std::string("Maker win round");
    }
    else if(Team2Points > Team1Points)
    {
        return std::string("Defender win round");
    }
    else
    {
        return std::string("No winner");
    }


    return std::string("");
}


int main()
{
    for(int i = 0; i < 100; i++)
    {
        std::cout << EachRoundResult() << std::endl;
    }
}
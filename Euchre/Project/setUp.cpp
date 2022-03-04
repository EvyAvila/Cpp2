#include "header.h"

struct TheCard
{
    public:
        int theCardValue;
        Suits theSuit;
        Name theCardName;

        //Regular for the 9 card
        TheCard(int value, Suits suit)
        {
            theCardValue = value;
            theSuit = suit;
        }

        TheCard(int value, Suits suit, Name name)
        {
            theCardValue = value;
            theSuit = suit;
            theCardName = name;
        }
};

struct TheDeck
{
    public:
        std::vector<TheCard> theCardDeck = std::vector<TheCard>();

        TheDeck()
        {
            for(int theSuit = 0; theSuit < 4; theSuit++)
            {
                for(int cardV = 9; cardV <= 14; cardV++)
                {
                    if(cardV == 11)
                    {
                        //Jack
                        theCardDeck.push_back(std::move(theCardDeck(cardV, (Suits)theSuit, (Name)0)));
                    }
                    else if(cardV == 12)
                    {
                        //Queen
                    }
                    else if(cardV == 13)
                    {
                        //King
                    }
                    else if(cardV == 14)
                    {
                        //Ace - hiigher value than king
                    }
                    else
                    {
                        //For 9 and 10
                    }
                }
            }
        }

        void ShuffleTheDeck()
        {
            auto seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::shuffle(theCardDeck.begin(), theCardDeck.end(), std::default_random_engine(seed));
        }

        TheCard DealingCard()
        {
            TheCard tcd = theCardDeck.back();
            theCardDeck.pop_back();
            return std::move(tcd);
        }
};
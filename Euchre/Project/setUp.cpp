/*
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
                        //Queen
                        theCardDeck.push_back(std::move(theCardDeck(cardV, (Suits)theSuit, (Name)2)));
                    }
                    else if(cardV == 12)
                    {
                        //King
                        theCardDeck.push_back(std::move(theCardDeck(cardV, (Suits)theSuit, (Name)3)));
                    }
                    else if(cardV == 13)
                    {
                        //Ace
                        theCardDeck.push_back(std::move(theCardDeck(cardV, (Suits)theSuit, (Name)0)));
                    }
                    else if(cardV == 14)
                    {
                        //Jack - highest value
                        theCardDeck.push_back(std::move(theCardDeck(cardV, (Suits)theSuit, (Name)1)));
                    }
                    else
                    {
                        //For 9 and 10
                        theCardDeck.push_back(std::move(theCardDeck(cardV, (Suits)theSuit)));
                    }
                }
            }
        }
        //Jack, Ace, King, Queen, 10, 9

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

class ThePlayer
{
    public:
        std::vector<TheCard> thePlayersHand;

        ThePlayer()
        {
            thePlayersHand = std::vector<TheCard>();
        }

        int LookAtHand()
        {
            //May or may not need this
            int theCardAmount = 0;
            for(std::vector<TheCard>::iterator thetotalAmount = thePlayersHand.begin(); thetotalAmount != thePlayersHand.end(); thetotalAmount++)
            {
                theCardAmount += thetotalAmount->theCardValue;
            }
        }  
};

//Fix later
class ComparingAnswerKey(ThePlayer *tp);
{
    public:
        //std::vector<TheCard> theHeartTrump;
        std::vector<enum> theHeartTrump = {Jack, JackTwo, Ace, King, Queen, Ten, Nine};
        std::vector<int> theNumberPosition = {15, 14, 13, 12, 11, 10, 9}

        std::vector<TheDeck> theDiamondTrump;
        std::vector<TheDeck> theSpadeTrump;
        std::vector<TheDeck> theClubTrump;

        //std::vector<TheDeck> theTrump;
        //ThePlayer player = new ThePlayer();

        ComparingAnswerKey(ThePlayer *thePlay)
        {
           //theTrump  = std::vector<TheDeck>();
           //theHeartTrump = std::vector<TheCard>();
           theHeartTrump = std::vector<enum>();
           theNumberPosition = std::vector<int>();
           ThePlayer->thePlay;
        }

        
        

};

bool Changevalue(ThePlayer *tp)
{
    for(int i = 0; i <= 14; i++)
    {
        
        if(tp->thePlayersHand[i].cardValue == 1)
        {
            tp->thePlayersHand[i].cardValue += 11;
            return true;
        }
        else if(tp->thePlayersHand[i].cardValue == 11 || tp->thePlayersHand[i].cardValue == 12 || tp->thePlayersHand[i].cardValue == 13)
        {
            tp->thePlayersHand[i].cardValue += 10;
            return true;
        }
    }
}
*/

/*

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
                        //Queen
                        theCardDeck.push_back(std::move(TheCard(cardV, (Suits)theSuit, (Name)2)));
                    }
                    else if(cardV == 12)
                    {
                        //King
                        theCardDeck.push_back(std::move(TheCard(cardV, (Suits)theSuit, (Name)3)));
                    }
                    else if(cardV == 13)
                    {
                        //Ace
                        theCardDeck.push_back(std::move(TheCard(cardV, (Suits)theSuit, (Name)0)));
                    }
                    else if(cardV == 14)
                    {
                        //Jack - highest value
                        theCardDeck.push_back(std::move(TheCard(cardV, (Suits)theSuit, (Name)1)));
                    }
                    else
                    {
                        //For 9 and 10
                        theCardDeck.push_back(std::move(TheCard(cardV, (Suits)theSuit)));
                    }
                }
            }
        }
        //Jack, Ace, King, Queen, 10, 9

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

            for(std::vector<TheCard>::iterator thetotalAmount = playerHand.begin(); thetotalAmount != playerHand.end(); thetotalAmount++)
            {
                theCardAmount += thetotalAmount->theCardValue;
            }
            return theCardAmount;
        }
        
};

TheTeam theTeam()
{
    TheDeck td = TheDeck();
    td.ShuffleTheDeck();
    

    ThePlayer *thePlayer = new ThePlayer();

    while(thePlayer->LookAtHand() < 5)
    {
        thePlayer->playerHand.push_back(td.DealingCard());
        if(thePlayer->LookAtHand() == 14)
        {
            return Team2;
        }
    }

    return Team2;
}

std::string FinalRoundResult(TheTeam rr)
{
    if(rr == Team1)
    {
        return std::move("Team 1 won the round");
    }
    else if(rr == Team2)
    {
        return std::move("Team 2 won the round");
    }
    else
    {
        return std::move("No winner");
    }
    
    return std::move("");
}


*/
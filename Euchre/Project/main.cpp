#include "header.h"

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

//Might not need it
bool Changevalue(ThePlayer *tp)
{
    for(int i = 9; i <= 14; i++)
    {
        if(tp->playerHand[i].Name == Jack)
        {
            tp->playerHand[i].CardValue += 14;
        }
    }
}

class GetTrumpCard
{
    public:
        Suits TrumpCard;

        GetTrumpCard()
        {
            TrumpCard = Suits(rand() % empty);

        }
};

TheTeam team()
{
    TheDeck td = TheDeck();
    td.ShuffleTheDeck();

    //Team 1
    ThePlayer *player1 = new ThePlayer();
    ThePlayer *player2 = new ThePlayer();

    //Team 2
    ThePlayer *player3 = new ThePlayer();
    ThePlayer *player4 = new ThePlayer();

    GetTrumpCard gtc = GetTrumpCard();
    gtc.TrumpCard;

        while(player1->LookAtHand() < 6)
        {
            player1->playerHand.push_back(td.DealingCard());

            //if(player1->LookAtHand() < 6 )
            //{
                //player1->playerHand.push_back(td.DealingCard());

                if(player1->LookAtHand() == 14 && gtc.TrumpCard == Heart)
                {
                    //return Team2;
                    Team1Points++;
                    //break;
                }
                else if(player1->LookAtHand() == 14 && gtc.TrumpCard == Diamond)
                {
                    Team1Points++;
                    //break;
                }
                else if(player1->LookAtHand() == 14 && gtc.TrumpCard == Spade)
                {
                    Team1Points++;
                    //break;
                }
                else if(player1->LookAtHand() == 14 && gtc.TrumpCard == Club)
                {
                    Team1Points++;
                }
                else if(player1->LookAtHand() == 0)
                {
                    break;
                }                
                else
                {
                   // 
                }
            //}
        }

        while(player3->LookAtHand() < 6)
        {
            player3->playerHand.push_back(td.DealingCard());

            //if(player1->LookAtHand() < 6 )
            //{
                //player1->playerHand.push_back(td.DealingCard());

                if(player3->LookAtHand() == 14 && gtc.TrumpCard == Heart)
                {
                    //return Team2;
                    Team2Points++;
                    //break;
                }
                else if(player3->LookAtHand() == 14 && gtc.TrumpCard == Diamond)
                {
                    Team2Points++;
                    //break;
                }
                else if(player3->LookAtHand() == 14 && gtc.TrumpCard == Spade)
                {
                    Team2Points++;
                    //break;
                }
                else if(player3->LookAtHand() == 14 && gtc.TrumpCard == Club)
                {
                    Team2Points++;
                }
                else if(player3->LookAtHand() == 0)
                {
                    break;
                }                
                else
                {
                   // 
                }
                
            //}
        
        }


        if(Team1Points > Team2Points)
        {
            return Team1;
        }
        else if(Team2Points > Team1Points)
        {
            return Team2;
        }
        return Team2;
}

std::string FinalRoundResult(TheTeam rr)
{
    if(rr == Team1)
    {
        return std::move("Team 1 wins the round");
    }
    else if(rr == Team2)
    {
        return std::move("Team 2 winds the round");
    }

    return std::move("");
}


int main()
{
    //std::cout << "Hello Testing" << std::endl;
    //for(int i = 0; i < 100; i++)
    //{
        //Can display specifc input
        //std::cout << TheCard(14, Heart, Jack).Name << std::endl;
        
        //Can display the card by calling each specific part
        //std::cout << TheDeck().TheCardDeck[5].CardValue << std::endl;
        //std::cout << TheDeck().TheCardDeck[5].Name << std::endl;
        //std::cout << TheDeck().TheCardDeck[5].Suit << std::endl;
        
        //can check size
        //std::cout << TheDeck().TheCardDeck[i].CardValue << std::endl;
        //std::cout << TheDeck().TheCardDeck.size() << std::endl;

        //Empty
        //std::cout << player1->LookAtHand() << std::endl;
        //std::cout << "Player 1 has the value of: " << std::endl;
        //std::cout<< player1->LookAtHand() << std::endl;
    //}

    std::cout << FinalRoundResult(TheTeam()) << std::endl;
    

}
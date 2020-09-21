#include "Mikail.h" //hier voeg je de body toe
#include <iostream>
#include "game.h"

//hier willen we definities doen die gedclareerd zijn

namespace PXL2019
{

    Mikail::Mikail( unsigned char instance ) : Player(instance)
    {
        wig = -1;
    }

    const char* Mikail::getName (void) const
    {

        return "Mikail";
    }

    int Mikail::GetTableHalf( int myLoc, int PlayersAlive ){
        if( myLoc >= (PlayersAlive/2) ){                    // Speler zit in tweede deel van de tafel
            return( 1 );
        }else{                                              // Speler zit in eerste deel van de tafel
            return( 0 );
        }
    }

    int Mikail::GetMyRank( void ){
        PokerRank myHandRank = getHand().getMyRank();

        if( myHandRank.getCategory() >= FLUSH ){            // Hand is >= aan Flush
            return( 2 );

        }else if(myHandRank.getCategory() >= TWO_PAIR){     // Hand is >= aan Two Pair
            return( 1 );

        }else{                                              // Bad hand cry
            return( 0 );
        }
    }

    int Mikail::CompareTable( void )
    {
        PokerRank myHandRank = getHand().getMyRank();
        PokerRank tableRank = getCommunityRank();

        if( myHandRank.getCategory() > tableRank.getCategory() ){           // Hand > tafel
            return( 1 );

        }else if( myHandRank.getCategory() == tableRank.getCategory() ){    // Hand = als tafel
            return( 0 );

        }else if( myHandRank.getCategory() < tableRank.getCategory() ){     // Hand < dan tafel
            return( -1 );
        }
    }

    int Mikail::willYouRaise( unsigned int totalBet )
    {

        PokerRank Pos = getCommunityRank();                                    // Welke kant van de tafel zit de speler ( 1 tweede helft, 0 eerste helft )
        int MyRank = GetMyRank();
        int Compare = CompareTable();

        if( Compare == -1 ){                                                    // Fold als hand slechter dan tafel
            return( -1 );

        }else if( Compare == 0 ){
            if( Pos == nullptr){
                if( MyRank == 2 ){          // Raise als : hand = tafel, speler zit in de eerste helft en hand is goed
                    return( 1 );

                }else if( MyRank == 1 ){    // Call als : hand = tafel, speler zit in de eerste helft en hand is ok
                    return( 0 );

                }else if( MyRank == 0 ){    // Fold als : hand = tafel, speler zit in de eerste helft en hand is slecht
                    return( -1 );
                }

            }else if( Pos == nullptr ){
                if( MyRank == 2 ){          // Raise als : hand = tafel, speler zit in de eerste helft en hand is goed
                    return( 1 );

                }else if( MyRank == 1 ){    // Call als : hand = tafel, speler zit in de eerste helft en hand is ok
                    return( 0 );

                }else if( MyRank == 0 ){    // Call als : hand = tafel, speler zit in de eerste helft en hand is slecht
                    return( 0 );
                }
            }

        }else if( Compare == 1 ){
            if( Pos == nullptr ){
                if( MyRank == 2 ){          // All-in als : hand > tafel, speler zit in de tweede helft en hand is goed
                    return( getChips() );

                }else if( MyRank == 1 ){    // Raise als : hand > tafel, speler zit in de tweede helft en hand is ok
                    return( 1 );

                }else if( MyRank == 0 ){    // Call als : hand > tafel, speler zit in de tweede helft en hand is slecht
                    return( 0 );
                }

            }else if( Pos == nullptr ){
                if( MyRank >= 1 ){          // All-in als : hand > tafel, speler zit in de tweede helft en hand is goed of ok
                    return( getChips() );

                }else if( MyRank == 0 ){    // Raise als : hand > tafel, speler zit in de tweede helft en hand is slecht
                    return( 1 );
                }
            }
        }
    }
    void Mikail::speech( int debug )
    {
        std::cout << "TADAAA" << debug << std::endl;
    }
}


// =  -> gelijk
// <  -> slechter
// >  -> beter

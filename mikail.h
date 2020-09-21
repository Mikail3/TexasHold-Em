#ifndef MIKAIL_H //als deze niet gedefined is stop
#define MIKAIL_H //hier define je de header
#include "player.h" //nu is player.h gekend


namespace PXL2019
{ //nu zit Mikail in de namespace


         class Mikail : public Player
         {
         public:
             Mikail( unsigned char instance);


         Mikail(); //constructor

         virtual const char* getName( void ) const;

         int GetTableHalf( int myLoc , int Playerslife);

         int GetMyRank( void );

         int CompareTable( void );

         int WillYouRaise ( unsigned int totalBet);

         protected:
             virtual int willYouRaise( unsigned int totalBet ); //Member functie
             void speech( int debug );

         private:
         int wig; //Dit is de member variabele


        };
 }

#endif // MIKAIL_H


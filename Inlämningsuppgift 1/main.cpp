#include <iostream>
#include <ctime>
using namespace std;


int main() {
  //Initierar variabler som behövs senare i programmet
  int balance = 0;
  int choice = 0;
  int bet = 0;
  int computerTotalScore = 0;
  int playerTotalScore = 0;
  int computerScore = 0;
  int playerScore = 0;
  int computerRoll1 = 0;
  int playerRoll1 = 0;
  int computerRoll2 = 0;
  int playerRoll2 = 0;
  int computerRollMax = 0;
  int playerRollMax = 0;
  srand(time(0));

  // While loop som är satt till att köras tills man väljer att avsluta spelet.
  while (true) {
    cout << "\nDu har " + to_string(balance) + " kr att spela för. \n\nVälj ett av följande alternativ:\n\n1. Sätta in pengar\n2. Satsa 100 kr\n3. Satsa 300 kr\n4. Satsa 500 kr\n5. Avsluta spelet\n\n>> ";

    // While loop som testar om input är ett nummer
    while(!(cin >> choice)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Felaktigt val, försök igen.\n\n>> ";
    }

    // Kollar att man inte sätter in mera än 5000 kr åt gången eller sätter in ett negativt tal.
    // Om man sätter in ett decimaltal klipps decimalerna bort.
    if (choice == 1) {
      while(true) {
        int deposit = 0;
        cout << "Hur mycket pengar vill du sätta in? Max 5.000 kr >> ";

        while(!(cin >> deposit)) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Felaktigt belopp, försök igen.\n\n>> ";
        }

        if (deposit > 5000) {
          cout << "Du försökte sätta in för mycket pengar, försök igen. Max 5.000 kr\n>> ";

        } else if (deposit < 0) {
          cout << "Du försökte sätta in ett negativt belopp." << endl;

        } else {
          balance += deposit;
          break;
        }
      }

      continue;

    // Kontrollerar att det finns tillräckligt med pengar för satsningen.
    } else if (choice == 2) {
      if (balance < 100) {
        cout << "Du har inte tillräckligt med pengar." << endl << endl;
        continue;

      } else {
        bet = 100;
      }

    } else if (choice == 3) {
      if (balance < 300) {
        cout << "Du har inte tillräckligt med pengar." << endl << endl;
        continue;

      } else {
        bet = 300;
      }

    } else if (choice == 4) {
      if (balance < 500) {
        cout << "Du har inte tillräckligt med pengar." << endl;
        continue;

      } else {
        bet = 500;
      }

      // Avslutar programmet.
    } else if (choice == 5) {
      cout << "Tack för att du har spelat. Du har " << balance << " kr att ta ut."  << endl;
      break;

      // Detta körs om man slår in en siffra som inte är mellan 1-5.
    } else {
      cout << "Felaktigt val, försök igen." << endl;
      continue;
    }

    cout << "Du har satsat " + to_string(bet) + " kr" << endl << endl;
    
    // Nollställer variablerna inför varje omgång.
    computerScore = 0;
    playerScore = 0;

    // Kastar tärning tills någon har vunnit 2 kast
    while (computerScore < 2 && playerScore < 2) {
      computerRoll1 = rand() % 6 + 1;
      playerRoll1 = rand() % 6 + 1;
      computerRoll2 = rand() % 6 + 1;
      playerRoll2 = rand() % 6 + 1;

      cout << "Du kastar " << playerRoll1 << " och " << playerRoll2 << " och datorn kastar " << computerRoll1 << " och " << computerRoll2 << "." << endl;

      // Kontrollerar vem som kastade högst, tilldelar poäng, och om ingen kastade högst blev det lika och ingen får poängen.
      if (computerRoll1 > computerRoll2) {
        computerRollMax = computerRoll1;

      } else {
        computerRollMax = computerRoll2;

      }
      if (playerRoll1 > playerRoll2) {
        playerRollMax = playerRoll1;

      } else {
        playerRollMax = playerRoll2;

      }
      if (computerRollMax > playerRollMax) {
        computerScore += 1;
        cout << "Datorn vann den här omgången." << endl << endl;

      } else if (playerRollMax > computerRollMax) {
        playerScore += 1;
        cout << "Du vann den här omgången." << endl << endl;

      } else {
        cout << "Ni kastade lika." << endl << endl;
      }
    }

    // Kontrollerar vem som vann omgången, ökar den totala vinsten för vinnaren och ändrar saldot enligt insatsen.
    if (computerScore > playerScore) {
      cout << "Datorn vann det här spelet!" << endl;
      computerTotalScore += 1;
      balance -= bet;

    } else if (playerScore > computerScore) {
      cout << "Du vann det här spelet!" << endl;
      playerTotalScore += 1;
      balance += bet;
    }

    cout << "\nDu har vunnit totalt " + to_string(playerTotalScore) + " gånger och datorn har vunnit " + to_string(computerTotalScore) + " gånger." << endl;
  }

  return 0;

}

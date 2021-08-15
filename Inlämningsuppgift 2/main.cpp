#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

// Deklarera variabler/funktioner som kommer att användas
static float * buildDeck();
static float * mixDeck(float deck[]);
int option();
int pickCard();
string printCard(float card);
string getSuit(float suit);
string getNumber(int number);


int main() {
  // Deklarerar variabler som endast behövs i main funktionen
  srand(time(0));
  float playerCard = 0;
  float computerCard = 0;
  float * deck = buildDeck();
  int playerTotalScore = 0;
  int computerTotalScore = 0;

    while (true) {      
      // Fråga användaren om hen vill spela eller avsluta programmet
      int choice = option();
      if(choice == 1) {
        // Deklarerar variablerna som endast behövs för spelet samt nollställer dem efter varje omgång
        int playerScore = 0;
        int computerScore = 0;
        while(true) {
          // Blanda leken
          mixDeck(deck);

          // Låter spelaren dra ett kort och drar ett kort åt datorn
          playerCard = deck[pickCard() - 1];
          computerCard = deck[rand() % 52];

          // While loop som ser till att datorn inte drar samma kort som spelaren
          while(computerCard == playerCard) {
            computerCard = deck[rand() % 52];
          }        
          cout << "\nDu drog " << printCard(playerCard) << "." << endl;
          cout << "Datorn drog " << printCard(computerCard) << "." << endl << endl;

          if(playerCard > computerCard) {
            cout << "Du vann den här rundan!" << endl;
            playerScore++;
          }

          if(computerCard > playerCard) {
            cout << "Datorn vann den här rundan!" << endl;
            computerScore++;
          }

          cout << "Du har vunnit " << playerScore << " gånger, och datorn har vunnit " << computerScore << " gånger." << endl << endl;

          // Avslutar spelet om spelaren eller datorn har kommit upp i 2 vunna omgångar
          if(playerScore == 2) {            
            playerTotalScore++;
            cout << "Du vann den här omgången!" << endl;
            break;
          }
          if(computerScore == 2) {            
            computerTotalScore++;
            cout << "Datorn vann den här omgången!" << endl;
            break;
          }
        }
        cout << "Du har vunnit " << playerTotalScore << " spel, och datorn har vunnit " << computerTotalScore << " spel." << endl << endl; 
      }

      // Avsluta programmet om användaren väljer det alternativet
      if(choice == 2){
        break;
      }
    }

  return 0;
}

// Bygger en kortlek med decimaltal där heltalet utgör valören och decimalen utgör färgen
static float * buildDeck() {
  int k = 0;
  static float deck[52] = {};
  static float numbers[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  static float suits[4] = {0.1, 0.2, 0.3, 0.4};
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 13; j++) {
      deck[k] = numbers[j] + suits[i];
      k++;
    }
  }
  return deck;
}

// Blandar kortleken
static float * mixDeck(float deck[]) {
  random_shuffle(&deck[0], &deck[52]);
  return deck;
}

// Visar huvudmenyn till användaren och kontrollerar att input är giltigt
int option() {
  int choice = 0;
  cout << "Välj ett av följande alternativ: " << endl << endl << "1. Spela." << endl << "2. Avsluta spelet." << endl << endl << ">> ";
  while(true){  
    while(!(cin >> choice)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Felaktigt val, försök igen.\n\n>> ";
      continue;
      }
      
      if (choice == 1 || choice == 2) {
        return choice;
      } else {
        cout << "Felaktigt val, försök igen.\n\n>> ";
      }
  }
};

// Låter användaren dra ett kort och kontrollerar att input är giltigt
int pickCard() {
  int choice = 0;
  cout << "\nDra ett kort ur leken genom att välja en siffra mellan 1 - 52\n\n>> ";
  while(true){  
    while(!(cin >> choice)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Felaktigt val, försök igen.\n\n>> ";
      continue;
      }
      
      if (choice >= 1 && choice <= 52) {
        return choice;

      } else {
        cout << "Felaktigt val, försök igen.\n\n>> ";
      }
  }
}

// Returnerar ett kort ur leken som en sträng
string printCard(float card) {
  float suit = card - int(card);
  float number = card - suit;
  return getSuit(suit) + " " + getNumber(number);
}

// Kontrollerar decimaltalet och returnerar färgen
string getSuit(float suit) {
  if(suit >= 0.39) {
    return "Spader";

  } else if (suit >= 0.29) {
    return "Hjärter";

  } else if (suit >= 0.19) {
    return "Ruter";

  } else if (suit >= 0.09) {
    return "Klöver";

  } else {
    return "Error: getSuit went wrong";
  }
}

// Kontrollerar heltalet och returnerar antingen det eller namnet på kortet om talet är 11 eller högre
string getNumber(int number) {
  if(number == 14) {
    return "Ess";

  } else if(number == 13) {
    return "Kung";

  } else if(number == 12) {
    return "Dam";

  } else if(number == 11) {
    return "Knekt";
  } else {
    return to_string(number);
  }
}

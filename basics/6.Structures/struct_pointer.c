#include <stdio.h>

#define DECK_SIZE 52
#define CARD_RANGE 13
struct Card {
  int pips;
  char suit;
} c1 = {5, 'd'};

/* call by value */
struct Card assign_to_copy(struct Card c, int a, char b) {
  c.pips = a;
  c.suit = b;
  return c;
}

/* call by reference */
struct Card *assign_to_real(struct Card *cp, int a, char b) {
  cp->pips = a;
  cp->suit = b;
  return cp;
}

void extract_values(struct Card *cp, int *p_ptr, char *s_ptr) {
  *p_ptr = cp->pips;
  *s_ptr = cp->suit;
}

void print_values(struct Card *cp) {
  int p;
  char s, *suit_name;
  // extract Card member values to local variables
  extract_values(cp, &p, &s);

  switch (s) {
  case 'c':
    suit_name = "clubs";
    break;
  case 'd':
    suit_name = "diamonds";
    break;
  case 'h':
    suit_name = "hearts";
    break;
  case 's':
    suit_name = "spades";
    break;
  default:
    suit_name = "error";
  }
  printf("card: %d of %s (%c) \n", p, suit_name, cp->suit);
}

int main() {

  struct Card result1 = assign_to_copy(c1, 1, 'h');
  printf("%i %c\n", c1.pips, c1.suit);
  printf("%i %c\n", result1.pips, result1.suit);

  struct Card *result2 = assign_to_real(&c1, 2, 's');
  printf("%i %c\n", c1.pips, c1.suit);
  printf("%i %c\n", result2->pips, result2->suit);

  print_values(&c1);
  assign_to_real(&c1, 7, 'd');
  print_values(&c1);
  assign_to_real(&c1, 10, 'x');
  print_values(&c1);

  /* 카드 덱 만들어보기! */
  /* array of structures */
  struct Card deck[DECK_SIZE];

  // 각 c,d,h,s에 대해 1~13까지 매칭시켜서 &deck[i], 즉 Card의 member(pips와 suit)에 할당 
  for (int i = 0; i < CARD_RANGE; i++) {
    assign_to_real(&deck[i + CARD_RANGE * 0], i + 1, 'c');
    assign_to_real(&deck[i + CARD_RANGE * 1], i + CARD_RANGE * 1, 'd');
    assign_to_real(&deck[i + CARD_RANGE * 2], i + CARD_RANGE * 2, 'h');
    assign_to_real(&deck[i + CARD_RANGE * 3], i + CARD_RANGE * 3, 's');
  }

  for (int i = 0; i < CARD_RANGE; i++) {
    print_values(deck + i);
  }
}

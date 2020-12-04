#include <iostream>

#include "game.hpp"
#include "mcts.hpp"
#include "node.hpp"

int main() {
  std::ios_base::sync_with_stdio(false);
  int sum = 0;
  for (int i = 0; i < 500; i++) {
    MCTS p1(13), p2(13);
    Game game(13);
    while (true) {
      p1.uct_search(5000);
      int move = p1.get_move();
      game.move(move);
      if (game.status != 0) break;
      p1.update_tree(move);
      p2.update_tree(move);
      p2.uct_search(5000);
      move = p2.get_move();
      game.move(move);
      if (game.status != 0) break;
      p1.update_tree(move);
      p2.update_tree(move);
    }
    sum += (int)game.status;
    if(i % 10 == 0)
      std::cout << (sum / (double)(i + 1) - 1) / 2 << std::endl;
  }
    std::cout << (sum / 500.0 - 1) / 2 << std::endl;
}
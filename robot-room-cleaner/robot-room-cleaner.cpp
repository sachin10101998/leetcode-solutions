class Solution {
public:
  void cleanRoom(Robot& robot) {
    mt19937 rng{random_device{}()};
    auto f = true;
    for (auto i = 0; i < 1000000; ++i) {
      robot.clean();
	  // must make a turn if blocked last time
      switch(uniform_int_distribution<int>(f ? 0 : 1, 3)(rng)) {
        case 0: // no turn
          break;
        case 1: // u turn
          robot.turnRight();
        case 2: // turn right
          robot.turnRight();
          break;
        case 3: // turn left
          robot.turnLeft();
          break;
      }
	  // am i blocked?
      f = robot.move();
    }
  }
};
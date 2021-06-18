# pthread
A learning demonstration why locking shared writable data is essential to prevent data races. Shared writable data must be protected in case it's writable and shared between different parties to prevent data corruption and races. Races can be very difficult to debug and can cause unexpected behavior to occur that this program try to visualize. This program show data races by incrementing a variable in a loop and see the final value of variable to see if some increments were missed with and without locking.

## How to run ?
clone repository and compile program by running ```make``` in repository directory. then run test.sh testing file to enter how many times the program should run to notice how unpredictable these races can be(sometimes corruptions happens sometimes not) making them very difficult to debug in the real world.

### NOTES
incomplete writes or reads cant be demonstrated here since x86 guarantee atomic reads or writes up to CPU bus size (64bit on x86_64) but RMW instructions such as the ```inc``` instruction that gcc compiler will generate for this variable increment are not atomic in nature so data corruption can occur but not incomplete reads or writes. You can also try to disable optimization to see how this will affect missed writes ratio which should increase since now increment will be done by more than not one instruction (```inc```) but 3 instruction (first ```mov```, ```add```, ```mov```) further increasing chances data races.

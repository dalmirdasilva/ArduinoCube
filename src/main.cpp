#include <DrawerTest.h>

#define TEST_MODE 1

int main(int argc, char *argv[]) {
  
  Drawer drawer = Drawer();
  DrawerTest drawerTest = DrawerTest(&drawer);
  drawerTest.run();
  
  return 0;
}

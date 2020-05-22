 #!/usr/bin/bash
cd src
echo "g++ -Wall -std=c++11 -lpthread board.cpp core_simulation.cpp mydevices.cpp sketch_ino.cpp -o arduino"
g++ -Wall -std=c++11 -pthread board.cpp core_simulation.cpp sensor_lum.cpp door.cpp environnement.cpp sketch_ino.cpp -o arduino
./arduino

cmake_minimum_required(VERSION 3.13)
project(CarGame)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CarGame_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

add_executable(CarGame main.cpp SDLfact.cpp SDLfact.h Game.cpp Game.h Afact.cpp Afact.h Car.cpp Car.h SDLcar.cpp SDLcar.h HighWay.cpp HighWay.h SDLHighWay.cpp SDLHighWay.h Entity.cpp Entity.h EnemyCar.cpp EnemyCar.h SDLEnemyCar.cpp SDLEnemyCar.h Menu.cpp Menu.h SDLMenu.cpp SDLMenu.h Player.cpp Player.h SDLPlayer.cpp SDLPlayer.h EventHandler.cpp EventHandler.h SDLEventHandler.cpp SDLEventHandler.h Bullet.cpp Bullet.h SDLBullet.cpp SDLBullet.h PowerUps.cpp PowerUps.h PowerUpAmmo.cpp PowerUpAmmo.h SDLPowerUpAmmo.cpp SDLPowerUpAmmo.h PowerUpCoin.cpp PowerUpCoin.h SDLPowerUpCoin.cpp SDLPowerUpCoin.h)

target_link_libraries(CarGame ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})
Snake Game
C++ 프로그래밍 Ncurses 라이브러리를 사용하여 만든 SnakeGame 프로젝트 구현체 입니다.

main.cpp
- Snakegame 을 구현한 파일
  
snake.cpp
- snake 에 필요한 함수를 작성한 파일
  
item.cpp
- item 에 필요한 함수를 작성한 파일
  
gate.cpp
- gate 에 필요한 함수를 작성한 파일
  
ui.cpp
- 미션판, 스코어판과 여러 화면 구성에 필요한 함수를 작성한 파일
  
map.cpp
- map 구성에 필요한 함수를 작성한 파일
  
map.h
- 초기 map 을 저장한 파일.
  
function.h
- snakegame 에 사용될 변수들과 함수, 클래스를 선언한 파일.
  
makefile
- snakegame 실행을 위한 makefile

How to build

1. make 명령어를 입력하여 snakegame 실행 파일을 생성한다
1-1. make가 없을 시 sudo apt install make (make install 명령어) 설치한다.
2. ./snakegame 을 입력하면 게임이 시작된다.
or
1. make 가 정상적으로 작동 하지 않을 시 g++ -o main main.cpp -lncurses 로 컴파일 한
후 ./main 으로 실행

# cub3d
## 1. 실행
~~~bash
#실행 (이동 : WASD / 시야전환 : <- ->)
git clone https://github.com/tapark/cub3d.git && cd cub3d && make && ./cub3D maps/map2.cub
#종료
press_key[ESC] or click[X]
#스크린샷
./cub3D maps/map2.cub --save
#초기화
make fclean
~~~

## 2. 설명
![cub3d](https://user-images.githubusercontent.com/67908647/115222037-435e4900-a145-11eb-9d02-afa4f8d21956.gif)
 - 맵파일(.cub)을 파싱하여 맵(벽과 이동가능한 공간)정보를 화면에 구현함
 - 동서남북 각각 다른 텍스쳐를 맵파일로부터 적용하여 거리에 따른 원근을 표현하고 지나갈 수 없는 장애물(오소리)을 구현함
 - 사방이 벽으로 막혀있지않은 맵의 경우, 플레이어의 시작위치가 여러개인 경우, 맵파일에 잘못된 인자가 들어있는 경우 등 예외처리
 - 맵파일은 해상도, 동서남북 텍스쳐, 장애물 텍스쳐, 천장과 바닥의 색, 맵정보로 구성되어있다. 

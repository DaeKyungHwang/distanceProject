#include <bangtal.h>

SceneID main_scene;	//바탕화면 정의
ObjectID cat;	//움직이는 물체 정의
ObjectID bar;	//거리 바 오브젝트 정의
ObjectID barCh;	//바를 움직이는 캐릭터 정의
TimerID sceneTimer = createTimer(90);	//게임 제한시간
TimerID barTimer = createTimer(0.01f);	//바를 움직이는 캐릭터 타이머 정의

void timerCallback(TimerID timer);	//타이머 콜백 함수
double xi = 320;	//바를 움직이는 캐릭터의 초기 좌표 정의

int main()
{
	setTimerCallback(timerCallback);

	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	main_scene = createScene("scene", "main_scene.png");	//바탕화면

	bar = createObject("bar.png");	//바
	locateObject(bar, main_scene, 320, 680);
	showObject(bar);

	barCh = createObject("cat.png");	//바를 움직이는 캐릭터
	scaleObject(barCh, 0.1f);
	locateObject(barCh, main_scene, 320, 680);
	showObject(barCh);

	startTimer(barTimer);
	startGame(main_scene);
}

void timerCallback(TimerID timer)
{
	if (timer == barTimer) {	//바를 움직이는 함수
		hideObject(barCh);
		xi = xi + 0.076;
		locateObject(barCh, main_scene, xi, 680);
		showObject(barCh);
	}

	setTimer(barTimer, 0.01f);	//바를 움직이는 시간 간격
	startTimer(barTimer);	//바 타이머 시작
}
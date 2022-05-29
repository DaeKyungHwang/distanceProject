#include <bangtal.h>

SceneID main_scene;	//����ȭ�� ����
ObjectID cat;	//�����̴� ��ü ����
ObjectID bar;	//�Ÿ� �� ������Ʈ ����
ObjectID barCh;	//�ٸ� �����̴� ĳ���� ����
TimerID sceneTimer = createTimer(90);	//���� ���ѽð�
TimerID barTimer = createTimer(0.01f);	//�ٸ� �����̴� ĳ���� Ÿ�̸� ����

void timerCallback(TimerID timer);	//Ÿ�̸� �ݹ� �Լ�
double xi = 320;	//�ٸ� �����̴� ĳ������ �ʱ� ��ǥ ����

int main()
{
	setTimerCallback(timerCallback);

	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	main_scene = createScene("scene", "main_scene.png");	//����ȭ��

	bar = createObject("bar.png");	//��
	locateObject(bar, main_scene, 320, 680);
	showObject(bar);

	barCh = createObject("cat.png");	//�ٸ� �����̴� ĳ����
	scaleObject(barCh, 0.1f);
	locateObject(barCh, main_scene, 320, 680);
	showObject(barCh);

	startTimer(barTimer);
	startGame(main_scene);
}

void timerCallback(TimerID timer)
{
	if (timer == barTimer) {	//�ٸ� �����̴� �Լ�
		hideObject(barCh);
		xi = xi + 0.076;
		locateObject(barCh, main_scene, xi, 680);
		showObject(barCh);
	}

	setTimer(barTimer, 0.01f);	//�ٸ� �����̴� �ð� ����
	startTimer(barTimer);	//�� Ÿ�̸� ����
}
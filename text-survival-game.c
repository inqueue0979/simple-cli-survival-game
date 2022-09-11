#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//게임 데이터 구조체
typedef struct _gameData
{
	int day; 
	int hp;
	int hunger;
	int sleepness;
}gameData;

//인벤토리 구조체 
typedef struct _inventory
{
	int berry;
	int edible_plant;
	int honey; 
	int herb;
	int s_meat;
	int l_meat;
}Inventory;

//확률 관련 구조체 
typedef struct _percentage
{
	int harvesting;
	int hunting;
	int fishing;
	int discovering;
	int collecting;
}percentage;

//함수 정의 
void loadScreen();
void MainMenu();
void GameMenu();
void Story(); 
char* changeDay(int *hunger, int *sleepness, percentage *pctg);
void Inven(Inventory *inventory, char *weather, gameData *data);
void save(gameData data, Inventory inven, percentage pctg);
void load(gameData *data, Inventory *inven, percentage *pctg);
void harvest(int pctg, Inventory *inventory);
void hunt(int pctg, Inventory *inventory);

//광역변수 설정
char *version = "0.1alpha"; 
char devMode = 0;
char str[64] = {0, };

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void main()
{
	//loadScreen();
	
	srand(time(NULL));
	while("true")
		MainMenu();
}

//초반 스크린 로딩 
void loadScreen()
{
	//제목 
	printf("***텍스트 서바이벌 게임***\n");
	Sleep(1000); 
	//버전 
	printf("버전 : %s\n", version);
	Sleep(1000);
	//로딩 스크린 
	printf("잠시 후 게임의 메인 화면으로 이동됩니다");
	Sleep(700);
	printf("."); 
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	
	fflush(stdin);
} 

//게임 메인 메뉴 
void MainMenu()
{
	char select;
	char* isenable;
	
	if(devMode == 1)
		isenable = "활성화됨";
	else
		isenable = "비활성화됨";
	
	system("cls"); //CUI 화면 초기화 
	printf("~~메인 메뉴~~\n\n");
	printf("1 / 새 게임 만들기\n\n");
	printf("2 / 게임 이어 하기\n\n");
	printf("3 / 게임 방법 보기\n\n");
	printf("c / 크레딧\n\n");
	printf("d / 개발자 모드 활성화 (현재 %s)\n\n", isenable);
	printf("e / 게임 종료\n\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~\n\n선택한 번호 : ");
	scanf("%c", &select);
	fflush(stdin);
	switch(select)
	{
		case '1':
			printf("\n\n~~~~~~~~~~~~~~~~~\n스토리를 보시겠습니까??\n\n");
			Sleep(700);
			printf("1 / 스토리 보기\n\n");
			printf("2 / 건너뛰기\n\n");
			printf("~~~~~~~~~~~~~~~~~\n\n선택한 번호 : ");
			char slc;
			scanf("%c", &slc);
			if(slc == '1')
			{
				Story();
				GameMenu(2);
			}
			else if(slc == '2')
			{
				system("cls");
				printf("잠시 후 스토리를 건너뛰고 게임을 시작합니다");
				Sleep(700);
				printf(".");
				Sleep(500);
				printf(".");
				Sleep(500);
				printf(".");
				Sleep(500);
				
				GameMenu(2);
			}
			else if(slc == 'q')
			{
				printf("뒤로 나갑니다.");
				Sleep(700);
			}	
			break;
		
		case '2':
			printf("\n아직 활성화되지 않은 기능입니다.");
			Sleep(1000); 
			break;
				
		case '3':
			break;
			
		case 'c':
			system("cls");
			printf("제작자 : jowonjae (inqueue0979)\n");
			printf("버전 : %s\n", version);
			printf("~~~~~~\n\n중학교 시절 배운 C언어 지식을 잊지 않기 위해 만든 간단한 텍스트 게임입니다.\n");
			printf("차차 기능들을 추가하여 대략적인 게임의 틀을 잡은 뒤 유니티엔진을 이용해 GUI 기반 게임을 제작할 예정입니다."); 
			printf("\n\n~~~~~~\n");
			printf("\n\n엔터키를 누르시면 메인메뉴로 돌아갑니다.");
			gets(str);
			break;
			
		case 'd':
			if (devMode == 0)
			{
				devMode = 1;
				printf("\n\n개발자 모드가 활성화되었습니다.");
				Sleep(700);
			}
			else 
			{
				devMode = 0;
				printf("\n\n개발자 모드가 비활성화되었습니다.");
				Sleep(700);
			}	
			break;
			
		case 'e':
			exit(0);
			break;			
	}
	
	fflush(stdin);
}

//스토리 작성 
void Story()
{
	system("cls");
	printf("스토리 관련 현재 제작중...\n\n");
	printf("인게임으로 넘어갑니다.");
	Sleep(1000);
	fflush(stdin);
}

//게임 내부 메뉴 
void GameMenu(int num)
{
	gameData data;
	percentage pctg;
	Inventory inven;
	char* weather;
	int goMain = 0;
	
	if(num == 1)
	{
		//불러오기 기능 
	}
	else if(num == 2)
	{
		//신규 데이터를 위한 초기화 
		data.day = 1;
		data.hp = 100;
		data.hunger = 100;
		data.sleepness = 100;
		pctg.harvesting = 70;
		pctg.hunting = 60;
		pctg.fishing = 100;
		pctg.discovering = 100;
		pctg.collecting = 100;
		inven.berry = 0;
		inven.edible_plant = 0;
		inven.honey = 0;
		inven.herb = 0;
		inven.s_meat = 0;
		inven.l_meat = 0;
		weather = "따스한 햇살이 사근사근 내리는 날.";
	}
	
	while("true")
	{
		char select;
		int slot;
		system("cls");
		printf("%d번째 날 | 날씨 : %s | 건강 = %d / 허기 = %d / 피로 = %d |\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", data.day, weather, data.hp, data.hunger, data.sleepness);
		if(devMode == 1)
			printf("확률 디버깅 (개발자 모드) / 수확 : %d | 사냥 : %d | 낚시 : %d | 탐험 : %d | 수집 : %d |\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", pctg.harvesting,pctg.hunting, pctg.fishing, pctg.discovering, pctg.collecting); 
		
		printf("1 / 식물 채집하기 (피로 -10)\n\n");
		printf("2 / 동물 사냥하기 (피로 -15)\n\n");
		printf("3 / 주변 탐사하기 (허기 -20)\n\n");
		printf("4 / 재료 수집하기 (허기 -20)\n\n");
		printf("5 / 잠을 자며 하루를 보내기 (피로 원상복구)\n\n");
		printf("~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("c / 도구 제작하기\n\n");
		printf("i / 인벤토리 보기\n\n");
		printf("s / 게임 저장하기\n\n");
		printf("e / 메인메뉴로 나가기 (저장 안 됨, 나가기 전 저장 필수!) \n\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~\n(잘못 입력 시 반응 없음)\n선택한 번호 : ");
		scanf("%c", &select);
		
		switch(select)
		{
			case '1':
				data.sleepness -= 10;
				harvest(pctg.harvesting, &inven);
				break;
		
			case '2':
				data.sleepness -= 15;
				hunt(pctg.hunting, &inven); 
				break;
					
			case '3':
				data.hunger	 -= 15;
				break;
				
			case '4':
				data.hunger -= 20;
				break;
				
			case '5':
				weather = changeDay(&data.hunger, &data.sleepness, &pctg);
				data.day++;
				data.sleepness = 100;			
				break;
			
			case 'c':
				break;
				
			case 'i':
				Inven(&inven, weather, &data);
				break;
				
			case 'l':
				load(&data, &inven, &pctg);
				break;
			
			case 's':
				save(data, inven, pctg);
				break;
			
			case 'e':
				printf("\n\n메인 메뉴로 나갑니다.");
				Sleep(1000);
				goMain = 1;
				break;	
				
			default:
				break;		
		}
		
		if(goMain == 1)
			break;
			
		fflush(stdin);
	}
}

//잠자기 기능 
char* changeDay(int *hunger, int *sleepness, percentage *pctg)
{
	char* weather;
	int random = 0;
	percentage perc = *pctg;
	
	//자고 일어날 시 배고픔 10 감소, 피로 100으로 원상복귀 
	*hunger -= 10;
	*sleepness = 100; 
	
	random = rand() % 4;
	
	switch(random)
	{
		case 0:
			weather = "따스한 햇살이 사근사근 내리는 날.";
			
			perc.harvesting = 70;
			perc.hunting = 60;
			perc.fishing = 0;
			perc.discovering = 0;
			perc.collecting = 0;
			
			break;
			
		case 1:
			weather = "추적추적 비 오는 날.";
			
			perc.harvesting = 30;
			perc.hunting = 60;
			perc.fishing = 0;
			perc.discovering = 0;
			perc.collecting = 0;
			
			break;
			
		case 2:
			weather = "뭉게뭉게 구름 낀 날.";
			
			perc.harvesting = 40;
			perc.hunting = 60;
			perc.fishing = 0;
			perc.discovering = 0;
			perc.collecting = 0;
			
			break;
			
		case 3:
			weather = "햇살이 바늘처럼 따가운 날.";
			
			perc.harvesting = 70;
			perc.hunting = 60;
			perc.fishing = 0;
			perc.discovering = 0;
			perc.collecting = 0;
			break;
			
		default:
			system("cls");
			weather = "프로그램에 문제가 발생했습니다. 제작자 측으로 문의해주십시오. 오류코드 : WEATHER_NOT_DEFINED";
			Sleep(10000);
			exit(0);
			break; 
	}
	
	system("cls");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n고단했던 하루를 잠으로 보냅니다");
	Sleep(700);				
	printf(".");
	Sleep(500);	
	printf(".");
	Sleep(500);	
	printf(".");
	Sleep(1000);
	
	 *pctg = perc;
	
	return weather;
}

void harvest(int pctg, Inventory *inventory)
{
	
	Inventory inven = *inventory;
	
	system("cls");
	printf("\n주변에서 채집해갈 것을 둘러본다");
	Sleep(700);
	printf("\n.");
	Sleep(500);
	printf("\n.");
	Sleep(500);
	printf("\n.");
	Sleep(1000);
	int random_out = rand() % 100;
	int random = rand() % 100;
	
	if(random_out < pctg)
	{
		if(random < 65)
		{
			printf("\n\n돌아다니다 보니 베리를 찾았다!");
			inven.berry++;
		}
		else if(random >= 65 && random <90)
		{
			printf("\n\n땅에 묻혀있던 식용 식물을 캤다!");
			inven.edible_plant++;
		}
		else if(random >= 90 && random < 95)
		{
			printf("\n\n우와! 꿀을 찾았다!");
			inven.honey++;
		}
		else if(random >= 95)
		{
			printf("\n\n희귀한 약초를 캤다!");
			inven.herb++;
		}
		else
		{
			printf("프로그램에 문제가 발생했습니다. 제작자 측으로 문의해주십시오. 오류코드 : RANDOM_NUMBER_EXCEEDED");
		}	
	}
	else
	{
		printf("\n\n오늘은 운이 없었다.. 채집할 만한 것을 찾지 못했다.."); 
	}
	
	if(devMode == 1) 
		printf(" (디버깅 모드 / 난수 :%d %d)", random_out, random);
		
	*inventory = inven;
	Sleep(1000);
}

void hunt(int pctg, Inventory *inventory)
{
	Inventory inven = *inventory;
	
	system("cls");
	printf("\n사냥감을 찾아본다");
	Sleep(700);
	printf("\n.");
	Sleep(500);
	printf("\n.");
	Sleep(500);
	printf("\n.");
	Sleep(1000);
	int random1 = rand() % 100;
	int random = rand() % 100;
	int random_2 = rand() % 100;
	
	if(random1 < pctg)
	{
		if(random < 80)
		{	
			if(random_2 < 75)
			{
				printf("\n\n토끼를 잡았다! +1 작은 고기");
				inven.s_meat++;
			}
			else if(random_2 >= 75 && random_2 < 95)
			{
				printf("\n\n앉아있던 새 두마리를 잡았다! +2 작은 고기");
				inven.s_meat++;
			}
			else if(random_2 >= 95)
			{
				printf("\n\n부패되지 않은 돼지 사체를 찾았다! +3 작은 고기");
				inven.s_meat++;
			}
			else
			{
				printf("프로그램에 문제가 발생했습니다. 제작자 측으로 문의해주십시오. 오류코드 : RANDOM_NUMBER_EXCEEDED");
			}	
		}
		else if(random >= 80)
		{
			if(random_2 < 90)
			{
				printf("\n\n사슴을 잡았다! +1 큰 고기");
				inven.l_meat++;
			}
			else if(random_2 >= 90)
			{
				printf("\n\n돼지를 잡았다! +2 큰 고기");
				inven.l_meat++;
			}
			else
			{
				printf("프로그램에 문제가 발생했습니다. 제작자 측으로 문의해주십시오. 오류코드 : RANDOM_NUMBER_EXCEEDED");
			}	
		}
		else
		{
			printf("프로그램에 문제가 발생했습니다. 제작자 측으로 문의해주십시오. 오류코드 : RANDOM_NUMBER_EXCEEDED");
		}	
	}
	else
	{
		printf("\n\n오늘은 운이 없었다..  사냥감을 찾지 못했다.."); 
	}
	
	if(devMode == 1) 
		printf(" (디버깅 모드 / 난수 :%d %d %d)", random1, random, random_2);
		
	*inventory = inven;
	Sleep(3000);
}

void discover()
{
	
}

void collect()
{
	
}

//인벤토리 기능 
void Inven(Inventory *inventory, char *weather, gameData *data)
{
	
	Inventory inven = *inventory;
	gameData gd = *data;
	
	while("true")
	{
		char select[3];
		system("cls");
		printf("%d번째 날 | 날씨 : %s | 건강 = %d / 허기 = %d / 피로 = %d |\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", gd.day, weather, gd.hp, gd.hunger, gd.sleepness);
		printf("~~인벤토리~~\n\n");
		printf("10 / 베리 | %d개\n\n", inven.berry);
		printf("11 / 식용식물 | %d개\n\n", inven.edible_plant);
		printf("12 / 꿀| %d\n\n", inven.honey);
		printf("13 / 약초| %d개\n\n", inven.herb);
		printf("14 / 작은 고기| %d개\n\n", inven.s_meat);
		printf("15 / 큰 고기| %d개\n\n", inven.l_meat);
		printf("q / 인벤토리 나가기\n\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~\n(잘못 입력 시 반응 없음)\n선택한 번호 : ");
		scanf("%s", select);
		
		printf("\n\n");
		switch(select[0])
		{
			case '1':
				switch(select[1])
				{
				case '0':
					if(inven.berry > 0)
					{
						inven.berry--;
						gd.hunger+= 10;
						printf("베리를 먹었습니다.");
					}
					else
					{
						printf("베리가 없습니다.");
					}
					break;
					
				case '1':
					if(inven.edible_plant > 0)
					{
						inven.edible_plant--;
						gd.hunger+= 12;
						printf("식용식물을 먹었습니다.");
					}
					else
					{
						printf("식용식물이 없습니다.");
					}
					break;
					
				case '2':
					if(inven.honey > 0)
					{
						inven.honey--;
						gd.hunger+= 20;
						gd.sleepness += 10;
						printf("꿀을 먹었습니다. 피로가 풀리는 맛입니다.");
					}
					else
					{
						printf("꿀이 없습니다.");
					}
					break;
					
				case '3':
					if(inven.herb > 0)
					{
						inven.herb--;
						gd.hunger+= 5;
						gd.sleepness += 20;
						gd.hp += 20;
						printf("약초를 먹었습니다. 건강이 회복되는 맛입니다.");
					}
					else
					{
						printf("약초가 없습니다.");
					}
					break;
				
				case '4':
					if(inven.s_meat > 0)
					{
						inven.s_meat--;
						gd.hunger+= 20;
						printf("작은 고기를 먹었습니다.");
					}
					else
					{
						printf("작은 고기가 없습니다.");
					}
					break;
					
				case '5':
					if(inven.l_meat > 0)
					{
						inven.l_meat--;
						gd.hunger+= 40;
						printf("큰 고기를 먹었습니다.");
					}
					else
					{
						printf("큰 고기가 없습니다.");
					}
					break;
				
				default:
					break;
			}
			break;
			
			default:
				break;
		}
		
		
		if(select[0] == 'q')
		{
			*inventory = inven;
			*data = gd;
			printf("\n\n인벤토리를 나갑니다.");
			Sleep(700); 
			break;
		}
		
		if(devMode == 1)
			printf("디버그 번호 : %s", select);
			
		fflush(stdin);
		Sleep(500);
	}
}

void craft()
{
	
}

//저장 기능 
void save(gameData data, Inventory inven, percentage pctg)
{
	FILE *fp[3];
	int quit = 0;
	
	while("true")
	{
		char slot;
		
		system("cls");
		printf("~~세이브 슬롯~~\n\n");
		printf("1 | 슬롯 1\n\n");
		printf("2 | 슬롯 2\n\n");
		printf("3 | 슬롯 3\n\n");
		printf("q | 나가기\n\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~\n(잘못 입력 시 반응 없음)\n선택한 번호 : ");
		scanf("%c", &slot);
		fflush(stdin);
		
		switch(slot)
		{
			case '1':
				fp[0] = fopen("save-1.txt","w+");
				//fprintf(fp[0],"%d %d %d %d %d %d %d %d %d %d",data.day, data.hp, data.hunger, data.sleepness, inven.berry, inven.meat, pctg.collecting, pctg.discovering, pctg.fishing, pctg.harvesting);
				fclose(fp[0]);
				quit++;
				printf("\n\n~~~~~~~~~~~~~~~~~~~~\n저장되었습니다!");
				break;
				
			case '2':
				fp[1] = fopen("save-2.txt","w+");
				//fprintf(fp[1],"%d %d %d %d %d %d %d %d %d %d",data.day, data.hp, data.hunger, data.sleepness, inven.berry, inven.meat, pctg.collecting, pctg.discovering, pctg.fishing, pctg.harvesting);
				fclose(fp[1]);
				quit++;
				printf("\n\n~~~~~~~~~~~~~~~~~~~~\n저장되었습니다!");
				break;
				
			case '3':
				fp[2] = fopen("save-3.txt","w+");
				//fprintf(fp[2],"%d %d %d %d %d %d %d %d %d %d",data.day, data.hp, data.hunger, data.sleepness, inven.berry, inven.meat, pctg.collecting, pctg.discovering, pctg.fishing, pctg.harvesting);
				fclose(fp[2]);
				quit++;
				printf("\n\n~~~~~~~~~~~~~~~~~~~~\n저장되었습니다!");
				break;
				
			case 'q':
				printf("\n\n~~~~~~~~~~~~~~~~~~~~\n뒤로 돌아갑니다.");
				quit++;
				break;
		}
		
		if(quit == 1)
		{
			Sleep(700);
			break;
		}	
	}	
}

//저장한 파일 로딩 기능 
void load(gameData *data, Inventory *inven, percentage *pctg)
{
	
}

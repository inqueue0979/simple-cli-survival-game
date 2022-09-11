#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//���� ������ ����ü
typedef struct _gameData
{
	int day; 
	int hp;
	int hunger;
	int sleepness;
}gameData;

//�κ��丮 ����ü 
typedef struct _inventory
{
	int berry;
	int edible_plant;
	int honey; 
	int herb;
	int s_meat;
	int l_meat;
}Inventory;

//Ȯ�� ���� ����ü 
typedef struct _percentage
{
	int harvesting;
	int hunting;
	int fishing;
	int discovering;
	int collecting;
}percentage;

//�Լ� ���� 
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

//�������� ����
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

//�ʹ� ��ũ�� �ε� 
void loadScreen()
{
	//���� 
	printf("***�ؽ�Ʈ �����̹� ����***\n");
	Sleep(1000); 
	//���� 
	printf("���� : %s\n", version);
	Sleep(1000);
	//�ε� ��ũ�� 
	printf("��� �� ������ ���� ȭ������ �̵��˴ϴ�");
	Sleep(700);
	printf("."); 
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	
	fflush(stdin);
} 

//���� ���� �޴� 
void MainMenu()
{
	char select;
	char* isenable;
	
	if(devMode == 1)
		isenable = "Ȱ��ȭ��";
	else
		isenable = "��Ȱ��ȭ��";
	
	system("cls"); //CUI ȭ�� �ʱ�ȭ 
	printf("~~���� �޴�~~\n\n");
	printf("1 / �� ���� �����\n\n");
	printf("2 / ���� �̾� �ϱ�\n\n");
	printf("3 / ���� ��� ����\n\n");
	printf("c / ũ����\n\n");
	printf("d / ������ ��� Ȱ��ȭ (���� %s)\n\n", isenable);
	printf("e / ���� ����\n\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~\n\n������ ��ȣ : ");
	scanf("%c", &select);
	fflush(stdin);
	switch(select)
	{
		case '1':
			printf("\n\n~~~~~~~~~~~~~~~~~\n���丮�� ���ðڽ��ϱ�??\n\n");
			Sleep(700);
			printf("1 / ���丮 ����\n\n");
			printf("2 / �ǳʶٱ�\n\n");
			printf("~~~~~~~~~~~~~~~~~\n\n������ ��ȣ : ");
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
				printf("��� �� ���丮�� �ǳʶٰ� ������ �����մϴ�");
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
				printf("�ڷ� �����ϴ�.");
				Sleep(700);
			}	
			break;
		
		case '2':
			printf("\n���� Ȱ��ȭ���� ���� ����Դϴ�.");
			Sleep(1000); 
			break;
				
		case '3':
			break;
			
		case 'c':
			system("cls");
			printf("������ : jowonjae (inqueue0979)\n");
			printf("���� : %s\n", version);
			printf("~~~~~~\n\n���б� ���� ��� C��� ������ ���� �ʱ� ���� ���� ������ �ؽ�Ʈ �����Դϴ�.\n");
			printf("���� ��ɵ��� �߰��Ͽ� �뷫���� ������ Ʋ�� ���� �� ����Ƽ������ �̿��� GUI ��� ������ ������ �����Դϴ�."); 
			printf("\n\n~~~~~~\n");
			printf("\n\n����Ű�� �����ø� ���θ޴��� ���ư��ϴ�.");
			gets(str);
			break;
			
		case 'd':
			if (devMode == 0)
			{
				devMode = 1;
				printf("\n\n������ ��尡 Ȱ��ȭ�Ǿ����ϴ�.");
				Sleep(700);
			}
			else 
			{
				devMode = 0;
				printf("\n\n������ ��尡 ��Ȱ��ȭ�Ǿ����ϴ�.");
				Sleep(700);
			}	
			break;
			
		case 'e':
			exit(0);
			break;			
	}
	
	fflush(stdin);
}

//���丮 �ۼ� 
void Story()
{
	system("cls");
	printf("���丮 ���� ���� ������...\n\n");
	printf("�ΰ������� �Ѿ�ϴ�.");
	Sleep(1000);
	fflush(stdin);
}

//���� ���� �޴� 
void GameMenu(int num)
{
	gameData data;
	percentage pctg;
	Inventory inven;
	char* weather;
	int goMain = 0;
	
	if(num == 1)
	{
		//�ҷ����� ��� 
	}
	else if(num == 2)
	{
		//�ű� �����͸� ���� �ʱ�ȭ 
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
		weather = "������ �޻��� ��ٻ�� ������ ��.";
	}
	
	while("true")
	{
		char select;
		int slot;
		system("cls");
		printf("%d��° �� | ���� : %s | �ǰ� = %d / ��� = %d / �Ƿ� = %d |\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", data.day, weather, data.hp, data.hunger, data.sleepness);
		if(devMode == 1)
			printf("Ȯ�� ����� (������ ���) / ��Ȯ : %d | ��� : %d | ���� : %d | Ž�� : %d | ���� : %d |\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", pctg.harvesting,pctg.hunting, pctg.fishing, pctg.discovering, pctg.collecting); 
		
		printf("1 / �Ĺ� ä���ϱ� (�Ƿ� -10)\n\n");
		printf("2 / ���� ����ϱ� (�Ƿ� -15)\n\n");
		printf("3 / �ֺ� Ž���ϱ� (��� -20)\n\n");
		printf("4 / ��� �����ϱ� (��� -20)\n\n");
		printf("5 / ���� �ڸ� �Ϸ縦 ������ (�Ƿ� ���󺹱�)\n\n");
		printf("~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("c / ���� �����ϱ�\n\n");
		printf("i / �κ��丮 ����\n\n");
		printf("s / ���� �����ϱ�\n\n");
		printf("e / ���θ޴��� ������ (���� �� ��, ������ �� ���� �ʼ�!) \n\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~\n(�߸� �Է� �� ���� ����)\n������ ��ȣ : ");
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
				printf("\n\n���� �޴��� �����ϴ�.");
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

//���ڱ� ��� 
char* changeDay(int *hunger, int *sleepness, percentage *pctg)
{
	char* weather;
	int random = 0;
	percentage perc = *pctg;
	
	//�ڰ� �Ͼ �� ����� 10 ����, �Ƿ� 100���� ���󺹱� 
	*hunger -= 10;
	*sleepness = 100; 
	
	random = rand() % 4;
	
	switch(random)
	{
		case 0:
			weather = "������ �޻��� ��ٻ�� ������ ��.";
			
			perc.harvesting = 70;
			perc.hunting = 60;
			perc.fishing = 0;
			perc.discovering = 0;
			perc.collecting = 0;
			
			break;
			
		case 1:
			weather = "�������� �� ���� ��.";
			
			perc.harvesting = 30;
			perc.hunting = 60;
			perc.fishing = 0;
			perc.discovering = 0;
			perc.collecting = 0;
			
			break;
			
		case 2:
			weather = "���Թ��� ���� �� ��.";
			
			perc.harvesting = 40;
			perc.hunting = 60;
			perc.fishing = 0;
			perc.discovering = 0;
			perc.collecting = 0;
			
			break;
			
		case 3:
			weather = "�޻��� �ٴ�ó�� ������ ��.";
			
			perc.harvesting = 70;
			perc.hunting = 60;
			perc.fishing = 0;
			perc.discovering = 0;
			perc.collecting = 0;
			break;
			
		default:
			system("cls");
			weather = "���α׷��� ������ �߻��߽��ϴ�. ������ ������ �������ֽʽÿ�. �����ڵ� : WEATHER_NOT_DEFINED";
			Sleep(10000);
			exit(0);
			break; 
	}
	
	system("cls");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n����ߴ� �Ϸ縦 ������ �����ϴ�");
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
	printf("\n�ֺ����� ä���ذ� ���� �ѷ�����");
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
			printf("\n\n���ƴٴϴ� ���� ������ ã�Ҵ�!");
			inven.berry++;
		}
		else if(random >= 65 && random <90)
		{
			printf("\n\n���� �����ִ� �Ŀ� �Ĺ��� ĺ��!");
			inven.edible_plant++;
		}
		else if(random >= 90 && random < 95)
		{
			printf("\n\n���! ���� ã�Ҵ�!");
			inven.honey++;
		}
		else if(random >= 95)
		{
			printf("\n\n����� ���ʸ� ĺ��!");
			inven.herb++;
		}
		else
		{
			printf("���α׷��� ������ �߻��߽��ϴ�. ������ ������ �������ֽʽÿ�. �����ڵ� : RANDOM_NUMBER_EXCEEDED");
		}	
	}
	else
	{
		printf("\n\n������ ���� ������.. ä���� ���� ���� ã�� ���ߴ�.."); 
	}
	
	if(devMode == 1) 
		printf(" (����� ��� / ���� :%d %d)", random_out, random);
		
	*inventory = inven;
	Sleep(1000);
}

void hunt(int pctg, Inventory *inventory)
{
	Inventory inven = *inventory;
	
	system("cls");
	printf("\n��ɰ��� ã�ƺ���");
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
				printf("\n\n�䳢�� ��Ҵ�! +1 ���� ���");
				inven.s_meat++;
			}
			else if(random_2 >= 75 && random_2 < 95)
			{
				printf("\n\n�ɾ��ִ� �� �θ����� ��Ҵ�! +2 ���� ���");
				inven.s_meat++;
			}
			else if(random_2 >= 95)
			{
				printf("\n\n���е��� ���� ���� ��ü�� ã�Ҵ�! +3 ���� ���");
				inven.s_meat++;
			}
			else
			{
				printf("���α׷��� ������ �߻��߽��ϴ�. ������ ������ �������ֽʽÿ�. �����ڵ� : RANDOM_NUMBER_EXCEEDED");
			}	
		}
		else if(random >= 80)
		{
			if(random_2 < 90)
			{
				printf("\n\n�罿�� ��Ҵ�! +1 ū ���");
				inven.l_meat++;
			}
			else if(random_2 >= 90)
			{
				printf("\n\n������ ��Ҵ�! +2 ū ���");
				inven.l_meat++;
			}
			else
			{
				printf("���α׷��� ������ �߻��߽��ϴ�. ������ ������ �������ֽʽÿ�. �����ڵ� : RANDOM_NUMBER_EXCEEDED");
			}	
		}
		else
		{
			printf("���α׷��� ������ �߻��߽��ϴ�. ������ ������ �������ֽʽÿ�. �����ڵ� : RANDOM_NUMBER_EXCEEDED");
		}	
	}
	else
	{
		printf("\n\n������ ���� ������..  ��ɰ��� ã�� ���ߴ�.."); 
	}
	
	if(devMode == 1) 
		printf(" (����� ��� / ���� :%d %d %d)", random1, random, random_2);
		
	*inventory = inven;
	Sleep(3000);
}

void discover()
{
	
}

void collect()
{
	
}

//�κ��丮 ��� 
void Inven(Inventory *inventory, char *weather, gameData *data)
{
	
	Inventory inven = *inventory;
	gameData gd = *data;
	
	while("true")
	{
		char select[3];
		system("cls");
		printf("%d��° �� | ���� : %s | �ǰ� = %d / ��� = %d / �Ƿ� = %d |\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", gd.day, weather, gd.hp, gd.hunger, gd.sleepness);
		printf("~~�κ��丮~~\n\n");
		printf("10 / ���� | %d��\n\n", inven.berry);
		printf("11 / �Ŀ�Ĺ� | %d��\n\n", inven.edible_plant);
		printf("12 / ��| %d\n\n", inven.honey);
		printf("13 / ����| %d��\n\n", inven.herb);
		printf("14 / ���� ���| %d��\n\n", inven.s_meat);
		printf("15 / ū ���| %d��\n\n", inven.l_meat);
		printf("q / �κ��丮 ������\n\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~\n(�߸� �Է� �� ���� ����)\n������ ��ȣ : ");
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
						printf("������ �Ծ����ϴ�.");
					}
					else
					{
						printf("������ �����ϴ�.");
					}
					break;
					
				case '1':
					if(inven.edible_plant > 0)
					{
						inven.edible_plant--;
						gd.hunger+= 12;
						printf("�Ŀ�Ĺ��� �Ծ����ϴ�.");
					}
					else
					{
						printf("�Ŀ�Ĺ��� �����ϴ�.");
					}
					break;
					
				case '2':
					if(inven.honey > 0)
					{
						inven.honey--;
						gd.hunger+= 20;
						gd.sleepness += 10;
						printf("���� �Ծ����ϴ�. �Ƿΰ� Ǯ���� ���Դϴ�.");
					}
					else
					{
						printf("���� �����ϴ�.");
					}
					break;
					
				case '3':
					if(inven.herb > 0)
					{
						inven.herb--;
						gd.hunger+= 5;
						gd.sleepness += 20;
						gd.hp += 20;
						printf("���ʸ� �Ծ����ϴ�. �ǰ��� ȸ���Ǵ� ���Դϴ�.");
					}
					else
					{
						printf("���ʰ� �����ϴ�.");
					}
					break;
				
				case '4':
					if(inven.s_meat > 0)
					{
						inven.s_meat--;
						gd.hunger+= 20;
						printf("���� ��⸦ �Ծ����ϴ�.");
					}
					else
					{
						printf("���� ��Ⱑ �����ϴ�.");
					}
					break;
					
				case '5':
					if(inven.l_meat > 0)
					{
						inven.l_meat--;
						gd.hunger+= 40;
						printf("ū ��⸦ �Ծ����ϴ�.");
					}
					else
					{
						printf("ū ��Ⱑ �����ϴ�.");
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
			printf("\n\n�κ��丮�� �����ϴ�.");
			Sleep(700); 
			break;
		}
		
		if(devMode == 1)
			printf("����� ��ȣ : %s", select);
			
		fflush(stdin);
		Sleep(500);
	}
}

void craft()
{
	
}

//���� ��� 
void save(gameData data, Inventory inven, percentage pctg)
{
	FILE *fp[3];
	int quit = 0;
	
	while("true")
	{
		char slot;
		
		system("cls");
		printf("~~���̺� ����~~\n\n");
		printf("1 | ���� 1\n\n");
		printf("2 | ���� 2\n\n");
		printf("3 | ���� 3\n\n");
		printf("q | ������\n\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~\n(�߸� �Է� �� ���� ����)\n������ ��ȣ : ");
		scanf("%c", &slot);
		fflush(stdin);
		
		switch(slot)
		{
			case '1':
				fp[0] = fopen("save-1.txt","w+");
				//fprintf(fp[0],"%d %d %d %d %d %d %d %d %d %d",data.day, data.hp, data.hunger, data.sleepness, inven.berry, inven.meat, pctg.collecting, pctg.discovering, pctg.fishing, pctg.harvesting);
				fclose(fp[0]);
				quit++;
				printf("\n\n~~~~~~~~~~~~~~~~~~~~\n����Ǿ����ϴ�!");
				break;
				
			case '2':
				fp[1] = fopen("save-2.txt","w+");
				//fprintf(fp[1],"%d %d %d %d %d %d %d %d %d %d",data.day, data.hp, data.hunger, data.sleepness, inven.berry, inven.meat, pctg.collecting, pctg.discovering, pctg.fishing, pctg.harvesting);
				fclose(fp[1]);
				quit++;
				printf("\n\n~~~~~~~~~~~~~~~~~~~~\n����Ǿ����ϴ�!");
				break;
				
			case '3':
				fp[2] = fopen("save-3.txt","w+");
				//fprintf(fp[2],"%d %d %d %d %d %d %d %d %d %d",data.day, data.hp, data.hunger, data.sleepness, inven.berry, inven.meat, pctg.collecting, pctg.discovering, pctg.fishing, pctg.harvesting);
				fclose(fp[2]);
				quit++;
				printf("\n\n~~~~~~~~~~~~~~~~~~~~\n����Ǿ����ϴ�!");
				break;
				
			case 'q':
				printf("\n\n~~~~~~~~~~~~~~~~~~~~\n�ڷ� ���ư��ϴ�.");
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

//������ ���� �ε� ��� 
void load(gameData *data, Inventory *inven, percentage *pctg)
{
	
}
